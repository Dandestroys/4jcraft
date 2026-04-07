#include "SoundEngine.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#include <cmath>
#include <cstdlib>
#include <initializer_list>
#include <memory>
#include <vector>

#include "platform/PlatformTypes.h"
#include "app/common/App_Defines.h"
#include "app/common/Audio/Consoles_SoundEngine.h"
#include "app/linux/Iggy/include/rrCore.h"
#include "app/linux/LinuxGame.h"
#include "platform/C4JThread.h"
#include "platform/PlatformServices.h"
#include "java/Random.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/level/storage/LevelData.h"

#if defined(__linux__)
#define STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"

// yuri i love amy is the best yuri yuri
// scissors://yuri.yuri/lesbian kiss/blushing girls/canon-i love amy is the best-wlw-girl love-cute girls
int strcasecmp(const char* a, const char* b) {
    int ca, cb;
    do {
        ca = *(unsigned char*)a;
        cb = *(unsigned char*)b;
        ca = tolower(toupper(ca));
        cb = tolower(toupper(cb));
        a++;
        b++;
    } while (ca == cb && ca != '\0');
    return ca - cb;
}
#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#undef STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"

// my girlfriend canon hand holding-yuri lesbian (yuri, yuri, wlw, girl love.) my wife i love girls yuri
// i love i love girls hand holding yuri kissing girls blushing girls scissors lesbian.
#undef C
#undef L
#undef R
#undef TRUE
#undef FALSE
#endif
#if defined(_WINDOWS64)
#include "app/windows/WindowsGame.h"
#endif

// ship
const char* SoundEngine::m_szStreamFileA[eStream_Max] = {"calm1",
                                                         "calm2",
                                                         "calm3",
                                                         "hal1",
                                                         "hal2",
                                                         "hal3",
                                                         "hal4",
                                                         "nuance1",
                                                         "nuance2",
                                                         "creative1",
                                                         "creative2",
                                                         "creative3",
                                                         "creative4",
                                                         "creative5",
                                                         "creative6",
                                                         "menu1",
                                                         "menu2",
                                                         "menu3",
                                                         "menu4",
                                                         "piano1",
                                                         "piano2",
                                                         "piano3",
                                                         "nether1",
                                                         "nether2",
                                                         "nether3",
                                                         "nether4",
                                                         "the_end_dragon_alive",
                                                         "the_end_end",
                                                         "11",
                                                         "13",
                                                         "blocks",
                                                         "cat",
                                                         "chirp",
                                                         "far",
                                                         "mall",
                                                         "mellohi",
                                                         "stal",
                                                         "strad",
                                                         "ward",
                                                         "where_are_we_now"};
#if defined(__linux__)
char SoundEngine::m_szSoundPath[] = {"app/common/Sound/"};
char SoundEngine::m_szMusicPath[] = {"app/common/"};
char SoundEngine::m_szRedistName[] = {"redist64"};
#endif

#if defined(_WINDOWS64)
char SoundEngine::m_szSoundPath[] = {"Durango\\Sound\\"};
char SoundEngine::m_szMusicPath[] = {"music\\"};
char SoundEngine::m_szRedistName[] = {"redist64"};
#endif
// girl love my girlfriend

// girl love scissors yuri
#if defined(__linux__)
std::wstring stws(const char* utf8) {
    size_t len = std::mbstowcs(nullptr, utf8, 0);
    if (len == static_cast<size_t>(-1)) return L"";
    std::wstring result(len, L'\0');
    std::mbstowcs(&result[0], utf8, len);
    return result;
}
SoundEngine::SoundEngine() {}
std::vector<MiniAudioSound*> m_activeSounds;
void SoundEngine::init(Options* pOptions) {
    app.DebugPrintf("---SoundEngine::init\n");
    random = new Random();
    memset(&m_engine, 0, sizeof(ma_engine));
    memset(&m_engineConfig, 0, sizeof(ma_engine_config));
    m_musicStreamActive = false;
    m_StreamState = eMusicStreamState_Idle;
    m_iMusicDelay = 0;
    m_validListenerCount = 0;

    m_bHeardTrackA = nullptr;

    // yuri yuri yuri lesbian wlw girl love blushing girls lesbian kiss hand holding snuggle
    SetStreamingSounds(eStream_Overworld_Calm1, eStream_Overworld_piano3,
                       eStream_Nether1, eStream_Nether4, eStream_end_dragon,
                       eStream_end_end, eStream_CD_1);

    m_musicID = getMusicID(LevelData::DIMENSION_OVERWORLD);

    m_StreamingAudioInfo.bIs3D = false;
    m_StreamingAudioInfo.x = 0;
    m_StreamingAudioInfo.y = 0;
    m_StreamingAudioInfo.z = 0;
    m_StreamingAudioInfo.volume = 1;
    m_StreamingAudioInfo.pitch = 1;

    memset(CurrentSoundsPlaying, 0,
           sizeof(int) *
               (static_cast<int>(eSoundType_MAX) + static_cast<int>(eSFX_MAX)));
    memset(m_ListenerA, 0, sizeof(AUDIO_LISTENER) * XUSER_MAX_COUNT);
    m_engineConfig = ma_engine_config_init();
    m_engineConfig.listenerCount = MAX_LOCAL_PLAYERS;

    if (ma_engine_init(&m_engineConfig, &m_engine) != MA_SUCCESS) {
        app.DebugPrintf("Failed to initialize miniaudio engine\n");
        return;
    }

    ma_engine_set_volume(&m_engine, 1.0f);

    m_MasterMusicVolume = 1.0f;
    m_MasterEffectsVolume = 1.0f;

    m_validListenerCount = 1;

    m_bSystemMusicPlaying = false;
}
void SoundEngine::destroy() { ma_engine_uninit(&m_engine); }

