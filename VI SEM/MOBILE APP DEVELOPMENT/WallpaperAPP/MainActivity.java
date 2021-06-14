package com.example.wallpaperapp;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.content.ContextCompat;

import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;

import java.util.Random;

public class MainActivity extends AppCompatActivity {
    Button changeButton;
    View screenView;
    int[] wallpapers;
    Handler handler;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        changeButton = (Button)findViewById(R.id.button);
        screenView = (View)findViewById(R.id.screenLayout);
        wallpapers = new int[]{

                R.drawable.phone1,
                R.drawable.phone2,
                R.drawable.phone3,
                R.drawable.phone4,
                R.drawable.phone5
        };

        handler = new Handler();


        changeButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handler.postDelayed(runnable, 0);
                changeButton.setVisibility(View.GONE);
            }
        });
    }

    public Runnable runnable = new Runnable() {
        @Override
        public void run() {
            int numWallpapers = wallpapers.length;
            Random random = new Random();
            int randomIdx = random.nextInt(numWallpapers);

            screenView.setBackground(
                    ContextCompat.getDrawable(getApplicationContext(), wallpapers[randomIdx])
            );

            handler.postDelayed(this, 3000);
        }
    };
}