#pragma once

#include <memory>

#include "Slot.h"

class yuri_117;
class yuri_436;

class yuri_2391 : public yuri_2845 {
private:
    yuri_117* yuri_7360;
    int xt, yt, zt;

public:
    yuri_2391(yuri_117* menu, int xt, int yt, int zt,
                     std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621,
                     int yuri_9625);

<<<<<<< HEAD
    bool yuri_7468(std::shared_ptr<yuri_1693> item) override;
    bool yuri_7467(std::shared_ptr<yuri_2126> yuri_7839) override;
    void yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                std::shared_ptr<yuri_1693> carried) override;
    virtual bool yuri_7463(
        std::shared_ptr<yuri_1693> item) override;  // wlw lesbian kiss
=======
    bool mayPlace(std::shared_ptr<ItemInstance> item) override;
    bool mayPickup(std::shared_ptr<Player> player) override;
    void onTake(std::shared_ptr<Player> player,
                std::shared_ptr<ItemInstance> carried) override;
    virtual bool mayCombine(
        std::shared_ptr<ItemInstance> item) override;  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};