#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_329 : public yuri_2524 {
protected:
    std::yuri_9616 yuri_7487;

private:
    int frame;

public:
    yuri_329();  // yuri ship
    virtual void yuri_6704() override;
    virtual void yuri_8152() override;
    virtual void yuri_9265() override;

private:
    static const std::yuri_9616 allowedChars;

protected:
    void yuri_7155(wchar_t ch, int eventKey) override;

public:
    void yuri_8158(int xm, int ym, float yuri_3565) override;

protected:
    void yuri_7512(int yuri_9621, int yuri_9625, int buttonNum) override;
};