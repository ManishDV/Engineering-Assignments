<?php

    if(isset($_POST['submitBtn'])){
        $conn = new mysqli('localhost','Manny','Manny@123','IWPL');

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        
        $mail = $_POST['email'];
        $pass = $_POST['password'];

        $sql = "UPDATE user_details SET pass='$pass' WHERE email='$mail'";
        if($conn->query($sql) === TRUE){
            header("location:resetSuccess.html");
        }else{
            $_SESSION["error"] = "Error In Updating Password";
            header("location:resetPass.php");
        }
    
    }else{
        $_SESSION["error"] = "Error In Updating Password";
        header("location:resetPass.php");
    }


?>