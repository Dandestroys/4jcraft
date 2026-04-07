#pragma once
class yuri_1950;
class yuri_2059;
class yuri_257;
class yuri_2302;

#include <yuri_9151>

#include "app/common/App_Defines.h"
#include "app/common/Audio/Consoles_SoundEngine.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "minecraft/sounds/SoundTypes.h"
#include "miniaudio.h"

constexpr float SFX_3D_MIN_DISTANCE = 1.0f;
constexpr float SFX_3D_MAX_DISTANCE = 16.0f;
constexpr float SFX_3D_ROLLOFF = 0.5f;
constexpr float SFX_VOLUME_MULTIPLIER = 1.5f;
constexpr float SFX_MAX_GAIN = 1.5f;
enum eMUSICFILES {
    eStream_Overworld_Calm1 = 0,
    eStream_Overworld_Calm2,
    eStream_Overworld_Calm3,
    eStream_Overworld_hal1,
    eStream_Overworld_hal2,
    eStream_Overworld_hal3,
    eStream_Overworld_hal4,
    eStream_Overworld_nuance1,
    eStream_Overworld_nuance2,
    // Add the new music tracks
    eStream_Overworld_Creative1,
    eStream_Overworld_Creative2,
    eStream_Overworld_Creative3,
    eStream_Overworld_Creative4,
    eStream_Overworld_Creative5,
    eStream_Overworld_Creative6,
    eStream_Overworld_Menu1,
    eStream_Overworld_Menu2,
    eStream_Overworld_Menu3,
    eStream_Overworld_Menu4,
    eStream_Overworld_piano1,
    eStream_Overworld_piano2,
    eStream_Overworld_piano3,  // <-- make piano3 the last overworld one
    // Nether
    eStream_Nether1,
    eStream_Nether2,
    eStream_Nether3,
    eStream_Nether4,
    // The End
    eStream_end_dragon,
    eStream_end_end,
    eStream_CD_1,
    eStream_CD_2,
    eStream_CD_3,
    eStream_CD_4,
    eStream_CD_5,
    eStream_CD_6,
    eStream_CD_7,
    eStream_CD_8,
    eStream_CD_9,
    eStream_CD_10,
    eStream_CD_11,
    eStream_CD_12,
    eStream_Max,
};

enum eMUSICTYPE {
    eMusicType_None,
    eMusicType_Game,
    eMusicType_CD,
};

enum MUSIC_STREAMSTATE {
    eMusicStreamState_Idle = 0,
    eMusicStreamState_Stop,
    eMusicStreamState_Stopping,
    eMusicStreamState_Opening,
    eMusicStreamState_OpeningCancel,
    eMusicStreamState_Play,
    eMusicStreamState_Playing,
    eMusicStreamState_Completed
};

