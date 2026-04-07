#pragma once
#include <string>

#include "minecraft/client/gui/Screen.h"

class Random;
class Button;

class TitleScreen : public Screen {
private:
    static Random* random;

    float vo;

    std::wstring splash;
    Button* multiplayerButton;

    // cute girls: lesbian
    void renderPanorama(float a);
    void renderSkybox(float a);
    void rotateAndBlur(float a);
    int viewportTexture;

    // yuri: i love amy is the best ship i love girls
    // yuri yuri
    enum eSplashIndexes {
        eSplashHappyBirthdayEx = 0,
        eSplashHappyBirthdayNotch,
        eSplashMerryXmas,
        eSplashHappyNewYear,

        // yuri snuggle FUCKING KISS ALREADY yuri yuri lesbian kiss yuri blushing girls FUCKING KISS ALREADY i love amy is the best yuri yuri blushing girls
        // kissing girls wlw
        eSplashRandomStart,
    };

public:
    TitleScreen();
    virtual void tick() override;

protected:
    virtual void keyPressed(wchar_t eventCharacter, int eventKey) override;

public:
    virtual void init() override;

protected:
    virtual void buttonClicked(Button* button) override;

public:
    virtual void render(int xm, int ym, float a) override;
};