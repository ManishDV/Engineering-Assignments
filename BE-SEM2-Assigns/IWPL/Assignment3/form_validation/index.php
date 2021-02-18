<?php
    session_start();    
?>
<!DOCTYPE html>
<html>

<head>
    <title>Music Gallary</title>
    <link type="text/css" rel="stylesheet" href="style.css" />
    <link rel="stylesheet" type="text/css" href="navbarstyle.css">
</head>

<body>
    <div class="navbar-container">
        <div class="logo">
            <a href="index.php"><img src="logo.png" width="56px" height="56px"></a>
        </div>
        <div class="nav-items">
            <ul>
            <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            <li><a href="logout.php">Logout</a></li>
            <?php }else{ ?>
                <li><a href="login.php">Sign In</a></li>
            <?php } ?>    
            <li><a href="#">About Us</a></li>
                <li><a href="Categories.php ">Browse</a></li>
                <li><a href="index.php" class="active">Home</a></li>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
                    {
                        $user = $_SESSION["username"];
                        echo "<li class=\"username\">Welcome  $user</li>";
                    }?>
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
                
            <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
              
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/BB.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/BK.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/farar.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/HHS.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/Judaiyan.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/tanhai.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
            <div class="player">
                <div class="imgBx">
                    <img src="Trending/Poster/TMN.jpg">
                </div>
                <?php if( isset($_SESSION['username']) && !empty($_SESSION['username']) )
            {
            ?>
            
             <audio controls preload="none"   controlsList="nodownload" disabled>
                    <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                </audio>
                
            <?php }else{ ?>
                    <div class="displayMsg">
                        <h3>Login To Play !!!</h3>
                    </div>
            <?php } ?>
            </div>
        </div>
    </div>
    <!-- <div class="container-main">
            <div id="carouselExampleControls" class="carousel slide" data-ride="carousel">
                <div class="carousel-inner">
                    <div class="carousel-item active">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/taronKeSheher.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/BB.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/BK.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/farar.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/HHS.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/Judaiyan.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/TMN.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                    <div class="carousel-item">
                        <div class="player">
                            <div class="imgBx">
                                <img src="Trending/Poster/tanhai.jpg">
                            </div>
                            <audio controls>
                                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
                            </audio>
                        </div>
                    </div>
                </div>
                <a class="carousel-control-prev" href="#carouselExampleControls" role="button" data-slide="prev">
                    <span class="carousel-control-prev-icon" aria-hidden="true"></span>
                    <span class="sr-only">Previous</span>
                </a>
                <a class="carousel-control-next" href="#carouselExampleControls" role="button" data-slide="next">
                    <span class="carousel-control-next-icon" aria-hidden="true"></span>
                    <span class="sr-only">Next</span>
                </a>
            </div>
        </div>
    </center> -->
    <!-- <center><h3>Trending Now</h3></center>
        
        <div class="player">
            <div class="imgBx">
                <img src="Trending/Poster/BB.jpg">
            </div>
            <audio controls>
                <source src="Trending/mp3/Taaron Ke Shehar.mp3" type="audio/mp3">
            </audio>
        </div>
         -->
    <!-- <center>
            <div>
                <div>
                    <figure><a href="taroKSLyrics.html">
                            <img src="Trending/Poster/taronKeSheher.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>Taron Ke Sheher Mein<br>Neha Kakkar</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/BB.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>BamBholle<br>Viruss</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/BK.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>BurjKhalifa<br>Madhubanti,Nikhita Gandhi</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/TMN.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>Tu Mera Nahi<br>Amaal Malik</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/farar.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>Faraar<br>Akull</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/HHS.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>Husn Hai Suhana<br>Chandana Dixit,Abhijit</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/tanhai.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>Tanhai<br>Tulasi Kumar</figcaption>
                    </figure>
                </div>
                <div>
                    <figure><a href="#">
                            <img src="Trending/Poster/Judaiyan.jpg" alt="Trulli" height="175px" width="175px"></a>
                        <figcaption>Judaiyan<br>Darshan Raval</figcaption>
                    </figure>
                </div>
            </div>
        </center> -->
        <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js" integrity="sha384-Tc5IQib027qvyjSMfHjOMaLkfuWVxZxUPnCJA7l2mCWNIpG9mGCD8wGNIcPD7Txa" crossorigin="anonymous"></script>
</body>

</html>