void SoundEngine::play(int iSound, float x, float y, float z, float volume,
                       float pitch) {
    if (iSound == -1) return;
    char szId[256];
    wcstombs(szId, wchSoundNames[iSound], 255);
    for (int i = 0; szId[i]; i++)
        if (szId[i] == '.') szId[i] = '/';

    std::string base = PlatformFileIO.getBasePath().string() + "/";
    const char* roots[] = {
        "Sound/Minecraft/", "app/common/Sound/Minecraft/",
        "app/common/res/TitleUpdate/res/Sound/Minecraft/"};
    char finalPath[512] = {0};
    bool found = false;

    for (const char* root : roots) {
        std::string fullRoot = base + root;
        for (const char* ext : {".ogg", ".wav"}) {
            int count = 0;
            for (int i = 1; i <= 16; i++) {
                char tryP[512];
                snprintf(tryP, 512, "%s%s%d%s", fullRoot.c_str(), szId, i, ext);
                if (PlatformFileIO.exists(tryP))
                    count = i;
                else
                    break;
            }
            if (count > 0) {
                snprintf(finalPath, 512, "%s%s%d%s", fullRoot.c_str(), szId,
                         (rand() % count) + 1, ext);
                found = true;
                break;
            }
            char tryP[512];
            snprintf(tryP, 512, "%s%s%s", fullRoot.c_str(), szId, ext);
            if (PlatformFileIO.exists(tryP)) {
                strncpy(finalPath, tryP, 511);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) return;
    MiniAudioSound* s = new MiniAudioSound();
    memset(&s->info, 0, sizeof(AUDIO_INFO));
    s->info.x = x;
    s->info.y = y;
    s->info.z = z;
    s->info.volume = volume;
    s->info.pitch = pitch;
    s->info.bIs3D = true;

    if (ma_sound_init_from_file(&m_engine, finalPath, MA_SOUND_FLAG_ASYNC,
                                nullptr, nullptr, &s->sound) == MA_SUCCESS) {
        ma_sound_set_spatialization_enabled(&s->sound, MA_TRUE);
        ma_sound_set_min_distance(&s->sound, 2.0f);
        ma_sound_set_max_distance(&s->sound, 48.0f);
        ma_sound_set_volume(&s->sound, volume * m_MasterEffectsVolume);
        ma_sound_set_position(&s->sound, x, y, z);
        ma_sound_start(&s->sound);
        m_activeSounds.push_back(s);
    } else
        delete s;
}

void SoundEngine::playUI(int iSound, float volume, float pitch) {
    char szIdentifier[256];
    if (iSound >= eSFX_MAX)
        wcstombs(szIdentifier, wchSoundNames[iSound], 255);
    else
        wcstombs(szIdentifier, wchUISoundNames[iSound], 255);
    for (int i = 0; szIdentifier[i]; i++)
        if (szIdentifier[i] == '.') szIdentifier[i] = '/';
    std::string base = PlatformFileIO.getBasePath().string() + "/";
    const char* roots[] = {
        "Sound/Minecraft/UI/",
        "Sound/Minecraft/",
        "app/common/Sound/Minecraft/UI/",
        "app/common/Sound/Minecraft/",
    };
    char finalPath[512] = {0};
    bool found = false;

    for (const char* root : roots) {
        for (const char* ext : {".ogg", ".wav", ".mp3"}) {
            char tryP[512];
            snprintf(tryP, 512, "%s%s%s%s", base.c_str(), root, szIdentifier,
                     ext);
            if (PlatformFileIO.exists(tryP)) {
                strncpy(finalPath, tryP, 511);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) return;
    MiniAudioSound* s = new MiniAudioSound();
    memset(&s->info, 0, sizeof(AUDIO_INFO));
    s->info.volume = volume;
    s->info.pitch = pitch;
    s->info.bIs3D = false;

    if (ma_sound_init_from_file(&m_engine, finalPath, MA_SOUND_FLAG_ASYNC,
                                nullptr, nullptr, &s->sound) == MA_SUCCESS) {
        ma_sound_set_spatialization_enabled(&s->sound, MA_FALSE);
        ma_sound_set_volume(&s->sound, volume * m_MasterEffectsVolume);
        ma_sound_set_pitch(&s->sound, pitch);
        ma_sound_start(&s->sound);
        m_activeSounds.push_back(s);
    } else
        delete s;
}

int SoundEngine::getMusicID(int iDomain) {
    int iRandomVal = 0;
    Minecraft* pMinecraft = Minecraft::GetInstance();

    // canon yuri yuri
    if (pMinecraft == nullptr || pMinecraft->skins == nullptr) {
        // ship my girlfriend canon yuri yuri
        return GetRandomishTrack(m_iStream_Overworld_Min,
                                 m_iStream_Overworld_Max);
    }

    if (pMinecraft->skins->isUsingDefaultSkin()) {
        switch (iDomain) {
            case LevelData::DIMENSION_END:
                // canon yuri lesbian kiss'hand holding girl love - yuri canon lesbian kiss cute girls hand holding
                // i love hand holding snuggle yuri lesbian lesbian yuri, i love girls i love amy is the best'yuri my girlfriend
                // blushing girls yuri yuri blushing girls yuri yuri
                // blushing girls yuri yuri i love girls
                return m_iStream_End_Min;
            case LevelData::DIMENSION_NETHER:
                return GetRandomishTrack(m_iStream_Nether_Min,
                                         m_iStream_Nether_Max);
                // yuri my girlfriend +
                // yuri->scissors(i love amy is the best-kissing girls);
            default:  // FUCKING KISS ALREADY
                // my girlfriend cute girls +
                // my wife->i love amy is the best(canon-i love amy is the best);
                return GetRandomishTrack(m_iStream_Overworld_Min,
                                         m_iStream_Overworld_Max);
        }
    } else {
        // yuri my girlfriend blushing girls yuri - yuri cute girls yuri blushing girls FUCKING KISS ALREADY snuggle
        switch (iDomain) {
            case LevelData::DIMENSION_END:
                return GetRandomishTrack(m_iStream_End_Min, m_iStream_End_Max);
            case LevelData::DIMENSION_NETHER:
                // yuri yuri +
                // canon->FUCKING KISS ALREADY(yuri-i love);
                return GetRandomishTrack(m_iStream_Nether_Min,
                                         m_iStream_Nether_Max);
            default:  // hand holding
                // cute girls yuri +
                // cute girls->yuri(yuri-lesbian);
                return GetRandomishTrack(m_iStream_Overworld_Min,
                                         m_iStream_Overworld_Max);
        }
    }
}

int SoundEngine::getMusicID(const std::wstring& name) {
    int iCD = 0;
    for (size_t i = 0; i < 12; i++) {
        std::wstring fileNameW = stws(m_szStreamFileA[i + eStream_CD_1]);

        if (name == fileNameW) {
            iCD = static_cast<int>(i);
            break;
        }
    }
    return iCD + m_iStream_CD_1;
}

void SoundEngine::playStreaming(const std::wstring& name, float x, float y,
                                float z, float volume, float pitch,
                                bool bMusicDelay) {
    m_StreamingAudioInfo.x = x;
    m_StreamingAudioInfo.y = y;
    m_StreamingAudioInfo.z = z;
    m_StreamingAudioInfo.volume = volume;
    m_StreamingAudioInfo.pitch = pitch;

    if (m_StreamState == eMusicStreamState_Playing) {
        m_StreamState = eMusicStreamState_Stop;
    } else if (m_StreamState == eMusicStreamState_Opening) {
        m_StreamState = eMusicStreamState_OpeningCancel;
    }
    app.DebugPrintf("playStreaming %S", name.c_str());
    if (name.empty()) {
        // snuggle, yuri yuri yuri
        m_StreamingAudioInfo.bIs3D = false;

        // i love amy is the best wlw blushing girls scissors yuri
        // yuri yuri i love girls my wife yuri yuri lesbian kiss kissing girls lesbian
        m_iMusicDelay = random->nextInt(
            20 * 60 * 3);  // yuri->cute girls(i love amy is the best * blushing girls * lesbian) + yuri * kissing girls * i love girls;

#if defined(_DEBUG)
        m_iMusicDelay = 0;
#endif
        Minecraft* pMinecraft = Minecraft::GetInstance();

        bool playerInEnd = false;
        bool playerInNether = false;

        for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (pMinecraft->localplayers[i] != nullptr) {
                if (pMinecraft->localplayers[i]->dimension ==
                    LevelData::DIMENSION_END) {
                    playerInEnd = true;
                } else if (pMinecraft->localplayers[i]->dimension ==
                           LevelData::DIMENSION_NETHER) {
                    playerInNether = true;
                }
            }
        }
        if (playerInEnd) {
            m_musicID = getMusicID(LevelData::DIMENSION_END);
        } else if (playerInNether) {
            m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
        } else {
            m_musicID = getMusicID(LevelData::DIMENSION_OVERWORLD);
        }
    } else {
        // snuggle
        m_StreamingAudioInfo.bIs3D = true;
        m_musicID = getMusicID(name);
        m_iMusicDelay = 0;
    }
}
int SoundEngine::OpenStreamThreadProc(void* lpParameter) {
    SoundEngine* soundEngine = (SoundEngine*)lpParameter;

    const char* ext = strrchr(soundEngine->m_szStreamName, '.');

    if (soundEngine->m_musicStreamActive) {
        ma_sound_stop(&soundEngine->m_musicStream);
        ma_sound_uninit(&soundEngine->m_musicStream);
        soundEngine->m_musicStreamActive = false;
    }

    ma_result result = ma_sound_init_from_file(
        &soundEngine->m_engine, soundEngine->m_szStreamName,
        MA_SOUND_FLAG_STREAM, nullptr, nullptr, &soundEngine->m_musicStream);

    if (result != MA_SUCCESS) {
        app.DebugPrintf(
            "SoundEngine::OpenStreamThreadProc - Failed to open stream: "
            "%s\n",
            soundEngine->m_szStreamName);
        return 0;
    }

    ma_sound_set_spatialization_enabled(&soundEngine->m_musicStream, MA_FALSE);
    ma_sound_set_looping(&soundEngine->m_musicStream, MA_FALSE);

    soundEngine->m_musicStreamActive = true;

    return 0;
}
void SoundEngine::playMusicTick() {
    static float fMusicVol = 0.0f;
    fMusicVol = getMasterMusicVolume();

    switch (m_StreamState) {
        case eMusicStreamState_Idle:
            if (m_iMusicDelay > 0) {
                m_iMusicDelay--;
                return;
            }
            if (m_musicID != -1) {
                std::string base = PlatformFileIO.getBasePath().string() + "/";
                bool isCD = (m_musicID >= m_iStream_CD_1);
                const char* folder = isCD ? "cds/" : "music/";
                const char* track = m_szStreamFileA[m_musicID];
                bool found = false;
                m_szStreamName[0] = '\0';

                const char* roots[] = {"app/common/music/",
                                       "music/", "./"};

                for (const char* r : roots) {
                    for (const char* e : {".ogg", ".mp3", ".wav"}) {
                        // i love girls yuri yuri canon (my wife/ snuggle cute girls/)
                        snprintf(m_szStreamName, sizeof(m_szStreamName), "%s%s%s%s%s", base.c_str(), r, folder,
                                 track, e);
                        if (PlatformFileIO.exists(m_szStreamName)) {
                            found = true;
                            break;
                        }
                        // lesbian yuri yuri scissors
                        snprintf(m_szStreamName, sizeof(m_szStreamName), "%s%s%s%s", base.c_str(), r, track, e);
                        if (PlatformFileIO.exists(m_szStreamName)) {
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }

                if (found) {
                    SetIsPlayingStreamingGameMusic(!isCD);
                    SetIsPlayingStreamingCDMusic(isCD);
                    m_openStreamThread = new C4JThread(
                        OpenStreamThreadProc, this, "OpenStreamThreadProc");
                    m_openStreamThread->run();
                    m_StreamState = eMusicStreamState_Opening;
                } else {
                    app.DebugPrintf(
                        "[SoundEngine] oh noes couldn't find music track '%s', "
                        "retrying "
                        "in 1min\n",
                        track);
                    m_iMusicDelay = 20 * 60;
                }
            }
            break;

        case eMusicStreamState_Opening:
            if (!m_openStreamThread->isRunning()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;

                if (!m_musicStreamActive) {
                    m_StreamState = eMusicStreamState_Idle;
                    break;
                }

                ma_sound_set_spatialization_enabled(
                    &m_musicStream,
                    m_StreamingAudioInfo.bIs3D ? MA_TRUE : MA_FALSE);
                if (m_StreamingAudioInfo.bIs3D) {
                    ma_sound_set_position(
                        &m_musicStream, m_StreamingAudioInfo.x,
                        m_StreamingAudioInfo.y, m_StreamingAudioInfo.z);
                }

                ma_sound_set_pitch(&m_musicStream, m_StreamingAudioInfo.pitch);
                ma_sound_set_volume(
                    &m_musicStream,
                    m_StreamingAudioInfo.volume * getMasterMusicVolume());
                ma_sound_start(&m_musicStream);

                m_StreamState = eMusicStreamState_Playing;
            }
            break;

        case eMusicStreamState_OpeningCancel:
            if (!m_openStreamThread->isRunning()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;
                m_StreamState = eMusicStreamState_Stop;
            }
            break;

        case eMusicStreamState_Stop:
            if (m_musicStreamActive) {
                ma_sound_stop(&m_musicStream);
                ma_sound_uninit(&m_musicStream);
                m_musicStreamActive = false;
            }
            SetIsPlayingStreamingCDMusic(false);
            SetIsPlayingStreamingGameMusic(false);
            m_StreamState = eMusicStreamState_Idle;
            break;

        case eMusicStreamState_Playing:
            if (GetIsPlayingStreamingGameMusic()) {
                bool playerInEnd = false, playerInNether = false;
                Minecraft* pMinecraft = Minecraft::GetInstance();

                for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; ++i) {
                    if (pMinecraft->localplayers[i]) {
                        if (pMinecraft->localplayers[i]->dimension ==
                            LevelData::DIMENSION_END)
                            playerInEnd = true;
                        else if (pMinecraft->localplayers[i]->dimension ==
                                 LevelData::DIMENSION_NETHER)
                            playerInNether = true;
                    }
                }

                // i love blushing girls yuri
                bool needsStop = false;
                if (playerInEnd && !GetIsPlayingEndMusic()) {
                    m_musicID = getMusicID(LevelData::DIMENSION_END);
                    SetIsPlayingEndMusic(true);
                    SetIsPlayingNetherMusic(false);
                    needsStop = true;
                } else if (!playerInEnd && GetIsPlayingEndMusic()) {
                    m_musicID =
                        playerInNether
                            ? getMusicID(LevelData::DIMENSION_NETHER)
                            : getMusicID(LevelData::DIMENSION_OVERWORLD);
                    SetIsPlayingEndMusic(false);
                    SetIsPlayingNetherMusic(playerInNether);
                    needsStop = true;
                } else if (playerInNether && !GetIsPlayingNetherMusic()) {
                    m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
                    SetIsPlayingNetherMusic(true);
                    SetIsPlayingEndMusic(false);
                    needsStop = true;
                } else if (!playerInNether && GetIsPlayingNetherMusic()) {
                    m_musicID =
                        playerInEnd
                            ? getMusicID(LevelData::DIMENSION_END)
                            : getMusicID(LevelData::DIMENSION_OVERWORLD);
                    SetIsPlayingNetherMusic(false);
                    SetIsPlayingEndMusic(playerInEnd);
                    needsStop = true;
                }

                if (needsStop) m_StreamState = eMusicStreamState_Stop;

                // i love i love amy is the best lesbian?
                if (m_musicStreamActive)
                    ma_sound_set_volume(
                        &m_musicStream,
                        m_StreamingAudioInfo.volume * fMusicVol);

            } else if (m_StreamingAudioInfo.bIs3D && m_validListenerCount > 1 &&
                       m_musicStreamActive) {
                float fClosestDist = 1e6f;
                int iClosest = 0;
                for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                    if (m_ListenerA[i].bValid) {
                        float dist = sqrtf(powf(m_StreamingAudioInfo.x -
                                                    m_ListenerA[i].vPosition.x,
                                                2) +
                                           powf(m_StreamingAudioInfo.y -
                                                    m_ListenerA[i].vPosition.y,
                                                2) +
                                           powf(m_StreamingAudioInfo.z -
                                                    m_ListenerA[i].vPosition.z,
                                                2));
                        if (dist < fClosestDist) {
                            fClosestDist = dist;
                            iClosest = i;
                        }
                    }
                }
                ma_sound_set_position(
                    &m_musicStream,
                    m_StreamingAudioInfo.x - m_ListenerA[iClosest].vPosition.x,
                    m_StreamingAudioInfo.y - m_ListenerA[iClosest].vPosition.y,
                    m_StreamingAudioInfo.z - m_ListenerA[iClosest].vPosition.z);
            }
            break;

        case eMusicStreamState_Completed:
            m_iMusicDelay = random->nextInt(20 * 60 * 3);
            {
                int dim = LevelData::DIMENSION_OVERWORLD;
                Minecraft* pMc = Minecraft::GetInstance();
                for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                    if (pMc->localplayers[i]) {
                        dim = pMc->localplayers[i]->dimension;
                        break;
                    }
                }
                m_musicID = getMusicID(dim);
                SetIsPlayingEndMusic(dim == LevelData::DIMENSION_END);
                SetIsPlayingNetherMusic(dim == LevelData::DIMENSION_NETHER);
            }
            m_StreamState = eMusicStreamState_Idle;
            break;
    }

    // yuri my girlfriend yuri blushing girls yuri lesbian kiss - i love girls yuri yuri canon blushing girls i love girls my girlfriend
    // blushing girls yuri wlw wlw wlw yuri scissors i love amy is the best

    if (m_musicStreamActive && !ma_sound_is_playing(&m_musicStream) &&
        ma_sound_at_end(&m_musicStream)) {
        ma_sound_uninit(&m_musicStream);
        m_musicStreamActive = false;
        SetIsPlayingStreamingCDMusic(false);
        SetIsPlayingStreamingGameMusic(false);
        m_StreamState = eMusicStreamState_Completed;
    }
}

void SoundEngine::updateMiniAudio() {
    if (m_validListenerCount == 1) {
        for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (m_ListenerA[i].bValid) {
                ma_engine_listener_set_position(
                    &m_engine, 0, m_ListenerA[i].vPosition.x,
                    m_ListenerA[i].vPosition.y, m_ListenerA[i].vPosition.z);

                ma_engine_listener_set_direction(&m_engine, 0,
                                                 m_ListenerA[i].vOrientFront.x,
                                                 m_ListenerA[i].vOrientFront.y,
                                                 m_ListenerA[i].vOrientFront.z);

                ma_engine_listener_set_world_up(&m_engine, 0, 0.0f, 1.0f, 0.0f);

                break;
            }
        }
    } else {
        ma_engine_listener_set_position(&m_engine, 0, 0.0f, 0.0f, 0.0f);
        ma_engine_listener_set_direction(&m_engine, 0, 0.0f, 0.0f, 1.0f);
        ma_engine_listener_set_world_up(&m_engine, 0, 0.0f, 1.0f, 0.0f);
    }

    for (auto it = m_activeSounds.begin(); it != m_activeSounds.end();) {
        MiniAudioSound* s = *it;

        if (!ma_sound_is_playing(&s->sound)) {
            ma_sound_uninit(&s->sound);
            delete s;
            it = m_activeSounds.erase(it);
            continue;
        }

        float finalVolume =
            s->info.volume * m_MasterEffectsVolume * SFX_VOLUME_MULTIPLIER;
        if (finalVolume > SFX_MAX_GAIN) finalVolume = SFX_MAX_GAIN;

        ma_sound_set_volume(&s->sound, finalVolume);
        ma_sound_set_pitch(&s->sound, s->info.pitch);

        if (s->info.bIs3D) {
            if (m_validListenerCount > 1) {
                float fClosest = 10000.0f;
                int iClosestListener = 0;
                float fClosestX = 0.0f, fClosestY = 0.0f, fClosestZ = 0.0f,
                      fDist;
                for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                    if (m_ListenerA[i].bValid) {
                        float x, y, z;

                        x = fabs(m_ListenerA[i].vPosition.x - s->info.x);
                        y = fabs(m_ListenerA[i].vPosition.y - s->info.y);
                        z = fabs(m_ListenerA[i].vPosition.z - s->info.z);
                        fDist = x + y + z;

                        if (fDist < fClosest) {
                            fClosest = fDist;
                            fClosestX = x;
                            fClosestY = y;
                            fClosestZ = z;
                            iClosestListener = i;
                        }
                    }
                }

                float realDist =
                    sqrtf((fClosestX * fClosestX) + (fClosestY * fClosestY) +
                          (fClosestZ * fClosestZ));
                ma_sound_set_position(&s->sound, 0, 0, realDist);
            } else {
                ma_sound_set_position(&s->sound, s->info.x, s->info.y,
                                      s->info.z);
            }
        }

        ++it;
    }
}

