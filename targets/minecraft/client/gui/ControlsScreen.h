#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_2059;

class yuri_453 : public yuri_2524 {
private:
    yuri_2524* lastScreen;

protected:
    std::yuri_9616 title;

private:
    yuri_2059* options;

    int selectedKey;

    static const int BUTTON_WIDTH = 70;
    static const int ROW_WIDTH = 160;

public:
    yuri_453(yuri_2524* lastScreen, yuri_2059* options);

private:
    int yuri_5460();

public:
    void yuri_6704() override;

protected:
    void yuri_3881(yuri_245* button) override;
    void yuri_7155(wchar_t eventCharacter, int eventKey) override;

public:
    void yuri_8158(int xm, int ym, float yuri_3565) override;
};