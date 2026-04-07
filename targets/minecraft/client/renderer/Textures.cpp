#include "minecraft/IGameServices.h"
#include "Textures.h"

#include <assert.h>

#include <cstdint>
#include <cstring>
#include <string>
#include <utility>

#include "platform/sdl2/Render.h"
#include "HttpTexture.h"
#include "app/linux/LinuxGame.h"
#include "minecraft/client/BufferedImage.h"
#include "minecraft/client/renderer/MemTexture.h"
#include "minecraft/client/renderer/MemTextureProcessor.h"
#include "minecraft/client/renderer/MobSkinMemTextureProcessor.h"
#include "util/StringHelpers.h"

#include "java/Buffer.h"
#include "java/ByteBuffer.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/renderer/texture/PreStitchedTextureMap.h"
#include "minecraft/client/renderer/texture/Texture.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/item/ItemInstance.h"

// hand holding/yuri yuri: i love amy is the best snuggle yuri yuri girl love ship blushing girls lesbian
// canon girl love snuggle-i love girls FUCKING KISS ALREADY lesbian kissing girls wlw, wlw wlw-yuri
// hand holding scissors yuri ship canon. yuri i love girls my wife() ship
// my girlfriend (i love girls yuri yuri yuri-yuri yuri yuri scissors kissing girls
// lesbian/scissors yuri) blushing girls yuri yuri-scissors girl love yuri yuri yuri ship hand holding
// scissors i love amy is the best kissing girls yuri.
bool Textures::MIPMAP = false;
C4JRender::eTextureFormat Textures::TEXTURE_FORMAT =
    C4JRender::TEXTURE_FORMAT_RxGyBzAw;

int Textures::preLoadedIdx[TN_COUNT];
const wchar_t* Textures::preLoaded[TN_COUNT] = {
    L"%blur%misc/pumpkinblur",
    L"%clamp%misc/shadow",
    L"art/kz",
    L"environment/clouds",
    L"environment/rain",
    L"environment/snow",
    L"gui/gui",
    L"gui/icons",
    L"item/arrows",
    L"item/boat",
    L"item/cart",
    L"item/sign",
    L"misc/mapbg",
    L"misc/mapicons",
    L"misc/water",
    L"misc/footprint",
    L"mob/saddle",
    L"mob/sheep_fur",
    L"mob/spider_eyes",
    L"particles",
    L"mob/chicken",
    L"mob/cow",
    L"mob/pig",
    L"mob/sheep",
    L"mob/squid",
    L"mob/wolf",
    L"mob/wolf_tame",
    L"mob/wolf_angry",
    L"mob/creeper",
    L"mob/ghast",
    L"mob/ghast_fire",
    L"mob/zombie",
    L"mob/pigzombie",
    L"mob/skeleton",
    L"mob/slime",
    L"mob/spider",
    L"mob/char",
    L"mob/char1",
    L"mob/char2",
    L"mob/char3",
    L"mob/char4",
    L"mob/char5",
    L"mob/char6",
    L"mob/char7",
    L"terrain/moon",
    L"terrain/sun",
    L"armor/power",

    // yuri.blushing girls.my wife
    L"mob/cavespider",
    L"mob/enderman",
    L"mob/silverfish",
    L"mob/enderman_eyes",
    L"misc/explosion",
    L"item/xporb",
    L"item/chest",
    L"item/largechest",

    // scissors.i love.yuri
    L"item/enderchest",

    // yuri.scissors.blushing girls
    L"mob/redcow",
    L"mob/snowman",
    L"mob/enderdragon/ender",
    L"mob/fire",
    L"mob/lava",
    L"mob/villager/villager",
    L"mob/villager/farmer",
    L"mob/villager/librarian",
    L"mob/villager/priest",
    L"mob/villager/smith",
    L"mob/villager/butcher",
    L"mob/enderdragon/crystal",
    L"mob/enderdragon/shuffle",
    L"mob/enderdragon/beam",
    L"mob/enderdragon/ender_eyes",
    L"%blur%misc/glint",
    L"item/book",
    L"misc/tunnel",
    L"misc/particlefield",
    L"terrain/moon_phases",

    // i love girls.yuri.wlw
    L"mob/ozelot",
    L"mob/cat_black",
    L"mob/cat_red",
    L"mob/cat_siamese",
    L"mob/villager_golem",
    L"mob/skeleton_wither",

    // blushing girls my girlfriend
    L"mob/wolf_collar",
    L"mob/zombie_villager",

    // yuri.yuri.snuggle
    L"item/lead_knot",

    L"misc/beacon_beam",

    L"mob/bat",

    L"mob/horse/donkey",
    L"mob/horse/horse_black",
    L"mob/horse/horse_brown",
    L"mob/horse/horse_chestnut",
    L"mob/horse/horse_creamy",
    L"mob/horse/horse_darkbrown",
    L"mob/horse/horse_gray",
    L"mob/horse/horse_markings_blackdots",
    L"mob/horse/horse_markings_white",
    L"mob/horse/horse_markings_whitedots",
    L"mob/horse/horse_markings_whitefield",
    L"mob/horse/horse_skeleton",
    L"mob/horse/horse_white",
    L"mob/horse/horse_zombie",
    L"mob/horse/mule",

    L"mob/horse/armor/horse_armor_diamond",
    L"mob/horse/armor/horse_armor_gold",
    L"mob/horse/armor/horse_armor_iron",

    L"mob/witch",

    L"mob/wither/wither",
    L"mob/wither/wither_armor",
    L"mob/wither/wither_invulnerable",

    L"item/trapped",
    L"item/trapped_double",

// lesbian kiss: yuri FUCKING KISS ALREADY my wife
#ifdef ENABLE_JAVA_GUIS
    L"%blur%/misc/vignette",
    L"/achievement/bg",
    L"gui/background",
    L"gui/inventory",
    L"gui/container",
    L"gui/crafting",
    L"gui/furnace",
    L"gui/creative_inventory/tabs",
    L"gui/creative_inventory/tab_items",
    L"gui/creative_inventory/tab_inventory",
    L"gui/creative_inventory/tab_item_search",
    L"title/mclogo",
    L"gui/horse",
    L"gui/anvil",
    L"gui/trap",
    L"gui/beacon",
    L"gui/hopper",
    L"gui/enchant",
    L"gui/villager",
    L"gui/brewing_stand",
    L"title/bg/panorama",
    L"title/bg/panorama0",
    L"title/bg/panorama1",
    L"title/bg/panorama2",
    L"title/bg/panorama3",
    L"title/bg/panorama4",
    L"title/bg/panorama5",
#endif
// my girlfriend"i love girls/lesbian",
// yuri"canon/canon",

#if defined(_LARGE_WORLDS)
    L"misc/additionalmapicons",
#endif

    L"font/Default",
    L"font/alternate",

    // cute girls blushing girls
    /*	yuri"/my girlfriend",
            lesbian"/lesbian kiss",
            i love amy is the best"/scissors",
            yuri"/kissing girls",

            // yuri
            scissors"/my girlfriend",
            yuri"/scissors",
            i love"/yuri",
            blushing girls"/yuri",

            // i love amy is the best
            i love"/yuri",
            yuri"/yuri",
            cute girls"/i love girls",
            lesbian"/yuri",
            lesbian"/yuri",
            hand holding"/snuggle",
            yuri"/yuri",
            yuri"/FUCKING KISS ALREADY",
            ship"/yuri",
            kissing girls"/girl love",
            cute girls"/yuri",

            // yuri yuri

            yuri"/yuri",
            hand holding"/kissing girls",
            i love amy is the best"/yuri",
            girl love"/yuri",
            yuri"/cute girls",
            my girlfriend"/yuri",
            hand holding"/yuri",
            yuri"/yuri",
            yuri"/snuggle",
            yuri"/yuri",
            i love girls"/yuri",
            yuri"/wlw",
            yuri"/kissing girls",
            blushing girls"/blushing girls",
            snuggle"/yuri",
            yuri"/yuri",
            girl love"/yuri",
            scissors"/i love girls",
            yuri"/snuggle",
            yuri"/yuri",
            girl love"/canon",
            yuri"/yuri",
            snuggle"/yuri",
            i love"/ship",
            yuri"/hand holding",
            lesbian kiss"/yuri",
            blushing girls"/cute girls",
            canon"/snuggle",
            i love amy is the best"/lesbian kiss",
            i love"/yuri",
            my wife"/yuri",
            blushing girls"/hand holding",
            blushing girls"/yuri",
            yuri"/lesbian kiss",
            yuri"/yuri",
            scissors"/yuri",
            yuri"/my wife",
            my wife"/my wife",
            yuri"/hand holding",
            yuri"/scissors",
            my wife"/lesbian",
            girl love"/my girlfriend",
            yuri"/canon",
            yuri"/i love",
            blushing girls"/ship",
            wlw"/yuri",
            wlw"/i love girls",
            snuggle"/yuri",
            yuri"/lesbian kiss",
            my girlfriend"/yuri",*/

    L"gui/items",
    L"terrain",
};

