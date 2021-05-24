
<!DOCTYPE html>
<html>

<head>
    <title>Categories</title>
    <link type="text/css" rel="stylesheet" href="css/style.css" />
    
    <link rel="stylesheet" type="text/css" href="css/navbarstyle.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
</head>

<body>
    <div class="navbar-container">
        <div class="logo">
            <a href="index.jsp"><img src="images/logo.png" width="70px" height="70px"></a>
        </div>
        <div class="nav-items">
            <ul>
            <%if(!((String)session.getAttribute("user")).equals("absent")){
            %>
                <li><a href="logout.jsp">Logout</a></li>
            <% }else{ %>
                <li><a href="login.jsp">Sign In</a></li>
            <% } %>
                <li><a href="#">About Us</a></li>
                <li><a href="Categories.jsp" class="active">Browse</a></li>
                <li><a href="index.jsp">Home</a></li>
                <% if(! ((String)session.getAttribute("user")).equals("absent")) {
                %>       
                        
                        <li class="username">Welcome  <%=session.getAttribute("user")%></li>;
                <%} %>    
            </ul>
        </div>
    </div>
    <div class="trend">
        <marquee>
            <h1>Categories</h1>
        </marquee>
    </div>
    <div class="container-main">
        <div class="cards">
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/edm.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/romance.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/bhakti.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/dance.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/era.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/festival.png" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/ghazals.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/party.png" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/retro.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/wedding.jpg" alt="Trulli"></a>
                </div>
            </div>
            <div class="catplayer">
                <div class="catimgBx">
                    <a href="#"><img src="category posters/workout.png" alt="Trulli"></a>
                </div>
            </div>
        </div>
</body>

</html>