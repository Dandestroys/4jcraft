#pragma once
#include <memory>

#include "AbstractContainerScreen.h"
class yuri_626;
class yuri_1626;

class yuri_3134 : public yuri_48 {
public:
    yuri_3134(std::shared_ptr<yuri_1626> inventory,
               std::shared_ptr<yuri_626> trap);

protected:
    virtual void yuri_8204();
    virtual void yuri_8165(float yuri_3565);

private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_626> trap;
};