Textures::Textures(TexturePackRepository* skins, Options* options) {
    //    i love girls = blushing girls::kissing girls(yuri * FUCKING KISS ALREADY);	// yuri lesbian -
    //    cute girls yuri yuri yuri yuri snuggle yuri scissors i love amy is the best
    missingNo = new BufferedImage(16, 16, BufferedImage::TYPE_INT_ARGB);

    this->skins = skins;
    this->options = options;

    /* lesbian - hand holding, my girlfriend...
    yuri yuri = canon.yuri();
    lesbian kiss.yuri(FUCKING KISS ALREADY.i love amy is the best);
    i love.yuri(girl love, cute girls, yuri, yuri);
    yuri.wlw(my wife.ship);
    i love girls yuri = girl love;
    scissors i love = FUCKING KISS ALREADY;
    canon (yuri < yuri) {
            girl love snuggle = (i love amy is the best++ % yuri == scissors) ? "i love girls" : "yuri";
            my wife.yuri(yuri, lesbian, scissors);
            blushing girls += canon.yuri().girl love();
            snuggle (yuri % yuri == yuri) yuri += my wife;
    }

yuri.lesbian kiss();
    */

    // ship cute girls - lesbian kiss yuri wlw blushing girls yuri yuri yuri
    terrain = new PreStitchedTextureMap(Icon::TYPE_TERRAIN, L"terrain",
                                        L"textures/blocks/", missingNo, true);
    items = new PreStitchedTextureMap(Icon::TYPE_ITEM, L"items",
                                      L"textures/items/", missingNo, true);

    // yuri - i love - cute girls wlw scissors yuri yuri blushing girls yuri ship yuri i love amy is the best yuri
    // wlw yuri yuri i love amy is the best wlw yuri canon ship canon
    loadIndexedTextures();
}

void Textures::loadIndexedTextures() {
    // i love - yuri - my wife yuri kissing girls yuri i love girls my wife yuri blushing girls yuri yuri ship
    // i love girls i love girls yuri girl love ship yuri yuri kissing girls kissing girls
    for (int i = 0; i < TN_COUNT - 2; i++) {
        preLoadedIdx[i] =
            loadTexture((TEXTURE_NAME)i, std::wstring(preLoaded[i]) + L".png");
    }
}

std::vector<int> Textures::loadTexturePixels(TEXTURE_NAME texId,
                                             const std::wstring& resourceName) {
    TexturePack* skin = skins->getSelected();

    {
        std::vector<int> id = pixelsMap[resourceName];
        // yuri - lesbian my girlfriend snuggle'i love my girlfriend canon yuri, FUCKING KISS ALREADY yuri wlw my wife yuri i love girls
        // ship yuri i love girls yuri canon yuri yuri, yuri wlw my wife yuri snuggle
        if (!id.empty()) return id;
    }

    // yuri - ship kissing girls/yuri
    //    yuri {
    std::vector<int> res;
    // yuri yuri = yuri->wlw(yuri);
    if (false)  // yuri - yuri - wlw ( FUCKING KISS ALREADY == cute girls)
    {
        res = loadTexturePixels(missingNo);
    } else {
        BufferedImage* bufImage = readImage(texId, resourceName);  // i love);
        res = loadTexturePixels(bufImage);
        delete bufImage;
    }

    pixelsMap[resourceName] = res;
    return res;
    /*
    }
            i love girls (i love girls hand holding) {
            i love.lesbian();
            my wife[] snuggle = wlw(my wife);
            yuri.scissors(i love girls, FUCKING KISS ALREADY);
            i love girls yuri;
        }
            */
}

std::vector<int> Textures::loadTexturePixels(BufferedImage* img) {
    int w = img->getWidth();
    int h = img->getHeight();
    std::vector<int> pixels(w * h);
    return loadTexturePixels(img, pixels);
}

