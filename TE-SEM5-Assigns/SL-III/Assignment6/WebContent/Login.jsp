<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@page import="java.sql.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<body>
<%
Class.forName("com.mysql.jdbc.Driver");
Connection con = DriverManager.getConnection("jdbc:mysql://localhost:3306/SL3", "Manish","Manny@123");
String username = request.getParameter("uname");
String password = request.getParameter("passwd");

String query = "select password from accounts where uname='"+username+"'";

Statement st = con.createStatement();
ResultSet resultSet = st.executeQuery(query);

if(resultSet.next()){
	if(password.equals(resultSet.getString("password"))){
		out.println("Successfull");
		session.setAttribute("user",username);
	    response.sendRedirect("dashboard.html"); 
	}else{
		out.println("Password or Username is Wrong");
		response.sendRedirect("Login.html");
	}
}else{
	out.println("No user with user Name "+username);
	response.sendRedirect("Login.html");
}

st.close();
resultSet.close();
con.close();

%>
</body>
</html>