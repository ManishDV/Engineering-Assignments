 
import DatabaseApp.*;
import org.omg.CosNaming.*;
import org.omg.CosNaming.NamingContextPackage.*;
import org.omg.CORBA.*;

import java.util.ArrayList;

public class DatabaseClient
{
  static DatabaseImpl databaseImpl;

  public static void main(String args[]) throws Exception
    {
      try{
        // create and initialize the ORB
        ORB orb = ORB.init(args, null);

        // get the root naming context
        org.omg.CORBA.Object objRef = 
            orb.resolve_initial_references("NameService");
        // Use NamingContextExt instead of NamingContext. This is 
        // part of the Interoperable naming Service.  
        NamingContextExt ncRef = NamingContextExtHelper.narrow(objRef);
 
        // resolve the Object Reference in Naming
        String name = "DatabaseImpl";
        databaseImpl = DatabaseImplHelper.narrow(ncRef.resolve_str(name));

        System.out.println("Obtained a handle on server object: " + databaseImpl);
        Record[] data = databaseImpl.getStudentData();
        
		for(Record s : data){
			System.out.println(s.roll + "\t  " + s.name + "\n");
			System.out.println("-------------------------------------------------------\n");
					
		}

        } catch (Exception e) {
          System.out.println("ERROR : " + e) ;
          e.printStackTrace(System.out);
          }
    }

}