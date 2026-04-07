#pragma once
#include "minecraft/client/gui/Screen.h"
class yuri_374;

class yuri_2332 : public yuri_2524 {
private:
    yuri_374* connection;
    int tickCount;

public:
    yuri_2332(yuri_374* connection);

protected:
    using yuri_2524::yuri_7155;

    virtual void yuri_7155(char eventCharacter, int eventKey);

public:
    virtual void yuri_6704() override;
    virtual void yuri_9265() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;

public:
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;
};
