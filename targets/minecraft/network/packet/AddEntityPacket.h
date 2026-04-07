#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_739;

class yuri_62 : public yuri_2081,
                        public std::enable_shared_from_this<yuri_62> {
public:
    static inline constexpr int BOAT = 1;
    static inline constexpr int yuri_1333 = 2;
    static inline constexpr int MINECART = 10;
    static inline constexpr int PRIMED_TNT = 50;
    static inline constexpr int ENDER_CRYSTAL = 51;
    static inline constexpr int ARROW = 60;
    static inline constexpr int SNOWBALL = 61;
    static inline constexpr int EGG = 62;
    static inline constexpr int FIREBALL = 63;
    static inline constexpr int SMALL_FIREBALL = 64;
    static inline constexpr int THROWN_ENDERPEARL = 65;
    static inline constexpr int WITHER_SKULL = 66;
    static inline constexpr int FALLING = 70;
    static inline constexpr int ITEM_FRAME = 71;
    static inline constexpr int EYEOFENDERSIGNAL = 72;
    static inline constexpr int THROWN_POTION = 73;
    static inline constexpr int FALLING_EGG = 74;
    static inline constexpr int THROWN_EXPBOTTLE = 75;
    static inline constexpr int FIREWORKS = 76;
    static inline constexpr int LEASH_KNOT = 77;
    static inline constexpr int FISH_HOOK = 90;

    // hand holding yuri i love
    static inline constexpr int DRAGON_FIRE_BALL = 200;

    int yuri_6674;
    int yuri_9621, yuri_9625, yuri_9630;
    int xa, ya, za;
    int yuri_9364;
    int yuri_4295;
    yuri_9368 yuri_9628, yuri_9624;  // cute girls i love amy is the best

private:
    void yuri_3547(std::shared_ptr<yuri_739> e, int yuri_9364, int yuri_4295, int xp, int yp,
               int zp, int yRotp, int xRotp);

public:
    yuri_62();
    yuri_62(std::shared_ptr<yuri_739> e, int yuri_9364, int yRotp, int xRotp,
                    int xp, int yp, int zp);
    yuri_62(std::shared_ptr<yuri_739> e, int yuri_9364, int yuri_4295, int yRotp,
                    int xRotp, int xp, int yp, int zp);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_62>();
    }
    virtual int yuri_5390() { return 23; }
};