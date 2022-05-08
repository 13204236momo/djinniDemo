package com.zhoumohan.djinni;

import android.os.Bundle;
import androidx.appcompat.app.AppCompatActivity;
import com.zhoumohan.djinni.databinding.ActivityMain2Binding;
import com.zhoumohan.djinni.gen.SexModeEnum;
import com.zhoumohan.djinni.gen.TestDjnniInterface;
import com.zhoumohan.djinni.gen.TestInfoStore;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("mytest");
    }

    ActivityMain2Binding binding;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMain2Binding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.btn.setOnClickListener(view -> {
            TestDjnniInterface djnniInterface = TestDjnniInterface.newInstance();
            TestInfoStore infoStore = new TestInfoStore(1234,"测试测试","djinni", SexModeEnum.SEX_MAN);
            String a = djnniInterface.show(infoStore);
            binding.tv.setText(a);
        });
    }
}