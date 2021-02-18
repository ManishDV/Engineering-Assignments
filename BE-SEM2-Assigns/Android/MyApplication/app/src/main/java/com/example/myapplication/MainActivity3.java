package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.media.Image;
import android.os.Bundle;
import android.widget.ImageView;

public class MainActivity3 extends AppCompatActivity {
    ImageView imgView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main3);
        getSupportActionBar().hide();

        getSupportActionBar().setTitle("Full Screen Image");
        Intent i = getIntent();
        int pos = i.getExtras().getInt("id");

        ImageAdapter imgAd = new ImageAdapter(this);

        imgView = (ImageView) findViewById(R.id.imageView);
        imgView.setImageResource(imgAd.imageIds[pos]);

    }
}