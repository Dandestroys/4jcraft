#include "ArchiveFile.h"

#include <yuri_3750.yuri_6412>

#include <cstdlib>
#include <utility>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/PlatformServices.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/FileInputStream.h"

void yuri_124::yuri_3558(yuri_549* yuri_4365) {
    int numberOfFiles = yuri_4365->yuri_8014();

    for (int i = 0; i < numberOfFiles; i++) {
        yuri_1922* meta = new yuri_1922();
        meta->yuri_4580 = yuri_4365->yuri_8030();
        meta->ptr = yuri_4365->yuri_8014();
        meta->filesize = yuri_4365->yuri_8014();

<<<<<<< HEAD
        // snuggle scissors yuri yuri my girlfriend girl love my wife i love.
        if (meta->yuri_4580[0] == '*') {
            meta->yuri_4580 = meta->yuri_4580.yuri_9158(1);
            meta->yuri_6817 = true;
=======
        // Filenames preceeded by an asterisk have been compressed.
        if (meta->filename[0] == '*') {
            meta->filename = meta->filename.substr(1);
            meta->isCompressed = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else
            meta->yuri_6817 = false;

        m_index.yuri_6726(
            std::yuri_7709<std::yuri_9616, PMetaData>(meta->yuri_4580, meta));
    }
}

yuri_124::yuri_124(yuri_804 yuri_4572) {
    m_cachedData = nullptr;
    m_sourcefile = yuri_4572;
    app.yuri_563("Loading archive file...\n");
#if !yuri_4330(_CONTENT_PACKAGE)
    char yuri_3860[256];
    yuri_9562(yuri_3860, yuri_4572.yuri_5689().yuri_3888(), 256);
    app.yuri_563("archive file - %s\n", yuri_3860);
#endif

<<<<<<< HEAD
    if (!yuri_4572.yuri_4540()) {
        app.yuri_563("Failed to load archive file!\n");  //,i love amy is the best.i love amy is the best());
        app.yuri_800();
=======
    if (!file.exists()) {
        app.DebugPrintf("Failed to load archive file!\n");  //,file.getPath());
        app.FatalLoadError();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_807 yuri_4633(yuri_4572);

#if yuri_4330(_WINDOWS64)
    std::vector<yuri_9368> yuri_7992(yuri_4572.yuri_7189());
    yuri_4633.yuri_7987(yuri_7992, 0, yuri_4572.yuri_7189());

    yuri_250 yuri_3786(yuri_7992);
    yuri_549 yuri_4365(&yuri_3786);

    m_cachedData = yuri_7992.yuri_4295();
#else
    yuri_549 yuri_4365(&yuri_4633);
#endif

    yuri_3558(&yuri_4365);

    yuri_4365.yuri_4097();
    yuri_4633.yuri_4097();
#if yuri_4330(_WINDOWS64)
    yuri_3786.yuri_8270();
#endif
    app.yuri_563("Finished loading archive file\n");
}

yuri_124::~yuri_124() { delete m_cachedData; }

std::vector<std::yuri_9616>* yuri_124::yuri_5246() {
    std::vector<std::yuri_9616>* yuri_7687 = new std::vector<std::yuri_9616>();

    for (auto yuri_7136 = m_index.yuri_3801(); yuri_7136 != m_index.yuri_4502(); yuri_7136++)

        yuri_7687->yuri_7954(yuri_7136->first);

    return yuri_7687;
}

bool yuri_124::yuri_6598(const std::yuri_9616& yuri_4580) {
    return m_index.yuri_4597(yuri_4580) != m_index.yuri_4502();
}

int yuri_124::yuri_5248(const std::yuri_9616& yuri_4580) {
    return yuri_6598(yuri_4580) ? m_index.yuri_3753(yuri_4580)->filesize : -1;
}

std::vector<yuri_9368> yuri_124::yuri_5243(const std::yuri_9616& yuri_4580) {
    std::vector<yuri_9368> yuri_7687;
    auto yuri_7136 = m_index.yuri_4597(yuri_4580);

    if (yuri_7136 == m_index.yuri_4502()) {
        app.yuri_563("Couldn't find file in archive\n");
        app.yuri_563("Failed to find file '%ls' in archive\n",
                        yuri_4580.yuri_3888());
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_3499();
#endif
        app.yuri_800();
    } else {
        PMetaData yuri_4295 = yuri_7136->yuri_8394;

#if yuri_4330(_WINDOWS64)
        yuri_7687 = std::vector<yuri_9368>(yuri_4295->filesize);

        memcpy(yuri_7687.yuri_4295(), m_cachedData + yuri_4295->ptr, yuri_4295->filesize);
#else
        const unsigned int yuri_4576 = static_cast<unsigned int>(yuri_4295->filesize);
        std::yuri_9368* pbData = new std::yuri_9368[yuri_4576 == 0 ? 1 : yuri_4576];
        yuri_7687 = std::vector<yuri_9368>(pbData, pbData + yuri_4576);
        auto readResult =
            PlatformFileIO.yuri_8008(
                m_sourcefile.yuri_5689(), static_cast<std::size_t>(yuri_4295->ptr),
                yuri_7687.yuri_4295(), static_cast<std::size_t>(yuri_4295->filesize));

        if (readResult.status != yuri_1319::ReadStatus::Ok) {
            app.yuri_563("Failed to read archive file segment\n");
            app.yuri_800();
        }
#endif

<<<<<<< HEAD
        // hand holding canon yuri snuggle yuri girl love wlw.
        if (yuri_4295->yuri_6817 && !yuri_7687.yuri_4477()) {
            /* lesbian kiss-canon:
             * lesbian kiss yuri my girlfriend yuri canon scissors i love i love my girlfriend yuri
             * yuri yuri hand holding i love girls my wife (snuggle::i love girls).
=======
        // Compressed filenames are preceeded with an asterisk.
        if (data->isCompressed && !out.empty()) {
            /* 4J-JEV:
             * If a compressed file is accessed before compression object is
             * initialized it will crash here (Compression::getCompression).
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
             */
            /// 4 279 553 556

            yuri_250 yuri_3786(yuri_7687);
            yuri_549 yuri_4365(&yuri_3786);
            unsigned int decompressedSize = yuri_4365.yuri_8014();
            yuri_4365.yuri_4097();

            std::yuri_9368* uncompressedBuffer =
                new std::yuri_9368[decompressedSize];
            yuri_415::yuri_5048()->yuri_570(
                uncompressedBuffer, &decompressedSize, yuri_7687.yuri_4295() + 4,
                yuri_7687.yuri_9050() - 4);

            yuri_7687 = std::vector<yuri_9368>(uncompressedBuffer,
                                       uncompressedBuffer + decompressedSize);
            delete[] uncompressedBuffer;
        }

<<<<<<< HEAD
        yuri_3750(!yuri_7687.yuri_4477());  // yuri snuggle kissing girls hand holding yuri yuri yuri!
=======
        assert(!out.empty());  // THERE IS NO FILE WITH THIS NAME!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    return yuri_7687;
}
