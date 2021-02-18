package com.example.quizera;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.regex.Pattern;

public class SignUpActivity extends AppCompatActivity {

    EditText etEmail;
    EditText etPhone;
    EditText etPass;
    EditText etUsername;
    EditText etCPass;
    Button btnRegister;
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sign_up);
        getSupportActionBar().hide();

        etEmail =  findViewById(R.id.emailId);
        etPhone =  findViewById(R.id.phone);
        etUsername =  findViewById(R.id.unameSignUp);
        etPass =  findViewById(R.id.signUpPass);
        etCPass =  findViewById(R.id.cpass);
        btnRegister =  findViewById(R.id.btnSUP);

        btnRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String email = etEmail.getText().toString().trim();
                String phone = etPhone.getText().toString().trim();
                String username = etUsername.getText().toString().trim();
                String pass = etPass.getText().toString().trim();
                boolean emailValidation = validateEmail(email);
                boolean phoneVal = validatePhone(phone);
                boolean userval = validateUserName(username);
                boolean passVal = validatePass(pass);

                if(emailValidation){
                    if(phoneVal){
                        if(userval){
                            if(passVal){
                                if(pass.equals(etCPass.getText().toString().trim())){
                                    try {
                                        DBHelper dbHelper = new DBHelper(getApplicationContext());
                                        UserModel user = new UserModel(email,phone,username,pass);
                                        if(dbHelper.insertOne(user)){
                                            Toast.makeText(SignUpActivity.this, "User Added Go Back To LOGIN", Toast.LENGTH_SHORT).show();
                                        }else{
                                            Toast.makeText(SignUpActivity.this, "Error In Adding a User", Toast.LENGTH_SHORT).show();
                                        }
                                    }catch (Exception e){
                                        Toast.makeText(SignUpActivity.this, e.toString(), Toast.LENGTH_SHORT).show();
                                    }
                                }else{
                                    Toast.makeText(SignUpActivity.this, "Passwords Do Not Match", Toast.LENGTH_SHORT).show();
                                }
                            }else{
                                Toast.makeText(SignUpActivity.this, "Password Must Contain At least 1 Uppercase letter,1 Lowercase letter,1 Special Symbol and 1 digit and length should be greater than 6", Toast.LENGTH_SHORT).show();
                            }
                        }else{
                            Toast.makeText(SignUpActivity.this, username + " Username Must be of Length 6", Toast.LENGTH_SHORT).show();
                        }
                    }else{
                        Toast.makeText(SignUpActivity.this, "Invalid Phone Number", Toast.LENGTH_SHORT).show();
                    }
                }else{
                    Toast.makeText(SignUpActivity.this, "Invalid Email Address", Toast.LENGTH_SHORT).show();
                }

            }
        });



    }

    public boolean validateEmail(String email){
        Pattern pattern = Patterns.EMAIL_ADDRESS;
        return pattern.matcher(email).matches();
    }

    public boolean validatePhone(String phone){

        if(!Pattern.matches("^[789][0-9]{9}$",phone)){
            return false;
        }
        return true;
    }

    public boolean validateUserName(String uname){
        if(uname.length() < 6) return false;
        return true;
    }

    public boolean validatePass(String pass){
        if(!Pattern.matches("^(?=.*[0-9])(?=.*[A-Z])(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{6,16}$",pass)){
            return false;
        }
        return true;
    }
}