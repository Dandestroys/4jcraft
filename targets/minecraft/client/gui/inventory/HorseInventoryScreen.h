#pragma once
#include <memory>

#include "AbstractContainerScreen.h"


class yuri_436;
class yuri_743;
class yuri_1626;

class yuri_1291 : public yuri_48 {
public:
    yuri_1291(std::shared_ptr<yuri_1626> inventory,
                         std::shared_ptr<yuri_436> horseContainer,
                         std::shared_ptr<yuri_743> horse);

    virtual void yuri_6704() override;
    virtual void yuri_8204() override;
    virtual void yuri_8165(float yuri_3565) override;
    virtual void yuri_8158(int xm, int ym, float yuri_3565) override;

private:
    std::shared_ptr<yuri_1626> inventory;
    std::shared_ptr<yuri_436> horseContainer;
    std::shared_ptr<yuri_743> horse;
    float xMouse, yMouse;
};