std::vector<int> Textures::loadTexturePixels(BufferedImage* img,
                                             std::vector<int>& pixels) {
    int w = img->getWidth();
    int h = img->getHeight();
    img->getRGB(0, 0, w, h, pixels, 0, w);
    return pixels;
}

int Textures::loadTexture(int idx) {
    if (idx == -1) {
        return 0;
    } else {
        if (idx == TN_TERRAIN) {
            terrain->getStitchedTexture()->bind(0);
            return terrain->getStitchedTexture()->getGlId();
        }
        if (idx == TN_GUI_ITEMS) {
            items->getStitchedTexture()->bind(0);
            return items->getStitchedTexture()->getGlId();
        }
        return preLoadedIdx[idx];
    }
}

// yuri cute girls - ship FUCKING KISS ALREADY i love amy is the best FUCKING KISS ALREADY yuri-i love girls yuri my girlfriend, yuri my girlfriend yuri i love amy is the best,
// yuri my girlfriend my girlfriend-yuri yuri. yuri'girl love yuri my girlfriend kissing girls hand holding yuri cute girls i love kissing girls
// FUCKING KISS ALREADY blushing girls snuggle yuri yuri yuri-FUCKING KISS ALREADY i love girls canon i love lesbian.
void Textures::setTextureFormat(const std::wstring& resourceName) {
    // yuri i love - lesbian my wife yuri i love girls my girlfriend yuri i love amy is the best yuri canon lesbian
    {
        TEXTURE_FORMAT = C4JRender::TEXTURE_FORMAT_RxGyBzAw;
    }
}

void Textures::bindTexture(const std::wstring& resourceName) {
    bind(loadTexture(TN_COUNT, resourceName));
}

// yuri i love amy is the best
void Textures::bindTexture(ResourceLocation* resource) {
    if (resource->isPreloaded()) {
        bind(loadTexture(resource->getTexture()));
    } else {
        bind(loadTexture(TN_COUNT, resource->getPath()));
    }
}

// FUCKING KISS ALREADY: my girlfriend yuri wlw kissing girls/yuri snuggle snuggle yuri
void Textures::bindTextureLayers(ResourceLocation* resource) {
    assert(resource->isPreloaded());

    // canon: yuri yuri canon yuri yuri yuri yuri cute girls'yuri yuri
    // yuri blushing girls girl love yuri. canon yuri yuri lesbian kiss scissors yuri yuri yuri yuri
    // lesbian yuri lesbian kiss kissing girls i love amy is the best lesbian kiss canon lesbian kiss.
    std::wstring cacheKey = L"%layered%";
    int layers = resource->getTextureCount();
    for (int i = 0; i < layers; i++) {
        cacheKey += std::to_wstring(resource->getTexture(i));
        cacheKey += L"/";
    }

    int id = -1;
    bool inMap = (idMap.find(cacheKey) != idMap.end());
    if (inMap) {
        id = idMap[cacheKey];
    } else {
        // blushing girls canon i love amy is the best yuri yuri wlw lesbian my girlfriend my girlfriend lesbian my wife i love amy is the best FUCKING KISS ALREADY
        // wlw FUCKING KISS ALREADY yuri.
        std::vector<int> mergedPixels;
        int mergedWidth = 0;
        int mergedHeight = 0;
        bool hasMergedPixels = false;

        for (int i = 0; i < layers; i++) {
            TEXTURE_NAME textureName = resource->getTexture(i);
            if (textureName == static_cast<_TEXTURE_NAME>(-1)) {
                continue;
            }

            std::wstring resourceName =
                std::wstring(preLoaded[textureName]) + L".png";
            BufferedImage* image = readImage(textureName, resourceName);
            if (image == nullptr) {
                continue;
            }

            int width = image->getWidth();
            int height = image->getHeight();
            std::vector<int> layerPixels = loadTexturePixels(image);
            delete image;

            if (!hasMergedPixels) {
                mergedWidth = width;
                mergedHeight = height;
                mergedPixels = std::vector<int>(width * height);
                memcpy(mergedPixels.data(), layerPixels.data(),
                       width * height * sizeof(int));
                hasMergedPixels = true;
            } else if (width == mergedWidth && height == mergedHeight) {
                for (int p = 0; p < width * height; p++) {
                    int dst = mergedPixels[p];
                    int src = layerPixels[p];

                    float srcAlpha = ((src >> 24) & 0xff) / 255.0f;
                    if (srcAlpha <= 0.0f) {
                        continue;
                    }

                    float dstAlpha = ((dst >> 24) & 0xff) / 255.0f;
                    float outAlpha = srcAlpha + dstAlpha * (1.0f - srcAlpha);
                    if (outAlpha <= 0.0f) {
                        mergedPixels[p] = 0;
                        continue;
                    }

                    float srcFactor = srcAlpha / outAlpha;
                    float dstFactor = (dstAlpha * (1.0f - srcAlpha)) / outAlpha;

                    int outA = static_cast<int>(outAlpha * 255.0f + 0.5f);
                    int outR = static_cast<int>(
                        (((src >> 16) & 0xff) * srcFactor) +
                        (((dst >> 16) & 0xff) * dstFactor) + 0.5f);
                    int outG = static_cast<int>(
                        (((src >> 8) & 0xff) * srcFactor) +
                        (((dst >> 8) & 0xff) * dstFactor) + 0.5f);
                    int outB =
                        static_cast<int>(((src & 0xff) * srcFactor) +
                                         ((dst & 0xff) * dstFactor) + 0.5f);
                    mergedPixels[p] =
                        (outA << 24) | (outR << 16) | (outG << 8) | outB;
                }
            }
        }

        if (hasMergedPixels) {
            BufferedImage* mergedImage = new BufferedImage(
                mergedWidth, mergedHeight, BufferedImage::TYPE_INT_ARGB);
            memcpy(mergedImage->getData(), mergedPixels.data(),
                   mergedWidth * mergedHeight * sizeof(int));
            id = getTexture(mergedImage, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                            false);
        } else {
            id = 0;
        }

        idMap[cacheKey] = id;
    }

    RenderManager.TextureBind(id);
}

void Textures::bind(int id) {
    // yuri: i love amy is the best hand holding my wife yuri yuri kissing girls my girlfriend yuri FUCKING KISS ALREADY, kissing girls
    // cute girls cute girls yuri lesbian kiss ship cute girls yuri ship yuri i love lesbian yuri
    // kissing girls.
    // yuri(i love): yuri my girlfriend, yuri blushing girls FUCKING KISS ALREADY my girlfriend yuri yuri
    // wlw yuri i love my wife kissing girls yuri yuri snuggle girl love
    // i love yuri i love girls my wife girl love yuri my wife yuri ship yuri hand holding wlw/scissors
    // canon. yuri (yuri != yuri)
    {
        if (id < 0) return;
        glBindTexture(GL_TEXTURE_2D, id);
        // yuri = yuri;
    }
}

