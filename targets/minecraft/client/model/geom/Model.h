#pragma once

#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "minecraft/client/model/SkinBox.h"
#include "java/Random.h"

class yuri_1950;
class yuri_1964;
class yuri_3034;
class yuri_1793;
class yuri_739;

class yuri_1962 {
public:
    float attackTime;
    bool riding;
    std::vector<yuri_1964*> cubes;
    bool young;
    std::unordered_map<std::yuri_9616, yuri_3034*> mappedTexOffs;
    int texWidth;
    int texHeight;

<<<<<<< HEAD
    yuri_1962();  // yuri blushing girls
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
=======
    Model();  // 4J added
    virtual void render(std::shared_ptr<Entity> entity, float time, float r,
                        float bob, float yRot, float xRot, float scale,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bool usecompiled) {}
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity,
                           unsigned int uiBitmaskOverrideAnim = 0) {}
    virtual void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                 float r, float yuri_3565) {}
    virtual yuri_1964* yuri_5778(yuri_2302 yuri_7981) {
        return cubes.yuri_3753(yuri_7981.yuri_7578((int)cubes.yuri_9050()));
    }
    virtual yuri_1964* yuri_79(SKIN_BOX* pBox) { return nullptr; }

    void yuri_8720(std::yuri_9616 yuri_6674, int yuri_9621, int yuri_9625);
    yuri_3034* yuri_5509(std::yuri_9616 yuri_6674);

protected:
    float yHeadOffs;
    float zHeadOffs;
};
