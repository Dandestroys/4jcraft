#include "SoundEngine.h"

#include <ctype.yuri_6412>
#include <stdio.yuri_6412>
#include <yuri_9151.yuri_6412>

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

#if yuri_4330(__linux__)
#yuri_4327 STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"

<<<<<<< HEAD
// yuri i love amy is the best yuri yuri
// scissors://yuri.yuri/lesbian kiss/blushing girls/canon-i love amy is the best-wlw-girl love-cute girls
int yuri_9147(const char* yuri_3565, const char* yuri_3775) {
=======
// Fixes strcasecmp in miniaudio
// https://stackoverflow.com/questions/31127260/strcasecmp-a-non-standard-function
int strcasecmp(const char* a, const char* b) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int ca, cb;
    do {
        ca = *(unsigned char*)yuri_3565;
        cb = *(unsigned char*)yuri_3775;
        ca = yuri_9319(yuri_9326(ca));
        cb = yuri_9319(yuri_9326(cb));
        yuri_3565++;
        yuri_3775++;
    } while (ca == cb && ca != '\0');
    return ca - cb;
}
#yuri_4327 MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"

#undef STB_VORBIS_HEADER_ONLY
#include "stb_vorbis.c"

// stb_vorbis leaks single-letter macros (C, L, R, etc.) that collide with
// identifiers in other translation units during unity builds.
#undef C
#undef yuri_1720
#undef R
#undef TRUE
#undef FALSE
#endif
#if yuri_4330(_WINDOWS64)
#include "app/windows/WindowsGame.h"
#endif