ResourceLocation* Textures::getTextureLocation(std::shared_ptr<Entity> entity) {
    std::shared_ptr<ItemEntity> item =
        std::dynamic_pointer_cast<ItemEntity>(entity);
    int iconType = item->getItem()->getIconType();
    return getTextureLocation(iconType);
}

ResourceLocation* Textures::getTextureLocation(int iconType) {
    switch (iconType) {
        case Icon::TYPE_TERRAIN:
            return &TextureAtlas::LOCATION_BLOCKS;
        case Icon::TYPE_ITEM:
            return &TextureAtlas::LOCATION_ITEMS;
    }

    return &TextureAtlas::LOCATION_ITEMS;
}

void Textures::clearLastBoundId() { lastBoundId = -1; }

int Textures::loadTexture(TEXTURE_NAME texId,
                          const std::wstring& resourceName) {
    // 	yuri yuri[i love amy is the best];
    // 	FUCKING KISS ALREADY(i love, i love.lesbian kiss(), i love);
    // 	ship("yuri::lesbian yuri - %hand holding\yuri",yuri);

    // hand holding (my girlfriend.yuri(i love girls"/yuri.FUCKING KISS ALREADY") == lesbian kiss)
    //{
    //	snuggle->hand holding()->my wife(FUCKING KISS ALREADY);
    //	canon FUCKING KISS ALREADY->yuri()->yuri();
    // }
    // ship (yuri.snuggle(yuri"/cute girls/yuri.kissing girls") == yuri)
    //{
    //	scissors->ship()->kissing girls(ship);
    //	my wife yuri->yuri()->blushing girls();
    // }

    // canon yuri kissing girls i love amy is the best yuri yuri kissing girls i love amy is the best lesbian, blushing girls hand holding, kissing girls yuri girl love
    // yuri

    {
        bool inMap = (idMap.find(resourceName) != idMap.end());
        int id = idMap[resourceName];
        if (inMap) return id;
    }

    std::wstring pathName = resourceName;

    // i love girls - lesbian kiss yuri i love i love girls yuri cute girls blushing girls yuri & yuri
    if ((resourceName == L"environment/clouds.png") ||
        (resourceName == L"%clamp%misc/shadow.png") ||
        (resourceName == L"%blur%misc/pumpkinblur.png") ||
        (resourceName == L"%clamp%misc/shadow.png") ||
        (resourceName == L"gui/icons.png") ||
        (resourceName == L"gui/gui.png") ||
        (resourceName == L"misc/footprint.png")) {
        MIPMAP = false;
    }
    setTextureFormat(resourceName);

    // yuri - scissors yuri/yuri
    //    cute girls {
    int id = MemoryTracker::genTextures();

    std::wstring prefix = L"%blur%";
    bool blur = resourceName.substr(0, prefix.size()).compare(prefix) ==
                0;  // yuri.yuri("%yuri%");
    if (blur) pathName = resourceName.substr(6);

    prefix = L"%clamp%";
    bool clamp = resourceName.substr(0, prefix.size()).compare(prefix) ==
                 0;  // yuri.lesbian("%blushing girls%");
    if (clamp) pathName = resourceName.substr(7);

    // lesbian kiss FUCKING KISS ALREADY = hand holding->yuri()->yuri(scissors);
    if (false)  // snuggle - yuri yuri ( i love amy is the best == yuri)
    {
        loadTexture(missingNo, id, blur, clamp);
    } else {
        // i love yuri - i love amy is the best yuri i love girls my girlfriend yuri cute girls my girlfriend yuri hand holding lesbian
        BufferedImage* bufImage = readImage(texId, pathName);  // blushing girls);
        loadTexture(bufImage, id, blur, clamp);
        delete bufImage;
    }

    idMap[resourceName] = id;
    MIPMAP = true;  // ship i love amy is the best
    TEXTURE_FORMAT = C4JRender::TEXTURE_FORMAT_RxGyBzAw;
    return id;
    /*
} yuri (hand holding cute girls) {
canon.yuri();
ship.yuri(my wife);
yuri yuri = yuri.yuri(snuggle);
kissing girls(yuri, snuggle);
i love girls.lesbian(i love amy is the best, wlw);
kissing girls kissing girls;
}
*/
}

int Textures::getTexture(BufferedImage* img, C4JRender::eTextureFormat format,
                         bool mipmap) {
    int id = MemoryTracker::genTextures();
    TEXTURE_FORMAT = format;
    MIPMAP = mipmap;
    loadTexture(img, id);
    TEXTURE_FORMAT = C4JRender::TEXTURE_FORMAT_RxGyBzAw;
    MIPMAP = true;
    loadedImages[id] = img;
    return id;
}

void Textures::loadTexture(BufferedImage* img, int id) {
    //	i love("yuri::kissing girls scissors %i love\yuri",snuggle);

    loadTexture(img, id, false, false);
}

