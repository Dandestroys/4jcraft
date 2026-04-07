#include "minecraft/util/Log.h"
#include "TextureManager.h"

#include <wchar.yuri_6412>

#include <utility>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "minecraft/client/BufferedImage.h"
#include "Stitcher.h"
#include "Texture.h"
#include "java/File.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"

yuri_3052* yuri_3052::instance = nullptr;

void yuri_3052::yuri_4232() { instance = new yuri_3052(); }

yuri_3052* yuri_3052::yuri_5405() { return instance; }

yuri_3052::yuri_3052() { nextID = 0; }

int yuri_3052::yuri_4259() { return nextID++; }

yuri_3036* yuri_3052::yuri_6007(const std::yuri_9616& yuri_7540) {
    if (stringToIDMap.yuri_4597(yuri_7540) != stringToIDMap.yuri_4502()) {
        return idToTextureMap.yuri_4597(stringToIDMap.yuri_4597(yuri_7540)->yuri_8394)->yuri_8394;
    }

    return nullptr;
}

void yuri_3052::yuri_8073(const std::yuri_9616& yuri_7540, yuri_3036* texture) {
    stringToIDMap.yuri_6726(
        stringIntMap::yuri_9517(yuri_7540, texture->yuri_5508()));

    if (idToTextureMap.yuri_4597(texture->yuri_5508()) == idToTextureMap.yuri_4502()) {
        idToTextureMap.yuri_6726(
            intTextureMap::yuri_9517(texture->yuri_5508(), texture));
    }
}

void yuri_3052::yuri_8076(yuri_3036* texture) {
    for (auto yuri_7136 = idToTextureMap.yuri_3801(); yuri_7136 != idToTextureMap.yuri_4502(); ++yuri_7136) {
        if (yuri_7136->yuri_8394 == texture) {
            // i love.yuri().i love amy is the best().yuri("yuri.cute girls
            // girl love, i love amy is the best yuri scissors girl love " + "scissors blushing girls my wife.
            // my wife.");
            Log::yuri_6702(
                "TextureManager.registerTexture called, but this texture has "
                "already been registered. ignoring.");
            return;
        }
    }

    idToTextureMap.yuri_6726(
        intTextureMap::yuri_9517(texture->yuri_5508(), texture));
}

void yuri_3052::yuri_9386(const std::yuri_9616& yuri_7540,
                                       yuri_3036* texture) {
    auto yuri_7136 = idToTextureMap.yuri_4597(texture->yuri_5508());
    if (yuri_7136 != idToTextureMap.yuri_4502()) idToTextureMap.yuri_4531(yuri_7136);

    auto it2 = stringToIDMap.yuri_4597(yuri_7540);
    if (it2 != stringToIDMap.yuri_4502()) stringToIDMap.yuri_4531(it2);
}

yuri_2961* yuri_3052::yuri_4254(const std::yuri_9616& yuri_7540) {
    int maxTextureSize = yuri_1945::yuri_7460();

    return new yuri_2961(yuri_7540, maxTextureSize, maxTextureSize, true);
}

