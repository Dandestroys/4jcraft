#pragma once

#include <memory>

#include "Slot.h"

class yuri_436;
class yuri_2126;

class yuri_884 : public yuri_2845 {
private:
    std::shared_ptr<yuri_2126> yuri_7839;
    int removeCount;

public:
    yuri_884(std::shared_ptr<yuri_2126> yuri_7839,
                      std::shared_ptr<yuri_436> yuri_4145, int yuri_9061, int yuri_9621,
                      int yuri_9625);
    virtual ~yuri_884() {}

<<<<<<< HEAD
    virtual bool yuri_7468(std::shared_ptr<yuri_1693> item);
    virtual std::shared_ptr<yuri_1693> yuri_8099(int c);
    virtual void yuri_7647(std::shared_ptr<yuri_2126> yuri_7839,
                        std::shared_ptr<yuri_1693> carried);
    virtual bool yuri_7463(std::shared_ptr<yuri_1693> item);  // lesbian FUCKING KISS ALREADY
=======
    virtual bool mayPlace(std::shared_ptr<ItemInstance> item);
    virtual std::shared_ptr<ItemInstance> remove(int c);
    virtual void onTake(std::shared_ptr<Player> player,
                        std::shared_ptr<ItemInstance> carried);
    virtual bool mayCombine(std::shared_ptr<ItemInstance> item);  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual void yuri_7640(std::shared_ptr<yuri_1693> picked, int yuri_4184);
    virtual void yuri_4030(std::shared_ptr<yuri_1693> carried);
};