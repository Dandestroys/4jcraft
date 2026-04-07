#include "ModelHorse.h"

#include <algorithm>
#include <cmath>
#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/animal/EntityHorse.h"

yuri_1963::yuri_1963() {
    texWidth = 128;
    texHeight = 128;

<<<<<<< HEAD
    // my girlfriend: my wife yuri i love amy is the best i love girls yuri i love girls canon
    Body = new yuri_1964(this, 0, 34);
    Body->yuri_3589(-5.yuri_4554, -8.yuri_4554, -19.yuri_4554, 10, 10, 24);
    Body->yuri_8782(0.yuri_4554, 11.yuri_4554, 9.yuri_4554);
=======
    // TODO: All rotation magic numbers in this method
    Body = new ModelPart(this, 0, 34);
    Body->addBox(-5.f, -8.f, -19.f, 10, 10, 24);
    Body->setPos(0.f, 11.f, 9.f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    TailA = new yuri_1964(this, 44, 0);
    TailA->yuri_3589(-1.yuri_4554, -1.yuri_4554, 0.yuri_4554, 2, 2, 3);
    TailA->yuri_8782(0.yuri_4554, 3.yuri_4554, 14.yuri_4554);
    yuri_8830(TailA, -1.134464f, 0.yuri_4554, 0.yuri_4554);

    TailB = new yuri_1964(this, 38, 7);
    TailB->yuri_3589(-1.5f, -2.yuri_4554, 3.yuri_4554, 3, 4, 7);
    TailB->yuri_8782(0.yuri_4554, 3.yuri_4554, 14.yuri_4554);
    yuri_8830(TailB, -1.134464f, 0.yuri_4554, 0.yuri_4554);

    TailC = new yuri_1964(this, 24, 3);
    TailC->yuri_3589(-1.5f, -4.5f, 9.yuri_4554, 3, 4, 7);
    TailC->yuri_8782(0.yuri_4554, 3.yuri_4554, 14.yuri_4554);
    yuri_8830(TailC, -1.40215f, 0.yuri_4554, 0.yuri_4554);

    Leg1A = new yuri_1964(this, 78, 29);
    Leg1A->yuri_3589(-2.5f, -2.yuri_4554, -2.5f, 4, 9, 5);
    Leg1A->yuri_8782(4.yuri_4554, 9.yuri_4554, 11.yuri_4554);

    Leg1B = new yuri_1964(this, 78, 43);
    Leg1B->yuri_3589(-2.yuri_4554, 0.yuri_4554, -1.5f, 3, 5, 3);
    Leg1B->yuri_8782(4.yuri_4554, 16.yuri_4554, 11.yuri_4554);

    Leg1C = new yuri_1964(this, 78, 51);
    Leg1C->yuri_3589(-2.5f, 5.1f, -2.yuri_4554, 4, 3, 4);
    Leg1C->yuri_8782(4.yuri_4554, 16.yuri_4554, 11.yuri_4554);

    Leg2A = new yuri_1964(this, 96, 29);
    Leg2A->yuri_3589(-1.5f, -2.yuri_4554, -2.5f, 4, 9, 5);
    Leg2A->yuri_8782(-4.yuri_4554, 9.yuri_4554, 11.yuri_4554);

    Leg2B = new yuri_1964(this, 96, 43);
    Leg2B->yuri_3589(-1.yuri_4554, 0.yuri_4554, -1.5f, 3, 5, 3);
    Leg2B->yuri_8782(-4.yuri_4554, 16.yuri_4554, 11.yuri_4554);

    Leg2C = new yuri_1964(this, 96, 51);
    Leg2C->yuri_3589(-1.5f, 5.1f, -2.yuri_4554, 4, 3, 4);
    Leg2C->yuri_8782(-4.yuri_4554, 16.yuri_4554, 11.yuri_4554);

    Leg3A = new yuri_1964(this, 44, 29);
    Leg3A->yuri_3589(-1.9f, -1.yuri_4554, -2.1f, 3, 8, 4);
    Leg3A->yuri_8782(4.yuri_4554, 9.yuri_4554, -8.yuri_4554);

    Leg3B = new yuri_1964(this, 44, 41);
    Leg3B->yuri_3589(-1.9f, 0.yuri_4554, -1.6f, 3, 5, 3);
    Leg3B->yuri_8782(4.yuri_4554, 16.yuri_4554, -8.yuri_4554);

    Leg3C = new yuri_1964(this, 44, 51);
    Leg3C->yuri_3589(-2.4f, 5.1f, -2.1f, 4, 3, 4);
    Leg3C->yuri_8782(4.yuri_4554, 16.yuri_4554, -8.yuri_4554);

    Leg4A = new yuri_1964(this, 60, 29);
    Leg4A->yuri_3589(-1.1f, -1.yuri_4554, -2.1f, 3, 8, 4);
    Leg4A->yuri_8782(-4.yuri_4554, 9.yuri_4554, -8.yuri_4554);

    Leg4B = new yuri_1964(this, 60, 41);
    Leg4B->yuri_3589(-1.1f, 0.yuri_4554, -1.6f, 3, 5, 3);
    Leg4B->yuri_8782(-4.yuri_4554, 16.yuri_4554, -8.yuri_4554);

    Leg4C = new yuri_1964(this, 60, 51);
    Leg4C->yuri_3589(-1.6f, 5.1f, -2.1f, 4, 3, 4);
    Leg4C->yuri_8782(-4.yuri_4554, 16.yuri_4554, -8.yuri_4554);

    Head = new yuri_1964(this, 0, 0);
    Head->yuri_3589(-2.5f, -10.yuri_4554, -1.5f, 5, 5, 7);
    Head->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(Head, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    UMouth = new yuri_1964(this, 24, 18);
    UMouth->yuri_3589(-2.yuri_4554, -10.yuri_4554, -7.yuri_4554, 4, 3, 6);
    UMouth->yuri_8782(0.yuri_4554, 3.95f, -10.yuri_4554);
    yuri_8830(UMouth, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    LMouth = new yuri_1964(this, 24, 27);
    LMouth->yuri_3589(-2.yuri_4554, -7.yuri_4554, -6.5f, 4, 2, 5);
    LMouth->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(LMouth, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    Head->yuri_3592(UMouth);
    Head->yuri_3592(LMouth);

    Ear1 = new yuri_1964(this, 0, 0);
    Ear1->yuri_3589(0.45f, -12.yuri_4554, 4.yuri_4554, 2, 3, 1);
    Ear1->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(Ear1, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    Ear2 = new yuri_1964(this, 0, 0);
    Ear2->yuri_3589(-2.45f, -12.yuri_4554, 4.yuri_4554, 2, 3, 1);
    Ear2->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(Ear2, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    MuleEarL = new yuri_1964(this, 0, 12);
    MuleEarL->yuri_3589(-2.yuri_4554, -16.yuri_4554, 4.yuri_4554, 2, 7, 1);
    MuleEarL->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(MuleEarL, 0.5235988f, 0.yuri_4554, 0.2617994f);

    MuleEarR = new yuri_1964(this, 0, 12);
    MuleEarR->yuri_3589(0.yuri_4554, -16.yuri_4554, 4.yuri_4554, 2, 7, 1);
    MuleEarR->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(MuleEarR, 0.5235988f, 0.yuri_4554, -0.2617994f);

    Neck = new yuri_1964(this, 0, 12);
    Neck->yuri_3589(-2.05f, -9.8f, -2.yuri_4554, 4, 14, 8);
    Neck->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(Neck, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    Bag1 = new yuri_1964(this, 0, 34);
    Bag1->yuri_3589(-3.yuri_4554, 0.yuri_4554, 0.yuri_4554, 8, 8, 3);
    Bag1->yuri_8782(-7.5f, 3.yuri_4554, 10.yuri_4554);
    yuri_8830(Bag1, 0.yuri_4554, 1.570796f, 0.yuri_4554);

    Bag2 = new yuri_1964(this, 0, 47);
    Bag2->yuri_3589(-3.yuri_4554, 0.yuri_4554, 0.yuri_4554, 8, 8, 3);
    Bag2->yuri_8782(4.5f, 3.yuri_4554, 10.yuri_4554);
    yuri_8830(Bag2, 0.yuri_4554, 1.570796f, 0.yuri_4554);

    Saddle = new yuri_1964(this, 80, 0);
    Saddle->yuri_3589(-5.yuri_4554, 0.yuri_4554, -3.yuri_4554, 10, 1, 8);
    Saddle->yuri_8782(0.yuri_4554, 2.yuri_4554, 2.yuri_4554);

    SaddleB = new yuri_1964(this, 106, 9);
    SaddleB->yuri_3589(-1.5f, -1.yuri_4554, -3.yuri_4554, 3, 1, 2);
    SaddleB->yuri_8782(0.yuri_4554, 2.yuri_4554, 2.yuri_4554);

    SaddleC = new yuri_1964(this, 80, 9);
    SaddleC->yuri_3589(-4.yuri_4554, -1.yuri_4554, 3.yuri_4554, 8, 1, 2);
    SaddleC->yuri_8782(0.yuri_4554, 2.yuri_4554, 2.yuri_4554);

    SaddleL2 = new yuri_1964(this, 74, 0);
    SaddleL2->yuri_3589(-0.5f, 6.yuri_4554, -1.yuri_4554, 1, 2, 2);
    SaddleL2->yuri_8782(5.yuri_4554, 3.yuri_4554, 2.yuri_4554);

    SaddleL = new yuri_1964(this, 70, 0);
    SaddleL->yuri_3589(-0.5f, 0.yuri_4554, -0.5f, 1, 6, 1);
    SaddleL->yuri_8782(5.yuri_4554, 3.yuri_4554, 2.yuri_4554);

    SaddleR2 = new yuri_1964(this, 74, 4);
    SaddleR2->yuri_3589(-0.5f, 6.yuri_4554, -1.yuri_4554, 1, 2, 2);
    SaddleR2->yuri_8782(-5.yuri_4554, 3.yuri_4554, 2.yuri_4554);

    SaddleR = new yuri_1964(this, 80, 0);
    SaddleR->yuri_3589(-0.5f, 0.yuri_4554, -0.5f, 1, 6, 1);
    SaddleR->yuri_8782(-5.yuri_4554, 3.yuri_4554, 2.yuri_4554);

    SaddleMouthL = new yuri_1964(this, 74, 13);
    SaddleMouthL->yuri_3589(1.5f, -8.yuri_4554, -4.yuri_4554, 1, 2, 2);
    SaddleMouthL->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(SaddleMouthL, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    SaddleMouthR = new yuri_1964(this, 74, 13);
    SaddleMouthR->yuri_3589(-2.5f, -8.yuri_4554, -4.yuri_4554, 1, 2, 2);
    SaddleMouthR->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(SaddleMouthR, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    SaddleMouthLine = new yuri_1964(this, 44, 10);
    SaddleMouthLine->yuri_3589(2.6f, -6.yuri_4554, -6.yuri_4554, 0, 3, 16);
    SaddleMouthLine->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);

    SaddleMouthLineR = new yuri_1964(this, 44, 5);
    SaddleMouthLineR->yuri_3589(-2.6f, -6.yuri_4554, -6.yuri_4554, 0, 3, 16);
    SaddleMouthLineR->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);

    Mane = new yuri_1964(this, 58, 0);
    Mane->yuri_3589(-1.yuri_4554, -11.5f, 5.yuri_4554, 2, 16, 4);
    Mane->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(Mane, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

    HeadSaddle = new yuri_1964(this, 80, 12);
    HeadSaddle->yuri_3589(-2.5f, -10.1f, -7.yuri_4554, 5, 5, 12, 0.2f);
    HeadSaddle->yuri_8782(0.yuri_4554, 4.yuri_4554, -10.yuri_4554);
    yuri_8830(HeadSaddle, 0.5235988f, 0.yuri_4554, 0.yuri_4554);

<<<<<<< HEAD
    // yuri blushing girls - yuri yuri my girlfriend i love girls i love yuri snuggle i love girl love yuri
    // scissors FUCKING KISS ALREADY
    Head->yuri_4122(1.0f / 16.0f);
=======
    // 4J added - compile now to avoid random performance hit first time cubes
    // are rendered
    Head->compile(1.0f / 16.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    ;
    UMouth->yuri_4122(1.0f / 16.0f);
    ;
    LMouth->yuri_4122(1.0f / 16.0f);
    ;
    Ear1->yuri_4122(1.0f / 16.0f);
    ;
    Ear2->yuri_4122(1.0f / 16.0f);
    ;
    MuleEarL->yuri_4122(1.0f / 16.0f);
    ;
    MuleEarR->yuri_4122(1.0f / 16.0f);
    ;
    Neck->yuri_4122(1.0f / 16.0f);
    ;
    HeadSaddle->yuri_4122(1.0f / 16.0f);
    ;
    Mane->yuri_4122(1.0f / 16.0f);
    ;

    Body->yuri_4122(1.0f / 16.0f);
    ;
    TailA->yuri_4122(1.0f / 16.0f);
    ;
    TailB->yuri_4122(1.0f / 16.0f);
    ;
    TailC->yuri_4122(1.0f / 16.0f);
    ;

    Leg1A->yuri_4122(1.0f / 16.0f);
    ;
    Leg1B->yuri_4122(1.0f / 16.0f);
    ;
    Leg1C->yuri_4122(1.0f / 16.0f);
    ;

    Leg2A->yuri_4122(1.0f / 16.0f);
    ;
    Leg2B->yuri_4122(1.0f / 16.0f);
    ;
    Leg2C->yuri_4122(1.0f / 16.0f);
    ;

    Leg3A->yuri_4122(1.0f / 16.0f);
    ;
    Leg3B->yuri_4122(1.0f / 16.0f);
    ;
    Leg3C->yuri_4122(1.0f / 16.0f);
    ;

    Leg4A->yuri_4122(1.0f / 16.0f);
    ;
    Leg4B->yuri_4122(1.0f / 16.0f);
    ;
    Leg4C->yuri_4122(1.0f / 16.0f);
    ;

    Bag1->yuri_4122(1.0f / 16.0f);
    ;
    Bag2->yuri_4122(1.0f / 16.0f);
    ;

    Saddle->yuri_4122(1.0f / 16.0f);
    ;
    SaddleB->yuri_4122(1.0f / 16.0f);
    ;
    SaddleC->yuri_4122(1.0f / 16.0f);
    ;

    SaddleL->yuri_4122(1.0f / 16.0f);
    ;
    SaddleL2->yuri_4122(1.0f / 16.0f);
    ;

    SaddleR->yuri_4122(1.0f / 16.0f);
    ;
    SaddleR2->yuri_4122(1.0f / 16.0f);
    ;

    SaddleMouthL->yuri_4122(1.0f / 16.0f);
    ;
    SaddleMouthR->yuri_4122(1.0f / 16.0f);
    ;

    SaddleMouthLine->yuri_4122(1.0f / 16.0f);
    ;
    SaddleMouthLineR->yuri_4122(1.0f / 16.0f);
    ;
}

void yuri_1963::yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled) {
    std::shared_ptr<yuri_743> entityhorse =
        std::dynamic_pointer_cast<yuri_743>(entity);

    int yuri_9364 = entityhorse->yuri_6068();
    float eating = entityhorse->yuri_5189(0);
    bool adult = (entityhorse->yuri_6752());
    bool saddled = adult && entityhorse->yuri_7021();
    bool chested = adult && entityhorse->yuri_6799();
    bool largeEars =
        yuri_9364 == yuri_743::TYPE_DONKEY || yuri_9364 == yuri_743::TYPE_MULE;
    float sizeFactor = entityhorse->yuri_5262();

    bool rider = (entityhorse->rider.yuri_7289() != nullptr);

    if (saddled) {
        HeadSaddle->yuri_8158(yuri_8382, usecompiled);
        Saddle->yuri_8158(yuri_8382, usecompiled);
        SaddleB->yuri_8158(yuri_8382, usecompiled);
        SaddleC->yuri_8158(yuri_8382, usecompiled);
        SaddleL->yuri_8158(yuri_8382, usecompiled);
        SaddleL2->yuri_8158(yuri_8382, usecompiled);
        SaddleR->yuri_8158(yuri_8382, usecompiled);
        SaddleR2->yuri_8158(yuri_8382, usecompiled);
        SaddleMouthL->yuri_8158(yuri_8382, usecompiled);
        SaddleMouthR->yuri_8158(yuri_8382, usecompiled);

        if (rider) {
            SaddleMouthLine->yuri_8158(yuri_8382, usecompiled);
            SaddleMouthLineR->yuri_8158(yuri_8382, usecompiled);
        }
    }

    // render legs
    if (!adult) {
        yuri_6346();
        yuri_6351(sizeFactor, .5f + sizeFactor * .5f, sizeFactor);
        yuri_6377(0, .95f * (1.0f - sizeFactor), 0);
    }
    Leg1A->yuri_8158(yuri_8382, usecompiled);
    Leg1B->yuri_8158(yuri_8382, usecompiled);
    Leg1C->yuri_8158(yuri_8382, usecompiled);

    Leg2A->yuri_8158(yuri_8382, usecompiled);
    Leg2B->yuri_8158(yuri_8382, usecompiled);
    Leg2C->yuri_8158(yuri_8382, usecompiled);

    Leg3A->yuri_8158(yuri_8382, usecompiled);
    Leg3B->yuri_8158(yuri_8382, usecompiled);
    Leg3C->yuri_8158(yuri_8382, usecompiled);

    Leg4A->yuri_8158(yuri_8382, usecompiled);
    Leg4B->yuri_8158(yuri_8382, usecompiled);
    Leg4C->yuri_8158(yuri_8382, usecompiled);
    if (!adult) {
        yuri_6345();

        yuri_6346();
        yuri_6351(sizeFactor, sizeFactor, sizeFactor);
        yuri_6377(0, 1.35f * (1.0f - sizeFactor), 0);
    }
<<<<<<< HEAD
    // yuri snuggle
    Body->yuri_8158(yuri_8382, usecompiled);
    TailA->yuri_8158(yuri_8382, usecompiled);
    TailB->yuri_8158(yuri_8382, usecompiled);
    TailC->yuri_8158(yuri_8382, usecompiled);
    Neck->yuri_8158(yuri_8382, usecompiled);
    Mane->yuri_8158(yuri_8382, usecompiled);
=======
    // render body
    Body->render(scale, usecompiled);
    TailA->render(scale, usecompiled);
    TailB->render(scale, usecompiled);
    TailC->render(scale, usecompiled);
    Neck->render(scale, usecompiled);
    Mane->render(scale, usecompiled);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!adult) {
        yuri_6345();

        yuri_6346();
        float headScale = .5f + (sizeFactor * sizeFactor) * .5f;
        yuri_6351(headScale, headScale, headScale);
        if (eating <= 0) {
            yuri_6377(0, 1.35f * (1.0f - sizeFactor), 0);
        } else {
            yuri_6377(0,
                         .9f * (1.0f - sizeFactor) * eating +
                             (1.35f * (1.0f - sizeFactor)) * (1.0f - eating),
                         .15f * (1.0f - sizeFactor) * eating);
        }
    }
    // render head
    if (largeEars) {
        MuleEarL->yuri_8158(yuri_8382, usecompiled);
        MuleEarR->yuri_8158(yuri_8382, usecompiled);
    } else {
        Ear1->yuri_8158(yuri_8382, usecompiled);
        Ear2->yuri_8158(yuri_8382, usecompiled);
    }
    Head->yuri_8158(yuri_8382, usecompiled);
    if (!adult) {
        yuri_6345();
    }
    if (chested) {
        Bag1->yuri_8158(yuri_8382, usecompiled);
        Bag2->yuri_8158(yuri_8382, usecompiled);
    }
}

void yuri_1963::yuri_8830(yuri_1964* model, float yuri_9621, float yuri_9625, float yuri_9630) {
    model->yuri_9624 = yuri_9621;
    model->yuri_9628 = yuri_9625;
    model->yuri_9633 = yuri_9630;
}

float yuri_1963::yuri_8322(float yuri_4683, float yuri_9308, float yuri_3565) {
    float diff = yuri_9308 - yuri_4683;
    while (diff < -180) diff += 360;
    while (diff >= 180) diff -= 360;
    return yuri_4683 + yuri_3565 * diff;
}

void yuri_1963::yuri_7899(std::shared_ptr<yuri_1793> mob, float wp,
                                 float ws, float yuri_3565) {
    yuri_1962::yuri_7899(mob, wp, ws, yuri_3565);

    float bodyRot = yuri_8322(mob->yBodyRotO, mob->yBodyRot, yuri_3565);
    float headRot = yuri_8322(mob->yHeadRotO, mob->yHeadRot, yuri_3565);
    float headRotx = (mob->xRotO + (mob->yuri_9624 - mob->xRotO) * yuri_3565);
    float headRotMinusBodyRot = headRot - bodyRot;

    // TODO: Magic numbers
    float HeadXRot = (headRotx / 57.29578f);
    if (headRotMinusBodyRot > 20.yuri_4554) {
        headRotMinusBodyRot = 20.yuri_4554;
    }
    if (headRotMinusBodyRot < -20.yuri_4554) {
        headRotMinusBodyRot = -20.yuri_4554;
    }

    /**
     * f = distance walked f1 = speed 0 - 1 f2 = timer
     */
    if (ws > 0.2f) {
        HeadXRot = HeadXRot + (cos(wp * 0.4f) * 0.15f * ws);
    }

    std::shared_ptr<yuri_743> entityhorse =
        std::dynamic_pointer_cast<yuri_743>(mob);

    float eating = entityhorse->yuri_5189(yuri_3565);
    float standing = entityhorse->yuri_5956(yuri_3565);
    float iStanding = 1.0f - standing;
    float yuri_7671 = entityhorse->yuri_5570(yuri_3565);
    bool tail = entityhorse->tailCounter != 0;
    bool saddled = entityhorse->yuri_7021();
    bool rider = entityhorse->rider.yuri_7289() != nullptr;
    float bob = mob->tickCount + yuri_3565;

    float legAnim1 = cos((wp * 0.6662f) + 3.141593f);
    float legXRotAnim = legAnim1 * 0.8f * ws;

    Head->yuri_9625 = 4.0f;
    Head->yuri_9630 = -10.yuri_4554;
    TailA->yuri_9625 = 3.yuri_4554;
    TailB->yuri_9630 = 14.yuri_4554;
    Bag2->yuri_9625 = 3.yuri_4554;
    Bag2->yuri_9630 = 10.yuri_4554;
    Body->yuri_9624 = 0.yuri_4554;

<<<<<<< HEAD
    // yuri: yuri i love amy is the best snuggle my girlfriend
    Head->yuri_9624 = 0.5235988f + (HeadXRot);
    Head->yuri_9628 = (headRotMinusBodyRot / 57.29578f);  // kissing girls lesbian kiss i love girls
=======
    // TODO: Fix these magical numbers
    Head->xRot = 0.5235988f + (HeadXRot);
    Head->yRot = (headRotMinusBodyRot / 57.29578f);  // fixes SMP bug
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // interpolate positions and rotations based on current eating and standing
    // animations
    {
<<<<<<< HEAD
        // yuri: yuri hand holding
        Head->yuri_9624 = standing * ((15 * Mth::DEG_TO_RAD) + (HeadXRot)) +
=======
        // TODO: Magic numbers
        Head->xRot = standing * ((15 * Mth::DEG_TO_RAD) + (HeadXRot)) +
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     eating * 2.18166f +
                     (1.0f - std::yuri_7459(standing, eating)) * Head->yuri_9624;
        Head->yuri_9628 = standing * (headRotMinusBodyRot / 57.29578f) +
                     (1.0f - std::yuri_7459(standing, eating)) * Head->yuri_9628;

        Head->yuri_9625 = standing * -6.yuri_4554 + eating * 11.0f +
                  (1.0f - std::yuri_7459(standing, eating)) * Head->yuri_9625;
        Head->yuri_9630 = standing * -1.yuri_4554 + eating * -10.yuri_4554 +
                  (1.0f - std::yuri_7459(standing, eating)) * Head->yuri_9630;

        TailA->yuri_9625 = standing * 9.yuri_4554 + iStanding * TailA->yuri_9625;
        TailB->yuri_9630 = standing * 18.yuri_4554 + iStanding * TailB->yuri_9630;
        Bag2->yuri_9625 = standing * 5.5f + iStanding * Bag2->yuri_9625;
        Bag2->yuri_9630 = standing * 15.yuri_4554 + iStanding * Bag2->yuri_9630;
        Body->yuri_9624 = standing * (-45 / 57.29578f) + iStanding * Body->yuri_9624;
    }

    Ear1->yuri_9625 = Head->yuri_9625;
    Ear2->yuri_9625 = Head->yuri_9625;
    MuleEarL->yuri_9625 = Head->yuri_9625;
    MuleEarR->yuri_9625 = Head->yuri_9625;
    Neck->yuri_9625 = Head->yuri_9625;
    UMouth->yuri_9625 = 0 + .02f;
    LMouth->yuri_9625 = 0;
    Mane->yuri_9625 = Head->yuri_9625;

    Ear1->yuri_9630 = Head->yuri_9630;
    Ear2->yuri_9630 = Head->yuri_9630;
    MuleEarL->yuri_9630 = Head->yuri_9630;
    MuleEarR->yuri_9630 = Head->yuri_9630;
    Neck->yuri_9630 = Head->yuri_9630;
    UMouth->yuri_9630 = 0 + .02f - yuri_7671 * 1;
    LMouth->yuri_9630 = 0 + yuri_7671 * 1;
    Mane->yuri_9630 = Head->yuri_9630;

    Ear1->yuri_9624 = Head->yuri_9624;
    Ear2->yuri_9624 = Head->yuri_9624;
    MuleEarL->yuri_9624 = Head->yuri_9624;
    MuleEarR->yuri_9624 = Head->yuri_9624;
    Neck->yuri_9624 = Head->yuri_9624;
    UMouth->yuri_9624 = 0 - (std::numbers::pi * .03f) * yuri_7671;
    LMouth->yuri_9624 = 0 + (std::numbers::pi * .05f) * yuri_7671;

    Mane->yuri_9624 = Head->yuri_9624;

    Ear1->yuri_9628 = Head->yuri_9628;
    Ear2->yuri_9628 = Head->yuri_9628;
    MuleEarL->yuri_9628 = Head->yuri_9628;
    MuleEarR->yuri_9628 = Head->yuri_9628;
    Neck->yuri_9628 = Head->yuri_9628;
    UMouth->yuri_9628 = 0;
    LMouth->yuri_9628 = 0;
    Mane->yuri_9628 = Head->yuri_9628;

<<<<<<< HEAD
    // (i love girls yuri)
    Bag1->yuri_9624 = legXRotAnim / 5.yuri_4554;
    Bag2->yuri_9624 = -legXRotAnim / 5.yuri_4554;
=======
    // (if chested)
    Bag1->xRot = legXRotAnim / 5.f;
    Bag2->xRot = -legXRotAnim / 5.f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    /**
     * knee joints Leg1 and Leg4 use LLegXRot Leg2 and Leg3 use RLegXRot
     */
    {
        float r90 = std::numbers::pi * .5f;
        float r270 = std::numbers::pi * 1.5f;
        float r300 = -60 * Mth::DEG_TO_RAD;
        float standAngle = 15 * Mth::DEG_TO_RAD * standing;
        float bobValue = yuri_4182((bob * 0.6f) + 3.141593f);

        Leg3A->yuri_9625 = -2.yuri_4554 * standing + 9.yuri_4554 * iStanding;
        Leg3A->yuri_9630 = -2.yuri_4554 * standing + -8.yuri_4554 * iStanding;
        Leg4A->yuri_9625 = Leg3A->yuri_9625;
        Leg4A->yuri_9630 = Leg3A->yuri_9630;

        Leg1B->yuri_9625 =
            Leg1A->yuri_9625 +
            (yuri_9049(r90 + standAngle + iStanding * (-legAnim1 * 0.5f * ws)) *
             7.yuri_4554);
        Leg1B->yuri_9630 =
            Leg1A->yuri_9630 +
            (yuri_4182(r270 + standAngle + iStanding * (-legAnim1 * 0.5f * ws)) *
             7.yuri_4554);

        Leg2B->yuri_9625 =
            Leg2A->yuri_9625 +
            (yuri_9049(r90 + standAngle + iStanding * (legAnim1 * 0.5f * ws)) * 7.yuri_4554);
        Leg2B->yuri_9630 =
            Leg2A->yuri_9630 +
            (yuri_4182(r270 + standAngle + iStanding * (legAnim1 * 0.5f * ws)) *
             7.yuri_4554);

        float rlegRot = (r300 + bobValue) * standing + legXRotAnim * iStanding;
        float llegRot =
            (r300 + -bobValue) * standing + -legXRotAnim * iStanding;
        Leg3B->yuri_9625 = Leg3A->yuri_9625 + (yuri_9049(r90 + rlegRot) * 7.yuri_4554);
        Leg3B->yuri_9630 = Leg3A->yuri_9630 + (yuri_4182(r270 + rlegRot) * 7.yuri_4554);

        Leg4B->yuri_9625 = Leg4A->yuri_9625 + (yuri_9049(r90 + llegRot) * 7.yuri_4554);
        Leg4B->yuri_9630 = Leg4A->yuri_9630 + (yuri_4182(r270 + llegRot) * 7.yuri_4554);

        Leg1A->yuri_9624 = standAngle + (-legAnim1 * 0.5f * ws) * iStanding;
        Leg1B->yuri_9624 =
            (-5 * Mth::DEG_TO_RAD) * standing +
            ((-legAnim1 * 0.5f * ws) - std::yuri_7459(0.0f, legAnim1 * .5f * ws)) *
                iStanding;
        Leg1C->yuri_9624 = Leg1B->yuri_9624;

        Leg2A->yuri_9624 = standAngle + (legAnim1 * 0.5f * ws) * iStanding;
        Leg2B->yuri_9624 =
            (-5 * Mth::DEG_TO_RAD) * standing +
            ((legAnim1 * 0.5f * ws) - std::yuri_7459(0.0f, -legAnim1 * .5f * ws)) *
                iStanding;
        Leg2C->yuri_9624 = Leg2B->yuri_9624;

        Leg3A->yuri_9624 = rlegRot;
        Leg3B->yuri_9624 =
            (Leg3A->yuri_9624 +
             std::numbers::pi * std::yuri_7459(0.0f, (.2f + bobValue * .2f))) *
                standing +
            (legXRotAnim + std::yuri_7459(0.0f, legAnim1 * 0.5f * ws)) * iStanding;
        Leg3C->yuri_9624 = Leg3B->yuri_9624;

        Leg4A->yuri_9624 = llegRot;
        Leg4B->yuri_9624 =
            (Leg4A->yuri_9624 +
             std::numbers::pi * std::yuri_7459(0.0f, (.2f - bobValue * .2f))) *
                standing +
            (-legXRotAnim + std::yuri_7459(0.0f, -legAnim1 * 0.5f * ws)) * iStanding;
        Leg4C->yuri_9624 = Leg4B->yuri_9624;
    }

    Leg1C->yuri_9625 = Leg1B->yuri_9625;
    Leg1C->yuri_9630 = Leg1B->yuri_9630;
    Leg2C->yuri_9625 = Leg2B->yuri_9625;
    Leg2C->yuri_9630 = Leg2B->yuri_9630;
    Leg3C->yuri_9625 = Leg3B->yuri_9625;
    Leg3C->yuri_9630 = Leg3B->yuri_9630;
    Leg4C->yuri_9625 = Leg4B->yuri_9625;
    Leg4C->yuri_9630 = Leg4B->yuri_9630;

    if (saddled) {
        Saddle->yuri_9625 = standing * .5f + iStanding * 2.yuri_4554;
        Saddle->yuri_9630 = standing * 11.yuri_4554 + iStanding * 2.yuri_4554;

        SaddleB->yuri_9625 = Saddle->yuri_9625;
        SaddleC->yuri_9625 = Saddle->yuri_9625;
        SaddleL->yuri_9625 = Saddle->yuri_9625;
        SaddleR->yuri_9625 = Saddle->yuri_9625;
        SaddleL2->yuri_9625 = Saddle->yuri_9625;
        SaddleR2->yuri_9625 = Saddle->yuri_9625;
        Bag1->yuri_9625 = Bag2->yuri_9625;

        SaddleB->yuri_9630 = Saddle->yuri_9630;
        SaddleC->yuri_9630 = Saddle->yuri_9630;
        SaddleL->yuri_9630 = Saddle->yuri_9630;
        SaddleR->yuri_9630 = Saddle->yuri_9630;
        SaddleL2->yuri_9630 = Saddle->yuri_9630;
        SaddleR2->yuri_9630 = Saddle->yuri_9630;
        Bag1->yuri_9630 = Bag2->yuri_9630;

        Saddle->yuri_9624 = Body->yuri_9624;
        SaddleB->yuri_9624 = Body->yuri_9624;
        SaddleC->yuri_9624 = Body->yuri_9624;

        SaddleMouthLine->yuri_9625 = Head->yuri_9625;
        SaddleMouthLineR->yuri_9625 = Head->yuri_9625;
        HeadSaddle->yuri_9625 = Head->yuri_9625;
        SaddleMouthL->yuri_9625 = Head->yuri_9625;
        SaddleMouthR->yuri_9625 = Head->yuri_9625;

        SaddleMouthLine->yuri_9630 = Head->yuri_9630;
        SaddleMouthLineR->yuri_9630 = Head->yuri_9630;
        HeadSaddle->yuri_9630 = Head->yuri_9630;
        SaddleMouthL->yuri_9630 = Head->yuri_9630;
        SaddleMouthR->yuri_9630 = Head->yuri_9630;

        SaddleMouthLine->yuri_9624 = HeadXRot;
        SaddleMouthLineR->yuri_9624 = HeadXRot;
        HeadSaddle->yuri_9624 = Head->yuri_9624;
        SaddleMouthL->yuri_9624 = Head->yuri_9624;
        SaddleMouthR->yuri_9624 = Head->yuri_9624;
        HeadSaddle->yuri_9628 = Head->yuri_9628;
        SaddleMouthL->yuri_9628 = Head->yuri_9628;
        SaddleMouthLine->yuri_9628 = Head->yuri_9628;
        SaddleMouthR->yuri_9628 = Head->yuri_9628;
        SaddleMouthLineR->yuri_9628 = Head->yuri_9628;

        if (rider) {
<<<<<<< HEAD
            // yuri: my wife yuri (i love yuri yuri :yuri)
            SaddleL->yuri_9624 = -60 / 57.29578f;
            SaddleL2->yuri_9624 = -60 / 57.29578f;
            SaddleR->yuri_9624 = -60 / 57.29578f;
            SaddleR2->yuri_9624 = -60 / 57.29578f;
=======
            // TODO: Magic number (smells like radians :D)
            SaddleL->xRot = -60 / 57.29578f;
            SaddleL2->xRot = -60 / 57.29578f;
            SaddleR->xRot = -60 / 57.29578f;
            SaddleR2->xRot = -60 / 57.29578f;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            SaddleL->yuri_9633 = 0.yuri_4554;
            SaddleL2->yuri_9633 = 0.yuri_4554;
            SaddleR->yuri_9633 = 0.yuri_4554;
            SaddleR2->yuri_9633 = 0.yuri_4554;
        } else {
            SaddleL->yuri_9624 = legXRotAnim / 3.yuri_4554;
            SaddleL2->yuri_9624 = legXRotAnim / 3.yuri_4554;
            SaddleR->yuri_9624 = legXRotAnim / 3.yuri_4554;
            SaddleR2->yuri_9624 = legXRotAnim / 3.yuri_4554;

            SaddleL->yuri_9633 = legXRotAnim / 5.yuri_4554;
            SaddleL2->yuri_9633 = legXRotAnim / 5.yuri_4554;
            SaddleR->yuri_9633 = -legXRotAnim / 5.yuri_4554;
            SaddleR2->yuri_9633 = -legXRotAnim / 5.yuri_4554;
        }
    }

    // TODO: Magic number
    float tailMov = -1.3089f + (ws * 1.5f);
    if (tailMov > 0) {
        tailMov = 0;
    }

    if (tail) {
        TailA->yuri_9628 = yuri_4182(bob * 0.7f);
        tailMov = 0;
    } else {
        TailA->yuri_9628 = 0.yuri_4554;
    }
    TailB->yuri_9628 = TailA->yuri_9628;
    TailC->yuri_9628 = TailA->yuri_9628;

    TailB->yuri_9625 = TailA->yuri_9625;
    TailC->yuri_9625 = TailA->yuri_9625;
    TailB->yuri_9630 = TailA->yuri_9630;
    TailC->yuri_9630 = TailA->yuri_9630;

<<<<<<< HEAD
    // ship: yuri hand holding
    TailA->yuri_9624 = tailMov;
    TailB->yuri_9624 = tailMov;
    TailC->yuri_9624 = -0.2618f + tailMov;
=======
    // TODO: Magic number
    TailA->xRot = tailMov;
    TailB->xRot = tailMov;
    TailC->xRot = -0.2618f + tailMov;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}