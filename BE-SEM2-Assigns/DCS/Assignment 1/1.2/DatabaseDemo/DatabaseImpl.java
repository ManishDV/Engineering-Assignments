import java.rmi.*;
import java.util.ArrayList;
import java.rmi.server.*;
import java.sql.*;

public class DatabaseImpl extends UnicastRemoteObject implements DatabaseInterface{
	
	public DatabaseImpl() throws RemoteException{
		super();
	}

	public ArrayList<Student> getStudentData() throws RemoteException{
		
		ArrayList<Student> data = new ArrayList();

		try{
			Class.forName("com.mysql.jdbc.Driver");  
		
			Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/ses","Manish","Manny@123");
			
			String query = "SELECT student.roll_no as ROLL_NO, student.student_name as NAME, cid as CLASS from student inner join class_has_students on student.roll_no = class_has_students.roll_no LIMIT 20";
			
			Statement stmt = con.createStatement();

			ResultSet rs = stmt.executeQuery(query);

			while(rs.next()){
				Student s = new Student(rs.getInt("ROLL_NO"),rs.getString("NAME"),rs.getString("CLASS"));
				data.add(s);	
			}

			con.close();

		}catch(Exception e){
			System.out.println(e);
		}
		return data;

	}

}