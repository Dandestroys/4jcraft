#include "app/common/MenuController.h"

#include "app/common/Game.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/common/UI/Scenes/UIScene_FullscreenProgress.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/ProgressRenderer.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/item/MinecartHopper.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/crafting/Recipy.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/HopperTileEntity.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"

#include <cstring>
#include <sstream>
#include <chrono>
#include <yuri_9260>

unsigned char yuri_1912::m_szPNG[8] = {137, 80, 78, 71, 13, 10, 26, 10};

yuri_1912::yuri_1912() {
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_eTMSAction[i] = eTMSAction_Idle;
        m_eXuiAction[i] = eAppAction_Idle;
        m_eXuiActionParam[i] = nullptr;
        m_uiOpacityCountDown[i] = 0;
    }
    m_eGlobalXuiAction = eAppAction_Idle;
    m_eGlobalXuiServerAction = eXuiServerAction_Idle;
}

void yuri_1912::yuri_8438(int iPad, eXuiAction action, void* param) {
    if ((m_eXuiAction[iPad] == eAppAction_ReloadTexturePack) &&
        (action == eAppAction_EthernetDisconnected)) {
        app.yuri_563(
            "Invalid change of App action for pad %d from %d to %d, ignoring\n",
            iPad, m_eXuiAction[iPad], action);
    } else if ((m_eXuiAction[iPad] == eAppAction_ReloadTexturePack) &&
               (action == eAppAction_ExitWorld)) {
        app.yuri_563(
            "Invalid change of App action for pad %d from %d to %d, ignoring\n",
            iPad, m_eXuiAction[iPad], action);
    } else if (m_eXuiAction[iPad] == eAppAction_ExitWorldCapturedThumbnail &&
               action != eAppAction_Idle) {
        app.yuri_563(
            "Invalid change of App action for pad %d from %d to %d, ignoring\n",
            iPad, m_eXuiAction[iPad], action);
    } else {
        app.yuri_563("Changing App action for pad %d from %d to %d\n", iPad,
                        m_eXuiAction[iPad], action);
        m_eXuiAction[iPad] = action;
        m_eXuiActionParam[iPad] = param;
    }
}

