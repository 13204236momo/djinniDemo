package com.zhoumohan.djinni;

import android.content.Context;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.Signature;
import android.os.Bundle;
import android.util.Log;

import androidx.appcompat.app.AppCompatActivity;

import com.zhoumohan.djinni.databinding.ActivityMain2Binding;
import com.zhoumohan.djinni.gen.SexModeEnum;
import com.zhoumohan.djinni.gen.TestDjnniInterface;
import com.zhoumohan.djinni.gen.TestInfoStore;

import java.security.MessageDigest;
import java.util.concurrent.ConcurrentHashMap;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("mytest");
    }

    ActivityMain2Binding binding;

    ConcurrentHashMap

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMain2Binding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        binding.btn.setOnClickListener(view -> {

//            TestDjnniInterface djnniInterface = TestDjnniInterface.newInstance();
//            TestInfoStore infoStore = new TestInfoStore(1234,"测试测试","djinni", SexModeEnum.SEX_MAN);
//            String a = djnniInterface.show(infoStore);
//            binding.tv.setText(a);

             String a = getAppSignature(this,"com.zhoumohan.djinni","md5");
            Log.e("zhou",a);
        });
    }

    public static String getAppSignature(Context context, String pkgName, String algorithm) {
        try {
            PackageInfo packageInfo = context.getPackageManager().getPackageInfo(
                    pkgName, PackageManager.GET_SIGNATURES);
            Signature[] signs = packageInfo.signatures;
            Signature sign = signs[0];
            String signStr = hexDigest(sign.toByteArray(), algorithm);
            return signStr;
        } catch (PackageManager.NameNotFoundException e) {
            e.printStackTrace();
        }
        return "";
    }

    public static String hexDigest(byte[] bytes, String algorithm) {
        MessageDigest md5;
        try {
            md5 = MessageDigest.getInstance(algorithm);
        } catch (Exception e) {
            e.printStackTrace();
            return "";
        }
        byte[] md5Bytes = md5.digest(bytes);
        StringBuffer hexValue = new StringBuffer();
        for (int i = 0; i < md5Bytes.length; i++) {
            int val = ((int) md5Bytes[i]) & 0xff;
            if (val < 16) {
                hexValue.append("0");
            }
            hexValue.append(Integer.toHexString(val));
        }
        return hexValue.toString();
    }

}