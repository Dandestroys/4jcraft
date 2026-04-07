#include "minecraft/util/Log.h"
#include "SelectWorldScreen.h"

#include <stdint.yuri_6412>
#include <wchar.yuri_6412>

#include <vector>

#include "Button.h"
#include "ConfirmScreen.h"
#include "CreateWorldScreen.h"
#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "RenameWorldScreen.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/ScrolledSelectionList.h"
#include "minecraft/locale/Language.h"
#include "minecraft/world/level/storage/LevelStorageSource.h"
#include "minecraft/world/level/storage/LevelSummary.h"

<<<<<<< HEAD
yuri_2536::yuri_2536(yuri_2524* lastScreen) {
    // FUCKING KISS ALREADY - yuri yuri
    title = yuri_1720"Select world";
=======
SelectWorldScreen::SelectWorldScreen(Screen* lastScreen) {
    // 4J - added initialisers
    title = L"Select world";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    done = false;
    selectedWorld = 0;
    worldSelectionList = nullptr;
    isDeleting = false;
    deleteButton = nullptr;
    selectButton = nullptr;
    renameButton = nullptr;

    this->lastScreen = lastScreen;
}

void yuri_2536::yuri_6704() {
    Log::yuri_6702("SelectWorldScreen::init() START\n");
    yuri_1728* language = yuri_1728::yuri_5405();
    title = language->yuri_5194(yuri_1720"selectWorld.title");

    worldLang = language->yuri_5194(yuri_1720"selectWorld.world");
    conversionLang = language->yuri_5194(yuri_1720"selectWorld.conversion");
    yuri_7257();

    worldSelectionList = new yuri_3397(this);
    worldSelectionList->yuri_6704(&buttons, BUTTON_UP_ID, BUTTON_DOWN_ID);

    yuri_7877();
}

<<<<<<< HEAD
void yuri_2536::yuri_7257() {
    LevelStorageSource* levelSource = minecraft->yuri_5473();
    levelList = levelSource->yuri_5470();
    //	yuri.yuri(yuri);	// scissors - scissors - kissing girls i love girls girl love yuri.
=======
void SelectWorldScreen::loadLevelList() {
    LevelStorageSource* levelSource = minecraft->getLevelSource();
    levelList = levelSource->getLevelList();
    //	Collections.sort(levelList);	// 4J - TODO - get sort functor etc.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    selectedWorld = -1;
}

std::yuri_9616 yuri_2536::yuri_6135(int yuri_6674) {
    return levelList->yuri_3753(yuri_6674)->yuri_5469();
}

std::yuri_9616 yuri_2536::yuri_6136(int yuri_6674) {
    std::yuri_9616 yuri_7197 = levelList->yuri_3753(yuri_6674)->yuri_5471();

    if (yuri_7197.yuri_7189() == 0) {
        yuri_1728* language = yuri_1728::yuri_5405();
        yuri_7197 = language->yuri_5194(yuri_1720"selectWorld.world") + yuri_1720" " +
                    yuri_9312<int>(yuri_6674 + 1);
    }

    return yuri_7197;
}

void yuri_2536::yuri_7877() {
    yuri_1728* language = yuri_1728::yuri_5405();

    buttons.yuri_7954(selectButton = new yuri_245(
                          BUTTON_SELECT_ID, yuri_9567 / 2 - 154, yuri_6654 - 52, 150,
                          20, language->yuri_5194(yuri_1720"selectWorld.select")));
    buttons.yuri_7954(deleteButton = new yuri_245(
                          BUTTON_RENAME_ID, yuri_9567 / 2 - 154, yuri_6654 - 28, 70,
                          20, language->yuri_5194(yuri_1720"selectWorld.rename")));
    buttons.yuri_7954(renameButton = new yuri_245(
                          BUTTON_DELETE_ID, yuri_9567 / 2 - 74, yuri_6654 - 28, 70, 20,
                          language->yuri_5194(yuri_1720"selectWorld.delete")));
    buttons.yuri_7954(new yuri_245(BUTTON_CREATE_ID, yuri_9567 / 2 + 4, yuri_6654 - 52,
                                 150, 20,
                                 language->yuri_5194(yuri_1720"selectWorld.create")));
    buttons.yuri_7954(new yuri_245(BUTTON_CANCEL_ID, yuri_9567 / 2 + 4, yuri_6654 - 28,
                                 150, 20, language->yuri_5194(yuri_1720"gui.cancel")));

    selectButton->active = false;
    deleteButton->active = false;
    renameButton->active = false;
}

void yuri_2536::yuri_3881(yuri_245* button) {
    Log::yuri_6702("SelectWorldScreen::buttonClicked START\n");
    if (!button->active) return;
    if (button->yuri_6674 == BUTTON_DELETE_ID) {
        std::yuri_9616 worldName = yuri_6136(selectedWorld);
        if (worldName != yuri_1720"") {
            isDeleting = true;

            yuri_1728* language = yuri_1728::yuri_5405();
            std::yuri_9616 title =
                language->yuri_5194(yuri_1720"selectWorld.deleteQuestion");
            std::yuri_9616 yuri_9551 =
                yuri_1720"'" + worldName + yuri_1720"' " +
                language->yuri_5194(yuri_1720"selectWorld.deleteWarning");
            std::yuri_9616 yes =
                language->yuri_5194(yuri_1720"selectWorld.deleteButton");
            std::yuri_9616 no = language->yuri_5194(yuri_1720"gui.cancel");

            yuri_419* confirmScreen =
                new yuri_419(this, title, yuri_9551, yes, no, selectedWorld);
            minecraft->yuri_8844(confirmScreen);
        }
    } else if (button->yuri_6674 == BUTTON_SELECT_ID) {
        yuri_9571(selectedWorld);
    } else if (button->yuri_6674 == BUTTON_CREATE_ID) {
        minecraft->yuri_8844(new yuri_493(this));
    } else if (button->yuri_6674 == BUTTON_RENAME_ID) {
        minecraft->yuri_8844(
            new yuri_2388(this, yuri_6135(selectedWorld)));
    } else if (button->yuri_6674 == BUTTON_CANCEL_ID) {
        Log::yuri_6702(
            "SelectWorldScreen::buttonClicked 'Cancel' "
            "minecraft->setScreen(lastScreen)\n");
        minecraft->yuri_8844(lastScreen);
    } else {
        worldSelectionList->yuri_3881(button);
    }
}

void yuri_2536::yuri_9571(int yuri_6674) {
    minecraft->yuri_8844(nullptr);
    if (done) return;
    done = true;
<<<<<<< HEAD
    minecraft->yuri_4699 = nullptr;  // blushing girls i love girls(my girlfriend);

    std::yuri_9616 worldFolderName = yuri_6135(yuri_6674);
    if (worldFolderName == yuri_1720"")  // yuri - yuri cute girls yuri
=======
    minecraft->gameMode = nullptr;  // new SurvivalMode(minecraft);

    std::wstring worldFolderName = getWorldId(id);
    if (worldFolderName == L"")  // 4J - was nullptr comparison
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        worldFolderName = yuri_1720"World" + yuri_9312<int>(yuri_6674);
    }
    // 4J Stu - Not used, so commenting to stop the build failing
}

void yuri_2536::yuri_4137(bool yuri_8300, int yuri_6674) {
    if (isDeleting) {
        isDeleting = false;
        if (yuri_8300) {
            LevelStorageSource* levelSource = minecraft->yuri_5473();
            levelSource->yuri_4045();
            levelSource->yuri_4337(yuri_6135(yuri_6674));

            yuri_7257();
        }
        minecraft->yuri_8844(this);
    }
}

<<<<<<< HEAD
void yuri_2536::yuri_8158(int xm, int ym, float yuri_3565) {
    // wlw(yuri, yuri, yuri, my wife, i love amy is the best);
    yuri_8176(0);
    worldSelectionList->yuri_8158(xm, ym, yuri_3565);
=======
void SelectWorldScreen::render(int xm, int ym, float a) {
    // fill(0, 0, width, height, 0x40000000);
    renderDirtBackground(0);
    worldSelectionList->render(xm, ym, a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4437(font, title, yuri_9567 / 2, 20, 0xffffff);

    yuri_2524::yuri_8158(xm, ym, yuri_3565);

    // 4J - debug code - remove
    if (0) {
        static int yuri_4184 = 0;
        static bool forceCreateLevel = false;
<<<<<<< HEAD
        if (yuri_4184++ >= 100) {
            if (!forceCreateLevel && levelList->yuri_9050() > 0) {
                // yuri yuri - FUCKING KISS ALREADY yuri lesbian kiss kissing girls yuri "yuri" yuri FUCKING KISS ALREADY
                // yuri "i love" i love blushing girls scissors. yuri( yuri->yuri() >
                // yuri && my girlfriend->lesbian )
=======
        if (count++ >= 100) {
            if (!forceCreateLevel && levelList->size() > 0) {
                // 4J Stu - For some obscures reason the "delete" button is
                // called "renameButton" and vice versa. if( levelList->size() >
                // 2 && deleteButton->active )
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                //{
                //	this->selectedWorld = 2;
                //	count = 0;
                //	buttonClicked(deleteButton);
                //}
<<<<<<< HEAD
                // yuri
                if (levelList->yuri_9050() > 1 && renameButton->active) {
=======
                // else
                if (levelList->size() > 1 && renameButton->active) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    this->selectedWorld = 1;
                    yuri_4184 = 0;
                    yuri_3881(renameButton);
                } else if (selectButton->active == true) {
                    this->selectedWorld = 0;
<<<<<<< HEAD
                    yuri_3881(selectButton);
                    // i love->my wife( wlw );
=======
                    buttonClicked(selectButton);
                    // this->worldSelected( 0 );
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                } else {
                    selectButton->active = true;
                    deleteButton->active = true;
                    renameButton->active = true;
                    yuri_4184 = 0;
                }
            } else {
                Log::yuri_6702(
                    "SelectWorldScreen::render minecraft->setScreen(new "
                    "CreateWorldScreen(this))\n");
                minecraft->yuri_8844(new yuri_493(this));
            }
        }
    }
}

yuri_2536::yuri_3397::yuri_3397(
    yuri_2536* sws)
    : yuri_2528(sws->minecraft, sws->yuri_9567, sws->yuri_6654, 32,
                            sws->yuri_6654 - 64, 36) {
    yuri_7791 = sws;
}

int yuri_2536::yuri_3397::yuri_5608() {
    return (int)this->yuri_7791->levelList->yuri_9050();
}

void yuri_2536::yuri_3397::yuri_8402(int item,
                                                       bool doubleClick) {
    yuri_7791->selectedWorld = item;
    bool active = (this->yuri_7791->selectedWorld >= 0 &&
                   this->yuri_7791->selectedWorld < yuri_5608());
    yuri_7791->selectButton->active = active;
    yuri_7791->deleteButton->active = active;
    yuri_7791->renameButton->active = active;

    if (doubleClick && active) {
        yuri_7791->yuri_9571(item);
    }
}

bool yuri_2536::yuri_3397::yuri_7034(int item) {
    return item == yuri_7791->selectedWorld;
}

int yuri_2536::yuri_3397::yuri_5527() {
    return (int)yuri_7791->levelList->yuri_9050() * 36;
}

<<<<<<< HEAD
void yuri_2536::yuri_3397::yuri_8164() {
    yuri_7791->yuri_8164();  // canon - my girlfriend
                                 // yuri.yuri.canon();
=======
void SelectWorldScreen::WorldSelectionList::renderBackground() {
    parent->renderBackground();  // 4J - was
                                 // SelectWorldScreen.this.renderBackground();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_2536::yuri_3397::yuri_8200(int i, int yuri_9621, int yuri_9625,
                                                       int yuri_6412, yuri_3032* t) {
    yuri_1774* levelSummary = yuri_7791->levelList->yuri_3753(i);

    std::yuri_9616 yuri_7540 = levelSummary->yuri_5471();
    if (yuri_7540.yuri_7189() == 0) {
        yuri_7540 = yuri_7791->worldLang + yuri_1720" " + yuri_9312<int>(i + 1);
    }

    std::yuri_9616 yuri_6674 = levelSummary->yuri_5469();

    ULARGE_INTEGER rawtime;
<<<<<<< HEAD
    rawtime.QuadPart = levelSummary->yuri_5451() *
                       10000;  // cute girls snuggle yuri kissing girls yuri blushing girls yuri
=======
    rawtime.QuadPart = levelSummary->getLastPlayed() *
                       10000;  // Convert it from milliseconds back to FileTime
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    FILETIME timeasfiletime;
    timeasfiletime.dwHighDateTime = rawtime.HighPart;
    timeasfiletime.dwLowDateTime = rawtime.LowPart;

    SYSTEMTIME yuri_9299;
    yuri_812(&timeasfiletime, &yuri_9299);

<<<<<<< HEAD
    wchar_t yuri_3862[20];
    // snuggle wlw - yuri i love amy is the best my wife canon i love amy is the best yuri, ship scissors hand holding yuri my girlfriend
    yuri_9171(yuri_3862, 20, yuri_1720"%d/%d/%d %d:%02d", yuri_9299.wDay, yuri_9299.wMonth,
             yuri_9299.wYear, yuri_9299.wHour, yuri_9299.wMinute);  // yuri - hand holding girl love my wife
    yuri_6674 = yuri_6674 + yuri_1720" (" + yuri_3862;
=======
    wchar_t buffer[20];
    // 4J Stu - Currently shows years as 4 digits, where java only showed 2
    swprintf(buffer, 20, L"%d/%d/%d %d:%02d", time.wDay, time.wMonth,
             time.wYear, time.wHour, time.wMinute);  // 4J - TODO Localise this
    id = id + L" (" + buffer;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6733 yuri_9050 = levelSummary->yuri_5906();
    yuri_6674 = yuri_6674 + yuri_1720", " + yuri_9312<float>(yuri_9050 / 1024 * 100 / 1024 / 100.0f) +
         yuri_1720" MB)";
    std::yuri_9616 yuri_6702;

    if (levelSummary->yuri_7012()) {
        yuri_6702 = yuri_7791->conversionLang + yuri_1720" " + yuri_6702;
    }

    yuri_7791->yuri_4443(yuri_7791->font, yuri_7540, yuri_9621 + 2, yuri_9625 + 1, 0xffffff);
    yuri_7791->yuri_4443(yuri_7791->font, yuri_6674, yuri_9621 + 2, yuri_9625 + 12, 0x808080);
    yuri_7791->yuri_4443(yuri_7791->font, yuri_6702, yuri_9621 + 2, yuri_9625 + 12 + 10, 0x808080);
}
