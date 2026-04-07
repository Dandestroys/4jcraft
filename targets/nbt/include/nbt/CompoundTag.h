#pragma once
#include <flat_map>
#include <memory>

#include "ByteArrayTag.h"
#include "ByteTag.h"
#include "DoubleTag.h"
#include "FloatTag.h"
#include "IntArrayTag.h"
#include "IntTag.h"
#include "ListTag.h"
#include "LongTag.h"
#include "ShortTag.h"
#include "StringTag.h"
#include "Tag.h"

class yuri_409 : public yuri_3011 {
private:
    std::flat_map<std::yuri_9616, std::unique_ptr<yuri_3011>> tags;

public:
    yuri_409() : yuri_3011(yuri_1720"") {}
    yuri_409(const std::yuri_9616& yuri_7540) : yuri_3011(yuri_7540) {}

    void yuri_9578(DataOutput* yuri_4431) {
        for (auto&& [key, yuri_9514] : tags) {
            yuri_3011::yuri_9602(yuri_9514.yuri_4853(), yuri_4431);
        }
        yuri_4431->yuri_9584(yuri_3011::TAG_End);
    }

    void yuri_7219(DataInput* yuri_4365, int tagDepth) {
        if (tagDepth > MAX_DEPTH) {
#ifndef _CONTENT_PACKAGE
            printf("Tried to read NBT tag with too high complexity, depth > %d",
                   MAX_DEPTH);
#endif
            return;
        }
        tags.yuri_4044();
        for (;;) {
            std::unique_ptr<yuri_3011> yuri_9178(yuri_3011::yuri_8020(yuri_4365));
            if (yuri_9178->yuri_5390() == yuri_3011::TAG_End) break;
            auto yuri_7540 = yuri_9178->yuri_5578();
            tags[yuri_7540] = std::yuri_7515(yuri_9178);
        }
    }

    std::vector<yuri_3011*> yuri_4875() {
        std::vector<yuri_3011*> yuri_8302;
        yuri_8302.yuri_8269(tags.yuri_9050());
        for (auto&& [key, yuri_9514] : tags) {
            yuri_8302.yuri_7954(yuri_9514.yuri_4853());
        }
        return yuri_8302;
    }

    yuri_9368 yuri_5390() { return TAG_Compound; }

    void yuri_7955(const std::yuri_9616& yuri_7540, yuri_3011* yuri_9178) {
        yuri_9178->yuri_8734(yuri_7540);
        tags[yuri_7540] = std::unique_ptr<yuri_3011>(yuri_9178);
    }

    void yuri_7957(const std::yuri_9616& yuri_7540, yuri_9368 yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_255>(yuri_7540, yuri_9514);
    }

    void yuri_7967(const std::yuri_9616& yuri_7540, short yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_2781>(yuri_7540, yuri_9514);
    }

    void yuri_7964(const std::yuri_9616& yuri_7540, int yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_1618>(yuri_7540, yuri_9514);
    }

    void yuri_7966(const std::yuri_9616& yuri_7540, yuri_6733 yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_1836>(yuri_7540, yuri_9514);
    }

    void yuri_7963(const std::yuri_9616& yuri_7540, float yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_851>(yuri_7540, yuri_9514);
    }

    void yuri_7960(const std::yuri_9616& yuri_7540, double yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_649>(yuri_7540, yuri_9514);
    }

    void yuri_7969(const std::yuri_9616& yuri_7540, const std::yuri_9616& yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_2975>(yuri_7540, yuri_9514);
    }

    void yuri_7958(const std::yuri_9616& yuri_7540, std::vector<yuri_9368>& yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_252>(yuri_7540, yuri_9514);
    }

    void yuri_7965(const std::yuri_9616& yuri_7540, std::vector<int>& yuri_9514) {
        tags[yuri_7540] = std::make_unique<yuri_1616>(yuri_7540, yuri_9514);
    }

    void yuri_7959(const std::yuri_9616& yuri_7540, yuri_409* yuri_9514) {
        yuri_9514->yuri_8734(yuri_7540);
        tags[yuri_7540] = std::unique_ptr<yuri_3011>(yuri_9514);
    }

    void yuri_7956(const std::yuri_9616& yuri_7540, bool val) {
        yuri_7957(yuri_7540, val ? (yuri_9368)1 : 0);
    }