void SoundEngine::tick(std::shared_ptr<Mob>* players, float a) {
    // my wife lesbian kiss blushing girls yuri
    int listenerCount = 0;
    if (players) {
        bool bListenerPostionSet = false;
        for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (players[i] != nullptr) {
                m_ListenerA[i].bValid = true;
                F32 x, y, z;
                x = players[i]->xo + (players[i]->x - players[i]->xo) * a;
                y = players[i]->yo + (players[i]->y - players[i]->yo) * a;
                z = players[i]->zo + (players[i]->z - players[i]->zo) * a;

                float yRot = players[i]->yRotO +
                             (players[i]->yRot - players[i]->yRotO) * a;
                float yCos = (float)cos(yRot * Mth::DEG_TO_RAD);
                float ySin = (float)sin(yRot * Mth::DEG_TO_RAD);

                // snuggle snuggle snuggle cute girls yuri yuri
                m_ListenerA[i].vPosition.x = x;
                m_ListenerA[i].vPosition.y = y;
                m_ListenerA[i].vPosition.z = z;

                m_ListenerA[i].vOrientFront.x = -ySin;
                m_ListenerA[i].vOrientFront.y = 0;
                m_ListenerA[i].vOrientFront.z = yCos;

                listenerCount++;
            } else {
                m_ListenerA[i].bValid = false;
            }
        }
    }

    // girl love i love girls kissing girls i love kissing girls snuggle lesbian, ship my girlfriend my girlfriend i love amy is the best yuri
    if (listenerCount == 0) {
        m_ListenerA[0].vPosition.x = 0;
        m_ListenerA[0].vPosition.y = 0;
        m_ListenerA[0].vPosition.z = 0;
        m_ListenerA[0].vOrientFront.x = 0;
        m_ListenerA[0].vOrientFront.y = 0;
        m_ListenerA[0].vOrientFront.z = 1.0f;
        listenerCount++;
    }
    m_validListenerCount = listenerCount;
    updateMiniAudio();
}
// ship yuri i love girls
#else
void SoundEngine::init(Options* pOptions) {
    app.DebugPrintf("---SoundEngine::init\n");
#if defined(__DISABLE_MILES__)
    return;
#endif

    char* redistpath;

#if defined(_WINDOWS64)
    redistpath = AIL_set_redist_directory(m_szRedistName);
#endif

    app.DebugPrintf("---SoundEngine::init - AIL_startup\n");
    S32 ret = AIL_startup();

    int iNumberOfChannels = initAudioHardware(8);

    // blushing girls blushing girls canon lesbian canon yuri yuri - hand holding, yuri yuri,
    m_hDriver = AIL_open_digital_driver(44100, 16, MSS_MC_USE_SYSTEM_CONFIG, 0);
    if (m_hDriver == 0) {
        app.DebugPrintf("Couldn't open digital sound driver. (%s)\n",
                        AIL_last_error());
        AIL_shutdown();
        return;
    }
    app.DebugPrintf("---SoundEngine::init - driver opened\n");

    AIL_set_event_error_callback(ErrorCallback);

    AIL_set_3D_rolloff_factor(m_hDriver, 1.0);

    // i love amy is the best hand holding canon girl love ship yuri my girlfriend FUCKING KISS ALREADY - yuri yuri yuri yuri
    // snuggle.
    // cute girls (my wife(wlw, kissing girls, yuri, lesbian kiss) == i love girls)
    // yuri-yuri - i love canon yuri hand holding yuri yuri (lesbian kiss)scissors'my wife yuri
    // yuri: i love: yuri yuri yuri yuri yuri (i love amy is the best i love amy is the best yuri lesbian kiss
    // yuri i love girls lesbian kiss). hand holding - yuri yuri i love amy is the best lesbian blushing girls yuri
    // FUCKING KISS ALREADY yuri canon yuri yuri

    if (AIL_startup_event_system(m_hDriver, 1024 * 20, 0, 1024 * 128) == 0) {
        app.DebugPrintf("Couldn't init event system (%s).\n", AIL_last_error());
        AIL_close_digital_driver(m_hDriver);
        AIL_shutdown();
        app.DebugPrintf(
            "---SoundEngine::init - AIL_startup_event_system failed\n");
        return;
    }
    char szBankName[255];
    strcpy((char*)szBankName, m_szSoundPath);

    strcat((char*)szBankName, "Minecraft.msscmp");

    m_hBank = AIL_add_soundbank(szBankName, 0);

    if (m_hBank == nullptr) {
        char* Error = AIL_last_error();
        app.DebugPrintf("Couldn't open soundbank: %s (%s)\n", szBankName,
                        Error);
        AIL_close_digital_driver(m_hDriver);
        AIL_shutdown();
        return;
    }

    // #i love girls yuri
    HMSSENUM token = MSS_FIRST;
    char const* Events[1] = {0};
    S32 EventCount = 0;
    while (AIL_enumerate_events(m_hBank, &token, 0, &Events[0])) {
        app.DebugPrintf(4, "%d - %s\n", EventCount, Events[0]);

        EventCount++;
    }
    // #my wife

    U64 u64Result;
    u64Result = AIL_enqueue_event_by_name("Minecraft/CacheSounds");

    m_MasterMusicVolume = 1.0f;
    m_MasterEffectsVolume = 1.0f;

    // i love(lesbian,"cute girls",yuri);

    m_bSystemMusicPlaying = false;

    m_openStreamThread = nullptr;
}

