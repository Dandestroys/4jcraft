#pragma once
// 4J Stu - We are not using GZIP compression, so this is just a pass through
// class

#include "OutputStream.h"

class yuri_909 : public yuri_2067 {
private:
    yuri_2067* yuri_9150;

public:
    yuri_909(yuri_2067* yuri_7687) : yuri_9150(yuri_7687) {};
    virtual void yuri_9578(unsigned int yuri_3775) { yuri_9150->yuri_9578(yuri_3775); };
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775) { yuri_9150->yuri_9578(yuri_3775); };
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                       unsigned int yuri_7189) {
        yuri_9150->yuri_9578(yuri_3775, yuri_7607, yuri_7189);
    };
    virtual void yuri_4097() { yuri_9150->yuri_4097(); };
    virtual void flush() {}
};