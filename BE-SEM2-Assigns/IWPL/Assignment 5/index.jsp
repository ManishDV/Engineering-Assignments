<!DOCTYPE html>
<html>

<head>
    <title>Music Gallary</title>
    <link type="text/css" rel="stylesheet" href="css/style.css" />
    <link rel="stylesheet" type="text/css" href="css/navbarstyle.css">
</head>

<body>
    <div class="navbar-container">
        <div class="logo">
            <a href="index.jsp"><img src="images/logo.png" width="56px" height="56px"></a>
        </div>
        <div class="nav-items">
            <ul>
            <%
            	if(session.getAttribute("user") == null){
            		session.setAttribute("user","absent");
            		session.setAttribute("error","None");
            	}
            
                if(! ((String) session.getAttribute("user")).equals("absent")) {
            %>
                <!-- <li>Welcome <?php ?> </li> -->
            <li><a href="logout.jsp">Logout</a></li>

            <% }else{ %>
                <li><a href="login.jsp">Sign In</a></li>
            <% } %>    
            <li><a href="#">About Us</a></li>
                <li><a href="Categories.jsp ">Browse</a></li>
                <li><a href="index.jsp" class="active">Home</a></li>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {
                %>       
                        
                        <li class="username">Welcome  <%=session.getAttribute("user")%></li>;
                <%} %>    
            </ul>
            
        </div>
    </div>
    <div class="trend">
        <marquee behavior="alternate">
            <h1>Trending Now</h1>
        </marquee>
    </div>
    <div class="container-main">
        <div class="cards">
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/taronKeSheher.jpg">
                </div>
                
            <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
              
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/BB.jpg">
                </div>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/BK.jpg">
                </div>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/farar.jpg">
                </div>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/HHS.jpg">
                </div>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/Judaiyan.jpg">
                </div>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/tanhai.jpg">
                </div>
                <%if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/TMN.jpg">
                </div>
                <%if(! ((String)session.getAttribute("user")).equals("absent")) {%>
                 <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <% }else{ %>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <% } %>
            </div>
        </div>
    </div>
<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</body>

</html>
<%session.setAttribute("error","None"); %>