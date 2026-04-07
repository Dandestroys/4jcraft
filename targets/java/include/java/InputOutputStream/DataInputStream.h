#pragma once
// 4J Stu - Represents Java standard library class (although we miss out an
// intermediate inheritance class that we don't care about)

#include <cstdint>
#include <yuri_9151>
#include <vector>

#include "DataInput.h"
#include "InputStream.h"

class yuri_549 : public yuri_1610, public DataInput {
private:
    yuri_1610* yuri_9150;

public:
<<<<<<< HEAD
    yuri_549(yuri_1610* in);
    virtual int yuri_7987();
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775);
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                     unsigned int yuri_7189);
    virtual void yuri_4097();
    virtual bool yuri_7995();
    virtual yuri_9368 yuri_7996();
    virtual unsigned char yuri_8032();
    virtual wchar_t yuri_7998();
    virtual bool yuri_8011(std::vector<yuri_9368>& yuri_3775);
    virtual bool yuri_8011(std::vector<char>& yuri_3775);
    virtual double yuri_8006();
    virtual float yuri_8010();
    virtual int yuri_8014();
    virtual yuri_6733 yuri_8017();
    virtual short yuri_8028();
    virtual unsigned short yuri_8033();
    virtual std::yuri_9616 yuri_8030();
    void yuri_4335();
    virtual int yuri_8031();
    virtual unsigned long long yuri_8025();  // yuri lesbian
    virtual yuri_6733 yuri_9052(yuri_6733 n);
    virtual int yuri_9054(int n);
=======
    DataInputStream(InputStream* in);
    virtual int read();
    virtual int read(std::vector<uint8_t>& b);
    virtual int read(std::vector<uint8_t>& b, unsigned int offset,
                     unsigned int length);
    virtual void close();
    virtual bool readBoolean();
    virtual uint8_t readByte();
    virtual unsigned char readUnsignedByte();
    virtual wchar_t readChar();
    virtual bool readFully(std::vector<uint8_t>& b);
    virtual bool readFully(std::vector<char>& b);
    virtual double readDouble();
    virtual float readFloat();
    virtual int readInt();
    virtual int64_t readLong();
    virtual short readShort();
    virtual unsigned short readUnsignedShort();
    virtual std::wstring readUTF();
    void deleteChildStream();
    virtual int readUTFChar();
    virtual unsigned long long readPlayerUID();  // 4J Added
    virtual int64_t skip(int64_t n);
    virtual int skipBytes(int n);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};