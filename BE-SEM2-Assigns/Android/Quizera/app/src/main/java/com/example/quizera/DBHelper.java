package com.example.quizera;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import androidx.annotation.Nullable;

public class DBHelper extends SQLiteOpenHelper {
    private String DB_NAME = "UsersDB";
    private String TABLE_NAME = "UserDetails";
    public DBHelper(@Nullable Context context) {
        super(context, "UsersDB", null, 1);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        String createTableQuery = "CREATE TABLE " + TABLE_NAME + " ( USERID INTEGER PRIMARY KEY AUTOINCREMENT, EMAIL TEXT,PHONE TEXT, USERNAME TEXT, PASSWORD TEXT);";
        db.execSQL(createTableQuery);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {

    }

    public boolean insertOne(UserModel user){
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues cv = new ContentValues();
        cv.put("EMAIL",user.getEmail());
        cv.put("USERNAME",user.getUsername());
        cv.put("PASSWORD",user.getPassword());
        cv.put("PHONE",user.getPhone());
        long insert = db.insert(TABLE_NAME, null, cv);
        Log.d("INSERT",Long.toString(insert));

        if(insert < 0)
            return false;
        return true;
    }

    public boolean testLogin(String username, String password){
        SQLiteDatabase db = this.getReadableDatabase();
        String query = "SELECT * FROM "+TABLE_NAME+" WHERE USERNAME='"+username+"' and PASSWORD='"+password+"'";
        Cursor cursor = db.rawQuery(query, null);
        if(cursor.moveToFirst()) {
            return true;
        }
        return false;

    }

}
