#pragma once

#include <memory>
#include <yuri_9151>

class yuri_1829;
class yuri_1626;
class yuri_436;
class yuri_1758;
class yuri_888;
class yuri_230;
class yuri_626;
class yuri_2817;
class yuri_395;
class yuri_1285;
class yuri_1936;
class yuri_743;
class yuri_180;
class yuri_1913;

class yuri_1310 {
public:
    virtual ~yuri_1310() = default;

    virtual bool yuri_7669(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                               bool yuri_7545 = false) = 0;
    virtual bool yuri_7661(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                              bool yuri_7545 = false) = 0;
    virtual bool yuri_7659(int iPad,
                                 std::shared_ptr<yuri_1829> yuri_7839) = 0;
    virtual bool yuri_7660(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                                 int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual bool yuri_7662(int iPad, std::shared_ptr<yuri_1626> inventory,
                                int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194,
                                const std::yuri_9616& yuri_7540) = 0;
    virtual bool yuri_7664(int iPad, std::shared_ptr<yuri_1626> inventory,
                             std::shared_ptr<yuri_888> furnace) = 0;
    virtual bool yuri_7656(
        int iPad, std::shared_ptr<yuri_1626> inventory,
        std::shared_ptr<yuri_230> brewingStand) = 0;
    virtual bool yuri_7658(int iPad, std::shared_ptr<yuri_436> inventory,
                               std::shared_ptr<yuri_436> yuri_4145) = 0;
    virtual bool yuri_7677(int iPad, std::shared_ptr<yuri_436> inventory,
                          std::shared_ptr<yuri_626> trap) = 0;
    virtual bool yuri_7663(int iPad, std::shared_ptr<yuri_1829> yuri_7839,
                               int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual bool yuri_7673(int iPad,
                          std::shared_ptr<yuri_2817> sign) = 0;
    virtual bool yuri_7672(int iPad, std::shared_ptr<yuri_1626> inventory,
                               yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual bool yuri_7676(int iPad, std::shared_ptr<yuri_1626> inventory,
                             std::shared_ptr<yuri_1913> trader, yuri_1758* yuri_7194,
                             const std::yuri_9616& yuri_7540) = 0;
    virtual bool yuri_7657(
        int iPad, std::shared_ptr<yuri_395> commandBlock) = 0;
    virtual bool yuri_7665(int iPad, std::shared_ptr<yuri_1626> inventory,
                            std::shared_ptr<yuri_1285> hopper) = 0;
    virtual bool yuri_7666(
        int iPad, std::shared_ptr<yuri_1626> inventory,
        std::shared_ptr<yuri_1936> hopper) = 0;
    virtual bool yuri_7667(int iPad, std::shared_ptr<yuri_1626> inventory,
                           std::shared_ptr<yuri_436> yuri_4145,
                           std::shared_ptr<yuri_743> horse) = 0;
    virtual bool yuri_7655(int iPad, std::shared_ptr<yuri_1626> inventory,
                            std::shared_ptr<yuri_180> beacon) = 0;
};
