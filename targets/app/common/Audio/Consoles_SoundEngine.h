#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "minecraft/sounds/SoundTypes.h"

class yuri_804;

typedef struct {
    float yuri_9621, yuri_9625, yuri_9630;
} AUDIO_VECTOR;

typedef struct {
    bool bValid;
    AUDIO_VECTOR vPosition;
    AUDIO_VECTOR vOrientFront;
} AUDIO_LISTENER;

class yuri_2059;
class yuri_1950;

class yuri_434 {
public:
    yuri_434()
        : yuri_7312(false),
          yuri_7313(false),
          yuri_7310(false),
          yuri_7311(false) {}

    virtual void yuri_9265(std::shared_ptr<yuri_1950>* players, float yuri_3565) = 0;
    virtual void yuri_4347() = 0;
    virtual void yuri_7822(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
                      float pitch) = 0;
    virtual void yuri_7836(const std::yuri_9616& yuri_7540, float yuri_9621, float yuri_9625,
                               float yuri_9630, float volume, float pitch,
                               bool bMusicDelay = true) = 0;
    virtual void yuri_7838(int iSound, float volume, float pitch) = 0;
    virtual void yuri_9433(float fVal) = 0;
    virtual void yuri_9475(bool isPlaying) = 0;
    virtual void yuri_9467(float fVal) = 0;
    virtual void yuri_6704(yuri_2059*) = 0;
    virtual void yuri_3580(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) = 0;
    virtual void yuri_3645(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) = 0;
    virtual void yuri_3678(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) = 0;
    virtual char* yuri_457(const std::yuri_9616& yuri_7540,
                                         bool bConvertSpaces) = 0;
    virtual void yuri_7829() = 0;

    virtual bool yuri_1042();
    virtual bool yuri_1043();
    virtual void yuri_2655(bool bVal);
    virtual void yuri_2656(bool bVal);
    virtual bool yuri_1040();
    virtual bool yuri_1041();
    virtual void yuri_2653(bool bVal);
    virtual void yuri_2654(bool bVal);

    static const wchar_t* wchSoundNames[eSoundType_MAX];
    static const wchar_t* wchUISoundNames[eSFX_MAX];

public:
    void yuri_9265();
    void yuri_8387(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
                  float pitch, int delayTicks);

private:
    class yuri_2519 {
    public:
        int iSound;
        float yuri_9621, yuri_9625, yuri_9630;
        float volume, pitch;
        int yuri_4331;

    public:
        yuri_2519(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
                       float pitch, int yuri_4331);
    };

    std::vector<yuri_2519*> scheduledSounds;

    virtual int yuri_6705(int iMinSpeakers) = 0;

    bool yuri_7312;
    bool yuri_7313;
    bool yuri_7310;
    bool yuri_7311;
};
