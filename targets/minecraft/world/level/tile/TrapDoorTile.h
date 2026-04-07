#pragma once

#include <memory>

#include "Tile.h"

class yuri_2126;
class yuri_1278;
class yuri_1758;
class yuri_1886;

class yuri_3132 : public yuri_3088 {
    friend class yuri_3088;

private:
    static const int TOP_MASK = 0x8;

protected:
    yuri_3132(int yuri_6674, yuri_1886* material);

    /*
     * public int getTexture(int face, int data) { if (face == 0 || face == 1)
     * return tex; int dir = getDir(data); if ((dir == 0 || dir == 2) ^ (face <=
     * 3)) { return tex; } int tt = (dir / 2 + ((face & 1) ^ dir)); tt += ((data
     * & 4) / 4); int texture = tex - (data & 8) * 2; if ((tt & 1) != 0) {
     * texture = -texture; } // if (getDir(data)==0 //
     * tt-=((face+data&3)&1)^((data&4)>>2); return texture; }
     */

public:
    bool yuri_3828();

public:
    bool yuri_7058(bool isServerLevel = false);

public:
    bool yuri_6827();
    bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    int yuri_5806();

public:
    yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    void yuri_9461(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     int forceData = -1,
<<<<<<< HEAD
                     std::shared_ptr<yuri_3091> forceEntity =
                         std::shared_ptr<yuri_3091>());  // wlw ship yuri,
                                                          // snuggle wlw
=======
                     std::shared_ptr<TileEntity> forceEntity =
                         std::shared_ptr<TileEntity>());  // 4J added forceData,
                                                          // forceEntity param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    void yuri_9402();

public:
    using yuri_3088::yuri_8855;
    void yuri_8855(int yuri_4295);

public:
    void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                std::shared_ptr<yuri_2126> yuri_7839);

public:
    virtual bool yuri_3033();
    bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
             int clickedFace, float clickX, float clickY, float clickZ,
             bool soundOnly = false);  // 4J added soundOnly param

public:
    void yuri_8752(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, bool shouldOpen);

public:
    void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);

public:
    yuri_1278* yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565, yuri_3322* yuri_3775);

public:
    int yuri_5159(int yuri_4361);

public:
    int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                                 float clickX, float clickY, float clickZ,
                                 int itemValue);

public:
    bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);

public:
    static bool yuri_6980(int yuri_4295);

private:
    static bool yuri_3760(int yuri_6674);
};
