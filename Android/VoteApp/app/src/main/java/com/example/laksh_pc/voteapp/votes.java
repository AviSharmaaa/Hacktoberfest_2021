package com.example.laksh_pc.voteapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class votes extends AppCompatActivity {

    private DatabaseReference mdata1;
    private DatabaseReference mdata2;
    private DatabaseReference mdata3;
    private DatabaseReference mdata4;
    private TextView status1;
    private TextView status2;
    private TextView status3;
    private TextView status4;
    int yes;
    int no;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_votes);
        mdata1 = FirebaseDatabase.getInstance().getReference();
        mdata2 = FirebaseDatabase.getInstance().getReference();
        mdata3 = FirebaseDatabase.getInstance().getReference();
        mdata4 = FirebaseDatabase.getInstance().getReference();
        status1 = (TextView) findViewById(R.id.viewcount) ;
        status2 = (TextView) findViewById(R.id.viewcount1);
        status3 = (TextView) findViewById(R.id.viewcount2);
        status4 = (TextView) findViewById(R.id.viewcount3);


        mdata1.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                long size = dataSnapshot.child("Barack Obama").getChildrenCount();
                String output = String.valueOf(size);
                status1.setText(output);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });
        mdata2.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                long size1 = dataSnapshot.child("Donald Trump").getChildrenCount();
                String output1 = String.valueOf(size1);
                status2.setText(output1);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });
        mdata3.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                long size2 = dataSnapshot.child("Venkaiah Naidu").getChildrenCount();
                String output2 = String.valueOf(size2);
                status3.setText(output2);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });
        mdata4.addListenerForSingleValueEvent(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                long size3 = dataSnapshot.child("Banwarilal").getChildrenCount();
                String output3 = String.valueOf(size3);
                status4.setText(output3);
            }

            @Override
            public void onCancelled(DatabaseError databaseError) {

            }
        });

    }

}
