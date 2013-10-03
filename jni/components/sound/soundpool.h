//----------------------------------------------------------------------------------------
/**
 * \file       soundpool.h
 * \author     Vonasek Lubos
 * \date       2013/04/20
 * \brief      Loading and playing sound
*/
//----------------------------------------------------------------------------------------

#ifndef SOUNDPOOL_H
#define SOUNDPOOL_H

#include "stdafx.h"

/**
 * @brief The soundpool class
 */
class soundpool : public sound {
public:

    int id;         ///< Is sample ID
    bool looping;   ///< Looping enability

    /**
     * @brief fmodapi create sound from file
     * @param filename is name of file to load
     * @param loop is true for sound looping
     * @param c is amount of channels
     */
    soundpool(const char* filename, bool loop, int c);

    /**
     * @brief soundpool destructor
     */
    virtual ~soundpool();

    /**
     * @brief close kills sound system
     */
    void close();

    /**
     * @brief play starts playing sound
     * @param index is index of instance to play
     */
    void play(int index);

    /**
     * @brief setFrequency sets frequency of sound
     * @param index is index of instance to set
     * @param hz is frequency of sound
     */
    void setFrequency(int index, float hz);

    /**
     * @brief setPan sets pan of sound
     * @param index is index of instance to set
     * @param pan is stereo position
     */
    void setPan(int index, float pan);

    /**
     * @brief setVolume sets volume of sound
     * @param index is index of instance to set
     * @param volume is amount of volume
     */
    void setVolume(int index, float volume);

    /**
     * @brief stop stops playing sound
     * @param index is index of instance to stop
     */
    void stop(int index);
};

#endif // SOUNDPOOL_H
