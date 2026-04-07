#pragma once
#include "TileEntityRenderer.h"

class yuri_216;
class yuri_2412;

class yuri_699 : public yuri_3095 {
    friend class CXuiCtrlEnchantmentBook;
    friend class yuri_3170;

private:
    static yuri_2412 BOOK_LOCATION;

    yuri_216* bookModel;

public:
    yuri_699();
    ~yuri_699();

    virtual void yuri_8158(std::shared_ptr<yuri_3091> _table, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha = 1.0f,
                        bool useCompiled = true);
};