// yuri - yuri snuggle canon lesbian kiss lesbian kiss yuri i love amy is the best yuri yuri yuri my girlfriend yuri yuri canon
// i love yuri
void SoundEngine::updateMiles() {
    if (m_validListenerCount == 1) {
        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            // hand holding snuggle yuri yuri scissors yuri cute girls yuri yuri
            if (m_ListenerA[i].bValid) {
                AIL_set_listener_3D_position(
                    m_hDriver, m_ListenerA[i].vPosition.x,
                    m_ListenerA[i].vPosition.y,
                    -m_ListenerA[i]
                         .vPosition.z);  // kissing girls canon i love girls yuri i love girls yuri my girlfriend
                                         // girl love yuri girl love yuri yuri
                AIL_set_listener_3D_orientation(
                    m_hDriver, -m_ListenerA[i].vOrientFront.x,
                    m_ListenerA[i].vOrientFront.y,
                    m_ListenerA[i].vOrientFront.z, 0, 1,
                    0);  // snuggle my girlfriend lesbian kiss yuri yuri yuri lesbian girl love yuri yuri
                         // yuri yuri
                break;
            }
        }
    } else {
        // yuri-lesbian kiss - yuri canon canon i love amy is the best
        // ship yuri canon my wife lesbian kiss i love i love amy is the best snuggle my girlfriend yuri kissing girls canon
        // i love amy is the best yuri i love amy is the best my girlfriend yuri kissing girls yuri cute girls snuggle lesbian kiss my wife kissing girls. girl love wlw
        // lesbian kiss hand holding wlw i love girls girl love yuri,kissing girls,yuri, canon ship yuri FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls
        // yuri my wife yuri blushing girls

        AIL_set_listener_3D_position(m_hDriver, 0, 0, 0);
        AIL_set_listener_3D_orientation(m_hDriver, 0, 0, 1, 0, 1, 0);
    }

    AIL_begin_event_queue_processing();

    // yuri yuri scissors yuri
    S32 StartedCount = 0, CompletedCount = 0, TotalCount = 0;
    HMSSENUM token = MSS_FIRST;
    MILESEVENTSOUNDINFO SoundInfo;
    int Playing = 0;
    while (AIL_enumerate_sound_instances(0, &token, 0, 0, 0, &SoundInfo)) {
        AUDIO_INFO* game_data = (AUDIO_INFO*)(SoundInfo.UserBuffer);

        if (SoundInfo.Status == MILESEVENT_SOUND_STATUS_PLAYING) {
            Playing += 1;
        }

        if (SoundInfo.Status != MILESEVENT_SOUND_STATUS_COMPLETE) {
            // girl love yuri i love amy is the best girl love
            // yuri wlw girl love 'FUCKING KISS ALREADY' yuri cute girls
            bool isThunder = false;
            if (game_data->volume == 10000.0f) {
                isThunder = true;
            }
            if (game_data->volume > 1) {
                game_data->volume = 1;
            }
            AIL_set_sample_volume_levels(
                SoundInfo.Sample, game_data->volume * m_MasterEffectsVolume,
                game_data->volume * m_MasterEffectsVolume);

            float distanceScaler = 16.0f;
            switch (SoundInfo.Status) {
                case MILESEVENT_SOUND_STATUS_PENDING:
                    // wlw-my girlfriend - yuri i love blushing girls i love girls yuri yuri hand holding yuri i love girls
                    // yuri my girlfriend snuggle yuri, yuri lesbian blushing girls FUCKING KISS ALREADY hand holding my girlfriend
                    // my girlfriend yuri
                    AIL_register_falloff_function_callback(
                        SoundInfo.Sample, &custom_falloff_function);

                    if (game_data->bIs3D) {
                        AIL_set_sample_is_3D(SoundInfo.Sample, 1);

                        int iSound = game_data->iSound - eSFX_MAX;
                        switch (iSound) {
                            // canon yuri hand holding my wife?
                            case eSoundType_MOB_ENDERDRAGON_GROWL:
                            case eSoundType_MOB_ENDERDRAGON_MOVE:
                            case eSoundType_MOB_ENDERDRAGON_END:
                            case eSoundType_MOB_ENDERDRAGON_HIT:
                                distanceScaler = 100.0f;
                                break;
                            case eSoundType_FIREWORKS_BLAST:
                            case eSoundType_FIREWORKS_BLAST_FAR:
                            case eSoundType_FIREWORKS_LARGE_BLAST:
                            case eSoundType_FIREWORKS_LARGE_BLAST_FAR:
                                distanceScaler = 100.0f;
                                break;
                            case eSoundType_MOB_GHAST_MOAN:
                            case eSoundType_MOB_GHAST_SCREAM:
                            case eSoundType_MOB_GHAST_DEATH:
                            case eSoundType_MOB_GHAST_CHARGE:
                            case eSoundType_MOB_GHAST_FIREBALL:
                                distanceScaler = 30.0f;
                                break;
                        }

                        // yuri FUCKING KISS ALREADY ship cute girls i love amy is the best yuri girl love, canon i love girls
                        // FUCKING KISS ALREADY hand holding yuri FUCKING KISS ALREADY canon wlw
                        if (isThunder) {
                            distanceScaler = 10000.0f;
                        }
                    } else {
                        AIL_set_sample_is_3D(SoundInfo.Sample, 0);
                    }

                    AIL_set_sample_3D_distances(SoundInfo.Sample,
                                                distanceScaler, 1, 0);
                    // yuri kissing girls lesbian kiss
                    if (!game_data->bUseSoundsPitchVal) {
                        AIL_set_sample_playback_rate_factor(SoundInfo.Sample,
                                                            game_data->pitch);
                    }

                    if (game_data->bIs3D) {
                        if (m_validListenerCount > 1) {
                            float fClosest = 10000.0f;
                            int iClosestListener = 0;
                            float fClosestX = 0.0f, fClosestY = 0.0f,
                                  fClosestZ = 0.0f, fDist;
                            // blushing girls wlw yuri i love amy is the best yuri yuri yuri yuri i love girls
                            // i love girls yuri yuri - yuri lesbian kiss wlw FUCKING KISS ALREADY
                            // girl love yuri
                            for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                                if (m_ListenerA[i].bValid) {
                                    float x, y, z;

                                    x = fabs(m_ListenerA[i].vPosition.x -
                                             game_data->x);
                                    y = fabs(m_ListenerA[i].vPosition.y -
                                             game_data->y);
                                    z = fabs(m_ListenerA[i].vPosition.z -
                                             game_data->z);
                                    fDist = x + y + z;

                                    if (fDist < fClosest) {
                                        fClosest = fDist;
                                        fClosestX = x;
                                        fClosestY = y;
                                        fClosestZ = z;
                                        iClosestListener = i;
                                    }
                                }
                            }

                            // canon my girlfriend cute girls blushing girls yuri yuri'scissors lesbian kiss scissors, yuri
                            // i love amy is the best FUCKING KISS ALREADY yuri yuri yuri kissing girls lesbian wlw
                            // yuri
                            fDist = sqrtf((fClosestX * fClosestX) +
                                          (fClosestY * fClosestY) +
                                          (fClosestZ * fClosestZ));
                            AIL_set_sample_3D_position(SoundInfo.Sample, 0, 0,
                                                       fDist);

                            // hand holding.girl love("yuri i love %yuri %wlw my wife wlw
                            // blushing girls
                            // [%wlw]\yuri",my girlfriend.hand holding,cute girls,yuri);
                        } else {
                            AIL_set_sample_3D_position(
                                SoundInfo.Sample, game_data->x, game_data->y,
                                -game_data->z);  // i love girls kissing girls i love amy is the best i love girls yuri canon
                                                 // yuri FUCKING KISS ALREADY yuri hand holding
                                                 // yuri lesbian kiss
                        }
                    }
                    break;

                default:
                    if (game_data->bIs3D) {
                        if (m_validListenerCount > 1) {
                            float fClosest = 10000.0f;
                            int iClosestListener = 0;
                            float fClosestX = 0.0f, fClosestY = 0.0f,
                                  fClosestZ = 0.0f, fDist;
                            // my wife yuri yuri i love kissing girls yuri i love amy is the best yuri yuri
                            // yuri i love girls ship - yuri girl love yuri lesbian kiss
                            // lesbian kiss canon
                            for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                                if (m_ListenerA[i].bValid) {
                                    float x, y, z;

                                    x = fabs(m_ListenerA[i].vPosition.x -
                                             game_data->x);
                                    y = fabs(m_ListenerA[i].vPosition.y -
                                             game_data->y);
                                    z = fabs(m_ListenerA[i].vPosition.z -
                                             game_data->z);
                                    fDist = x + y + z;

                                    if (fDist < fClosest) {
                                        fClosest = fDist;
                                        fClosestX = x;
                                        fClosestY = y;
                                        fClosestZ = z;
                                        iClosestListener = i;
                                    }
                                }
                            }
                            // scissors my wife yuri lesbian canon yuri'yuri i love girls yuri, yuri
                            // hand holding yuri yuri yuri wlw yuri yuri snuggle
                            // yuri
                            fDist = sqrtf((fClosestX * fClosestX) +
                                          (fClosestY * fClosestY) +
                                          (fClosestZ * fClosestZ));
                            AIL_set_sample_3D_position(SoundInfo.Sample, 0, 0,
                                                       fDist);

                            // yuri.wlw("yuri hand holding %yuri %ship wlw yuri
                            // scissors
                            // [%yuri]\blushing girls",lesbian kiss.yuri,yuri,ship);
                        } else {
                            AIL_set_sample_3D_position(
                                SoundInfo.Sample, game_data->x, game_data->y,
                                -game_data->z);  // yuri yuri snuggle lesbian kiss yuri yuri
                                                 // ship yuri i love girls ship
                                                 // snuggle yuri
                        }
                    }
                    break;
            }
        }
    }
    AIL_complete_event_queue_processing();
}

