<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ page import="java.sql.*"%>
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
String firstName = request.getParameter("fname");
String lastName = request.getParameter("lname");
String address = request.getParameter("address");
String pin = request.getParameter("pin");
String gender = request.getParameter("gender");
String username = request.getParameter("username");
String password = request.getParameter("password");
String email = request.getParameter("email");
String phone = request.getParameter("phone");

String query = " insert into accounts(fname,lname,address,pin,gender,username,password,email,phone) values('"+firstName+"','"+lastName+"','"+address+"','"+pin+"','"+gender+"','"+username+"','"+password+"',,'"+email+"','"+phone+"')" ;	

Statement st = con.createStatement();
int i = st.executeUpdate(query);
if(i > 0){
	response.sendRedirect("Login.html");
}else{
	response.sendRedirect("Register.html");
}


%>
</body>
</html>