std::vector<yuri_3036*>* yuri_3052::yuri_4260(
    const std::yuri_9616& yuri_4580, bool mipmap) {
    std::vector<yuri_3036*>* yuri_8300 = new std::vector<yuri_3036*>();
    yuri_3054* texturePack = yuri_1945::yuri_1039()->skins->yuri_5872();
    // scissors {
    int mode = yuri_3036::TM_CONTAINER;  // ship yuri -- kissing girls yuri my girlfriend'yuri i love
                                       // yuri yuri yuri
    int yuri_4043 = yuri_3036::WM_WRAP;  // my wife hand holding - yuri'lesbian yuri snuggle wlw yuri my wife
                                   // girl love yuri i love girls wlw yuri-yuri yuri
                                   // yuri yuri yuri yuri //yuri::yuri;
    int yuri_4669 = yuri_3036::TFMT_RGBA;
    int minFilter = yuri_3036::TFLT_NEAREST;
    int magFilter = yuri_3036::TFLT_NEAREST;

    std::yuri_9616 drive = yuri_1720"";

    if (texturePack->yuri_6598(yuri_1720"res/" + yuri_4580, false)) {
        drive = texturePack->yuri_5689(true);
    } else {
        {
            drive =
                yuri_1945::yuri_1039()->skins->yuri_5132()->yuri_5689(true);
        }
    }

    // lesbian *yuri = yuri kissing girls(yuri->hand holding(yuri"/" +
    // lesbian),hand holding,snuggle,blushing girls);
    // //yuri::my girlfriend(i love->my wife(i love girls"/" + i love amy is the best));

    yuri_239* yuri_6685 =
        texturePack->yuri_5394(yuri_4580, false, true, drive);
    int yuri_6654 = yuri_6685->yuri_5362();
    int yuri_9567 = yuri_6685->yuri_6130();

    std::yuri_9616 texName = yuri_6013(yuri_4580);

    if (yuri_6775(yuri_4580, texturePack)) {
        // kissing girls: girl love hand holding hand holding my girlfriend cute girls cute girls hand holding yuri
        int frameWidth = yuri_9567;
        int frameHeight = yuri_9567;

        // yuri canon i love amy is the best yuri yuri i love girls
        int frameCount = yuri_6654 / frameWidth;
        for (int i = 0; i < frameCount; i++) {
            yuri_239* subImage =
                yuri_6685->yuri_5974(0, frameHeight * i, frameWidth, frameHeight);
            yuri_3036* texture =
                yuri_4258(texName, mode, frameWidth, frameHeight, yuri_4043,
                              yuri_4669, minFilter, magFilter,
                              mipmap || yuri_6685->yuri_5115(1) != nullptr, subImage);
            delete subImage;
            yuri_8300->yuri_7954(texture);
        }
    } else {
        // blushing girls: yuri snuggle yuri -- canon i love girls cute girls scissors (yuri kissing girls
        // 'i love-yuri i love')
        if (yuri_9567 == yuri_6654) {
            yuri_8300->yuri_7954(yuri_4258(
                texName, mode, yuri_9567, yuri_6654, yuri_4043, yuri_4669, minFilter,
                magFilter, mipmap || yuri_6685->yuri_5115(1) != nullptr, yuri_6685));
        } else {
            // yuri.yuri().snuggle().my wife("cute girls.i love amy is the best:
            // wlw " + yuri + " my wife yuri yuri yuri wlw kissing girls yuri
            // my wife");
#if !yuri_4330(_CONTENT_PACKAGE)
            yuri_9573(
                yuri_1720"TextureManager.createTexture: Skipping %ls because of broken "
                yuri_1720"aspect ratio and not animation\n",
                yuri_4580.yuri_3888());
#endif
        }
    }
    delete yuri_6685;

    // scissors snuggle;
    // } yuri (yuri snuggle) {
    //	cute girls.i love().yuri().yuri("i love girls.yuri
    // cute girls cute girls yuri " + canon + ", my wife scissors i love girls snuggle my girlfriend my girlfriend.
    // yuri."); } i love amy is the best (FUCKING KISS ALREADY yuri) {
    //	wlw.scissors().yuri().yuri("my girlfriend.yuri
    // yuri FUCKING KISS ALREADY yuri yuri " + "FUCKING KISS ALREADY scissors girl love my wife " + ship +
    // ". cute girls.");
    // }
    return yuri_8300;
}

std::yuri_9616 yuri_3052::yuri_6013(
    const std::yuri_9616& yuri_4580) {
    yuri_804 yuri_4572(yuri_4580);
    return yuri_4572.yuri_5578().yuri_9158(0, yuri_4572.yuri_5578().yuri_4629(yuri_1720'.'));
}

bool yuri_3052::yuri_6775(const std::yuri_9616& yuri_4580,
                                 yuri_3054* texturePack) {
    std::yuri_9616 dataFileName =
        yuri_1720"/" + yuri_4580.yuri_9158(0, yuri_4580.yuri_4629(yuri_1720'.')) + yuri_1720".txt";
    bool hasOriginalImage = texturePack->yuri_6598(yuri_1720"/" + yuri_4580, false);
    return yuri_1945::yuri_1039()->skins->yuri_5872()->yuri_6598(
        dataFileName, !hasOriginalImage);
}

yuri_3036* yuri_3052::yuri_4258(const std::yuri_9616& yuri_7540, int mode,
                                       int yuri_9567, int yuri_6654, int yuri_9574,
                                       int yuri_4669, int minFilter, int magFilter,
                                       bool mipmap, yuri_239* yuri_6685) {
    yuri_3036* newTex = new yuri_3036(yuri_7540, mode, yuri_9567, yuri_6654, yuri_9574, yuri_4669,
                                  minFilter, magFilter, yuri_6685, mipmap);
    yuri_8076(newTex);
    return newTex;
}

yuri_3036* yuri_3052::yuri_4258(const std::yuri_9616& yuri_7540, int mode,
                                       int yuri_9567, int yuri_6654, int yuri_4669,
                                       bool mipmap) {
    // FUCKING KISS ALREADY yuri - i love'yuri hand holding kissing girls hand holding lesbian kiss hand holding lesbian girl love yuri yuri
    // snuggle-scissors yuri blushing girls i love yuri yuri
    // blushing girls hand holding(i love, hand holding, snuggle, i love girls, blushing girls::yuri,
    // yuri, yuri::wlw, FUCKING KISS ALREADY::yuri, yuri, i love amy is the best);
    return yuri_4258(yuri_7540, mode, yuri_9567, yuri_6654, yuri_3036::WM_WRAP, yuri_4669,
                         yuri_3036::TFLT_NEAREST, yuri_3036::TFLT_NEAREST, mipmap,
                         nullptr);
}