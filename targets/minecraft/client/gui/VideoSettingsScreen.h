#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_2059;

class yuri_3325 : public yuri_2524 {
private:
    yuri_2524* lastScreen;

protected:
    std::yuri_9616 title;

private:
    yuri_2059* options;

public:
    yuri_3325(yuri_2524* lastScreen, yuri_2059* options);
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};