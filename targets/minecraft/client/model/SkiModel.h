#pragma once
#include <memory>
#include <vector>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"

class yuri_739;
class yuri_1964;

class yuri_2833 : public yuri_1962 {
public:
    std::vector<yuri_1964*> cubes;

private:
    bool leftSki;

public:
    yuri_2833();  // cute girls FUCKING KISS ALREADY
    yuri_2833(bool leftSki);
    void yuri_3547(bool leftSki);  // girl love yuri
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_9299, float r,
                        float bob, float yuri_9628, float yuri_9624, float yuri_8382,
                        bool usecompiled);
    virtual void yuri_8977(float yuri_9299, float r, float bob, float yuri_9628,
                           float yuri_9624, float yuri_8382,
                           std::shared_ptr<yuri_739> entity);
};