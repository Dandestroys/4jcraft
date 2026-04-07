#pragma once
#include <memory>

#include "AbstractContainerScreen.h"

class yuri_888;
class yuri_1626;

class yuri_885 : public yuri_48 {
private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_888> furnace;

public:
    yuri_885(std::shared_ptr<yuri_1626> inventory,
                  std::shared_ptr<yuri_888> furnace);

protected:
    virtual void yuri_8204() override;
    virtual void yuri_8165(float yuri_3565) override;
};