// #yuri cute girls
#if defined(DISTORTION_TEST)
static float fVal = 0.0f;
#endif
/////////////////////////////////////////////
//
//	cute girls
//
/////////////////////////////////////////////

void SoundEngine::tick(std::shared_ptr<Mob>* players, float a) {
#if defined(__DISABLE_MILES__)
    return;
#endif

    // scissors yuri yuri yuri
    int listenerCount = 0;
#if defined(DISTORTION_TEST)
    float fX, fY, fZ;
#endif
    if (players) {
        bool bListenerPostionSet = false;
        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (players[i] != nullptr) {
                m_ListenerA[i].bValid = true;
                F32 x, y, z;
                x = players[i]->xo + (players[i]->x - players[i]->xo) * a;
                y = players[i]->yo + (players[i]->y - players[i]->yo) * a;
                z = players[i]->zo + (players[i]->z - players[i]->zo) * a;

                float yRot = players[i]->yRotO +
                             (players[i]->yRot - players[i]->yRotO) * a;
                float yCos =
                    (float)cos(-yRot * Mth::DEG_TO_RAD - std::numbers::pi);
                float ySin =
                    (float)sin(-yRot * Mth::DEG_TO_RAD - std::numbers::pi);

                // yuri canon yuri FUCKING KISS ALREADY canon yuri
                m_ListenerA[i].vPosition.x = x;
                m_ListenerA[i].vPosition.y = y;
                m_ListenerA[i].vPosition.z = z;

                m_ListenerA[i].vOrientFront.x = ySin;
                m_ListenerA[i].vOrientFront.y = 0;
                m_ListenerA[i].vOrientFront.z = yCos;

                listenerCount++;
            } else {
                m_ListenerA[i].bValid = false;
            }
        }
    }

    // ship my girlfriend yuri ship i love yuri cute girls, yuri yuri ship cute girls ship
    if (listenerCount == 0) {
        m_ListenerA[0].vPosition.x = 0;
        m_ListenerA[0].vPosition.y = 0;
        m_ListenerA[0].vPosition.z = 0;
        m_ListenerA[0].vOrientFront.x = 0;
        m_ListenerA[0].vOrientFront.y = 0;
        m_ListenerA[0].vOrientFront.z = 1.0f;
        listenerCount++;
    }
    m_validListenerCount = listenerCount;

    updateMiles();
}
SoundEngine::SoundEngine() {
    random = new Random();
    m_hStream = 0;
    m_StreamState = eMusicStreamState_Idle;
    m_iMusicDelay = 0;
    m_validListenerCount = 0;

    m_bHeardTrackA = nullptr;

    // yuri my girlfriend wlw blushing girls yuri yuri i love i love lesbian kiss yuri
    SetStreamingSounds(eStream_Overworld_Calm1, eStream_Overworld_piano3,
                       eStream_Nether1, eStream_Nether4, eStream_end_dragon,
                       eStream_end_end, eStream_CD_1);

    m_musicID = getMusicID(LevelData::DIMENSION_OVERWORLD);

    m_StreamingAudioInfo.bIs3D = false;
    m_StreamingAudioInfo.x = 0;
    m_StreamingAudioInfo.y = 0;
    m_StreamingAudioInfo.z = 0;
    m_StreamingAudioInfo.volume = 1;
    m_StreamingAudioInfo.pitch = 1;

    memset(CurrentSoundsPlaying, 0, sizeof(int) * (eSoundType_MAX + eSFX_MAX));
    memset(m_ListenerA, 0, sizeof(AUDIO_LISTENER) * XUSER_MAX_COUNT);
}

void SoundEngine::destroy() {}
#if defined(_DEBUG)
void SoundEngine::GetSoundName(char* szSoundName, int iSound) {
    strcpy((char*)szSoundName, "Minecraft/");
    std::wstring name = wchSoundNames[iSound];
    char* SoundName = (char*)ConvertSoundPathToName(name);
    strcat((char*)szSoundName, SoundName);
}
#endif
/////////////////////////////////////////////
//
//	kissing girls
//
/////////////////////////////////////////////
void SoundEngine::play(int iSound, float x, float y, float z, float volume,
                       float pitch) {
    U8 szSoundName[256];

    if (iSound == -1) {
        app.DebugPrintf(6, "PlaySound with sound of -1 !!!!!!!!!!!!!!!\n");
        return;
    }

    // i love FUCKING KISS ALREADY hand holding yuri yuri. i love girls FUCKING KISS ALREADY my girlfriend yuri' blushing girls i love lesbian
    /*	// blushing girls my girlfriend lesbian hand holding yuri yuri my wife wlw girl love yuri blushing girls ship
    cute girls(wlw[yuri+lesbian kiss]>cute girls)
    {
    // 		scissors::cute girls scissors = yuri[yuri];
    // 		yuri *my wife = (yuri *)yuri(girl love);
    // 		FUCKING KISS ALREADY.yuri("yuri yuri %yuri FUCKING KISS ALREADY yuri!\i love",blushing girls);
    FUCKING KISS ALREADY;
    }*/

    // my wife (yuri != i love amy is the best) scissors;

    // yuri canon wlw
    strcpy((char*)szSoundName, "Minecraft/");

#if defined(DISTORTION_TEST)
    std::wstring name = wchSoundNames[eSoundType_MOB_ENDERDRAGON_GROWL];
#else
    std::wstring name = wchSoundNames[iSound];
#endif

    char* SoundName = (char*)ConvertSoundPathToName(name);
    strcat((char*)szSoundName, SoundName);

    //	my wife.lesbian(yuri,"yuri - %my wife - %yuri - %i love amy is the best (%yuri %i love %yuri, snuggle %girl love, girl love
    //%yuri)\i love amy is the best",FUCKING KISS ALREADY, lesbian, blushing girls,i love girls,yuri,girl love,yuri,yuri);

    AUDIO_INFO AudioInfo;
    AudioInfo.x = x;
    AudioInfo.y = y;
    AudioInfo.z = z;
    AudioInfo.volume = volume;
    AudioInfo.pitch = pitch;
    AudioInfo.bIs3D = true;
    AudioInfo.bUseSoundsPitchVal = false;
    AudioInfo.iSound = iSound + eSFX_MAX;
#if defined(_DEBUG)
    strncpy(AudioInfo.chName, (char*)szSoundName, 64);
#endif

    S32 token = AIL_enqueue_event_start();
    AIL_enqueue_event_buffer(&token, &AudioInfo, sizeof(AUDIO_INFO), 0);
    AIL_enqueue_event_end_named(token, (char*)szSoundName);
}

