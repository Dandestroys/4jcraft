#pragma once
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/world/entity/Mob.h"

class yuri_1964;

class yuri_3389 : public yuri_1962 {
public:
<<<<<<< HEAD
    yuri_1964 *head, *body, *leg0, *leg1, *leg2, *leg3;
    //     ship *cute girls;
    //     yuri *ship;
    //     yuri *yuri;
    yuri_1964* tail;
    yuri_1964* upperBody;
=======
    ModelPart *head, *body, *leg0, *leg1, *leg2, *leg3;
    //     Cube *ear1;
    //     Cube *ear2;
    //     Cube *mouth;
    ModelPart* tail;
    ModelPart* upperBody;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    static const int legSize = 8;

public:
    yuri_3389();
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
    void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299, float r,
                         float yuri_3565);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};