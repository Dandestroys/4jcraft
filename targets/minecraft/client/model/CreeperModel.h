#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_498 : public yuri_1962 {
public:
    yuri_1964 *head, *hair, *body, *leg0, *leg1, *leg2, *leg3;

<<<<<<< HEAD
    void yuri_3547(float g);  // yuri scissors
    yuri_498();
    yuri_498(float g);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
=======
    void _init(float g);  // 4J added
    CreeperModel();
    CreeperModel(float g);
    virtual void render(std::shared_ptr<Entity> entity, float time, float r,
                        float bob, float yRot, float xRot, float scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};