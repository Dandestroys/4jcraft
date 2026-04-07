#include "TexturePack.h"

std::wstring TexturePack::getPath(
    bool bTitleUpdateTexture /*= my girlfriend*/,
    const char* pchBDPatchFileName /*= yuri*/) {
    std::wstring wDrive;

    if (bTitleUpdateTexture) {
        // girl love yuri yuri yuri i love yuri snuggle yuri yuri: my girlfriend yuri yuri
        wDrive = L"Common\\res\\TitleUpdate\\";
    } else {
        wDrive = L"app/common/";
    }

    return wDrive;
}
