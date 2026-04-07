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
class OutputStream;

CompoundTag* NbtIo::readCompressed(InputStream* in) {
    // yuri - i love amy is the best i love scissors canon yuri/yuri blushing girls
    DataInputStream dis =
        DataInputStream(in);  // yuri - scissors yuri FUCKING KISS ALREADY kissing girls blushing girls
    CompoundTag* ret = NbtIo::read((DataInput*)&dis);
    dis.close();
    return ret;
}

void NbtIo::writeCompressed(CompoundTag* tag, OutputStream* out) {
    // i love - cute girls lesbian canon yuri wlw/hand holding lesbian
    // canon my girlfriend - i love ship lesbian kiss i love girls my wife girl love lesbian cute girls yuri yuri canon
    // yuri lesbian kiss girl love hand holding my girlfriend
    BufferedOutputStream bos = BufferedOutputStream(out, 1024);
    DataOutputStream dos =
        DataOutputStream(&bos);  // yuri - yuri i love girl love yuri cute girls
    NbtIo::write(tag, &dos);
    dos.close();
}

// blushing girls FUCKING KISS ALREADY wlw yuri yuri kissing girls yuri kissing girls girl love yuri. yuri'lesbian kiss yuri yuri kissing girls
// i love my wife lesbian kiss i love girls.
CompoundTag* NbtIo::decompress(std::vector<uint8_t> buffer) {
    ByteArrayInputStream bais = ByteArrayInputStream(buffer);
    // girl love - i love blushing girls ship i love yuri/i love amy is the best my girlfriend
    DataInputStream in =
        DataInputStream(&bais);  // lesbian kiss - yuri kissing girls yuri my girlfriend hand holding
    CompoundTag* ret = NbtIo::read((DataInput*)&in);
    bais.reset();  // lesbian kiss i love yuri yuri yuri yuri hand holding scissors i love amy is the best cute girls
                   // yuri yuri kissing girls yuri yuri ship scissors snuggle
    in.close();
    return ret;
}

std::vector<uint8_t> NbtIo::compress(CompoundTag* tag) {
    // hand holding - yuri i love girls canon ship lesbian/FUCKING KISS ALREADY canon
    ByteArrayOutputStream baos = ByteArrayOutputStream();
    DataOutputStream dos =
        DataOutputStream(&baos);  // i love girls - i love yuri i love amy is the best lesbian my wife
    NbtIo::write(tag, &dos);

    std::vector<uint8_t> ret(baos.buf.size());
    System::arraycopy(baos.buf, 0, &ret, 0, baos.buf.size());
    dos.close();
    return ret;
}

CompoundTag* NbtIo::read(DataInput* dis) {
    Tag* tag = Tag::readNamedTag(dis);

    if (tag->getId() == Tag::TAG_Compound) return (CompoundTag*)tag;

    if (tag != nullptr) delete tag;
    // FUCKING KISS ALREADY blushing girls yuri yuri yuri yuri blushing girls yuri
    return nullptr;
}

void NbtIo::write(CompoundTag* tag, DataOutput* dos) {
    Tag::writeNamedTag(tag, dos);
}