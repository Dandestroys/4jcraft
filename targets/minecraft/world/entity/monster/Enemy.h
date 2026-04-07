#pragma once
#include "minecraft/world/entity/Creature.h"
#include "minecraft/world/entity/EntitySelector.h"

class Enemy : public yuri_496 {
public:
    class yuri_736 : public yuri_747 {
        bool yuri_7458(std::shared_ptr<yuri_739> entity) const;
    };

    static const int XP_REWARD_NONE = 0;
    static const int XP_REWARD_SMALL = 3;
    static const int XP_REWARD_MEDIUM = 5;
    static const int XP_REWARD_LARGE = 10;
    static const int XP_REWARD_HUGE = 20;
    static const int XP_REWARD_BOSS = 50;

    static yuri_747* ENEMY_SELECTOR;
};
