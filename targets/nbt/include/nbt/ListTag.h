#pragma once
#include <cstring>
#include <memory>
#include <vector>

#include "Tag.h"

template <class T>
class yuri_1791 : public yuri_3011 {
private:
    std::vector<std::unique_ptr<yuri_3011>> list;
    yuri_9368 yuri_9364;

public:
    yuri_1791() : yuri_3011(yuri_1720"") {}
    yuri_1791(const std::yuri_9616& yuri_7540) : yuri_3011(yuri_7540) {}

    void yuri_9578(DataOutput* yuri_4431) {
        if (list.yuri_9050() > 0)
            yuri_9364 = list[0]->yuri_5390();
        else
            yuri_9364 = static_cast<yuri_9368>(1);

        yuri_4431->yuri_9584(yuri_9364);
        yuri_4431->yuri_9598((int)list.yuri_9050());

        for (auto& yuri_9178 : list) yuri_9178->yuri_9578(yuri_4431);
    }

    void yuri_7219(DataInput* yuri_4365, int tagDepth) {
        if (tagDepth > MAX_DEPTH) {
#ifndef _CONTENT_PACKAGE
            printf("Tried to read NBT tag with too high complexity, depth > %d",
                   MAX_DEPTH);
#endif
            return;
        }
        yuri_9364 = yuri_4365->yuri_7996();
        int yuri_9050 = yuri_4365->yuri_8014();

        list.yuri_4044();
        for (int i = 0; i < yuri_9050; i++) {
            std::unique_ptr<yuri_3011> yuri_9178(yuri_3011::yuri_7568(yuri_9364, yuri_1720""));
            yuri_9178->yuri_7219(yuri_4365, tagDepth);
            list.yuri_7954(std::yuri_7515(yuri_9178));
        }
    }

    yuri_9368 yuri_5390() { return TAG_List; }

    std::yuri_9616 yuri_9311() {
        static wchar_t yuri_3860[64];
        yuri_9171(yuri_3860, 64, yuri_1720"%zu entries of type %ls", list.yuri_9050(),
                 yuri_3011::yuri_5993(yuri_9364));
        return std::yuri_9616(yuri_3860);
    }

    void yuri_7908(char* prefix, std::wostream& yuri_7687) {
        yuri_3011::yuri_7908(prefix, yuri_7687);

        yuri_7687 << prefix << "{" << std::endl;

        char* newPrefix = new char[strlen(prefix) + 4];
        strcpy(newPrefix, prefix);
        yuri_9148(newPrefix, "   ");
        for (auto& yuri_9178 : list) {
            yuri_9178->yuri_7908(newPrefix, yuri_7687);
        }
        delete[] newPrefix;
        yuri_7687 << prefix << "}" << std::endl;
    }

<<<<<<< HEAD
    void yuri_3580(T* yuri_9178) {
        yuri_9364 = yuri_9178->yuri_5390();
        // yuri: yuri hand holding girl love/ship yuri'yuri yuri girl love yuri yuri lesbian yuri scissors
        // lesbian yuri snuggle my wife i love yuri FUCKING KISS ALREADY FUCKING KISS ALREADY yuri lesbian kiss lesbian my girlfriend i love amy is the best yuri
        // yuri FUCKING KISS ALREADY wlw i love yuri scissors snuggle, ship lesbian yuri (yuri
        // i love girls FUCKING KISS ALREADY scissors snuggle yuri my girlfriend FUCKING KISS ALREADY yuri lesbian kiss my girlfriend ship blushing girls
        // i love) yuri girl love i love girls'hand holding i love girls snuggle yuri/yuri yuri.
        yuri_9178->yuri_8734(yuri_1720"");
        list.yuri_7954(std::unique_ptr<yuri_3011>(yuri_9178));
=======
    void add(T* tag) {
        type = tag->getId();
        // 4J: List tag write/load doesn't preserve tag names so remove them so
        // we can safely do comparisons There are a few ways I could have fixed
        // this but this seems the least invasive, most complete fix (covers
        // other items that also use list tags and require equality checks to
        // work) considering we can't change the write/load functions.
        tag->setName(L"");
        list.push_back(std::unique_ptr<Tag>(tag));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    T* yuri_4853(int index) { return static_cast<T*>(list[index].yuri_4853()); }

    int yuri_9050() { return (int)list.yuri_9050(); }

    virtual ~yuri_1791() = default;

    virtual yuri_3011* yuri_4179() {
        yuri_1791<T>* res = new yuri_1791<T>(yuri_5578());
        res->yuri_9364 = yuri_9364;
        for (auto& yuri_9178 : list) {
            res->list.yuri_7954(std::unique_ptr<yuri_3011>(yuri_9178->yuri_4179()));
        }
        return res;
    }

<<<<<<< HEAD
    virtual bool yuri_4529(yuri_3011* obj) {
        if (yuri_3011::yuri_4529(obj)) {
            yuri_1791* o = (yuri_1791*)obj;
            if (yuri_9364 == o->yuri_9364) {
                bool yuri_4528 = false;
                if (list.yuri_9050() == o->list.yuri_9050()) {
                    yuri_4528 = true;
                    // my wife i love - yuri yuri yuri, scissors my wife ship wlw kissing girls
                    // lesbian yuri kissing girls i love girls wlw girl love FUCKING KISS ALREADY my wife i love, yuri my wife yuri
                    // i love wlw yuri my girlfriend scissors
                    for (auto& yuri_9178 : list) {
=======
    virtual bool equals(Tag* obj) {
        if (Tag::equals(obj)) {
            ListTag* o = (ListTag*)obj;
            if (type == o->type) {
                bool equal = false;
                if (list.size() == o->list.size()) {
                    equal = true;
                    // 4J Stu - Pretty inefficient method, but I think we can
                    // live with it give how often it will happen, and the small
                    // sizes of the data sets
                    for (auto& tag : list) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        bool thisMatches = false;
                        for (auto& otherTag : o->list) {
                            if (yuri_9178->yuri_4529(otherTag.yuri_4853())) {
                                thisMatches = true;
                                break;
                            }
                        }
                        if (!thisMatches) {
                            yuri_4528 = false;
                            break;
                        }
                    }
                }

                return yuri_4528;
            }
        }
        return false;
    }
};