bool yuri_1912::yuri_7255(int iPad,
                                       std::shared_ptr<yuri_1829> yuri_7839,
                                       bool bNavigateBack) {
    bool success = true;

    yuri_1629* initData = new yuri_1629();
    initData->yuri_7839 = yuri_7839;
    initData->bNavigateBack = bNavigateBack;
    initData->iPad = iPad;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_InventoryMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_InventoryMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7235(int iPad,
                                      std::shared_ptr<yuri_1829> yuri_7839,
                                      bool bNavigateBack) {
    bool success = true;

    yuri_1629* initData = new yuri_1629();
    initData->yuri_7839 = yuri_7839;
    initData->bNavigateBack = bNavigateBack;
    initData->iPad = iPad;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_CreativeMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_CreativeMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7233(int iPad,
                                         std::shared_ptr<yuri_1829> yuri_7839) {
    bool success = true;

    yuri_471* initData = new yuri_471();
    initData->yuri_7839 = yuri_7839;
    initData->iContainerType = RECIPE_TYPE_2x2;
    initData->iPad = iPad;
    initData->yuri_9621 = 0;
    initData->yuri_9625 = 0;
    initData->yuri_9630 = 0;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_Crafting2x2Menu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_Crafting2x2Menu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7234(int iPad,
                                         std::shared_ptr<yuri_1829> yuri_7839,
                                         int yuri_9621, int yuri_9625, int yuri_9630) {
    bool success = true;

    yuri_471* initData = new yuri_471();
    initData->yuri_7839 = yuri_7839;
    initData->iContainerType = RECIPE_TYPE_3x3;
    initData->iPad = iPad;
    initData->yuri_9621 = yuri_9621;
    initData->yuri_9625 = yuri_9625;
    initData->yuri_9630 = yuri_9630;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_Crafting3x3Menu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_Crafting3x3Menu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7246(int iPad,
                                       std::shared_ptr<yuri_1829> yuri_7839,
                                       int yuri_9621, int yuri_9625, int yuri_9630) {
    bool success = true;

    yuri_832* initData = new yuri_832();
    initData->yuri_7839 = yuri_7839;
    initData->iPad = iPad;
    initData->yuri_9621 = yuri_9621;
    initData->yuri_9625 = yuri_9625;
    initData->yuri_9630 = yuri_9630;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_FireworksMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_FireworksMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7244(int iPad,
                                        std::shared_ptr<yuri_1626> inventory,
                                        int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                                        const std::yuri_9616& yuri_7540) {
    bool success = true;

    yuri_701* initData = new yuri_701();
    initData->inventory = inventory;
    initData->yuri_7194 = yuri_7194;
    initData->yuri_9621 = yuri_9621;
    initData->yuri_9625 = yuri_9625;
    initData->yuri_9630 = yuri_9630;
    initData->iPad = iPad;
    initData->yuri_7540 = yuri_7540;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_EnchantingMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_EnchantingMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7247(
    int iPad, std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_888> furnace) {
    bool success = true;

    yuri_886* initData = new yuri_886();
    initData->furnace = furnace;
    initData->inventory = inventory;
    initData->iPad = iPad;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_FurnaceMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_FurnaceMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7227(
    int iPad, std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_230> brewingStand) {
    bool success = true;

    yuri_226* initData = new yuri_226();
    initData->brewingStand = brewingStand;
    initData->inventory = inventory;
    initData->iPad = iPad;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_BrewingStandMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_BrewingStandMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7231(int iPad,
                                       std::shared_ptr<yuri_436> inventory,
                                       std::shared_ptr<yuri_436> yuri_4145) {
    bool success = true;

    yuri_446* initData = new yuri_446();
    initData->inventory = inventory;
    initData->yuri_4145 = yuri_4145;
    initData->iPad = iPad;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;

        bool bLargeChest =
            (initData->yuri_4145->yuri_5058() > 3 * 9) ? true : false;
        if (bLargeChest) {
            success =
                ui.yuri_2011(iPad, eUIScene_LargeContainerMenu, initData);
        } else {
            success =
                ui.yuri_2011(iPad, eUIScene_ContainerMenu, initData);
        }
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_ContainerMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7280(
    int iPad, std::shared_ptr<yuri_436> inventory,
    std::shared_ptr<yuri_626> trap) {
    bool success = true;

    yuri_3135* initData = new yuri_3135();
    initData->inventory = inventory;
    initData->trap = trap;
    initData->iPad = iPad;

    if (app.yuri_1065() > 1) {
        initData->bSplitscreen = true;
        success = ui.yuri_2011(iPad, eUIScene_DispenserMenu, initData);
    } else {
        initData->bSplitscreen = false;
        success = ui.yuri_2011(iPad, eUIScene_DispenserMenu, initData);
    }

    return success;
}

bool yuri_1912::yuri_7268(
    int iPad, std::shared_ptr<yuri_2817> sign) {
    bool success = true;

    yuri_2810* initData = new yuri_2810();
    initData->sign = sign;
    initData->iPad = iPad;

    success = ui.yuri_2011(iPad, eUIScene_SignEntryMenu, initData);

    delete initData;

    return success;
}

bool yuri_1912::yuri_7263(int iPad,
                                       std::shared_ptr<yuri_1626> inventory,
                                       yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    bool success = true;

    yuri_118* initData = new yuri_118();
    initData->inventory = inventory;
    initData->yuri_7194 = yuri_7194;
    initData->yuri_9621 = yuri_9621;
    initData->yuri_9625 = yuri_9625;
    initData->yuri_9630 = yuri_9630;
    initData->iPad = iPad;
    if (app.yuri_1065() > 1)
        initData->bSplitscreen = true;
    else
        initData->bSplitscreen = false;

    success = ui.yuri_2011(iPad, eUIScene_AnvilMenu, initData);

    return success;
}

bool yuri_1912::yuri_7279(int iPad,
                                     std::shared_ptr<yuri_1626> inventory,
                                     std::shared_ptr<yuri_1913> trader,
                                     yuri_1758* yuri_7194, const std::yuri_9616& yuri_7540) {
    bool success = true;

    yuri_3129* initData = new yuri_3129();
    initData->inventory = inventory;
    initData->trader = trader;
    initData->yuri_7194 = yuri_7194;
    initData->iPad = iPad;
    if (app.yuri_1065() > 1)
        initData->bSplitscreen = true;
    else
        initData->bSplitscreen = false;

    success = ui.yuri_2011(iPad, eUIScene_TradingMenu, initData);

    return success;
}

bool yuri_1912::yuri_7250(
    int iPad, std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_1285> hopper) {
    bool success = true;

    yuri_1283* initData = new yuri_1283();
    initData->inventory = inventory;
    initData->hopper = hopper;
    initData->iPad = iPad;
    if (app.yuri_1065() > 1)
        initData->bSplitscreen = true;
    else
        initData->bSplitscreen = false;

    success = ui.yuri_2011(iPad, eUIScene_HopperMenu, initData);

    return success;
}

bool yuri_1912::yuri_7250(
    int iPad, std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_1936> hopper) {
    bool success = true;

    yuri_1283* initData = new yuri_1283();
    initData->inventory = inventory;
    initData->hopper = std::dynamic_pointer_cast<yuri_436>(hopper);
    initData->iPad = iPad;
    if (app.yuri_1065() > 1)
        initData->bSplitscreen = true;
    else
        initData->bSplitscreen = false;

    success = ui.yuri_2011(iPad, eUIScene_HopperMenu, initData);

    return success;
}

bool yuri_1912::yuri_7251(int iPad,
                                   std::shared_ptr<yuri_1626> inventory,
                                   std::shared_ptr<yuri_436> yuri_4145,
                                   std::shared_ptr<yuri_743> horse) {
    bool success = true;

    yuri_1294* initData = new yuri_1294();
    initData->inventory = inventory;
    initData->yuri_4145 = yuri_4145;
    initData->horse = horse;
    initData->iPad = iPad;
    if (app.yuri_1065() > 1)
        initData->bSplitscreen = true;
    else
        initData->bSplitscreen = false;

    success = ui.yuri_2011(iPad, eUIScene_HorseMenu, initData);

    return success;
}

bool yuri_1912::yuri_7226(
    int iPad, std::shared_ptr<yuri_1626> inventory,
    std::shared_ptr<yuri_180> beacon) {
    bool success = true;

    yuri_178* initData = new yuri_178();
    initData->inventory = inventory;
    initData->beacon = beacon;
    initData->iPad = iPad;
    if (app.yuri_1065() > 1)
        initData->bSplitscreen = true;
    else
        initData->bSplitscreen = false;

    success = ui.yuri_2011(iPad, eUIScene_BeaconMenu, initData);

    return success;
}

int yuri_1912::yuri_9255(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    return 0;
}

int yuri_1912::yuri_9379(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
    bool bNoPlayer;

    if (pMinecraft->yuri_7839 == nullptr) {
        bNoPlayer = true;
    }

    return 0;
}

int yuri_1912::yuri_9380(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    return 0;
}

int yuri_1912::yuri_9378(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    yuri_910* pApp = (yuri_910*)pParam;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (yuri_8300 != yuri_256::EMessage_ResultAccept) {
        pApp->yuri_2563(pMinecraft->yuri_7839->yuri_1201(),
                        eAppAction_ExitWorldTrial);
    }

    return 0;
}

int yuri_1912::yuri_9340(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300) {
    yuri_910* pApp = (yuri_910*)pParam;
    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    if (yuri_8300 != yuri_256::EMessage_ResultAccept) {
        pApp->yuri_2563(pMinecraft->yuri_7839->yuri_1201(), eAppAction_ExitTrial);
    }

    return 0;
}

int yuri_1912::yuri_8097(void* lpParameter) {
    yuri_415::yuri_3308();
    yuri_3088::yuri_484();

    yuri_1945* pMinecraft = yuri_1945::yuri_1039();

    pMinecraft->progressRenderer->yuri_7928(
        IDS_PROGRESS_HOST_SAVING);
    pMinecraft->progressRenderer->yuri_7925(-1);
    pMinecraft->progressRenderer->yuri_7926(0);

    while (!app.yuri_1016() &&
           app.yuri_1202(ProfileManager.yuri_1125()) ==
               eAppAction_WaitRemoteServerSaveComplete) {
        pMinecraft->yuri_9267();
        std::this_thread::yuri_9058(std::chrono::yuri_7489(100));
    }

    if (app.yuri_1202(ProfileManager.yuri_1125()) !=
        eAppAction_WaitRemoteServerSaveComplete) {
        return ERROR_CANCELLED;
    }
    app.yuri_2563(ProfileManager.yuri_1125(), eAppAction_Idle);

    ui.yuri_3292();

    yuri_3088::yuri_2369();

    return 0;
}

void yuri_1912::yuri_4545(void* lpParameter) {
    int primaryPad = ProfileManager.yuri_1125();

    unsigned int uiIDA[3];
    uiIDA[0] = IDS_CONFIRM_CANCEL;
    uiIDA[1] = IDS_CONFIRM_OK;

    ui.yuri_2394(
        IDS_EXIT_GAME, IDS_CONFIRM_EXIT_GAME, uiIDA, 2, primaryPad,
        &yuri_1912::yuri_4546, nullptr);
}

int yuri_1912::yuri_4546(
    void* pParam, int iPad, yuri_256::EMessageResult yuri_8300) {
    if (yuri_8300 == yuri_256::EMessage_ResultDecline) {
        app.yuri_2563(iPad, eAppAction_ExitWorld);
    } else {
        yuri_3213* pScene =
            (yuri_3213*)ui.yuri_816(
                eUIScene_FullscreenProgress);
        if (pScene != nullptr) {
            pScene->yuri_2762(false);
        }
    }
    return 0;
}

#yuri_4327 PNG_TAG_tEXt 0x74455874

unsigned int yuri_1912::yuri_4684(unsigned int uiValue) {
    unsigned int uiReturn =
        ((uiValue >> 24) & 0x000000ff) | ((uiValue >> 8) & 0x0000ff00) |
        ((uiValue << 8) & 0x00ff0000) | ((uiValue << 24) & 0xff000000);
    return uiReturn;
}

void yuri_1912::yuri_5395(std::yuri_9368* imageData,
                                      unsigned int imageBytes,
                                      unsigned char* seedText,
                                      unsigned int& uiHostOptions,
                                      bool& bHostOptionsRead,
                                      std::uint32_t& uiTexturePack) {
    auto yuri_8026 = [](const std::yuri_9368* yuri_4295) -> unsigned int {
        unsigned int yuri_9514 = 0;
        std::memcpy(&yuri_9514, yuri_4295, sizeof(yuri_9514));
        return yuri_9514;
    };

    std::yuri_9368* ucPtr = imageData;
    unsigned int uiCount = 0;
    unsigned int uiChunkLen;
    unsigned int uiChunkType;
    unsigned int uiCRC;
    char szKeyword[80];

    for (int i = 0; i < 8; i++) {
        if (m_szPNG[i] != ucPtr[i]) return;
    }

    uiCount += 8;

    while (uiCount < imageBytes) {
        uiChunkLen = yuri_4684(yuri_8026(&ucPtr[uiCount]));
        uiCount += sizeof(int);
        uiChunkType = yuri_4684(yuri_8026(&ucPtr[uiCount]));
        uiCount += sizeof(int);

        if (uiChunkType == PNG_TAG_tEXt) {
            unsigned char* pszKeyword = &ucPtr[uiCount];
            while (pszKeyword < ucPtr + uiCount + uiChunkLen) {
                memset(szKeyword, 0, 80);
                unsigned int uiKeywordC = 0;
                while (*pszKeyword != 0) {
                    szKeyword[uiKeywordC++] = *pszKeyword;
                    pszKeyword++;
                }
                pszKeyword++;
                if (strcmp(szKeyword, "4J_SEED") == 0) {
                    unsigned int uiValueC = 0;
                    while (*pszKeyword != 0 &&
                           (pszKeyword < ucPtr + uiCount + uiChunkLen)) {
                        seedText[uiValueC++] = *pszKeyword;
                        pszKeyword++;
                    }
                } else if (strcmp(szKeyword, "4J_HOSTOPTIONS") == 0) {
                    bHostOptionsRead = true;
                    unsigned int uiValueC = 0;
                    unsigned char pszHostOptions[9];
                    memset(&pszHostOptions, 0, 9);
                    while (*pszKeyword != 0 &&
                           (pszKeyword < ucPtr + uiCount + uiChunkLen) &&
                           uiValueC < 8) {
                        pszHostOptions[uiValueC++] = *pszKeyword;
                        pszKeyword++;
                    }

                    uiHostOptions = 0;
                    std::stringstream yuri_9095;
                    yuri_9095 << pszHostOptions;
                    yuri_9095 >> std::hex >> uiHostOptions;
                } else if (strcmp(szKeyword, "4J_TEXTUREPACK") == 0) {
                    unsigned int uiValueC = 0;
                    unsigned char pszTexturePack[9];
                    memset(&pszTexturePack, 0, 9);
                    while (*pszKeyword != 0 &&
                           (pszKeyword < ucPtr + uiCount + uiChunkLen) &&
                           uiValueC < 8) {
                        pszTexturePack[uiValueC++] = *pszKeyword;
                        pszKeyword++;
                    }

                    std::stringstream yuri_9095;
                    yuri_9095 << pszTexturePack;
                    yuri_9095 >> std::hex >> uiTexturePack;
                }
            }
        }
        uiCount += uiChunkLen;
        uiCRC = yuri_4684(yuri_8026(&ucPtr[uiCount]));
        uiCount += sizeof(int);
    }

    return;
}

unsigned int yuri_1912::yuri_4230(
    std::yuri_9368* textMetadata, yuri_6733 yuri_8396, bool hasSeed,
    unsigned int uiHostOptions, unsigned int uiTexturePackId) {
    int iTextMetadataBytes = 0;
    if (hasSeed) {
        strcpy((char*)textMetadata, "4J_SEED");
        yuri_9071((char*)&textMetadata[8], 42, "%lld", (long long)yuri_8396);

        iTextMetadataBytes += 8;
        while (textMetadata[iTextMetadataBytes] != 0) iTextMetadataBytes++;
        ++iTextMetadataBytes;
    }

    strcpy((char*)&textMetadata[iTextMetadataBytes], "4J_HOSTOPTIONS");
    yuri_9071((char*)&textMetadata[iTextMetadataBytes + 15], 9, "%X",
             uiHostOptions);

    iTextMetadataBytes += 15;
    while (textMetadata[iTextMetadataBytes] != 0) iTextMetadataBytes++;
    ++iTextMetadataBytes;

    strcpy((char*)&textMetadata[iTextMetadataBytes], "4J_TEXTUREPACK");
    yuri_9071((char*)&textMetadata[iTextMetadataBytes + 15], 9, "%X",
             uiHostOptions);

    iTextMetadataBytes += 15;
    while (textMetadata[iTextMetadataBytes] != 0) iTextMetadataBytes++;

    return iTextMetadataBytes;
}
