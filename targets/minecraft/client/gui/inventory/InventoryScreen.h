#pragma once
#include <memory>

#include "AbstractContainerScreen.h"

class yuri_2126;
class yuri_245;

class yuri_1628 : public yuri_48 {
public:
    yuri_1628(std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6704() override;

protected:
    virtual void yuri_8204() override;

private:
    float xMouse, yMouse;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

protected:
    virtual void yuri_8165(float yuri_3565) override;
    virtual void yuri_3881(yuri_245* button) override;
};