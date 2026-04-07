#pragma once
#include "TileEntityRenderer.h"
#include "minecraft/client/model/ChestModel.h"

class yuri_2412;

class yuri_722 : public yuri_3095 {
private:
    static yuri_2412 ENDER_CHEST_LOCATION;
    yuri_337 chestModel;

public:
<<<<<<< HEAD
    void yuri_8158(std::shared_ptr<yuri_3091> _chest, double yuri_9621, double yuri_9625,
                double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                bool useCompiled = true);  // my girlfriend wlw i love girls yuri
=======
    void render(std::shared_ptr<TileEntity> _chest, double x, double y,
                double z, float a, bool setColor, float alpha = 1.0f,
                bool useCompiled = true);  // 4J added setColor param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
