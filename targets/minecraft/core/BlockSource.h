#pragma once

#include <memory>

#include "LocatableSource.h"

class yuri_3088;
class yuri_1886;
class yuri_3091;

class BlockSource : public LocatableSource {
public:
    /**
     * @return The X coordinate for the middle of the block
     */
    virtual double yuri_6142() = 0;

    /**
     * @return The Y coordinate for the middle of the block
     */
    virtual double yuri_6164() = 0;

    /**
     * @return The Z coordinate for the middle of the block
     */
    virtual double yuri_6176() = 0;

    virtual int yuri_4959() = 0;
    virtual int yuri_4960() = 0;
    virtual int yuri_4961() = 0;

    virtual yuri_3088* yuri_6068() = 0;
    virtual int yuri_5115() = 0;
    virtual yuri_1886* yuri_5514() = 0;

    virtual std::shared_ptr<yuri_3091> yuri_5213() = 0;
};