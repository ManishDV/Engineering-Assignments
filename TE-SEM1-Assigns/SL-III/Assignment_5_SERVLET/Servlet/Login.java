import java.io.*;
import javax.servlet.*;
import javax.servlet.http.*;
import java.sql.*;
import javax.sql.*;

public class Login extends HttpServlet
{
	public void doPost(HttpServletRequest req,HttpServletResponse res) throws IOException,ServletException
	{
		res.setContentType("text/html");
		PrintWriter out=res.getWriter();
	
		    String n=req.getParameter("username");  
    		    String p=req.getParameter("userpass");

		    try{
			Class.forName("com.mysql.jdbc.Driver");
			
			Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/Feedback","Manish","Manny@123");
			
			String query = "select pass from accounts where name='"+n+"'";
			
			Statement st = con.createStatement();
			ResultSet resultSet = st.executeQuery(query);
			
			if(resultSet.next()){
				if(p.equals(resultSet.getString("pass"))){
					out.println("<script>alert('Access Granted')</script>");
					//res.sendRedirect("/opt/tomcat/webapps/ROOT/Servlet/submit.html");
				}else{
					out.println("<script>alert('Invalid Crentials')</script>");
					//res.sendRedirect("Login.html"); 
				}
			}else{
				out.println("<script>alert('No user Exists with Entered Username')</script>");
				//res.sendRedirect("Login.html");
			}
			
			st.close();
			resultSet.close();
			con.close();
		
	}catch(Exception e){
		out.println(e.getMessage());
	}

  
    }
}
