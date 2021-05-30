<%@ page import="auth.Authenticator" %>
<%@ page import="auth.ProfileData" %>

<%
	String fname = request.getParameter("fname");
	String lname = request.getParameter("lname");
    String addr = request.getParameter("addr");
    String pin = request.getParameter("pin");
    String dob = request.getParameter("dob");
    String gender = request.getParameter("gender");
    String uname = request.getParameter("username");
    String pass = request.getParameter("pass");
    String email = request.getParameter("email");
    String phone = request.getParameter("phone");
    
	
    ProfileData profile = new ProfileData();
    
    profile.setFirst_name(fname);
    profile.setLast_name(lname);
    profile.setAddress(addr);
    profile.setPin(pin);
    profile.setDOB(dob);
    profile.setGender(gender.charAt(0));
    profile.setUsername(uname);
    profile.setPass(pass);
    profile.setEmail(email);
    profile.setPhone(phone);
    
    Authenticator auth = new Authenticator();
    
    if(auth.register(profile)){
    	response.sendRedirect("success.html");
    }else{
    	System.out.println("Cannot Insert Error Occured");
    }
    
    
    
%>