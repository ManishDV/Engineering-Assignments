package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Button login = (Button) findViewById(R.id.btnLogin);
        EditText etName = (EditText) findViewById(R.id.username);
        EditText etPass = (EditText) findViewById(R.id.password);
        login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(etName.getText().toString().length() != 0 && etPass.getText().toString().length() !=0) {
                    Intent i = new Intent(getApplicationContext(), MainActivity2.class);
                    i.putExtra("name", etName.getText().toString());
                    startActivity(i);
                }else{
                    Toast.makeText(getApplicationContext(),"Username and Password Must Not Be Empty!",Toast.LENGTH_LONG).show();
                }
            }
        });
    }
}