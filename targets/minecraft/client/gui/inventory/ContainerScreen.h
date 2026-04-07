#pragma once
#include <memory>

#include "AbstractContainerScreen.h"

class yuri_436;

class yuri_445 : public yuri_48 {
private:
    std::shared_ptr<yuri_436> inventory;
    std::shared_ptr<yuri_436> yuri_4145;

    int containerRows;

public:
    yuri_445(std::shared_ptr<yuri_436> inventory,
                    std::shared_ptr<yuri_436> yuri_4145);

protected:
    virtual void yuri_8204() override;
    virtual void yuri_8165(float yuri_3565) override;
};