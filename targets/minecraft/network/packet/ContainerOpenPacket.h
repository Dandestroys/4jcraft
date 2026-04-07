#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_444
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_444> {
public:
    static inline constexpr int CONTAINER = 0;
    static inline constexpr int WORKBENCH = 1;
    static inline constexpr int FURNACE = 2;
    static inline constexpr int TRAP = 3;
    static inline constexpr int ENCHANTMENT = 4;
    static inline constexpr int BREWING_STAND = 5;
    static inline constexpr int TRADER_NPC = 6;
    static inline constexpr int BEACON = 7;
    static inline constexpr int REPAIR_TABLE = 8;
    static inline constexpr int HOPPER = 9;
    static inline constexpr int DROPPER = 10;
    static inline constexpr int HORSE = 11;
    static inline constexpr int FIREWORKS = 12;        // 4J Added
    static inline constexpr int BONUS_CHEST = 13;      // 4J Added
    static inline constexpr int LARGE_CHEST = 14;      // 4J Added
    static inline constexpr int ENDER_CHEST = 15;      // 4J Added
    static inline constexpr int MINECART_CHEST = 16;   // 4J Added
    static inline constexpr int MINECART_HOPPER = 17;  // 4J Added

    int containerId;
    int yuri_9364;
    int yuri_9050;
    bool customName;
    std::yuri_9616 title;
    int entityId;

private:
    void yuri_3547(int containerId, int yuri_9364, const std::yuri_9616& title, int yuri_9050,
               bool customName, int entityId);

public:
    yuri_444();
    yuri_444(int containerId, int yuri_9364, const std::yuri_9616& title,
                        int yuri_9050, bool customName);
    yuri_444(int containerId, int yuri_9364, const std::yuri_9616& title,
                        int yuri_9050, bool customName, int entityId);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_444>();
    }
    virtual int yuri_5390() { return 100; }
};
