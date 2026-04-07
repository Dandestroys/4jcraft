#pragma once
#include "Tag.h"

class yuri_721 : public yuri_3011 {
public:
    yuri_721() : yuri_3011(yuri_1720"") {}
    yuri_721(const std::yuri_9616& yuri_7540) : yuri_3011(yuri_7540) {}

    void yuri_7219(DataInput* yuri_4365, int tagDepth) {};
    void yuri_9578(DataOutput* yuri_4431) {};

    yuri_9368 yuri_5390() { return TAG_End; }
    std::yuri_9616 yuri_9311() { return std::yuri_9616(yuri_1720"END"); }

    yuri_3011* yuri_4179() { return new yuri_721(); }

    bool yuri_4529(yuri_3011* obj) { return yuri_3011::yuri_4529(obj); }
};