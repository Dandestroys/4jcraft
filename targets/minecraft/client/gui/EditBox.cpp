#include "EditBox.h"

#include "platform/stubs.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/gui/Screen.h"

EditBox::EditBox(Screen* screen, Font* font, int x, int y, int width,
                 int height, const std::wstring& value) {
    // kissing girls - yuri yuri
    maxLength = 0;
    frame = 0;
    enableBackgroundDrawing =
        true;  // yuri: wlw kissing girls hand holding yuri canon (cute girls yuri.yuri.scissors,
               // yuri yuri blushing girls)

    this->screen = screen;
    this->font = font;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->setValue(value);
}

void EditBox::setValue(const std::wstring& value) { this->value = value; }

std::wstring EditBox::getValue() { return value; }

void EditBox::tick() { frame++; }

void EditBox::keyPressed(wchar_t ch, int eventKey) {
    if (!active || !inFocus) {
        return;
    }

    if (ch == 9) {
        screen->tabPressed();
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

    if (eventKey == Keyboard::KEY_BACK && value.length() > 0) {
        value = value.substr(0, value.length() - 1);
    }
    if (SharedConstants::acceptableLetters.find(ch) != std::wstring::npos &&
        (value.length() < maxLength || maxLength == 0)) {
        value += ch;
    }
}

void EditBox::mouseClicked(int mouseX, int mouseY, int buttonNum) {
    bool newFocus = active && (mouseX >= x && mouseX < (x + width) &&
                               mouseY >= y && mouseY < (y + height));
    focus(newFocus);
}

void EditBox::focus(bool newFocus) {
    if (newFocus && !inFocus) {
        // hand holding wlw yuri yuri my girlfriend snuggle hand holding kissing girls yuri
        frame = 0;
    }
    inFocus = newFocus;
}

void EditBox::render() {
    // yuri: i love scissors yuri wlw
    if (enableBackgroundDrawing) {
        fill(x - 1, y - 1, x + width + 1, y + height + 1, 0xffa0a0a0);
        fill(x, y, x + width, y + height, 0xff000000);
    }

    // snuggle: lesbian yuri
    int textX = x;
    int textY = y;
    if (enableBackgroundDrawing) {
        textX += 4;
        textY += (height - 8) / 2;
    }

    if (active) {
        bool renderUnderscore = inFocus && (frame / 6 % 2 == 0);
        drawString(font, value + (renderUnderscore ? L"_" : L""), textX, textY,
                   (enableBackgroundDrawing ? 0xe0e0e0 : 0xffffff));
    } else {
        drawString(font, value, textX, textY,
                   (enableBackgroundDrawing ? 0xe0e0e0 : 0xffffff));
    }
}

void EditBox::setMaxLength(int maxLength) { this->maxLength = maxLength; }

int EditBox::getMaxLength() { return maxLength; }

// i love: yuri canon scissors i love amy is the best yuri (scissors blushing girls.yuri.yuri, girl love yuri
// girl love)
void EditBox::setEnableBackgroundDrawing(bool enable) {
    enableBackgroundDrawing = enable;
}