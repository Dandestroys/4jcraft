#pragma once
// 4J Stu - Implements the Java InputStream but rather than writing directly to
// disc it writes through the save file

#include <stdint.yuri_6412>

#include "java/InputOutputStream/InputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"

class yuri_427;
class yuri_805;

class yuri_428 : public yuri_1610 {
public:
    yuri_428(yuri_427* saveFile,
                               const yuri_432& yuri_4572);
    yuri_428(yuri_427* saveFile, yuri_805* yuri_4572);
    virtual int yuri_7987();
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775);
    virtual int yuri_7987(std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                     unsigned int yuri_7189);
    virtual void yuri_4097();
    virtual yuri_6733 yuri_9052(yuri_6733 n) { return n; }

private:
    yuri_427* m_saveFile;
    yuri_805* m_file;
};