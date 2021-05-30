<?php

    session_start();
    unset($_SESSION['Error']);

    
    if(isset($_POST['username'])){
        echo checkUsername($_POST['username']);
    }else{
        header('Content-Type: text/plain');
        $test = utf8_encode($_POST['data']); // Don't forget the encoding
        $data = json_decode($test);
        echo checkPassword($data);
    }
    function checkUsername($uname){
        $servername = "localhost";
        $username = "Manny";
        $password = "Manny@123";
        $dbname = "IWPL";
    
        $conn = new mysqli($servername, $username, $password, $dbname);
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT * FROM user_details where username='$uname'";
        $result = $conn->query($sql);
    
        if ($result->num_rows > 0) {
            
            $conn->close();
            return "EXISTS";
        } else {
            
            $conn->close();
            return "ERROR";
        }
    
    }

    function checkPassword($data){
        
        $uname = $data->username;
        $pass = $data->pass;

        $servername = "localhost";
        $username = "Manny";
        $password = "Manny@123";
        $dbname = "IWPL";
    
        $conn = new mysqli($servername, $username, $password, $dbname);
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }

        $sql = "SELECT * FROM user_details where username='$uname' and pass='$pass'";
        $result = $conn->query($sql);
    
        if ($result->num_rows > 0) {
            echo "EXISTS";
        } else {
            echo "ERROR";
        }
    
        $conn->close();
    }
?>