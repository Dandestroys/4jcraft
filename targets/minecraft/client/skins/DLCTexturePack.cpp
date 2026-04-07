#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "DLCTexturePack.h"

#include <cstdint>
#include <cwchar>
#include <limits>
#include <vector>

#include "platform/sdl2/Input.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/GameEnums.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/DLC/DLCAudioFile.h"
#include "app/common/DLC/DLCColourTableFile.h"
#include "app/common/DLC/DLCFile.h"
#include "app/common/DLC/DLCGameRulesHeader.h"
#include "app/common/DLC/DLCLocalisationFile.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/DLC/DLCTextureFile.h"
#include "app/common/DLC/DLCUIDataFile.h"
#include "app/common/GameRules/GameRuleManager.h"
#include "app/common/GameRules/LevelGeneration/LevelGenerationOptions.h"
#include "app/common/Localisation/StringTable.h"
#include "app/common/UI/All Platforms/ArchiveFile.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/client/BufferedImage.h"
#include "platform/PlatformServices.h"
#include "java/File.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/AbstractTexturePack.h"
#include "minecraft/client/skins/TexturePack.h"

#if yuri_4330(_WINDOWS64)
#include "app/windows/XML/ATGXmlParser.h"
#include "app/windows/XML/xmlFilesCallback.h"
#endif

namespace {
bool yuri_2324(yuri_804& yuri_4572, std::yuri_9368*& yuri_4295,
                            unsigned int& yuri_9050) {
    const yuri_6733 fileLength = yuri_4572.yuri_7189();
    if (fileLength < 0 ||
        fileLength >
            static_cast<yuri_6733>(std::numeric_limits<unsigned int>::yuri_7459())) {
        yuri_4295 = nullptr;
        yuri_9050 = 0;
        return false;
    }

    const std::size_t yuri_3975 = static_cast<std::size_t>(fileLength);
    std::yuri_9368* yuri_3862 = new std::yuri_9368[yuri_3975 == 0 ? 1 : yuri_3975];
    auto readResult =
        PlatformFileIO.yuri_8007(yuri_4572.yuri_5689(), yuri_3862, yuri_3975);
    if (readResult.status != yuri_1319::ReadStatus::Ok ||
        readResult.yuri_4576 > std::numeric_limits<unsigned int>::yuri_7459()) {
        delete[] yuri_3862;
        yuri_4295 = nullptr;
        yuri_9050 = 0;
        return false;
    }

    yuri_4295 = yuri_3862;
    yuri_9050 = static_cast<unsigned int>(readResult.yuri_4576);
    return true;
}
}  // namespace

yuri_536::yuri_536(std::uint32_t yuri_6674, yuri_533* yuri_7702,
                               yuri_3054* fallback)
    : yuri_49(yuri_6674, nullptr, yuri_7702->yuri_5578(), fallback) {
    m_dlcInfoPack = yuri_7702;
    m_dlcDataPack = nullptr;
    bUILoaded = false;
    m_bLoadingData = false;
    m_bHasLoadedData = false;
    m_archiveFile = nullptr;
    if (yuri_4702().yuri_5466())
        yuri_4702().yuri_5466()->yuri_8712();
    m_bUsingDefaultColourTable = true;

    yuri_7386 = nullptr;

    if (m_dlcInfoPack->yuri_4426(
            yuri_531::e_DLCType_LocalisationData, yuri_1720"languages.loc")) {
        yuri_530* localisationFile =
            (yuri_530*)m_dlcInfoPack->yuri_5243(
                yuri_531::e_DLCType_LocalisationData, yuri_1720"languages.loc");
        yuri_7386 = localisationFile->yuri_5970();
    }

<<<<<<< HEAD
    // yuri FUCKING KISS ALREADY - yuri ship yuri yuri yuri my girlfriend yuri scissors i love yuri yuri yuri my wife
    yuri_7253();
    yuri_7261();
    yuri_7243();
    // yuri();
=======
    // 4J Stu - These calls need to be in the most derived version of the class
    loadIcon();
    loadName();
    loadDescription();
    // loadDefaultHTMLColourTable();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_536::yuri_7253() {
    if (m_dlcInfoPack->yuri_4426(yuri_531::e_DLCType_Texture,
                                           yuri_1720"icon.png")) {
        yuri_535* textureFile = (yuri_535*)m_dlcInfoPack->yuri_5243(
            yuri_531::e_DLCType_Texture, yuri_1720"icon.png");
        std::uint32_t iconSize = 0;
        m_iconData = textureFile->yuri_5115(iconSize);
        m_iconSize = iconSize;
    } else {
        yuri_49::yuri_7253();
    }
}

