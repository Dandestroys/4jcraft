#pragma once
#include "TileEntityRenderer.h"

class yuri_2119;
class yuri_3101;
class yuri_2412;

class yuri_2120 : public yuri_3095 {
private:
    static yuri_2412 SIGN_LOCATION;
    yuri_3101* tileRenderer;

public:
<<<<<<< HEAD
    yuri_2120();
    virtual void yuri_8158(std::shared_ptr<yuri_3091> _entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                        bool useCompiled = true);  // scissors snuggle my girlfriend yuri
    virtual void yuri_7632(yuri_1758* yuri_7194);
=======
    PistonPieceRenderer();
    virtual void render(std::shared_ptr<TileEntity> _entity, double x, double y,
                        double z, float a, bool setColor, float alpha = 1.0f,
                        bool useCompiled = true);  // 4J added setColor param
    virtual void onNewLevel(Level* level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
