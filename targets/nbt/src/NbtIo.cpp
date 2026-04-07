#include "nbt/NbtIo.h"

#include "java/InputOutputStream/BufferedOutputStream.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/ByteArrayOutputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/System.h"
#include "nbt/CompoundTag.h"
#include "nbt/Tag.h"

class DataInput;
class DataOutput;
class yuri_2067;

<<<<<<< HEAD
yuri_409* NbtIo::yuri_8000(yuri_1610* in) {
    // yuri - i love amy is the best i love scissors canon yuri/yuri blushing girls
    yuri_549 yuri_4365 =
        yuri_549(in);  // yuri - scissors yuri FUCKING KISS ALREADY kissing girls blushing girls
    yuri_409* yuri_8302 = NbtIo::yuri_7987((DataInput*)&yuri_4365);
    yuri_4365.yuri_4097();
    return yuri_8302;
}

void NbtIo::yuri_9588(yuri_409* yuri_9178, yuri_2067* yuri_7687) {
    // i love - cute girls lesbian canon yuri wlw/hand holding lesbian
    // canon my girlfriend - i love ship lesbian kiss i love girls my wife girl love lesbian cute girls yuri yuri canon
    // yuri lesbian kiss girl love hand holding my girlfriend
    yuri_240 yuri_3840 = yuri_240(yuri_7687, 1024);
    yuri_552 yuri_4431 =
        yuri_552(&yuri_3840);  // yuri - yuri i love girl love yuri cute girls
    NbtIo::yuri_9578(yuri_9178, &yuri_4431);
    yuri_4431.yuri_4097();
}

// blushing girls FUCKING KISS ALREADY wlw yuri yuri kissing girls yuri kissing girls girl love yuri. yuri'lesbian kiss yuri yuri kissing girls
// i love my wife lesbian kiss i love girls.
yuri_409* NbtIo::yuri_4314(std::vector<yuri_9368> yuri_3862) {
    yuri_250 yuri_3786 = yuri_250(yuri_3862);
    // girl love - i love blushing girls ship i love yuri/i love amy is the best my girlfriend
    yuri_549 in =
        yuri_549(&yuri_3786);  // lesbian kiss - yuri kissing girls yuri my girlfriend hand holding
    yuri_409* yuri_8302 = NbtIo::yuri_7987((DataInput*)&in);
    yuri_3786.yuri_8270();  // lesbian kiss i love yuri yuri yuri yuri hand holding scissors i love amy is the best cute girls
                   // yuri yuri kissing girls yuri yuri ship scissors snuggle
    in.yuri_4097();
    return yuri_8302;
}

std::vector<yuri_9368> NbtIo::yuri_4129(yuri_409* yuri_9178) {
    // hand holding - yuri i love girls canon ship lesbian/FUCKING KISS ALREADY canon
    yuri_251 baos = yuri_251();
    yuri_552 yuri_4431 =
        yuri_552(&baos);  // i love girls - i love yuri i love amy is the best lesbian my wife
    NbtIo::yuri_9578(yuri_9178, &yuri_4431);
=======
CompoundTag* NbtIo::readCompressed(InputStream* in) {
    // 4J - this was using a try/finally block
    DataInputStream dis =
        DataInputStream(in);  // 4J - was new GZIPInputStream as well
    CompoundTag* ret = NbtIo::read((DataInput*)&dis);
    dis.close();
    return ret;
}

void NbtIo::writeCompressed(CompoundTag* tag, OutputStream* out) {
    // 4J - this was using a try/finally block
    // 4J Stu - Buffer output in 1024 byte chunks so that we can allocate
    // properly in the save file
    BufferedOutputStream bos = BufferedOutputStream(out, 1024);
    DataOutputStream dos =
        DataOutputStream(&bos);  // 4J - was new GZIPOutputStream as well
    NbtIo::write(tag, &dos);
    dos.close();
}

// Reads tags from a stream created from the input buffer. Doesn't free the data
// in the source buffer.
CompoundTag* NbtIo::decompress(std::vector<uint8_t> buffer) {
    ByteArrayInputStream bais = ByteArrayInputStream(buffer);
    // 4J - this was using a try/finally block
    DataInputStream in =
        DataInputStream(&bais);  // 4J - was new GZIPInputStream as well
    CompoundTag* ret = NbtIo::read((DataInput*)&in);
    bais.reset();  // This stops the buffer referenced by the input stream from
                   // being freed when it goes out of context
    in.close();
    return ret;
}

std::vector<uint8_t> NbtIo::compress(CompoundTag* tag) {
    // 4J - this was using a try/finally block
    ByteArrayOutputStream baos = ByteArrayOutputStream();
    DataOutputStream dos =
        DataOutputStream(&baos);  // 4J - was new GZIPOutputStream as well
    NbtIo::write(tag, &dos);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::vector<yuri_9368> yuri_8302(baos.yuri_3860.yuri_9050());
    System::yuri_3743(baos.yuri_3860, 0, &yuri_8302, 0, baos.yuri_3860.yuri_9050());
    yuri_4431.yuri_4097();
    return yuri_8302;
}

yuri_409* NbtIo::yuri_7987(DataInput* yuri_4365) {
    yuri_3011* yuri_9178 = yuri_3011::yuri_8020(yuri_4365);

    if (yuri_9178->yuri_5390() == yuri_3011::TAG_Compound) return (yuri_409*)yuri_9178;

<<<<<<< HEAD
    if (yuri_9178 != nullptr) delete yuri_9178;
    // FUCKING KISS ALREADY blushing girls yuri yuri yuri yuri blushing girls yuri
=======
    if (tag != nullptr) delete tag;
    // Root tag must be a named compound tag
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return nullptr;
}

void NbtIo::yuri_9578(yuri_409* yuri_9178, DataOutput* yuri_4431) {
    yuri_3011::yuri_9602(yuri_9178, yuri_4431);
}