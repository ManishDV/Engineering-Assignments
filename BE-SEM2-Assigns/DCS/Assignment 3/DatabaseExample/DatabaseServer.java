// HelloServer.java
import DatabaseApp.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;
import org.omg.PortableServer.*;
import org.omg.PortableServer.POA;
import java.sql.*;

import java.util.ArrayList;

import java.util.Properties;

class Database extends DatabaseImplPOA {
  private ORB orb;

  public void setORB(ORB orb_val) {
    orb = orb_val; 
  }
    
  // implement sayHello() method
  public Record[] getStudentData(){
    
    try{
      
      System.out.println("\n[DRIVER]: Loading\n");
			Class.forName("com.mysql.jdbc.Driver");  
      
      System.out.println("\n[DRIVER]: Loaded\n");
			Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/ses","Manish","Manny@123");
			
			String query = "SELECT roll_no as ROLL_NO, student_name as NAME from student limit 10;";
			
			Statement stmt = con.createStatement();

			ResultSet rs = stmt.executeQuery(query);
      rs.last();
      System.out.println("\n[ROWS]: "+rs.getRow() + "\n");
      Record[] data = new Record[rs.getRow()];
      rs.beforeFirst();
      int i = 0;    
        while(rs.next()){
          Record r = new Record(rs.getInt("ROLL_NO"),rs.getString("NAME"));
          data[i++] = r;	
      }

			con.close();
      return data;
		}catch(Exception e){
			System.out.println(e);
		}
    
    Record[] r = new Record[1];
    r[0] = new Record(0,"No Record");;
    return r;
  }
   
}


public class DatabaseServer {

  public static void main(String args[]) throws Exception {
    try{
      // create and initialize the ORB
      ORB orb = ORB.init(args, null);

      // get reference to rootpoa and activate the POAManager
      POA rootpoa = POAHelper.narrow(orb.resolve_initial_references("RootPOA"));
      rootpoa.the_POAManager().activate();

      // create servant and register it with the ORB
      Database dbImpl = new Database();
      dbImpl.setORB(orb); 

      // get object reference from the servant
      org.omg.CORBA.Object ref = rootpoa.servant_to_reference(dbImpl);
      DatabaseImpl href = DatabaseImplHelper.narrow(ref);
          
      // get the root naming context
      org.omg.CORBA.Object objRef =
          orb.resolve_initial_references("NameService");
      // Use NamingContextExt which is part of the Interoperable
      // Naming Service (INS) specification.
      NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);

      // bind the Object Reference in Naming
      String name = "DatabaseImpl";
      NameComponent path[] = ncRef.to_name( name );
      ncRef.rebind(path, href);

      System.out.println("DatabaseServer ready and waiting ...");

      // wait for invocations from clients
      orb.run();
    } 
        
      catch (Exception e) {
        System.err.println("ERROR: " + e);
        e.printStackTrace(System.out);
      }
          
      System.out.println("HelloServer Exiting ...");
        
  }
}