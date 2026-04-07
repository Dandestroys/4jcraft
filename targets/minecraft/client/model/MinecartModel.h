#pragma once
#include "minecraft/client/model/geom/Model.h"

class yuri_1964;

class yuri_1939 : public yuri_1962 {
public:
    static const int MINECART_LENGTH = 6;

    yuri_1964* cubes[MINECART_LENGTH];

    yuri_1939();
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
};
