#pragma once
#include "Screen.h"

class yuri_558 : public yuri_2524 {
public:
    virtual void yuri_6704() override;

protected:
    virtual void yuri_7155(char eventCharacter, int eventKey);
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
    virtual bool yuri_6984() override;
};