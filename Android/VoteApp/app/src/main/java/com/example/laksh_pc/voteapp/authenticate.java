package com.example.laksh_pc.voteapp;

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

public class authenticate extends AppCompatActivity {

    private EditText txtemaillogin;
    private EditText txtpwd;
    private FirebaseAuth firebaseAuth;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_authenticate);
        txtemaillogin = (EditText) findViewById(R.id.emaillog);
        txtpwd = (EditText) findViewById(R.id.pwdlog);
        firebaseAuth = FirebaseAuth.getInstance();
    }
    public void btnuserlog(View v){
        (firebaseAuth.signInWithEmailAndPassword(txtemaillogin.getText().toString(), txtpwd.getText().toString())).addOnCompleteListener(new OnCompleteListener<AuthResult>() {
            @Override
            public void onComplete(@NonNull Task<AuthResult> task) {
                if(task.isSuccessful()) {
                    Toast.makeText(authenticate.this,"Login successful",Toast.LENGTH_LONG).show();
                    Intent i = new Intent(authenticate.this, navhome.class);
                    i.putExtra("Email", firebaseAuth.getCurrentUser().getEmail());
                    startActivity(i);
                }
                else{
                    Log.e("Error", task.getException().toString());
                    Toast.makeText(authenticate.this, task.getException().getMessage(),Toast.LENGTH_LONG).show();

                }
            }
        });

    }
}