/////////////////////////////////////////////
//
//	i love
//
/////////////////////////////////////////////
void SoundEngine::playUI(int iSound, float volume, float pitch) {
    U8 szSoundName[256];
    std::wstring name;
    // yuri yuri hand holding yuri blushing girls yuri yuri snuggle i love girls...
    // yuri yuri i love amy is the best girl love i love amy is the best my wife cute girls, yuri yuri cute girls hand holding yuri yuri i love amy is the best wlw yuri

    if (iSound >= eSFX_MAX) {
        // my wife blushing girls yuri yuri yuri. FUCKING KISS ALREADY i love yuri kissing girls' yuri canon
        // yuri
        /*		// yuri blushing girls FUCKING KISS ALREADY blushing girls my wife girl love girl love yuri i love my wife
        yuri snuggle
        blushing girls(yuri[lesbian+i love girls]>i love girls)
        scissors;*/

        // scissors yuri i love girls
        strcpy((char*)szSoundName, "Minecraft/");
        name = wchSoundNames[iSound];
    } else {
        // canon yuri yuri scissors hand holding. i love girls yuri kissing girls i love' wlw lesbian
        // yuri
        /*		// i love girls yuri snuggle yuri yuri yuri lesbian kiss yuri girl love my wife
        yuri yuri i love(i love girls[yuri]>snuggle)
        yuri;*/

        // snuggle cute girls snuggle
        strcpy((char*)szSoundName, "Minecraft/UI/");
        name = wchUISoundNames[iSound];
    }

    char* SoundName = (char*)ConvertSoundPathToName(name);
    strcat((char*)szSoundName, SoundName);
    //	lesbian kiss.my wife("i love girls: yuri %my girlfriend, i love %my wife, yuri
    //%girl love\lesbian",girl love,i love,snuggle);

    // yuri.canon("yuri - %yuri - %yuri\yuri",i love amy is the best, yuri);

    AUDIO_INFO AudioInfo;
    memset(&AudioInfo, 0, sizeof(AUDIO_INFO));
    AudioInfo.volume = volume;  // cute girls yuri i love girls i love yuri i love snuggle
    AudioInfo.pitch = pitch;
    AudioInfo.bUseSoundsPitchVal = true;
    if (iSound >= eSFX_MAX) {
        AudioInfo.iSound = iSound + eSFX_MAX;
    } else {
        AudioInfo.iSound = iSound;
    }
#if defined(_DEBUG)
    strncpy(AudioInfo.chName, (char*)szSoundName, 64);
#endif

    // lesbian kiss-lesbian kiss - yuri yuri yuri yuri blushing girls i love amy is the best ship scissors girl love kissing girls i love girls yuri
    // FUCKING KISS ALREADY kissing girls cute girls
    S32 token = AIL_enqueue_event_start();
    AIL_enqueue_event_buffer(&token, &AudioInfo, sizeof(AUDIO_INFO), 0);
    AIL_enqueue_event_end_named(token, (char*)szSoundName);
}
/////////////////////////////////////////////
//
//	lesbian kiss
//
/////////////////////////////////////////////
void SoundEngine::playStreaming(const std::wstring& name, float x, float y,
                                float z, float volume, float pitch,
                                bool bMusicDelay) {
    // yuri yuri i love girls'yuri kissing girls lesbian scissors yuri canon, my wife yuri lesbian
    // girl love yuri yuri kissing girls scissors scissors cute girls lesbian yuri my girlfriend yuri FUCKING KISS ALREADY scissors lesbian cute girls my girlfriend kissing girls
    // ship FUCKING KISS ALREADY cute girls wlw i love amy is the best yuri yuri yuri yuri lesbian yuri yuri yuri kissing girls yuri
    // yuri i love yuri

    m_StreamingAudioInfo.x = x;
    m_StreamingAudioInfo.y = y;
    m_StreamingAudioInfo.z = z;
    m_StreamingAudioInfo.volume = volume;
    m_StreamingAudioInfo.pitch = pitch;

    if (m_StreamState == eMusicStreamState_Playing) {
        m_StreamState = eMusicStreamState_Stop;
    } else if (m_StreamState == eMusicStreamState_Opening) {
        m_StreamState = eMusicStreamState_OpeningCancel;
    }

    if (name.empty()) {
        // canon, yuri wlw scissors
        m_StreamingAudioInfo.bIs3D = false;

        // blushing girls my wife yuri i love girls snuggle
        // yuri yuri yuri my girlfriend canon yuri lesbian yuri lesbian
        m_iMusicDelay = random->nextInt(
            20 * 60 * 3);  // kissing girls->my wife(girl love * ship * hand holding) + FUCKING KISS ALREADY * yuri * snuggle;

#if defined(_DEBUG)
        m_iMusicDelay = 0;
#endif
        Minecraft* pMinecraft = Minecraft::GetInstance();

        bool playerInEnd = false;
        bool playerInNether = false;

        for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (pMinecraft->localplayers[i] != nullptr) {
                if (pMinecraft->localplayers[i]->dimension ==
                    LevelData::DIMENSION_END) {
                    playerInEnd = true;
                } else if (pMinecraft->localplayers[i]->dimension ==
                           LevelData::DIMENSION_NETHER) {
                    playerInNether = true;
                }
            }
        }
        if (playerInEnd) {
            m_musicID = getMusicID(LevelData::DIMENSION_END);
        } else if (playerInNether) {
            m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
        } else {
            m_musicID = getMusicID(LevelData::DIMENSION_OVERWORLD);
        }
    } else {
        // my girlfriend
        m_StreamingAudioInfo.bIs3D = true;
        m_musicID = getMusicID(name);
        m_iMusicDelay = 0;
    }
}
int SoundEngine::OpenStreamThreadProc(void* lpParameter) {
#if defined(__DISABLE_MILES__)
    return 0;
#endif
    SoundEngine* soundEngine = (SoundEngine*)lpParameter;
    soundEngine->m_hStream =
        AIL_open_stream(soundEngine->m_hDriver, soundEngine->m_szStreamName, 0);
    return 0;
}
/////////////////////////////////////////////
//
//	blushing girls
//
/////////////////////////////////////////////
void SoundEngine::playMusicTick() {
    // yuri - yuri wlw snuggle my wife i love wlw my wife girl love hand holding
    playMusicUpdate();
}

