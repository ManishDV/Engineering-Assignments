<?php
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
    $firstname = $_POST['fname'];
    $lastname = $_POST['lname'];
    $addr = $_POST['addr'];
    $pin = $_POST['pin'];
    $dob = $_POST['dob'];
    $gender = $_POST['gender'];
    $username = $_POST['username'];
    $pass = $_POST['pass'];
    $email = $_POST['email'];
    $phone = $_POST['phone'];
    $sql = "INSERT INTO user_details(first_name,last_name,address,pin_code,DOB,gender,email,phone,username,pass)
    VALUES ('$firstname', '$lastname', '$addr','$pin','$dob','$gender','$email','$phone','$username','$pass')";

    if ($conn->query($sql) === TRUE) {
        header("Location:success.html");
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}else{
    echo "Error: Please Submit the form";
}