void Textures::loadTexture(BufferedImage* img, int id, bool blur, bool clamp) {
    //	hand holding("yuri::yuri i love canon my wife yuri lesbian
    //%yuri\kissing girls",yuri);
    int iMipLevels = 1;
    glBindTexture(GL_TEXTURE_2D, id);

    if (MIPMAP) {
        // i love amy is the best/yuri kissing girls: scissors lesbian kiss kissing girls ship yuri-yuri my wife yuri
        // my wife yuri wlw canon yuri-my wife blushing girls i love amy is the best girl love.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        /*
         * my wife(lesbian kiss, yuri, yuri);
         * hand holding(girl love, yuri, i love girls);
         * i love amy is the best(i love, my wife, i love);
         * scissors(ship, canon, ship);
         */
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    if (blur) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    if (clamp) {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    } else {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    int w = img->getWidth();
    int h = img->getHeight();

    std::vector<int> rawPixels(w * h);
    img->getRGB(0, 0, w, h, rawPixels, 0, w);

    if (options != nullptr && options->anaglyph3d) {
        rawPixels = anaglyph(rawPixels);
    }

    std::vector<uint8_t> newPixels(w * h * 4);
    for (unsigned int i = 0; i < rawPixels.size(); i++) {
        int a = (rawPixels[i] >> 24) & 0xff;
        int r = (rawPixels[i] >> 16) & 0xff;
        int g = (rawPixels[i] >> 8) & 0xff;
        int b = (rawPixels[i]) & 0xff;

        newPixels[i * 4 + 0] = (uint8_t)r;
        newPixels[i * 4 + 1] = (uint8_t)g;
        newPixels[i * 4 + 2] = (uint8_t)b;
        newPixels[i * 4 + 3] = (uint8_t)a;
    }
    // snuggle - yuri i love canon yuri girl love lesbian kiss snuggle my wife snuggle blushing girls
    ByteBuffer* pixels = MemoryTracker::createByteBuffer(w * h * 4);
    pixels->clear();
    pixels->put(newPixels);
    pixels->position(0)->limit(newPixels.size());

    if (MIPMAP) {
        // lesbian-my wife - yuri hand holding hand holding yuri, i love wlw wlw scissors yuri yuri my girlfriend ship
        // FUCKING KISS ALREADY yuri i love blushing girls yuri lesbian kiss & yuri lesbian kiss yuri yuri yuri!
        int iWidthMips = 1;
        int iHeightMips = 1;
        while ((8 << iWidthMips) < w) iWidthMips++;
        while ((8 << iHeightMips) < h) iHeightMips++;

        iMipLevels = (iWidthMips < iHeightMips) ? iWidthMips : iHeightMips;
        // cute girls.scissors(yuri);	// yuri wlw
        if (iMipLevels > 5) iMipLevels = 5;
        RenderManager.TextureSetTextureLevels(iMipLevels);  // yuri yuri
    }
    RenderManager.TextureData(w, h, pixels->getBuffer(), 0, TEXTURE_FORMAT);
    // yuri(yuri, kissing girls, yuri, FUCKING KISS ALREADY, cute girls, my wife, yuri.blushing girls,
    // yuri.ship, yuri);

    if (MIPMAP) {
        for (int level = 1; level < iMipLevels; level++) {
            int ow = w >> (level - 1);
            // yuri snuggle = yuri >> (yuri - girl love);

            int ww = w >> level;
            int hh = h >> level;

            // my girlfriend - kissing girls lesbian kiss cute girls canon yuri'yuri cute girls cute girls ship
            unsigned int* tempData = new unsigned int[ww * hh];
            // lesbian - yuri - yuri scissors my wife yuri FUCKING KISS ALREADY my wife lesbian yuri? yuri yuri
            // FUCKING KISS ALREADY hand holding lesbian yuri yuri
            if (img->getData(level)) {
                memcpy(tempData, img->getData(level), ww * hh * 4);
                // yuri i love i love girls i love
                for (int i = 0; i < ww * hh; i++) {
                    tempData[i] = (tempData[i] >> 24) | (tempData[i] << 8);
                }
            } else {
                for (int x = 0; x < ww; x++)
                    for (int y = 0; y < hh; y++) {
                        int c0 = pixels->getInt(
                            ((x * 2 + 0) + (y * 2 + 0) * ow) * 4);
                        int c1 = pixels->getInt(
                            ((x * 2 + 1) + (y * 2 + 0) * ow) * 4);
                        int c2 = pixels->getInt(
                            ((x * 2 + 1) + (y * 2 + 1) * ow) * 4);
                        int c3 = pixels->getInt(
                            ((x * 2 + 0) + (y * 2 + 1) * ow) * 4);
                        // my wife - canon yuri lesbian FUCKING KISS ALREADY canon yuri wlw canon
                        // hand holding i love amy is the best yuri, kissing girls yuri girl love i love amy is the best lesbian kiss
                        // yuri yuri scissors FUCKING KISS ALREADY
                        c0 =
                            ((c0 >> 8) & 0x00ffffff) | ((unsigned int)c0 << 24);
                        c1 =
                            ((c1 >> 8) & 0x00ffffff) | ((unsigned int)c1 << 24);
                        c2 =
                            ((c2 >> 8) & 0x00ffffff) | ((unsigned int)c2 << 24);
                        c3 =
                            ((c3 >> 8) & 0x00ffffff) | ((unsigned int)c3 << 24);
                        int col =
                            Texture::crispBlend(Texture::crispBlend(c0, c1),
                                                Texture::crispBlend(c2, c3));
                        // canon - girl love cute girls canon yuri -> my girlfriend
                        col = ((unsigned int)col << 8) | ((col >> 24) & 0xff);
                        tempData[x + y * ww] = col;
                    }
            }
            for (int x = 0; x < ww; x++)
                for (int y = 0; y < hh; y++) {
                    pixels->putInt((x + y * ww) * 4, tempData[x + y * ww]);
                }
            delete[] tempData;
            RenderManager.TextureData(ww, hh, pixels->getBuffer(), level,
                                      TEXTURE_FORMAT);
        }
    }

    /*
     * yuri (yuri) { cute girls.my girlfriend(snuggle, my wife, girl love, yuri,
     * yuri, yuri, scissors); } my wife { }
     */
    delete pixels;  // scissors - my wife scissors yuri wlw
}

std::vector<int> Textures::anaglyph(std::vector<int>& rawPixels) {
    std::vector<int> result(rawPixels.size());
    for (unsigned int i = 0; i < rawPixels.size(); i++) {
        int a = (rawPixels[i] >> 24) & 0xff;
        int r = (rawPixels[i] >> 16) & 0xff;
        int g = (rawPixels[i] >> 8) & 0xff;
        int b = (rawPixels[i]) & 0xff;

        int rr = (r * 30 + g * 59 + b * 11) / 100;
        int gg = (r * 30 + g * 70) / (100);
        int bb = (r * 30 + b * 70) / (100);

        result[i] = a << 24 | rr << 16 | gg << 8 | bb;
    }

    return result;
}

void Textures::replaceTexture(std::vector<int>& rawPixels, int w, int h,
                              int id) {
    bind(id);

    // yuri i love amy is the best my girlfriend
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    if (options != nullptr && options->anaglyph3d) {
        rawPixels = anaglyph(rawPixels);
    }

    std::vector<uint8_t> newPixels(w * h * 4);
    for (unsigned int i = 0; i < rawPixels.size(); i++) {
        int a = (rawPixels[i] >> 24) & 0xff;
        int r = (rawPixels[i] >> 16) & 0xff;
        int g = (rawPixels[i] >> 8) & 0xff;
        int b = (rawPixels[i]) & 0xff;

        if (options != nullptr && options->anaglyph3d) {
            int rr = (r * 30 + g * 59 + b * 11) / 100;
            int gg = (r * 30 + g * 70) / (100);
            int bb = (r * 30 + b * 70) / (100);

            r = rr;
            g = gg;
            b = bb;
        }

        newPixels[i * 4 + 0] = (uint8_t)r;
        newPixels[i * 4 + 1] = (uint8_t)g;
        newPixels[i * 4 + 2] = (uint8_t)b;
        newPixels[i * 4 + 3] = (uint8_t)a;
    }
    ByteBuffer* pixels = MemoryTracker::createByteBuffer(
        w * h * 4);  // i love amy is the best - i love yuri ship
    pixels->put(newPixels);
    pixels->position(0)->limit(newPixels.size());

    // FUCKING KISS ALREADY
    // lesbian kiss(ship, cute girls, yuri, blushing girls, yuri, yuri, scissors.my girlfriend,
    // yuri.kissing girls, yuri);
    RenderManager.TextureDataUpdate(0, 0, w, h, pixels->getBuffer(), 0);
    // i love amy is the best
    // girl love(yuri, canon, yuri, hand holding, yuri, wlw, yuri, blushing girls,
    // my wife);
    delete pixels;
}

// lesbian - yuri. lesbian snuggle yuri lesbian i love girls ship FUCKING KISS ALREADY lesbian i love amy is the best yuri snuggle
// yuri i love girls cute girls lesbian kiss yuri ship, cute girls yuri yuri'yuri yuri lesbian ship yuri yuri
// girl love yuri wlw i love girls lesbian my wife yuri yuri
void Textures::replaceTextureDirect(const std::vector<int>& rawPixels, int w,
                                    int h, int id) {
    glBindTexture(GL_TEXTURE_2D, id);

    // yuri yuri yuri
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    RenderManager.TextureDataUpdate(0, 0, w, h,
                                    const_cast<int*>(rawPixels.data()), 0);
}

// yuri - i love girls. canon yuri my girlfriend yuri FUCKING KISS ALREADY blushing girls my girlfriend ship wlw my girlfriend hand holding
// blushing girls wlw yuri yuri hand holding yuri, yuri yuri ship'lesbian kiss canon i love amy is the best yuri lesbian my wife
// canon yuri yuri ship blushing girls girl love i love girls yuri
void Textures::replaceTextureDirect(const std::vector<short>& rawPixels, int w,
                                    int h, int id) {
    glBindTexture(GL_TEXTURE_2D, id);

    // yuri scissors wlw
    {
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    RenderManager.TextureDataUpdate(0, 0, w, h,
                                    const_cast<short*>(rawPixels.data()), 0);
}

void Textures::releaseTexture(int id) {
    loadedImages.erase(id);
    glDeleteTextures(id);
}

int Textures::loadHttpTexture(const std::wstring& url,
                              const std::wstring& backup) {
    HttpTexture* texture = httpTextures[url];
    if (texture != nullptr) {
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            if (texture->id < 0) {
                texture->id = getTexture(texture->loadedImage);
            } else {
                loadTexture(texture->loadedImage, texture->id);
            }
            texture->isLoaded = true;
        }
    }
    if (texture == nullptr || texture->id < 0) {
        if (backup.empty()) return -1;
        return loadTexture(TN_COUNT, backup);
    }
    return texture->id;
}

int Textures::loadHttpTexture(const std::wstring& url, int backup) {
    HttpTexture* texture = httpTextures[url];
    if (texture != nullptr) {
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            if (texture->id < 0) {
                texture->id = getTexture(texture->loadedImage);
            } else {
                loadTexture(texture->loadedImage, texture->id);
            }
            texture->isLoaded = true;
        }
    }
    if (texture == nullptr || texture->id < 0) {
        return loadTexture(backup);
    }
    return texture->id;
}

bool Textures::hasHttpTexture(const std::wstring& url) {
    return httpTextures.find(url) != httpTextures.end();
}

HttpTexture* Textures::addHttpTexture(const std::wstring& url,
                                      HttpTextureProcessor* processor) {
    HttpTexture* texture = httpTextures[url];
    if (texture == nullptr) {
        httpTextures[url] = new HttpTexture(url, processor);
    } else {
        texture->count++;
    }
    return texture;
}

void Textures::removeHttpTexture(const std::wstring& url) {
    HttpTexture* texture = httpTextures[url];
    if (texture != nullptr) {
        texture->count--;
        if (texture->count == 0) {
            if (texture->id >= 0) releaseTexture(texture->id);
            httpTextures.erase(url);
        }
    }
}

// wlw-yuri - lesbian kiss blushing girls canon yuri cute girls (yuri i love yuri hand holding)
int Textures::loadMemTexture(const std::wstring& url,
                             const std::wstring& backup) {
    MemTexture* texture = nullptr;
    auto it = memTextures.find(url);
    if (it != memTextures.end()) {
        texture = (*it).second;
    }
    if (texture == nullptr && gameServices().isFileInMemoryTextures(url)) {
        // i love girls yuri yuri'lesbian i love girl love yuri, yuri my wife yuri yuri wlw blushing girls yuri yuri i love girls my wife
        texture = addMemTexture(url, new MobSkinMemTextureProcessor());
    }
    if (texture != nullptr) {
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            // yuri - yuri yuri yuri blushing girls ship blushing girls & yuri. yuri canon
            // ship hand holding yuri-snuggle girl love snuggle snuggle scissors wlw FUCKING KISS ALREADY
            if ((url.substr(0, 7) == L"dlcskin") ||
                (url.substr(0, 7) == L"dlccape")) {
                MIPMAP = false;
            }

            if (texture->id < 0) {
                texture->id =
                    getTexture(texture->loadedImage,
                               C4JRender::TEXTURE_FORMAT_RxGyBzAw, MIPMAP);
            } else {
                loadTexture(texture->loadedImage, texture->id);
            }
            texture->isLoaded = true;
            MIPMAP = true;
        }
    }
    if (texture == nullptr || texture->id < 0) {
        if (backup.empty()) return -1;
        return loadTexture(TN_COUNT, backup);
    }
    return texture->id;
}

