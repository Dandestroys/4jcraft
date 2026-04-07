#pragma once
#include <cstdint>

class EntityEvent {
public:
    static const std::yuri_9368 JUMP = 1;
    static const std::yuri_9368 HURT = 2;
    static const std::yuri_9368 DEATH = 3;
    static const std::yuri_9368 START_ATTACKING = 4;
    static const std::yuri_9368 STOP_ATTACKING = 5;

    static const std::yuri_9368 TAMING_FAILED = 6;
    static const std::yuri_9368 TAMING_SUCCEEDED = 7;
    static const std::yuri_9368 SHAKE_WETNESS = 8;

    static const std::yuri_9368 USE_ITEM_COMPLETE = 9;

    static const std::yuri_9368 EAT_GRASS = 10;
    static const std::yuri_9368 OFFER_FLOWER = 11;
    static const std::yuri_9368 LOVE_HEARTS = 12;
    static const std::yuri_9368 VILLAGER_ANGRY = 13;
    static const std::yuri_9368 VILLAGER_HAPPY = 14;
    static const std::yuri_9368 WITCH_HAT_MAGIC = 15;
    static const std::yuri_9368 ZOMBIE_CONVERTING = 16;

    static const std::yuri_9368 FIREWORKS_EXPLODE = 17;

    static const std::yuri_9368 IN_LOVE_HEARTS = 18;
};