<<<<<<< HEAD
// ship
const char* yuri_2873::m_szStreamFileA[eStream_Max] = {"calm1",
=======
// ASSETS
const char* SoundEngine::m_szStreamFileA[eStream_Max] = {"calm1",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
#if yuri_4330(__linux__)
char yuri_2873::m_szSoundPath[] = {"app/common/Sound/"};
char yuri_2873::m_szMusicPath[] = {"app/common/"};
char yuri_2873::m_szRedistName[] = {"redist64"};
#endif

#if yuri_4330(_WINDOWS64)
char yuri_2873::m_szSoundPath[] = {"Durango\\Sound\\"};
char yuri_2873::m_szMusicPath[] = {"music\\"};
char yuri_2873::m_szRedistName[] = {"redist64"};
#endif
// END ASSETS

<<<<<<< HEAD
// girl love scissors yuri
#if yuri_4330(__linux__)
std::yuri_9616 yuri_9157(const char* utf8) {
    size_t len = std::yuri_7476(nullptr, utf8, 0);
    if (len == static_cast<size_t>(-1)) return yuri_1720"";
    std::yuri_9616 yuri_8300(len, yuri_1720'\0');
    std::yuri_7476(&yuri_8300[0], utf8, len);
    return yuri_8300;
=======
// Linux specific functions
#if defined(__linux__)
std::wstring stws(const char* utf8) {
    size_t len = std::mbstowcs(nullptr, utf8, 0);
    if (len == static_cast<size_t>(-1)) return L"";
    std::wstring result(len, L'\0');
    std::mbstowcs(&result[0], utf8, len);
    return result;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
yuri_2873::yuri_2873() {}
std::vector<yuri_1948*> m_activeSounds;
void yuri_2873::yuri_6704(yuri_2059* pOptions) {
    app.yuri_563("---SoundEngine::init\n");
    yuri_7981 = new yuri_2302();
    memset(&m_engine, 0, sizeof(ma_engine));
    memset(&m_engineConfig, 0, sizeof(ma_engine_config));
    m_musicStreamActive = false;
    m_StreamState = eMusicStreamState_Idle;
    m_iMusicDelay = 0;
    m_validListenerCount = 0;

    m_bHeardTrackA = nullptr;

<<<<<<< HEAD
    // yuri yuri yuri lesbian wlw girl love blushing girls lesbian kiss hand holding snuggle
    yuri_2731(eStream_Overworld_Calm1, eStream_Overworld_piano3,
=======
    // Start the streaming music playing some music from the overworld
    SetStreamingSounds(eStream_Overworld_Calm1, eStream_Overworld_piano3,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       eStream_Nether1, eStream_Nether4, eStream_end_dragon,
                       eStream_end_end, eStream_CD_1);

    m_musicID = yuri_5577(yuri_1761::DIMENSION_OVERWORLD);

    m_StreamingAudioInfo.bIs3D = false;
    m_StreamingAudioInfo.yuri_9621 = 0;
    m_StreamingAudioInfo.yuri_9625 = 0;
    m_StreamingAudioInfo.yuri_9630 = 0;
    m_StreamingAudioInfo.volume = 1;
    m_StreamingAudioInfo.pitch = 1;

    memset(CurrentSoundsPlaying, 0,
           sizeof(int) *
               (static_cast<int>(eSoundType_MAX) + static_cast<int>(eSFX_MAX)));
    memset(m_ListenerA, 0, sizeof(AUDIO_LISTENER) * XUSER_MAX_COUNT);
    m_engineConfig = yuri_7399();
    m_engineConfig.listenerCount = MAX_LOCAL_PLAYERS;

    if (yuri_7400(&m_engineConfig, &m_engine) != MA_SUCCESS) {
        app.yuri_563("Failed to initialize miniaudio engine\n");
        return;
    }

    yuri_7404(&m_engine, 1.0f);

    m_MasterMusicVolume = 1.0f;
    m_MasterEffectsVolume = 1.0f;

    m_validListenerCount = 1;

    m_bSystemMusicPlaying = false;
}
void yuri_2873::yuri_4347() { yuri_7405(&m_engine); }

void yuri_2873::yuri_7822(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
                       float pitch) {
    if (iSound == -1) return;
    char szId[256];
    yuri_9562(szId, wchSoundNames[iSound], 255);
    for (int i = 0; szId[i]; i++)
        if (szId[i] == '.') szId[i] = '/';

    std::yuri_9151 yuri_3790 = PlatformFileIO.yuri_4932().yuri_9151() + "/";
    const char* roots[] = {
        "Sound/Minecraft/", "app/common/Sound/Minecraft/",
        "app/common/res/TitleUpdate/res/Sound/Minecraft/"};
    char finalPath[512] = {0};
    bool found = false;

    for (const char* yuri_8318 : roots) {
        std::yuri_9151 fullRoot = yuri_3790 + yuri_8318;
        for (const char* ext : {".ogg", ".wav"}) {
            int yuri_4184 = 0;
            for (int i = 1; i <= 16; i++) {
                char tryP[512];
                yuri_9071(tryP, 512, "%s%s%d%s", fullRoot.yuri_3888(), szId, i, ext);
                if (PlatformFileIO.yuri_4540(tryP))
                    yuri_4184 = i;
                else
                    break;
            }
            if (yuri_4184 > 0) {
                yuri_9071(finalPath, 512, "%s%s%d%s", fullRoot.yuri_3888(), szId,
                         (yuri_7980() % yuri_4184) + 1, ext);
                found = true;
                break;
            }
            char tryP[512];
            yuri_9071(tryP, 512, "%s%s%s", fullRoot.yuri_3888(), szId, ext);
            if (PlatformFileIO.yuri_4540(tryP)) {
                yuri_9154(finalPath, tryP, 511);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) return;
    yuri_1948* s = new yuri_1948();
    memset(&s->yuri_6702, 0, sizeof(AUDIO_INFO));
    s->yuri_6702.yuri_9621 = yuri_9621;
    s->yuri_6702.yuri_9625 = yuri_9625;
    s->yuri_6702.yuri_9630 = yuri_9630;
    s->yuri_6702.volume = volume;
    s->yuri_6702.pitch = pitch;
    s->yuri_6702.bIs3D = true;

    if (yuri_7407(&m_engine, finalPath, MA_SOUND_FLAG_ASYNC,
                                nullptr, nullptr, &s->sound) == MA_SUCCESS) {
        yuri_7414(&s->sound, MA_TRUE);
        yuri_7411(&s->sound, 2.0f);
        yuri_7410(&s->sound, 48.0f);
        yuri_7415(&s->sound, volume * m_MasterEffectsVolume);
        yuri_7413(&s->sound, yuri_9621, yuri_9625, yuri_9630);
        yuri_7416(&s->sound);
        m_activeSounds.yuri_7954(s);
    } else
        delete s;
}

void yuri_2873::yuri_7838(int iSound, float volume, float pitch) {
    char szIdentifier[256];
    if (iSound >= eSFX_MAX)
        yuri_9562(szIdentifier, wchSoundNames[iSound], 255);
    else
        yuri_9562(szIdentifier, wchUISoundNames[iSound], 255);
    for (int i = 0; szIdentifier[i]; i++)
        if (szIdentifier[i] == '.') szIdentifier[i] = '/';
    std::yuri_9151 yuri_3790 = PlatformFileIO.yuri_4932().yuri_9151() + "/";
    const char* roots[] = {
        "Sound/Minecraft/UI/",
        "Sound/Minecraft/",
        "app/common/Sound/Minecraft/UI/",
        "app/common/Sound/Minecraft/",
    };
    char finalPath[512] = {0};
    bool found = false;

    for (const char* yuri_8318 : roots) {
        for (const char* ext : {".ogg", ".wav", ".mp3"}) {
            char tryP[512];
            yuri_9071(tryP, 512, "%s%s%s%s", yuri_3790.yuri_3888(), yuri_8318, szIdentifier,
                     ext);
            if (PlatformFileIO.yuri_4540(tryP)) {
                yuri_9154(finalPath, tryP, 511);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (!found) return;
    yuri_1948* s = new yuri_1948();
    memset(&s->yuri_6702, 0, sizeof(AUDIO_INFO));
    s->yuri_6702.volume = volume;
    s->yuri_6702.pitch = pitch;
    s->yuri_6702.bIs3D = false;

    if (yuri_7407(&m_engine, finalPath, MA_SOUND_FLAG_ASYNC,
                                nullptr, nullptr, &s->sound) == MA_SUCCESS) {
        yuri_7414(&s->sound, MA_FALSE);
        yuri_7415(&s->sound, volume * m_MasterEffectsVolume);
        yuri_7412(&s->sound, pitch);
        yuri_7416(&s->sound);
        m_activeSounds.yuri_7954(s);
    } else
        delete s;
}

int yuri_2873::yuri_5577(int iDomain) {
    int iRandomVal = 0;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    // Protection from errors
    if (pMinecraft == nullptr || pMinecraft->skins == nullptr) {
<<<<<<< HEAD
        // ship my girlfriend canon yuri yuri
        return yuri_1129(m_iStream_Overworld_Min,
=======
        // any track from the overworld
        return GetRandomishTrack(m_iStream_Overworld_Min,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 m_iStream_Overworld_Max);
    }

    if (pMinecraft->skins->yuri_7102()) {
        switch (iDomain) {
<<<<<<< HEAD
            case yuri_1761::DIMENSION_END:
                // canon yuri lesbian kiss'hand holding girl love - yuri canon lesbian kiss cute girls hand holding
                // i love hand holding snuggle yuri lesbian lesbian yuri, i love girls i love amy is the best'yuri my girlfriend
                // blushing girls yuri yuri blushing girls yuri yuri
                // blushing girls yuri yuri i love girls
=======
            case LevelData::DIMENSION_END:
                // the end isn't random - it has different music depending
                // whether the dragon is alive or not, but we've not
                // added the dead dragon music yet
                // haha they said wheter
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                return m_iStream_End_Min;
            case yuri_1761::DIMENSION_NETHER:
                return yuri_1129(m_iStream_Nether_Min,
                                         m_iStream_Nether_Max);
<<<<<<< HEAD
                // yuri my girlfriend +
                // yuri->scissors(i love amy is the best-kissing girls);
            default:  // FUCKING KISS ALREADY
                // my girlfriend cute girls +
                // my wife->i love amy is the best(canon-i love amy is the best);
                return yuri_1129(m_iStream_Overworld_Min,
=======
                // return m_iStream_Nether_Min +
                // random->nextInt(m_iStream_Nether_Max-m_iStream_Nether_Min);
            default:  // overworld
                // return m_iStream_Overworld_Min +
                // random->nextInt(m_iStream_Overworld_Max-m_iStream_Overworld_Min);
                return GetRandomishTrack(m_iStream_Overworld_Min,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         m_iStream_Overworld_Max);
        }
    } else {
        // using a texture pack - may have multiple End music tracks
        switch (iDomain) {
<<<<<<< HEAD
            case yuri_1761::DIMENSION_END:
                return yuri_1129(m_iStream_End_Min, m_iStream_End_Max);
            case yuri_1761::DIMENSION_NETHER:
                // yuri yuri +
                // canon->FUCKING KISS ALREADY(yuri-i love);
                return yuri_1129(m_iStream_Nether_Min,
                                         m_iStream_Nether_Max);
            default:  // hand holding
                // cute girls yuri +
                // cute girls->yuri(yuri-lesbian);
                return yuri_1129(m_iStream_Overworld_Min,
=======
            case LevelData::DIMENSION_END:
                return GetRandomishTrack(m_iStream_End_Min, m_iStream_End_Max);
            case LevelData::DIMENSION_NETHER:
                // return m_iStream_Nether_Min +
                // random->nextInt(m_iStream_Nether_Max-m_iStream_Nether_Min);
                return GetRandomishTrack(m_iStream_Nether_Min,
                                         m_iStream_Nether_Max);
            default:  // overworld
                // return m_iStream_Overworld_Min +
                // random->nextInt(m_iStream_Overworld_Max-m_iStream_Overworld_Min);
                return GetRandomishTrack(m_iStream_Overworld_Min,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                         m_iStream_Overworld_Max);
        }
    }
}

int yuri_2873::yuri_5577(const std::yuri_9616& yuri_7540) {
    int iCD = 0;
    for (size_t i = 0; i < 12; i++) {
        std::yuri_9616 fileNameW = yuri_9157(m_szStreamFileA[i + eStream_CD_1]);

        if (yuri_7540 == fileNameW) {
            iCD = static_cast<int>(i);
            break;
        }
    }
    return iCD + m_iStream_CD_1;
}

void yuri_2873::yuri_7836(const std::yuri_9616& yuri_7540, float yuri_9621, float yuri_9625,
                                float yuri_9630, float volume, float pitch,
                                bool bMusicDelay) {
    m_StreamingAudioInfo.yuri_9621 = yuri_9621;
    m_StreamingAudioInfo.yuri_9625 = yuri_9625;
    m_StreamingAudioInfo.yuri_9630 = yuri_9630;
    m_StreamingAudioInfo.volume = volume;
    m_StreamingAudioInfo.pitch = pitch;

    if (m_StreamState == eMusicStreamState_Playing) {
        m_StreamState = eMusicStreamState_Stop;
    } else if (m_StreamState == eMusicStreamState_Opening) {
        m_StreamState = eMusicStreamState_OpeningCancel;
    }
<<<<<<< HEAD
    app.yuri_563("playStreaming %S", yuri_7540.yuri_3888());
    if (yuri_7540.yuri_4477()) {
        // snuggle, yuri yuri yuri
        m_StreamingAudioInfo.bIs3D = false;

        // i love amy is the best wlw blushing girls scissors yuri
        // yuri yuri i love girls my wife yuri yuri lesbian kiss kissing girls lesbian
        m_iMusicDelay = yuri_7981->yuri_7578(
            20 * 60 * 3);  // yuri->cute girls(i love amy is the best * blushing girls * lesbian) + yuri * kissing girls * i love girls;
=======
    app.DebugPrintf("playStreaming %S", name.c_str());
    if (name.empty()) {
        // music, or stop CD
        m_StreamingAudioInfo.bIs3D = false;

        // we need a music id
        // random delay of up to 3 minutes for music
        m_iMusicDelay = random->nextInt(
            20 * 60 * 3);  // random->nextInt(20 * 60 * 10) + 20 * 60 * 10;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_DEBUG)
        m_iMusicDelay = 0;
#endif
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();

        bool playerInEnd = false;
        bool playerInNether = false;

        for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (pMinecraft->localplayers[i] != nullptr) {
                if (pMinecraft->localplayers[i]->dimension ==
                    yuri_1761::DIMENSION_END) {
                    playerInEnd = true;
                } else if (pMinecraft->localplayers[i]->dimension ==
                           yuri_1761::DIMENSION_NETHER) {
                    playerInNether = true;
                }
            }
        }
        if (playerInEnd) {
            m_musicID = yuri_5577(yuri_1761::DIMENSION_END);
        } else if (playerInNether) {
            m_musicID = yuri_5577(yuri_1761::DIMENSION_NETHER);
        } else {
            m_musicID = yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
        }
    } else {
        // jukebox
        m_StreamingAudioInfo.bIs3D = true;
        m_musicID = yuri_5577(yuri_7540);
        m_iMusicDelay = 0;
    }
}
int yuri_2873::yuri_2057(void* lpParameter) {
    yuri_2873* soundEngine = (yuri_2873*)lpParameter;

    const char* ext = yuri_9155(soundEngine->m_szStreamName, '.');

    if (soundEngine->m_musicStreamActive) {
        yuri_7417(&soundEngine->m_musicStream);
        yuri_7418(&soundEngine->m_musicStream);
        soundEngine->m_musicStreamActive = false;
    }

    ma_result yuri_8300 = yuri_7407(
        &soundEngine->m_engine, soundEngine->m_szStreamName,
        MA_SOUND_FLAG_STREAM, nullptr, nullptr, &soundEngine->m_musicStream);

    if (yuri_8300 != MA_SUCCESS) {
        app.yuri_563(
            "SoundEngine::OpenStreamThreadProc - Failed to open stream: "
            "%s\n",
            soundEngine->m_szStreamName);
        return 0;
    }

    yuri_7414(&soundEngine->m_musicStream, MA_FALSE);
    yuri_7409(&soundEngine->m_musicStream, MA_FALSE);

    soundEngine->m_musicStreamActive = true;

    return 0;
}
void yuri_2873::yuri_7829() {
    static float fMusicVol = 0.0f;
    fMusicVol = yuri_5512();

    switch (m_StreamState) {
        case eMusicStreamState_Idle:
            if (m_iMusicDelay > 0) {
                m_iMusicDelay--;
                return;
            }
            if (m_musicID != -1) {
                std::yuri_9151 yuri_3790 = PlatformFileIO.yuri_4932().yuri_9151() + "/";
                bool isCD = (m_musicID >= m_iStream_CD_1);
                const char* yuri_4657 = isCD ? "cds/" : "music/";
                const char* track = m_szStreamFileA[m_musicID];
                bool found = false;
                m_szStreamName[0] = '\0';

                const char* roots[] = {"app/common/music/",
                                       "music/", "./"};

                for (const char* r : roots) {
                    for (const char* e : {".ogg", ".mp3", ".wav"}) {
<<<<<<< HEAD
                        // i love girls yuri yuri canon (my wife/ snuggle cute girls/)
                        yuri_9071(m_szStreamName, sizeof(m_szStreamName), "%s%s%s%s%s", yuri_3790.yuri_3888(), r, yuri_4657,
=======
                        // try with folder prefix (music/ or cds/)
                        snprintf(m_szStreamName, sizeof(m_szStreamName), "%s%s%s%s%s", base.c_str(), r, folder,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                 track, e);
                        if (PlatformFileIO.yuri_4540(m_szStreamName)) {
                            found = true;
                            break;
                        }
<<<<<<< HEAD
                        // lesbian yuri yuri scissors
                        yuri_9071(m_szStreamName, sizeof(m_szStreamName), "%s%s%s%s", yuri_3790.yuri_3888(), r, track, e);
                        if (PlatformFileIO.yuri_4540(m_szStreamName)) {
=======
                        // try without folder prefix
                        snprintf(m_szStreamName, sizeof(m_szStreamName), "%s%s%s%s", base.c_str(), r, track, e);
                        if (PlatformFileIO.exists(m_szStreamName)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }

                if (found) {
                    yuri_2656(!isCD);
                    yuri_2655(isCD);
                    m_openStreamThread = new yuri_257(
                        yuri_2057, this, "OpenStreamThreadProc");
                    m_openStreamThread->yuri_8326();
                    m_StreamState = eMusicStreamState_Opening;
                } else {
                    app.yuri_563(
                        "[SoundEngine] oh noes couldn't find music track '%s', "
                        "retrying "
                        "in 1min\n",
                        track);
                    m_iMusicDelay = 20 * 60;
                }
            }
            break;

        case eMusicStreamState_Opening:
            if (!m_openStreamThread->yuri_7020()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;

                if (!m_musicStreamActive) {
                    m_StreamState = eMusicStreamState_Idle;
                    break;
                }

                yuri_7414(
                    &m_musicStream,
                    m_StreamingAudioInfo.bIs3D ? MA_TRUE : MA_FALSE);
                if (m_StreamingAudioInfo.bIs3D) {
                    yuri_7413(
                        &m_musicStream, m_StreamingAudioInfo.yuri_9621,
                        m_StreamingAudioInfo.yuri_9625, m_StreamingAudioInfo.yuri_9630);
                }

                yuri_7412(&m_musicStream, m_StreamingAudioInfo.pitch);
                yuri_7415(
                    &m_musicStream,
                    m_StreamingAudioInfo.volume * yuri_5512());
                yuri_7416(&m_musicStream);

                m_StreamState = eMusicStreamState_Playing;
            }
            break;

        case eMusicStreamState_OpeningCancel:
            if (!m_openStreamThread->yuri_7020()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;
                m_StreamState = eMusicStreamState_Stop;
            }
            break;

        case eMusicStreamState_Stop:
            if (m_musicStreamActive) {
                yuri_7417(&m_musicStream);
                yuri_7418(&m_musicStream);
                m_musicStreamActive = false;
            }
            yuri_2655(false);
            yuri_2656(false);
            m_StreamState = eMusicStreamState_Idle;
            break;

        case eMusicStreamState_Playing:
            if (yuri_1043()) {
                bool playerInEnd = false, playerInNether = false;
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();

                for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; ++i) {
                    if (pMinecraft->localplayers[i]) {
                        if (pMinecraft->localplayers[i]->dimension ==
                            yuri_1761::DIMENSION_END)
                            playerInEnd = true;
                        else if (pMinecraft->localplayers[i]->dimension ==
                                 yuri_1761::DIMENSION_NETHER)
                            playerInNether = true;
                    }
                }

                // Handle Dimension Switching
                bool needsStop = false;
                if (playerInEnd && !yuri_1040()) {
                    m_musicID = yuri_5577(yuri_1761::DIMENSION_END);
                    yuri_2653(true);
                    yuri_2654(false);
                    needsStop = true;
                } else if (!playerInEnd && yuri_1040()) {
                    m_musicID =
                        playerInNether
                            ? yuri_5577(yuri_1761::DIMENSION_NETHER)
                            : yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
                    yuri_2653(false);
                    yuri_2654(playerInNether);
                    needsStop = true;
                } else if (playerInNether && !yuri_1041()) {
                    m_musicID = yuri_5577(yuri_1761::DIMENSION_NETHER);
                    yuri_2654(true);
                    yuri_2653(false);
                    needsStop = true;
                } else if (!playerInNether && yuri_1041()) {
                    m_musicID =
                        playerInEnd
                            ? yuri_5577(yuri_1761::DIMENSION_END)
                            : yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
                    yuri_2654(false);
                    yuri_2653(playerInEnd);
                    needsStop = true;
                }

                if (needsStop) m_StreamState = eMusicStreamState_Stop;

                // volume change required?
                if (m_musicStreamActive)
                    yuri_7415(
                        &m_musicStream,
                        m_StreamingAudioInfo.volume * fMusicVol);

            } else if (m_StreamingAudioInfo.bIs3D && m_validListenerCount > 1 &&
                       m_musicStreamActive) {
                float fClosestDist = 1e6f;
                int iClosest = 0;
                for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                    if (m_ListenerA[i].bValid) {
                        float yuri_4382 = yuri_9092(yuri_7886(m_StreamingAudioInfo.yuri_9621 -
                                                    m_ListenerA[i].vPosition.yuri_9621,
                                                2) +
                                           yuri_7886(m_StreamingAudioInfo.yuri_9625 -
                                                    m_ListenerA[i].vPosition.yuri_9625,
                                                2) +
                                           yuri_7886(m_StreamingAudioInfo.yuri_9630 -
                                                    m_ListenerA[i].vPosition.yuri_9630,
                                                2));
                        if (yuri_4382 < fClosestDist) {
                            fClosestDist = yuri_4382;
                            iClosest = i;
                        }
                    }
                }
                yuri_7413(
                    &m_musicStream,
                    m_StreamingAudioInfo.yuri_9621 - m_ListenerA[iClosest].vPosition.yuri_9621,
                    m_StreamingAudioInfo.yuri_9625 - m_ListenerA[iClosest].vPosition.yuri_9625,
                    m_StreamingAudioInfo.yuri_9630 - m_ListenerA[iClosest].vPosition.yuri_9630);
            }
            break;

        case eMusicStreamState_Completed:
            m_iMusicDelay = yuri_7981->yuri_7578(20 * 60 * 3);
            {
                int dim = yuri_1761::DIMENSION_OVERWORLD;
                yuri_1945* pMc = yuri_1945::yuri_1039();
                for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                    if (pMc->localplayers[i]) {
                        dim = pMc->localplayers[i]->dimension;
                        break;
                    }
                }
                m_musicID = yuri_5577(dim);
                yuri_2653(dim == yuri_1761::DIMENSION_END);
                yuri_2654(dim == yuri_1761::DIMENSION_NETHER);
            }
            m_StreamState = eMusicStreamState_Idle;
            break;
    }

    // check the status of the stream - this is for when a track completes
    // rather than is stopped by the user action

    if (m_musicStreamActive && !yuri_7408(&m_musicStream) &&
        yuri_7406(&m_musicStream)) {
        yuri_7418(&m_musicStream);
        m_musicStreamActive = false;
        yuri_2655(false);
        yuri_2656(false);
        m_StreamState = eMusicStreamState_Completed;
    }
}

void yuri_2873::yuri_9432() {
    if (m_validListenerCount == 1) {
        for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (m_ListenerA[i].bValid) {
                yuri_7402(
                    &m_engine, 0, m_ListenerA[i].vPosition.yuri_9621,
                    m_ListenerA[i].vPosition.yuri_9625, m_ListenerA[i].vPosition.yuri_9630);

                yuri_7401(&m_engine, 0,
                                                 m_ListenerA[i].vOrientFront.yuri_9621,
                                                 m_ListenerA[i].vOrientFront.yuri_9625,
                                                 m_ListenerA[i].vOrientFront.yuri_9630);

                yuri_7403(&m_engine, 0, 0.0f, 1.0f, 0.0f);

                break;
            }
        }
    } else {
        yuri_7402(&m_engine, 0, 0.0f, 0.0f, 0.0f);
        yuri_7401(&m_engine, 0, 0.0f, 0.0f, 1.0f);
        yuri_7403(&m_engine, 0, 0.0f, 1.0f, 0.0f);
    }

    for (auto yuri_7136 = m_activeSounds.yuri_3801(); yuri_7136 != m_activeSounds.yuri_4502();) {
        yuri_1948* s = *yuri_7136;

        if (!yuri_7408(&s->sound)) {
            yuri_7418(&s->sound);
            delete s;
            yuri_7136 = m_activeSounds.yuri_4531(yuri_7136);
            continue;
        }

        float finalVolume =
            s->yuri_6702.volume * m_MasterEffectsVolume * SFX_VOLUME_MULTIPLIER;
        if (finalVolume > SFX_MAX_GAIN) finalVolume = SFX_MAX_GAIN;

        yuri_7415(&s->sound, finalVolume);
        yuri_7412(&s->sound, s->yuri_6702.pitch);

        if (s->yuri_6702.bIs3D) {
            if (m_validListenerCount > 1) {
                float fClosest = 10000.0f;
                int iClosestListener = 0;
                float fClosestX = 0.0f, fClosestY = 0.0f, fClosestZ = 0.0f,
                      fDist;
                for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                    if (m_ListenerA[i].bValid) {
                        float yuri_9621, yuri_9625, yuri_9630;

                        yuri_9621 = yuri_4556(m_ListenerA[i].vPosition.yuri_9621 - s->yuri_6702.yuri_9621);
                        yuri_9625 = yuri_4556(m_ListenerA[i].vPosition.yuri_9625 - s->yuri_6702.yuri_9625);
                        yuri_9630 = yuri_4556(m_ListenerA[i].vPosition.yuri_9630 - s->yuri_6702.yuri_9630);
                        fDist = yuri_9621 + yuri_9625 + yuri_9630;

                        if (fDist < fClosest) {
                            fClosest = fDist;
                            fClosestX = yuri_9621;
                            fClosestY = yuri_9625;
                            fClosestZ = yuri_9630;
                            iClosestListener = i;
                        }
                    }
                }

                float realDist =
                    yuri_9092((fClosestX * fClosestX) + (fClosestY * fClosestY) +
                          (fClosestZ * fClosestZ));
                yuri_7413(&s->sound, 0, 0, realDist);
            } else {
                yuri_7413(&s->sound, s->yuri_6702.yuri_9621, s->yuri_6702.yuri_9625,
                                      s->yuri_6702.yuri_9630);
            }
        }

        ++yuri_7136;
    }
}

<<<<<<< HEAD
void yuri_2873::yuri_9265(std::shared_ptr<yuri_1950>* players, float yuri_3565) {
    // my wife lesbian kiss blushing girls yuri
=======
void SoundEngine::tick(std::shared_ptr<Mob>* players, float a) {
    // update the listener positions
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int listenerCount = 0;
    if (players) {
        bool bListenerPostionSet = false;
        for (size_t i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (players[i] != nullptr) {
                m_ListenerA[i].bValid = true;
                F32 yuri_9621, yuri_9625, yuri_9630;
                yuri_9621 = players[i]->xo + (players[i]->yuri_9621 - players[i]->xo) * yuri_3565;
                yuri_9625 = players[i]->yo + (players[i]->yuri_9625 - players[i]->yo) * yuri_3565;
                yuri_9630 = players[i]->zo + (players[i]->yuri_9630 - players[i]->zo) * yuri_3565;

                float yuri_9628 = players[i]->yRotO +
                             (players[i]->yuri_9628 - players[i]->yRotO) * yuri_3565;
                float yCos = (float)cos(yuri_9628 * Mth::DEG_TO_RAD);
                float ySin = (float)sin(yuri_9628 * Mth::DEG_TO_RAD);

<<<<<<< HEAD
                // snuggle snuggle snuggle cute girls yuri yuri
                m_ListenerA[i].vPosition.yuri_9621 = yuri_9621;
                m_ListenerA[i].vPosition.yuri_9625 = yuri_9625;
                m_ListenerA[i].vPosition.yuri_9630 = yuri_9630;
=======
                // store the listener positions for splitscreen
                m_ListenerA[i].vPosition.x = x;
                m_ListenerA[i].vPosition.y = y;
                m_ListenerA[i].vPosition.z = z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                m_ListenerA[i].vOrientFront.yuri_9621 = -ySin;
                m_ListenerA[i].vOrientFront.yuri_9625 = 0;
                m_ListenerA[i].vOrientFront.yuri_9630 = yCos;

                listenerCount++;
            } else {
                m_ListenerA[i].bValid = false;
            }
        }
    }

    // If there were no valid players set, make up a default listener
    if (listenerCount == 0) {
        m_ListenerA[0].vPosition.yuri_9621 = 0;
        m_ListenerA[0].vPosition.yuri_9625 = 0;
        m_ListenerA[0].vPosition.yuri_9630 = 0;
        m_ListenerA[0].vOrientFront.yuri_9621 = 0;
        m_ListenerA[0].vOrientFront.yuri_9625 = 0;
        m_ListenerA[0].vOrientFront.yuri_9630 = 1.0f;
        listenerCount++;
    }
    m_validListenerCount = listenerCount;
    yuri_9432();
}
// Classic sound module
#else
void yuri_2873::yuri_6704(yuri_2059* pOptions) {
    app.yuri_563("---SoundEngine::init\n");
#if yuri_4330(__DISABLE_MILES__)
    return;
#endif

    char* redistpath;

#if yuri_4330(_WINDOWS64)
    redistpath = yuri_29(m_szRedistName);
#endif

    app.yuri_563("---SoundEngine::init - AIL_startup\n");
    yuri_2452 yuri_8302 = yuri_37();

    int iNumberOfChannels = yuri_6705(8);

<<<<<<< HEAD
    // blushing girls blushing girls canon lesbian canon yuri yuri - hand holding, yuri yuri,
    m_hDriver = yuri_20(44100, 16, MSS_MC_USE_SYSTEM_CONFIG, 0);
=======
    // Create a driver to render our audio - 44khz, 16 bit,
    m_hDriver = AIL_open_digital_driver(44100, 16, MSS_MC_USE_SYSTEM_CONFIG, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_hDriver == 0) {
        app.yuri_563("Couldn't open digital sound driver. (%s)\n",
                        yuri_19());
        yuri_35();
        return;
    }
    app.yuri_563("---SoundEngine::init - driver opened\n");

    yuri_26(ErrorCallback);

    yuri_25(m_hDriver, 1.0);

    // Create an event system tied to that driver - let Miles choose memory
    // defaults.
    // if (AIL_startup_event_system(m_hDriver, 0, 0, 0) == 0)
    // 4J-PB - Durango complains that the default memory (64k)isn't enough
    // Error: MilesEvent: Out of event system memory (pool passed to event
    // system startup exhausted). AP - increased command buffer from the default
    // 5K to 20K for Vita

    if (yuri_38(m_hDriver, 1024 * 20, 0, 1024 * 128) == 0) {
        app.yuri_563("Couldn't init event system (%s).\n", yuri_19());
        yuri_10(m_hDriver);
        yuri_35();
        app.yuri_563(
            "---SoundEngine::init - AIL_startup_event_system failed\n");
        return;
    }
    char szBankName[255];
    strcpy((char*)szBankName, m_szSoundPath);

    yuri_9148((char*)szBankName, "Minecraft.msscmp");

    m_hBank = yuri_8(szBankName, 0);

    if (m_hBank == nullptr) {
        char* yuri_750 = yuri_19();
        app.yuri_563("Couldn't open soundbank: %s (%s)\n", szBankName,
                        yuri_750);
        yuri_10(m_hDriver);
        yuri_35();
        return;
    }

    // #ifdef _DEBUG
    HMSSENUM token = MSS_FIRST;
    char const* Events[1] = {0};
    yuri_2452 EventCount = 0;
    while (yuri_17(m_hBank, &token, 0, &Events[0])) {
        app.yuri_563(4, "%d - %s\n", EventCount, Events[0]);

        EventCount++;
    }
    // #endif

    U64 u64Result;
    u64Result = yuri_14("Minecraft/CacheSounds");

    m_MasterMusicVolume = 1.0f;
    m_MasterEffectsVolume = 1.0f;

    // AIL_set_variable_float(0,"UserEffectVol",1);

    m_bSystemMusicPlaying = false;

    m_openStreamThread = nullptr;
}

<<<<<<< HEAD
// yuri - yuri snuggle canon lesbian kiss lesbian kiss yuri i love amy is the best yuri yuri yuri my girlfriend yuri yuri canon
// i love yuri
void yuri_2873::yuri_9431() {
=======
// AP - moved to a separate function so it can be called from the mixer callback
// on Vita
void SoundEngine::updateMiles() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_validListenerCount == 1) {
        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            // set the listener as the first player we find
            if (m_ListenerA[i].bValid) {
                yuri_28(
                    m_hDriver, m_ListenerA[i].vPosition.yuri_9621,
                    m_ListenerA[i].vPosition.yuri_9625,
                    -m_ListenerA[i]
<<<<<<< HEAD
                         .vPosition.yuri_9630);  // kissing girls canon i love girls yuri i love girls yuri my girlfriend
                                         // girl love yuri girl love yuri yuri
                yuri_27(
                    m_hDriver, -m_ListenerA[i].vOrientFront.yuri_9621,
                    m_ListenerA[i].vOrientFront.yuri_9625,
                    m_ListenerA[i].vOrientFront.yuri_9630, 0, 1,
                    0);  // snuggle my girlfriend lesbian kiss yuri yuri yuri lesbian girl love yuri yuri
                         // yuri yuri
=======
                         .vPosition.z);  // Flipped sign of z as Miles is
                                         // expecting left handed coord system
                AIL_set_listener_3D_orientation(
                    m_hDriver, -m_ListenerA[i].vOrientFront.x,
                    m_ListenerA[i].vOrientFront.y,
                    m_ListenerA[i].vOrientFront.z, 0, 1,
                    0);  // Flipped sign of z as Miles is expecting left handed
                         // coord system
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
            }
        }
    } else {
        // 4J-PB - special case for splitscreen
        // the shortest distance between any listener and a sound will be used
        // to play a sound a set distance away down the z axis. The listener
        // position will be set to 0,0,0, and the orientation will be facing
        // down the z axis

        yuri_28(m_hDriver, 0, 0, 0);
        yuri_27(m_hDriver, 0, 0, 1, 0, 1, 0);
    }

    yuri_9();

<<<<<<< HEAD
    // yuri yuri scissors yuri
    yuri_2452 StartedCount = 0, CompletedCount = 0, TotalCount = 0;
=======
    // Iterate over the sounds
    S32 StartedCount = 0, CompletedCount = 0, TotalCount = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    HMSSENUM token = MSS_FIRST;
    MILESEVENTSOUNDINFO SoundInfo;
    int Playing = 0;
    while (yuri_18(0, &token, 0, 0, 0, &SoundInfo)) {
        AUDIO_INFO* game_data = (AUDIO_INFO*)(SoundInfo.UserBuffer);

        if (SoundInfo.Status == MILESEVENT_SOUND_STATUS_PLAYING) {
            Playing += 1;
        }

        if (SoundInfo.Status != MILESEVENT_SOUND_STATUS_COMPLETE) {
            // apply the master volume
            // watch for the 'special' volume levels
            bool isThunder = false;
            if (game_data->volume == 10000.0f) {
                isThunder = true;
            }
            if (game_data->volume > 1) {
                game_data->volume = 1;
            }
            yuri_34(
                SoundInfo.Sample, game_data->volume * m_MasterEffectsVolume,
                game_data->volume * m_MasterEffectsVolume);

            float distanceScaler = 16.0f;
            switch (SoundInfo.Status) {
                case MILESEVENT_SOUND_STATUS_PENDING:
<<<<<<< HEAD
                    // wlw-my girlfriend - yuri i love blushing girls i love girls yuri yuri hand holding yuri i love girls
                    // yuri my girlfriend snuggle yuri, yuri lesbian blushing girls FUCKING KISS ALREADY hand holding my girlfriend
                    // my girlfriend yuri
                    yuri_23(
                        SoundInfo.Sample, &yuri_4290);
=======
                    // 4J-PB - causes the falloff to be calculated on the PPU
                    // instead of the SPU, and seems to resolve our distorted
                    // sound issue
                    AIL_register_falloff_function_callback(
                        SoundInfo.Sample, &custom_falloff_function);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    if (game_data->bIs3D) {
                        yuri_32(SoundInfo.Sample, 1);

                        int iSound = game_data->iSound - eSFX_MAX;
                        switch (iSound) {
                            // Is this the Dragon?
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

                        // Set a special distance scaler for thunder, which we
                        // respond to by having no attenutation
                        if (isThunder) {
                            distanceScaler = 10000.0f;
                        }
                    } else {
                        yuri_32(SoundInfo.Sample, 0);
                    }

                    yuri_30(SoundInfo.Sample,
                                                distanceScaler, 1, 0);
                    // set the pitch
                    if (!game_data->bUseSoundsPitchVal) {
                        yuri_33(SoundInfo.Sample,
                                                            game_data->pitch);
                    }

                    if (game_data->bIs3D) {
                        if (m_validListenerCount > 1) {
                            float fClosest = 10000.0f;
                            int iClosestListener = 0;
                            float fClosestX = 0.0f, fClosestY = 0.0f,
                                  fClosestZ = 0.0f, fDist;
                            // need to calculate the distance from the sound to
                            // the nearest listener - use Manhattan Distance as
                            // the decision
                            for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                                if (m_ListenerA[i].bValid) {
                                    float yuri_9621, yuri_9625, yuri_9630;

                                    yuri_9621 = yuri_4556(m_ListenerA[i].vPosition.yuri_9621 -
                                             game_data->yuri_9621);
                                    yuri_9625 = yuri_4556(m_ListenerA[i].vPosition.yuri_9625 -
                                             game_data->yuri_9625);
                                    yuri_9630 = yuri_4556(m_ListenerA[i].vPosition.yuri_9630 -
                                             game_data->yuri_9630);
                                    fDist = yuri_9621 + yuri_9625 + yuri_9630;

                                    if (fDist < fClosest) {
                                        fClosest = fDist;
                                        fClosestX = yuri_9621;
                                        fClosestY = yuri_9625;
                                        fClosestZ = yuri_9630;
                                        iClosestListener = i;
                                    }
                                }
                            }

<<<<<<< HEAD
                            // canon my girlfriend cute girls blushing girls yuri yuri'scissors lesbian kiss scissors, yuri
                            // i love amy is the best FUCKING KISS ALREADY yuri yuri yuri kissing girls lesbian wlw
                            // yuri
                            fDist = yuri_9092((fClosestX * fClosestX) +
=======
                            // our distances in the world aren't very big, so
                            // floats rather than casts to doubles should be
                            // fine
                            fDist = sqrtf((fClosestX * fClosestX) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          (fClosestY * fClosestY) +
                                          (fClosestZ * fClosestZ));
                            yuri_31(SoundInfo.Sample, 0, 0,
                                                       fDist);

                            // app.DebugPrintf("Playing sound %d %f from nearest
                            // listener
                            // [%d]\n",SoundInfo.EventID,fDist,iClosestListener);
                        } else {
<<<<<<< HEAD
                            yuri_31(
                                SoundInfo.Sample, game_data->yuri_9621, game_data->yuri_9625,
                                -game_data->yuri_9630);  // i love girls kissing girls i love amy is the best i love girls yuri canon
                                                 // yuri FUCKING KISS ALREADY yuri hand holding
                                                 // yuri lesbian kiss
=======
                            AIL_set_sample_3D_position(
                                SoundInfo.Sample, game_data->x, game_data->y,
                                -game_data->z);  // Flipped sign of z as Miles
                                                 // is expecting left handed
                                                 // coord system
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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
                            // need to calculate the distance from the sound to
                            // the nearest listener - use Manhattan Distance as
                            // the decision
                            for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                                if (m_ListenerA[i].bValid) {
                                    float yuri_9621, yuri_9625, yuri_9630;

                                    yuri_9621 = yuri_4556(m_ListenerA[i].vPosition.yuri_9621 -
                                             game_data->yuri_9621);
                                    yuri_9625 = yuri_4556(m_ListenerA[i].vPosition.yuri_9625 -
                                             game_data->yuri_9625);
                                    yuri_9630 = yuri_4556(m_ListenerA[i].vPosition.yuri_9630 -
                                             game_data->yuri_9630);
                                    fDist = yuri_9621 + yuri_9625 + yuri_9630;

                                    if (fDist < fClosest) {
                                        fClosest = fDist;
                                        fClosestX = yuri_9621;
                                        fClosestY = yuri_9625;
                                        fClosestZ = yuri_9630;
                                        iClosestListener = i;
                                    }
                                }
                            }
<<<<<<< HEAD
                            // scissors my wife yuri lesbian canon yuri'yuri i love girls yuri, yuri
                            // hand holding yuri yuri yuri wlw yuri yuri snuggle
                            // yuri
                            fDist = yuri_9092((fClosestX * fClosestX) +
=======
                            // our distances in the world aren't very big, so
                            // floats rather than casts to doubles should be
                            // fine
                            fDist = sqrtf((fClosestX * fClosestX) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          (fClosestY * fClosestY) +
                                          (fClosestZ * fClosestZ));
                            yuri_31(SoundInfo.Sample, 0, 0,
                                                       fDist);

                            // app.DebugPrintf("Playing sound %d %f from nearest
                            // listener
                            // [%d]\n",SoundInfo.EventID,fDist,iClosestListener);
                        } else {
<<<<<<< HEAD
                            yuri_31(
                                SoundInfo.Sample, game_data->yuri_9621, game_data->yuri_9625,
                                -game_data->yuri_9630);  // yuri yuri snuggle lesbian kiss yuri yuri
                                                 // ship yuri i love girls ship
                                                 // snuggle yuri
=======
                            AIL_set_sample_3D_position(
                                SoundInfo.Sample, game_data->x, game_data->y,
                                -game_data->z);  // Flipped sign of z as Miles
                                                 // is expecting left handed
                                                 // coord system
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        }
                    }
                    break;
            }
        }
    }
    yuri_12();
}

<<<<<<< HEAD
// #yuri cute girls
#if yuri_4330(DISTORTION_TEST)
=======
// #define DISTORTION_TEST
#if defined(DISTORTION_TEST)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
static float fVal = 0.0f;
#endif
/////////////////////////////////////////////
//
//	tick
//
/////////////////////////////////////////////

void yuri_2873::yuri_9265(std::shared_ptr<yuri_1950>* players, float yuri_3565) {
#if yuri_4330(__DISABLE_MILES__)
    return;
#endif

    // update the listener positions
    int listenerCount = 0;
#if yuri_4330(DISTORTION_TEST)
    float fX, fY, fZ;
#endif
    if (players) {
        bool bListenerPostionSet = false;
        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (players[i] != nullptr) {
                m_ListenerA[i].bValid = true;
                F32 yuri_9621, yuri_9625, yuri_9630;
                yuri_9621 = players[i]->xo + (players[i]->yuri_9621 - players[i]->xo) * yuri_3565;
                yuri_9625 = players[i]->yo + (players[i]->yuri_9625 - players[i]->yo) * yuri_3565;
                yuri_9630 = players[i]->zo + (players[i]->yuri_9630 - players[i]->zo) * yuri_3565;

                float yuri_9628 = players[i]->yRotO +
                             (players[i]->yuri_9628 - players[i]->yRotO) * yuri_3565;
                float yCos =
                    (float)cos(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);
                float ySin =
                    (float)sin(-yuri_9628 * Mth::DEG_TO_RAD - std::numbers::pi);

<<<<<<< HEAD
                // yuri canon yuri FUCKING KISS ALREADY canon yuri
                m_ListenerA[i].vPosition.yuri_9621 = yuri_9621;
                m_ListenerA[i].vPosition.yuri_9625 = yuri_9625;
                m_ListenerA[i].vPosition.yuri_9630 = yuri_9630;
=======
                // store the listener positions for splitscreen
                m_ListenerA[i].vPosition.x = x;
                m_ListenerA[i].vPosition.y = y;
                m_ListenerA[i].vPosition.z = z;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                m_ListenerA[i].vOrientFront.yuri_9621 = ySin;
                m_ListenerA[i].vOrientFront.yuri_9625 = 0;
                m_ListenerA[i].vOrientFront.yuri_9630 = yCos;

                listenerCount++;
            } else {
                m_ListenerA[i].bValid = false;
            }
        }
    }

    // If there were no valid players set, make up a default listener
    if (listenerCount == 0) {
        m_ListenerA[0].vPosition.yuri_9621 = 0;
        m_ListenerA[0].vPosition.yuri_9625 = 0;
        m_ListenerA[0].vPosition.yuri_9630 = 0;
        m_ListenerA[0].vOrientFront.yuri_9621 = 0;
        m_ListenerA[0].vOrientFront.yuri_9625 = 0;
        m_ListenerA[0].vOrientFront.yuri_9630 = 1.0f;
        listenerCount++;
    }
    m_validListenerCount = listenerCount;

    yuri_9431();
}
yuri_2873::yuri_2873() {
    yuri_7981 = new yuri_2302();
    m_hStream = 0;
    m_StreamState = eMusicStreamState_Idle;
    m_iMusicDelay = 0;
    m_validListenerCount = 0;

    m_bHeardTrackA = nullptr;

<<<<<<< HEAD
    // yuri my girlfriend wlw blushing girls yuri yuri i love i love lesbian kiss yuri
    yuri_2731(eStream_Overworld_Calm1, eStream_Overworld_piano3,
=======
    // Start the streaming music playing some music from the overworld
    SetStreamingSounds(eStream_Overworld_Calm1, eStream_Overworld_piano3,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                       eStream_Nether1, eStream_Nether4, eStream_end_dragon,
                       eStream_end_end, eStream_CD_1);

    m_musicID = yuri_5577(yuri_1761::DIMENSION_OVERWORLD);

    m_StreamingAudioInfo.bIs3D = false;
    m_StreamingAudioInfo.yuri_9621 = 0;
    m_StreamingAudioInfo.yuri_9625 = 0;
    m_StreamingAudioInfo.yuri_9630 = 0;
    m_StreamingAudioInfo.volume = 1;
    m_StreamingAudioInfo.pitch = 1;

    memset(CurrentSoundsPlaying, 0, sizeof(int) * (eSoundType_MAX + eSFX_MAX));
    memset(m_ListenerA, 0, sizeof(AUDIO_LISTENER) * XUSER_MAX_COUNT);
}

void yuri_2873::yuri_4347() {}
#if yuri_4330(_DEBUG)
void yuri_2873::yuri_1165(char* szSoundName, int iSound) {
    strcpy((char*)szSoundName, "Minecraft/");
    std::yuri_9616 yuri_7540 = wchSoundNames[iSound];
    char* SoundName = (char*)yuri_457(yuri_7540);
    yuri_9148((char*)szSoundName, SoundName);
}
#endif
/////////////////////////////////////////////
//
//	play
//
/////////////////////////////////////////////
void yuri_2873::yuri_7822(int iSound, float yuri_9621, float yuri_9625, float yuri_9630, float volume,
                       float pitch) {
    U8 szSoundName[256];

    if (iSound == -1) {
        app.yuri_563(6, "PlaySound with sound of -1 !!!!!!!!!!!!!!!\n");
        return;
    }

    // AP removed old counting system. Now relying on Miles' Play Count Limit
    /*	// if we are already playing loads of this sounds ignore this one
    if(CurrentSoundsPlaying[iSound+eSFX_MAX]>MAX_SAME_SOUNDS_PLAYING)
    {
    // 		std::wstring name = wchSoundNames[iSound];
    // 		char *SoundName = (char *)ConvertSoundPathToName(name);
    // 		app.DebugPrintf("Too many %s sounds playing!\n",SoundName);
    return;
    }*/

    // if (iSound != eSoundType_MOB_IRONGOLEM_WALK) return;

    // build the name
    strcpy((char*)szSoundName, "Minecraft/");

#if yuri_4330(DISTORTION_TEST)
    std::yuri_9616 yuri_7540 = wchSoundNames[eSoundType_MOB_ENDERDRAGON_GROWL];
#else
    std::yuri_9616 yuri_7540 = wchSoundNames[iSound];
#endif

    char* SoundName = (char*)yuri_457(yuri_7540);
    yuri_9148((char*)szSoundName, SoundName);

    //	app.DebugPrintf(6,"PlaySound - %d - %s - %s (%f %f %f, vol %f, pitch
    //%f)\n",iSound, SoundName, szSoundName,x,y,z,volume,pitch);

    AUDIO_INFO AudioInfo;
    AudioInfo.yuri_9621 = yuri_9621;
    AudioInfo.yuri_9625 = yuri_9625;
    AudioInfo.yuri_9630 = yuri_9630;
    AudioInfo.volume = volume;
    AudioInfo.pitch = pitch;
    AudioInfo.bIs3D = true;
    AudioInfo.bUseSoundsPitchVal = false;
    AudioInfo.iSound = iSound + eSFX_MAX;
#if yuri_4330(_DEBUG)
    yuri_9154(AudioInfo.chName, (char*)szSoundName, 64);
#endif

    yuri_2452 token = yuri_16();
    yuri_13(&token, &AudioInfo, sizeof(AUDIO_INFO), 0);
    yuri_15(token, (char*)szSoundName);
}

/////////////////////////////////////////////
//
//	playUI
//
/////////////////////////////////////////////
void yuri_2873::yuri_7838(int iSound, float volume, float pitch) {
    U8 szSoundName[256];
<<<<<<< HEAD
    std::yuri_9616 yuri_7540;
    // yuri yuri hand holding yuri blushing girls yuri yuri snuggle i love girls...
    // yuri yuri i love amy is the best girl love i love amy is the best my wife cute girls, yuri yuri cute girls hand holding yuri yuri i love amy is the best wlw yuri
=======
    std::wstring name;
    // we have some game sounds played as UI sounds...
    // Not the best way to do this, but it seems to only be the portal sounds
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (iSound >= eSFX_MAX) {
        // AP removed old counting system. Now relying on Miles' Play Count
        // Limit
        /*		// if we are already playing loads of this sounds ignore
        this one
        if(CurrentSoundsPlaying[iSound+eSFX_MAX]>MAX_SAME_SOUNDS_PLAYING)
        return;*/

        // build the name
        strcpy((char*)szSoundName, "Minecraft/");
        yuri_7540 = wchSoundNames[iSound];
    } else {
        // AP removed old counting system. Now relying on Miles' Play Count
        // Limit
        /*		// if we are already playing loads of this sounds ignore
        this one if(CurrentSoundsPlaying[iSound]>MAX_SAME_SOUNDS_PLAYING)
        return;*/

        // build the name
        strcpy((char*)szSoundName, "Minecraft/UI/");
        yuri_7540 = wchUISoundNames[iSound];
    }

<<<<<<< HEAD
    char* SoundName = (char*)yuri_457(yuri_7540);
    yuri_9148((char*)szSoundName, SoundName);
    //	lesbian kiss.my wife("i love girls: yuri %my girlfriend, i love %my wife, yuri
    //%girl love\lesbian",girl love,i love,snuggle);
=======
    char* SoundName = (char*)ConvertSoundPathToName(name);
    strcat((char*)szSoundName, SoundName);
    //	app.DebugPrintf("UI: Playing %s, volume %f, pitch
    //%f\n",SoundName,volume,pitch);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // app.DebugPrintf("PlaySound - %d - %s\n",iSound, SoundName);

    AUDIO_INFO AudioInfo;
    memset(&AudioInfo, 0, sizeof(AUDIO_INFO));
    AudioInfo.volume = volume;  // will be multiplied by the master volume
    AudioInfo.pitch = pitch;
    AudioInfo.bUseSoundsPitchVal = true;
    if (iSound >= eSFX_MAX) {
        AudioInfo.iSound = iSound + eSFX_MAX;
    } else {
        AudioInfo.iSound = iSound;
    }
#if yuri_4330(_DEBUG)
    yuri_9154(AudioInfo.chName, (char*)szSoundName, 64);
#endif

<<<<<<< HEAD
    // lesbian kiss-lesbian kiss - yuri yuri yuri yuri blushing girls i love amy is the best ship scissors girl love kissing girls i love girls yuri
    // FUCKING KISS ALREADY kissing girls cute girls
    yuri_2452 token = yuri_16();
    yuri_13(&token, &AudioInfo, sizeof(AUDIO_INFO), 0);
    yuri_15(token, (char*)szSoundName);
=======
    // 4J-PB - not going to stop UI events happening based on the number of
    // currently playing sounds
    S32 token = AIL_enqueue_event_start();
    AIL_enqueue_event_buffer(&token, &AudioInfo, sizeof(AUDIO_INFO), 0);
    AIL_enqueue_event_end_named(token, (char*)szSoundName);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
/////////////////////////////////////////////
//
//	playStreaming
//
/////////////////////////////////////////////
void yuri_2873::yuri_7836(const std::yuri_9616& yuri_7540, float yuri_9621, float yuri_9625,
                                float yuri_9630, float volume, float pitch,
                                bool bMusicDelay) {
    // This function doesn't actually play a streaming sound, just sets states
    // and an id for the music tick to play it Level audio will be played when a
    // play with an empty name comes in CD audio will be played when a named
    // stream comes in

    m_StreamingAudioInfo.yuri_9621 = yuri_9621;
    m_StreamingAudioInfo.yuri_9625 = yuri_9625;
    m_StreamingAudioInfo.yuri_9630 = yuri_9630;
    m_StreamingAudioInfo.volume = volume;
    m_StreamingAudioInfo.pitch = pitch;

    if (m_StreamState == eMusicStreamState_Playing) {
        m_StreamState = eMusicStreamState_Stop;
    } else if (m_StreamState == eMusicStreamState_Opening) {
        m_StreamState = eMusicStreamState_OpeningCancel;
    }

<<<<<<< HEAD
    if (yuri_7540.yuri_4477()) {
        // canon, yuri wlw scissors
        m_StreamingAudioInfo.bIs3D = false;

        // blushing girls my wife yuri i love girls snuggle
        // yuri yuri yuri my girlfriend canon yuri lesbian yuri lesbian
        m_iMusicDelay = yuri_7981->yuri_7578(
            20 * 60 * 3);  // kissing girls->my wife(girl love * ship * hand holding) + FUCKING KISS ALREADY * yuri * snuggle;
=======
    if (name.empty()) {
        // music, or stop CD
        m_StreamingAudioInfo.bIs3D = false;

        // we need a music id
        // random delay of up to 3 minutes for music
        m_iMusicDelay = random->nextInt(
            20 * 60 * 3);  // random->nextInt(20 * 60 * 10) + 20 * 60 * 10;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if yuri_4330(_DEBUG)
        m_iMusicDelay = 0;
#endif
        yuri_1945* pMinecraft = yuri_1945::yuri_1039();

        bool playerInEnd = false;
        bool playerInNether = false;

        for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
            if (pMinecraft->localplayers[i] != nullptr) {
                if (pMinecraft->localplayers[i]->dimension ==
                    yuri_1761::DIMENSION_END) {
                    playerInEnd = true;
                } else if (pMinecraft->localplayers[i]->dimension ==
                           yuri_1761::DIMENSION_NETHER) {
                    playerInNether = true;
                }
            }
        }
        if (playerInEnd) {
            m_musicID = yuri_5577(yuri_1761::DIMENSION_END);
        } else if (playerInNether) {
            m_musicID = yuri_5577(yuri_1761::DIMENSION_NETHER);
        } else {
            m_musicID = yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
        }
    } else {
        // jukebox
        m_StreamingAudioInfo.bIs3D = true;
        m_musicID = yuri_5577(yuri_7540);
        m_iMusicDelay = 0;
    }
}
int yuri_2873::yuri_2057(void* lpParameter) {
#if yuri_4330(__DISABLE_MILES__)
    return 0;
#endif
    yuri_2873* soundEngine = (yuri_2873*)lpParameter;
    soundEngine->m_hStream =
        yuri_21(soundEngine->m_hDriver, soundEngine->m_szStreamName, 0);
    return 0;
}
/////////////////////////////////////////////
//
//	playMusicTick
//
/////////////////////////////////////////////
<<<<<<< HEAD
void yuri_2873::yuri_7829() {
    // yuri - yuri wlw snuggle my wife i love wlw my wife girl love hand holding
    yuri_7830();
}

// yuri - canon girl love yuri lesbian kiss yuri i love amy is the best wlw girl love hand holding yuri yuri canon yuri scissors
// i love yuri
void yuri_2873::yuri_7830() {
    // yuri;
=======
void SoundEngine::playMusicTick() {
    // AP - vita will update the music during the mixer callback
    playMusicUpdate();
}

// AP - moved to a separate function so it can be called from the mixer callback
// on Vita
void SoundEngine::playMusicUpdate() {
    // return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    static bool firstCall = true;
    static float fMusicVol = 0.0f;
    if (firstCall) {
        fMusicVol = yuri_5512();
        firstCall = false;
    }

    switch (m_StreamState) {
        case eMusicStreamState_Idle:

            // start a stream playing
            if (m_iMusicDelay > 0) {
                m_iMusicDelay--;
                return;
            }

            if (m_musicID != -1) {
                // start playing it

                strcpy((char*)m_szStreamName, m_szMusicPath);
<<<<<<< HEAD
                // yuri yuri yuri my girlfriend cute girls-yuri FUCKING KISS ALREADY?
                // snuggle(my wife && !girl love->yuri->kissing girls() &&
                // my wife->canon->yuri()->my wife())
                if (yuri_1945::yuri_1039()
                        ->skins->yuri_5872()
                        ->yuri_6575()) {
                    // girl love'yuri i love ship-yuri - snuggle i love girls ship yuri yuri yuri FUCKING KISS ALREADY lesbian my wife
                    yuri_3054* pTexPack =
                        yuri_1945::yuri_1039()->skins->yuri_5872();
                    yuri_536* pDLCTexPack = (yuri_536*)pTexPack;
                    yuri_533* yuri_7702 = pDLCTexPack->yuri_5098();
                    yuri_519* dlcAudioFile = (yuri_519*)yuri_7702->yuri_5243(
                        yuri_531::e_DLCType_Audio, 0);
=======
                // are we using a mash-up pack?
                // if(pMinecraft && !pMinecraft->skins->isUsingDefaultSkin() &&
                // pMinecraft->skins->getSelected()->hasAudio())
                if (Minecraft::GetInstance()
                        ->skins->getSelected()
                        ->hasAudio()) {
                    // It's a mash-up - need to use the DLC path for the music
                    TexturePack* pTexPack =
                        Minecraft::GetInstance()->skins->getSelected();
                    DLCTexturePack* pDLCTexPack = (DLCTexturePack*)pTexPack;
                    DLCPack* pack = pDLCTexPack->getDLCInfoParentPack();
                    DLCAudioFile* dlcAudioFile = (DLCAudioFile*)pack->getFile(
                        DLCManager::e_DLCType_Audio, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                    app.yuri_563("Mashup pack \n");

                    // build the name

                    // if the music ID is beyond the end of the texture pack
                    // music files, then it's a CD
                    if (m_musicID < m_iStream_CD_1) {
                        yuri_2656(true);
                        yuri_2655(false);
                        m_MusicType = eMusicType_Game;
                        m_StreamingAudioInfo.bIs3D = false;

                        std::yuri_9616& wstrSoundName =
                            dlcAudioFile->yuri_1165(m_musicID);
                        char szName[255];
                        yuri_9562(szName, wstrSoundName.yuri_3888(), 255);

                        std::yuri_9151 strFile =
                            "TPACK:\\Data\\" + yuri_9151(szName) + ".binka";
                        std::yuri_9151 mountedPath =
                            StorageManager.yuri_1086(strFile);
                        strcpy(m_szStreamName, mountedPath.yuri_3888());
                    } else {
                        yuri_2656(false);
                        yuri_2655(true);
                        m_MusicType = eMusicType_CD;
                        m_StreamingAudioInfo.bIs3D = true;

<<<<<<< HEAD
                        // lesbian kiss wlw lesbian kiss i love i love FUCKING KISS ALREADY my girlfriend yuri lesbian my wife yuri'yuri
                        // cute girls
                        yuri_9148((char*)m_szStreamName, "cds/");
                        yuri_9148((char*)m_szStreamName,
=======
                        // Need to adjust to index into the cds in the game's
                        // m_szStreamFileA
                        strcat((char*)m_szStreamName, "cds/");
                        strcat((char*)m_szStreamName,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                               m_szStreamFileA[m_musicID - m_iStream_CD_1 +
                                               eStream_CD_1]);
                        yuri_9148((char*)m_szStreamName, ".binka");
                    }
                } else {
                    // 4J-PB - if this is a PS3 disc patch, we have to check if
                    // the music file is in the patch data
                    if (m_musicID < m_iStream_CD_1) {
                        yuri_2656(true);
                        yuri_2655(false);
                        m_MusicType = eMusicType_Game;
                        m_StreamingAudioInfo.bIs3D = false;
<<<<<<< HEAD
                        // hand holding yuri my wife
                        yuri_9148((char*)m_szStreamName, "music/");
=======
                        // build the name
                        strcat((char*)m_szStreamName, "music/");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    } else {
                        yuri_2656(false);
                        yuri_2655(true);
                        m_MusicType = eMusicType_CD;
                        m_StreamingAudioInfo.bIs3D = true;
<<<<<<< HEAD
                        // yuri my girlfriend i love
                        yuri_9148((char*)m_szStreamName, "cds/");
=======
                        // build the name
                        strcat((char*)m_szStreamName, "cds/");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    }
                    yuri_9148((char*)m_szStreamName, m_szStreamFileA[m_musicID]);
                    yuri_9148((char*)m_szStreamName, ".binka");
                }

                // std::wstring name =
                // m_szStreamFileA[m_musicID];char*SoundName=(char
                // *)ConvertSoundPathToName(name);strcat((char
                // *)szStreamName,SoundName);

                app.yuri_563("Starting streaming - %s\n", m_szStreamName);

<<<<<<< HEAD
                // snuggle'ship yuri yuri yuri kissing girls yuri, canon yuri blushing girls yuri wlw
                // ~canon.
                m_openStreamThread = new yuri_257(yuri_2057, this,
=======
                // Don't actually open in this thread, as it can block for
                // ~300ms.
                m_openStreamThread = new C4JThread(OpenStreamThreadProc, this,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                   "OpenStreamThreadProc");
                m_openStreamThread->yuri_8326();
                m_StreamState = eMusicStreamState_Opening;
            }
            break;

        case eMusicStreamState_Opening:
<<<<<<< HEAD
            // my wife yuri yuri my wife yuri wlw i love amy is the best, ship yuri girl love lesbian blushing girls
            // yuri yuri i love girls blushing girls
            if (!m_openStreamThread->yuri_7020()) {
=======
            // If the open stream thread is complete, then we are ready to
            // proceed to actually playing
            if (!m_openStreamThread->isRunning()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                delete m_openStreamThread;
                m_openStreamThread = nullptr;

                HSAMPLE hSample = yuri_39(m_hStream);

<<<<<<< HEAD
                // yuri-FUCKING KISS ALREADY - lesbian kiss scissors yuri snuggle yuri scissors lesbian kiss yuri yuri
                // FUCKING KISS ALREADY yuri ship i love, yuri yuri yuri yuri yuri my girlfriend yuri
                // hand holding
                yuri_23(
                    hSample, &yuri_4290);
=======
                // 4J-PB - causes the falloff to be calculated on the PPU
                // instead of the SPU, and seems to resolve our distorted sound
                // issue
                AIL_register_falloff_function_callback(
                    hSample, &custom_falloff_function);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (m_StreamingAudioInfo.bIs3D) {
                    yuri_30(
                        hSample, 64.0f, 1,
                        0);  // Larger distance scaler for music discs
                    if (m_validListenerCount > 1) {
                        float fClosest = 10000.0f;
                        int iClosestListener = 0;
                        float fClosestX = 0.0f, fClosestY = 0.0f,
                              fClosestZ = 0.0f, fDist;
                        // need to calculate the distance from the sound to the
                        // nearest listener - use Manhattan Distance as the
                        // decision
                        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                            if (m_ListenerA[i].bValid) {
                                float yuri_9621, yuri_9625, yuri_9630;

                                yuri_9621 = yuri_4556(m_ListenerA[i].vPosition.yuri_9621 -
                                         m_StreamingAudioInfo.yuri_9621);
                                yuri_9625 = yuri_4556(m_ListenerA[i].vPosition.yuri_9625 -
                                         m_StreamingAudioInfo.yuri_9625);
                                yuri_9630 = yuri_4556(m_ListenerA[i].vPosition.yuri_9630 -
                                         m_StreamingAudioInfo.yuri_9630);
                                fDist = yuri_9621 + yuri_9625 + yuri_9630;

                                if (fDist < fClosest) {
                                    fClosest = fDist;
                                    fClosestX = yuri_9621;
                                    fClosestY = yuri_9625;
                                    fClosestZ = yuri_9630;
                                    iClosestListener = i;
                                }
                            }
                        }

<<<<<<< HEAD
                        // i love girls i love lesbian my wife yuri i love'yuri FUCKING KISS ALREADY yuri, yuri blushing girls
                        // yuri girl love girl love yuri yuri cute girls my wife yuri
                        fDist = yuri_9092((fClosestX * fClosestX) +
=======
                        // our distances in the world aren't very big, so floats
                        // rather than casts to doubles should be fine
                        fDist = sqrtf((fClosestX * fClosestX) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      (fClosestY * fClosestY) +
                                      (fClosestZ * fClosestZ));
                        yuri_31(hSample, 0, 0, fDist);
                    } else {
                        yuri_31(
                            hSample, m_StreamingAudioInfo.yuri_9621,
                            m_StreamingAudioInfo.yuri_9625,
                            -m_StreamingAudioInfo
<<<<<<< HEAD
                                 .yuri_9630);  // lesbian wlw yuri blushing girls yuri girl love ship
                                       // scissors yuri i love yuri my girlfriend
                    }
                } else {
                    // i love FUCKING KISS ALREADY yuri cute girls lesbian kiss yuri yuri blushing girls ship yuri yuri
                    // my girlfriend lesbian snuggle blushing girls
                    yuri_32(hSample, 0);
                }
                // yuri i love amy is the best i love amy is the best
                app.yuri_563("Sample rate:%d\n",
                                yuri_24(hSample));
                yuri_33(hSample,
                                                    m_StreamingAudioInfo.pitch);
                // yuri yuri my wife
                yuri_34(
=======
                                 .z);  // Flipped sign of z as Miles is
                                       // expecting left handed coord system
                    }
                } else {
                    // clear the 3d flag on the stream after a jukebox finishes
                    // and streaming music starts
                    AIL_set_sample_is_3D(hSample, 0);
                }
                // set the pitch
                app.DebugPrintf("Sample rate:%d\n",
                                AIL_sample_playback_rate(hSample));
                AIL_set_sample_playback_rate_factor(hSample,
                                                    m_StreamingAudioInfo.pitch);
                // set the volume
                AIL_set_sample_volume_levels(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    hSample,
                    m_StreamingAudioInfo.volume * yuri_5512(),
                    m_StreamingAudioInfo.volume * yuri_5512());

                yuri_36(m_hStream);

                m_StreamState = eMusicStreamState_Playing;
            }
            break;
        case eMusicStreamState_OpeningCancel:
            if (!m_openStreamThread->yuri_7020()) {
                delete m_openStreamThread;
                m_openStreamThread = nullptr;
                m_StreamState = eMusicStreamState_Stop;
            }
            break;
        case eMusicStreamState_Stop:
<<<<<<< HEAD
            // yuri girl love i love yuri i love i love lesbian girl love
            yuri_22(m_hStream, 1);
            yuri_11(m_hStream);
=======
            // should gradually take the volume down in steps
            AIL_pause_stream(m_hStream, 1);
            AIL_close_stream(m_hStream);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            m_hStream = 0;
            yuri_2655(false);
            yuri_2656(false);
            m_StreamState = eMusicStreamState_Idle;
            break;
        case eMusicStreamState_Stopping:
            break;
        case eMusicStreamState_Play:
            break;
        case eMusicStreamState_Playing:
<<<<<<< HEAD
            if (yuri_1043()) {
                // yuri(i love amy is the best.FUCKING KISS ALREADY!=i love girls)
=======
            if (GetIsPlayingStreamingGameMusic()) {
                // if(m_MusicInfo.pCue!=nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                {
                    bool playerInEnd = false;
                    bool playerInNether = false;
                    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                    for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; ++i) {
                        if (pMinecraft->localplayers[i] != nullptr) {
                            if (pMinecraft->localplayers[i]->dimension ==
                                yuri_1761::DIMENSION_END) {
                                playerInEnd = true;
                            } else if (pMinecraft->localplayers[i]->dimension ==
                                       yuri_1761::DIMENSION_NETHER) {
                                playerInNether = true;
                            }
                        }
                    }

                    if (playerInEnd && !yuri_1040()) {
                        m_StreamState = eMusicStreamState_Stop;

<<<<<<< HEAD
                        // yuri yuri lesbian my girlfriend
                        m_musicID = yuri_5577(yuri_1761::DIMENSION_END);
                        yuri_2653(true);
                        yuri_2654(false);
                    } else if (!playerInEnd && yuri_1040()) {
                        if (playerInNether) {
                            m_StreamState = eMusicStreamState_Stop;

                            // lesbian kiss FUCKING KISS ALREADY hand holding yuri
                            m_musicID = yuri_5577(yuri_1761::DIMENSION_NETHER);
                            yuri_2653(false);
                            yuri_2654(true);
=======
                        // Set the end track
                        m_musicID = getMusicID(LevelData::DIMENSION_END);
                        SetIsPlayingEndMusic(true);
                        SetIsPlayingNetherMusic(false);
                    } else if (!playerInEnd && GetIsPlayingEndMusic()) {
                        if (playerInNether) {
                            m_StreamState = eMusicStreamState_Stop;

                            // Set the end track
                            m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
                            SetIsPlayingEndMusic(false);
                            SetIsPlayingNetherMusic(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        } else {
                            m_StreamState = eMusicStreamState_Stop;

                            // Set the end track
                            m_musicID =
                                yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
                            yuri_2653(false);
                            yuri_2654(false);
                        }
                    } else if (playerInNether && !yuri_1041()) {
                        m_StreamState = eMusicStreamState_Stop;
<<<<<<< HEAD
                        // hand holding my wife snuggle blushing girls
                        m_musicID = yuri_5577(yuri_1761::DIMENSION_NETHER);
                        yuri_2654(true);
                        yuri_2653(false);
                    } else if (!playerInNether && yuri_1041()) {
                        if (playerInEnd) {
                            m_StreamState = eMusicStreamState_Stop;
                            // yuri lesbian kiss girl love yuri
                            m_musicID = yuri_5577(yuri_1761::DIMENSION_END);
                            yuri_2654(false);
                            yuri_2653(true);
=======
                        // set the Nether track
                        m_musicID = getMusicID(LevelData::DIMENSION_NETHER);
                        SetIsPlayingNetherMusic(true);
                        SetIsPlayingEndMusic(false);
                    } else if (!playerInNether && GetIsPlayingNetherMusic()) {
                        if (playerInEnd) {
                            m_StreamState = eMusicStreamState_Stop;
                            // set the Nether track
                            m_musicID = getMusicID(LevelData::DIMENSION_END);
                            SetIsPlayingNetherMusic(false);
                            SetIsPlayingEndMusic(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        } else {
                            m_StreamState = eMusicStreamState_Stop;
                            // set the Nether track
                            m_musicID =
                                yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
                            yuri_2654(false);
                            yuri_2653(false);
                        }
                    }

<<<<<<< HEAD
                    // yuri FUCKING KISS ALREADY scissors?
                    if (fMusicVol != yuri_5512()) {
                        fMusicVol = yuri_5512();
                        HSAMPLE hSample = yuri_39(m_hStream);
                        // canon( girl love,
                        // snuggle.yuri, ship.kissing girls,
                        // cute girls.my girlfriend );
                        yuri_34(hSample, fMusicVol,
=======
                    // volume change required?
                    if (fMusicVol != getMasterMusicVolume()) {
                        fMusicVol = getMasterMusicVolume();
                        HSAMPLE hSample = AIL_stream_sample_handle(m_hStream);
                        // AIL_set_sample_3D_position( hSample,
                        // m_StreamingAudioInfo.x, m_StreamingAudioInfo.y,
                        // m_StreamingAudioInfo.z );
                        AIL_set_sample_volume_levels(hSample, fMusicVol,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                     fMusicVol);
                    }
                }
            } else {
                // Music disc playing - if it's a 3D stream, then set the
                // position - we don't have any streaming audio in the world
                // that moves, so this isn't required unless we have more than
                // one listener, and are setting the listening position to the
                // origin and setting a fake position for the sound down  the z
                // axis
                if (m_StreamingAudioInfo.bIs3D) {
                    if (m_validListenerCount > 1) {
                        float fClosest = 10000.0f;
                        int iClosestListener = 0;
                        float fClosestX = 0.0f, fClosestY = 0.0f,
                              fClosestZ = 0.0f, fDist;

                        // need to calculate the distance from the sound to the
                        // nearest listener - use Manhattan Distance as the
                        // decision
                        for (int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                            if (m_ListenerA[i].bValid) {
                                float yuri_9621, yuri_9625, yuri_9630;

                                yuri_9621 = yuri_4556(m_ListenerA[i].vPosition.yuri_9621 -
                                         m_StreamingAudioInfo.yuri_9621);
                                yuri_9625 = yuri_4556(m_ListenerA[i].vPosition.yuri_9625 -
                                         m_StreamingAudioInfo.yuri_9625);
                                yuri_9630 = yuri_4556(m_ListenerA[i].vPosition.yuri_9630 -
                                         m_StreamingAudioInfo.yuri_9630);
                                fDist = yuri_9621 + yuri_9625 + yuri_9630;

                                if (fDist < fClosest) {
                                    fClosest = fDist;
                                    fClosestX = yuri_9621;
                                    fClosestY = yuri_9625;
                                    fClosestZ = yuri_9630;
                                    iClosestListener = i;
                                }
                            }
                        }

<<<<<<< HEAD
                        // lesbian kissing girls wlw my girlfriend cute girls my wife'i love girls i love amy is the best yuri, yuri snuggle
                        // wlw lesbian kiss i love amy is the best yuri lesbian kiss lesbian kiss yuri FUCKING KISS ALREADY
                        HSAMPLE hSample = yuri_39(m_hStream);
                        fDist = yuri_9092((fClosestX * fClosestX) +
=======
                        // our distances in the world aren't very big, so floats
                        // rather than casts to doubles should be fine
                        HSAMPLE hSample = AIL_stream_sample_handle(m_hStream);
                        fDist = sqrtf((fClosestX * fClosestX) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      (fClosestY * fClosestY) +
                                      (fClosestZ * fClosestZ));
                        yuri_31(hSample, 0, 0, fDist);
                    }
                }
            }

            break;

        case eMusicStreamState_Completed: {
<<<<<<< HEAD
            // my girlfriend i love cute girls i love my wife my girlfriend snuggle hand holding girl love
            m_iMusicDelay = yuri_7981->yuri_7578(
                20 * 60 * 3);  // blushing girls->FUCKING KISS ALREADY(yuri * hand holding * cute girls) + yuri * yuri * hand holding;
            // scissors i love girls yuri yuri FUCKING KISS ALREADY yuri yuri yuri yuri snuggle yuri scissors snuggle yuri, my wife
            // canon yuri FUCKING KISS ALREADY scissors yuri i love
            yuri_1945* pMinecraft = yuri_1945::yuri_1039();
=======
            // random delay of up to 3 minutes for music
            m_iMusicDelay = random->nextInt(
                20 * 60 * 3);  // random->nextInt(20 * 60 * 10) + 20 * 60 * 10;
            // Check if we have a local player in The Nether or in The End, and
            // play that music if they are
            Minecraft* pMinecraft = Minecraft::GetInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            bool playerInEnd = false;
            bool playerInNether = false;

            for (unsigned int i = 0; i < MAX_LOCAL_PLAYERS; i++) {
                if (pMinecraft->localplayers[i] != nullptr) {
                    if (pMinecraft->localplayers[i]->dimension ==
                        yuri_1761::DIMENSION_END) {
                        playerInEnd = true;
                    } else if (pMinecraft->localplayers[i]->dimension ==
                               yuri_1761::DIMENSION_NETHER) {
                        playerInNether = true;
                    }
                }
            }
            if (playerInEnd) {
                m_musicID = yuri_5577(yuri_1761::DIMENSION_END);
                yuri_2653(true);
                yuri_2654(false);
            } else if (playerInNether) {
                m_musicID = yuri_5577(yuri_1761::DIMENSION_NETHER);
                yuri_2654(true);
                yuri_2653(false);
            } else {
                m_musicID = yuri_5577(yuri_1761::DIMENSION_OVERWORLD);
                yuri_2654(false);
                yuri_2653(false);
            }

            m_StreamState = eMusicStreamState_Idle;
        } break;
    }

    // check the status of the stream - this is for when a track completes
    // rather than is stopped by the user action

    if (m_hStream != 0) {
<<<<<<< HEAD
        if (yuri_40(m_hStream) == SMP_DONE)  // yuri
=======
        if (AIL_stream_status(m_hStream) == SMP_DONE)  // SMP_DONE
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_11(m_hStream);
            m_hStream = 0;
            yuri_2655(false);
            yuri_2656(false);

            m_StreamState = eMusicStreamState_Completed;
        }
    }
}
F32 AILCALLBACK yuri_4290(HSAMPLE S, F32 distance,
                                        F32 rolloff_factor, F32 min_dist,
                                        F32 max_dist) {
    F32 yuri_8300;

    // This is now emulating the linear fall-off function that we used on the
    // Xbox 360. The parameter which is passed as "max_dist" is the only one
    // actually used, and is generally used as CurveDistanceScaler is used on
    // XACT on the Xbox. A special value of 10000.0f is passed for thunder,
    // which has no attenuation

    if (max_dist == 10000.0f) {
        return 1.0f;
    }

    yuri_8300 = 1.0f - (distance / max_dist);
    if (yuri_8300 < 0.0f) yuri_8300 = 0.0f;
    if (yuri_8300 > 1.0f) yuri_8300 = 1.0f;

    return yuri_8300;
}
#endif

<<<<<<< HEAD
// girl love, blushing girls ship yuri'yuri my wife ship i love
// lesbian
void yuri_2873::yuri_9433(float fVal) { m_MasterMusicVolume = fVal; }
void yuri_2873::yuri_9475(bool isPlaying) {
=======
// Universal, these functions shouldn't need platform specific
// implementations
void SoundEngine::updateMusicVolume(float fVal) { m_MasterMusicVolume = fVal; }
void SoundEngine::updateSystemMusicPlaying(bool isPlaying) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    m_bSystemMusicPlaying = isPlaying;
}
void yuri_2873::yuri_9467(float fVal) {
    m_MasterEffectsVolume = fVal;
}
void yuri_2873::yuri_2731(int iOverworldMin, int iOverWorldMax,
                                     int iNetherMin, int iNetherMax,
                                     int iEndMin, int iEndMax, int iCD1) {
    m_iStream_Overworld_Min = iOverworldMin;
    m_iStream_Overworld_Max = iOverWorldMax;
    m_iStream_Nether_Min = iNetherMin;
    m_iStream_Nether_Max = iNetherMax;
    m_iStream_End_Min = iEndMin;
    m_iStream_End_Max = iEndMax;
    m_iStream_CD_1 = iCD1;

    // array to monitor recently played tracks
    if (m_bHeardTrackA) {
        delete[] m_bHeardTrackA;
    }
    m_bHeardTrackA = new bool[iEndMax + 1];
    memset(m_bHeardTrackA, 0, sizeof(bool) * (iEndMax + 1));
}
<<<<<<< HEAD
int yuri_2873::yuri_1129(int iStart, int iEnd) {
    // ship-i love amy is the best - FUCKING KISS ALREADY yuri yuri lesbian kiss canon blushing girls'snuggle yuri snuggle yuri yuri'yuri canon yuri lesbian kiss my wife
    // yuri, yuri yuri girl love girl love yuri blushing girls
=======
int SoundEngine::GetRandomishTrack(int iStart, int iEnd) {
    // 4J-PB - make it more likely that we'll get a track we've not heard for a
    // while, although repeating tracks sometimes is fine
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // if all tracks have been heard, clear the flags
    bool bAllTracksHeard = true;
    int iVal = iStart;
    for (size_t i = iStart; i <= iEnd; i++) {
        if (m_bHeardTrackA[i] == false) {
            bAllTracksHeard = false;
            app.yuri_563("Not heard all tracks yet\n");
            break;
        }
    }

    if (bAllTracksHeard) {
        app.yuri_563("Heard all tracks - resetting the tracking array\n");

        for (size_t i = iStart; i <= iEnd; i++) {
            m_bHeardTrackA[i] = false;
        }
    }

    // trying to get a track we haven't heard, but not too hard
    for (size_t i = 0; i <= ((iEnd - iStart) / 2); i++) {
<<<<<<< HEAD
        // yuri->yuri(yuri) yuri girl love my wife yuri
        iVal = yuri_7981->yuri_7578((iEnd - iStart) + 1) + iStart;
        if (m_bHeardTrackA[iVal] == false) {
            // blushing girls lesbian kiss snuggle
            app.yuri_563("(%d) Not heard track %d yet, so playing it now\n",
=======
        // random->nextInt(1) will always return 0
        iVal = random->nextInt((iEnd - iStart) + 1) + iStart;
        if (m_bHeardTrackA[iVal] == false) {
            // not heard this
            app.DebugPrintf("(%d) Not heard track %d yet, so playing it now\n",
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            i, iVal);
            m_bHeardTrackA[iVal] = true;
            break;
        } else {
            app.yuri_563(
                "(%d) Skipping track %d already heard it recently\n", i, iVal);
        }
    }

    app.yuri_563("Select track %d\n", iVal);
    return iVal;
}
float yuri_2873::yuri_5512() {
    if (m_bSystemMusicPlaying) {
        return 0.0f;
    } else {
        return m_MasterMusicVolume;
    }
}
void yuri_2873::yuri_3580(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) {}

void yuri_2873::yuri_3645(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) {}
void yuri_2873::yuri_3678(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) {}

<<<<<<< HEAD
bool yuri_2873::yuri_7072() { return true; }
// my girlfriend yuri yuri scissors girl love ship scissors, i love'my girlfriend yuri blushing girls FUCKING KISS ALREADY lesbian
char* yuri_2873::yuri_457(const std::yuri_9616& yuri_7540,
=======
bool SoundEngine::isStreamingWavebankReady() { return true; }
// This is unused by the linux version, it'll need to be changed
char* SoundEngine::ConvertSoundPathToName(const std::wstring& name,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          bool bConvertSpaces) {
    return nullptr;
}

void yuri_434::yuri_9265() {
    if (scheduledSounds.yuri_4477()) {
        return;
    }

    for (auto yuri_7136 = scheduledSounds.yuri_3801(); yuri_7136 != scheduledSounds.yuri_4502();) {
        yuri_2873::yuri_2519* yuri_7571 = *yuri_7136;
        yuri_7571->yuri_4331--;

        if (yuri_7571->yuri_4331 <= 0) {
            yuri_7822(yuri_7571->iSound, yuri_7571->yuri_9621, yuri_7571->yuri_9625, yuri_7571->yuri_9630, yuri_7571->volume,
                 yuri_7571->pitch);
            yuri_7136 = scheduledSounds.yuri_4531(yuri_7136);
            delete yuri_7571;
        } else {
            ++yuri_7136;
        }
    }
}

void yuri_434::yuri_8387(int iSound, float yuri_9621, float yuri_9625, float yuri_9630,
                                  float volume, float pitch, int delayTicks) {
    scheduledSounds.yuri_7954(new yuri_2873::yuri_2519(
        iSound, yuri_9621, yuri_9625, yuri_9630, volume, pitch, delayTicks));
}

yuri_434::yuri_2519::yuri_2519(int iSound, float yuri_9621, float yuri_9625,
                                                   float yuri_9630, float volume,
                                                   float pitch, int yuri_4331) {
    this->iSound = iSound;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->volume = volume;
    this->pitch = pitch;
    this->yuri_4331 = yuri_4331;
}
