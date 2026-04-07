#pragma once

#include "minecraft/GameEnums.h"
#include "MobEffect.h"

class yuri_1793;
class yuri_162;

class yuri_1262 : public yuri_1953 {
public:
    yuri_1262(int yuri_6674, bool yuri_6896, eMinecraftColour yuri_4111);

    void yuri_8103(std::shared_ptr<yuri_1793> entity,
                                  yuri_162* attributes, int amplifier);
};