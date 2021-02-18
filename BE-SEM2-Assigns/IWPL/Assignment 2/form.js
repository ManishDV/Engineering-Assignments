function validateFirstName() {
    form = document.getElementById('registerForm');
    fname = document.getElementById('fname').value;
    rename = /^[a-zA-Z ]{2,30}$/;
    if (fname.length != 0 && rename.test(fname)) {
        form.fname.style = "border:2px solid green";
        return true;
    } else {
        form.fname.style = "border:2px solid red";
        form.fname.focus();
        return false;
    }
}

function validateLastName() {
    form = document.getElementById('registerForm');
    lname = document.getElementById('lname').value;
    rename = /^[a-zA-Z ]{2,30}$/;

    if (lname.length != 0 && rename.test(lname)) {

        document.getElementById('lname').style = "border:2px solid green";
        // return true;
    } else {

        document.getElementById('lname').style = "border:2px solid red";
        // return false;
    }
}

function validatePin() {
    form = document.getElementById('registerForm');
    pin = document.getElementById('pin').value;
    var pinre = /^\d{6}$/;
    if (pin.length != 0 && pinre.test(pin)) {
        form.pin.style = "border:2px solid green";
        return true;
    } else {
        form.pin.style = "border:2px solid red";
        return false;
    }
}

function validateUname() {
    uname = document.getElementById('username').value;
    form = document.getElementById('registerForm');

    if (uname.length >= 6) {
        document.getElementById("username").style = "border : 2px solid green";
        return true;
    } else {
        document.getElementById("username").style = "border : 2px solid red";
        return false;
    }

}

function validatePhone() {
    phone = document.getElementById('phone').value;
    form = document.getElementById('registerForm');
    var phoneno = /^[789]\d{9}$/;
    if (phoneno.test(phone)) {
        document.getElementById("phone").style = "border : 2px solid green";
        return true;
    } else {
        document.getElementById("phone").style = "border : 2px solid red";
        return false;
    }

}

function validateEmail() {
    email = document.getElementById('email').value;
    form = document.getElementById('registerForm');
    var emailre = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
    if (emailre.test(email)) {
        document.getElementById("email").style = "border : 2px solid green";
        return true;
    } else {
        document.getElementById("email").style = "border : 2px solid red";
        return false;
    }

}


function validateAge() {
    // id = document.getElementById("date");
    // id.type = 'search';

    bday = new Date(document.getElementById("date").value);
    bday = bday.getFullYear();
    today = new Date();
    today = today.getFullYear();
    years = today - bday;
    console.log(years);

    // alert("BDAY: " + bday + "\nTODAY: " + today + "\nYEAR: " + years);
    if (years < 13) {
        // document.getElementById("ageError").style = "visibility: visible";
        // bday.style = "border : 2px solid red";
        alert("Age must be greater than 15")
    } else {
        // document.getElementById("ageError").style = "visibility: hidden";
        document.getElementById("date").style = "border : 2px solid green";
    }

}


function validateAddress(){
    if(document.getElementById("addr").value.length != 0){
        document.getElementById("addr").style = "border : 2px solid green";
    }else{
        document.getElementById("addr").style = "border : 2px solid red";
    }
}

function validatePass(){
	console.log('Came Here');
	var re = /^(?=.*[0-9])(?=.*[A-Z])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{6,16}$/;
	pass = document.getElementById('pass').value;
	console.log(pass);
	if(re.test(pass)){
		document.getElementById("pass").style = "border : 2px solid green";
	}else{
		document.getElementById("pass").style = "border : 2px solid red";
	}
}

function confirmPass(){
	pass = document.getElementById('pass').value;
	cpass = document.getElementById('cpass').value;
	console.log(pass)
	console.log(cpass)
	console.log(cpass === pass)
	
	if(cpass === pass){
		document.getElementById("cpass").style = "border : 2px solid green";

		document.getElementById('cpassError').style="visibility:hidden;";
	}else{
		document.getElementById('cpassError').style="visibility:visible;color:#FF0000";
		document.getElementById("cpass").style = "border : 2px solid red";
	}
}