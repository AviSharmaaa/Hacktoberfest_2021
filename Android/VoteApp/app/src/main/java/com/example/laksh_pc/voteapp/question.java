package com.example.laksh_pc.voteapp;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;

import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;

public class question extends AppCompatActivity {

    TextView question;
    TextView option1;
    TextView option2;
    FirebaseDatabase firebaseDatabase;
    DatabaseReference databaseReference;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_question);
        question = (TextView) findViewById(R.id.ques);
        option1 = (TextView) findViewById(R.id.op1);
        option2 = (TextView) findViewById(R.id.op5);
        firebaseDatabase = FirebaseDatabase.getInstance();
        databaseReference = firebaseDatabase.getReference();
    }
    public void sendques(View view){
        databaseReference.child("Question").setValue(question.getText().toString());
        databaseReference.child("Option1").setValue(option1.getText().toString());
        databaseReference.child("Option2").setValue(option2.getText().toString());

    }
    public void openview(View view){
        Intent startview = new Intent(this,quesview.class);
        startActivity(startview);
    }
}
