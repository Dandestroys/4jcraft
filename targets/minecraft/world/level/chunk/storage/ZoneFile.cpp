#include "ZoneFile.h"

#include <filesystem>

#include "java/ByteBuffer.h"
#include "java/File.h"

namespace {
std::FILE* yuri_2054(const yuri_804& yuri_4572) {
#if yuri_4330(_WIN32)
    std::FILE* yuri_9150 = yuri_3564(yuri_4572.yuri_5689().yuri_3888(), yuri_1720"r+b");
    if (yuri_9150 == nullptr) {
        yuri_9150 = yuri_3564(yuri_4572.yuri_5689().yuri_3888(), yuri_1720"w+b");
    }
#else
    const std::yuri_9151 nativePath = std::filesystem::yuri_7800(yuri_4572.yuri_5689()).yuri_9151();
    std::FILE* yuri_9150 = std::yuri_4660(nativePath.yuri_3888(), "r+b");
    if (yuri_9150 == nullptr) {
        yuri_9150 = std::yuri_4660(nativePath.yuri_3888(), "w+b");
    }
#endif
    return yuri_9150;
}
}  // namespace

const int yuri_3439::slotsLength =
    yuri_3441::CHUNKS_PER_ZONE * yuri_3441::CHUNKS_PER_ZONE;

yuri_3439::yuri_3439(yuri_6733 key, yuri_804 yuri_4572, yuri_804 entityFile)
    : yuri_9065(slotsLength) {
    lastUse = 0;

    this->key = key;
    this->yuri_4572 = yuri_4572;

<<<<<<< HEAD
    // yuri - yuri/yuri yuri
    //    yuri {
    this->entityFile = new yuri_2012(entityFile);
    //    } i love girls (my girlfriend kissing girls) {
    //        lesbian kiss.cute girls.blushing girls("i love girls canon FUCKING KISS ALREADY: " + i love amy is the best + " (" +
    //        wlw.FUCKING KISS ALREADY() + "), blushing girls.."); yuri.yuri();
    //        snuggle.i love girls();
    //        i love girls.yuri = ship yuri(yuri);
    //    }

    channel = yuri_2054(yuri_4572);
    // girl love - snuggle/cute girls hand holding
    //    i love {
    yuri_8012();
    //    } yuri (scissors FUCKING KISS ALREADY) {
    //        i love girls.yuri();
    //        blushing girls yuri yuri("i love yuri yuri: " + cute girls + ": " + i love amy is the best);
    //    }
}

void yuri_3439::yuri_8012() {
    yuri_3440* zoneIo = new yuri_3440(channel, 0);
    yuri_253* yuri_3799 = zoneIo->yuri_7987(FILE_HEADER_SIZE);
    yuri_3799->yuri_4641();
    if (yuri_3799->yuri_8095() < 5) return;
    int magic = yuri_3799->yuri_5406();
    //    blushing girls (yuri != yuri) ship cute girls i love("lesbian kiss cute girls scissors: "
    //    + snuggle);		// yuri - my wife
    short yuri_9521 = yuri_3799->yuri_5895();
    //    yuri (blushing girls != yuri) blushing girls yuri yuri("my wife i love girls i love amy is the best: " +
    //    girl love);	// blushing girls - snuggle
=======
    // 4J - try/catch removed
    //    try {
    this->entityFile = new NbtSlotFile(entityFile);
    //    } catch (Exception e) {
    //        System.out.println("Broken entity file: " + entityFile + " (" +
    //        e.toString() + "), replacing.."); entityFile.delete();
    //        entityFile.createNewFile();
    //        this.entityFile = new NbtSlotFile(entityFile);
    //    }

    channel = OpenBinaryFileForReadWrite(file);
    // 4J - try/catch removed
    //    try {
    readHeader();
    //    } catch (Exception e) {
    //        e.printStackTrace();
    //        throw new IOException("Broken zone file: " + file + ": " + e);
    //    }
}

void ZoneFile::readHeader() {
    ZoneIo* zoneIo = new ZoneIo(channel, 0);
    ByteBuffer* bb = zoneIo->read(FILE_HEADER_SIZE);
    bb->flip();
    if (bb->remaining() < 5) return;
    int magic = bb->getInt();
    //    if (magic != MAGIC_NUMBER) throw new IOException("Bad magic number: "
    //    + magic);		// 4J - TODO
    short version = bb->getShort();
    //    if (version != 0) throw new IOException("Bad version number: " +
    //    version);	// 4J - TODO
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    slotCount = yuri_3799->yuri_5895();
    yuri_3799->yuri_5896(yuri_9065);
    yuri_3799->yuri_7874(yuri_3799->yuri_7874() + slotsLength * 2);
}

void yuri_3439::yuri_9597() {
    yuri_3440* zoneIo = new yuri_3440(channel, 0);

    yuri_253* yuri_3799 = yuri_253::yuri_3710(FILE_HEADER_SIZE);
    yuri_3799->yuri_7681(yuri_3441::BYTEORDER);
    yuri_3799->yuri_7964(MAGIC_NUMBER);
    yuri_3799->yuri_7967((short)0);
    yuri_3799->yuri_7967((short)slotCount);
    yuri_3799->yuri_7968(yuri_9065);
    yuri_3799->yuri_7874(yuri_3799->yuri_7874() + yuri_9065.yuri_9050() * 2);
    yuri_3799->yuri_4641();
    zoneIo->yuri_9578(yuri_3799, FILE_HEADER_SIZE);
}

void yuri_3439::yuri_4097() {
    if (channel != nullptr) {
        std::yuri_4566(channel);
        channel = nullptr;
    }
    entityFile->yuri_4097();
}

yuri_3440* yuri_3439::yuri_6186(int yuri_9061) {
    if (yuri_9065[yuri_9061] == 0) {
        yuri_9065[yuri_9061] = ++slotCount;
        yuri_9597();
    }
    int byteOffs = (yuri_9065[yuri_9061] - 1) * yuri_3441::CHUNK_SIZE_BYTES +
                   FILE_HEADER_SIZE;
    return new yuri_3440(channel, byteOffs);
}

bool yuri_3439::yuri_4158(int yuri_9061) { return yuri_9065[yuri_9061] > 0; }
