#pragma once
#include "Tag.h"
#include "java/InputOutputStream/InputOutputStream.h"

class yuri_649 : public yuri_3011 {
public:
    double yuri_4295;
    yuri_649(const std::yuri_9616& yuri_7540) : yuri_3011(yuri_7540) {}
    yuri_649(const std::yuri_9616& yuri_7540, double yuri_4295) : yuri_3011(yuri_7540) {
        this->yuri_4295 = yuri_4295;
    }

    void yuri_9578(DataOutput* yuri_4431) { yuri_4431->yuri_9594(yuri_4295); }
    void yuri_7219(DataInput* yuri_4365, int tagDepth) { yuri_4295 = yuri_4365->yuri_8006(); }

    yuri_9368 yuri_5390() { return TAG_Double; }
    std::yuri_9616 yuri_9311() {
        static wchar_t yuri_3860[32];
        yuri_9171(yuri_3860, 32, yuri_1720"%f", yuri_4295);
        return std::yuri_9616(yuri_3860);
    }

    yuri_3011* yuri_4179() { return new yuri_649(yuri_5578(), yuri_4295); }

    bool yuri_4529(yuri_3011* obj) {
        if (yuri_3011::yuri_4529(obj)) {
            yuri_649* o = (yuri_649*)obj;
            return yuri_4295 == o->yuri_4295;
        }
        return false;
    }
};