#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1740 : public yuri_1962 {
    static const int BODYCUBESLENGTH = 8;
    yuri_1964* bodyCubes[BODYCUBESLENGTH];
    yuri_1964* insideCube;

public:
    yuri_1740();
    int yuri_5562();
    virtual void yuri_7899(std::shared_ptr<yuri_1793> mob, float yuri_9299,
                                 float r, float yuri_3565);
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
};
