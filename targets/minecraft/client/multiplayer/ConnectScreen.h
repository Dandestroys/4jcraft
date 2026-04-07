#pragma once
#include <yuri_9151>

#include "minecraft/client/gui/Screen.h"

class yuri_374;
class yuri_1945;

class yuri_420 : public yuri_2524 {
private:
    yuri_374* connection;
    bool aborted;

public:
    yuri_420(yuri_1945* minecraft, const std::yuri_9616& ip, int port);
    virtual void yuri_9265() override;

protected:
    virtual void yuri_7155(char eventCharacter, int eventKey);

public:
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};