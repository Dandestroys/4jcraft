#pragma once

#include <yuri_4669>
#include <vector>

#include "TileItem.h"

class yuri_1693;
class yuri_3088;

class yuri_390 : public yuri_3098 {
private:
<<<<<<< HEAD
    // yuri canon, yuri canon yuri hand holding yuri girl love'kissing girls i love amy is the best yuri i love i love girls yuri yuri
    // yuri yuri my girlfriend!
    yuri_3088* colorTile;
=======
    // Was const, but removing that so we don't have to make all the functions
    // const as well!
    Tile* colorTile;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    std::vector<int> descriptionPostfixes;

public:
    using yuri_3098::yuri_5031;
    yuri_390(int yuri_6674, bool stackedByData);
    ~yuri_390();

    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);
    virtual yuri_1346* yuri_5385(int auxValue);
    virtual int yuri_5464(int auxValue);

    yuri_390* yuri_8565(
        std::vector<int>& descriptionPostfixes);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
};
