<?php
session_start();  
unset($_SESSION['Error']);
error_reporting(0);  
?>
<!DOCTYPE html>
<html>

<head>
    <title>Login to Music Gallary</title>
    <link rel="stylesheet" type="text/css" href="navbarstyle.css">
    <link rel="stylesheet" type="text/css" href="login.css">
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
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
                <li><a href="login.php" class="active">Sign In</a></li>
            <?php } ?>
                <li><a href="#">About Us</a></li>
                <li><a href="Categories.php">Browse</a></li>
                <li><a href="index.php">Home</a></li>
            </ul>
        </div>
    </div>
    <div class="errorSpan">
    <?php
                    if(isset($_SESSION["error"])){
                        $error = $_SESSION["error"];
                        echo "<center>$error</center>";
                    }
                ?> 
    </div>
    <div class="card-container">
        <div>
            <div class="header">
                <h2>Login</h2>
            </div>
            <div class="fields">
                <form method="POST" action="validate.php">
                    <input type="text" name="username" id="username" placeholder="username" align="center" autocomplete="off" />
                    <input type="password" name="pass" id="pass" placeholder="Password" autocomplete="off">
                    <input type="submit" value="Login" id="btnSubmit">
                </form>
            </div>
            <div class="foot">
                <p>Not a Member ? <a href="registration.html"><font color="#118899"><b><i>Register Here</i></b></font></a></p>
            </div>
        </div>
    </div>
</body>

</html>

<?php
    unset($_SESSION["error"]);
?>