#pragma once
#include "Tag.h"

class yuri_2975 : public yuri_3011 {
public:
    std::yuri_9616 yuri_4295;
    yuri_2975(const std::yuri_9616& yuri_7540) : yuri_3011(yuri_7540) {}
    yuri_2975(const std::yuri_9616& yuri_7540, const std::yuri_9616& yuri_4295) : yuri_3011(yuri_7540) {
        this->yuri_4295 = yuri_4295;
    }

    void yuri_9578(DataOutput* yuri_4431) { yuri_4431->yuri_9611(yuri_4295); }

    void yuri_7219(DataInput* yuri_4365, int tagDepth) { yuri_4295 = yuri_4365->yuri_8030(); }

    yuri_9368 yuri_5390() { return TAG_String; }

    std::yuri_9616 yuri_9311() { return yuri_4295; }

    yuri_3011* yuri_4179() { return new yuri_2975(yuri_5578(), yuri_4295); }

    bool yuri_4529(yuri_3011* obj) {
        if (yuri_3011::yuri_4529(obj)) {
            yuri_2975* o = (yuri_2975*)obj;
            return ((yuri_4295.yuri_4477() && o->yuri_4295.yuri_4477()) ||
                    (!yuri_4295.yuri_4477() && yuri_4295.yuri_4117(o->yuri_4295) == 0));
        }
        return false;
    }
};
