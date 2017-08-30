#include <jni.h>
#include <string>
#include <arm_neon.h>
extern "C" {
JNIEXPORT jintArray JNICALL
Java_meteor_asu_edu_speedytiltshift_SpeedyTiltShift_nativeTiltShift(JNIEnv *env,
                                                                    jobject This,
                                                                    jintArray pixels_,
                                                                    jint width, jint height,
                                                                    jint a0, jint a1, jint a2, jint a3, jfloat s_far, jfloat s_near
                                                                    ) {
    int32x4_t sum_vec = vdupq_n_s32(0);
    jint *pixels = env->GetIntArrayElements(pixels_, NULL);
    long length = env->GetArrayLength(pixels_);
    jintArray pixelsOut = env->NewIntArray(length);

    env->SetIntArrayRegion(pixelsOut, 0, length, pixels);
    env->ReleaseIntArrayElements(pixels_, pixels, 0);
    return pixelsOut;
}

JNIEXPORT jintArray JNICALL
Java_meteor_asu_edu_speedytiltshift_SpeedyTiltShift_nativeTiltShiftNeon(JNIEnv *env,
                                                                    jobject This,
                                                                    jintArray pixels_,
                                                                    jint width, jint height,
                                                                    jint a0, jint a1, jint a2, jint a3, jfloat s_far, jfloat s_near
) {
    int32x4_t sum_vec = vdupq_n_s32(0);
    jint *pixels = env->GetIntArrayElements(pixels_, NULL);
    long length = env->GetArrayLength(pixels_);
    jintArray pixelsOut = env->NewIntArray(length);

    env->SetIntArrayRegion(pixelsOut, 0, length, pixels);
    env->ReleaseIntArrayElements(pixels_, pixels, 0);
    return pixelsOut;
}
}