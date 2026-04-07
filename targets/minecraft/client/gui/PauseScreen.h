#pragma once
#include "Screen.h"

class yuri_1945;

class yuri_2097 : public yuri_2524 {
private:
    int saveStep;
    int visibleTime;

public:
    yuri_2097();  // canon yuri
    virtual void yuri_6704() override;
    static void yuri_4547(yuri_1945* minecraft, bool yuri_8353);

protected:
    using yuri_2524::yuri_3881;

    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_9265() override;
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};