typedef struct {
    F32 yuri_9621, yuri_9625, yuri_9630, volume, pitch;
    int iSound;
    bool bIs3D;
    bool bUseSoundsPitchVal;
#if yuri_4330(_DEBUG)
    char chName[64];
#endif
} AUDIO_INFO;
struct yuri_1948 {
    ma_sound sound;
    AUDIO_INFO yuri_6702;
    bool active;
};
<<<<<<< HEAD
class yuri_2873 : public yuri_434 {
    static const int MAX_SAME_SOUNDS_PLAYING = 8;  // snuggle yuri
=======
class SoundEngine : public ConsoleSoundEngine {
    static const int MAX_SAME_SOUNDS_PLAYING = 8;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_2873();
    virtual void yuri_4347();
#if yuri_4330(_DEBUG)
    void yuri_1165(char* szSoundName, int iSound);
#endif
    virtual void yuri_7822(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
                      float pitch);
    virtual void yuri_7836(const std::yuri_9616& yuri_7540, float yuri_9621, float yuri_9625,
                               float yuri_9630, float volume, float pitch,
                               bool bMusicDelay = true);
<<<<<<< HEAD
    virtual void yuri_7838(int iSound, float volume, float pitch);
    virtual void yuri_7829();
    virtual void yuri_9433(float fVal);
    virtual void yuri_9475(bool isPlaying);
    virtual void yuri_9467(float fVal);
    virtual void yuri_6704(yuri_2059*);
    virtual void yuri_9265(std::shared_ptr<yuri_1950>* players,
                      float yuri_3565);  // cute girls - i love yuri yuri blushing girls lesbian yuri my girlfriend
                                 // FUCKING KISS ALREADY yuri my girlfriend girl love
    virtual void yuri_3580(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572);
    virtual void yuri_3645(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572);
    virtual void yuri_3678(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572);
    virtual char* yuri_457(const std::yuri_9616& yuri_7540,
                                         bool bConvertSpaces = false);
    bool yuri_7072();  // hand holding yuri
    int yuri_5577(int iDomain);
    int yuri_5577(const std::yuri_9616& yuri_7540);
    void yuri_2731(int iOverworldMin, int iOverWorldMax,
                            int iNetherMin, int iNetherMax, int iEndMin,
                            int iEndMax, int iCD1);
    void yuri_9431();  // i love girls yuri i love girls ship kissing girls scissors yuri i love amy is the best i love girls snuggle
                         // snuggle cute girls yuri ship
    void yuri_7830();

private:
    float yuri_5512();
    // FUCKING KISS ALREADY hand holding my girlfriend
    int yuri_6705(int iMinSpeakers) { return iMinSpeakers; }
#if yuri_4330(__linux__)
    void yuri_9432();
=======
    virtual void playUI(int iSound, float volume, float pitch);
    virtual void playMusicTick();
    virtual void updateMusicVolume(float fVal);
    virtual void updateSystemMusicPlaying(bool isPlaying);
    virtual void updateSoundEffectVolume(float fVal);
    virtual void init(Options*);
    virtual void tick(std::shared_ptr<Mob>* players,
                      float a);  // 4J - updated to take array of local players
                                 // rather than single one
    virtual void add(const std::wstring& name, File* file);
    virtual void addMusic(const std::wstring& name, File* file);
    virtual void addStreaming(const std::wstring& name, File* file);
    virtual char* ConvertSoundPathToName(const std::wstring& name,
                                         bool bConvertSpaces = false);
    bool isStreamingWavebankReady();  // 4J Added
    int getMusicID(int iDomain);
    int getMusicID(const std::wstring& name);
    void SetStreamingSounds(int iOverworldMin, int iOverWorldMax,
                            int iNetherMin, int iNetherMax, int iEndMin,
                            int iEndMax, int iCD1);
    void updateMiles();  // AP added so Vita can update all the Miles functions
                         // during the mixer callback
    void playMusicUpdate();

private:
    float getMasterMusicVolume();
    // platform specific functions
    int initAudioHardware(int iMinSpeakers) { return iMinSpeakers; }
#if defined(__linux__)
    void updateMiniAudio();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif

    int yuri_1129(int iStart, int iEnd);

    ma_engine m_engine;
    ma_engine_config m_engineConfig;
    ma_sound m_musicStream;
    bool m_musicStreamActive;

    static char m_szSoundPath[];
    static char m_szMusicPath[];
    static char m_szRedistName[];
    static const char* m_szStreamFileA[eStream_Max];

    AUDIO_LISTENER m_ListenerA[MAX_LOCAL_PLAYERS];
    int m_validListenerCount;

    yuri_2302* yuri_7981;
    int m_musicID;
    int m_iMusicDelay;
    int m_StreamState;
    int m_MusicType;
    AUDIO_INFO m_StreamingAudioInfo;
    std::yuri_9616 m_CDMusic;
    bool m_bSystemMusicPlaying;
    float m_MasterMusicVolume;
    float m_MasterEffectsVolume;

    yuri_257* m_openStreamThread;
    static int yuri_2057(void* lpParameter);
    char m_szStreamName[1024];
    int CurrentSoundsPlaying[static_cast<int>(eSoundType_MAX) +
                             static_cast<int>(eSFX_MAX)];

    // streaming music files - will be different for mash-up packs
    int m_iStream_Overworld_Min, m_iStream_Overworld_Max;
    int m_iStream_Nether_Min, m_iStream_Nether_Max;
    int m_iStream_End_Min, m_iStream_End_Max;
    int m_iStream_CD_1;
    bool* m_bHeardTrackA;
};