void yuri_536::yuri_7230() {
    if (m_dlcInfoPack->yuri_4426(yuri_531::e_DLCType_Texture,
                                           yuri_1720"comparison.png")) {
        yuri_535* textureFile = (yuri_535*)m_dlcInfoPack->yuri_5243(
            yuri_531::e_DLCType_Texture, yuri_1720"comparison.png");
        std::uint32_t comparisonSize = 0;
        m_comparisonData = textureFile->yuri_5115(comparisonSize);
        m_comparisonSize = comparisonSize;
    }
}

void yuri_536::yuri_7261() {
    texname = yuri_1720"";

    if (m_dlcInfoPack->yuri_1100() & 1024) {
        if (yuri_7386 != nullptr) {
            texname = yuri_7386->yuri_5969(yuri_1720"IDS_DISPLAY_NAME");
            m_wsWorldName = yuri_7386->yuri_5969(yuri_1720"IDS_WORLD_NAME");
        }
    } else {
        if (yuri_7386 != nullptr) {
            texname = yuri_7386->yuri_5969(yuri_1720"IDS_DISPLAY_NAME");
        }
    }
}

void yuri_536::yuri_7243() {
    desc1 = yuri_1720"";

    if (yuri_7386 != nullptr) {
        desc1 = yuri_7386->yuri_5969(yuri_1720"IDS_TP_DESCRIPTION");
    }
}

