package com.example.laksh_pc.voteapp;

import android.app.ProgressDialog;
import android.content.Intent;
import android.support.annotation.NonNull;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.gms.tasks.OnCompleteListener;
import com.google.android.gms.tasks.Task;
import com.google.firebase.auth.AuthResult;
import com.google.firebase.auth.FirebaseAuth;

public class registration extends AppCompatActivity {

    private EditText txtemailaddr;
    private EditText txtpwd;
    private FirebaseAuth firebaseAuth;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_registration);
        txtemailaddr = (EditText) findViewById(R.id.emailreg);
        txtpwd = (EditText) findViewById(R.id.pwdreg);
        firebaseAuth = firebaseAuth.getInstance();
    }
    public void btnuserreg(View v){
        (firebaseAuth.createUserWithEmailAndPassword(txtemailaddr.getText().toString(),txtpwd.getText().toString())).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {

                if (task.isSuccessful()) {
                    Toast.makeText(registration.this, "Registration Successful", Toast.LENGTH_LONG).show();
                    Intent i = new Intent(registration.this, authenticate.class);
                    startActivity(i);

                } else {
                    Log.e("Error", task.getException().toString());
                    Toast.makeText(registration.this, task.getException().getMessage(), Toast.LENGTH_LONG).show();

                }
            }

        });

    }
}
