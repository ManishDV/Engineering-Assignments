<?php
session_start();  
unset($_SESSION['Error']);
error_reporting(0);  
?>
<!DOCTYPE html>
<html>

<head>
    <title>Login to Music Gallary</title>
    <link rel="stylesheet" type="text/css" href="css/navbarstyle.css">
    <link rel="stylesheet" type="text/css" href="css/login.css">
    
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
    <style>
        .errorSpan{
            height: 50px;
            margin-right: 2%;
            overflow: auto;
            
            width: 400px;
            margin-top: -50px;
        }
    </style>
</head>


<body>
    <div class="card-container">
        <div>
            <div class="header">
                <h2>Reset Password</h2>
            </div>
            <div class="fields">
                <form method="POST" action="resetPassword.php">
                    <input type="Password" name="password" id="username" placeholder="Enter New Password" align="center" autocomplete="off" onkeyup="validatePass()"/>
                    <input type="password" name="confirmPass" id="pass" placeholder="Confirm Password" autocomplete="off" onkeyup="confirmPassword()" />
                    <input type="hidden" name="email" value="<?php  echo $_GET['email']; ?>">
                    <input type="submit" value="Reset" name="submitBtn" id="btnSubmit" onclick="return validate()">    
                </form>
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
        
    </div>
    </div>
</body>

<script>
    let pass = false;
    let cpass = false;
    function validatePass(){
        // console.log('Came Here');
        var re = /^(?=.*[0-9])(?=.*[A-Z])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{6,16}$/;
        pass = document.getElementById('username').value;
        // console.log(pass);
        if(re.test(pass)){
            document.getElementById("username").style = "border-bottom : 2px solid green";
            document.getElementsByClassName("errorSpan")[0].innerHTML = "";
            pass = true;
        }else{
            document.getElementById("username").style = "border-bottom : 2px solid red";
            document.getElementsByClassName("errorSpan")[0].innerHTML = "Password must contain at least 1 capital Letter, 1 small letter,1 special symbol and 1 digit";
            // document.getElementsByClassName("errorSpan")[0].style = "overflow: auto";
            pass = false;
        }
    }

    function confirmPassword(){
        pass = document.getElementById('username').value;
        cpass = document.getElementById('pass').value;
        if(cpass === pass){
            document.getElementById("pass").style = "border-bottom : 2px solid green";
            document.getElementsByClassName('errorSpan')[0].innerHTML="";
            cpass = true;
        }else{
            document.getElementById("pass").style = "border-bottom : 2px solid red";
            document.getElementsByClassName('errorSpan')[0].innerHTML="Passwords do not match";
            cpass = false;
        }
        return true;
    }

    function validate(){
        if(pass && cpass) return true;
        return false;
    }

</script>

</html>

<?php
    unset($_SESSION["error"]);
?>