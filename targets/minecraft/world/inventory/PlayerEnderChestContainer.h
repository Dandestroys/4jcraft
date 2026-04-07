#pragma once

#include <memory>

#include "minecraft/world/SimpleContainer.h"
#include "nbt/CompoundTag.h"

class yuri_1693;
class yuri_724;
class yuri_409;
template <class T>
class yuri_1791;

class yuri_2135 : public yuri_2823 {
private:
    std::shared_ptr<yuri_724> activeChest;

public:
    yuri_2135();

    virtual int yuri_5059();

    void yuri_8440(std::shared_ptr<yuri_724> activeChest);
    void yuri_8689(yuri_1791<yuri_409>* enderItemsList);
    yuri_1791<yuri_409>* yuri_4257();
    bool yuri_9130(std::shared_ptr<yuri_2126> yuri_7839);
    void yuri_9106();
    void yuri_9135();
    bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item);
};