import java.sql.*;
import java.utils.*;

class Authenticator {

    Connection con;

    public Authenticator(){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/IWPL","Manny","Manny@123");
        }catch(Exception e){
            out.println("Cannot Connect To Database");
        }
    }

    public bool authenticate(String user, String pass){
        String query = "select count(*) from user_details where username=" + user + " and pass="+pass+";";
        Statement stmt = con.createStatement();
        ResultSet rs=stmt.executeQuery(query);
        
        if(rs.next())
            return true;
        
            return false;
    }
    

}