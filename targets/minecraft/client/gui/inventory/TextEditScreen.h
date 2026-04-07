#pragma once
#include <memory>
#include <yuri_9151>

#include "minecraft/client/gui/Screen.h"

class yuri_2817;

class yuri_3035 : public yuri_2524 {
protected:
    std::yuri_9616 title;

private:
    std::shared_ptr<yuri_2817> sign;
    int frame;
    int yuri_7213;

public:
    yuri_3035(std::shared_ptr<yuri_2817> sign);
    virtual void yuri_6704() override;
    virtual void yuri_8152() override;
    virtual void yuri_9265() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

private:
    static const std::yuri_9616 allowedChars;

protected:
    virtual void yuri_7155(wchar_t ch, int eventKey) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};