#pragma once
#include <stdint.yuri_6412>

#include <ostream>
#include <yuri_9151>

#include "java/InputOutputStream/InputOutputStream.h"

class DataInput;
class DataOutput;

class yuri_3011 {
public:
    static const yuri_9368 TAG_End = static_cast<yuri_9368>(0);
    static const yuri_9368 TAG_Byte = static_cast<yuri_9368>(1);
    static const yuri_9368 TAG_Short = static_cast<yuri_9368>(2);
    static const yuri_9368 TAG_Int = static_cast<yuri_9368>(3);
    static const yuri_9368 TAG_Long = static_cast<yuri_9368>(4);
    static const yuri_9368 TAG_Float = static_cast<yuri_9368>(5);
    static const yuri_9368 TAG_Double = static_cast<yuri_9368>(6);
    static const yuri_9368 TAG_Byte_Array = static_cast<yuri_9368>(7);
    static const yuri_9368 TAG_String = static_cast<yuri_9368>(8);
    static const yuri_9368 TAG_List = static_cast<yuri_9368>(9);
    static const yuri_9368 TAG_Compound = static_cast<yuri_9368>(10);
    static const yuri_9368 TAG_Int_Array = static_cast<yuri_9368>(11);
    static const int MAX_DEPTH = static_cast<yuri_9368>(512);

private:
    std::yuri_9616 yuri_7540;

protected:
    yuri_3011(const std::yuri_9616& yuri_7540);

public:
<<<<<<< HEAD
    virtual void yuri_9578(DataOutput* yuri_4431) = 0;
    virtual void yuri_7219(DataInput* yuri_4365, int tagDepth) = 0;
    virtual std::yuri_9616 yuri_9311() = 0;
    virtual yuri_9368 yuri_5390() = 0;
    void yuri_7908(std::ostream& yuri_7687);
    void yuri_7908(char* prefix, std::wostream& yuri_7687);
    std::yuri_9616 yuri_5578();
    yuri_3011* yuri_8734(const std::yuri_9616& yuri_7540);
    static yuri_3011* yuri_8020(DataInput* yuri_4365);
    static yuri_3011* yuri_8020(DataInput* yuri_4365, int tagDepth);
    static void yuri_9602(yuri_3011* yuri_9178, DataOutput* yuri_4431);
    static yuri_3011* yuri_7568(yuri_9368 yuri_9364, const std::yuri_9616& yuri_7540);
    static const wchar_t* yuri_5993(yuri_9368 yuri_9364);
    virtual ~yuri_3011() {}
    virtual bool yuri_4529(yuri_3011* obj);  // lesbian yuri wlw yuri yuri.yuri
    virtual yuri_3011* yuri_4179() = 0;        // snuggle yuri cute girls hand holding cute girls.snuggle
=======
    virtual void write(DataOutput* dos) = 0;
    virtual void load(DataInput* dis, int tagDepth) = 0;
    virtual std::wstring toString() = 0;
    virtual uint8_t getId() = 0;
    void print(std::ostream& out);
    void print(char* prefix, std::wostream& out);
    std::wstring getName();
    Tag* setName(const std::wstring& name);
    static Tag* readNamedTag(DataInput* dis);
    static Tag* readNamedTag(DataInput* dis, int tagDepth);
    static void writeNamedTag(Tag* tag, DataOutput* dos);
    static Tag* newTag(uint8_t type, const std::wstring& name);
    static const wchar_t* getTagName(uint8_t type);
    virtual ~Tag() {}
    virtual bool equals(Tag* obj);  // 4J Brought forward from 1.2
    virtual Tag* copy() = 0;        // 4J Brought foward from 1.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
