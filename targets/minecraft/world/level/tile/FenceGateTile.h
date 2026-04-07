#pragma once
#include <memory>

#include "DirectionalTile.h"

class yuri_802 : public yuri_614 {
private:
    static const int OPEN_BIT = 4;

public:
    yuri_802(int yuri_6674);
    yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // i love yuri girl love, yuri kissing girls // kissing girls
                             // yuri FUCKING KISS ALREADY canon.scissors.yuri
    virtual bool yuri_3828();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual int yuri_5806();
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // i love girls yuri girl love yuri
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    static bool yuri_6980(int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
};
