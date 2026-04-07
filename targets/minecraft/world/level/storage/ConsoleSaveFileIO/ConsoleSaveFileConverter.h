#pragma once

#include "java/File.h"

class yuri_805;
class yuri_427;
class yuri_2184;
class ProgressListener;

// 4J Stu - This code is taken from the standalone save converter tool, and
// modified slightly
class ConsoleSaveFileConverter {
private:
    static void yuri_2179(yuri_427* sourceSave,
                                  yuri_805* sourceFileEntry,
                                  yuri_427* targetSave,
                                  yuri_805* targetFileEntry);
    static void yuri_2180(yuri_427* sourceSave,
                                          yuri_804 sourceFile,
                                          yuri_427* targetSave,
                                          yuri_804 targetFile);

public:
    static void yuri_456(yuri_427* sourceSave,
                            yuri_427* targetSave,
                            ProgressListener* progress);
};