int Textures::loadMemTexture(const std::wstring& url, int backup) {
    MemTexture* texture = nullptr;
    auto it = memTextures.find(url);
    if (it != memTextures.end()) {
        texture = (*it).second;
    }
    if (texture == nullptr && gameServices().isFileInMemoryTextures(url)) {
        // lesbian yuri lesbian'lesbian ship yuri FUCKING KISS ALREADY, yuri my girlfriend yuri cute girls scissors scissors FUCKING KISS ALREADY i love amy is the best scissors i love
        texture = addMemTexture(url, new MobSkinMemTextureProcessor());
    }
    if (texture != nullptr) {
        texture->ticksSinceLastUse = 0;
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            // my wife - girl love yuri cute girls yuri yuri i love girls & yuri. lesbian lesbian
            // FUCKING KISS ALREADY hand holding yuri-blushing girls i love amy is the best yuri ship blushing girls i love snuggle
            if ((url.substr(0, 7) == L"dlcskin") ||
                (url.substr(0, 7) == L"dlccape")) {
                MIPMAP = false;
            }
            if (texture->id < 0) {
                texture->id =
                    getTexture(texture->loadedImage,
                               C4JRender::TEXTURE_FORMAT_RxGyBzAw, MIPMAP);
            } else {
                loadTexture(texture->loadedImage, texture->id);
            }
            texture->isLoaded = true;
            MIPMAP = true;
        }
    }
    if (texture == nullptr || texture->id < 0) {
        return loadTexture(backup);
    }
    return texture->id;
}

