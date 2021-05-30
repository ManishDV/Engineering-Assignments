$("document").ready(function() {

    let firstName = false;
    let lastName = false;
    let address = false;
    let pinNo = false;
    let DOB = false;
    let userName = false;
    let password = false;
    let cpassword = false;
    let emailId = false;
    let phoneNo = false;


    $("#addr").keyup(function() {
        let addr = $("#addr").val();
        if (addr.length != 0) {
            $("#addr").css('border', '2px solid green');
            $("#addrError").css('visibility', 'hidden');
            $("#addrError").slideUp();
            address = true;
        } else {
            $("#addrError").slideDown();
            $("#addr").css('border', '2px solid red');
            $("#addrError").css('font-size', '12px');
            $("#addrError").css('color', 'red');
            $("#addrError").css('visibility', 'visible');
            $("#addr").focus();
            address = false;
        }
    });


    $("#fname").keyup(function() {
        let fname = $("#fname").val();
        let rename = new RegExp('^[a-zA-Z]{2,30}$');
        if (fname.length != 0 && rename.test(fname)) {
            $("#fname").css('border', '2px solid green');
            $("#fnameError").css('visibility', 'hidden');
            $("#fnameError").slideUp();
            firstName = true;
        } else {
            $("#fnameError").slideDown();
            $("#fname").css('border', '2px solid red');
            $("#fnameError").css('font-size', '12px');
            $("#fnameError").css('color', 'red');
            $("#fnameError").css('visibility', 'visible');
            $("#fname").focus();
            firstName = false;
        }
    });

    $("#lname").keyup(function() {
        let lname = $("#lname").val();
        let rename = new RegExp('^[a-zA-Z]{2,30}$');
        if (lname.length != 0 && rename.test(lname)) {
            $("#lname").css('border', '2px solid green');
            $("#lnameError").css('visibility', 'hidden');
            $("#lnameError").slideUp();
            lastName = true;

        } else {
            $("#lnameError").slideDown();
            $("#lname").css('border', '2px solid red');
            $("#lnameError").css('font-size', '12px');
            $("#lnameError").css('color', 'red');
            $("#lnameError").css('visibility', 'visible');
            $("#lname").focus();
            lastName = false;

        }
    });

    $("#pin").keyup(function() {
        let pin = $("#pin").val();
        let repin = new RegExp('^\[0-9]{6}$');
        if (pin.length != 0 && repin.test(pin)) {
            $("#pin").css('border', '2px solid green');
            $("#pinError").css('display', 'none');
            $("#pinError").slideUp();
            pinNo = true;

        } else {
            $("#pinError").slideDown();
            $("#pin").css('border', '2px solid red');
            $("#pinError").css('font-size', '12px');
            $("#pinError").css('color', 'red');
            $("#pinError").css('display', 'block');
            $("#pin").focus();
            pinNo = false;
        }
    });

    $("#date").keyup(function() {
        let bday = new Date($("#date").val());
        bday = bday.getFullYear();
        let today = new Date();
        today = today.getFullYear();
        let years = today - bday;
        if (years < 15) {
            $("#ageError").slideDown();
            $("#date").css('border', '2px solid red');
            $("#ageError").css('font-size', '12px');
            $("#ageError").css('color', 'red');
            $("#ageError").css('display', 'block');
            $("#date").focus();
            DOB = false;
            // alert("Age must be greater than 15")
        } else {
            $("#ageError").slideUp();
            $("#date").css('border', '2px solid green');
            DOB = true;
        }
    });

    $("#username").keyup(function() {

        let uname = $("#username").val();
        if (uname.length < 6) {
            $("#userError").slideDown();
            $("#username").css('border', '2px solid red');
            $("#userError").css('font-size', '12px');
            $("#userError").css('color', 'red');
            $("#userError").css('display', 'block');
            $("#username").focus();
            userName = false;
        } else {
            $("#userError").slideUp();
            $("#username").css('border', '2px solid green');
            userName = true;

        }

    });

    $("#pass").keyup(function() {

        let pass = $("#pass").val();
        let passre = new RegExp('^(?=.*[0-9])(?=.*[A-Z])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{6,16}$');
        if (pass.length != 0 && passre.test(pass)) {
            $("#passError").slideUp();
            $("#pass").css('border', '2px solid green');
            password = true;

        } else {
            $("#passError").slideDown();
            $("#pass").css('border', '2px solid red');
            $("#passError").css('font-size', '12px');
            $("#passError").css('color', 'red');
            $("#passError").css('display', 'block');
            $("#pass").focus();
            password = false;
        }

    });

    $("#cpass").keyup(function() {

        let pass = $("#pass").val();
        let cpass = $("#cpass").val();
        if (pass == cpass) {
            $("#cpassError").slideUp();
            $("#cpass").css('border', '2px solid green');
            cpassword = true;

        } else {
            $("#cpassError").slideDown();
            $("#cpass").css('border', '2px solid red');
            $("#cpassError").css('font-size', '12px');
            $("#cpassError").css('color', 'red');
            $("#cpassError").css('display', 'block');
            $("#cpass").focus();
            cpassword = false;

        }

    });

    $("#email").keyup(function() {

        let email = $("#email").val();
        let emailre = new RegExp('^[0-9a-zA-z.]{1,}[0-9a-zA-z.]{0,}[@]{1}[a-zA-Z]{1,10}[.]{1}[a-zA-Z]{2,5}');
        if (email.length != 0 && emailre.test(email)) {
            $("#mailError").slideUp();
            $("#email").css('border', '2px solid green');
            emailId = true;
        } else {
            $("#mailError").slideDown();
            $("#email").css('border', '2px solid red');
            $("#mailError").css('font-size', '12px');
            $("#mailError").css('color', 'red');
            $("#mailError").css('display', 'block');
            $("#email").focus();
            emailId = false;

        }

    });

    $("#phone").keyup(function() {

        let phone = $("#phone").val();
        let phonere = new RegExp('^[789]{1}[0-9]{9}$');
        if (phone.length != 0 && phonere.test(phone)) {
            $("#phoneError").slideUp();
            $("#phone").css('border', '2px solid green');
            phoneNo = true;
        } else {
            $("#phoneError").slideDown();
            $("#phone").css('border', '2px solid red');
            $("#phoneError").css('font-size', '12px');
            $("#phoneError").css('color', 'red');
            $("#phoneError").css('display', 'block');
            $("#phone").focus();
            phoneNo = false;
        }

    });


    $("#submitBtn").click(function(e) {

        if (firstName && lastName && address && pinNo && DOB && userName && password && cpassword && emailId && phoneNo) {
            return true;
        } else {
            e.preventDefault();
            return false;
        }

    });


});