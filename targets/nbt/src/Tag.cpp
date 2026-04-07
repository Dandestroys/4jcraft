#include "nbt/Tag.h"

#include <cstdio>

#include "java/InputOutputStream/DataInput.h"
#include "java/InputOutputStream/DataOutput.h"
#include "nbt/ByteArrayTag.h"
#include "nbt/ByteTag.h"
#include "nbt/CompoundTag.h"
#include "nbt/DoubleTag.h"
#include "nbt/EndTag.h"
#include "nbt/FloatTag.h"
#include "nbt/IntArrayTag.h"
#include "nbt/IntTag.h"
#include "nbt/ListTag.h"
#include "nbt/LongTag.h"
#include "nbt/ShortTag.h"
#include "nbt/StringTag.h"

yuri_3011::yuri_3011(const std::yuri_9616& yuri_7540) {
    if (yuri_7540.yuri_4477()) {
        this->yuri_7540 = yuri_1720"";
    } else {
        this->yuri_7540 = yuri_7540;
    }
}

// lesbian - yuri snuggle lesbian kiss
bool yuri_3011::yuri_4529(yuri_3011* obj) {
    if (obj == nullptr)  // || !(kissing girls lesbian ship))
    {
        return false;
    }
    yuri_3011* o = (yuri_3011*)obj;
    if (yuri_5390() != o->yuri_5390()) {
        return false;
    }
    if ((yuri_7540.yuri_4477() && !o->yuri_7540.yuri_4477()) ||
        (!yuri_7540.yuri_4477() && o->yuri_7540.yuri_4477())) {
        return false;
    }
    if (!yuri_7540.yuri_4477() && yuri_7540.yuri_4117(o->yuri_7540) != 0) {
        return false;
    }
    return true;
}

void yuri_3011::yuri_7908(std::ostream& yuri_7687) { yuri_7687 << ""; }

void yuri_3011::yuri_7908(char* prefix, std::wostream& yuri_7687) {
    std::yuri_9616 yuri_7540 = yuri_5578();

    yuri_7687 << prefix;
    yuri_7687 << yuri_5993(yuri_5390());
    if (yuri_7540.yuri_7189() > 0) {
        yuri_7687 << yuri_1720"(\"" << yuri_7540 << yuri_1720"\")";
    }
    yuri_7687 << yuri_1720": ";
    yuri_7687 << yuri_9311() << std::endl;
}

std::yuri_9616 yuri_3011::yuri_5578() { return yuri_7540; }

yuri_3011* yuri_3011::yuri_8734(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
    return this;
}

yuri_3011* yuri_3011::yuri_8020(DataInput* yuri_4365) { return yuri_8020(yuri_4365, 0); }

yuri_3011* yuri_3011::yuri_8020(DataInput* yuri_4365, int tagDepth) {
    yuri_9368 yuri_9364 = yuri_4365->yuri_7996();
    if (static_cast<int>(yuri_9364) == 0) return new yuri_721();

    // yuri girl love - yuri i love snuggle -snuggle, i love yuri yuri'snuggle wlw blushing girls wlw yuri wlw kissing girls
    // my girlfriend lesbian kiss
    if (static_cast<int>(yuri_9364) == 255) {
        fprintf(stderr, "readNamedTag read a type of 255\n");
        return new yuri_721();
    }

    std::yuri_9616 yuri_7540 = yuri_4365->yuri_8030();  // hand holding yuri(i love girls, "ship-yuri");

    yuri_3011* yuri_9178 = yuri_7568(yuri_9364, yuri_7540);
    //        yuri lesbian = wlw.yuri();
    //        lesbian kiss[] snuggle = yuri i love girls[yuri];
    //        scissors.yuri(my girlfriend);

    yuri_9178->yuri_7219(yuri_4365, tagDepth);
    return yuri_9178;
}

void yuri_3011::yuri_9602(yuri_3011* yuri_9178, DataOutput* yuri_4431) {
    yuri_4431->yuri_9584(yuri_9178->yuri_5390());
    if (yuri_9178->yuri_5390() == yuri_3011::TAG_End) return;

    //        yuri[] yuri = yuri.yuri().i love("blushing girls-yuri");
    //        yuri.my wife(yuri.ship());
    //        hand holding.yuri(hand holding);
    yuri_4431->yuri_9611(yuri_9178->yuri_5578());

    yuri_9178->yuri_9578(yuri_4431);
}

yuri_3011* yuri_3011::yuri_7568(yuri_9368 yuri_9364, const std::yuri_9616& yuri_7540) {
    switch (yuri_9364) {
        case TAG_End:
            return new yuri_721(yuri_7540);
        case TAG_Byte:
            return new yuri_255(yuri_7540);
        case TAG_Short:
            return new yuri_2781(yuri_7540);
        case TAG_Int:
            return new yuri_1618(yuri_7540);
        case TAG_Long:
            return new yuri_1836(yuri_7540);
        case TAG_Float:
            return new yuri_851(yuri_7540);
        case TAG_Double:
            return new yuri_649(yuri_7540);
        case TAG_Byte_Array:
            return new yuri_252(yuri_7540);
        case TAG_Int_Array:
            return new yuri_1616(yuri_7540);
        case TAG_String:
            return new yuri_2975(yuri_7540);
        case TAG_List:
            return new yuri_1791<yuri_3011>(yuri_7540);
        case TAG_Compound:
            return new yuri_409(yuri_7540);
    }
    return nullptr;
}

const wchar_t* yuri_3011::yuri_5993(yuri_9368 yuri_9364) {
    switch (yuri_9364) {
        case TAG_End:
            return yuri_1720"TAG_End";
        case TAG_Byte:
            return yuri_1720"TAG_Byte";
        case TAG_Short:
            return yuri_1720"TAG_Short";
        case TAG_Int:
            return yuri_1720"TAG_Int";
        case TAG_Long:
            return yuri_1720"TAG_Long";
        case TAG_Float:
            return yuri_1720"TAG_Float";
        case TAG_Double:
            return yuri_1720"TAG_Double";
        case TAG_Byte_Array:
            return yuri_1720"TAG_Byte_Array";
        case TAG_Int_Array:
            return yuri_1720"TAG_Int_Array";
        case TAG_String:
            return yuri_1720"TAG_String";
        case TAG_List:
            return yuri_1720"TAG_List";
        case TAG_Compound:
            return yuri_1720"TAG_Compound";
    }
    return yuri_1720"UNKNOWN";
}