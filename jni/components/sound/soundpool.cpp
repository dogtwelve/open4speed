//----------------------------------------------------------------------------------------
/**
 * \file       soundpool.cpp
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      Loading and playing sound
*/
//----------------------------------------------------------------------------------------

#include "stdafx.h"

int samplesCount = 0;   ///< Amount of samples

#ifdef ANDROID
#include "jni.h"
#include "app.h"
#endif

/**
 * @brief soundpool destructor
 */
soundpool::~soundpool() {

}

/**
 * @brief fmodapi create sound from file
 * @param filename is name of file to load
 * @param loop is true for sound looping
 * @param c is amount of channels
 */
soundpool::soundpool(const char* filename, bool loop, int channels) {
#ifdef ANDROID
    id = samplesCount;
    samplesCount++;
    looping = loop;

    jclass clazz = instance->FindClass("com/lvonasek/o4s/O4SActivity");
    jmethodID method = instance->GetStaticMethodID(clazz, "soundLoad", "(Ljava/lang/String;)V");
    jstring jstr = instance->NewStringUTF(filename);
    instance->CallStaticVoidMethod(clazz, method, jstr);
#endif
}

/**
 * @brief close kills sound system
 */
void soundpool::close() {

}

/**
 * @brief play starts playing sound
 * @param index is index of instance to play
 */
void soundpool::play(int index) {
#ifdef ANDROID
    if (index == 0) {
        jclass clazz = instance->FindClass("com/lvonasek/o4s/O4SActivity");
        jmethodID method = instance->GetStaticMethodID(clazz, "soundPlay", "(II)V");
        instance->CallStaticVoidMethod(clazz, method, id, (int)looping);
    }
#endif
}

/**
 * @brief setFrequency sets frequency of sound
 * @param index is index of instance to set
 * @param hz is frequency of sound
 */
void soundpool::setFrequency(int index, float hz) {
#ifdef ANDROID
    if (index == 0) {
        jclass clazz = instance->FindClass("com/lvonasek/o4s/O4SActivity");
        jmethodID method = instance->GetStaticMethodID(clazz, "soundFreq", "(IF)V");
        instance->CallStaticVoidMethod(clazz, method, id, (float)(hz/50000.0+0.2));
    }
#endif
}

/**
 * @brief setPan sets pan of sound
 * @param index is index of instance to set
 * @param pan is stereo position
 */
void soundpool::setPan(int index, float pan) {

}

/**
 * @brief setVolume sets volume of sound
 * @param index is index of instance to set
 * @param volume is amount of volume
 */
void soundpool::setVolume(int index, float volume) {
#ifdef ANDROID
    if (index == 0) {
        jclass clazz = instance->FindClass("com/lvonasek/o4s/O4SActivity");
        jmethodID method = instance->GetStaticMethodID(clazz, "soundVolume", "(IF)V");
        instance->CallStaticVoidMethod(clazz, method, id, volume);
    }
#endif
}

/**
 * @brief stop stops playing sound
 * @param index is index of instance to stop
 */
void soundpool::stop(int index) {
#ifdef ANDROID
    if (index == 0) {
        jclass clazz = instance->FindClass("com/lvonasek/o4s/O4SActivity");
        jmethodID method = instance->GetStaticMethodID(clazz, "soundStop", "(I)V");
        instance->CallStaticVoidMethod(clazz, method, id);
    }
#endif
}
