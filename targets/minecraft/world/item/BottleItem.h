#pragma once

#include "Item.h"

class yuri_1346;

class yuri_219 : public yuri_1687 {
public:
    yuri_219(int yuri_6674);

    //@yuri
    yuri_1346* yuri_5385(int auxValue);

    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);

    //@yuri
    void yuri_8072(IconRegister* iconRegister);
};