package com.example.dialer;

import androidx.appcompat.app.AppCompatActivity;

import android.Manifest;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    Button zero, one, two, three, four, five, six, seven, eight, nine;
    Button star, hash, call, save, undo;
    TextView input;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        zero = findViewById(R.id.button0);
        one = findViewById(R.id.button1);
        two = findViewById(R.id.button2);
        three = findViewById(R.id.button3);
        four = findViewById(R.id.button4);
        five = findViewById(R.id.button5);
        six = findViewById(R.id.button6);
        seven = findViewById(R.id.button7);
        eight = findViewById(R.id.button8);
        nine = findViewById(R.id.button9);

        star = findViewById(R.id.buttonStar);
        hash = findViewById(R.id.buttonHash);
        call = findViewById(R.id.call);
        save = findViewById(R.id.addContact);
        undo = findViewById(R.id.clear);

        input = findViewById(R.id.display);

        zero.setOnClickListener(this::setValue);
        one.setOnClickListener(this::setValue);
        two.setOnClickListener(this::setValue);
        three.setOnClickListener(this::setValue);
        four.setOnClickListener(this::setValue);
        five.setOnClickListener(this::setValue);
        six.setOnClickListener(this::setValue);
        seven.setOnClickListener(this::setValue);
        eight.setOnClickListener(this::setValue);
        nine.setOnClickListener(this::setValue);
        star.setOnClickListener(this::setValue);
        hash.setOnClickListener(this::setValue);

        call.setOnClickListener(this::onClick);
        save.setOnClickListener(this::onClick);
        undo.setOnClickListener(this::onClick);

        // Hide Add to contacts button initially
        save.setVisibility(View.GONE);
    }

    private void setValue(View v) {
        if (save.getVisibility() == View.GONE)
            save.setVisibility(View.VISIBLE);

        input.setText(input.getText() + ((Button)v).getText().toString());
        System.out.println(((Button)v).getText());
        System.out.println(input.getText());
    }

    private void onClick(View v) {
        switch (v.getId()) {
            case R.id.clear:
                if (input.length() == 0) return; // Don't do anything when input is empty
                input.setText(input.getText().subSequence(0, input.length()-1));

                if (input.length() == 0)
                    save.setVisibility(View.GONE);
                break;

            case R.id.call:
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M &&
                    checkSelfPermission(Manifest.permission.CALL_PHONE) != PackageManager.PERMISSION_GRANTED) {
                    requestPermissions(new String[]{ Manifest.permission.CALL_PHONE }, 1);
                } else {
                    String phoneNo = input.getText().toString();
                    Intent intentCall = new Intent(Intent.ACTION_CALL);
                    intentCall.setData(Uri.parse("tel:"+phoneNo));
                    startActivity(intentCall);
                }
                break;

            case R.id.addContact:
                if (input.length() == 0) return; // Don't do anything when input is empty
                String contact = input.getText().toString();
                Intent intentSave = new Intent(ContactsContract.Intents.SHOW_OR_CREATE_CONTACT, Uri.parse("tel:"+contact));
                startActivity(intentSave);
                break;
        }
    }
}