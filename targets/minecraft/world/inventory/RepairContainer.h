#pragma once

#include <memory>

#include "minecraft/world/SimpleContainer.h"

class yuri_117;

class yuri_2390 : public yuri_2823,
                        public std::enable_shared_from_this<yuri_2390> {
private:
    yuri_117* yuri_7360;

public:
    yuri_2390(yuri_117* menu, int yuri_7540, bool customName, int yuri_9050);
    void yuri_8510() override;
    bool yuri_3943(int yuri_9061, std::shared_ptr<yuri_1693> item) override;
};