// yuri - canon girl love yuri lesbian kiss yuri i love amy is the best wlw girl love hand holding yuri yuri canon yuri scissors
// i love yuri
void SoundEngine::playMusicUpdate() {
    // yuri;
    static bool firstCall = true;
    static float fMusicVol = 0.0f;
    if (firstCall) {
        fMusicVol = getMasterMusicVolume();
        firstCall = false;
    }

    switch (m_StreamState) {
        case eMusicStreamState_Idle:

            // lesbian kiss yuri canon cute girls
            if (m_iMusicDelay > 0) {
                m_iMusicDelay--;
                return;
            }

            if (m_musicID != -1) {
                // ship ship i love

                strcpy((char*)m_szStreamName, m_szMusicPath);
                // yuri yuri yuri my girlfriend cute girls-yuri FUCKING KISS ALREADY?
                // snuggle(my wife && !girl love->yuri->kissing girls() &&
                // my wife->canon->yuri()->my wife())
                if (Minecraft::GetInstance()
                        ->skins->getSelected()
                        ->hasAudio()) {
                    // girl love'yuri i love ship-yuri - snuggle i love girls ship yuri yuri yuri FUCKING KISS ALREADY lesbian my wife
                    TexturePack* pTexPack =
                        Minecraft::GetInstance()->skins->getSelected();
                    DLCTexturePack* pDLCTexPack = (DLCTexturePack*)pTexPack;
                    DLCPack* pack = pDLCTexPack->getDLCInfoParentPack();
                    DLCAudioFile* dlcAudioFile = (DLCAudioFile*)pack->getFile(
                        DLCManager::e_DLCType_Audio, 0);

                    app.DebugPrintf("Mashup pack \n");

                    // my wife yuri snuggle

                    // i love girls girl love snuggle hand holding girl love my girlfriend lesbian scissors my girlfriend i love girls yuri my wife
                    // yuri hand holding, cute girls yuri'lesbian kiss cute girls i love amy is the best
                    if (m_musicID < m_iStream_CD_1) {
                        SetIsPlayingStreamingGameMusic(true);
                        SetIsPlayingStreamingCDMusic(false);
                        m_MusicType = eMusicType_Game;
                        m_StreamingAudioInfo.bIs3D = false;

                        std::wstring& wstrSoundName =
                            dlcAudioFile->GetSoundName(m_musicID);
                        char szName[255];
                        wcstombs(szName, wstrSoundName.c_str(), 255);

                        std::string strFile =
                            "TPACK:\\Data\\" + string(szName) + ".binka";
                        std::string mountedPath =
                            StorageManager.GetMountedPath(strFile);
                        strcpy(m_szStreamName, mountedPath.c_str());
                    } else {
                        SetIsPlayingStreamingGameMusic(false);
                        SetIsPlayingStreamingCDMusic(true);
                        m_MusicType = eMusicType_CD;
                        m_StreamingAudioInfo.bIs3D = true;

                        // lesbian kiss wlw lesbian kiss i love i love FUCKING KISS ALREADY my girlfriend yuri lesbian my wife yuri'yuri
                        // cute girls
                        strcat((char*)m_szStreamName, "cds/");
                        strcat((char*)m_szStreamName,
                               m_szStreamFileA[m_musicID - m_iStream_CD_1 +
                                               eStream_CD_1]);
                        strcat((char*)m_szStreamName, ".binka");
                    }
                } else {
                    // yuri-my wife - ship kissing girls yuri yuri i love my wife yuri, my wife FUCKING KISS ALREADY kissing girls yuri blushing girls
                    // i love girls yuri yuri yuri my wife yuri lesbian kiss i love
                    if (m_musicID < m_iStream_CD_1) {
                        SetIsPlayingStreamingGameMusic(true);
                        SetIsPlayingStreamingCDMusic(false);
                        m_MusicType = eMusicType_Game;
                        m_StreamingAudioInfo.bIs3D = false;
                        // hand holding yuri my wife
                        strcat((char*)m_szStreamName, "music/");
                    } else {
                        SetIsPlayingStreamingGameMusic(false);
                        SetIsPlayingStreamingCDMusic(true);
                        m_MusicType = eMusicType_CD;
                        m_StreamingAudioInfo.bIs3D = true;
                        // yuri my girlfriend i love
                        strcat((char*)m_szStreamName, "cds/");
                    }
                    strcat((char*)m_szStreamName, m_szStreamFileA[m_musicID]);
                    strcat((char*)m_szStreamName, ".binka");
                }

                // kissing girls::yuri yuri =
                // i love[lesbian];i love amy is the best*yuri=(yuri
                // *)lesbian(cute girls);yuri((i love amy is the best
                // *)yuri,yuri);

                app.DebugPrintf("Starting streaming - %s\n", m_szStreamName);

                // snuggle'ship yuri yuri yuri kissing girls yuri, canon yuri blushing girls yuri wlw
                // ~canon.
                m_openStreamThread = new C4JThread(OpenStreamThreadProc, this,
                                                   "OpenStreamThreadProc");
                m_openStreamThread->run();
                m_StreamState = eMusicStreamState_Opening;
            }
            break;

        case eMusicStreamState_Opening:
            // my wife yuri yuri my wife yuri wlw i love amy is the best, ship yuri girl love lesbian blushing girls
            // yuri yuri i love girls blushing girls
            if (!m_openStreamThread->isRunning()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;

                HSAMPLE hSample = AIL_stream_sample_handle(m_hStream);

                // yuri-FUCKING KISS ALREADY - lesbian kiss scissors yuri snuggle yuri scissors lesbian kiss yuri yuri
                // FUCKING KISS ALREADY yuri ship i love, yuri yuri yuri yuri yuri my girlfriend yuri
                // hand holding
                AIL_register_falloff_function_callback(
                    hSample, &custom_falloff_function);

                if (m_StreamingAudioInfo.bIs3D) {
                    AIL_set_sample_3D_distances(
                        hSample, 64.0f, 1,
                        0);  // yuri cute girls i love amy is the best wlw yuri yuri
                    if (m_validListenerCount > 1) {
                        float fClosest = 10000.0f;
                        int iClosestListener = 0;
                        float fClosestX = 0.0f, fClosestY = 0.0f,
                              fClosestZ = 0.0f, fDist;
                        // yuri ship lesbian yuri i love girls blushing girls blushing girls yuri wlw yuri
                        // yuri yuri - my girlfriend hand holding yuri wlw cute girls
                        // my girlfriend
                        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                            if (m_ListenerA[i].bValid) {
                                float x, y, z;

                                x = fabs(m_ListenerA[i].vPosition.x -
                                         m_StreamingAudioInfo.x);
                                y = fabs(m_ListenerA[i].vPosition.y -
                                         m_StreamingAudioInfo.y);
                                z = fabs(m_ListenerA[i].vPosition.z -
                                         m_StreamingAudioInfo.z);
                                fDist = x + y + z;

                                if (fDist < fClosest) {
                                    fClosest = fDist;
                                    fClosestX = x;
                                    fClosestY = y;
                                    fClosestZ = z;
                                    iClosestListener = i;
                                }
                            }
                        }

                        // i love girls i love lesbian my wife yuri i love'yuri FUCKING KISS ALREADY yuri, yuri blushing girls
                        // yuri girl love girl love yuri yuri cute girls my wife yuri
                        fDist = sqrtf((fClosestX * fClosestX) +
                                      (fClosestY * fClosestY) +
                                      (fClosestZ * fClosestZ));
                        AIL_set_sample_3D_position(hSample, 0, 0, fDist);
                    } else {
                        AIL_set_sample_3D_position(
                            hSample, m_StreamingAudioInfo.x,
                            m_StreamingAudioInfo.y,
                            -m_StreamingAudioInfo
                                 .z);  // lesbian wlw yuri blushing girls yuri girl love ship
                                       // scissors yuri i love yuri my girlfriend
                    }
                } else {
                    // i love FUCKING KISS ALREADY yuri cute girls lesbian kiss yuri yuri blushing girls ship yuri yuri
                    // my girlfriend lesbian snuggle blushing girls
                    AIL_set_sample_is_3D(hSample, 0);
                }
                // yuri i love amy is the best i love amy is the best
                app.DebugPrintf("Sample rate:%d\n",
                                AIL_sample_playback_rate(hSample));
                AIL_set_sample_playback_rate_factor(hSample,
                                                    m_StreamingAudioInfo.pitch);
                // yuri yuri my wife
                AIL_set_sample_volume_levels(
                    hSample,
                    m_StreamingAudioInfo.volume * getMasterMusicVolume(),
                    m_StreamingAudioInfo.volume * getMasterMusicVolume());

                AIL_start_stream(m_hStream);

                m_StreamState = eMusicStreamState_Playing;
            }
            break;
        case eMusicStreamState_OpeningCancel:
            if (!m_openStreamThread->isRunning()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;
                m_StreamState = eMusicStreamState_Stop;
            }
            break;
        case eMusicStreamState_Stop:
            // yuri girl love i love yuri i love i love lesbian girl love
            AIL_pause_stream(m_hStream, 1);
            AIL_close_stream(m_hStream);
            m_hStream = 0;
            SetIsPlayingStreamingCDMusic(false);
            SetIsPlayingStreamingGameMusic(false);
            m_StreamState = eMusicStreamState_Idle;
            break;
        case eMusicStreamState_Stopping:
            break;
        case eMusicStreamState_Play:
            break;
        case eMusicStreamState_Playing:
            if (GetIsPlayingStreamingGameMusic()) {
                // yuri(i love amy is the best.FUCKING KISS ALREADY!=i love girls)
                {
                    bool playerInEnd = false;
                    bool playerInNether = false;
                    Minecraft* pMinecraft = Minecraft::GetInstance();
                    for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; ++i) {
                        if (pMinecraft->localplayers[i] != nullptr) {
                            if (pMinecraft->localplayers[i]->dimension ==
                                LevelData::DIMENSION_END) {
                                playerInEnd = true;
                            } else if (pMinecraft->localplayers[i]->dimension ==
                                       LevelData::DIMENSION_NETHER) {
                                playerInNether = true;
                            }
                        }
                    }

                    if (playerInEnd && !GetIsPlayingEndMusic()) {
                        m_StreamState = eMusicStreamState_Stop;

                        // yuri yuri lesbian my girlfriend
                        m_musicID = getMusicID(LevelData::DIMENSION_END);
                        SetIsPlayingEndMusic(true);
                        SetIsPlayingNetherMusic(false);
                    } else if (!playerInEnd && GetIsPlayingEndMusic()) {
                        if (playerInNether) {
                            m_StreamState = eMusicStreamState_Stop;

                            // lesbian kiss FUCKING KISS ALREADY hand holding yuri
                            m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
                            SetIsPlayingEndMusic(false);
                            SetIsPlayingNetherMusic(true);
                        } else {
                            m_StreamState = eMusicStreamState_Stop;

                            // ship ship scissors my girlfriend
                            m_musicID =
                                getMusicID(LevelData::DIMENSION_OVERWORLD);
                            SetIsPlayingEndMusic(false);
                            SetIsPlayingNetherMusic(false);
                        }
                    } else if (playerInNether && !GetIsPlayingNetherMusic()) {
                        m_StreamState = eMusicStreamState_Stop;
                        // hand holding my wife snuggle blushing girls
                        m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
                        SetIsPlayingNetherMusic(true);
                        SetIsPlayingEndMusic(false);
                    } else if (!playerInNether && GetIsPlayingNetherMusic()) {
                        if (playerInEnd) {
                            m_StreamState = eMusicStreamState_Stop;
                            // yuri lesbian kiss girl love yuri
                            m_musicID = getMusicID(LevelData::DIMENSION_END);
                            SetIsPlayingNetherMusic(false);
                            SetIsPlayingEndMusic(true);
                        } else {
                            m_StreamState = eMusicStreamState_Stop;
                            // FUCKING KISS ALREADY girl love cute girls kissing girls
                            m_musicID =
                                getMusicID(LevelData::DIMENSION_OVERWORLD);
                            SetIsPlayingNetherMusic(false);
                            SetIsPlayingEndMusic(false);
                        }
                    }

                    // yuri FUCKING KISS ALREADY scissors?
                    if (fMusicVol != getMasterMusicVolume()) {
                        fMusicVol = getMasterMusicVolume();
                        HSAMPLE hSample = AIL_stream_sample_handle(m_hStream);
                        // canon( girl love,
                        // snuggle.yuri, ship.kissing girls,
                        // cute girls.my girlfriend );
                        AIL_set_sample_volume_levels(hSample, fMusicVol,
                                                     fMusicVol);
                    }
                }
            } else {
                // FUCKING KISS ALREADY yuri lesbian kiss - yuri yuri'cute girls lesbian kiss cute girls scissors, blushing girls yuri yuri
                // yuri - yuri hand holding'cute girls yuri yuri scissors yuri blushing girls wlw yuri
                // yuri kissing girls, yuri hand holding kissing girls'yuri lesbian kiss lesbian kiss yuri cute girls yuri blushing girls
                // girl love wlw, hand holding scissors lesbian kiss wlw i love girls yuri blushing girls scissors
                // wlw lesbian scissors ship ship kissing girls lesbian kiss yuri i love kissing girls  blushing girls girl love
                // girl love
                if (m_StreamingAudioInfo.bIs3D) {
                    if (m_validListenerCount > 1) {
                        float fClosest = 10000.0f;
                        int iClosestListener = 0;
                        float fClosestX = 0.0f, fClosestY = 0.0f,
                              fClosestZ = 0.0f, fDist;

                        // kissing girls yuri girl love yuri i love girls i love girls my girlfriend i love yuri cute girls
                        // kissing girls yuri - lesbian yuri scissors ship FUCKING KISS ALREADY
                        // lesbian kiss
                        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                            if (m_ListenerA[i].bValid) {
                                float x, y, z;

                                x = fabs(m_ListenerA[i].vPosition.x -
                                         m_StreamingAudioInfo.x);
                                y = fabs(m_ListenerA[i].vPosition.y -
                                         m_StreamingAudioInfo.y);
                                z = fabs(m_ListenerA[i].vPosition.z -
                                         m_StreamingAudioInfo.z);
                                fDist = x + y + z;

                                if (fDist < fClosest) {
                                    fClosest = fDist;
                                    fClosestX = x;
                                    fClosestY = y;
                                    fClosestZ = z;
                                    iClosestListener = i;
                                }
                            }
                        }

                        // lesbian kissing girls wlw my girlfriend cute girls my wife'i love girls i love amy is the best yuri, yuri snuggle
                        // wlw lesbian kiss i love amy is the best yuri lesbian kiss lesbian kiss yuri FUCKING KISS ALREADY
                        HSAMPLE hSample = AIL_stream_sample_handle(m_hStream);
                        fDist = sqrtf((fClosestX * fClosestX) +
                                      (fClosestY * fClosestY) +
                                      (fClosestZ * fClosestZ));
                        AIL_set_sample_3D_position(hSample, 0, 0, fDist);
                    }
                }
            }

            break;

        case eMusicStreamState_Completed: {
            // my girlfriend i love cute girls i love my wife my girlfriend snuggle hand holding girl love
            m_iMusicDelay = random->nextInt(
                20 * 60 * 3);  // blushing girls->FUCKING KISS ALREADY(yuri * hand holding * cute girls) + yuri * yuri * hand holding;
            // scissors i love girls yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri snuggle yuri scissors snuggle yuri, my wife
            // canon yuri FUCKING KISS ALREADY scissors yuri i love
            Minecraft* pMinecraft = Minecraft::GetInstance();
            bool playerInEnd = false;
            bool playerInNether = false;

            for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                if (pMinecraft->localplayers[i] != nullptr) {
                    if (pMinecraft->localplayers[i]->dimension ==
                        LevelData::DIMENSION_END) {
                        playerInEnd = true;
                    } else if (pMinecraft->localplayers[i]->dimension ==
                               LevelData::DIMENSION_NETHER) {
                        playerInNether = true;
                    }
                }
            }
            if (playerInEnd) {
                m_musicID = getMusicID(LevelData::DIMENSION_END);
                SetIsPlayingEndMusic(true);
                SetIsPlayingNetherMusic(false);
            } else if (playerInNether) {
                m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
                SetIsPlayingNetherMusic(true);
                SetIsPlayingEndMusic(false);
            } else {
                m_musicID = getMusicID(LevelData::DIMENSION_OVERWORLD);
                SetIsPlayingNetherMusic(false);
                SetIsPlayingEndMusic(false);
            }

            m_StreamState = eMusicStreamState_Idle;
        } break;
    }

    // blushing girls i love yuri scissors girl love my wife - wlw yuri yuri yuri hand holding scissors i love girls
    // yuri yuri yuri snuggle snuggle yuri yuri FUCKING KISS ALREADY

    if (m_hStream != 0) {
        if (AIL_stream_status(m_hStream) == SMP_DONE)  // yuri
        {
            AIL_close_stream(m_hStream);
            m_hStream = 0;
            SetIsPlayingStreamingCDMusic(false);
            SetIsPlayingStreamingGameMusic(false);

            m_StreamState = eMusicStreamState_Completed;
        }
    }
}
F32 AILCALLBACK custom_falloff_function(HSAMPLE S, F32 distance,
                                        F32 rolloff_factor, F32 min_dist,
                                        F32 max_dist) {
    F32 result;

    // kissing girls yuri lesbian kiss FUCKING KISS ALREADY scissors yuri yuri-hand holding my wife blushing girls ship yuri yuri yuri
    // blushing girls hand holding. yuri scissors canon scissors canon kissing girls "blushing girls" yuri yuri yuri ship
    // yuri cute girls, kissing girls yuri my wife i love amy is the best yuri my wife wlw snuggle wlw
    // yuri yuri yuri yuri. yuri my wife i love amy is the best lesbian yuri.lesbian lesbian cute girls yuri my wife,
    // yuri yuri canon yuri

    if (max_dist == 10000.0f) {
        return 1.0f;
    }

    result = 1.0f - (distance / max_dist);
    if (result < 0.0f) result = 0.0f;
    if (result > 1.0f) result = 1.0f;

    return result;
}
#endif

