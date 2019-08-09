function validateName() {
  form = document.getElementById('registerForm');
  fname = document.getElementById('fname').value;
  lname = document.getElementById('lname').value;
  rename = /^[a-zA-Z ]{2,30}$/;
  if (fname.length != 0 && rename.test(fname)) {
    form.fname.style = "border:1px solid green";
  }
  else {
    form.fname.style = "border:1px solid red";
    document.getElementById('ferr').innerHTML = "Error";
  }
  if (lname.length != 0 && rename.test(lname)) {

    form.lname.style = "border:1px solid green";
  }
  else {

    form.lname.style = "border:1px solid red";
  }
}
function validateAddress() {
  form = document.getElementById('registerForm');
  addr = document.getElementById('addr').value;

  if (addr.length != 0) {
    form.addr.style = "border:1px solid green";
  }
  else {
    form.addr.style = "border:1px solid red";
  }

}


function validatePin() {
  form = document.getElementById('registerForm');
  pin = document.getElementById('pin').value;
  var pinre = /^\d{6}$/;
  if (pin.length != 0 && pinre.test(pin)) {
    form.pin.style = "border:1px solid green";
  }
  else {
    form.pin.style = "border:1px solid red";
  }

}

function validate() {

  form = document.getElementById('registerForm');
  fname = document.getElementById('fname').value;
  lname = document.getElementById('lname').value;
  pass = document.getElementById('pass').value;
  uname = document.getElementById('username').value;
  cpass = document.getElementById('cpass').value;
  email = document.getElementById('email').value;
  phone = document.getElementById('phone').value;
  addr = document.getElementById('addr').value;
  pin = document.getElementById('pin').value;
  radio1 = document.getElementById('male');
  radio2 = document.getElementById('female');
  radio3 = document.getElementById('other');
  var re = /^(?=.*[0-9])(?=.*[A-Z])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{6,16}$/;
  var emailre = /^\w+([\.-]?\w+)*@\w+([\.-]?\w+)*(\.\w{2,3})+$/;
  var phoneno = /^\d{10}$/;
  var pinre = /^\d{6}$/;
  if (fname.length != 0) {
    if (lname.length != 0) {

      if (uname.length >= 6) {
        if (pass.length >= 6) {
          if (cpass.length == pass.length) {
            if (re.test(pass)) {
              if (cpass.value == pass.value) {
                if (emailre.test(email)) {
                  if (phoneno.test(phone)) {
                    if (pinre.test(pin)) {
                      if (radio1.checked || radio2.checked || radio3.checked) {
                        alert("Form Is Successfully Submitted");

                        return true;
                      }
                      else {
                        alert("Select Gender Please");
                        form.male.focus();
                        return false;
                      }

                    } else {
                      alert("Pin Number Should Contain only Digits or Length Should be 6 digits");
                      form.pin.focus();
                      return false;
                    }
                  } else {
                    alert("Phone Number Must be of length 10 and it must contains only digits");
                    form.phone.focus();
                    return false;
                  }
                } else {
                  alert("Incorrect Email");
                  form.email.focus();
                  return false;
                }
              } else {
                alert("Password Does Not Match");
                form.cpass.focus();
                return false;
              }
            } else {
              alert("password Must contain at least one Uppercase letter,one lowercase letter,one digit and Special Character");
              form.pass.focus();
              return false;
            }
          } else {
            alert("Password Does Not Match");
            form.cpass.focus();
            return false;
          }
        } else {
          alert("Length Of Password should at least be 6");
          form.pass.focus();
          return false;
        }
      } else {
        alert("\nLength Of Username Should be 6");
        form.username.focus();
        return false;
      }



    }
    else {
      alert("Enter Last Name");

      form.lname.focus();
      return false;
    }
  }
  else {
    alert("Enter First Name");

    form.fname.focus();
    return false;
  }


}