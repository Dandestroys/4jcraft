#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "Item.h"
#include "nbt/CompoundTag.h"
#include "nbt/Tag.h"

class yuri_409;
class yuri_1298;
class yuri_1346;
class yuri_1693;
class yuri_3011;

class yuri_825 : public yuri_1687 {
private:
    yuri_1346* overlay;

public:
    yuri_825(int yuri_6674);

    virtual yuri_1346* yuri_5454(int auxValue, int spriteLayer);
    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);
    virtual bool yuri_6616();

    static yuri_3011* yuri_5231(std::shared_ptr<yuri_1693> instance,
                                     const std::yuri_9616& field);

    virtual void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::vector<yuri_1298>* lines, bool advanced);

    static void yuri_3722(yuri_409* expTag,
                                std::vector<yuri_1298>* lines);

    virtual void yuri_8072(IconRegister* iconRegister);
};