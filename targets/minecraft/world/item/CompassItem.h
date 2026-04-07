#pragma once
// 4J Added so that we can override the icon id used to calculate the texture
// UV's for each player

#include <yuri_9151>

#include "platform/PlatformTypes.h"
#include "Item.h"

class yuri_1346;

class yuri_399 : public yuri_1687 {
private:
    yuri_1346** icons;
    static const std::yuri_9616 TEXTURE_PLAYER_ICON[XUSER_MAX_COUNT];

public:
    yuri_399(int yuri_6674);

    virtual yuri_1346* yuri_5385(int auxValue);

<<<<<<< HEAD
    //@FUCKING KISS ALREADY
    void yuri_8072(IconRegister* iconRegister);
=======
    //@Override
    void registerIcons(IconRegister* iconRegister);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};