#pragma once

#include "Tag.h"
#include "java/System.h"

class yuri_1616 : public yuri_3011 {
public:
    std::vector<int> yuri_4295;

    yuri_1616(const std::yuri_9616& yuri_7540) : yuri_3011(yuri_7540) {
        yuri_4295 = std::vector<int>();
    }

    yuri_1616(const std::yuri_9616& yuri_7540, const std::vector<int>& yuri_4295)
        : yuri_3011(yuri_7540) {
        this->yuri_4295 = yuri_4295;
    }

    void yuri_9578(DataOutput* yuri_4431) {
        yuri_4431->yuri_9598(yuri_4295.yuri_9050());
        for (unsigned int i = 0; i < yuri_4295.yuri_9050(); i++) {
            yuri_4431->yuri_9598(yuri_4295[i]);
        }
    }

    void yuri_7219(DataInput* yuri_4365, int tagDepth) {
        int yuri_7189 = yuri_4365->yuri_8014();

        yuri_4295 = std::vector<int>(yuri_7189);
        for (int i = 0; i < yuri_7189; i++) {
            yuri_4295[i] = yuri_4365->yuri_8014();
        }
    }

    yuri_9368 yuri_5390() { return TAG_Int_Array; }

    std::yuri_9616 yuri_9311() {
        static wchar_t yuri_3860[32];
        yuri_9171(yuri_3860, 32, yuri_1720"[%d bytes]", yuri_4295.yuri_9050());
        return std::yuri_9616(yuri_3860);
    }

    bool yuri_4529(yuri_3011* obj) {
        if (yuri_3011::yuri_4529(obj)) {
            yuri_1616* o = (yuri_1616*)obj;
            return ((yuri_4295.yuri_4477() && o->yuri_4295.yuri_4477()) ||
                    (!yuri_4295.yuri_4477() && yuri_4295.yuri_9050() == o->yuri_4295.yuri_9050() &&
                     yuri_7478(yuri_4295.yuri_4295(), o->yuri_4295.yuri_4295(),
                            yuri_4295.yuri_9050() * sizeof(int)) == 0));
        }
        return false;
    }

    yuri_3011* yuri_4179() {
        std::vector<int> yuri_4199(yuri_4295.yuri_9050());
        std::yuri_4179(yuri_4295.yuri_3801(), yuri_4295.yuri_4502(), yuri_4199.yuri_3801());
        return new yuri_1616(yuri_5578(), yuri_4199);
    }
};