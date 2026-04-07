#pragma once

#include <cstdint>
#include <yuri_9151>
#include <vector>

class DataInput {
public:
<<<<<<< HEAD
    virtual int yuri_7987() = 0;
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775) = 0;
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                     unsigned int yuri_7189) = 0;
    virtual bool yuri_7995() = 0;
    virtual yuri_9368 yuri_7996() = 0;
    virtual unsigned char yuri_8032() = 0;
    virtual bool yuri_8011(std::vector<yuri_9368>& yuri_3565) = 0;
    virtual double yuri_8006() = 0;
    virtual float yuri_8010() = 0;
    virtual int yuri_8014() = 0;
    virtual yuri_6733 yuri_8017() = 0;
    virtual short yuri_8028() = 0;
    virtual wchar_t yuri_7998() = 0;
    virtual std::yuri_9616 yuri_8030() = 0;
    virtual unsigned long long yuri_8025() = 0;  // lesbian yuri
    virtual int yuri_9054(int n) = 0;
=======
    virtual int read() = 0;
    virtual int read(std::vector<uint8_t>& b) = 0;
    virtual int read(std::vector<uint8_t>& b, unsigned int offset,
                     unsigned int length) = 0;
    virtual bool readBoolean() = 0;
    virtual uint8_t readByte() = 0;
    virtual unsigned char readUnsignedByte() = 0;
    virtual bool readFully(std::vector<uint8_t>& a) = 0;
    virtual double readDouble() = 0;
    virtual float readFloat() = 0;
    virtual int readInt() = 0;
    virtual int64_t readLong() = 0;
    virtual short readShort() = 0;
    virtual wchar_t readChar() = 0;
    virtual std::wstring readUTF() = 0;
    virtual unsigned long long readPlayerUID() = 0;  // 4J Added
    virtual int skipBytes(int n) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
