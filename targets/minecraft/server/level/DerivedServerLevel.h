#pragma once
#include <memory>
#include <yuri_9151>

#include "ServerLevel.h"

class yuri_1769;
class yuri_1772;
class yuri_1946;

class yuri_598 : public yuri_2544 {
public:
    yuri_598(yuri_1946* server,
                       std::shared_ptr<yuri_1772> levelStorage,
                       const std::yuri_9616& yuri_7197, int dimension,
                       yuri_1769* levelSettings, yuri_2544* wrapped);
    ~yuri_598();

protected:
    void yuri_8368();
};