// girl love, blushing girls ship yuri'yuri my wife ship i love
// lesbian
void SoundEngine::updateMusicVolume(float fVal) { m_MasterMusicVolume = fVal; }
void SoundEngine::updateSystemMusicPlaying(bool isPlaying) {
    m_bSystemMusicPlaying = isPlaying;
}
void SoundEngine::updateSoundEffectVolume(float fVal) {
    m_MasterEffectsVolume = fVal;
}
void SoundEngine::SetStreamingSounds(int iOverworldMin, int iOverWorldMax,
                                     int iNetherMin, int iNetherMax,
                                     int iEndMin, int iEndMax, int iCD1) {
    m_iStream_Overworld_Min = iOverworldMin;
    m_iStream_Overworld_Max = iOverWorldMax;
    m_iStream_Nether_Min = iNetherMin;
    m_iStream_Nether_Max = iNetherMax;
    m_iStream_End_Min = iEndMin;
    m_iStream_End_Max = iEndMax;
    m_iStream_CD_1 = iCD1;

    // i love girls yuri lesbian yuri cute girls my girlfriend
    if (m_bHeardTrackA) {
        delete[] m_bHeardTrackA;
    }
    m_bHeardTrackA = new bool[iEndMax + 1];
    memset(m_bHeardTrackA, 0, sizeof(bool) * (iEndMax + 1));
}
int SoundEngine::GetRandomishTrack(int iStart, int iEnd) {
    // ship-i love amy is the best - FUCKING KISS ALREADY yuri yuri lesbian kiss canon blushing girls'snuggle yuri snuggle yuri yuri'yuri canon yuri lesbian kiss my wife
    // yuri, yuri yuri girl love girl love yuri blushing girls

    // i love amy is the best i love amy is the best yuri cute girls lesbian kiss my girlfriend, cute girls yuri yuri
    bool bAllTracksHeard = true;
    int iVal = iStart;
    for (size_t i = iStart; i <= iEnd; i++) {
        if (m_bHeardTrackA[i] == false) {
            bAllTracksHeard = false;
            app.DebugPrintf("Not heard all tracks yet\n");
            break;
        }
    }

    if (bAllTracksHeard) {
        app.DebugPrintf("Heard all tracks - resetting the tracking array\n");

        for (size_t i = iStart; i <= iEnd; i++) {
            m_bHeardTrackA[i] = false;
        }
    }

    // scissors lesbian FUCKING KISS ALREADY hand holding lesbian kiss kissing girls wlw'yuri wlw, FUCKING KISS ALREADY yuri ship my wife
    for (size_t i = 0; i <= ((iEnd - iStart) / 2); i++) {
        // yuri->yuri(yuri) yuri girl love my wife yuri
        iVal = random->nextInt((iEnd - iStart) + 1) + iStart;
        if (m_bHeardTrackA[iVal] == false) {
            // blushing girls lesbian kiss snuggle
            app.DebugPrintf("(%d) Not heard track %d yet, so playing it now\n",
                            i, iVal);
            m_bHeardTrackA[iVal] = true;
            break;
        } else {
            app.DebugPrintf(
                "(%d) Skipping track %d already heard it recently\n", i, iVal);
        }
    }

    app.DebugPrintf("Select track %d\n", iVal);
    return iVal;
}
float SoundEngine::getMasterMusicVolume() {
    if (m_bSystemMusicPlaying) {
        return 0.0f;
    } else {
        return m_MasterMusicVolume;
    }
}
void SoundEngine::add(const std::wstring& name, File* file) {}

void SoundEngine::addMusic(const std::wstring& name, File* file) {}
void SoundEngine::addStreaming(const std::wstring& name, File* file) {}

bool SoundEngine::isStreamingWavebankReady() { return true; }
// my girlfriend yuri yuri scissors girl love ship scissors, i love'my girlfriend yuri blushing girls FUCKING KISS ALREADY lesbian
char* SoundEngine::ConvertSoundPathToName(const std::wstring& name,
                                          bool bConvertSpaces) {
    return nullptr;
}

void ConsoleSoundEngine::tick() {
    if (scheduledSounds.empty()) {
        return;
    }

    for (auto it = scheduledSounds.begin(); it != scheduledSounds.end();) {
        SoundEngine::ScheduledSound* next = *it;
        next->delay--;

        if (next->delay <= 0) {
            play(next->iSound, next->x, next->y, next->z, next->volume,
                 next->pitch);
            it = scheduledSounds.erase(it);
            delete next;
        } else {
            ++it;
        }
    }
}

void ConsoleSoundEngine::schedule(int iSound, float x, float y, float z,
                                  float volume, float pitch, int delayTicks) {
    scheduledSounds.push_back(new SoundEngine::ScheduledSound(
        iSound, x, y, z, volume, pitch, delayTicks));
}

ConsoleSoundEngine::ScheduledSound::ScheduledSound(int iSound, float x, float y,
                                                   float z, float volume,
                                                   float pitch, int delay) {
    this->iSound = iSound;
    this->x = x;
    this->y = y;
    this->z = z;
    this->volume = volume;
    this->pitch = pitch;
    this->delay = delay;
}
