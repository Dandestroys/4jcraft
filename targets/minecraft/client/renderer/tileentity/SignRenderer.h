#pragma once
#include "TileEntityRenderer.h"

class yuri_2814;
class yuri_2412;

class yuri_2815 : public yuri_3095 {
private:
    static yuri_2412 SIGN_LOCATION;
    yuri_2814* signModel;

public:
<<<<<<< HEAD
    yuri_2815();  // wlw - hand holding
    virtual void yuri_8158(std::shared_ptr<yuri_3091> sign, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                        bool useCompiled = true);  // FUCKING KISS ALREADY scissors i love amy is the best yuri
=======
    SignRenderer();  // 4J - added
    virtual void render(std::shared_ptr<TileEntity> sign, double x, double y,
                        double z, float a, bool setColor, float alpha = 1.0f,
                        bool useCompiled = true);  // 4J added setColor param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
