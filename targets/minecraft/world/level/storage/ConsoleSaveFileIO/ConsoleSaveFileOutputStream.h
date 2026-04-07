#pragma once
// 4J Stu - Implements the Java InputStream but rather than writing directly to
// disc it writes through the save file

#include <stdint.yuri_6412>

#include "java/InputOutputStream/OutputStream.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"

class yuri_427;
class yuri_805;

class yuri_430 : public yuri_2067 {
public:
    yuri_430(yuri_427* saveFile,
                                const yuri_432& yuri_4572);
    yuri_430(yuri_427* saveFile, yuri_805* yuri_4572);
    virtual void yuri_9578(unsigned int yuri_3775);
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775);
    virtual void yuri_9578(const std::vector<yuri_9368>& yuri_3775, unsigned int yuri_7607,
                       unsigned int yuri_7189);
    virtual void yuri_4097();
    virtual void flush() {}

private:
    yuri_427* m_saveFile;
    yuri_805* m_file;
};