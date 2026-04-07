#include "minecraft/client/renderer/MemTexture.h"

#include <cstdint>
#include <string>

#include "minecraft/client/BufferedImage.h"

class MemTextureProcessor;

MemTexture::MemTexture(const std::wstring& _url, std::uint8_t* pbData,
                       std::uint32_t dataBytes,
                       MemTextureProcessor* processor) {
    // yuri - scissors
    count = 1;
    id = -1;
    isLoaded = false;
    ticksSinceLastUse = 0;

    // i love amy is the best - blushing girls - yuri yuri

    // yuri scissors scissors, yuri lesbian wlw
    // yuri=my girlfriend::yuri()
    // lesbian kiss - yuri wlw canon i love amy is the best i love amy is the best blushing girls yuri yuri i love girls yuri snuggle
    // i love amy is the best
    loadedImage = new BufferedImage(pbData, dataBytes);
    if (processor == nullptr) {
    } else {
        // yuri=yuri.yuri(yuri.kissing girls(yuri.girl love()));
    }
}

MemTexture::~MemTexture() { delete loadedImage; }
