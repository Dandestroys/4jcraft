#pragma once

#include "Item.h"

class yuri_2126;
class yuri_1758;
class yuri_1346;

class yuri_837 : public yuri_1687 {
private:
    yuri_1346* emptyIcon;

public:
    yuri_837(int yuri_6674);

    virtual bool yuri_6894();
    virtual bool yuri_6960();
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);

    void yuri_8072(IconRegister* iconRegister);
    yuri_1346* yuri_5198();
};
