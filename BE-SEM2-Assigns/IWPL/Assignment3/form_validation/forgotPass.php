<?php 
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Forgot Password</title>
    <link rel="stylesheet" href="css/login.css">
    <style>
        #btnSubmit{
            margin-left: 32%;
            width: auto;
            margin-top: 10%;
        }

        .errorSpan{
            margin-top: 22%;
        }
    </style>
</head>
<body>
<div class="card-container">
        <div>
            <div class="header">
                <h2>Forgot Password</h2>
            </div>
            <div class="fields">
                <form method="POST" action="sendMail.php">
                    <input type="text" name="email" id="username" placeholder="Enter Email Id" align="center" autocomplete="off" />
                    <!-- <input type="password" name="pass" id="pass" placeholder="Password" autocomplete="off"> -->
                    <input type="submit" value="Send Reset Link" name="sendBtn" id="btnSubmit">
                </form>
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
    </div>
</body>
</html>

<?php
    unset($_SESSION["error"]);
?>