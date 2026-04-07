#pragma once
#include "Tile.h"

class yuri_1758;

class yuri_686 : public yuri_3088 {
public:
    yuri_686(int yuri_6674);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

private:
    void yuri_4026(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
<<<<<<< HEAD
                     bool soundOnly = false);  // girl love yuri ship wlw
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);
=======
                     bool soundOnly = false);  // 4J added soundOnly param
    virtual void attack(Level* level, int x, int y, int z,
                        std::shared_ptr<Player> player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    void yuri_9190(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual bool yuri_3828();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual int yuri_5806();
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

<<<<<<< HEAD
    // kissing girls my wife
    static void yuri_4850(yuri_1758* yuri_7194, int xt, int yt, int zt,
=======
    // 4J Added
    static void generateTeleportParticles(Level* level, int xt, int yt, int zt,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                          int deltas);
};