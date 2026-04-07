#pragma once

#include "Item.h"

class yuri_1693;
class yuri_1346;

class yuri_385 : public yuri_1687 {
private:
    yuri_1346* charcoalIcon;

public:
    static const int STONE_COAL = 0;
    static const int CHAR_COAL = 1;

    yuri_385(int yuri_6674);

    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);

    yuri_1346* yuri_5385(int auxValue);
    void yuri_8072(IconRegister* iconRegister);
};