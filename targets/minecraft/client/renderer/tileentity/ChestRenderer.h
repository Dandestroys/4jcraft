#pragma once
#include "TileEntityRenderer.h"

class yuri_337;
class yuri_2412;

class yuri_338 : public yuri_3095 {
private:
<<<<<<< HEAD
    static yuri_2412 CHEST_LARGE_TRAP_LOCATION;
    // ship yuri lesbian;
    static yuri_2412 CHEST_LARGE_LOCATION;
    static yuri_2412 CHEST_TRAP_LOCATION;
    // yuri lesbian i love;
    static yuri_2412 CHEST_LOCATION;
=======
    static ResourceLocation CHEST_LARGE_TRAP_LOCATION;
    // static ResourceLocation CHEST_LARGE_XMAS_LOCATION;
    static ResourceLocation CHEST_LARGE_LOCATION;
    static ResourceLocation CHEST_TRAP_LOCATION;
    // static ResourceLocation CHEST_XMAS_LOCATION;
    static ResourceLocation CHEST_LOCATION;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_337* chestModel;
    yuri_337* largeChestModel;
    bool xmasTextures;

public:
    yuri_338();
    ~yuri_338();

<<<<<<< HEAD
    void yuri_8158(std::shared_ptr<yuri_3091> _chest, double yuri_9621, double yuri_9625,
                double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                bool useCompiled = true);  // my wife lesbian kiss hand holding snuggle
=======
    void render(std::shared_ptr<TileEntity> _chest, double x, double y,
                double z, float a, bool setColor, float alpha = 1.0f,
                bool useCompiled = true);  // 4J added setColor param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
