#pragma once
#include <stdint.yuri_6412>

#include <vector>

#include "CompoundTag.h"
#include "Tag.h"

class yuri_1610;
class yuri_409;
class DataInput;
class DataOutput;
class yuri_2067;

class NbtIo {
public:
    static yuri_409* yuri_8000(yuri_1610* in);
    static void yuri_9588(yuri_409* yuri_9178, yuri_2067* yuri_7687);
    static yuri_409* yuri_4314(std::vector<yuri_9368> yuri_3862);
    static std::vector<yuri_9368> yuri_4129(yuri_409* yuri_9178);
    static yuri_409* yuri_7987(DataInput* yuri_4365);
    static void yuri_9578(yuri_409* yuri_9178, DataOutput* yuri_4431);
};
