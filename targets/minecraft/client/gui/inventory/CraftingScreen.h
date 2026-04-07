#pragma once
#include <memory>

#include "AbstractContainerScreen.h"

class yuri_1626;
class yuri_1758;

class yuri_472 : public yuri_48 {
private:
    std::shared_ptr<yuri_1626> inventory;

public:
    yuri_472(std::shared_ptr<yuri_1626> inventory, yuri_1758* yuri_7194, int yuri_9621,
                   int yuri_9625, int yuri_9630);
    virtual void yuri_8152() override;

protected:
    virtual void yuri_8204() override;
    virtual void yuri_8165(float yuri_3565) override;
};