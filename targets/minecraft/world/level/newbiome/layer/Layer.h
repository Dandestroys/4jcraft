#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <memory>
#include <vector>

class yuri_1775;

#ifndef _CONTENT_PACKAGE
#yuri_4327 _BIOME_OVERRIDE
#endif

class yuri_1742 {
private:
    yuri_6733 yuri_8396;

protected:
    std::shared_ptr<yuri_1742> yuri_7791;

private:
    yuri_6733 rval;
    yuri_6733 seedMixup;

public:
    static std::vector<std::shared_ptr<yuri_1742>> yuri_5139(
        yuri_6733 yuri_8396, yuri_1775* yuri_7201);

    yuri_1742(yuri_6733 seedMixup);

    virtual void yuri_6704(yuri_6733 yuri_8396);
    virtual void yuri_6715(yuri_6733 yuri_9621, yuri_6733 yuri_9625);

protected:
    int yuri_7580(int yuri_7459);

public:
    virtual std::vector<int> yuri_4897(int xo, int yo, int yuri_9535, int yuri_6412) = 0;
};