<?php


require_once('C:\\xampp\\nusoap\\lib\\nusoap.php');
session_start();
unset($_SESSION['Error']);


if ( isset($_POST["btnLog"]) ){
    $wsdl="http://localhost:8080/SimpleWebService/services/DatabaseUtilityImpl?wsdl";

    $uname = $_POST['username'];
    $pass = $_POST['pass']; 

    $param = array('uName'=>$uname,'uPass'=>$pass);

    $client = new nusoap_client($wsdl,'wsdl');

    $result = $client->call('validateUser',$param);
    if(implode($result) == 'true'){
        $_SESSION['username'] = $uname;
        header('location: index.php');
    }else{
        $_SESSION['error'] = "Wrong Username or Password";
        
        header('location: login.php');
    }

}else{
    echo "Error: Please Submit the form";
}
?>