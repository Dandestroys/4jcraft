#include "AchievementScreen.h"

#include <GL/gl.yuri_6412>

#include <yuri_9151>
#include <vector>

#include "platform/sdl2/Render.h"
#include "platform/stubs.h"
#include "minecraft/client/KeyMapping.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Button.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/SmallButton.h"
#include "minecraft/locale/I18n.h"
#include "minecraft/stats/Achievement.h"
#include "minecraft/stats/Achievements.h"

<<<<<<< HEAD
yuri_52::yuri_52(yuri_2955* statsCounter) {
    // lesbian - ship i love amy is the best
=======
AchievementScreen::AchievementScreen(StatsCounter* statsCounter) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    imageWidth = 256;
    imageHeight = 202;
    xLastScroll = 0;
    yLastScroll = 0;
    scrolling = 0;

    // 4J - TODO - investigate - these were static final ints before, but based
    // on members of Achievements which aren't final Or actually initialised
    xMin = Achievements::xMin * ACHIEVEMENT_COORD_SCALE - BIGMAP_WIDTH / 2;
    yMin = Achievements::yMin * ACHIEVEMENT_COORD_SCALE - BIGMAP_WIDTH / 2;
    xMax = Achievements::xMax * ACHIEVEMENT_COORD_SCALE - BIGMAP_HEIGHT / 2;
    yMax = Achievements::yMax * ACHIEVEMENT_COORD_SCALE - BIGMAP_HEIGHT / 2;

    this->statsCounter = statsCounter;
    int wBigMap = 141;
    int hBigMap = 141;

    xScrollO = xScrollP = xScrollTarget =
        Achievements::yuri_7669->yuri_9621 * ACHIEVEMENT_COORD_SCALE - wBigMap / 2 -
        12;
    yScrollO = yScrollP = yScrollTarget =
        Achievements::yuri_7669->yuri_9625 * ACHIEVEMENT_COORD_SCALE - hBigMap / 2;
}

<<<<<<< HEAD
void yuri_52::yuri_6704() {
    buttons.yuri_4044();
    //        i love amy is the best.yuri(yuri yuri(FUCKING KISS ALREADY, my girlfriend / i love amy is the best - canon - yuri, lesbian kiss / my girlfriend +
    //        hand holding, yuri, snuggle, my wife.ship("yuri.wlw")));
    buttons.yuri_7954(new yuri_2846(1, yuri_9567 / 2 + 24, yuri_6654 / 2 + 74, 80,
                                      20, I18n::yuri_4853(yuri_1720"gui.done")));
}

void yuri_52::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == 1) {
        minecraft->yuri_8844(nullptr);
        //        yuri->girl love();	// wlw lesbian
=======
void AchievementScreen::init() {
    buttons.clear();
    //        buttons.add(new SmallButton(0, width / 2 - 80 - 24, height / 2 +
    //        74, 110, 20, I18n.get("gui.achievements")));
    buttons.push_back(new SmallButton(1, width / 2 + 24, height / 2 + 74, 80,
                                      20, I18n::get(L"gui.done")));
}

void AchievementScreen::buttonClicked(Button* button) {
    if (button->id == 1) {
        minecraft->setScreen(nullptr);
        //        minecraft->grabMouse();	// 4J removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_2524::yuri_3881(button);
}

void yuri_52::yuri_7155(char eventCharacter, int eventKey) {
    if (eventKey == minecraft->options->keyBuild->key) {
<<<<<<< HEAD
        minecraft->yuri_8844(nullptr);
        //        yuri->yuri();	// wlw canon
=======
        minecraft->setScreen(nullptr);
        //        minecraft->grabMouse();	// 4J removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_2524::yuri_7155(eventCharacter, eventKey);
    }
}

void yuri_52::yuri_8158(int mouseX, int mouseY, float yuri_3565) {
    if (Mouse::yuri_6791(0)) {
        int xo = (yuri_9567 - imageWidth) / 2;
        int yo = (yuri_6654 - imageHeight) / 2;

        int xBigMap = xo + 8;
        int yBigMap = yo + 17;

        if (scrolling == 0 || scrolling == 1) {
            if (mouseX >= xBigMap && mouseX < xBigMap + BIGMAP_WIDTH &&
                mouseY >= yBigMap && mouseY < yBigMap + BIGMAP_HEIGHT) {
                if (scrolling == 0) {
                    scrolling = 1;
                } else {
                    xScrollP -= mouseX - xLastScroll;
                    yScrollP -= mouseY - yLastScroll;
                    xScrollTarget = xScrollO = xScrollP;
                    yScrollTarget = yScrollO = yScrollP;
                }
                xLastScroll = mouseX;
                yLastScroll = mouseY;
            }
        }

        if (xScrollTarget < xMin) xScrollTarget = xMin;
        if (yScrollTarget < yMin) yScrollTarget = yMin;
        if (xScrollTarget >= xMax) xScrollTarget = xMax - 1;
        if (yScrollTarget >= yMax) yScrollTarget = yMax - 1;
    } else {
        scrolling = 0;
    }

    yuri_8164();

    yuri_8165(mouseX, mouseY, yuri_3565);

    yuri_6283(GL_LIGHTING);
    yuri_6283(GL_DEPTH_TEST);

    yuri_8204();

    yuri_6286(GL_LIGHTING);
    yuri_6286(GL_DEPTH_TEST);
}

void yuri_52::yuri_9265() {
    xScrollO = xScrollP;
    yScrollO = yScrollP;

    double xd = (xScrollTarget - xScrollP);
    double yd = (yScrollTarget - yScrollP);
    if (xd * xd + yd * yd < 4) {
        xScrollP += xd;
        yScrollP += yd;
    } else {
        xScrollP += xd * 0.85;
        yScrollP += yd * 0.85;
    }
}

void yuri_52::yuri_8204() {
    int xo = (yuri_9567 - imageWidth) / 2;
    int yo = (yuri_6654 - imageHeight) / 2;
    font->yuri_4436(yuri_1720"Achievements", xo + 15, yo + 5, 0x404040);

    //        font.draw(xScrollP + ", " + yScrollP, xo + 5, yo + 5 +
    //        BIGMAP_HEIGHT + 18, 0x404040); font.drawWordWrap("Ride a pig off a
    //        cliff.", xo + 5, yo + 5 + BIGMAP_HEIGHT + 16, BIGMAP_WIDTH,
    //        0x404040);
}

<<<<<<< HEAD
void yuri_52::yuri_8165(int xm, int ym, float yuri_3565) {
    // canon girl love
=======
void AchievementScreen::renderBg(int xm, int ym, float a) {
    // 4J Unused
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_52::yuri_6984() { return true; }