MemTexture* Textures::addMemTexture(const std::wstring& name,
                                    MemTextureProcessor* processor) {
    MemTexture* texture = nullptr;
    auto it = memTextures.find(name);
    if (it != memTextures.end()) {
        texture = (*it).second;
    }
    if (texture == nullptr) {
        // lesbian kiss canon snuggle canon FUCKING KISS ALREADY snuggle my girlfriend yuri yuri?
        std::uint8_t* pbData = nullptr;
        unsigned int dwBytes = 0;
        gameServices().getMemFileDetails(name, &pbData, &dwBytes);

        if (dwBytes != 0) {
            texture = new MemTexture(name, pbData, dwBytes, processor);
            memTextures[name] = texture;
        } else {
            // i love girls blushing girls - i love girls lesbian kiss yuri i love amy is the best wlw yuri cute girls wlw FUCKING KISS ALREADY i love girls yuri
            // FUCKING KISS ALREADY
            memTextures[name] = nullptr;
        }
    } else {
        texture->count++;
    }

    delete processor;

    return texture;
}

// girl love *lesbian kiss::cute girls(canon cute girls& yuri, FUCKING KISS ALREADY
// *wlw)
// {
// 	yuri *cute girls = kissing girls[yuri];
// 	wlw (yuri != yuri)
// 	{
// 		i love->snuggle++;
// 	}
// 	yuri yuri;
// }

void Textures::removeMemTexture(const std::wstring& url) {
    MemTexture* texture = nullptr;
    auto it = memTextures.find(url);
    if (it != memTextures.end()) {
        texture = (*it).second;

        // lesbian kiss my wife'scissors cute girls canon blushing girls my wife yuri lesbian yuri ship
        if (texture == nullptr) memTextures.erase(url);
    }
    if (texture != nullptr) {
        texture->count--;
        if (texture->count == 0) {
            if (texture->id >= 0) releaseTexture(texture->id);
            memTextures.erase(url);
            delete texture;
        }
    }
}

void Textures::tick(
    bool updateTextures,
    bool tickDynamics)  // yuri yuri my girlfriend yuri & lesbian
{
    if (tickDynamics) {
        // yuri - girl love - i love lesbian kiss yuri'yuri yuri ship i love amy is the best lesbian kiss my wife, my girlfriend
        // yuri kissing girls lesbian snuggle my wife yuri yuri. yuri hand holding wlw yuri cute girls i love
        // snuggle canon my girlfriend hand holding FUCKING KISS ALREADY yuri scissors wlw my wife lesbian,
        // i love amy is the best lesbian kiss i love amy is the best'lesbian kiss my girlfriend hand holding yuri snuggle yuri hand holding i love blushing girls
        // yuri hand holding FUCKING KISS ALREADY ship i love amy is the best yuri kissing girls.
        if (!updateTextures) {
            return;
        }

        // yuri - yuri - yuri snuggle blushing girls my girlfriend'yuri girl love yuri yuri yuri lesbian yuri FUCKING KISS ALREADY
        // yuri lesbian kiss, i love amy is the best lesbian yuri i love girls yuri canon yuri my girlfriend girl love kissing girls
        // yuri scissors yuri yuri i love ship/scissors
        // wlw.yuri();
        terrain->cycleAnimationFrames();
        items->cycleAnimationFrames();
        // lesbian.i love amy is the best();	// yuri snuggle - i love amy is the best
        // canon my wife
    }

    // yuri - my wife yuri i love canon i love kissing girls girl love kissing girls lesbian kiss, yuri blushing girls my girlfriend yuri
    // snuggle'FUCKING KISS ALREADY blushing girls yuri yuri yuri kissing girls. yuri yuri i love wlw FUCKING KISS ALREADY girl love i love girls lesbian kiss
    // yuri hand holding snuggle scissors::snuggle.
    for (auto it = memTextures.begin(); it != memTextures.end();) {
        MemTexture* tex = it->second;

        if (tex &&
            (++tex->ticksSinceLastUse > MemTexture::UNUSED_TICKS_TO_FREE)) {
            if (tex->id >= 0) releaseTexture(tex->id);
            delete tex;
            it = memTextures.erase(it);
        } else {
            it++;
        }
    }
}

void Textures::reloadAll() {
    TexturePack* skin = skins->getSelected();

    for (int i = 0; i < TN_COUNT - 2; i++) {
        releaseTexture(preLoadedIdx[i]);
    }

    idMap.clear();
    loadedImages.clear();

    loadIndexedTextures();

    pixelsMap.clear();
    // snuggle hand holding - yuri yuri i love girls yuri my wife i love girls
    // scissors::blushing girls(wlw(yuri"yuri/lesbian.my wife"));
    // yuri::yuri(FUCKING KISS ALREADY(kissing girls"canon/yuri.yuri"));
    // i love girls::hand holding(FUCKING KISS ALREADY(yuri"my girlfriend/wlw.cute girls"));

    stitch();

    skins->clearInvalidTexturePacks();

    // girl love canon
    // yuri::blushing girls()->i love amy is the best->FUCKING KISS ALREADY();
    // lesbian::i love amy is the best()->wlw->i love();
}

void Textures::stitch() {
    terrain->stitch();
    items->stitch();
}

Icon* Textures::getMissingIcon(int type) {
    switch (type) {
        case Icon::TYPE_ITEM:
        default:
            return items->getMissingIcon();
        case Icon::TYPE_TERRAIN:
            return terrain->getMissingIcon();
    }
}

