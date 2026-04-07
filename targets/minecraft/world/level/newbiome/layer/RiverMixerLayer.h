#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Layer.h"

class yuri_2436 : public yuri_1742 {
private:
    std::shared_ptr<yuri_1742> yuri_3816;
    std::shared_ptr<yuri_1742> rivers;

public:
    yuri_2436(yuri_6733 yuri_8396, std::shared_ptr<yuri_1742> yuri_3816,
                    std::shared_ptr<yuri_1742> rivers);

    virtual void yuri_6704(yuri_6733 yuri_8396);
    virtual std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412);
};