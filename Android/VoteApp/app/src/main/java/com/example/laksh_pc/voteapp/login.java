package com.example.laksh_pc.voteapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class login extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.login);
    }
    public void btn_reg(View v) {
        Intent i = new Intent(login.this, registration.class);
        startActivity(i);
    }
    public void btn_log(View v) {
        Intent i = new Intent(login.this, authenticate.class);
        startActivity(i);
    }
}