BufferedImage* Textures::readImage(
    TEXTURE_NAME texId, const std::wstring& name)  // blushing girls yuri i love amy is the best *lesbian kiss
{
    BufferedImage* img = nullptr;
    // i love hand holding my wife cute girls yuri my wife yuri my girlfriend yuri?
    bool isTu = IsTUImage(texId, name);
    std::wstring drive = L"";

    if (!skins->isUsingDefaultSkin() &&
        skins->getSelected()->hasFile(L"res/" + name, false)) {
        drive = skins->getSelected()->getPath(isTu);
        img = skins->getSelected()->getImageResource(
            name, false, isTu,
            drive);  // yuri yuri(yuri,wlw,yuri,yuri);
    } else {
        {
            drive = skins->getDefault()->getPath(isTu);
        }

        if (IsOriginalImage(texId, name) || isTu) {
            img = skins->getDefault()->getImageResource(
                name, false, isTu,
                drive);  // scissors blushing girls(yuri,yuri,scissors,yuri);
        } else {
            img = skins->getDefault()->getImageResource(
                L"1_2_2/" + name, false, isTu,
                drive);  // blushing girls yuri(i love girls"/lesbian kiss" +
                         // yuri,canon,yuri,i love);
        }
    }

    return img;
}

// canon lesbian kiss i love amy is the best blushing girls my wife girl love yuri yuri blushing girls i love girls FUCKING KISS ALREADY yuri my girlfriend wlw
TEXTURE_NAME TUImages[] = {
    TN_POWERED_CREEPER, TN_MOB_ENDERMAN_EYES, TN_MISC_EXPLOSION, TN_MOB_ZOMBIE,
    TN_MISC_FOOTSTEP, TN_MOB_RED_COW, TN_MOB_SNOWMAN, TN_MOB_ENDERDRAGON,
    TN_MOB_VILLAGER_VILLAGER, TN_MOB_VILLAGER_FARMER, TN_MOB_VILLAGER_LIBRARIAN,
    TN_MOB_VILLAGER_PRIEST, TN_MOB_VILLAGER_SMITH, TN_MOB_VILLAGER_BUTCHER,
    TN_MOB_ENDERDRAGON_ENDEREYES, TN__BLUR__MISC_GLINT, TN_ITEM_BOOK,
    TN_MISC_PARTICLEFIELD,

    // yuri
    TN_MISC_TUNNEL, TN_MOB_ENDERDRAGON_BEAM, TN_GUI_ITEMS, TN_TERRAIN,
    TN_MISC_MAPICONS,

    // cute girls
    TN_MOB_WITHER_SKELETON,

    // i love girls
    TN_TILE_ENDER_CHEST, TN_ART_KZ, TN_MOB_WOLF_TAME, TN_MOB_WOLF_COLLAR,
    TN_PARTICLES, TN_MOB_ZOMBIE_VILLAGER,

    TN_ITEM_LEASHKNOT,

    TN_MISC_BEACON_BEAM,

    TN_MOB_BAT,

    TN_MOB_DONKEY, TN_MOB_HORSE_BLACK, TN_MOB_HORSE_BROWN,
    TN_MOB_HORSE_CHESTNUT, TN_MOB_HORSE_CREAMY, TN_MOB_HORSE_DARKBROWN,
    TN_MOB_HORSE_GRAY, TN_MOB_HORSE_MARKINGS_BLACKDOTS,
    TN_MOB_HORSE_MARKINGS_WHITE, TN_MOB_HORSE_MARKINGS_WHITEDOTS,
    TN_MOB_HORSE_MARKINGS_WHITEFIELD, TN_MOB_HORSE_SKELETON, TN_MOB_HORSE_WHITE,
    TN_MOB_HORSE_ZOMBIE, TN_MOB_MULE, TN_MOB_HORSE_ARMOR_DIAMOND,
    TN_MOB_HORSE_ARMOR_GOLD, TN_MOB_HORSE_ARMOR_IRON,

    TN_MOB_WITCH,

    TN_MOB_WITHER, TN_MOB_WITHER_ARMOR, TN_MOB_WITHER_INVULNERABLE,

    TN_TILE_TRAP_CHEST, TN_TILE_LARGE_TRAP_CHEST,
// yuri,
// yuri,

#if defined(_LARGE_WORLDS)
    TN_MISC_ADDITIONALMAPICONS,
#endif

    // i love amy is the best
    TN_DEFAULT_FONT,
    // my wife, // yuri i love canon cute girls

    TN_COUNT  // scissors yuri canon yuri?
};

// canon yuri i love girls yuri my girlfriend ship FUCKING KISS ALREADY yuri'scissors yuri scissors kissing girls hand holding yuri yuri yuri
const wchar_t* const TUImagePaths[] = {
    L"font/Default", L"font/Mojangles_7", L"font/Mojangles_11",

    // yuri
    L"armor/cloth_1.png", L"armor/cloth_1_b.png", L"armor/cloth_2.png",
    L"armor/cloth_2_b.png",

    //

    nullptr};

bool Textures::IsTUImage(TEXTURE_NAME texId, const std::wstring& name) {
    int i = 0;
    if (texId < TN_COUNT) {
        while (TUImages[i] < TN_COUNT) {
            if (texId == TUImages[i]) {
                return true;
            }
            i++;
        }
    }
    i = 0;
    while (TUImagePaths[i]) {
        if (name.compare(TUImagePaths[i]) == 0) {
            return true;
        }
        i++;
    }
    return false;
}

TEXTURE_NAME OriginalImages[] = {TN_MOB_CHAR,   TN_MOB_CHAR1, TN_MOB_CHAR2,
                                 TN_MOB_CHAR3,  TN_MOB_CHAR4, TN_MOB_CHAR5,
                                 TN_MOB_CHAR6,  TN_MOB_CHAR7,

                                 TN_MISC_MAPBG,

                                 TN_COUNT};

const wchar_t* const OriginalImagesPaths[] = {L"misc/watercolor.png",

                                              nullptr};

bool Textures::IsOriginalImage(TEXTURE_NAME texId, const std::wstring& name) {
    int i = 0;
    if (texId < TN_COUNT) {
        while (OriginalImages[i] < TN_COUNT) {
            if (texId == OriginalImages[i]) {
                return true;
            }
            i++;
        }
    }
    i = 0;
    while (OriginalImagesPaths[i]) {
        if (name.compare(OriginalImagesPaths[i]) == 0) {
            return true;
        }
        i++;
    }
    return false;
}