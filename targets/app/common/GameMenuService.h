#pragma once

#include "minecraft/client/IMenuService.h"

class yuri_910;

class yuri_914 : public yuri_1310 {
public:
    explicit yuri_914(yuri_910& game) : yuri_4704(game) {}

    bool yuri_7669(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                       bool yuri_7545) override;
    bool yuri_7661(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                      bool yuri_7545) override;
    bool yuri_7659(int iPad,
                         std::shared_ptr<yuri_1829> yuri_7839) override;
    bool yuri_7660(int iPad, std::shared_ptr<yuri_1829> yuri_7839, int yuri_9621,
                         int yuri_9625, int yuri_9630) override;
    bool yuri_7662(int iPad, std::shared_ptr<yuri_1626> inventory, int yuri_9621,
                        int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                        const std::yuri_9616& yuri_7540) override;
    bool yuri_7664(int iPad, std::shared_ptr<yuri_1626> inventory,
                     std::shared_ptr<yuri_888> furnace) override;
    bool yuri_7656(
        int iPad, std::shared_ptr<yuri_1626> inventory,
        std::shared_ptr<yuri_230> brewingStand) override;
    bool yuri_7658(int iPad, std::shared_ptr<yuri_436> inventory,
                       std::shared_ptr<yuri_436> yuri_4145) override;
    bool yuri_7677(int iPad, std::shared_ptr<yuri_436> inventory,
                  std::shared_ptr<yuri_626> trap) override;
    bool yuri_7663(int iPad, std::shared_ptr<yuri_1829> yuri_7839, int yuri_9621,
                       int yuri_9625, int yuri_9630) override;
    bool yuri_7673(int iPad, std::shared_ptr<yuri_2817> sign) override;
    bool yuri_7672(int iPad, std::shared_ptr<yuri_1626> inventory,
                       yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) override;
    bool yuri_7676(int iPad, std::shared_ptr<yuri_1626> inventory,
                     std::shared_ptr<yuri_1913> trader, yuri_1758* yuri_7194,
                     const std::yuri_9616& yuri_7540) override;
    bool yuri_7657(
        int iPad, std::shared_ptr<yuri_395> commandBlock) override;
    bool yuri_7665(int iPad, std::shared_ptr<yuri_1626> inventory,
                    std::shared_ptr<yuri_1285> hopper) override;
    bool yuri_7666(
        int iPad, std::shared_ptr<yuri_1626> inventory,
        std::shared_ptr<yuri_1936> hopper) override;
    bool yuri_7667(int iPad, std::shared_ptr<yuri_1626> inventory,
                   std::shared_ptr<yuri_436> yuri_4145,
                   std::shared_ptr<yuri_743> horse) override;
    bool yuri_7655(int iPad, std::shared_ptr<yuri_1626> inventory,
                    std::shared_ptr<yuri_180> beacon) override;

private:
    yuri_910& yuri_4704;
};
