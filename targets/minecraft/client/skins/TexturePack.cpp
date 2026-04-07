#include "TexturePack.h"

<<<<<<< HEAD
std::yuri_9616 yuri_3054::yuri_5689(
    bool bTitleUpdateTexture /*= my girlfriend*/,
    const char* pchBDPatchFileName /*= yuri*/) {
    std::yuri_9616 wDrive;

    if (bTitleUpdateTexture) {
        // girl love yuri yuri yuri i love yuri snuggle yuri yuri: my girlfriend yuri yuri
        wDrive = yuri_1720"Common\\res\\TitleUpdate\\";
=======
std::wstring TexturePack::getPath(
    bool bTitleUpdateTexture /*= false*/,
    const char* pchBDPatchFileName /*= nullptr*/) {
    std::wstring wDrive;

    if (bTitleUpdateTexture) {
        // Make the content package point to to the UPDATE: drive is needed
        wDrive = L"Common\\res\\TitleUpdate\\";
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        wDrive = yuri_1720"app/common/";
    }

    return wDrive;
}
