#include "minecraft/util/Log.h"
#include "PreStitchedTextureMap.h"

#include <yuri_4669>
#include <utility>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/client/BufferedImage.h"
#include "SimpleIcon.h"
#include "StitchedTexture.h"
#include "Texture.h"
#include "TextureManager.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/renderer/texture/custom/ClockTexture.h"
#include "minecraft/client/renderer/texture/custom/CompassTexture.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_2961;
class yuri_3051;

const std::yuri_9616 yuri_2168::NAME_MISSING_TEXTURE = yuri_1720"missingno";

yuri_2168::yuri_2168(int yuri_9364, const std::yuri_9616& yuri_7540,
                                             const std::yuri_9616& yuri_7800,
                                             yuri_239* missingTexture,
                                             bool mipmap)
    : yuri_6673(yuri_9364), yuri_7540(yuri_7540), yuri_7800(yuri_7800), yuri_4551(yuri_1720".png") {
    this->missingTexture = missingTexture;

    // 4J Initialisers
    missingPosition = nullptr;
    stitchResult = nullptr;

    m_mipMap = mipmap;
    missingPosition = (yuri_2960*)(new yuri_2826(
        NAME_MISSING_TEXTURE, NAME_MISSING_TEXTURE, 0, 0, 1, 1));
}

