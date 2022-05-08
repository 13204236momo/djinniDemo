// AUTOGENERATED FILE - DO NOT MODIFY!
// This file generated by Djinni from info.djinni

package com.zhoumohan.djinni.gen;

import java.util.concurrent.atomic.AtomicBoolean;

public abstract class TestDjnniInterface {
    public static final int VERSION = 1;

    public abstract String show(TestInfoStore testInfo);

    public static TestDjnniInterface newInstance()
    {
        return CppProxy.newInstance();
    }

    private static final class CppProxy extends TestDjnniInterface
    {
        private final long nativeRef;
        private final AtomicBoolean destroyed = new AtomicBoolean(false);

        private CppProxy(long nativeRef)
        {
            if (nativeRef == 0) throw new RuntimeException("nativeRef is zero");
            this.nativeRef = nativeRef;
        }

        private native void nativeDestroy(long nativeRef);
        public void _djinni_private_destroy()
        {
            boolean destroyed = this.destroyed.getAndSet(true);
            if (!destroyed) nativeDestroy(this.nativeRef);
        }
        protected void finalize() throws java.lang.Throwable
        {
            _djinni_private_destroy();
            super.finalize();
        }

        @Override
        public String show(TestInfoStore testInfo)
        {
            assert !this.destroyed.get() : "trying to use a destroyed object";
            return native_show(this.nativeRef, testInfo);
        }
        private native String native_show(long _nativeRef, TestInfoStore testInfo);

        public static native TestDjnniInterface newInstance();
    }
}