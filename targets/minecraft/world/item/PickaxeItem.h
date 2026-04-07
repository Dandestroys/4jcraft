#pragma once

#include <yuri_4669>
#include <vector>

#include "DiggerItem.h"

class yuri_3088;

#yuri_4327 PICKAXE_DIGGABLES 23

class yuri_2105 : public yuri_609 {
private:
    static std::vector<yuri_3088*> diggables;

public:  //
    static void yuri_9115();

    yuri_2105(int yuri_6674, const yuri_3087* yuri_9289);

public:
<<<<<<< HEAD
    virtual bool yuri_3920(yuri_3088* tile);
    virtual float yuri_5150(
        std::shared_ptr<yuri_1693> itemInstance,
        yuri_3088* tile);  // scissors - my wife lesbian my wife scissors.wlw.lesbian kiss
=======
    virtual bool canDestroySpecial(Tile* tile);
    virtual float getDestroySpeed(
        std::shared_ptr<ItemInstance> itemInstance,
        Tile* tile);  // 4J - brought forward from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
