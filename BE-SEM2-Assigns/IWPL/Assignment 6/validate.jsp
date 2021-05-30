<%@ page import="auth.Authenticator" %>
<%

    String user = request.getParameter("username");
    String pass = request.getParameter("pass");
    
    Authenticator auth = new Authenticator();

    if(auth.authenticate(user,pass)){
        session.setAttribute("user",user);
        session.setAttribute("error","None");
        response.sendRedirect("index.jsp");
    }else{
        session.setAttribute("user","absent");
        session.setAttribute("error","Username or Password is wrong");
        response.sendRedirect("login.jsp");
    }
    

%>