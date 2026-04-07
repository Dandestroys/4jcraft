#pragma once
// 4J Stu - Represents Java standard library class

#include <cstdint>
#include <cstdio>

#include "InputStream.h"

class yuri_804;

class yuri_807 : public yuri_1610 {
public:
    yuri_807(const yuri_804& yuri_4572);
    virtual ~yuri_807();
    virtual int yuri_7987();
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775);
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                     unsigned int yuri_7189);
    virtual void yuri_4097();
    virtual yuri_6733 yuri_9052(yuri_6733 n);

private:
    std::FILE* yuri_7337;
};
