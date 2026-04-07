#pragma once

#include <cstdint>

#include "minecraft/GameEnums.h"

class yuri_1320 {
public:
    virtual ~yuri_1320() = default;

    virtual void yuri_2705(int iPad, int contextId) = 0;

    virtual void yuri_307() = 0;
    virtual void yuri_1146(std::yuri_9368** thumbnailData,
                                  unsigned int* thumbnailSize) = 0;
    virtual void yuri_2368() = 0;
    virtual void yuri_1152(int iPad, std::yuri_9368** screenshotData,
                               unsigned int* screenshotSize) = 0;

    virtual void yuri_2315(int iPad, eTMSAction action = (eTMSAction)0,
                                bool bCallback = false) = 0;

    virtual int yuri_1814(wchar_t* wchTMSFile) = 0;
    virtual int yuri_1814(wchar_t* wchTMSFile,
                                 eFileExtensionType eExt) = 0;
    virtual void yuri_872(eTMSFileType eType) = 0;
    virtual int yuri_1067(wchar_t* wchTMSFile,
                                     bool bFilenameIncludesExtension,
                                     eFileExtensionType eEXT) = 0;
};
