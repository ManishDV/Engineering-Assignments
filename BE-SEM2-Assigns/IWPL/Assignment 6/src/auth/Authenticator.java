package auth;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
public class Authenticator {

    public Connection con;
    
    public Authenticator(){
        try{
            Class.forName("com.mysql.jdbc.Driver");
            con = DriverManager.getConnection("jdbc:mysql://localhost:3306/IWPL","Manny","Manny@123");
        }catch(Exception e){
        	System.out.println("Cannot Connect To Database");
        }
    }

    public boolean authenticate(String user, String pass) throws Exception{
        String query = "select username,pass from user_details where username='" + user + "' and pass='"+pass+"';";
        Statement stmt = con.createStatement();
        ResultSet rs=stmt.executeQuery(query);
        rs.last();
        int row = rs.getRow();
        if(row > 0)
            return true;
        else
        	return false;
    }
    
    public boolean register(ProfileData profile) throws SQLException {
    	
    	 String query = "insert into user_details(first_name,last_name,address,pin_code,DOB,gender,email,phone,username,pass) values(?,?,?,?,?,?,?,?,?,?);";
    	 
    	 PreparedStatement ps = con.prepareStatement(query);
    	 
    	 ps.setString(1, profile.getFirst_name());
    	 ps.setString(2, profile.getLast_name());
    	 ps.setString(3, profile.getAddress());
    	 ps.setString(4, profile.getPin());
    	 ps.setDate(5, java.sql.Date.valueOf(profile.getDOB()));
    	 ps.setString(6, String.valueOf(profile.getGender()));
    	 ps.setString(7, profile.getEmail());
    	 ps.setString(8, profile.getPhone());
    	 ps.setString(9, profile.getUsername());
    	 ps.setString(10, profile.getPass());
    	 
    	 int i = ps.executeUpdate();
    	 if( i > 0)
    		 return true;
    	return false;
    }

}