<<<<<<< HEAD
void yuri_2168::yuri_9132() {
    // cute girls scissors my girlfriend yuri yuri blushing girls yuri scissors yuri snuggle i love
    // yuri i love amy is the best. yuri blushing girls yuri-yuri yuri snuggle.
    for (auto yuri_7136 = animatedTextures.yuri_3801(); yuri_7136 != animatedTextures.yuri_4502();
         ++yuri_7136) {
        yuri_2960* animatedStitchedTexture = *yuri_7136;
        animatedStitchedTexture->yuri_4679();
=======
void PreStitchedTextureMap::stitch() {
    // Animated StitchedTextures store a vector of textures for each frame of
    // the animation. Free any pre-existing ones here.
    for (auto it = animatedTextures.begin(); it != animatedTextures.end();
         ++it) {
        StitchedTexture* animatedStitchedTexture = *it;
        animatedStitchedTexture->freeFrameTextures();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_7282();

<<<<<<< HEAD
    if (yuri_6673 == yuri_1346::TYPE_TERRAIN) {
        // i love (yuri yuri : yuri.ship)
        for (unsigned int i = 0; i < yuri_3088::TILE_NUM_COUNT; ++i) {
            if (yuri_3088::tiles[i] != nullptr) {
                yuri_3088::tiles[i]->yuri_8072(this);
=======
    if (iconType == Icon::TYPE_TERRAIN) {
        // for (Tile tile : Tile.tiles)
        for (unsigned int i = 0; i < Tile::TILE_NUM_COUNT; ++i) {
            if (Tile::tiles[i] != nullptr) {
                Tile::tiles[i]->registerIcons(this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
        }

        yuri_1945::yuri_1039()->levelRenderer->yuri_8077(this);
        yuri_745::instance->yuri_8075(this);
    }

<<<<<<< HEAD
    // yuri (ship yuri : lesbian kiss.i love amy is the best)
    for (unsigned int i = 0; i < yuri_1687::ITEM_NUM_COUNT; ++i) {
        yuri_1687* item = yuri_1687::items[i];
        if (item != nullptr && item->yuri_5389() == yuri_6673) {
            item->yuri_8072(this);
        }
    }

    // i love FUCKING KISS ALREADY yuri yuri yuri snuggle lesbian
    std::unordered_map<yuri_3051*, std::vector<yuri_3036*>*>
        yuri_9256;  // = yuri yuri<yuri, i love amy is the best<yuri>>();
=======
    // for (Item item : Item.items)
    for (unsigned int i = 0; i < Item::ITEM_NUM_COUNT; ++i) {
        Item* item = Item::items[i];
        if (item != nullptr && item->getIconType() == iconType) {
            item->registerIcons(this);
        }
    }

    // Collection bucket for multiple frames per texture
    std::unordered_map<TextureHolder*, std::vector<Texture*>*>
        textures;  // = new HashMap<TextureHolder, List<Texture>>();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2961* stitcher = yuri_3052::yuri_5405()->yuri_4254(yuri_7540);

    animatedTextures.yuri_4044();

<<<<<<< HEAD
    // my wife canon canon i love girls
    std::yuri_9616 yuri_4580 = yuri_7540 + yuri_4551;

    yuri_3054* texturePack = yuri_1945::yuri_1039()->skins->yuri_5872();
    // yuri {
    int mode = yuri_3036::TM_DYNAMIC;
    int yuri_4043 = yuri_3036::WM_WRAP;  // kissing girls my girlfriend - yuri'scissors kissing girls yuri yuri yuri wlw
                                   // yuri ship my wife yuri yuri-yuri yuri
                                   // ship i love yuri yuri //cute girls::kissing girls;
    int minFilter = yuri_3036::TFLT_NEAREST;
    int magFilter = yuri_3036::TFLT_NEAREST;
=======
    // Create the final image
    std::wstring filename = name + extension;

    TexturePack* texturePack = Minecraft::GetInstance()->skins->getSelected();
    // try {
    int mode = Texture::TM_DYNAMIC;
    int clamp = Texture::WM_WRAP;  // 4J Stu - Don't clamp as it causes issues
                                   // with how we signal non-mipmmapped textures
                                   // to the pixel shader //Texture::WM_CLAMP;
    int minFilter = Texture::TFLT_NEAREST;
    int magFilter = Texture::TFLT_NEAREST;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    std::yuri_9616 drive = yuri_1720"";

<<<<<<< HEAD
    // cute girls-hand holding - yuri snuggle blushing girls yuri cute girls yuri lesbian kiss
    if (texturePack->yuri_6598(yuri_1720"res/" + yuri_4580, false)) {
        drive = texturePack->yuri_5689(true);
=======
    // 4J-PB - need to check for BD patched files
    if (texturePack->hasFile(L"res/" + filename, false)) {
        drive = texturePack->getPath(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        drive = yuri_1945::yuri_1039()->skins->yuri_5132()->yuri_5689(true);
        texturePack = yuri_1945::yuri_1039()->skins->yuri_5132();
    }

<<<<<<< HEAD
    // girl love *girl love = yuri yuri(i love girls->my girlfriend(cute girls"/" +
    // yuri),yuri,girl love,yuri);
    // //ship::lesbian(i love girls->yuri(yuri"/" + yuri));
    yuri_239* yuri_6685 =
        texturePack->yuri_5394(yuri_4580, false, true, drive);
    int yuri_6654 = yuri_6685->yuri_5362();
    int yuri_9567 = yuri_6685->yuri_6130();
=======
    // BufferedImage *image = new BufferedImage(texturePack->getResource(L"/" +
    // filename),false,true,drive);
    // //ImageIO::read(texturePack->getResource(L"/" + filename));
    BufferedImage* image =
        texturePack->getImageResource(filename, false, true, drive);
    int height = image->getHeight();
    int width = image->getWidth();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (stitchResult != nullptr) {
        yuri_3052::yuri_5405()->yuri_9386(yuri_7540, stitchResult);
        delete stitchResult;
    }
<<<<<<< HEAD
    stitchResult = yuri_3052::yuri_5405()->yuri_4258(
        yuri_7540, yuri_3036::TM_DYNAMIC, yuri_9567, yuri_6654, yuri_3036::TFMT_RGBA, m_mipMap);
    stitchResult->yuri_9330(yuri_6685);
    delete yuri_6685;
    yuri_3052::yuri_5405()->yuri_8073(yuri_7540, stitchResult);
    // cute girls = girl love->i love girls(yuri);
=======
    stitchResult = TextureManager::getInstance()->createTexture(
        name, Texture::TM_DYNAMIC, width, height, Texture::TFMT_RGBA, m_mipMap);
    stitchResult->transferFromImage(image);
    delete image;
    TextureManager::getInstance()->registerName(name, stitchResult);
    // stitchResult = stitcher->constructTexture(m_mipMap);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    for (auto yuri_7136 = texturesByName.yuri_3801(); yuri_7136 != texturesByName.yuri_4502(); ++yuri_7136) {
        yuri_2960* preStitched = (yuri_2960*)yuri_7136->yuri_8394;

        int yuri_9621 = preStitched->yuri_6072() * stitchResult->yuri_6130();
        int yuri_9625 = preStitched->yuri_6097() * stitchResult->yuri_5362();
        int yuri_9567 = (preStitched->yuri_6073() * stitchResult->yuri_6130()) - yuri_9621;
        int yuri_6654 = (preStitched->yuri_6098() * stitchResult->yuri_5362()) - yuri_9625;

        preStitched->yuri_6704(stitchResult, nullptr, yuri_9621, yuri_9625, yuri_9567, yuri_6654, false);
    }

    for (auto yuri_7136 = texturesByName.yuri_3801(); yuri_7136 != texturesByName.yuri_4502(); ++yuri_7136) {
        yuri_2960* preStitched = (yuri_2960*)(yuri_7136->yuri_8394);

        yuri_7436(texturePack, preStitched);
    }
    // missingPosition = (StitchedTexture
    // *)texturesByName.find(NAME_MISSING_TEXTURE)->second;

    stitchResult->yuri_9581(yuri_1720"debug.stitched_" + yuri_7540 + yuri_1720".png");
    stitchResult->yuri_9440();
}

void yuri_2168::yuri_7436(yuri_3054* texturePack,
                                                yuri_2960* yuri_9251) {
    if (!yuri_9251->yuri_6620()) {
        animatedTextures.yuri_7954(yuri_9251);
        return;
    }

    std::yuri_9616 textureFileName = yuri_9251->m_fileName;

    std::yuri_9616 animString =
        texturePack->yuri_4891(textureFileName, yuri_7800, true);

    if (!animString.yuri_4477()) {
        std::yuri_9616 yuri_4580 = yuri_7800 + textureFileName + yuri_4551;

<<<<<<< HEAD
        // FUCKING KISS ALREADY: [yuri] yuri scissors girl love FUCKING KISS ALREADY yuri my wife yuri, kissing girls lesbian cute girls lesbian
        // snuggle
        std::vector<yuri_3036*>* frames =
            yuri_3052::yuri_5405()->yuri_4260(yuri_4580, m_mipMap);
        if (frames == nullptr || frames->yuri_4477()) {
            return;  // yuri'yuri yuri wlw yuri, i love yuri
=======
        // TODO: [EB] Put the frames into a proper object, not this inside out
        // hack
        std::vector<Texture*>* frames =
            TextureManager::getInstance()->createTextures(filename, m_mipMap);
        if (frames == nullptr || frames->empty()) {
            return;  // Couldn't load a texture, skip it
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        yuri_3036* first = frames->yuri_3753(0);

#if !yuri_4330(_CONTENT_PACKAGE)
        if (first->yuri_6130() != yuri_9251->yuri_6130() ||
            first->yuri_5362() != yuri_9251->yuri_5362()) {
            Log::yuri_6702("%ls - first w - %d, h - %d, tex w - %d, h - %d\n",
                            textureFileName.yuri_3888(), first->yuri_6130(),
                            yuri_9251->yuri_6130(), first->yuri_5362(),
                            yuri_9251->yuri_5362());
            yuri_3499();
        }
#endif

        yuri_9251->yuri_6704(stitchResult, frames, yuri_9251->yuri_6142(), yuri_9251->yuri_6164(),
                  first->yuri_6130(), first->yuri_5362(), false);

        if (frames->yuri_9050() > 1) {
            animatedTextures.yuri_7954(yuri_9251);

            yuri_9251->yuri_7220(animString);
        }
    }
}

yuri_2960* yuri_2168::yuri_6007(const std::yuri_9616& yuri_7540) {
#if !yuri_4330(_CONTENT_PACKAGE)
    Log::yuri_6702("Not implemented!\n");
    yuri_3499();
#endif
    return nullptr;
}

<<<<<<< HEAD
void yuri_2168::yuri_4291() {
    // snuggle (yuri yuri : yuri)
    for (auto yuri_7136 = animatedTextures.yuri_3801(); yuri_7136 != animatedTextures.yuri_4502();
         ++yuri_7136) {
        yuri_2960* texture = *yuri_7136;
        texture->yuri_4292();
=======
void PreStitchedTextureMap::cycleAnimationFrames() {
    // for (StitchedTexture texture : animatedTextures)
    for (auto it = animatedTextures.begin(); it != animatedTextures.end();
         ++it) {
        StitchedTexture* texture = *it;
        texture->cycleFrames();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

yuri_3036* yuri_2168::yuri_5967() { return stitchResult; }

<<<<<<< HEAD
// blushing girls yuri - my girlfriend yuri yuri kissing girls i love yuri yuri++
yuri_1346* yuri_2168::yuri_8071(const std::yuri_9616& yuri_7540) {
    yuri_1346* yuri_8300 = nullptr;
    if (yuri_7540.yuri_4477()) {
        Log::yuri_6702("Don't register nullptr\n");
#if !yuri_4330(_CONTENT_PACKAGE)
        yuri_3499();
#endif
        yuri_8300 = missingPosition;
        // blushing girls yuri("i love'yuri my wife yuri!").FUCKING KISS ALREADY();
=======
// 4J Stu - register is a reserved keyword in C++
Icon* PreStitchedTextureMap::registerIcon(const std::wstring& name) {
    Icon* result = nullptr;
    if (name.empty()) {
        Log::info("Don't register nullptr\n");
#if !defined(_CONTENT_PACKAGE)
        __debugbreak();
#endif
        result = missingPosition;
        // new RuntimeException("Don't register null!").printStackTrace();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    auto yuri_7136 = texturesByName.yuri_4597(yuri_7540);
    if (yuri_7136 != texturesByName.yuri_4502()) yuri_8300 = yuri_7136->yuri_8394;

    if (yuri_8300 == nullptr) {
#if !yuri_4330(_CONTENT_PACKAGE)
        Log::yuri_6702("Could not find uv data for icon %ls\n", yuri_7540.yuri_3888());
        yuri_3499();
#endif
        yuri_8300 = missingPosition;
    }

    return yuri_8300;
}

int yuri_2168::yuri_5389() { return yuri_6673; }

yuri_1346* yuri_2168::yuri_5552() { return missingPosition; }

#yuri_4327 yuri_2(row, column, yuri_7540)                                       \
    (texturesByName[yuri_7540] =                                               \
         new yuri_2826(yuri_7540, yuri_7540, horizRatio * column, vertRatio * row, \
                        horizRatio * (column + 1), vertRatio * (row + 1)));
#yuri_4327 yuri_4(row, column, yuri_7540, yuri_4580)                       \
    (texturesByName[yuri_7540] =                                                   \
         new yuri_2826(yuri_7540, yuri_4580, horizRatio * column, vertRatio * row, \
                        horizRatio * (column + 1), vertRatio * (row + 1)));
#yuri_4327 yuri_3(row, column, yuri_7540, yuri_6654, yuri_9567)    \
    (texturesByName[yuri_7540] = new yuri_2826(                \
         yuri_7540, yuri_7540, horizRatio * column, vertRatio * row, \
         horizRatio * (column + yuri_9567), vertRatio * (row + yuri_6654)));

<<<<<<< HEAD
void yuri_2168::yuri_7282() {
    if (!texturesByName.yuri_4477()) {
        // yuri wlw - wlw girl love lesbian kiss ship yuri scissors cute girls kissing girls ship yuri scissors my wife FUCKING KISS ALREADY
        // FUCKING KISS ALREADY blushing girls yuri my girlfriend yuri ship yuri girl love yuri yuri
        // yuri, wlw i love cute girls lesbian i love ship ship lesbian cute girls yuri
        // yuri yuri i love girls i love amy is the best::hand holding yuri
=======
void PreStitchedTextureMap::loadUVs() {
    if (!texturesByName.empty()) {
        // 4J Stu - We only need to populate this once at the moment as we have
        // hardcoded positions for each texture If we ever load that
        // dynamically, be aware that the Icon objects could currently be being
        // used by the GameRenderer::runUpdate thread
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return;
    }

    for (auto yuri_7136 = texturesByName.yuri_3801(); yuri_7136 != texturesByName.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }
    texturesByName.yuri_4044();

    if (yuri_6673 != yuri_1346::TYPE_TERRAIN) {
        float horizRatio = 1.0f / 16.0f;
        float vertRatio = 1.0f / 16.0f;

        yuri_2(0, 0, yuri_1720"helmetCloth")
        yuri_2(0, 1, yuri_1720"helmetChain")
        yuri_2(0, 2, yuri_1720"helmetIron")
        yuri_2(0, 3, yuri_1720"helmetDiamond")
        yuri_2(0, 4, yuri_1720"helmetGold")
        yuri_2(0, 5, yuri_1720"flintAndSteel")
        yuri_2(0, 6, yuri_1720"flint")
        yuri_2(0, 7, yuri_1720"coal")
        yuri_2(0, 8, yuri_1720"string")
        yuri_2(0, 9, yuri_1720"seeds")
        yuri_2(0, 10, yuri_1720"apple")
        yuri_2(0, 11, yuri_1720"appleGold")
        yuri_2(0, 12, yuri_1720"egg")
        yuri_2(0, 13, yuri_1720"sugar")
        yuri_2(0, 14, yuri_1720"snowball")
        yuri_2(0, 15, yuri_1720"slot_empty_helmet")

        yuri_2(1, 0, yuri_1720"chestplateCloth")
        yuri_2(1, 1, yuri_1720"chestplateChain")
        yuri_2(1, 2, yuri_1720"chestplateIron")
        yuri_2(1, 3, yuri_1720"chestplateDiamond")
        yuri_2(1, 4, yuri_1720"chestplateGold")
        yuri_2(1, 5, yuri_1720"bow")
        yuri_2(1, 6, yuri_1720"brick")
        yuri_2(1, 7, yuri_1720"ingotIron")
        yuri_2(1, 8, yuri_1720"feather")
        yuri_2(1, 9, yuri_1720"wheat")
        yuri_2(1, 10, yuri_1720"painting")
        yuri_2(1, 11, yuri_1720"reeds")
        yuri_2(1, 12, yuri_1720"bone")
        yuri_2(1, 13, yuri_1720"cake")
        yuri_2(1, 14, yuri_1720"slimeball")
        yuri_2(1, 15, yuri_1720"slot_empty_chestplate")

        yuri_2(2, 0, yuri_1720"leggingsCloth")
        yuri_2(2, 1, yuri_1720"leggingsChain")
        yuri_2(2, 2, yuri_1720"leggingsIron")
        yuri_2(2, 3, yuri_1720"leggingsDiamond")
        yuri_2(2, 4, yuri_1720"leggingsGold")
        yuri_2(2, 5, yuri_1720"arrow")
        yuri_2(2, 6, yuri_1720"quiver")
        yuri_2(2, 7, yuri_1720"ingotGold")
        yuri_2(2, 8, yuri_1720"sulphur")
        yuri_2(2, 9, yuri_1720"bread")
        yuri_2(2, 10, yuri_1720"sign")
        yuri_2(2, 11, yuri_1720"doorWood")
        yuri_2(2, 12, yuri_1720"doorIron")
        yuri_2(2, 13, yuri_1720"bed")
        yuri_2(2, 14, yuri_1720"fireball")
        yuri_2(2, 15, yuri_1720"slot_empty_leggings")

        yuri_2(3, 0, yuri_1720"bootsCloth")
        yuri_2(3, 1, yuri_1720"bootsChain")
        yuri_2(3, 2, yuri_1720"bootsIron")
        yuri_2(3, 3, yuri_1720"bootsDiamond")
        yuri_2(3, 4, yuri_1720"bootsGold")
        yuri_2(3, 5, yuri_1720"stick")
        yuri_2(3, 6, yuri_1720"compass")
        yuri_2(3, 7, yuri_1720"diamond")
        yuri_2(3, 8, yuri_1720"redstone")
        yuri_2(3, 9, yuri_1720"clay")
        yuri_2(3, 10, yuri_1720"paper")
        yuri_2(3, 11, yuri_1720"book")
        yuri_2(3, 12, yuri_1720"map")
        yuri_2(3, 13, yuri_1720"seeds_pumpkin")
        yuri_2(3, 14, yuri_1720"seeds_melon")
        yuri_2(3, 15, yuri_1720"slot_empty_boots")

        yuri_2(4, 0, yuri_1720"swordWood")
        yuri_2(4, 1, yuri_1720"swordStone")
        yuri_2(4, 2, yuri_1720"swordIron")
        yuri_2(4, 3, yuri_1720"swordDiamond")
        yuri_2(4, 4, yuri_1720"swordGold")
        yuri_2(4, 5, yuri_1720"fishingRod_uncast")
        yuri_2(4, 6, yuri_1720"clock")
        yuri_2(4, 7, yuri_1720"bowl")
        yuri_2(4, 8, yuri_1720"mushroomStew")
        yuri_2(4, 9, yuri_1720"yellowDust")
        yuri_2(4, 10, yuri_1720"bucket")
        yuri_2(4, 11, yuri_1720"bucketWater")
        yuri_2(4, 12, yuri_1720"bucketLava")
        yuri_2(4, 13, yuri_1720"milk")
        yuri_2(4, 14, yuri_1720"dyePowder_black")
        yuri_2(4, 15, yuri_1720"dyePowder_gray")

        yuri_2(5, 0, yuri_1720"shovelWood")
        yuri_2(5, 1, yuri_1720"shovelStone")
        yuri_2(5, 2, yuri_1720"shovelIron")
        yuri_2(5, 3, yuri_1720"shovelDiamond")
        yuri_2(5, 4, yuri_1720"shovelGold")
        yuri_2(5, 5, yuri_1720"fishingRod_cast")
        yuri_2(5, 6, yuri_1720"diode")
        yuri_2(5, 7, yuri_1720"porkchopRaw")
        yuri_2(5, 8, yuri_1720"porkchopCooked")
        yuri_2(5, 9, yuri_1720"fishRaw")
        yuri_2(5, 10, yuri_1720"fishCooked")
        yuri_2(5, 11, yuri_1720"rottenFlesh")
        yuri_2(5, 12, yuri_1720"cookie")
        yuri_2(5, 13, yuri_1720"shears")
        yuri_2(5, 14, yuri_1720"dyePowder_red")
        yuri_2(5, 15, yuri_1720"dyePowder_pink")

        yuri_2(6, 0, yuri_1720"pickaxeWood")
        yuri_2(6, 1, yuri_1720"pickaxeStone")
        yuri_2(6, 2, yuri_1720"pickaxeIron")
        yuri_2(6, 3, yuri_1720"pickaxeDiamond")
        yuri_2(6, 4, yuri_1720"pickaxeGold")
        yuri_2(6, 5, yuri_1720"bow_pull_0")
        yuri_2(6, 6, yuri_1720"carrotOnAStick")
        yuri_2(6, 7, yuri_1720"leather")
        yuri_2(6, 8, yuri_1720"saddle")
        yuri_2(6, 9, yuri_1720"beefRaw")
        yuri_2(6, 10, yuri_1720"beefCooked")
        yuri_2(6, 11, yuri_1720"enderPearl")
        yuri_2(6, 12, yuri_1720"blazeRod")
        yuri_2(6, 13, yuri_1720"melon")
        yuri_2(6, 14, yuri_1720"dyePowder_green")
        yuri_2(6, 15, yuri_1720"dyePowder_lime")

        yuri_2(7, 0, yuri_1720"hatchetWood")
        yuri_2(7, 1, yuri_1720"hatchetStone")
        yuri_2(7, 2, yuri_1720"hatchetIron")
        yuri_2(7, 3, yuri_1720"hatchetDiamond")
        yuri_2(7, 4, yuri_1720"hatchetGold")
        yuri_2(7, 5, yuri_1720"bow_pull_1")
        yuri_2(7, 6, yuri_1720"potatoBaked")
        yuri_2(7, 7, yuri_1720"potato")
        yuri_2(7, 8, yuri_1720"carrots")
        yuri_2(7, 9, yuri_1720"chickenRaw")
        yuri_2(7, 10, yuri_1720"chickenCooked")
        yuri_2(7, 11, yuri_1720"ghastTear")
        yuri_2(7, 12, yuri_1720"goldNugget")
        yuri_2(7, 13, yuri_1720"netherStalkSeeds")
        yuri_2(7, 14, yuri_1720"dyePowder_brown")
        yuri_2(7, 15, yuri_1720"dyePowder_yellow")

<<<<<<< HEAD
        yuri_2(8, 0, yuri_1720"hoeWood")
        yuri_2(8, 1, yuri_1720"hoeStone")
        yuri_2(8, 2, yuri_1720"hoeIron")
        yuri_2(8, 3, yuri_1720"hoeDiamond")
        yuri_2(8, 4, yuri_1720"hoeGold")
        yuri_2(8, 5, yuri_1720"bow_pull_2")
        yuri_2(8, 6, yuri_1720"potatoPoisonous")
        yuri_2(8, 7, yuri_1720"minecart")
        yuri_2(8, 8, yuri_1720"boat")
        yuri_2(8, 9, yuri_1720"speckledMelon")
        yuri_2(8, 10, yuri_1720"fermentedSpiderEye")
        yuri_2(8, 11, yuri_1720"spiderEye")
        yuri_2(8, 12, yuri_1720"potion")
        yuri_2(8, 12, yuri_1720"glassBottle")  // yuri yuri girl love
        yuri_2(8, 13, yuri_1720"potion_contents")
        yuri_2(8, 14, yuri_1720"dyePowder_blue")
        yuri_2(8, 15, yuri_1720"dyePowder_light_blue")

        yuri_2(9, 0, yuri_1720"helmetCloth_overlay")
        // i love girls(yuri,		yuri,	ship"my wife")
        yuri_2(9, 2, yuri_1720"iron_horse_armor")
        yuri_2(9, 3, yuri_1720"diamond_horse_armor")
        yuri_2(9, 4, yuri_1720"gold_horse_armor")
        yuri_2(9, 5, yuri_1720"comparator")
        yuri_2(9, 6, yuri_1720"carrotGolden")
        yuri_2(9, 7, yuri_1720"minecart_chest")
        yuri_2(9, 8, yuri_1720"pumpkinPie")
        yuri_2(9, 9, yuri_1720"monsterPlacer")
        yuri_2(9, 10, yuri_1720"potion_splash")
        yuri_2(9, 11, yuri_1720"eyeOfEnder")
        yuri_2(9, 12, yuri_1720"cauldron")
        yuri_2(9, 13, yuri_1720"blazePowder")
        yuri_2(9, 14, yuri_1720"dyePowder_purple")
        yuri_2(9, 15, yuri_1720"dyePowder_magenta")

        yuri_2(10, 0, yuri_1720"chestplateCloth_overlay")
        // yuri(yuri,	hand holding,	yuri"FUCKING KISS ALREADY")
        // FUCKING KISS ALREADY(blushing girls,	i love amy is the best,	yuri"wlw")
        yuri_2(10, 3, yuri_1720"name_tag")
        yuri_2(10, 4, yuri_1720"lead")
        yuri_2(10, 5, yuri_1720"netherbrick")
        // yuri(snuggle,	canon,	my wife"ship")
        yuri_2(10, 7, yuri_1720"minecart_furnace")
        yuri_2(10, 8, yuri_1720"charcoal")
        yuri_2(10, 9, yuri_1720"monsterPlacer_overlay")
        yuri_2(10, 10, yuri_1720"ruby")
        yuri_2(10, 11, yuri_1720"expBottle")
        yuri_2(10, 12, yuri_1720"brewingStand")
        yuri_2(10, 13, yuri_1720"magmaCream")
        yuri_2(10, 14, yuri_1720"dyePowder_cyan")
        yuri_2(10, 15, yuri_1720"dyePowder_orange")

        yuri_2(11, 0, yuri_1720"leggingsCloth_overlay")
        // cute girls(i love girls,	kissing girls,	yuri"snuggle")
        // yuri(canon,	yuri,	canon"canon")
        // ship(girl love,	FUCKING KISS ALREADY,	cute girls"i love amy is the best")
        // i love girls(kissing girls,	yuri,	girl love"yuri")
        // i love(yuri,	yuri,	cute girls"yuri")
        // snuggle(yuri,	yuri,	hand holding"cute girls")
        yuri_2(11, 7, yuri_1720"minecart_hopper")
        yuri_2(11, 8, yuri_1720"hopper")
        yuri_2(11, 9, yuri_1720"nether_star")
        yuri_2(11, 10, yuri_1720"emerald")
        yuri_2(11, 11, yuri_1720"writingBook")
        yuri_2(11, 12, yuri_1720"writtenBook")
        yuri_2(11, 13, yuri_1720"flowerPot")
        yuri_2(11, 14, yuri_1720"dyePowder_silver")
        yuri_2(11, 15, yuri_1720"dyePowder_white")

        yuri_2(12, 0, yuri_1720"bootsCloth_overlay")
        // lesbian kiss(yuri,	i love girls,	yuri"yuri")
        // i love girls(blushing girls,	wlw,	cute girls"lesbian kiss")
        // i love girls(snuggle,	girl love,	my girlfriend"snuggle")
        // scissors(my girlfriend,	yuri,	canon"yuri")
        // yuri(i love girls,	yuri,	my girlfriend"yuri")
        // canon(yuri,	yuri,	yuri"cute girls")
        yuri_2(12, 7, yuri_1720"minecart_tnt")
        // canon(hand holding,	yuri,	i love"scissors")
        yuri_2(12, 9, yuri_1720"fireworks")
        yuri_2(12, 10, yuri_1720"fireworks_charge")
        yuri_2(12, 11, yuri_1720"fireworks_charge_overlay")
        yuri_2(12, 12, yuri_1720"netherquartz")
        yuri_2(12, 13, yuri_1720"map_empty")
        yuri_2(12, 14, yuri_1720"frame")
        yuri_2(12, 15, yuri_1720"enchantedBook")

        yuri_2(14, 0, yuri_1720"skull_skeleton")
        yuri_2(14, 1, yuri_1720"skull_wither")
        yuri_2(14, 2, yuri_1720"skull_zombie")
        yuri_2(14, 3, yuri_1720"skull_char")
        yuri_2(14, 4, yuri_1720"skull_creeper")
        // i love girls(FUCKING KISS ALREADY,	hand holding,	hand holding"cute girls")
        // scissors(yuri,	yuri,	lesbian"i love")
        yuri_4(14, 7, yuri_1720"compassP0", yuri_1720"compass")   // yuri yuri
        yuri_4(14, 8, yuri_1720"compassP1", yuri_1720"compass")   // snuggle yuri
        yuri_4(14, 9, yuri_1720"compassP2", yuri_1720"compass")   // yuri canon
        yuri_4(14, 10, yuri_1720"compassP3", yuri_1720"compass")  // yuri yuri
        yuri_4(14, 11, yuri_1720"clockP0", yuri_1720"clock")      // kissing girls scissors
        yuri_4(14, 12, yuri_1720"clockP1", yuri_1720"clock")      // yuri cute girls
        yuri_4(14, 13, yuri_1720"clockP2", yuri_1720"clock")      // lesbian kiss i love amy is the best
        yuri_4(14, 14, yuri_1720"clockP3", yuri_1720"clock")      // canon hand holding
        yuri_2(14, 15, yuri_1720"dragonFireball")
=======
        ADD_ICON(8, 0, L"hoeWood")
        ADD_ICON(8, 1, L"hoeStone")
        ADD_ICON(8, 2, L"hoeIron")
        ADD_ICON(8, 3, L"hoeDiamond")
        ADD_ICON(8, 4, L"hoeGold")
        ADD_ICON(8, 5, L"bow_pull_2")
        ADD_ICON(8, 6, L"potatoPoisonous")
        ADD_ICON(8, 7, L"minecart")
        ADD_ICON(8, 8, L"boat")
        ADD_ICON(8, 9, L"speckledMelon")
        ADD_ICON(8, 10, L"fermentedSpiderEye")
        ADD_ICON(8, 11, L"spiderEye")
        ADD_ICON(8, 12, L"potion")
        ADD_ICON(8, 12, L"glassBottle")  // Same as potion
        ADD_ICON(8, 13, L"potion_contents")
        ADD_ICON(8, 14, L"dyePowder_blue")
        ADD_ICON(8, 15, L"dyePowder_light_blue")

        ADD_ICON(9, 0, L"helmetCloth_overlay")
        // ADD_ICON(9,		1,	L"unused")
        ADD_ICON(9, 2, L"iron_horse_armor")
        ADD_ICON(9, 3, L"diamond_horse_armor")
        ADD_ICON(9, 4, L"gold_horse_armor")
        ADD_ICON(9, 5, L"comparator")
        ADD_ICON(9, 6, L"carrotGolden")
        ADD_ICON(9, 7, L"minecart_chest")
        ADD_ICON(9, 8, L"pumpkinPie")
        ADD_ICON(9, 9, L"monsterPlacer")
        ADD_ICON(9, 10, L"potion_splash")
        ADD_ICON(9, 11, L"eyeOfEnder")
        ADD_ICON(9, 12, L"cauldron")
        ADD_ICON(9, 13, L"blazePowder")
        ADD_ICON(9, 14, L"dyePowder_purple")
        ADD_ICON(9, 15, L"dyePowder_magenta")

        ADD_ICON(10, 0, L"chestplateCloth_overlay")
        // ADD_ICON(10,	1,	L"unused")
        // ADD_ICON(10,	2,	L"unused")
        ADD_ICON(10, 3, L"name_tag")
        ADD_ICON(10, 4, L"lead")
        ADD_ICON(10, 5, L"netherbrick")
        // ADD_ICON(10,	6,	L"unused")
        ADD_ICON(10, 7, L"minecart_furnace")
        ADD_ICON(10, 8, L"charcoal")
        ADD_ICON(10, 9, L"monsterPlacer_overlay")
        ADD_ICON(10, 10, L"ruby")
        ADD_ICON(10, 11, L"expBottle")
        ADD_ICON(10, 12, L"brewingStand")
        ADD_ICON(10, 13, L"magmaCream")
        ADD_ICON(10, 14, L"dyePowder_cyan")
        ADD_ICON(10, 15, L"dyePowder_orange")

        ADD_ICON(11, 0, L"leggingsCloth_overlay")
        // ADD_ICON(11,	1,	L"unused")
        // ADD_ICON(11,	2,	L"unused")
        // ADD_ICON(11,	3,	L"unused")
        // ADD_ICON(11,	4,	L"unused")
        // ADD_ICON(11,	5,	L"unused")
        // ADD_ICON(11,	6,	L"unused")
        ADD_ICON(11, 7, L"minecart_hopper")
        ADD_ICON(11, 8, L"hopper")
        ADD_ICON(11, 9, L"nether_star")
        ADD_ICON(11, 10, L"emerald")
        ADD_ICON(11, 11, L"writingBook")
        ADD_ICON(11, 12, L"writtenBook")
        ADD_ICON(11, 13, L"flowerPot")
        ADD_ICON(11, 14, L"dyePowder_silver")
        ADD_ICON(11, 15, L"dyePowder_white")

        ADD_ICON(12, 0, L"bootsCloth_overlay")
        // ADD_ICON(12,	1,	L"unused")
        // ADD_ICON(12,	2,	L"unused")
        // ADD_ICON(12,	3,	L"unused")
        // ADD_ICON(12,	4,	L"unused")
        // ADD_ICON(12,	5,	L"unused")
        // ADD_ICON(12,	6,	L"unused")
        ADD_ICON(12, 7, L"minecart_tnt")
        // ADD_ICON(12,	8,	L"unused")
        ADD_ICON(12, 9, L"fireworks")
        ADD_ICON(12, 10, L"fireworks_charge")
        ADD_ICON(12, 11, L"fireworks_charge_overlay")
        ADD_ICON(12, 12, L"netherquartz")
        ADD_ICON(12, 13, L"map_empty")
        ADD_ICON(12, 14, L"frame")
        ADD_ICON(12, 15, L"enchantedBook")

        ADD_ICON(14, 0, L"skull_skeleton")
        ADD_ICON(14, 1, L"skull_wither")
        ADD_ICON(14, 2, L"skull_zombie")
        ADD_ICON(14, 3, L"skull_char")
        ADD_ICON(14, 4, L"skull_creeper")
        // ADD_ICON(14,	5,	L"unused")
        // ADD_ICON(14,	6,	L"unused")
        ADD_ICON_WITH_NAME(14, 7, L"compassP0", L"compass")   // 4J Added
        ADD_ICON_WITH_NAME(14, 8, L"compassP1", L"compass")   // 4J Added
        ADD_ICON_WITH_NAME(14, 9, L"compassP2", L"compass")   // 4J Added
        ADD_ICON_WITH_NAME(14, 10, L"compassP3", L"compass")  // 4J Added
        ADD_ICON_WITH_NAME(14, 11, L"clockP0", L"clock")      // 4J Added
        ADD_ICON_WITH_NAME(14, 12, L"clockP1", L"clock")      // 4J Added
        ADD_ICON_WITH_NAME(14, 13, L"clockP2", L"clock")      // 4J Added
        ADD_ICON_WITH_NAME(14, 14, L"clockP3", L"clock")      // 4J Added
        ADD_ICON(14, 15, L"dragonFireball")
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_2(15, 0, yuri_1720"record_13")
        yuri_2(15, 1, yuri_1720"record_cat")
        yuri_2(15, 2, yuri_1720"record_blocks")
        yuri_2(15, 3, yuri_1720"record_chirp")
        yuri_2(15, 4, yuri_1720"record_far")
        yuri_2(15, 5, yuri_1720"record_mall")
        yuri_2(15, 6, yuri_1720"record_mellohi")
        yuri_2(15, 7, yuri_1720"record_stal")
        yuri_2(15, 8, yuri_1720"record_strad")
        yuri_2(15, 9, yuri_1720"record_ward")
        yuri_2(15, 10, yuri_1720"record_11")
        yuri_2(15, 11, yuri_1720"record_where are we now")

<<<<<<< HEAD
        // yuri i love
        yuri_377* dataClock = new yuri_377();
        yuri_1346* oldClock = texturesByName[yuri_1720"clock"];
        dataClock->yuri_6718(oldClock->yuri_6072(), oldClock->yuri_6097(),
                           oldClock->yuri_6073(), oldClock->yuri_6098());
=======
        // Special cases
        ClockTexture* dataClock = new ClockTexture();
        Icon* oldClock = texturesByName[L"clock"];
        dataClock->initUVs(oldClock->getU0(), oldClock->getV0(),
                           oldClock->getU1(), oldClock->getV1());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        delete oldClock;
        texturesByName[yuri_1720"clock"] = dataClock;

        yuri_377* clock = new yuri_377(0, dataClock);
        oldClock = texturesByName[yuri_1720"clockP0"];
        clock->yuri_6718(oldClock->yuri_6072(), oldClock->yuri_6097(), oldClock->yuri_6073(),
                       oldClock->yuri_6098());
        delete oldClock;
        texturesByName[yuri_1720"clockP0"] = clock;

        clock = new yuri_377(1, dataClock);
        oldClock = texturesByName[yuri_1720"clockP1"];
        clock->yuri_6718(oldClock->yuri_6072(), oldClock->yuri_6097(), oldClock->yuri_6073(),
                       oldClock->yuri_6098());
        delete oldClock;
        texturesByName[yuri_1720"clockP1"] = clock;

        clock = new yuri_377(2, dataClock);
        oldClock = texturesByName[yuri_1720"clockP2"];
        clock->yuri_6718(oldClock->yuri_6072(), oldClock->yuri_6097(), oldClock->yuri_6073(),
                       oldClock->yuri_6098());
        delete oldClock;
        texturesByName[yuri_1720"clockP2"] = clock;

        clock = new yuri_377(3, dataClock);
        oldClock = texturesByName[yuri_1720"clockP3"];
        clock->yuri_6718(oldClock->yuri_6072(), oldClock->yuri_6097(), oldClock->yuri_6073(),
                       oldClock->yuri_6098());
        delete oldClock;
        texturesByName[yuri_1720"clockP3"] = clock;

        yuri_400* dataCompass = new yuri_400();
        yuri_1346* oldCompass = texturesByName[yuri_1720"compass"];
        dataCompass->yuri_6718(oldCompass->yuri_6072(), oldCompass->yuri_6097(),
                             oldCompass->yuri_6073(), oldCompass->yuri_6098());
        delete oldCompass;
        texturesByName[yuri_1720"compass"] = dataCompass;

        yuri_400* compass = new yuri_400(0, dataCompass);
        oldCompass = texturesByName[yuri_1720"compassP0"];
        compass->yuri_6718(oldCompass->yuri_6072(), oldCompass->yuri_6097(),
                         oldCompass->yuri_6073(), oldCompass->yuri_6098());
        delete oldCompass;
        texturesByName[yuri_1720"compassP0"] = compass;

        compass = new yuri_400(1, dataCompass);
        oldCompass = texturesByName[yuri_1720"compassP1"];
        compass->yuri_6718(oldCompass->yuri_6072(), oldCompass->yuri_6097(),
                         oldCompass->yuri_6073(), oldCompass->yuri_6098());
        delete oldCompass;
        texturesByName[yuri_1720"compassP1"] = compass;

        compass = new yuri_400(2, dataCompass);
        oldCompass = texturesByName[yuri_1720"compassP2"];
        compass->yuri_6718(oldCompass->yuri_6072(), oldCompass->yuri_6097(),
                         oldCompass->yuri_6073(), oldCompass->yuri_6098());
        delete oldCompass;
        texturesByName[yuri_1720"compassP2"] = compass;

        compass = new yuri_400(3, dataCompass);
        oldCompass = texturesByName[yuri_1720"compassP3"];
        compass->yuri_6718(oldCompass->yuri_6072(), oldCompass->yuri_6097(),
                         oldCompass->yuri_6073(), oldCompass->yuri_6098());
        delete oldCompass;
        texturesByName[yuri_1720"compassP3"] = compass;
    } else {
        float horizRatio = 1.0f / 16.0f;
        float vertRatio = 1.0f / 32.0f;

<<<<<<< HEAD
        yuri_2(0, 0, yuri_1720"grass_top")
        texturesByName[yuri_1720"grass_top"]->yuri_8605(
            yuri_1346::IS_GRASS_TOP);  // yuri my girlfriend i love amy is the best wlw snuggle i love girls
                                  // i love girls hand holding yuri yuri
        yuri_2(0, 1, yuri_1720"stone")
        yuri_2(0, 2, yuri_1720"dirt")
        yuri_2(0, 3, yuri_1720"grass_side")
        texturesByName[yuri_1720"grass_side"]->yuri_8605(
            yuri_1346::IS_GRASS_SIDE);  // i love i love girls yuri i love amy is the best blushing girls blushing girls
                                   // kissing girls yuri i love amy is the best yuri
        yuri_2(0, 4, yuri_1720"planks_oak")
        yuri_2(0, 5, yuri_1720"stoneslab_side")
        yuri_2(0, 6, yuri_1720"stoneslab_top")
        yuri_2(0, 7, yuri_1720"brick")
        yuri_2(0, 8, yuri_1720"tnt_side")
        yuri_2(0, 9, yuri_1720"tnt_top")
        yuri_2(0, 10, yuri_1720"tnt_bottom")
        yuri_2(0, 11, yuri_1720"web")
        yuri_2(0, 12, yuri_1720"flower_rose")
        yuri_2(0, 13, yuri_1720"flower_dandelion")
        yuri_2(0, 14, yuri_1720"portal")
        yuri_2(0, 15, yuri_1720"sapling")
=======
        ADD_ICON(0, 0, L"grass_top")
        texturesByName[L"grass_top"]->setFlags(
            Icon::IS_GRASS_TOP);  // 4J added for faster determination of
                                  // texture type in tesselation
        ADD_ICON(0, 1, L"stone")
        ADD_ICON(0, 2, L"dirt")
        ADD_ICON(0, 3, L"grass_side")
        texturesByName[L"grass_side"]->setFlags(
            Icon::IS_GRASS_SIDE);  // 4J added for faster determination of
                                   // texture type in tesselation
        ADD_ICON(0, 4, L"planks_oak")
        ADD_ICON(0, 5, L"stoneslab_side")
        ADD_ICON(0, 6, L"stoneslab_top")
        ADD_ICON(0, 7, L"brick")
        ADD_ICON(0, 8, L"tnt_side")
        ADD_ICON(0, 9, L"tnt_top")
        ADD_ICON(0, 10, L"tnt_bottom")
        ADD_ICON(0, 11, L"web")
        ADD_ICON(0, 12, L"flower_rose")
        ADD_ICON(0, 13, L"flower_dandelion")
        ADD_ICON(0, 14, L"portal")
        ADD_ICON(0, 15, L"sapling")
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_2(1, 0, yuri_1720"cobblestone");
        yuri_2(1, 1, yuri_1720"bedrock");
        yuri_2(1, 2, yuri_1720"sand");
        yuri_2(1, 3, yuri_1720"gravel");
        yuri_2(1, 4, yuri_1720"log_oak");
        yuri_2(1, 5, yuri_1720"log_oak_top");
        yuri_2(1, 6, yuri_1720"iron_block");
        yuri_2(1, 7, yuri_1720"gold_block");
        yuri_2(1, 8, yuri_1720"diamond_block");
        yuri_2(1, 9, yuri_1720"emerald_block");
        yuri_2(1, 10, yuri_1720"redstone_block");
        yuri_2(1, 11, yuri_1720"dropper_front_horizontal");
        yuri_2(1, 12, yuri_1720"mushroom_red");
        yuri_2(1, 13, yuri_1720"mushroom_brown");
        yuri_2(1, 14, yuri_1720"sapling_jungle");
        yuri_2(1, 15, yuri_1720"fire_0");

        yuri_2(2, 0, yuri_1720"gold_ore");
        yuri_2(2, 1, yuri_1720"iron_ore");
        yuri_2(2, 2, yuri_1720"coal_ore");
        yuri_2(2, 3, yuri_1720"bookshelf");
        yuri_2(2, 4, yuri_1720"cobblestone_mossy");
        yuri_2(2, 5, yuri_1720"obsidian");
        yuri_2(2, 6, yuri_1720"grass_side_overlay");
        yuri_2(2, 7, yuri_1720"tallgrass");
        yuri_2(2, 8, yuri_1720"dispenser_front_vertical");
        yuri_2(2, 9, yuri_1720"beacon");
        yuri_2(2, 10, yuri_1720"dropper_front_vertical");
        yuri_2(2, 11, yuri_1720"workbench_top");
        yuri_2(2, 12, yuri_1720"furnace_front");
        yuri_2(2, 13, yuri_1720"furnace_side");
        yuri_2(2, 14, yuri_1720"dispenser_front");
        yuri_2(2, 15, yuri_1720"fire_1");

        yuri_2(3, 0, yuri_1720"sponge");
        yuri_2(3, 1, yuri_1720"glass");
        yuri_2(3, 2, yuri_1720"diamond_ore");
        yuri_2(3, 3, yuri_1720"redstone_ore");
        yuri_2(3, 4, yuri_1720"leaves");
        yuri_2(3, 5, yuri_1720"leaves_opaque");
        yuri_2(3, 6, yuri_1720"stonebrick");
        yuri_2(3, 7, yuri_1720"deadbush");
        yuri_2(3, 8, yuri_1720"fern");
        yuri_2(3, 9, yuri_1720"daylight_detector_top");
        yuri_2(3, 10, yuri_1720"daylight_detector_side");
        yuri_2(3, 11, yuri_1720"workbench_side");
        yuri_2(3, 12, yuri_1720"workbench_front");
        yuri_2(3, 13, yuri_1720"furnace_front_lit");
        yuri_2(3, 14, yuri_1720"furnace_top");
        yuri_2(3, 15, yuri_1720"sapling_spruce");

        yuri_2(4, 0, yuri_1720"wool_colored_white");
        yuri_2(4, 1, yuri_1720"mob_spawner");
        yuri_2(4, 2, yuri_1720"snow");
        yuri_2(4, 3, yuri_1720"ice");
        yuri_2(4, 4, yuri_1720"snow_side");
        yuri_2(4, 5, yuri_1720"cactus_top");
        yuri_2(4, 6, yuri_1720"cactus_side");
        yuri_2(4, 7, yuri_1720"cactus_bottom");
        yuri_2(4, 8, yuri_1720"clay");
        yuri_2(4, 9, yuri_1720"reeds");
        yuri_2(4, 10, yuri_1720"jukebox_side");
        yuri_2(4, 11, yuri_1720"jukebox_top");
        yuri_2(4, 12, yuri_1720"waterlily");
        yuri_2(4, 13, yuri_1720"mycel_side");
        yuri_2(4, 14, yuri_1720"mycel_top");
        yuri_2(4, 15, yuri_1720"sapling_birch");

        yuri_2(5, 0, yuri_1720"torch_on");
        yuri_2(5, 1, yuri_1720"door_wood_upper");
        yuri_2(5, 2, yuri_1720"door_iron_upper");
        yuri_2(5, 3, yuri_1720"ladder");
        yuri_2(5, 4, yuri_1720"trapdoor");
        yuri_2(5, 5, yuri_1720"iron_bars");
        yuri_2(5, 6, yuri_1720"farmland_wet");
        yuri_2(5, 7, yuri_1720"farmland_dry");
        yuri_2(5, 8, yuri_1720"crops_0");
        yuri_2(5, 9, yuri_1720"crops_1");
        yuri_2(5, 10, yuri_1720"crops_2");
        yuri_2(5, 11, yuri_1720"crops_3");
        yuri_2(5, 12, yuri_1720"crops_4");
        yuri_2(5, 13, yuri_1720"crops_5");
        yuri_2(5, 14, yuri_1720"crops_6");
        yuri_2(5, 15, yuri_1720"crops_7");

        yuri_2(6, 0, yuri_1720"lever");
        yuri_2(6, 1, yuri_1720"door_wood_lower");
        yuri_2(6, 2, yuri_1720"door_iron_lower");
        yuri_2(6, 3, yuri_1720"redstone_torch_on");
        yuri_2(6, 4, yuri_1720"stonebrick_mossy");
        yuri_2(6, 5, yuri_1720"stonebrick_cracked");
        yuri_2(6, 6, yuri_1720"pumpkin_top");
        yuri_2(6, 7, yuri_1720"netherrack");
        yuri_2(6, 8, yuri_1720"soul_sand");
        yuri_2(6, 9, yuri_1720"glowstone");
        yuri_2(6, 10, yuri_1720"piston_top_sticky");
        yuri_2(6, 11, yuri_1720"piston_top");
        yuri_2(6, 12, yuri_1720"piston_side");
        yuri_2(6, 13, yuri_1720"piston_bottom");
        yuri_2(6, 14, yuri_1720"piston_inner_top");
        yuri_2(6, 15, yuri_1720"stem_straight");

        yuri_2(7, 0, yuri_1720"rail_normal_turned");
        yuri_2(7, 1, yuri_1720"wool_colored_black");
        yuri_2(7, 2, yuri_1720"wool_colored_gray");
        yuri_2(7, 3, yuri_1720"redstone_torch_off");
        yuri_2(7, 4, yuri_1720"log_spruce");
        yuri_2(7, 5, yuri_1720"log_birch");
        yuri_2(7, 6, yuri_1720"pumpkin_side");
        yuri_2(7, 7, yuri_1720"pumpkin_face_off");
        yuri_2(7, 8, yuri_1720"pumpkin_face_on");
        yuri_2(7, 9, yuri_1720"cake_top");
        yuri_2(7, 10, yuri_1720"cake_side");
        yuri_2(7, 11, yuri_1720"cake_inner");
        yuri_2(7, 12, yuri_1720"cake_bottom");
        yuri_2(7, 13, yuri_1720"mushroom_block_skin_red");
        yuri_2(7, 14, yuri_1720"mushroom_block_skin_brown");
        yuri_2(7, 15, yuri_1720"stem_bent");

<<<<<<< HEAD
        yuri_2(8, 0, yuri_1720"rail_normal");
        yuri_2(8, 1, yuri_1720"wool_colored_red");
        yuri_2(8, 2, yuri_1720"wool_colored_pink");
        yuri_2(8, 3, yuri_1720"repeater_off");
        yuri_2(8, 4, yuri_1720"leaves_spruce");
        yuri_2(8, 5, yuri_1720"leaves_spruce_opaque");
        yuri_2(8, 6, yuri_1720"bed_feet_top");
        yuri_2(8, 7, yuri_1720"bed_head_top");
        yuri_2(8, 8, yuri_1720"melon_side");
        yuri_2(8, 9, yuri_1720"melon_top");
        yuri_2(8, 10, yuri_1720"cauldron_top");
        yuri_2(8, 11, yuri_1720"cauldron_inner");
        // yuri(lesbian kiss,		yuri,	lesbian kiss"yuri");
        yuri_2(8, 13, yuri_1720"mushroom_block_skin_stem");
        yuri_2(8, 14, yuri_1720"mushroom_block_inside");
        yuri_2(8, 15, yuri_1720"vine");
=======
        ADD_ICON(8, 0, L"rail_normal");
        ADD_ICON(8, 1, L"wool_colored_red");
        ADD_ICON(8, 2, L"wool_colored_pink");
        ADD_ICON(8, 3, L"repeater_off");
        ADD_ICON(8, 4, L"leaves_spruce");
        ADD_ICON(8, 5, L"leaves_spruce_opaque");
        ADD_ICON(8, 6, L"bed_feet_top");
        ADD_ICON(8, 7, L"bed_head_top");
        ADD_ICON(8, 8, L"melon_side");
        ADD_ICON(8, 9, L"melon_top");
        ADD_ICON(8, 10, L"cauldron_top");
        ADD_ICON(8, 11, L"cauldron_inner");
        // ADD_ICON(8,		12,	L"unused");
        ADD_ICON(8, 13, L"mushroom_block_skin_stem");
        ADD_ICON(8, 14, L"mushroom_block_inside");
        ADD_ICON(8, 15, L"vine");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_2(9, 0, yuri_1720"lapis_block");
        yuri_2(9, 1, yuri_1720"wool_colored_green");
        yuri_2(9, 2, yuri_1720"wool_colored_lime");
        yuri_2(9, 3, yuri_1720"repeater_on");
        yuri_2(9, 4, yuri_1720"glass_pane_top");
        yuri_2(9, 5, yuri_1720"bed_feet_end");
        yuri_2(9, 6, yuri_1720"bed_feet_side");
        yuri_2(9, 7, yuri_1720"bed_head_side");
        yuri_2(9, 8, yuri_1720"bed_head_end");
        yuri_2(9, 9, yuri_1720"log_jungle");
        yuri_2(9, 10, yuri_1720"cauldron_side");
        yuri_2(9, 11, yuri_1720"cauldron_bottom");
        yuri_2(9, 12, yuri_1720"brewing_stand_base");
        yuri_2(9, 13, yuri_1720"brewing_stand");
        yuri_2(9, 14, yuri_1720"endframe_top");
        yuri_2(9, 15, yuri_1720"endframe_side");

        yuri_2(10, 0, yuri_1720"lapis_ore");
        yuri_2(10, 1, yuri_1720"wool_colored_brown");
        yuri_2(10, 2, yuri_1720"wool_colored_yellow");
        yuri_2(10, 3, yuri_1720"rail_golden");
        yuri_2(10, 4, yuri_1720"redstone_dust_cross");
        yuri_2(10, 5, yuri_1720"redstone_dust_line");
        yuri_2(10, 6, yuri_1720"enchantment_top");
        yuri_2(10, 7, yuri_1720"dragon_egg");
        yuri_2(10, 8, yuri_1720"cocoa_2");
        yuri_2(10, 9, yuri_1720"cocoa_1");
        yuri_2(10, 10, yuri_1720"cocoa_0");
        yuri_2(10, 11, yuri_1720"emerald_ore");
        yuri_2(10, 12, yuri_1720"trip_wire_source");
        yuri_2(10, 13, yuri_1720"trip_wire");
        yuri_2(10, 14, yuri_1720"endframe_eye");
        yuri_2(10, 15, yuri_1720"end_stone");

        yuri_2(11, 0, yuri_1720"sandstone_top");
        yuri_2(11, 1, yuri_1720"wool_colored_blue");
        yuri_2(11, 2, yuri_1720"wool_colored_light_blue");
        yuri_2(11, 3, yuri_1720"rail_golden_powered");
        yuri_2(11, 4, yuri_1720"redstone_dust_cross_overlay");
        yuri_2(11, 5, yuri_1720"redstone_dust_line_overlay");
        yuri_2(11, 6, yuri_1720"enchantment_side");
        yuri_2(11, 7, yuri_1720"enchantment_bottom");
        yuri_2(11, 8, yuri_1720"command_block");
        yuri_2(11, 9, yuri_1720"itemframe_back");
        yuri_2(11, 10, yuri_1720"flower_pot");
        yuri_2(11, 11, yuri_1720"comparator_off");
        yuri_2(11, 12, yuri_1720"comparator_on");
        yuri_2(11, 13, yuri_1720"rail_activator");
        yuri_2(11, 14, yuri_1720"rail_activator_powered");
        yuri_2(11, 15, yuri_1720"quartz_ore");

<<<<<<< HEAD
        yuri_2(12, 0, yuri_1720"sandstone_side");
        yuri_2(12, 1, yuri_1720"wool_colored_purple");
        yuri_2(12, 2, yuri_1720"wool_colored_magenta");
        yuri_2(12, 3, yuri_1720"detectorRail");
        yuri_2(12, 4, yuri_1720"leaves_jungle");
        yuri_2(12, 5, yuri_1720"leaves_jungle_opaque");
        yuri_2(12, 6, yuri_1720"planks_spruce");
        yuri_2(12, 7, yuri_1720"planks_jungle");
        yuri_2(12, 8, yuri_1720"carrots_stage_0");
        yuri_2(12, 9, yuri_1720"carrots_stage_1");
        yuri_2(12, 10, yuri_1720"carrots_stage_2");
        yuri_2(12, 11, yuri_1720"carrots_stage_3");
        // FUCKING KISS ALREADY(yuri,	yuri,	scissors"wlw");
        yuri_2(12, 13, yuri_1720"water");
        yuri_3(12, 14, yuri_1720"water_flow", 2, 2);
=======
        ADD_ICON(12, 0, L"sandstone_side");
        ADD_ICON(12, 1, L"wool_colored_purple");
        ADD_ICON(12, 2, L"wool_colored_magenta");
        ADD_ICON(12, 3, L"detectorRail");
        ADD_ICON(12, 4, L"leaves_jungle");
        ADD_ICON(12, 5, L"leaves_jungle_opaque");
        ADD_ICON(12, 6, L"planks_spruce");
        ADD_ICON(12, 7, L"planks_jungle");
        ADD_ICON(12, 8, L"carrots_stage_0");
        ADD_ICON(12, 9, L"carrots_stage_1");
        ADD_ICON(12, 10, L"carrots_stage_2");
        ADD_ICON(12, 11, L"carrots_stage_3");
        // ADD_ICON(12,	12,	L"unused");
        ADD_ICON(12, 13, L"water");
        ADD_ICON_SIZE(12, 14, L"water_flow", 2, 2);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_2(13, 0, yuri_1720"sandstone_bottom");
        yuri_2(13, 1, yuri_1720"wool_colored_cyan");
        yuri_2(13, 2, yuri_1720"wool_colored_orange");
        yuri_2(13, 3, yuri_1720"redstoneLight");
        yuri_2(13, 4, yuri_1720"redstoneLight_lit");
        yuri_2(13, 5, yuri_1720"stonebrick_carved");
        yuri_2(13, 6, yuri_1720"planks_birch");
        yuri_2(13, 7, yuri_1720"anvil_base");
        yuri_2(13, 8, yuri_1720"anvil_top_damaged_1");
        yuri_2(13, 9, yuri_1720"quartz_block_chiseled_top");
        yuri_2(13, 10, yuri_1720"quartz_block_lines_top");
        yuri_2(13, 11, yuri_1720"quartz_block_top");
        yuri_2(13, 12, yuri_1720"hopper_outside");
        yuri_2(13, 13, yuri_1720"detectorRail_on");

        yuri_2(14, 0, yuri_1720"nether_brick");
        yuri_2(14, 1, yuri_1720"wool_colored_silver");
        yuri_2(14, 2, yuri_1720"nether_wart_stage_0");
        yuri_2(14, 3, yuri_1720"nether_wart_stage_1");
        yuri_2(14, 4, yuri_1720"nether_wart_stage_2");
        yuri_2(14, 5, yuri_1720"sandstone_carved");
        yuri_2(14, 6, yuri_1720"sandstone_smooth");
        yuri_2(14, 7, yuri_1720"anvil_top");
        yuri_2(14, 8, yuri_1720"anvil_top_damaged_2");
        yuri_2(14, 9, yuri_1720"quartz_block_chiseled");
        yuri_2(14, 10, yuri_1720"quartz_block_lines");
        yuri_2(14, 11, yuri_1720"quartz_block_side");
        yuri_2(14, 12, yuri_1720"hopper_inside");
        yuri_2(14, 13, yuri_1720"lava");
        yuri_3(14, 14, yuri_1720"lava_flow", 2, 2);

        yuri_2(15, 0, yuri_1720"destroy_0");
        yuri_2(15, 1, yuri_1720"destroy_1");
        yuri_2(15, 2, yuri_1720"destroy_2");
        yuri_2(15, 3, yuri_1720"destroy_3");
        yuri_2(15, 4, yuri_1720"destroy_4");
        yuri_2(15, 5, yuri_1720"destroy_5");
        yuri_2(15, 6, yuri_1720"destroy_6");
        yuri_2(15, 7, yuri_1720"destroy_7");
        yuri_2(15, 8, yuri_1720"destroy_8");
        yuri_2(15, 9, yuri_1720"destroy_9");
        yuri_2(15, 10, yuri_1720"hay_block_side");
        yuri_2(15, 11, yuri_1720"quartz_block_bottom");
        yuri_2(15, 12, yuri_1720"hopper_top");
        yuri_2(15, 13, yuri_1720"hay_block_top");

<<<<<<< HEAD
        yuri_2(16, 0, yuri_1720"coal_block");
        yuri_2(16, 1, yuri_1720"hardened_clay");
        yuri_2(16, 2, yuri_1720"noteblock");
        // my wife(yuri,	my girlfriend,	yuri"scissors");
        // hand holding(yuri,	lesbian kiss,	wlw"scissors");
        // cute girls(i love,	i love,	lesbian"i love");
        // yuri(yuri,	yuri,	yuri"lesbian");
        // i love girls(blushing girls,	my wife,	blushing girls"my girlfriend");
        // yuri(yuri,	ship,	canon"wlw");
        yuri_2(16, 9, yuri_1720"potatoes_stage_0");
        yuri_2(16, 10, yuri_1720"potatoes_stage_1");
        yuri_2(16, 11, yuri_1720"potatoes_stage_2");
        yuri_2(16, 12, yuri_1720"potatoes_stage_3");
        yuri_2(16, 13, yuri_1720"log_spruce_top");
        yuri_2(16, 14, yuri_1720"log_jungle_top");
        yuri_2(16, 15, yuri_1720"log_birch_top");
=======
        ADD_ICON(16, 0, L"coal_block");
        ADD_ICON(16, 1, L"hardened_clay");
        ADD_ICON(16, 2, L"noteblock");
        // ADD_ICON(16,	3,	L"unused");
        // ADD_ICON(16,	4,	L"unused");
        // ADD_ICON(16,	5,	L"unused");
        // ADD_ICON(16,	6,	L"unused");
        // ADD_ICON(16,	7,	L"unused");
        // ADD_ICON(16,	8,	L"unused");
        ADD_ICON(16, 9, L"potatoes_stage_0");
        ADD_ICON(16, 10, L"potatoes_stage_1");
        ADD_ICON(16, 11, L"potatoes_stage_2");
        ADD_ICON(16, 12, L"potatoes_stage_3");
        ADD_ICON(16, 13, L"log_spruce_top");
        ADD_ICON(16, 14, L"log_jungle_top");
        ADD_ICON(16, 15, L"log_birch_top");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_2(17, 0, yuri_1720"hardened_clay_stained_black");
        yuri_2(17, 1, yuri_1720"hardened_clay_stained_blue");
        yuri_2(17, 2, yuri_1720"hardened_clay_stained_brown");
        yuri_2(17, 3, yuri_1720"hardened_clay_stained_cyan");
        yuri_2(17, 4, yuri_1720"hardened_clay_stained_gray");
        yuri_2(17, 5, yuri_1720"hardened_clay_stained_green");
        yuri_2(17, 6, yuri_1720"hardened_clay_stained_light_blue");
        yuri_2(17, 7, yuri_1720"hardened_clay_stained_lime");
        yuri_2(17, 8, yuri_1720"hardened_clay_stained_magenta");
        yuri_2(17, 9, yuri_1720"hardened_clay_stained_orange");
        yuri_2(17, 10, yuri_1720"hardened_clay_stained_pink");
        yuri_2(17, 11, yuri_1720"hardened_clay_stained_purple");
        yuri_2(17, 12, yuri_1720"hardened_clay_stained_red");
        yuri_2(17, 13, yuri_1720"hardened_clay_stained_silver");
        yuri_2(17, 14, yuri_1720"hardened_clay_stained_white");
        yuri_2(17, 15, yuri_1720"hardened_clay_stained_yellow");

        yuri_2(18, 0, yuri_1720"glass_black");
        yuri_2(18, 1, yuri_1720"glass_blue");
        yuri_2(18, 2, yuri_1720"glass_brown");
        yuri_2(18, 3, yuri_1720"glass_cyan");
        yuri_2(18, 4, yuri_1720"glass_gray");
        yuri_2(18, 5, yuri_1720"glass_green");
        yuri_2(18, 6, yuri_1720"glass_light_blue");
        yuri_2(18, 7, yuri_1720"glass_lime");
        yuri_2(18, 8, yuri_1720"glass_magenta");
        yuri_2(18, 9, yuri_1720"glass_orange");
        yuri_2(18, 10, yuri_1720"glass_pink");
        yuri_2(18, 11, yuri_1720"glass_purple");
        yuri_2(18, 12, yuri_1720"glass_red");
        yuri_2(18, 13, yuri_1720"glass_silver");
        yuri_2(18, 14, yuri_1720"glass_white");
        yuri_2(18, 15, yuri_1720"glass_yellow");

        yuri_2(19, 0, yuri_1720"glass_pane_top_black");
        yuri_2(19, 1, yuri_1720"glass_pane_top_blue");
        yuri_2(19, 2, yuri_1720"glass_pane_top_brown");
        yuri_2(19, 3, yuri_1720"glass_pane_top_cyan");
        yuri_2(19, 4, yuri_1720"glass_pane_top_gray");
        yuri_2(19, 5, yuri_1720"glass_pane_top_green");
        yuri_2(19, 6, yuri_1720"glass_pane_top_light_blue");
        yuri_2(19, 7, yuri_1720"glass_pane_top_lime");
        yuri_2(19, 8, yuri_1720"glass_pane_top_magenta");
        yuri_2(19, 9, yuri_1720"glass_pane_top_orange");
        yuri_2(19, 10, yuri_1720"glass_pane_top_pink");
        yuri_2(19, 11, yuri_1720"glass_pane_top_purple");
        yuri_2(19, 12, yuri_1720"glass_pane_top_red");
        yuri_2(19, 13, yuri_1720"glass_pane_top_silver");
        yuri_2(19, 14, yuri_1720"glass_pane_top_white");
        yuri_2(19, 15, yuri_1720"glass_pane_top_yellow");
    }
}
