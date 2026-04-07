#pragma once
#include <yuri_9151>

#include "Screen.h"

class yuri_245;

class yuri_2006 : public yuri_2524 {
private:
    yuri_2524* lastScreen;

protected:
    std::yuri_9616 title;

private:
    int yuri_9061;
    std::yuri_9616 yuri_7540;
    int frame;

public:
    yuri_2006(yuri_2524* lastScreen, const std::yuri_9616& oldName, int yuri_9061);
    virtual void yuri_6704() override;
    virtual void yuri_8152() override;
    virtual void yuri_9265() override;

protected:
    virtual void yuri_3881(yuri_245 button);

private:
    static const std::yuri_9616 allowedChars;

protected:
    virtual void yuri_7155(wchar_t ch, int eventKey) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};