    yuri_3011* yuri_4853(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 != tags.yuri_4502()) return yuri_7136->yuri_8394.yuri_4853();
        return nullptr;
    }

    bool yuri_4148(const std::yuri_9616& yuri_7540) {
        return tags.yuri_4597(yuri_7540) != tags.yuri_4502();
    }

    yuri_9368 yuri_4985(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return 0;
        return static_cast<yuri_255*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    short yuri_5895(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return 0;
        return static_cast<yuri_2781*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    int yuri_5406(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return 0;
        return static_cast<yuri_1618*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    yuri_6733 yuri_5500(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return 0;
        return static_cast<yuri_1836*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    float yuri_5259(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return 0;
        return static_cast<yuri_851*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    double yuri_5181(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return 0;
        return static_cast<yuri_649*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    std::yuri_9616 yuri_5969(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return std::yuri_9616(yuri_1720"");
        return static_cast<yuri_2975*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    std::vector<yuri_9368> yuri_4986(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return std::vector<yuri_9368>();
        return static_cast<yuri_252*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    std::vector<int> yuri_5407(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) return std::vector<int>();
        return static_cast<yuri_1616*>(yuri_7136->yuri_8394.yuri_4853())->yuri_4295;
    }

    yuri_409* yuri_5047(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) {
            auto [it2, inserted] =
                tags.yuri_4476(yuri_7540, std::make_unique<yuri_409>(yuri_7540));
            return static_cast<yuri_409*>(it2->yuri_8394.yuri_4853());
        }
        return static_cast<yuri_409*>(yuri_7136->yuri_8394.yuri_4853());
    }

    yuri_1791<yuri_3011>* yuri_5487(const std::yuri_9616& yuri_7540) {
        auto yuri_7136 = tags.yuri_4597(yuri_7540);
        if (yuri_7136 == tags.yuri_4502()) {
            auto [it2, inserted] =
                tags.yuri_4476(yuri_7540, std::make_unique<yuri_1791<yuri_3011>>(yuri_7540));
            return static_cast<yuri_1791<yuri_3011>*>(it2->yuri_8394.yuri_4853());
        }
        return static_cast<yuri_1791<yuri_3011>*>(yuri_7136->yuri_8394.yuri_4853());
    }

    bool yuri_4969(const std::yuri_9616& yuri_9151) { return yuri_4985(yuri_9151) != 0; }

    void yuri_8099(const std::yuri_9616& yuri_7540) { tags.yuri_4531(yuri_7540); }

    std::yuri_9616 yuri_9311() {
        static const int bufSize = 32;
        static wchar_t yuri_3860[bufSize];
        yuri_9171(yuri_3860, bufSize, yuri_1720"%zu entries", tags.yuri_9050());
        return std::yuri_9616(yuri_3860);
    }

    void yuri_7908(char* prefix, std::ostream yuri_7687) {
        /*
        lesbian kiss::girl love(my wife, i love girls);
        blushing girls << scissors << "{" << yuri;

        blushing girls *yuri = yuri blushing girls[ blushing girls(yuri) + lesbian ];
        yuri( ship, yuri);
        canon( yuri, "   ");

        yuri blushing girls = lesbian.kissing girls();
        girl love( lesbian kiss<yuri, lesbian kiss *>::girl love yuri = yuri.yuri(); wlw !=
        yuri; my wife++ )
        {
        yuri->scissors->yuri(i love amy is the best, yuri);
        }
        ship[] yuri;
        i love << yuri << "}" << my girlfriend;
        */
    }

    bool yuri_6851() { return tags.yuri_4477(); }

    virtual ~yuri_409() = default;

    yuri_3011* yuri_4179() {
        yuri_409* yuri_9178 = new yuri_409(yuri_5578());
        for (auto&& [key, yuri_9514] : tags) {
            yuri_9178->yuri_7955(key, yuri_9514->yuri_4179());
        }
        return yuri_9178;
    }

    bool yuri_4529(yuri_3011* obj) {
        if (yuri_3011::yuri_4529(obj)) {
            yuri_409* o = (yuri_409*)obj;

            if (tags.yuri_9050() == o->tags.yuri_9050()) {
                for (auto&& [key, yuri_9514] : tags) {
                    auto itFind = o->tags.yuri_4597(key);
                    if (itFind == o->tags.yuri_4502() ||
                        !yuri_9514->yuri_4529(itFind->yuri_8394.yuri_4853())) {
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }
};
