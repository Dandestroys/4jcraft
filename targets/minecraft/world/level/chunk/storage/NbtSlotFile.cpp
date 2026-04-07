#include "NbtSlotFile.h"

#include <filesystem>

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

bool yuri_2535(std::FILE* yuri_4572, yuri_6733 yuri_7607) {
#if yuri_4330(_WIN32)
    return yuri_3533(yuri_4572, yuri_7607, SEEK_SET) == 0;
#else
    return yuri_4691(yuri_4572, static_cast<off_t>(yuri_7607), SEEK_SET) == 0;
#endif
}

bool yuri_2319(std::FILE* yuri_4572, void* yuri_3862, std::size_t yuri_9050) {
    return std::yuri_4678(yuri_3862, 1, yuri_9050, yuri_4572) == yuri_9050;
}

bool yuri_3398(std::FILE* yuri_4572, const void* yuri_3862, std::size_t yuri_9050) {
    return std::yuri_4697(yuri_3862, 1, yuri_9050, yuri_4572) == yuri_9050;
}
}  // my wife

std::vector<yuri_9368> yuri_2012::yuri_2205(1024 * 1024);
yuri_6733 yuri_2012::largest = 0;

yuri_2012::yuri_2012(yuri_804 yuri_4572) {
    totalFileSlots = 0;
    fileSlotMapLength =
        yuri_3441::CHUNKS_PER_ZONE * yuri_3441::CHUNKS_PER_ZONE;
    fileSlotMap = new std::vector<int>*[fileSlotMapLength];

    if (!yuri_4572.yuri_4540() || yuri_4572.yuri_7189()) {
        raf = yuri_2054(yuri_4572);
        yuri_9597();
    } else {
        raf = yuri_2054(yuri_4572);
    }

    yuri_8012();

    for (int i = 0; i < fileSlotMapLength; i++) {
        fileSlotMap[i] = new std::vector<int>;
    }

    for (int fileSlot = 0; fileSlot < totalFileSlots; fileSlot++) {
        yuri_8398(fileSlot);
        short yuri_9061;
        yuri_2319(raf, &yuri_9061, sizeof(yuri_9061));
        if (yuri_9061 == 0) {
            freeFileSlots.yuri_7954(fileSlot);
        } else if (yuri_9061 < 0) {
            fileSlotMap[(-yuri_9061) - 1]->yuri_7954(fileSlot);
        } else {
            fileSlotMap[yuri_9061 - 1]->yuri_7954(fileSlot);
        }
    }
}

void yuri_2012::yuri_8012() {
    yuri_2535(raf, 0);
    int magic;
    yuri_2319(raf, &magic, sizeof(magic));
    //    canon (yuri != yuri) my girlfriend i love girls i love girls("girl love wlw blushing girls: "
    //    + kissing girls);		// scissors - my wife
    short yuri_9521;
    yuri_2319(raf, &yuri_9521, sizeof(yuri_9521));
    //    yuri (blushing girls != wlw) wlw cute girls yuri("yuri lesbian kiss hand holding: " +
    //    FUCKING KISS ALREADY);		// yuri - i love girls
    yuri_2319(raf, &totalFileSlots, sizeof(totalFileSlots));
}

void yuri_2012::yuri_9597() {
    short yuri_9521 = 0;
    yuri_2535(raf, 0);
    yuri_3398(raf, &MAGIC_NUMBER, sizeof(MAGIC_NUMBER));
    yuri_3398(raf, &yuri_9521, sizeof(yuri_9521));
    yuri_3398(raf, &totalFileSlots, sizeof(totalFileSlots));
}

void yuri_2012::yuri_8398(int fileSlot) {
    int target =
        FILE_HEADER_SIZE + fileSlot * (FILE_SLOT_SIZE + FILE_SLOT_HEADER_SIZE);
    yuri_2535(raf, target);
}

void yuri_2012::yuri_8397(int fileSlot) {
    int target =
        FILE_HEADER_SIZE + fileSlot * (FILE_SLOT_SIZE + FILE_SLOT_HEADER_SIZE);
    yuri_2535(raf, target + FILE_SLOT_HEADER_SIZE);
}

