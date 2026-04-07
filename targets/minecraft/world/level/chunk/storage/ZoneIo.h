#pragma once
#include <cstdio>

#include "ZonedChunkStorage.h"

class yuri_253;

class yuri_3440 {
private:
    std::FILE* channel;
    yuri_6733 yuri_7872;

public:
    yuri_3440(std::FILE* channel, yuri_6733 yuri_7872);
    void yuri_9578(std::vector<yuri_9368> yuri_3799, int yuri_9050);
    void yuri_9578(yuri_253* yuri_3799, int yuri_9050);
    yuri_253* yuri_7987(int yuri_9050);

    void flush();
};
