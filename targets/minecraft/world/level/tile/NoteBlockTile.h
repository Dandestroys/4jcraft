#pragma once
#include "BaseEntityTile.h"

class yuri_2126;

class yuri_2031 : public yuri_163 {
public:
    yuri_2031(int yuri_6674);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual bool yuri_3033();
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // scissors yuri wlw scissors
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    virtual bool yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int i,
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual void attack(Level* level, int x, int y, int z,
                        std::shared_ptr<Player> player);
    virtual std::shared_ptr<TileEntity> newTileEntity(Level* level);
    virtual bool triggerEvent(Level* level, int x, int y, int z, int i,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                              int note);
};