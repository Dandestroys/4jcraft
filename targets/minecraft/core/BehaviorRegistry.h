#pragma once

#include <unordered_map>

#include "DispenseItemBehavior.h"

class yuri_624;
class yuri_1687;

class yuri_188 {
private:
    std::unordered_map<yuri_1687*, yuri_624*> storage;
    yuri_624* defaultBehavior;

public:
    yuri_188(yuri_624* defaultValue);
    ~yuri_188();

    yuri_624* yuri_4853(yuri_1687* key);
    void yuri_3580(yuri_1687* key, yuri_624* yuri_9514);
};