package com.example.quizera;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.TextView;

public class HomeActivity extends AppCompatActivity {

    TextView tvUname;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_home);
        tvUname = findViewById(R.id.txtUname);
        Intent i = getIntent();
        String s = i.getStringExtra("User");
        tvUname.setText("Welcome "+ s);
    }
}