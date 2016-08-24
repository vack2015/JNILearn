package org.vackapi.jnilearn;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        textView= (TextView) findViewById(R.id.textView);
        JNILearn jniLearn=new JNILearn();
        jniLearn.test();
        textView.setText(jniLearn.stringFromJNI());
        jniLearn.show();
    }
}
