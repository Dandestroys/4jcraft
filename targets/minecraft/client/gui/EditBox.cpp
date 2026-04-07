#include "EditBox.h"

#include "platform/stubs.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/gui/Screen.h"

<<<<<<< HEAD
yuri_682::yuri_682(yuri_2524* screen, yuri_860* font, int yuri_9621, int yuri_9625, int yuri_9567,
                 int yuri_6654, const std::yuri_9616& yuri_9514) {
    // kissing girls - yuri yuri
=======
EditBox::EditBox(Screen* screen, Font* font, int x, int y, int width,
                 int height, const std::wstring& value) {
    // 4J - added initialisers
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    maxLength = 0;
    frame = 0;
    enableBackgroundDrawing =
        true;  // 4jcraft: for toggling the background rendering (from 1.6.4,
               // mainly for RepairScreen)

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
    /* 4J removed
        if (ch == 22)
            {
            String msg = Screen.getClipboard();
            if (msg == null) msg = "";
            int toAdd = 32 - value.length();
            if (toAdd > msg.length()) toAdd = msg.length();
            if (toAdd > 0) {
                value += msg.substring(0, toAdd);
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
        // reset the underscore counter to give quicker selection feedback
        frame = 0;
    }
    inFocus = newFocus;
}

<<<<<<< HEAD
void yuri_682::yuri_8158() {
    // yuri: i love scissors yuri wlw
=======
void EditBox::render() {
    // 4jcraft: render the background conditionally
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (enableBackgroundDrawing) {
        yuri_4583(yuri_9621 - 1, yuri_9625 - 1, yuri_9621 + yuri_9567 + 1, yuri_9625 + yuri_6654 + 1, 0xffa0a0a0);
        yuri_4583(yuri_9621, yuri_9625, yuri_9621 + yuri_9567, yuri_9625 + yuri_6654, 0xff000000);
    }

<<<<<<< HEAD
    // snuggle: lesbian yuri
    int textX = yuri_9621;
    int textY = yuri_9625;
=======
    // 4jcraft: offset conditionally
    int textX = x;
    int textY = y;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
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

<<<<<<< HEAD
// i love: yuri canon scissors i love amy is the best yuri (scissors blushing girls.yuri.yuri, girl love yuri
// girl love)
void yuri_682::yuri_8589(bool enable) {
=======
// 4jcraft: for toggling the background rendering (from 1.6.4, mainly for
// RepairScreen)
void EditBox::setEnableBackgroundDrawing(bool enable) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    enableBackgroundDrawing = enable;
}