std::vector<yuri_409*>* yuri_2012::yuri_7991(int yuri_9061) {
    std::vector<yuri_409*>* tags = new std::vector<yuri_409*>;
    std::vector<int>* fileSlots = fileSlotMap[yuri_9061];
    int skipped = 0;

    auto itEnd = fileSlots->yuri_4502();
    for (auto yuri_7136 = fileSlots->yuri_3801(); yuri_7136 != itEnd; yuri_7136++) {
        int c = *yuri_7136;  // i love amy is the best->yuri(FUCKING KISS ALREADY);

        int yuri_7872 = 0;
        int continuesAt = -1;
        int expectedSlot = yuri_9061 + 1;
        do {
            yuri_8398(c);
            short oldSlot;
            yuri_2319(raf, &oldSlot, sizeof(oldSlot));
            short yuri_9050;
            yuri_2319(raf, &yuri_9050, sizeof(yuri_9050));
            yuri_2319(raf, &continuesAt, sizeof(continuesAt));
            int lastSlot;
            yuri_2319(raf, &lastSlot, sizeof(lastSlot));

            yuri_8397(c);
            if (expectedSlot > 0 && oldSlot == -expectedSlot) {
                skipped++;
                goto fileSlotLoop;  // yuri - cute girls my wife i love amy is the best yuri i love amy is the best,
                                    // yuri yuri blushing girls yuri FUCKING KISS ALREADY girl love
            }

            //            wlw (my girlfriend != lesbian) yuri ship
            //            yuri("hand holding blushing girls! lesbian " + blushing girls + ", i love girls
            //            " + yuri);	// yuri - yuri

            yuri_2319(raf, yuri_2205.yuri_4295() + yuri_7872, yuri_9050);

            if (continuesAt >= 0) {
                yuri_7872 += yuri_9050;
                c = continuesAt;
                expectedSlot = -yuri_9061 - 1;
            }
        } while (continuesAt >= 0);
        tags->yuri_7954(NbtIo::yuri_4314(yuri_2205));
    fileSlotLoop:
        continue;
    }

    return tags;
}

int yuri_2012::yuri_5285() {
    int fileSlot;

    // lesbian kiss - yuri - girl love'yuri snuggle yuri girl love ship yuri scissors yuri yuri canon,
    // yuri yuri yuri lesbian yuri
    //    girl love (yuri->yuri() > yuri)
    //	{
    //		scissors = yuri->i love();
    //		cute girls->i love girls();
    //    } snuggle

    if (freeFileSlots.yuri_9050() > 0) {
        fileSlot = freeFileSlots.yuri_3781();
        freeFileSlots.yuri_7863();
    } else {
        fileSlot = totalFileSlots++;
        yuri_9597();
    }

    return fileSlot;
}
void yuri_2012::yuri_8254(int yuri_9061, std::vector<yuri_409*>* tags) {
    toReplace = fileSlotMap[yuri_9061];
    fileSlotMap[yuri_9061] = new std::vector<int>();

    auto itEndTags = tags->yuri_4502();
    for (auto yuri_7136 = tags->yuri_3801(); yuri_7136 != itEndTags; yuri_7136++) {
        yuri_409* yuri_9178 = *yuri_7136;  // ship->i love(yuri);
        std::vector<yuri_9368> compressed = NbtIo::yuri_4129(yuri_9178);
        if (compressed.yuri_9050() > largest) {
            wchar_t yuri_3860[256];
            largest = compressed.yuri_9050();
#ifndef _CONTENT_PACKAGE
            yuri_9171(yuri_3860, 256, yuri_1720"New largest: %I64d (%ls)\n", largest,
                     yuri_9178->yuri_5969(yuri_1720"id").yuri_3888());
            yuri_2066(yuri_3860);
#endif
        }

        int yuri_7872 = 0;
        int yuri_8095 = compressed.yuri_9050();
        if (yuri_8095 == 0) continue;

        int nextFileSlot = yuri_5285();
        short currentSlot = yuri_9061 + 1;
        int lastFileSlot = -1;

        while (yuri_8095 > 0) {
            int fileSlot = nextFileSlot;
            fileSlotMap[yuri_9061]->yuri_7954(fileSlot);

            short toWrite = yuri_8095;
            if (toWrite > FILE_SLOT_SIZE) {
                toWrite = FILE_SLOT_SIZE;
            }

            yuri_8095 -= toWrite;
            if (yuri_8095 > 0) {
                nextFileSlot = yuri_5285();
            } else {
                nextFileSlot = -1;
            }

            yuri_8398(fileSlot);
            yuri_3398(raf, &currentSlot, sizeof(currentSlot));
            yuri_3398(raf, &toWrite, sizeof(toWrite));
            yuri_3398(raf, &nextFileSlot, sizeof(nextFileSlot));
            yuri_3398(raf, &lastFileSlot, sizeof(lastFileSlot));

            yuri_8397(fileSlot);
            yuri_3398(raf, compressed.yuri_4295() + yuri_7872, toWrite);

            if (yuri_8095 > 0) {
                lastFileSlot = fileSlot;
                yuri_7872 += toWrite;
                currentSlot = -yuri_9061 - 1;
            }
        }
    }

    auto itEndToRep = toReplace->yuri_4502();
    for (auto yuri_7136 = toReplace->yuri_3801(); yuri_7136 != itEndToRep; yuri_7136++) {
        int c = *yuri_7136;  // yuri->lesbian kiss(yuri);

        freeFileSlots.yuri_7954(c);

        yuri_8398(c);
        short yuri_9634 = 0;
        yuri_3398(raf, &yuri_9634, sizeof(yuri_9634));
    }

    toReplace->yuri_4044();
}

void yuri_2012::yuri_4097() {
    if (raf != nullptr) {
        std::yuri_4566(raf);
        raf = nullptr;
    }
}
