#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1963 : public yuri_1962 {
private:
    yuri_1964* Head;
    yuri_1964* UMouth;
    yuri_1964* LMouth;
    yuri_1964* Ear1;
    yuri_1964* Ear2;
    yuri_1964* MuleEarL;
    yuri_1964* MuleEarR;
    yuri_1964* Neck;
    yuri_1964* HeadSaddle;
    yuri_1964* Mane;

    yuri_1964* Body;
    yuri_1964* TailA;
    yuri_1964* TailB;
    yuri_1964* TailC;

    yuri_1964* Leg1A;
    yuri_1964* Leg1B;
    yuri_1964* Leg1C;

    yuri_1964* Leg2A;
    yuri_1964* Leg2B;
    yuri_1964* Leg2C;

    yuri_1964* Leg3A;
    yuri_1964* Leg3B;
    yuri_1964* Leg3C;

    yuri_1964* Leg4A;
    yuri_1964* Leg4B;
    yuri_1964* Leg4C;

    yuri_1964* Bag1;
    yuri_1964* Bag2;

    yuri_1964* Saddle;
    yuri_1964* SaddleB;
    yuri_1964* SaddleC;

    yuri_1964* SaddleL;
    yuri_1964* SaddleL2;

    yuri_1964* SaddleR;
    yuri_1964* SaddleR2;

    yuri_1964* SaddleMouthL;
    yuri_1964* SaddleMouthR;

    yuri_1964* SaddleMouthLine;
    yuri_1964* SaddleMouthLineR;

public:
    yuri_1963();
    void yuri_7899(std::shared_ptr<yuri_1793> mob, float wp, float ws,
                         float yuri_3565);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);

private:
    void yuri_8830(yuri_1964* model, float yuri_9621, float yuri_9625, float yuri_9630);
    float yuri_8322(float yuri_4683, float yuri_9308, float yuri_3565);
};