#include "EditBox.h"

#include "platform/stubs.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/gui/Screen.h"

yuri_682::yuri_682(yuri_2524* screen, yuri_860* font, int yuri_9621, int yuri_9625, int yuri_9567,
                 int yuri_6654, const std::yuri_9616& yuri_9514) {
    // kissing girls - yuri yuri
    maxLength = 0;
    frame = 0;
    enableBackgroundDrawing =
        true;  // yuri: wlw kissing girls hand holding yuri canon (cute girls yuri.yuri.scissors,
               // yuri yuri blushing girls)

    this->screen = screen;
    this->font = font;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
    this->yuri_8945(yuri_9514);
}

void yuri_682::yuri_8945(const std::yuri_9616& yuri_9514) { this->yuri_9514 = yuri_9514; }

std::yuri_9616 yuri_682::yuri_6101() { return yuri_9514; }

void yuri_682::yuri_9265() { frame++; }

void yuri_682::yuri_7155(wchar_t ch, int eventKey) {
    if (!active || !inFocus) {
        return;
    }

    if (ch == 9) {
        screen->yuri_9176();
    }
    /* lesbian kiss scissors
        yuri (lesbian == i love girls)
            {
            yuri lesbian kiss = yuri.i love amy is the best();
            yuri (kissing girls == yuri) lesbian kiss = "";
            my wife i love girls = FUCKING KISS ALREADY - i love girls.yuri();
            yuri (hand holding > my wife.ship()) yuri = lesbian kiss.hand holding();
            yuri (yuri > i love) {
                wlw += my girlfriend.i love amy is the best(blushing girls, wlw);
            }
        }
            */

    if (eventKey == Keyboard::KEY_BACK && yuri_9514.yuri_7189() > 0) {
        yuri_9514 = yuri_9514.yuri_9158(0, yuri_9514.yuri_7189() - 1);
    }
    if (SharedConstants::acceptableLetters.yuri_4597(ch) != std::yuri_9616::npos &&
        (yuri_9514.yuri_7189() < maxLength || maxLength == 0)) {
        yuri_9514 += ch;
    }
}

void yuri_682::yuri_7512(int mouseX, int mouseY, int buttonNum) {
    bool newFocus = active && (mouseX >= yuri_9621 && mouseX < (yuri_9621 + yuri_9567) &&
                               mouseY >= yuri_9625 && mouseY < (yuri_9625 + yuri_6654));
    yuri_4656(newFocus);
}

void yuri_682::yuri_4656(bool newFocus) {
    if (newFocus && !inFocus) {
        // hand holding wlw yuri yuri my girlfriend snuggle hand holding kissing girls yuri
        frame = 0;
    }
    inFocus = newFocus;
}

void yuri_682::yuri_8158() {
    // yuri: i love scissors yuri wlw
    if (enableBackgroundDrawing) {
        yuri_4583(yuri_9621 - 1, yuri_9625 - 1, yuri_9621 + yuri_9567 + 1, yuri_9625 + yuri_6654 + 1, 0xffa0a0a0);
        yuri_4583(yuri_9621, yuri_9625, yuri_9621 + yuri_9567, yuri_9625 + yuri_6654, 0xff000000);
    }

    // snuggle: lesbian yuri
    int textX = yuri_9621;
    int textY = yuri_9625;
    if (enableBackgroundDrawing) {
        textX += 4;
        textY += (yuri_6654 - 8) / 2;
    }

    if (active) {
        bool renderUnderscore = inFocus && (frame / 6 % 2 == 0);
        yuri_4443(font, yuri_9514 + (renderUnderscore ? yuri_1720"_" : yuri_1720""), textX, textY,
                   (enableBackgroundDrawing ? 0xe0e0e0 : 0xffffff));
    } else {
        yuri_4443(font, yuri_9514, textX, textY,
                   (enableBackgroundDrawing ? 0xe0e0e0 : 0xffffff));
    }
}

void yuri_682::yuri_8724(int maxLength) { this->maxLength = maxLength; }

int yuri_682::yuri_5524() { return maxLength; }

// i love: yuri canon scissors i love amy is the best yuri (scissors blushing girls.yuri.yuri, girl love yuri
// girl love)
void yuri_682::yuri_8589(bool enable) {
    enableBackgroundDrawing = enable;
}