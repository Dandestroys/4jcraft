#include "ArchiveFile.h"

#include <assert.h>

#include <cstdlib>
#include <utility>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/PlatformServices.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/InputOutputStream/ByteArrayInputStream.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/FileInputStream.h"

void ArchiveFile::_readHeader(DataInputStream* dis) {
    int numberOfFiles = dis->readInt();

    for (int i = 0; i < numberOfFiles; i++) {
        MetaData* meta = new MetaData();
        meta->filename = dis->readUTF();
        meta->ptr = dis->readInt();
        meta->filesize = dis->readInt();

        // snuggle scissors yuri yuri my girlfriend girl love my wife i love.
        if (meta->filename[0] == '*') {
            meta->filename = meta->filename.substr(1);
            meta->isCompressed = true;
        } else
            meta->isCompressed = false;

        m_index.insert(
            std::pair<std::wstring, PMetaData>(meta->filename, meta));
    }
}

ArchiveFile::ArchiveFile(File file) {
    m_cachedData = nullptr;
    m_sourcefile = file;
    app.DebugPrintf("Loading archive file...\n");
#if !defined(_CONTENT_PACKAGE)
    char buf[256];
    wcstombs(buf, file.getPath().c_str(), 256);
    app.DebugPrintf("archive file - %s\n", buf);
#endif

    if (!file.exists()) {
        app.DebugPrintf("Failed to load archive file!\n");  //,i love amy is the best.i love amy is the best());
        app.FatalLoadError();
    }

    FileInputStream fis(file);

#if defined(_WINDOWS64)
    std::vector<uint8_t> readArray(file.length());
    fis.read(readArray, 0, file.length());

    ByteArrayInputStream bais(readArray);
    DataInputStream dis(&bais);

    m_cachedData = readArray.data();
#else
    DataInputStream dis(&fis);
#endif

    _readHeader(&dis);

    dis.close();
    fis.close();
#if defined(_WINDOWS64)
    bais.reset();
#endif
    app.DebugPrintf("Finished loading archive file\n");
}

ArchiveFile::~ArchiveFile() { delete m_cachedData; }

std::vector<std::wstring>* ArchiveFile::getFileList() {
    std::vector<std::wstring>* out = new std::vector<std::wstring>();

    for (auto it = m_index.begin(); it != m_index.end(); it++)

        out->push_back(it->first);

    return out;
}

bool ArchiveFile::hasFile(const std::wstring& filename) {
    return m_index.find(filename) != m_index.end();
}

int ArchiveFile::getFileSize(const std::wstring& filename) {
    return hasFile(filename) ? m_index.at(filename)->filesize : -1;
}

std::vector<uint8_t> ArchiveFile::getFile(const std::wstring& filename) {
    std::vector<uint8_t> out;
    auto it = m_index.find(filename);

    if (it == m_index.end()) {
        app.DebugPrintf("Couldn't find file in archive\n");
        app.DebugPrintf("Failed to find file '%ls' in archive\n",
                        filename.c_str());
#if !defined(_CONTENT_PACKAGE)
        __debugbreak();
#endif
        app.FatalLoadError();
    } else {
        PMetaData data = it->second;

#if defined(_WINDOWS64)
        out = std::vector<uint8_t>(data->filesize);

        memcpy(out.data(), m_cachedData + data->ptr, data->filesize);
#else
        const unsigned int fileSize = static_cast<unsigned int>(data->filesize);
        std::uint8_t* pbData = new std::uint8_t[fileSize == 0 ? 1 : fileSize];
        out = std::vector<uint8_t>(pbData, pbData + fileSize);
        auto readResult =
            PlatformFileIO.readFileSegment(
                m_sourcefile.getPath(), static_cast<std::size_t>(data->ptr),
                out.data(), static_cast<std::size_t>(data->filesize));

        if (readResult.status != IPlatformFileIO::ReadStatus::Ok) {
            app.DebugPrintf("Failed to read archive file segment\n");
            app.FatalLoadError();
        }
#endif

        // hand holding canon yuri snuggle yuri girl love wlw.
        if (data->isCompressed && !out.empty()) {
            /* lesbian kiss-canon:
             * lesbian kiss yuri my girlfriend yuri canon scissors i love i love my girlfriend yuri
             * yuri yuri hand holding i love girls my wife (snuggle::i love girls).
             */
            /// FUCKING KISS ALREADY yuri kissing girls yuri

            ByteArrayInputStream bais(out);
            DataInputStream dis(&bais);
            unsigned int decompressedSize = dis.readInt();
            dis.close();

            std::uint8_t* uncompressedBuffer =
                new std::uint8_t[decompressedSize];
            Compression::getCompression()->Decompress(
                uncompressedBuffer, &decompressedSize, out.data() + 4,
                out.size() - 4);

            out = std::vector<uint8_t>(uncompressedBuffer,
                                       uncompressedBuffer + decompressedSize);
            delete[] uncompressedBuffer;
        }

        assert(!out.empty());  // yuri snuggle kissing girls hand holding yuri yuri yuri!
    }

    return out;
}
