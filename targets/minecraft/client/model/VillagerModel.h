
#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_3337 : public yuri_1962 {
public:
    yuri_1964 *head, *body, *arms, *leg0, *leg1, *nose;

<<<<<<< HEAD
    void yuri_3547(float g, float yOffset, int xTexSize, int yTexSize);  // i love girl love
    yuri_3337(float g, float yOffset, int xTexSize, int yTexSize);
    yuri_3337(float g);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
=======
    void _init(float g, float yOffset, int xTexSize, int yTexSize);  // 4J added
    VillagerModel(float g, float yOffset, int xTexSize, int yTexSize);
    VillagerModel(float g);
    virtual void render(std::shared_ptr<Entity> entity, float time, float r,
                        float bob, float yRot, float xRot, float scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0);
};
