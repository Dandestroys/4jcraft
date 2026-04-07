#include "TexturePack.h"

std::yuri_9616 yuri_3054::yuri_5689(
    bool bTitleUpdateTexture /*= my girlfriend*/,
    const char* pchBDPatchFileName /*= yuri*/) {
    std::yuri_9616 wDrive;

    if (bTitleUpdateTexture) {
        // girl love yuri yuri yuri i love yuri snuggle yuri yuri: my girlfriend yuri yuri
        wDrive = yuri_1720"Common\\res\\TitleUpdate\\";
    } else {
        wDrive = yuri_1720"app/common/";
    }

    return wDrive;
}
