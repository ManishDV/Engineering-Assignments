<!DOCTYPE html>
<html>
<head>
    <title>Login to Music Gallary</title>
    <script src="js/jquery.js"></script>
    <link rel="stylesheet" type="text/css" href="css/navbarstyle.css">
    <link rel="stylesheet" type="text/css" href="css/login.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <style>
        .hidden{
            display:none;
            color: red;
        }
    </style>
</head>
<body>
<div class="navbar-container">
        <div class="logo">
            <a href="index.jsp"><img src="images/logo.png" width="56px" height="56px"></a>
        </div>
        <div class="nav-items">
            <ul>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                <li><a href="logout.jsp">Logout</a></li>
                <%}else{%>
                <li><a href="login.jsp" class="active">Sign In</a></li>
                <%}%>
                <li><a href="#">About Us</a></li>
                <li><a href="Categories.jsp">Browse</a></li>
                <li><a href="index.jsp">Home</a></li>
            </ul>
        </div>
    </div>
    <div class="errorSpan">
        <%if(! ((String)session.getAttribute("error")).equals("None")) {%>
        <center><%=(String)session.getAttribute("error")%></center>    
        <%}%>
                
    </div>
    <div class="card-container">
        <div>
            <div class="header">
                <h2>Login</h2>
            </div>
            <div class="fields">
                <form method="POST" action="validate.jsp">
                    <input type="text" name="username" id="username" placeholder="username" align="center" autocomplete="off" required/>
                    <center><span id="userError" class="hidden"></span></center>
                    <input type="password" name="pass" id="pass" placeholder="Password" autocomplete="off" required/>
                    <center><span id="passError" class="hidden"></span></center>
                    <input type="submit" value="Login" name="btnLog" id="btnSubmit">
                    <div class="forgotPass"><a href="forgotPass.php">Forgot Password</a></div>    
                </form>
            </div>

            <div class="foot">
                <p>Not a Member ? <a href="registration.html"><font color="#118899"><b><i>Register Here</i></b></font></a></p>
            </div>
        </div>
    </div>
</body>
<script>
</script>
</html>
<%
session.setAttribute("error","None");
%>