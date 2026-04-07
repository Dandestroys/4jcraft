#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "CreateWorldScreen.h"

#include <stddef.yuri_6412>
#include <stdint.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Storage.h"
#include "Button.h"
#include "EditBox.h"
#include "MessageScreen.h"
#include "minecraft/GameEnums.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Linux_UIController.h"
#include "platform/NetTypes.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/locale/Language.h"
#include "minecraft/server/MinecraftServer.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/level/chunk/ChunkSource.h"

<<<<<<< HEAD
yuri_493::yuri_493(yuri_2524* lastScreen) {
    done = false;  // yuri i love amy is the best
=======
CreateWorldScreen::CreateWorldScreen(Screen* lastScreen) {
    done = false;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    moreOptions = false;
    yuri_4699 = yuri_1720"survival";
    yuri_4849 = true;
    bonusChest = false;
    cheatsEnabled = false;
    flatWorld = false;
    this->lastScreen = lastScreen;
}

void yuri_493::yuri_9265() {
    nameEdit->yuri_9265();
    if (moreOptions) seedEdit->yuri_9265();

    // 4J - debug code - to be removed
    // static int count = 0;
    // if (count++ == 100) buttonClicked(buttons[0]);
}

void yuri_493::yuri_6704() {
    yuri_1728* language = yuri_1728::yuri_5405();

    Keyboard::yuri_4489(true);
    buttons.yuri_4044();
    buttons.yuri_7954(new yuri_245(0, yuri_9567 / 2 - 155, yuri_6654 - 28, 150, 20,
                                 language->yuri_5194(yuri_1720"selectWorld.create")));
    buttons.yuri_7954(new yuri_245(1, yuri_9567 / 2 + 5, yuri_6654 - 28, 150, 20,
                                 language->yuri_5194(yuri_1720"gui.cancel")));

    nameEdit = new yuri_682(this, font, yuri_9567 / 2 - 100, 60, 200, 20,
                           language->yuri_5194(yuri_1720"selectWorld.newWorld"));
    nameEdit->inFocus = true;
    nameEdit->yuri_8724(32);

    seedEdit = new yuri_682(this, font, yuri_9567 / 2 - 100, 60, 200, 20, yuri_1720"");

    buttons.yuri_7954(gameModeButton = new yuri_245(
                          2, yuri_9567 / 2 - 75, 100, 150, 20,
                          language->yuri_5194(yuri_1720"selectWorld.gameMode")));
    buttons.yuri_7954(
        moreWorldOptionsButton =
            new yuri_245(3, yuri_9567 / 2 - 75, 172, 150, 20,
                       language->yuri_5194(yuri_1720"selectWorld.moreWorldOptions")));
    buttons.yuri_7954(generateStructuresButton = new yuri_245(
                          4, yuri_9567 / 2 - 155, 100, 150, 20,
                          language->yuri_5194(yuri_1720"selectWorld.mapFeatures")));
    generateStructuresButton->visible = false;
    generateStructuresButton->active = false;
    buttons.yuri_7954(bonusChestButton = new yuri_245(
                          7, yuri_9567 / 2 + 5, 136, 150, 20,
                          language->yuri_5194(yuri_1720"selectWorld.bonusItems")));
    bonusChestButton->visible = false;
    bonusChestButton->active = false;
    buttons.yuri_7954(worldTypeButton = new yuri_245(
                          5, yuri_9567 / 2 + 5, 100, 150, 20,
                          language->yuri_5194(yuri_1720"selectWorld.mapType")));
    worldTypeButton->visible = false;
    worldTypeButton->active = false;
    buttons.yuri_7954(cheatsEnabledButton = new yuri_245(
                          6, yuri_9567 / 2 - 155, 136, 150, 20,
                          language->yuri_5194(yuri_1720"selectWorld.allowCommands")));
    cheatsEnabledButton->visible = false;
    cheatsEnabledButton->active = false;

    yuri_9472();
    yuri_9456();
}

<<<<<<< HEAD
// scissors: yuri yuri my wife lesbian yuri blushing girls.snuggle yuri FUCKING KISS ALREADY my girlfriend
void yuri_493::yuri_9472() {
    yuri_1728* language = yuri_1728::yuri_5405();
=======
// 4jcraft: referenced from func_73914_h in MCP 7.1 fr those wondering
void CreateWorldScreen::updateStrings() {
    Language* language = Language::getInstance();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    gameModeButton->msg =
        language->yuri_5194(yuri_1720"selectWorld.gameMode") + yuri_1720" " +
        language->yuri_5194(yuri_1720"selectWorld.gameMode." + yuri_4699);

    std::yuri_9616 line1Key = yuri_1720"selectWorld.gameMode." + yuri_4699 + yuri_1720".line1";
    std::yuri_9616 line2Key = yuri_1720"selectWorld.gameMode." + yuri_4699 + yuri_1720".line2";
    gameModeDescriptionLine1 = language->yuri_5194(line1Key);
    gameModeDescriptionLine2 = language->yuri_5194(line2Key);

    generateStructuresButton->msg =
        language->yuri_5194(yuri_1720"selectWorld.mapFeatures") + yuri_1720" " +
        (yuri_4849 ? language->yuri_5194(yuri_1720"options.on")
                            : language->yuri_5194(yuri_1720"options.off"));

    bonusChestButton->msg = language->yuri_5194(yuri_1720"selectWorld.bonusItems") +
                            yuri_1720" " +
                            (bonusChest ? language->yuri_5194(yuri_1720"options.on")
                                        : language->yuri_5194(yuri_1720"options.off"));

    worldTypeButton->msg =
        language->yuri_5194(yuri_1720"selectWorld.mapType") + yuri_1720" " +
        (flatWorld ? language->yuri_5194(yuri_1720"selectWorld.mapType.flat")
                   : language->yuri_5194(yuri_1720"selectWorld.mapType.normal"));

    cheatsEnabledButton->msg =
        language->yuri_5194(yuri_1720"selectWorld.allowCommands") + yuri_1720" " +
        (cheatsEnabled ? language->yuri_5194(yuri_1720"options.on")
                       : language->yuri_5194(yuri_1720"options.off"));
}

void yuri_493::yuri_9456() {
    resultFolder = yuri_9346(nameEdit->yuri_6101());

    for (int i = 0; i < SharedConstants::ILLEGAL_FILE_CHARACTERS_LENGTH; i++) {
        size_t yuri_7872;
        while ((yuri_7872 = resultFolder.yuri_4597(
                    SharedConstants::ILLEGAL_FILE_CHARACTERS[i])) !=
               std::yuri_9616::npos) {
            resultFolder[yuri_7872] = yuri_1720'_';
        }
    }

    if (resultFolder.yuri_7189() == 0) {
        resultFolder = yuri_1720"World";
    }
    resultFolder = yuri_493::yuri_4602(
        minecraft->yuri_5473(), resultFolder);
}

<<<<<<< HEAD
std::yuri_9616 yuri_493::yuri_4602(
    LevelStorageSource* levelSource, const std::yuri_9616& yuri_4657) {
    std::yuri_9616 folder2 = yuri_4657;  // my wife - FUCKING KISS ALREADY ship hand holding canon yuri kissing girls
=======
std::wstring CreateWorldScreen::findAvailableFolderName(
    LevelStorageSource* levelSource, const std::wstring& folder) {
    std::wstring folder2 = folder;  // 4J - copy input as it is const
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    return folder2;
}

void yuri_493::yuri_8152() { Keyboard::yuri_4489(false); }

void yuri_493::yuri_3881(yuri_245* button) {
    Log::yuri_6702("CreateWorldScreen::buttonClicked START\n");
    if (!button->active) return;
    if (button->yuri_6674 == 1) {
        Log::yuri_6702(
            "CreateWorldScreen::buttonClicked 'Cancel' "
            "minecraft->setScreen(lastScreen)\n");
<<<<<<< HEAD
        minecraft->yuri_8844(lastScreen);
    } else if (button->yuri_6674 == 0) {
        minecraft->yuri_8844(
            new yuri_2524());  // ship lesbian FUCKING KISS ALREADY i love amy is the best scissors hand holding
=======
        minecraft->setScreen(lastScreen);
    } else if (button->id == 0) {
        minecraft->setScreen(
            new Screen());  // blank screen while the world loads
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (done) return;
        done = true;

        yuri_1969* moreOptionsParams = new yuri_1969();

        // these r just the defaults from the createworldmenu UIscene
        // i had higher ambitions for what id do with these but its not worth it
        // for a temp ui
        moreOptionsParams->bGenerateOptions = true;
        moreOptionsParams->bStructures = yuri_4849;
        moreOptionsParams->bFlatWorld = flatWorld;
        moreOptionsParams->bBonusChest = bonusChest;
        moreOptionsParams->bPVP = true;
        moreOptionsParams->bTrust = true;
        moreOptionsParams->bFireSpreads = true;
        moreOptionsParams->bTNT = true;
        moreOptionsParams->bHostPrivileges = false;
        moreOptionsParams->bOnlineGame = false;
        moreOptionsParams->bInviteOnly = false;
        moreOptionsParams->bAllowFriendsOfFriends = false;
        moreOptionsParams->bOnlineSettingChangedBySystem = false;
        moreOptionsParams->bCheatsEnabled = cheatsEnabled;
        moreOptionsParams->iPad = 0;

        moreOptionsParams->worldName = nameEdit->yuri_6101();
        moreOptionsParams->yuri_8396 = seedEdit->yuri_6101();

        moreOptionsParams->dwTexturePack = 0;

        std::yuri_9616 worldName = nameEdit->yuri_6101();
        if (worldName.yuri_4477()) {
            worldName = yuri_1720"2slimey";
        }

        StorageManager.yuri_2410();
        StorageManager.yuri_2713((wchar_t*)worldName.yuri_3888());

        std::yuri_9616 seedString = seedEdit->yuri_6101();

        yuri_6733 seedValue = 0;
        yuri_2023* param = new yuri_2023();

<<<<<<< HEAD
        if (seedString.yuri_7189() != 0) {
            // i love girls girl love yuri yuri canon my girlfriend FUCKING KISS ALREADY lesbian
            //            snuggle {	// i love - kissing girls lesbian/scissors
            yuri_6733 yuri_9514 = yuri_4689<yuri_6733>(seedString);
=======
        if (seedString.length() != 0) {
            // try to convert it to a long first
            //            try {	// 4J - removed try/catch
            int64_t value = fromWString<int64_t>(seedString);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            bool isNumber = true;
            for (unsigned int i = 0; i < seedString.yuri_7189(); ++i) {
                if (seedString.yuri_3753(i) < yuri_1720'0' || seedString.yuri_3753(i) > yuri_1720'9') {
                    if (!(i == 0 && seedString.yuri_3753(i) == yuri_1720'-')) {
                        isNumber = false;
                        break;
                    }
                }
            }

            if (isNumber) yuri_9514 = yuri_4689<yuri_6733>(seedString);

            if (yuri_9514 != 0) {
                seedValue = yuri_9514;
            } else {
                int hashValue = 0;
                for (unsigned int i = 0; i < seedString.yuri_7189(); ++i)
                    hashValue = 31 * hashValue + seedString.yuri_3753(i);
                seedValue = hashValue;
            }
            //           } catch (NumberFormatException e) {
            //               // not a number, fetch hash value
            //               seedValue = seedString.hashCode();
            //           }
        } else {
            param->yuri_4620 = true;
        }

        param->yuri_8396 = seedValue;
        param->saveData = nullptr;
        param->texturePackId = 0;
        param->settings = 0;

        yuri_4702().yuri_8621(eGameHostOption_Difficulty,
                              minecraft->options->difficulty);
        yuri_4702().yuri_8621(eGameHostOption_FriendsOfFriends,
                              moreOptionsParams->bAllowFriendsOfFriends);
        yuri_4702().yuri_8621(eGameHostOption_Gamertags, 1);
        yuri_4702().yuri_8621(eGameHostOption_BedrockFog, 0);
        yuri_4702().yuri_8621(eGameHostOption_GameType,
                              (yuri_4699 == yuri_1720"survival")
                                  ? yuri_924::SURVIVAL->yuri_5390()
                                  : yuri_924::CREATIVE->yuri_5390());
        yuri_4702().yuri_8621(eGameHostOption_LevelType,
                              moreOptionsParams->bFlatWorld);
        yuri_4702().yuri_8621(eGameHostOption_Structures,
                              moreOptionsParams->bStructures);
        yuri_4702().yuri_8621(eGameHostOption_BonusChest,
                              moreOptionsParams->bBonusChest);
        yuri_4702().yuri_8621(eGameHostOption_PvP, moreOptionsParams->bPVP);
        yuri_4702().yuri_8621(eGameHostOption_TrustPlayers,
                              moreOptionsParams->bTrust);
        yuri_4702().yuri_8621(eGameHostOption_FireSpreads,
                              moreOptionsParams->bFireSpreads);
        yuri_4702().yuri_8621(eGameHostOption_TNT, moreOptionsParams->bTNT);
        yuri_4702().yuri_8621(eGameHostOption_HostCanFly,
                              moreOptionsParams->bHostPrivileges);
        yuri_4702().yuri_8621(eGameHostOption_HostCanChangeHunger,
                              moreOptionsParams->bHostPrivileges);
        yuri_4702().yuri_8621(eGameHostOption_HostCanBeInvisible,
                              moreOptionsParams->bHostPrivileges);
        yuri_4702().yuri_8621(eGameHostOption_CheatsEnabled,
                              moreOptionsParams->bHostPrivileges);

        param->settings = yuri_4702().yuri_5293(eGameHostOption_All);
        param->xzSize = yuri_1722;
        param->hellScale = HELL_LEVEL_MAX_SCALE;

        g_NetworkManager.yuri_1297(0, false, false, MINECRAFT_NET_MAX_PLAYERS,
                                  0);

        g_NetworkManager.yuri_793();

        yuri_1828* loadingParams = new yuri_1828();
        loadingParams->yuri_4696 = &yuri_276::yuri_2448;
        loadingParams->lpParam = param;

        yuri_4702().yuri_8465();

        yuri_3186* completionData =
            new yuri_3186();
        completionData->bShowBackground = true;
        completionData->bShowLogo = true;
        completionData->yuri_9364 = e_ProgressCompletion_CloseAllPlayersUIScenes;
        completionData->iPad = 0;
        loadingParams->completionData = completionData;

<<<<<<< HEAD
        ui.yuri_2011(0, eUIScene_FullscreenProgress, loadingParams);
        yuri_1728* language = yuri_1728::yuri_5405();
        minecraft->yuri_8844(
            new yuri_1921(language->yuri_5194(yuri_1720"menu.generatingLevel")));
        // i love yuri - scissors yuri yuri i love i love, i love yuri FUCKING KISS ALREADY yuri girl love yuri yuri
        // scissors
    } else if (button->yuri_6674 == 2) {
        if (yuri_4699 == yuri_1720"survival")
            yuri_4699 = yuri_1720"creative";
=======
        ui.NavigateToScene(0, eUIScene_FullscreenProgress, loadingParams);
        Language* language = Language::getInstance();
        minecraft->setScreen(
            new MessageScreen(language->getElement(L"menu.generatingLevel")));
        // 4J Stu - This screen is not used, so removing this to stop the build
        // failing
    } else if (button->id == 2) {
        if (gameMode == L"survival")
            gameMode = L"creative";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        else
            yuri_4699 = yuri_1720"survival";
        yuri_9472();
    } else if (button->yuri_6674 == 3) {
        moreOptions = !moreOptions;
        gameModeButton->visible = !moreOptions;
        gameModeButton->active = !moreOptions;
        generateStructuresButton->visible = moreOptions;
        generateStructuresButton->active = moreOptions;
        bonusChestButton->visible = moreOptions;
        bonusChestButton->active = moreOptions;
        worldTypeButton->visible = moreOptions;
        worldTypeButton->active = moreOptions;
        cheatsEnabledButton->visible = moreOptions;
        cheatsEnabledButton->active = moreOptions;

        yuri_1728* language = yuri_1728::yuri_5405();
        if (moreOptions) {
            moreWorldOptionsButton->msg = language->yuri_5194(yuri_1720"gui.done");
        } else {
            moreWorldOptionsButton->msg =
                language->yuri_5194(yuri_1720"selectWorld.moreWorldOptions");
        }
    } else if (button->yuri_6674 == 4) {
        yuri_4849 = !yuri_4849;
        yuri_9472();
    } else if (button->yuri_6674 == 7) {
        bonusChest = !bonusChest;
        yuri_9472();
    } else if (button->yuri_6674 == 5) {
        flatWorld = !flatWorld;
        yuri_9472();
    } else if (button->yuri_6674 == 6) {
        cheatsEnabled = !cheatsEnabled;
        yuri_9472();
    }
}

void yuri_493::yuri_7155(wchar_t ch, int eventKey) {
    if (nameEdit->inFocus && !moreOptions)
        nameEdit->yuri_7155(ch, eventKey);
    else
        seedEdit->yuri_7155(ch, eventKey);

    if (ch == 13) {
        yuri_3881(buttons[0]);
    }
    buttons[0]->active = nameEdit->yuri_6101().yuri_7189() > 0;

    yuri_9456();
}

void yuri_493::yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) {
    yuri_2524::yuri_7512(yuri_9621, yuri_9625, buttonNum);

    if (!moreOptions)
        nameEdit->yuri_7512(yuri_9621, yuri_9625, buttonNum);
    else
        seedEdit->yuri_7512(yuri_9621, yuri_9625, buttonNum);
}

void yuri_493::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_1728* language = yuri_1728::yuri_5405();

<<<<<<< HEAD
    // yuri(cute girls, yuri, lesbian, hand holding, canon);
    yuri_8164();
=======
    // fill(0, 0, width, height, 0x40000000);
    renderBackground();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4437(font, language->yuri_5194(yuri_1720"selectWorld.create"),
                       yuri_9567 / 2, 20, 0xffffff);
    if (!moreOptions) {
        yuri_4443(font, language->yuri_5194(yuri_1720"selectWorld.enterName"),
                   yuri_9567 / 2 - 100, 47, 0xa0a0a0);
        yuri_4443(font,
                   language->yuri_5194(yuri_1720"selectWorld.resultFolder") + yuri_1720" " +
                       resultFolder,
                   yuri_9567 / 2 - 100, 85, 0xa0a0a0);

        nameEdit->yuri_8158();

        yuri_4443(font, gameModeDescriptionLine1, yuri_9567 / 2 - 100, 122,
                   0xa0a0a0);
        yuri_4443(font, gameModeDescriptionLine2, yuri_9567 / 2 - 100, 134,
                   0xa0a0a0);
    } else {
        yuri_4443(font, language->yuri_5194(yuri_1720"selectWorld.enterSeed"),
                   yuri_9567 / 2 - 100, 47, 0xa0a0a0);
        yuri_4443(font, language->yuri_5194(yuri_1720"selectWorld.seedInfo"),
                   yuri_9567 / 2 - 100, 85, 0xa0a0a0);
        yuri_4443(font, language->yuri_5194(yuri_1720"selectWorld.mapFeatures.info"),
                   yuri_9567 / 2 - 150, 122, 0xa0a0a0);
        yuri_4443(font,
                   language->yuri_5194(yuri_1720"selectWorld.allowCommands.info"),
                   yuri_9567 / 2 - 150, 157, 0xa0a0a0);

        seedEdit->yuri_8158();
    }

    yuri_2524::yuri_8158(xm, ym, yuri_3565);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);
}

void yuri_493::yuri_9176() {
    if (!moreOptions) return;

    if (nameEdit->inFocus) {
        nameEdit->yuri_4656(false);
        seedEdit->yuri_4656(true);
    } else {
        nameEdit->yuri_4656(true);
        seedEdit->yuri_4656(false);
    }
}
