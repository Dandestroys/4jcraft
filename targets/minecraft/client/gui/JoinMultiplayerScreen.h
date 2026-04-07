#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_682;
class yuri_245;

class yuri_1703 : public yuri_2524 {
private:
    yuri_2524* lastScreen;
    yuri_682* ipEdit;

public:
    yuri_1703(yuri_2524* lastScreen);
    virtual void yuri_9265() override;
    virtual void yuri_6704() override;
    virtual void yuri_8152() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

private:
    virtual int yuri_7796(const std::yuri_9616& yuri_9145, int def);

protected:
    virtual void yuri_7155(wchar_t ch, int eventKey) override;
    virtual void yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};