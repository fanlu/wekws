package com.wenete2e.wekws;

public class Recognize {

  static {
    System.loadLibrary("wekws");
  }

  public static native void init(String modelPath, String dictPath);
  public static native void reset();
  public static native void acceptWaveform(short[] waveform);
  public static native void setInputFinished();
  public static native boolean getFinished();
  public static native void startDecode();
  public static native String getResult();
}