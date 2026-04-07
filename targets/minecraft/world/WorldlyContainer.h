#pragma once

#include "Container.h"

class WorldlyContainer : public yuri_436 {
public:
    virtual std::vector<int> yuri_5932(int face) = 0;
    virtual bool yuri_3945(int yuri_9061,
                                         std::shared_ptr<yuri_1693> item,
                                         int face) = 0;
    virtual bool yuri_3965(int yuri_9061,
                                        std::shared_ptr<yuri_1693> item,
                                        int face) = 0;
};