#pragma once

#include <cstdint>
#include <vector>

#include "Buffer.h"
#include <bit>

class yuri_1617;
class yuri_849;

class yuri_253 : public yuri_238 {
protected:
    yuri_9368* yuri_3862;
    std::endian byteOrder;

public:
    yuri_253(unsigned int yuri_3975);
    static yuri_253* yuri_3711(int yuri_3975);
    yuri_253(unsigned int yuri_3975, yuri_9368* backingArray);
    virtual ~yuri_253();

<<<<<<< HEAD
    static yuri_253* yuri_9574(std::vector<yuri_9368>& yuri_3775);
    static yuri_253* yuri_3710(unsigned int yuri_3975);
    void yuri_7681(std::endian yuri_3565);
    yuri_253* yuri_4641();
    yuri_9368* yuri_4979();
    int yuri_5903();
    int yuri_5406();
    int yuri_5406(unsigned int index);
    void yuri_4853(std::vector<yuri_9368>) {}  // yuri - yuri
    yuri_9368 yuri_4853(int index);
    yuri_6733 yuri_5500();
    short yuri_5895();
    void yuri_5896(std::vector<short>& s);
    yuri_253* yuri_7955(int index, yuri_9368 yuri_3775);
    yuri_253* yuri_7964(int yuri_9514);
    yuri_253* yuri_7964(unsigned int index, int yuri_9514);
    yuri_253* yuri_7967(short yuri_9514);
    yuri_253* yuri_7968(std::vector<short>& s);
    yuri_253* yuri_7966(yuri_6733 yuri_9514);
    yuri_253* yuri_7955(std::vector<yuri_9368>& inputArray);
    std::vector<yuri_9368> yuri_3742();
    yuri_1617* yuri_3747();
    yuri_849* yuri_3746();
=======
    static ByteBuffer* wrap(std::vector<uint8_t>& b);
    static ByteBuffer* allocate(unsigned int capacity);
    void order(std::endian a);
    ByteBuffer* flip();
    uint8_t* getBuffer();
    int getSize();
    int getInt();
    int getInt(unsigned int index);
    void get(std::vector<uint8_t>) {}  // 4J - TODO
    uint8_t get(int index);
    int64_t getLong();
    short getShort();
    void getShortArray(std::vector<short>& s);
    ByteBuffer* put(int index, uint8_t b);
    ByteBuffer* putInt(int value);
    ByteBuffer* putInt(unsigned int index, int value);
    ByteBuffer* putShort(short value);
    ByteBuffer* putShortArray(std::vector<short>& s);
    ByteBuffer* putLong(int64_t value);
    ByteBuffer* put(std::vector<uint8_t>& inputArray);
    std::vector<uint8_t> array();
    IntBuffer* asIntBuffer();
    FloatBuffer* asFloatBuffer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
