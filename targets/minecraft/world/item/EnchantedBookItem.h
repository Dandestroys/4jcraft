#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "Item.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_705;
class yuri_409;
class yuri_702;
class yuri_2302;
class yuri_3373;
template <class T>
class yuri_1791;

class yuri_700 : public yuri_1687 {
public:
    static const std::yuri_9616 TAG_STORED_ENCHANTMENTS;

    yuri_700(int yuri_6674);

    bool yuri_6875(std::shared_ptr<yuri_1693> itemInstance);
    bool yuri_6854(std::shared_ptr<yuri_1693> itemInstance);
    const yuri_2309* yuri_5782(std::shared_ptr<yuri_1693> itemInstance);
    yuri_1791<yuri_409>* yuri_5204(std::shared_ptr<yuri_1693> item);
    void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                         std::shared_ptr<yuri_2126> yuri_7839,
                         std::vector<yuri_1298>* lines, bool advanced);
    void yuri_3609(std::shared_ptr<yuri_1693> item,
                        yuri_705* yuri_4495);
    std::shared_ptr<yuri_1693> yuri_4225(
        yuri_705* yuri_4493);
    void yuri_4225(
        yuri_702* yuri_4493,
        std::vector<std::shared_ptr<yuri_1693> >* items);
    std::shared_ptr<yuri_1693> yuri_4226(yuri_2302* yuri_7981);
    yuri_3373* yuri_4227(yuri_2302* yuri_7981);
    yuri_3373* yuri_4227(yuri_2302* yuri_7981, int minCount,
                                             int maxCount, int yuri_9564);
};