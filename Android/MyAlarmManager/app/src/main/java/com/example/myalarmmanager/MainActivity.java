package com.example.myalarmmanager;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageButton;
import android.widget.TextView;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Locale;

public class MainActivity extends AppCompatActivity implements
        View.OnClickListener, DatePickerFragment.DialogDateListener,
        TimePickerFragment.DialogTimeListener {

    TextView tvOnceDate;
    TextView tvOnceTime;
    EditText edtOnceMessage;
    ImageButton btnOnceDate;
    ImageButton btnOnceTime;
    Button btnSetOnce;

    private AlarmReceiver alarmReceiver;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        tvOnceDate = findViewById(R.id.tv_once_date);
        btnOnceDate = findViewById(R.id.btn_once_date);
        tvOnceTime = findViewById(R.id.tv_once_time);
        btnOnceTime = findViewById(R.id.btn_once_time);
        edtOnceMessage = findViewById(R.id.edt_once_message);
        btnSetOnce = findViewById(R.id.btn_set_once_alarm);

        btnOnceDate.setOnClickListener(this);
        btnOnceTime.setOnClickListener(this);
        btnSetOnce.setOnClickListener(this);

        alarmReceiver = new AlarmReceiver();
    }
    final String DATE_PICKER_TAG = "DatePicker";
    final String TIME_PICKER_ONCE_TAG = "TimePickerOnce";
    final String TIME_PICKER_REPEAT_TAG = "TimePickerRepeat";

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_once_date:
                DatePickerFragment datePickerFragment = new DatePickerFragment();
                    datePickerFragment.show(getSupportFragmentManager(), DATE_PICKER_TAG);
                    break;
             case R.id.btn_once_time:
                 TimePickerFragment timePickerFragmentOne = new TimePickerFragment();
                    timePickerFragmentOne.show(getSupportFragmentManager(), TIME_PICKER_ONCE_TAG);
                    break;
             case R.id.btn_set_once_alarm:
                 String onceDate = tvOnceDate.getText().toString();
                 String onceTime = tvOnceTime.getText().toString();
                 String onceMessage = edtOnceMessage.getText().toString();

                 alarmReceiver.setOneTimeAlarm(this,
                         AlarmReceiver.TYPE_ONE_TIME,
                         onceDate,
                         onceTime,
                         onceMessage);
                 break;
        }
    }

    @Override
    public void onDialogDateSet(String tag, int year, int month, int dayOfMonth) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month, dayOfMonth);
        SimpleDateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd", Locale.getDefault());

        tvOnceDate.setText(dateFormat.format(calendar.getTime()));
    }

    @Override
    public void onDialogTimeSet(String tag, int hourOfDay, int minute) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(Calendar.HOUR_OF_DAY, hourOfDay);
        calendar.set(Calendar.MINUTE, minute);

        SimpleDateFormat dateFormat = new SimpleDateFormat("HH:mm", Locale.getDefault());

        switch (tag) {
            case TIME_PICKER_ONCE_TAG:
                tvOnceTime.setText(dateFormat.format(calendar.getTime()));
                break;
            default:
                break;
         }
    }
}