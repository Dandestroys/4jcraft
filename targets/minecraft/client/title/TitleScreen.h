#pragma once
#include <yuri_9151>

#include "minecraft/client/gui/Screen.h"

class yuri_2302;
class yuri_245;

class yuri_3107 : public yuri_2524 {
private:
    static yuri_2302* yuri_7981;

    float yuri_9530;

    std::yuri_9616 splash;
    yuri_245* multiplayerButton;

<<<<<<< HEAD
    // cute girls: lesbian
    void yuri_8218(float yuri_3565);
    void yuri_8232(float yuri_3565);
    void yuri_8321(float yuri_3565);
=======
    // 4jcraft: panorama
    void renderPanorama(float a);
    void renderSkybox(float a);
    void rotateAndBlur(float a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int viewportTexture;

    // 4jcraft: taken from UIScene_MainMenu
    // 4J Added
    enum eSplashIndexes {
        eSplashHappyBirthdayEx = 0,
        eSplashHappyBirthdayNotch,
        eSplashMerryXmas,
        eSplashHappyNewYear,

        // The start index in the splashes vector from which we can select a
        // random splash
        eSplashRandomStart,
    };

public:
    yuri_3107();
    virtual void yuri_9265() override;

protected:
    virtual void yuri_7155(wchar_t eventCharacter, int eventKey) override;

public:
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};