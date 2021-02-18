package com.example.myapplication;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.GridView;
import android.widget.ImageView;

public class ImageAdapter extends BaseAdapter {

    private Context mCon;
    public int[] imageIds = {
            R.drawable.img1,R.drawable.img2,R.drawable.img3,
            R.drawable.img6,R.drawable.img5,R.drawable.img4,
            R.drawable.img7,R.drawable.img8,R.drawable.img9,
            R.drawable.img12,R.drawable.img11,R.drawable.img10,
            R.drawable.img13,R.drawable.img14,R.drawable.img15,
            R.drawable.img18,R.drawable.img17,R.drawable.img16
    };

    public ImageAdapter(Context mCon) {
        this.mCon = mCon;
    }

    @Override
    public int getCount() {
        return imageIds.length;
    }

    @Override
    public Object getItem(int position) {
        return imageIds[position];
    }

    @Override
    public long getItemId(int position) {
        return 0;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ImageView imgView = new ImageView(mCon);
        imgView.setImageResource(imageIds[position]);
        imgView.setScaleType(ImageView.ScaleType.CENTER);
        imgView.setLayoutParams(new GridView.LayoutParams(300,400));
        return imgView;
    }
}
