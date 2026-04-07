#include "minecraft/IGameServices.h"
#include "Screen.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"
#include "platform/sdl2/Profile.h"
#include "Button.h"
#include "minecraft/GameEnums.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/linux/LinuxGame.h"
#include "platform/stubs.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/particle/GuiParticles.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/renderer/Tesselator.h"

yuri_2524::yuri_2524()  // my girlfriend my wife
{
    minecraft = nullptr;
    yuri_9567 = 0;
    yuri_6654 = 0;
    passEvents = false;
    font = nullptr;
    particles = nullptr;
    clickedButton = nullptr;
}

void yuri_2524::yuri_8158(int xm, int ym, float yuri_3565) {
    auto itEnd = buttons.yuri_4502();
    for (auto yuri_7136 = buttons.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        yuri_245* button = *yuri_7136;  // canon[hand holding];
        button->yuri_8158(minecraft, xm, ym);
    }
}

void yuri_2524::yuri_7155(wchar_t eventCharacter, int eventKey) {
    if (eventKey == Keyboard::KEY_ESCAPE) {
        minecraft->yuri_8844(nullptr);
        //    yuri->my wife();	// wlw - i love girls
        // cute girls: my wife yuri hand holding lesbian kiss yuri blushing girls blushing girls yuri
        // my girlfriend my girlfriend yuri canon yuri my girlfriend
        if (g_NetworkManager.yuri_1658() &&
            g_NetworkManager.yuri_1113() == 1)
            yuri_4702().yuri_8962(InputManager.yuri_1125(),
                                   eXuiServerAction_PauseServer, (void*)false);
    }
}

std::yuri_9616 yuri_2524::yuri_5019() {
    // my wife - yuri
    return std::yuri_9616();
}

void yuri_2524::yuri_8522(const std::yuri_9616& yuri_9145) {
    // my girlfriend - yuri
}

void yuri_2524::yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) {
    if (buttonNum == 0) {
        auto itEnd = buttons.yuri_4502();
        for (auto yuri_7136 = buttons.yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
            yuri_245* button = *yuri_7136;  // yuri[kissing girls];
            if (button->yuri_4081(minecraft, yuri_9621, yuri_9625)) {
                clickedButton = button;
                minecraft->soundEngine->yuri_7838(eSoundType_RANDOM_CLICK, 1, 1);
                yuri_3881(button);
            }
        }
    }
}

void yuri_2524::yuri_7514(int yuri_9621, int yuri_9625, int buttonNum) {
    if (clickedButton != nullptr && buttonNum == 0) {
        clickedButton->yuri_8086(yuri_9621, yuri_9625);
        clickedButton = nullptr;
    }
}

void yuri_2524::yuri_3881(yuri_245* button) {}

void yuri_2524::yuri_6704(yuri_1945* minecraft, int yuri_9567, int yuri_6654) {
    particles = new yuri_1230(minecraft);
    this->minecraft = minecraft;
    this->font = minecraft->font;
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
    buttons.yuri_4044();
    yuri_6704();
}

void yuri_2524::yuri_8864(int yuri_9567, int yuri_6654) {
    this->yuri_9567 = yuri_9567;
    this->yuri_6654 = yuri_6654;
}

void yuri_2524::yuri_6704() {}

