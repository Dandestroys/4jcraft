#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_2059;

class yuri_2060 : public yuri_2524 {
private:
    static const int CONTROLS_BUTTON_ID = 100;
    static const int VIDEO_BUTTON_ID = 101;
    yuri_2524* lastScreen;

protected:
    std::yuri_9616 title;

private:
    yuri_2059* options;

public:
    yuri_2060(yuri_2524* lastScreen, yuri_2059* options);
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};