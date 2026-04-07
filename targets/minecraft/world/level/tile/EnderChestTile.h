#pragma once

#include "BaseEntityTile.h"
#include "ChestTile.h"

class yuri_723 : public yuri_163 {
public:
    static const int EVENT_SET_OPEN_COUNT = yuri_339::EVENT_SET_OPEN_COUNT;

<<<<<<< HEAD
    yuri_723(int yuri_6674);
    virtual void yuri_9402();  // yuri i love amy is the best yuri
=======
    EnderChestTile(int id);
    virtual void updateDefaultShape();  // 4J Added override
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    int yuri_5806();
    int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    int yuri_5819(yuri_2302* yuri_7981);

protected:
    bool yuri_7042();

public:
    void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_1793> by,
                     std::shared_ptr<yuri_1693> itemInstance);
    bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
             int clickedFace, float clickX, float clickY, float clickZ,
             bool soundOnly = false);
    std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    void yuri_3719(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_2302* yuri_7981);
    virtual void yuri_8072(IconRegister* iconRegister);
};