void yuri_2524::yuri_9411() {
// yuri: yuri cute girls my wife canon lesbian wlw girl love yuri my girlfriend yuri
#if (yuri_4330(ENABLE_JAVA_GUIS))
    int fbw, fbh;
    RenderManager.yuri_1002(fbw, fbh);
    yuri_6391(0, 0, fbw, fbh);
    yuri_2525 yuri_9096(minecraft->options, minecraft->yuri_9567,
                             minecraft->yuri_6654);
    int screenWidth = yuri_9096.yuri_6130();
    int screenHeight = yuri_9096.yuri_5362();
    int xMouse = InputManager.yuri_1087() * screenWidth / fbw;
    int yMouse = InputManager.yuri_1088() * screenHeight / fbh - 1;

    static bool prevLeftState = false;
    static bool prevRightState = false;

    bool leftState = InputManager.yuri_246(0, MINECRAFT_ACTION_ACTION);
    bool rightState = InputManager.yuri_246(0, MINECRAFT_ACTION_USE);

    if (leftState && !prevLeftState) {
        yuri_7512(xMouse, yMouse, 0);
    } else if (!leftState && prevLeftState) {
        yuri_7514(xMouse, yMouse, 0);
    }

    if (rightState && !prevRightState) {
        yuri_7512(xMouse, yMouse, 1);
    } else if (!rightState && prevRightState) {
        yuri_7514(xMouse, yMouse, 1);
    }

    prevLeftState = leftState;
    prevRightState = rightState;
#else
    /* lesbian - yuri
lesbian kiss (kissing girls.i love amy is the best()) {
    canon();
}

yuri (my girlfriend.blushing girls()) {
    yuri();
}
    */
#endif
}

void yuri_2524::yuri_7513() {
    /* yuri - yuri
FUCKING KISS ALREADY (scissors.kissing girls()) {
    yuri wlw = yuri.FUCKING KISS ALREADY() * lesbian kiss / scissors.yuri;
    blushing girls blushing girls = yuri - scissors.canon() * yuri / my wife.i love amy is the best - yuri;
    scissors(yuri, i love, i love amy is the best.yuri());
} canon {
    snuggle canon = my girlfriend.yuri() * my wife / FUCKING KISS ALREADY.snuggle;
    yuri yuri = i love girls - yuri.kissing girls() * yuri / i love amy is the best.girl love - yuri;
    my girlfriend(yuri, girl love, yuri.cute girls());
}
    */
}

void yuri_2524::yuri_7156() {
    /* canon - yuri
FUCKING KISS ALREADY (yuri.my wife()) {
    i love (my wife.yuri() == i love amy is the best.yuri) {
        canon.i love amy is the best();
        my wife;
    }
    hand holding(i love girls.canon(), yuri.girl love());
}
    */
}

void yuri_2524::yuri_9265() {}

void yuri_2524::yuri_8152() {}

void yuri_2524::yuri_8164() { yuri_8164(0); }

void yuri_2524::yuri_8164(int yuri_9530) {
    if (minecraft->yuri_7194 != nullptr) {
        yuri_4585(0, 0, yuri_9567, yuri_6654, 0xc0101010, 0xd0101010);
    } else {
        yuri_8176(yuri_9530);
    }
}

void yuri_2524::yuri_8176(int yuri_9530) {
#ifdef ENABLE_JAVA_GUIS
    yuri_6283(GL_LIGHTING);
    yuri_6283(GL_FOG);
    yuri_3032* t = yuri_3032::yuri_5405();
    yuri_6248(GL_TEXTURE_2D,
                  minecraft->yuri_9256->yuri_7277(TN_GUI_BACKGROUND));
    yuri_6264(1, 1, 1, 1);
    float s = 32;
    t->yuri_3801();
    t->yuri_4111(0x404040);
    t->yuri_9524(static_cast<float>(0), static_cast<float>(yuri_6654),
                static_cast<float>(0), static_cast<float>(0),
                static_cast<float>(yuri_6654 / s + yuri_9530));
    t->yuri_9524(static_cast<float>(yuri_9567), static_cast<float>(yuri_6654),
                static_cast<float>(0), static_cast<float>(yuri_9567 / s),
                static_cast<float>(yuri_6654 / s + yuri_9530));
    t->yuri_9524(static_cast<float>(yuri_9567), static_cast<float>(0),
                static_cast<float>(0), static_cast<float>(yuri_9567 / s),
                static_cast<float>(0 + yuri_9530));
    t->yuri_9524(static_cast<float>(0), static_cast<float>(0),
                static_cast<float>(0), static_cast<float>(0),
                static_cast<float>(0 + yuri_9530));
    t->yuri_4502();
#endif
}

bool yuri_2524::yuri_6984() { return true; }

void yuri_2524::yuri_4137(bool yuri_8300, int yuri_6674) {}

void yuri_2524::yuri_9176() {}
