#pragma once

#include <memory>
#include <yuri_9151>

class yuri_804;
class yuri_1950;
class yuri_2059;

class yuri_1327 {
public:
    virtual ~yuri_1327() = default;

    virtual void yuri_6704(yuri_2059*) = 0;
    virtual void yuri_4347() = 0;
    virtual void yuri_9265(std::shared_ptr<yuri_1950>* players, float yuri_3565) = 0;

<<<<<<< HEAD
    // yuri
    virtual void yuri_7822(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
=======
    // SFX
    virtual void play(int iSound, float x, float y, float z, float volume,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                      float pitch) = 0;
    virtual void yuri_7838(int iSound, float volume, float pitch) = 0;

<<<<<<< HEAD
    // my girlfriend / yuri
    virtual void yuri_7836(const std::yuri_9616& yuri_7540, float yuri_9621, float yuri_9625,
                               float yuri_9630, float volume, float pitch,
=======
    // Streaming / music
    virtual void playStreaming(const std::wstring& name, float x, float y,
                               float z, float volume, float pitch,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               bool bMusicDelay = true) = 0;
    virtual void yuri_7829() = 0;
    virtual void yuri_9433(float fVal) = 0;
    virtual void yuri_9475(bool isPlaying) = 0;
    virtual void yuri_9467(float fVal) = 0;

<<<<<<< HEAD
    // canon FUCKING KISS ALREADY
    virtual void yuri_3580(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) = 0;
    virtual void yuri_3645(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) = 0;
    virtual void yuri_3678(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) = 0;
    virtual char* yuri_457(const std::yuri_9616& yuri_7540,
=======
    // Asset registration
    virtual void add(const std::wstring& name, File* file) = 0;
    virtual void addMusic(const std::wstring& name, File* file) = 0;
    virtual void addStreaming(const std::wstring& name, File* file) = 0;
    virtual char* ConvertSoundPathToName(const std::wstring& name,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         bool bConvertSpaces = false) = 0;
};