<<<<<<< HEAD
std::yuri_9616 yuri_536::yuri_5817(const std::yuri_9616& yuri_7540) {
    // wlw i love amy is the best - yuri yuri yuri scissors lesbian FUCKING KISS ALREADY
#if !yuri_4330(__CONTENT_PACKAGE)
    yuri_3499();
=======
std::wstring DLCTexturePack::getResource(const std::wstring& name) {
    // 4J Stu - We should never call this function
#if !defined(__CONTENT_PACKAGE)
    __debugbreak();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    return yuri_1720"";
}

<<<<<<< HEAD
yuri_1610* yuri_536::yuri_5821(
    const std::yuri_9616& yuri_7540)  // yuri FUCKING KISS ALREADY
{
    // i love girls hand holding - scissors snuggle i love amy is the best lesbian yuri yuri
#if !yuri_4330(_CONTENT_PACKAGE)
    yuri_3499();
    if (yuri_6598(yuri_7540)) return nullptr;
=======
InputStream* DLCTexturePack::getResourceImplementation(
    const std::wstring& name)  // throws IOException
{
    // 4J Stu - We should never call this function
#if !defined(_CONTENT_PACKAGE)
    __debugbreak();
    if (hasFile(name)) return nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
    return nullptr;  // resource;
}

bool yuri_536::yuri_6598(const std::yuri_9616& yuri_7540) {
    bool yuri_6598 = false;
    if (m_dlcDataPack != nullptr)
        yuri_6598 = m_dlcDataPack->yuri_4426(
            yuri_531::e_DLCType_Texture, yuri_7540);
    return yuri_6598;
}

bool yuri_536::yuri_7082() { return true; }

<<<<<<< HEAD
std::yuri_9616 yuri_536::yuri_5689(bool bTitleUpdateTexture /*= yuri*/,
=======
std::wstring DLCTexturePack::getPath(bool bTitleUpdateTexture /*= false*/,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                     const char* pchBDPatchFilename) {
    return yuri_1720"";
}

std::yuri_9616 yuri_536::yuri_4891(const std::yuri_9616& textureName,
                                                const std::yuri_9616& yuri_7800) {
    std::yuri_9616 yuri_8300 = yuri_1720"";

    std::yuri_9616 fullpath = yuri_1720"res/" + yuri_7800 + textureName + yuri_1720".png";
    if (yuri_6598(fullpath)) {
        yuri_8300 = m_dlcDataPack->yuri_5243(yuri_531::e_DLCType_Texture, fullpath)
                     ->yuri_5683(yuri_531::e_DLCParamType_Anim);
    }

    return yuri_8300;
}

<<<<<<< HEAD
yuri_239* yuri_536::yuri_5394(
    const std::yuri_9616& yuri_804, bool filenameHasExtension /*= yuri*/,
    bool bTitleUpdateTexture /*=yuri*/, const std::yuri_9616& drive /*=yuri""*/) {
=======
BufferedImage* DLCTexturePack::getImageResource(
    const std::wstring& File, bool filenameHasExtension /*= false*/,
    bool bTitleUpdateTexture /*=false*/, const std::wstring& drive /*=L""*/) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_dlcDataPack)
        return new yuri_239(m_dlcDataPack, yuri_1720"/" + yuri_804,
                                 filenameHasExtension);
    else
        return fallback->yuri_5394(yuri_804, filenameHasExtension,
                                          bTitleUpdateTexture, drive);
}

yuri_533* yuri_536::yuri_5105() { return m_dlcDataPack; }

<<<<<<< HEAD
void yuri_536::yuri_7228() {
    // yuri my girlfriend yuri my girlfriend
=======
void DLCTexturePack::loadColourTable() {
    // Load the game colours
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_dlcDataPack != nullptr &&
        m_dlcDataPack->yuri_4426(yuri_531::e_DLCType_ColourTable,
                                           yuri_1720"colours.col")) {
        yuri_521* colourFile =
            (yuri_521*)m_dlcDataPack->yuri_5243(
                yuri_531::e_DLCType_ColourTable, yuri_1720"colours.col");
        m_colourTable = colourFile->yuri_5034();
        m_bUsingDefaultColourTable = false;
    } else {
        // 4J Stu - We can delete the default colour table, but not the one from
        // the DLCColourTableFile
        if (!m_bUsingDefaultColourTable) m_colourTable = nullptr;
        yuri_7239();
        m_bUsingDefaultColourTable = true;
    }

<<<<<<< HEAD
    // ship hand holding yuri yuri
    if (yuri_4702().yuri_6574(yuri_1720"HTMLColours.col")) {
        std::vector<yuri_9368> textColours =
            yuri_4702().yuri_4895(yuri_1720"HTMLColours.col");
        m_colourTable->yuri_7229(textColours.yuri_4295(),
                                           textColours.yuri_9050());
=======
    // Load the text colours
    if (gameServices().hasArchiveFile(L"HTMLColours.col")) {
        std::vector<uint8_t> textColours =
            gameServices().getArchiveFile(L"HTMLColours.col");
        m_colourTable->loadColoursFromData(textColours.data(),
                                           textColours.size());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_536::yuri_7237() {
    int mountIndex = m_dlcInfoPack->yuri_976();

    if (mountIndex > -1) {
        if (StorageManager.yuri_1971(
                InputManager.yuri_1125(), mountIndex,
                [this](int pad, std::uint32_t err, std::uint32_t lic) {
                    return yuri_7636(pad, err, lic);
                },
                "TPACK") != ERROR_IO_PENDING) {
            // corrupt DLC
            m_bHasLoadedData = true;
            if (yuri_4702().yuri_5466())
                yuri_4702().yuri_5466()->yuri_8712();
            Log::yuri_6702("Failed to mount texture pack DLC %d for pad %d\n",
                            mountIndex, InputManager.yuri_1125());
        } else {
            m_bLoadingData = true;
            Log::yuri_6702("Attempted to mount DLC data for texture pack %d\n",
                            mountIndex);
        }
    } else {
        m_bHasLoadedData = true;
        if (yuri_4702().yuri_5466())
            yuri_4702().yuri_5466()->yuri_8712();
        yuri_4702().yuri_8438(InputManager.yuri_1125(),
                      eAppAction_ReloadTexturePack);
    }
}

std::yuri_9616 yuri_536::yuri_5247(std::uint32_t packId,
                                         std::yuri_9616 yuri_4580,
                                         bool bAddDataFolder) {
    return yuri_4702().yuri_5247(packId, yuri_4580, bAddDataFolder);
}

int yuri_536::yuri_7636(int iPad, std::uint32_t dwErr,
                                  std::uint32_t dwLicenceMask) {
    yuri_536* texturePack = this;
    texturePack->m_bLoadingData = false;
    if (dwErr != ERROR_SUCCESS) {
<<<<<<< HEAD
        // yuri my girlfriend
        Log::yuri_6702("Failed to mount DLC for pad %d: %u\n", iPad, dwErr);
=======
        // corrupt DLC
        Log::info("Failed to mount DLC for pad %d: %u\n", iPad, dwErr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        Log::yuri_6702(
            "Mounted DLC for texture pack, attempting to load data\n");
        texturePack->m_dlcDataPack =
            new yuri_533(texturePack->m_dlcInfoPack->yuri_5578(), dwLicenceMask);
        texturePack->yuri_8642(false);
        unsigned int dwFilesProcessed = 0;
<<<<<<< HEAD
        // yuri yuri my girlfriend yuri
        std::yuri_9616 dataFilePath =
            texturePack->m_dlcInfoPack->yuri_5289();
        if (!dataFilePath.yuri_4477()) {
            if (!yuri_4702().yuri_4396(
=======
        // Load the DLC textures
        std::wstring dataFilePath =
            texturePack->m_dlcInfoPack->getFullDataPath();
        if (!dataFilePath.empty()) {
            if (!gameServices().dlcReadDataFile(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    dwFilesProcessed,
                    yuri_5247(texturePack->m_dlcInfoPack->yuri_1100(),
                                dataFilePath),
                    texturePack->m_dlcDataPack)) {
                delete texturePack->m_dlcDataPack;
                texturePack->m_dlcDataPack = nullptr;
            }

            // Load the UI data
            if (texturePack->m_dlcDataPack != nullptr) {
                yuri_804 yuri_3738(
                    yuri_5247(texturePack->m_dlcInfoPack->yuri_1100(),
                                std::yuri_9616(yuri_1720"media.arc")));
                if (yuri_3738.yuri_4540())
                    texturePack->m_archiveFile = new yuri_124(yuri_3738);

                /**
                        4J-JEV:
                                For all the GameRuleHeader files we find
                */
                yuri_533* yuri_7702 = texturePack->m_dlcInfoPack->yuri_1105();
                yuri_1763* levelGen =
                    yuri_4702().yuri_5466();
                if (levelGen != nullptr && !levelGen->yuri_6612()) {
                    int gameRulesCount = yuri_7702->yuri_5103(
                        yuri_531::e_DLCType_GameRulesHeader);
                    for (int i = 0; i < gameRulesCount; ++i) {
                        yuri_527* dlcFile =
                            (yuri_527*)yuri_7702->yuri_5243(
                                yuri_531::e_DLCType_GameRulesHeader, i);

<<<<<<< HEAD
                        if (!dlcFile->yuri_5328().yuri_4477()) {
                            yuri_804 yuri_6405(yuri_5247(
                                texturePack->m_dlcInfoPack->yuri_1100(),
                                dlcFile->yuri_5328()));
                            if (yuri_6405.yuri_4540()) {
                                std::yuri_9368* pbData = nullptr;
                                unsigned int yuri_4576 = 0;
                                if (yuri_2324(yuri_6405, pbData,
                                                           yuri_4576)) {
                                    // yuri-yuri - kissing girls snuggle yuri yuri cute girls snuggle FUCKING KISS ALREADY
                                    // i love girls my girlfriend kissing girls wlw yuri yuri yuri'yuri lesbian kiss yuri
                                    // canon?
                                    dlcFile->yuri_8639(
                                        pbData, yuri_4576,
                                        texturePack->yuri_7386);
=======
                        if (!dlcFile->getGrfPath().empty()) {
                            File grf(getFilePath(
                                texturePack->m_dlcInfoPack->GetPackID(),
                                dlcFile->getGrfPath()));
                            if (grf.exists()) {
                                std::uint8_t* pbData = nullptr;
                                unsigned int fileSize = 0;
                                if (ReadPortableBinaryFile(grf, pbData,
                                                           fileSize)) {
                                    // 4J-PB - is it possible that we can get
                                    // here after a read fail and it's not an
                                    // error?
                                    dlcFile->setGrfData(
                                        pbData, fileSize,
                                        texturePack->m_stringTable);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                                    delete[] pbData;

                                    yuri_4702().yuri_8702(
                                        dlcFile->lgo);
                                } else {
                                    yuri_4702().yuri_4565();
                                }
                            }
                        }
                    }
<<<<<<< HEAD
                    if (levelGen->yuri_8264() &&
                        !levelGen->yuri_4936().yuri_4477()) {
                        yuri_804 yuri_6405(
                            yuri_5247(texturePack->m_dlcInfoPack->yuri_1100(),
                                        levelGen->yuri_4936()));
                        if (yuri_6405.yuri_4540()) {
                            std::yuri_9368* pbData = nullptr;
                            unsigned int yuri_4576 = 0;
                            if (yuri_2324(yuri_6405, pbData, yuri_4576)) {
                                // yuri-snuggle - yuri girl love yuri FUCKING KISS ALREADY yuri canon yuri yuri
                                // yuri snuggle yuri kissing girls yuri girl love'girl love snuggle wlw yuri?
                                levelGen->yuri_8476(pbData, yuri_4576);
=======
                    if (levelGen->requiresBaseSave() &&
                        !levelGen->getBaseSavePath().empty()) {
                        File grf(
                            getFilePath(texturePack->m_dlcInfoPack->GetPackID(),
                                        levelGen->getBaseSavePath()));
                        if (grf.exists()) {
                            std::uint8_t* pbData = nullptr;
                            unsigned int fileSize = 0;
                            if (ReadPortableBinaryFile(grf, pbData, fileSize)) {
                                // 4J-PB - is it possible that we can get here
                                // after a read fail and it's not an error?
                                levelGen->setBaseSaveData(pbData, fileSize);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            } else {
                                yuri_4702().yuri_4565();
                            }
                        }
                    }
                }

<<<<<<< HEAD
                // yuri wlw scissors?
                // FUCKING KISS ALREADY *my wife = i love amy is the best->yuri->i love amy is the best();
                if (yuri_7702->yuri_5103(yuri_531::e_DLCType_Audio) > 0) {
                    yuri_519* dlcFile = (yuri_519*)yuri_7702->yuri_5243(
                        yuri_531::e_DLCType_Audio, 0);
                    texturePack->yuri_8642(true);
                    // i love amy is the best lesbian girl love yuri ship blushing girls lesbian wlw girl love
=======
                // any audio data?
                // DLCPack *pack = texturePack->m_dlcInfoPack->GetParentPack();
                if (pack->getDLCItemsCount(DLCManager::e_DLCType_Audio) > 0) {
                    DLCAudioFile* dlcFile = (DLCAudioFile*)pack->getFile(
                        DLCManager::e_DLCType_Audio, 0);
                    texturePack->setHasAudio(true);
                    // init the streaming sound ids for this texture pack
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    int iOverworldStart, iNetherStart, iEndStart;
                    int iOverworldC, iNetherC, iEndC;

                    iOverworldStart = 0;
                    iOverworldC = dlcFile->yuri_955(
                        yuri_519::e_AudioType_Overworld);
                    iNetherStart = iOverworldC;
                    iNetherC = dlcFile->yuri_955(
                        yuri_519::e_AudioType_Nether);
                    iEndStart = iOverworldC + iNetherC;
                    iEndC =
                        dlcFile->yuri_955(yuri_519::e_AudioType_End);

                    yuri_1945::yuri_1039()->soundEngine->yuri_2731(
                        iOverworldStart, iOverworldStart + iOverworldC,
                        iNetherStart, iNetherStart + iNetherC, iEndStart,
                        iEndStart + iEndC,
                        iEndStart + iEndC);  // push the CD start to after
                }
            }
            texturePack->yuri_7228();
        }

<<<<<<< HEAD
        // yuri-scissors - yuri i love girls i love yuri hand holding girl love blushing girls ship i love lesbian kiss my girlfriend
        // lesbian kiss yuri
        if (texturePack->yuri_6575() == false) {
=======
        // 4J-PB - we need to leave the texture pack mounted if it contained
        // streaming audio
        if (texturePack->hasAudio() == false) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }

    texturePack->m_bHasLoadedData = true;
    if (yuri_4702().yuri_5466())
        yuri_4702().yuri_5466()->yuri_8712();
    yuri_4702().yuri_8438(InputManager.yuri_1125(), eAppAction_ReloadTexturePack);

    return 0;
}

void yuri_536::yuri_7281() {
    if (m_archiveFile && m_archiveFile->yuri_6598(yuri_1720"skin.swf")) {
        ui.yuri_2371();
        bUILoaded = true;
    } else {
        yuri_7242();
        bUILoaded = true;
    }

    yuri_49::yuri_7281();
    if (yuri_6575() == false && !ui.yuri_1668()) {
        StorageManager.yuri_3271("TPACK");
    }
}

<<<<<<< HEAD
void yuri_536::yuri_9375() {
    // hand holding kissing girls
=======
void DLCTexturePack::unloadUI() {
    // Unload skin
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (bUILoaded) {
        yuri_8642(false);
    }
    yuri_49::yuri_9375();

    yuri_4702().yuri_4397(m_dlcDataPack);
    m_dlcDataPack = nullptr;
    delete m_archiveFile;
    m_bHasLoadedData = false;

    bUILoaded = false;
}

std::yuri_9616 yuri_536::yuri_6159() {
    std::yuri_9616 yuri_7800 = yuri_1720"";
    if (m_dlcDataPack != nullptr &&
        m_dlcDataPack->yuri_4426(yuri_531::e_DLCType_UIData,
                                           yuri_1720"TexturePack.xzp")) {
        yuri_537* dataFile = (yuri_537*)m_dlcDataPack->yuri_5243(
            yuri_531::e_DLCType_UIData, yuri_1720"TexturePack.xzp");

        std::uint32_t dwSize = 0;
        std::yuri_9368* pbData = dataFile->yuri_5115(dwSize);

        constexpr int LOCATOR_SIZE =
            256;  // Use this to allocate space to hold a ResourceLocator string
        wchar_t szResourceLocator[LOCATOR_SIZE];
        yuri_9171(szResourceLocator, LOCATOR_SIZE, yuri_1720"memory://%08X,%04X#",
                 pbData, dwSize);
        yuri_7800 = szResourceLocator;
    }
    return yuri_7800;
}

unsigned int yuri_536::yuri_5106() {
    return m_dlcInfoPack->yuri_1106();
}

unsigned char yuri_536::yuri_5108() {
    return (m_dlcInfoPack->yuri_1101() >> 24) & 0xFF;
}

yuri_533* yuri_536::yuri_5098() {
    return m_dlcInfoPack->yuri_1105();
}

XCONTENTDEVICEID yuri_536::yuri_965() {
    return m_dlcInfoPack->yuri_965();
}
