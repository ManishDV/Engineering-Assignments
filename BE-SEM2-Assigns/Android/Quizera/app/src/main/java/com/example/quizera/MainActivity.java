package com.example.quizera;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    Button btnSignUp;
    EditText etUname;
    EditText etPass;
    Button btnLogin;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        getSupportActionBar().hide();

        etUname = findViewById(R.id.username);
        etPass = findViewById(R.id.password);
        btnLogin = findViewById(R.id.btnLogin);
        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    String uname = etUname.getText().toString().trim();
                    String pass = etPass.getText().toString().trim();
                    if(uname.length() != 0 && pass.length() != 0) {
                        DBHelper dbHelper = new DBHelper(getApplicationContext());
                        if (dbHelper.testLogin(uname,pass)) {
                            Intent i = new Intent(MainActivity.this,HomeActivity.class);
//                            Log.d("Error","Fine IN hERE");
                            i.putExtra("User",uname);
                            startActivity(i);
                        } else {
                            Toast.makeText(getApplicationContext(), "Username or Password is Wrong", Toast.LENGTH_LONG).show();
                        }
                    }else{
                        Toast.makeText(getApplicationContext(), "All Fields Are Mandatory", Toast.LENGTH_LONG).show();
                    }

                }catch(Exception e){
                    Toast.makeText(MainActivity.this, e.toString(), Toast.LENGTH_LONG).show();
                }

            }
        });


        btnSignUp = (Button) findViewById(R.id.btnSignUp);
        btnSignUp.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this,SignUpActivity.class));
            }
        });
    }

    public boolean validate(String uname, String password){

        return true;
    }

}