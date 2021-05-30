<?php 
use PHPMailer\PHPMailer\PHPMailer;
require    'Mailer/src/PHPMailer.php';
require    'Mailer/src/SMTP.php';
use PHPMailer\PHPMailer\Exception;

require 'Mailer/src/Exception.php';

session_start();
unset($_SESSION['Error']);

if( isset($_POST['sendBtn'])){
    echo "<script>cosnole.log('It came Here')</script>";
    $to = $_POST['email'];
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

    $sql = "SELECT *  FROM user_details where email='$to'";
    $result = $conn->query($sql);



    if ($result->num_rows > 0) {
        $row = $result->fetch_row();
        $firstName = $row[1];
        $lastName = $row[2]; 
        $mail               = new PHPMailer;
        $body               = "<h1> Click the following link to reset password</h1><p><a href='http://localhost/Assignment3//form_validation/resetPass.php?email=$to'>CLICK HERE TO RESET PASSWORD</a></p>";
        $mail->IsSMTP();                                        // telling the class to use SMTP
        $mail->SMTPDebug    = 1;                                // enables SMTP debug information (for testing)
        $mail->SMTPAuth     = true;                             // enable SMTP authentication
        $mail->SMTPSecure   = "tls";                            // sets the prefix to the servier
        $mail->Host         = "smtp.gmail.com";                 // sets GMAIL as the SMTP server
        $mail->Port         = 587;                              // set the SMTP port for the GMAIL server

        $mail->Username     = "music@gmail.com"  ;           // GMAIL username
        $mail->Password     = '' ;           // GMAIL password

        $mail->SetFrom('musicgallaryservices@gmail.com', 'Music Gallary');
        $mail->Subject    = "Password Reset";
        $mail->MsgHTML($body);
        $address = $to;
        $mail->AddAddress($address, "$firstName $lastName");

        // $mail->AddAttachment("images/phpmailer.gif");        // attachment
        // $mail->AddAttachment("images/phpmailer_mini.gif");   // attachment

        if(!$mail->Send()) {
            $_SESSION["error"] = "Mail Not Sent";
            header("Location:forgotPass.php");
        } 
        else {
            $_SESSION["error"] = "Password Reset Link is sent to your email id";
            header("Location:forgotPass.php");
        }
    } 
    else {
        $_SESSION["error"] = "*No record available for entered Email address.";
        header("Location:forgotPass.php");
    }

    $conn->close();


}
?>

