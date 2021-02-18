<?php
session_start();
unset($_SESSION['Error']);
$servername = "localhost";
$username = "Manny";
$password = "Manny@123";
$dbname = "IWPL";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}


if ( $_SERVER["REQUEST_METHOD"] == "POST" ){
    $uname = $_POST['username'];
    $pass = $_POST['pass']; 
    $sql = "SELECT username, pass FROM user_details where username='$uname' and pass='$pass'";
    $result = $conn->query($sql);

    if ($result->num_rows > 0) {
        $_SESSION["username"] = $uname;
        header("Location:index.php");
        unset($_SESSION["error"]);
    } else {
        
        $_SESSION["error"] = "*Either Username or Password is Wrong.";
        header("Location:login.php");
    }

    $conn->close();
}else{
    echo "Error: Please Submit the form";
}
?>