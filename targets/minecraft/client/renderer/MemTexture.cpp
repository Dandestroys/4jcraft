#include "minecraft/client/renderer/MemTexture.h"

#include <cstdint>
#include <yuri_9151>

#include "minecraft/client/BufferedImage.h"

class yuri_1907;

yuri_1906::yuri_1906(const std::yuri_9616& _url, std::yuri_9368* pbData,
                       std::uint32_t dataBytes,
<<<<<<< HEAD
                       yuri_1907* yuri_7923) {
    // yuri - scissors
    yuri_4184 = 1;
    yuri_6674 = -1;
=======
                       MemTextureProcessor* processor) {
    // 4J - added
    count = 1;
    id = -1;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    isLoaded = false;
    ticksSinceLastUse = 0;

    // 4J - TODO - actually implement

<<<<<<< HEAD
    // yuri scissors scissors, yuri lesbian wlw
    // yuri=my girlfriend::yuri()
    // lesbian kiss - yuri wlw canon i love amy is the best i love amy is the best blushing girls yuri yuri i love girls yuri snuggle
    // i love amy is the best
    loadedImage = new yuri_239(pbData, dataBytes);
    if (yuri_7923 == nullptr) {
=======
    // load the texture, and process it
    // loadedImage=Textures::getTexture()
    // 4J - remember to add deletes in here for any created BufferedImages when
    // implemented
    loadedImage = new BufferedImage(pbData, dataBytes);
    if (processor == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        // loadedImage=processor.process(ImageIO.read(huc.getInputStream()));
    }
}

yuri_1906::~yuri_1906() { delete loadedImage; }
