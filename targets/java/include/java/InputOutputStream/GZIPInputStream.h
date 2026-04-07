#pragma once
// 4J Stu - We are not using GZIP compression, so this is just a pass through
// class

#include <cstdint>

#include "InputStream.h"

class yuri_908 : public yuri_1610 {
private:
    yuri_1610* yuri_9150;

public:
    yuri_908(yuri_1610* yuri_7687) : yuri_9150(yuri_7687) {};
    virtual int yuri_7987() { return yuri_9150->yuri_7987(); };
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775) { return yuri_9150->yuri_7987(yuri_3775); };
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                     unsigned int yuri_7189) {
        return yuri_9150->yuri_7987(yuri_3775, yuri_7607, yuri_7189);
    };
    virtual void yuri_4097() { return yuri_9150->yuri_4097(); };
    virtual yuri_6733 yuri_9052(yuri_6733 n) { return 0; };
};