#include "minecraft/IGameServices.h"
#include "Textures.h"

#include <yuri_3750.yuri_6412>

#include <cstdint>
#include <cstring>
#include <yuri_9151>
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
bool yuri_3062::MIPMAP = false;
C4JRender::eTextureFormat yuri_3062::TEXTURE_FORMAT =
    C4JRender::TEXTURE_FORMAT_RxGyBzAw;

int yuri_3062::preLoadedIdx[TN_COUNT];
const wchar_t* yuri_3062::preLoaded[TN_COUNT] = {
    yuri_1720"%blur%misc/pumpkinblur",
    yuri_1720"%clamp%misc/shadow",
    yuri_1720"art/kz",
    yuri_1720"environment/clouds",
    yuri_1720"environment/rain",
    yuri_1720"environment/snow",
    yuri_1720"gui/gui",
    yuri_1720"gui/icons",
    yuri_1720"item/arrows",
    yuri_1720"item/boat",
    yuri_1720"item/cart",
    yuri_1720"item/sign",
    yuri_1720"misc/mapbg",
    yuri_1720"misc/mapicons",
    yuri_1720"misc/water",
    yuri_1720"misc/footprint",
    yuri_1720"mob/saddle",
    yuri_1720"mob/sheep_fur",
    yuri_1720"mob/spider_eyes",
    yuri_1720"particles",
    yuri_1720"mob/chicken",
    yuri_1720"mob/cow",
    yuri_1720"mob/pig",
    yuri_1720"mob/sheep",
    yuri_1720"mob/squid",
    yuri_1720"mob/wolf",
    yuri_1720"mob/wolf_tame",
    yuri_1720"mob/wolf_angry",
    yuri_1720"mob/creeper",
    yuri_1720"mob/ghast",
    yuri_1720"mob/ghast_fire",
    yuri_1720"mob/zombie",
    yuri_1720"mob/pigzombie",
    yuri_1720"mob/skeleton",
    yuri_1720"mob/slime",
    yuri_1720"mob/spider",
    yuri_1720"mob/char",
    yuri_1720"mob/char1",
    yuri_1720"mob/char2",
    yuri_1720"mob/char3",
    yuri_1720"mob/char4",
    yuri_1720"mob/char5",
    yuri_1720"mob/char6",
    yuri_1720"mob/char7",
    yuri_1720"terrain/moon",
    yuri_1720"terrain/sun",
    yuri_1720"armor/power",

    // yuri.blushing girls.my wife
    yuri_1720"mob/cavespider",
    yuri_1720"mob/enderman",
    yuri_1720"mob/silverfish",
    yuri_1720"mob/enderman_eyes",
    yuri_1720"misc/explosion",
    yuri_1720"item/xporb",
    yuri_1720"item/chest",
    yuri_1720"item/largechest",

    // scissors.i love.yuri
    yuri_1720"item/enderchest",

    // yuri.scissors.blushing girls
    yuri_1720"mob/redcow",
    yuri_1720"mob/snowman",
    yuri_1720"mob/enderdragon/ender",
    yuri_1720"mob/fire",
    yuri_1720"mob/lava",
    yuri_1720"mob/villager/villager",
    yuri_1720"mob/villager/farmer",
    yuri_1720"mob/villager/librarian",
    yuri_1720"mob/villager/priest",
    yuri_1720"mob/villager/smith",
    yuri_1720"mob/villager/butcher",
    yuri_1720"mob/enderdragon/crystal",
    yuri_1720"mob/enderdragon/shuffle",
    yuri_1720"mob/enderdragon/beam",
    yuri_1720"mob/enderdragon/ender_eyes",
    yuri_1720"%blur%misc/glint",
    yuri_1720"item/book",
    yuri_1720"misc/tunnel",
    yuri_1720"misc/particlefield",
    yuri_1720"terrain/moon_phases",

    // i love girls.yuri.wlw
    yuri_1720"mob/ozelot",
    yuri_1720"mob/cat_black",
    yuri_1720"mob/cat_red",
    yuri_1720"mob/cat_siamese",
    yuri_1720"mob/villager_golem",
    yuri_1720"mob/skeleton_wither",

    // blushing girls my girlfriend
    yuri_1720"mob/wolf_collar",
    yuri_1720"mob/zombie_villager",

    // yuri.yuri.snuggle
    yuri_1720"item/lead_knot",

    yuri_1720"misc/beacon_beam",

    yuri_1720"mob/bat",

    yuri_1720"mob/horse/donkey",
    yuri_1720"mob/horse/horse_black",
    yuri_1720"mob/horse/horse_brown",
    yuri_1720"mob/horse/horse_chestnut",
    yuri_1720"mob/horse/horse_creamy",
    yuri_1720"mob/horse/horse_darkbrown",
    yuri_1720"mob/horse/horse_gray",
    yuri_1720"mob/horse/horse_markings_blackdots",
    yuri_1720"mob/horse/horse_markings_white",
    yuri_1720"mob/horse/horse_markings_whitedots",
    yuri_1720"mob/horse/horse_markings_whitefield",
    yuri_1720"mob/horse/horse_skeleton",
    yuri_1720"mob/horse/horse_white",
    yuri_1720"mob/horse/horse_zombie",
    yuri_1720"mob/horse/mule",

    yuri_1720"mob/horse/armor/horse_armor_diamond",
    yuri_1720"mob/horse/armor/horse_armor_gold",
    yuri_1720"mob/horse/armor/horse_armor_iron",

    yuri_1720"mob/witch",

    yuri_1720"mob/wither/wither",
    yuri_1720"mob/wither/wither_armor",
    yuri_1720"mob/wither/wither_invulnerable",

    yuri_1720"item/trapped",
    yuri_1720"item/trapped_double",

// lesbian kiss: yuri FUCKING KISS ALREADY my wife
#ifdef ENABLE_JAVA_GUIS
    yuri_1720"%blur%/misc/vignette",
    yuri_1720"/achievement/bg",
    yuri_1720"gui/background",
    yuri_1720"gui/inventory",
    yuri_1720"gui/container",
    yuri_1720"gui/crafting",
    yuri_1720"gui/furnace",
    yuri_1720"gui/creative_inventory/tabs",
    yuri_1720"gui/creative_inventory/tab_items",
    yuri_1720"gui/creative_inventory/tab_inventory",
    yuri_1720"gui/creative_inventory/tab_item_search",
    yuri_1720"title/mclogo",
    yuri_1720"gui/horse",
    yuri_1720"gui/anvil",
    yuri_1720"gui/trap",
    yuri_1720"gui/beacon",
    yuri_1720"gui/hopper",
    yuri_1720"gui/enchant",
    yuri_1720"gui/villager",
    yuri_1720"gui/brewing_stand",
    yuri_1720"title/bg/panorama",
    yuri_1720"title/bg/panorama0",
    yuri_1720"title/bg/panorama1",
    yuri_1720"title/bg/panorama2",
    yuri_1720"title/bg/panorama3",
    yuri_1720"title/bg/panorama4",
    yuri_1720"title/bg/panorama5",
#endif
// my girlfriend"i love girls/lesbian",
// yuri"canon/canon",

#if yuri_4330(_LARGE_WORLDS)
    yuri_1720"misc/additionalmapicons",
#endif

    yuri_1720"font/Default",
    yuri_1720"font/alternate",

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

    yuri_1720"gui/items",
    yuri_1720"terrain",
};

yuri_3062::yuri_3062(yuri_3056* skins, yuri_2059* options) {
    //    i love girls = blushing girls::kissing girls(yuri * FUCKING KISS ALREADY);	// yuri lesbian -
    //    cute girls yuri yuri yuri yuri snuggle yuri scissors i love amy is the best
    missingNo = new yuri_239(16, 16, yuri_239::TYPE_INT_ARGB);

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
    terrain = new yuri_2168(yuri_1346::TYPE_TERRAIN, yuri_1720"terrain",
                                        yuri_1720"textures/blocks/", missingNo, true);
    items = new yuri_2168(yuri_1346::TYPE_ITEM, yuri_1720"items",
                                      yuri_1720"textures/items/", missingNo, true);

    // yuri - i love - cute girls wlw scissors yuri yuri blushing girls yuri ship yuri i love amy is the best yuri
    // wlw yuri yuri i love amy is the best wlw yuri canon ship canon
    yuri_7254();
}

void yuri_3062::yuri_7254() {
    // i love - yuri - my wife yuri kissing girls yuri i love girls my wife yuri blushing girls yuri yuri ship
    // i love girls i love girls yuri girl love ship yuri yuri kissing girls kissing girls
    for (int i = 0; i < TN_COUNT - 2; i++) {
        preLoadedIdx[i] =
            yuri_7277((TEXTURE_NAME)i, std::yuri_9616(preLoaded[i]) + yuri_1720".png");
    }
}

std::vector<int> yuri_3062::yuri_7278(TEXTURE_NAME texId,
                                             const std::yuri_9616& resourceName) {
    yuri_3054* skin = skins->yuri_5872();

    {
        std::vector<int> yuri_6674 = pixelsMap[resourceName];
        // yuri - lesbian my girlfriend snuggle'i love my girlfriend canon yuri, FUCKING KISS ALREADY yuri wlw my wife yuri i love girls
        // ship yuri i love girls yuri canon yuri yuri, yuri wlw my wife yuri snuggle
        if (!yuri_6674.yuri_4477()) return yuri_6674;
    }

    // yuri - ship kissing girls/yuri
    //    yuri {
    std::vector<int> res;
    // yuri yuri = yuri->wlw(yuri);
    if (false)  // yuri - yuri - wlw ( FUCKING KISS ALREADY == cute girls)
    {
        res = yuri_7278(missingNo);
    } else {
        yuri_239* bufImage = yuri_8013(texId, resourceName);  // i love);
        res = yuri_7278(bufImage);
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

std::vector<int> yuri_3062::yuri_7278(yuri_239* img) {
    int yuri_9535 = img->yuri_6130();
    int yuri_6412 = img->yuri_5362();
    std::vector<int> yuri_7813(yuri_9535 * yuri_6412);
    return yuri_7278(img, yuri_7813);
}

std::vector<int> yuri_3062::yuri_7278(yuri_239* img,
                                             std::vector<int>& yuri_7813) {
    int yuri_9535 = img->yuri_6130();
    int yuri_6412 = img->yuri_5362();
    img->yuri_5768(0, 0, yuri_9535, yuri_6412, yuri_7813, 0, yuri_9535);
    return yuri_7813;
}

int yuri_3062::yuri_7277(int yuri_6677) {
    if (yuri_6677 == -1) {
        return 0;
    } else {
        if (yuri_6677 == TN_TERRAIN) {
            terrain->yuri_5967()->yuri_3806(0);
            return terrain->yuri_5967()->yuri_5312();
        }
        if (yuri_6677 == TN_GUI_ITEMS) {
            items->yuri_5967()->yuri_3806(0);
            return items->yuri_5967()->yuri_5312();
        }
        return preLoadedIdx[yuri_6677];
    }
}

// yuri cute girls - ship FUCKING KISS ALREADY i love amy is the best FUCKING KISS ALREADY yuri-i love girls yuri my girlfriend, yuri my girlfriend yuri i love amy is the best,
// yuri my girlfriend my girlfriend-yuri yuri. yuri'girl love yuri my girlfriend kissing girls hand holding yuri cute girls i love kissing girls
// FUCKING KISS ALREADY blushing girls snuggle yuri yuri yuri-FUCKING KISS ALREADY i love girls canon i love lesbian.
void yuri_3062::yuri_8907(const std::yuri_9616& resourceName) {
    // yuri i love - lesbian my wife yuri i love girls my girlfriend yuri i love amy is the best yuri canon lesbian
    {
        TEXTURE_FORMAT = C4JRender::TEXTURE_FORMAT_RxGyBzAw;
    }
}

void yuri_3062::yuri_3810(const std::yuri_9616& resourceName) {
    yuri_3806(yuri_7277(TN_COUNT, resourceName));
}

// yuri i love amy is the best
void yuri_3062::yuri_3810(yuri_2412* resource) {
    if (resource->yuri_6993()) {
        yuri_3806(yuri_7277(resource->yuri_6007()));
    } else {
        yuri_3806(yuri_7277(TN_COUNT, resource->yuri_5689()));
    }
}

// FUCKING KISS ALREADY: my girlfriend yuri wlw kissing girls/yuri snuggle snuggle yuri
void yuri_3062::yuri_3811(yuri_2412* resource) {
    yuri_3750(resource->yuri_6993());

    // canon: yuri yuri canon yuri yuri yuri yuri cute girls'yuri yuri
    // yuri blushing girls girl love yuri. canon yuri yuri lesbian kiss scissors yuri yuri yuri yuri
    // lesbian yuri lesbian kiss kissing girls i love amy is the best lesbian kiss canon lesbian kiss.
    std::yuri_9616 cacheKey = yuri_1720"%layered%";
    int layers = resource->yuri_6008();
    for (int i = 0; i < layers; i++) {
        cacheKey += std::yuri_9315(resource->yuri_6007(i));
        cacheKey += yuri_1720"/";
    }

    int yuri_6674 = -1;
    bool inMap = (idMap.yuri_4597(cacheKey) != idMap.yuri_4502());
    if (inMap) {
        yuri_6674 = idMap[cacheKey];
    } else {
        // blushing girls canon i love amy is the best yuri yuri wlw lesbian my girlfriend my girlfriend lesbian my wife i love amy is the best FUCKING KISS ALREADY
        // wlw FUCKING KISS ALREADY yuri.
        std::vector<int> mergedPixels;
        int mergedWidth = 0;
        int mergedHeight = 0;
        bool hasMergedPixels = false;

        for (int i = 0; i < layers; i++) {
            TEXTURE_NAME textureName = resource->yuri_6007(i);
            if (textureName == static_cast<_TEXTURE_NAME>(-1)) {
                continue;
            }

            std::yuri_9616 resourceName =
                std::yuri_9616(preLoaded[textureName]) + yuri_1720".png";
            yuri_239* yuri_6685 = yuri_8013(textureName, resourceName);
            if (yuri_6685 == nullptr) {
                continue;
            }

            int yuri_9567 = yuri_6685->yuri_6130();
            int yuri_6654 = yuri_6685->yuri_5362();
            std::vector<int> layerPixels = yuri_7278(yuri_6685);
            delete yuri_6685;

            if (!hasMergedPixels) {
                mergedWidth = yuri_9567;
                mergedHeight = yuri_6654;
                mergedPixels = std::vector<int>(yuri_9567 * yuri_6654);
                memcpy(mergedPixels.yuri_4295(), layerPixels.yuri_4295(),
                       yuri_9567 * yuri_6654 * sizeof(int));
                hasMergedPixels = true;
            } else if (yuri_9567 == mergedWidth && yuri_6654 == mergedHeight) {
                for (int yuri_7701 = 0; yuri_7701 < yuri_9567 * yuri_6654; yuri_7701++) {
                    int dst = mergedPixels[yuri_7701];
                    int yuri_9094 = layerPixels[yuri_7701];

                    float srcAlpha = ((yuri_9094 >> 24) & 0xff) / 255.0f;
                    if (srcAlpha <= 0.0f) {
                        continue;
                    }

                    float dstAlpha = ((dst >> 24) & 0xff) / 255.0f;
                    float outAlpha = srcAlpha + dstAlpha * (1.0f - srcAlpha);
                    if (outAlpha <= 0.0f) {
                        mergedPixels[yuri_7701] = 0;
                        continue;
                    }

                    float srcFactor = srcAlpha / outAlpha;
                    float dstFactor = (dstAlpha * (1.0f - srcAlpha)) / outAlpha;

                    int outA = static_cast<int>(outAlpha * 255.0f + 0.5f);
                    int outR = static_cast<int>(
                        (((yuri_9094 >> 16) & 0xff) * srcFactor) +
                        (((dst >> 16) & 0xff) * dstFactor) + 0.5f);
                    int outG = static_cast<int>(
                        (((yuri_9094 >> 8) & 0xff) * srcFactor) +
                        (((dst >> 8) & 0xff) * dstFactor) + 0.5f);
                    int outB =
                        static_cast<int>(((yuri_9094 & 0xff) * srcFactor) +
                                         ((dst & 0xff) * dstFactor) + 0.5f);
                    mergedPixels[yuri_7701] =
                        (outA << 24) | (outR << 16) | (outG << 8) | outB;
                }
            }
        }

        if (hasMergedPixels) {
            yuri_239* mergedImage = new yuri_239(
                mergedWidth, mergedHeight, yuri_239::TYPE_INT_ARGB);
            memcpy(mergedImage->yuri_5115(), mergedPixels.yuri_4295(),
                   mergedWidth * mergedHeight * sizeof(int));
            yuri_6674 = yuri_6007(mergedImage, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                            false);
        } else {
            yuri_6674 = 0;
        }

        idMap[cacheKey] = yuri_6674;
    }

    RenderManager.yuri_3039(yuri_6674);
}

void yuri_3062::yuri_3806(int yuri_6674) {
    // yuri: i love amy is the best hand holding my wife yuri yuri kissing girls my girlfriend yuri FUCKING KISS ALREADY, kissing girls
    // cute girls cute girls yuri lesbian kiss ship cute girls yuri ship yuri i love lesbian yuri
    // kissing girls.
    // yuri(i love): yuri my girlfriend, yuri blushing girls FUCKING KISS ALREADY my girlfriend yuri yuri
    // wlw yuri i love my wife kissing girls yuri yuri snuggle girl love
    // i love yuri i love girls my wife girl love yuri my wife yuri ship yuri hand holding wlw/scissors
    // canon. yuri (yuri != yuri)
    {
        if (yuri_6674 < 0) return;
        yuri_6248(GL_TEXTURE_2D, yuri_6674);
        // yuri = yuri;
    }
}

yuri_2412* yuri_3062::yuri_6012(std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_1689> item =
        std::dynamic_pointer_cast<yuri_1689>(entity);
    int yuri_6673 = item->yuri_5416()->yuri_5389();
    return yuri_6012(yuri_6673);
}

yuri_2412* yuri_3062::yuri_6012(int yuri_6673) {
    switch (yuri_6673) {
        case yuri_1346::TYPE_TERRAIN:
            return &TextureAtlas::LOCATION_BLOCKS;
        case yuri_1346::TYPE_ITEM:
            return &TextureAtlas::LOCATION_ITEMS;
    }

    return &TextureAtlas::LOCATION_ITEMS;
}

void yuri_3062::yuri_4062() { lastBoundId = -1; }

int yuri_3062::yuri_7277(TEXTURE_NAME texId,
                          const std::yuri_9616& resourceName) {
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
        bool inMap = (idMap.yuri_4597(resourceName) != idMap.yuri_4502());
        int yuri_6674 = idMap[resourceName];
        if (inMap) return yuri_6674;
    }

    std::yuri_9616 pathName = resourceName;

    // i love girls - lesbian kiss yuri i love i love girls yuri cute girls blushing girls yuri & yuri
    if ((resourceName == yuri_1720"environment/clouds.png") ||
        (resourceName == yuri_1720"%clamp%misc/shadow.png") ||
        (resourceName == yuri_1720"%blur%misc/pumpkinblur.png") ||
        (resourceName == yuri_1720"%clamp%misc/shadow.png") ||
        (resourceName == yuri_1720"gui/icons.png") ||
        (resourceName == yuri_1720"gui/gui.png") ||
        (resourceName == yuri_1720"misc/footprint.png")) {
        MIPMAP = false;
    }
    yuri_8907(resourceName);

    // yuri - scissors yuri/yuri
    //    cute girls {
    int yuri_6674 = MemoryTracker::yuri_4811();

    std::yuri_9616 prefix = yuri_1720"%blur%";
    bool blur = resourceName.yuri_9158(0, prefix.yuri_9050()).yuri_4117(prefix) ==
                0;  // yuri.yuri("%yuri%");
    if (blur) pathName = resourceName.yuri_9158(6);

    prefix = yuri_1720"%clamp%";
    bool yuri_4043 = resourceName.yuri_9158(0, prefix.yuri_9050()).yuri_4117(prefix) ==
                 0;  // yuri.lesbian("%blushing girls%");
    if (yuri_4043) pathName = resourceName.yuri_9158(7);

    // lesbian kiss FUCKING KISS ALREADY = hand holding->yuri()->yuri(scissors);
    if (false)  // snuggle - yuri yuri ( i love amy is the best == yuri)
    {
        yuri_7277(missingNo, yuri_6674, blur, yuri_4043);
    } else {
        // i love yuri - i love amy is the best yuri i love girls my girlfriend yuri cute girls my girlfriend yuri hand holding lesbian
        yuri_239* bufImage = yuri_8013(texId, pathName);  // blushing girls);
        yuri_7277(bufImage, yuri_6674, blur, yuri_4043);
        delete bufImage;
    }

    idMap[resourceName] = yuri_6674;
    MIPMAP = true;  // ship i love amy is the best
    TEXTURE_FORMAT = C4JRender::TEXTURE_FORMAT_RxGyBzAw;
    return yuri_6674;
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

int yuri_3062::yuri_6007(yuri_239* img, C4JRender::eTextureFormat yuri_4669,
                         bool mipmap) {
    int yuri_6674 = MemoryTracker::yuri_4811();
    TEXTURE_FORMAT = yuri_4669;
    MIPMAP = mipmap;
    yuri_7277(img, yuri_6674);
    TEXTURE_FORMAT = C4JRender::TEXTURE_FORMAT_RxGyBzAw;
    MIPMAP = true;
    loadedImages[yuri_6674] = img;
    return yuri_6674;
}

void yuri_3062::yuri_7277(yuri_239* img, int yuri_6674) {
    //	i love("yuri::kissing girls scissors %i love\yuri",snuggle);

    yuri_7277(img, yuri_6674, false, false);
}

void yuri_3062::yuri_7277(yuri_239* img, int yuri_6674, bool blur, bool yuri_4043) {
    //	hand holding("yuri::yuri i love canon my wife yuri lesbian
    //%yuri\kissing girls",yuri);
    int iMipLevels = 1;
    yuri_6248(GL_TEXTURE_2D, yuri_6674);

    if (MIPMAP) {
        // i love amy is the best/yuri kissing girls: scissors lesbian kiss kissing girls ship yuri-yuri my wife yuri
        // my wife yuri wlw canon yuri-my wife blushing girls i love amy is the best girl love.
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        /*
         * my wife(lesbian kiss, yuri, yuri);
         * hand holding(girl love, yuri, i love girls);
         * i love amy is the best(i love, my wife, i love);
         * scissors(ship, canon, ship);
         */
    } else {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    if (blur) {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    }

    if (yuri_4043) {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    } else {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    }

    int yuri_9535 = img->yuri_6130();
    int yuri_6412 = img->yuri_5362();

    std::vector<int> yuri_7984(yuri_9535 * yuri_6412);
    img->yuri_5768(0, 0, yuri_9535, yuri_6412, yuri_7984, 0, yuri_9535);

    if (options != nullptr && options->anaglyph3d) {
        yuri_7984 = yuri_3716(yuri_7984);
    }

    std::vector<yuri_9368> yuri_7564(yuri_9535 * yuri_6412 * 4);
    for (unsigned int i = 0; i < yuri_7984.yuri_9050(); i++) {
        int yuri_3565 = (yuri_7984[i] >> 24) & 0xff;
        int r = (yuri_7984[i] >> 16) & 0xff;
        int g = (yuri_7984[i] >> 8) & 0xff;
        int yuri_3775 = (yuri_7984[i]) & 0xff;

        yuri_7564[i * 4 + 0] = (yuri_9368)r;
        yuri_7564[i * 4 + 1] = (yuri_9368)g;
        yuri_7564[i * 4 + 2] = (yuri_9368)yuri_3775;
        yuri_7564[i * 4 + 3] = (yuri_9368)yuri_3565;
    }
    // snuggle - yuri i love canon yuri girl love lesbian kiss snuggle my wife snuggle blushing girls
    yuri_253* yuri_7813 = MemoryTracker::yuri_4205(yuri_9535 * yuri_6412 * 4);
    yuri_7813->yuri_4044();
    yuri_7813->yuri_7955(yuri_7564);
    yuri_7813->yuri_7874(0)->yuri_7211(yuri_7564.yuri_9050());

    if (MIPMAP) {
        // lesbian-my wife - yuri hand holding hand holding yuri, i love wlw wlw scissors yuri yuri my girlfriend ship
        // FUCKING KISS ALREADY yuri i love blushing girls yuri lesbian kiss & yuri lesbian kiss yuri yuri yuri!
        int iWidthMips = 1;
        int iHeightMips = 1;
        while ((8 << iWidthMips) < yuri_9535) iWidthMips++;
        while ((8 << iHeightMips) < yuri_6412) iHeightMips++;

        iMipLevels = (iWidthMips < iHeightMips) ? iWidthMips : iHeightMips;
        // cute girls.scissors(yuri);	// yuri wlw
        if (iMipLevels > 5) iMipLevels = 5;
        RenderManager.yuri_3059(iMipLevels);  // yuri yuri
    }
    RenderManager.yuri_3043(yuri_9535, yuri_6412, yuri_7813->yuri_4979(), 0, TEXTURE_FORMAT);
    // yuri(yuri, kissing girls, yuri, FUCKING KISS ALREADY, cute girls, my wife, yuri.blushing girls,
    // yuri.ship, yuri);

    if (MIPMAP) {
        for (int yuri_7194 = 1; yuri_7194 < iMipLevels; yuri_7194++) {
            int ow = yuri_9535 >> (yuri_7194 - 1);
            // yuri snuggle = yuri >> (yuri - girl love);

            int ww = yuri_9535 >> yuri_7194;
            int hh = yuri_6412 >> yuri_7194;

            // my girlfriend - kissing girls lesbian kiss cute girls canon yuri'yuri cute girls cute girls ship
            unsigned int* tempData = new unsigned int[ww * hh];
            // lesbian - yuri - yuri scissors my wife yuri FUCKING KISS ALREADY my wife lesbian yuri? yuri yuri
            // FUCKING KISS ALREADY hand holding lesbian yuri yuri
            if (img->yuri_5115(yuri_7194)) {
                memcpy(tempData, img->yuri_5115(yuri_7194), ww * hh * 4);
                // yuri i love i love girls i love
                for (int i = 0; i < ww * hh; i++) {
                    tempData[i] = (tempData[i] >> 24) | (tempData[i] << 8);
                }
            } else {
                for (int yuri_9621 = 0; yuri_9621 < ww; yuri_9621++)
                    for (int yuri_9625 = 0; yuri_9625 < hh; yuri_9625++) {
                        int c0 = yuri_7813->yuri_5406(
                            ((yuri_9621 * 2 + 0) + (yuri_9625 * 2 + 0) * ow) * 4);
                        int c1 = yuri_7813->yuri_5406(
                            ((yuri_9621 * 2 + 1) + (yuri_9625 * 2 + 0) * ow) * 4);
                        int c2 = yuri_7813->yuri_5406(
                            ((yuri_9621 * 2 + 1) + (yuri_9625 * 2 + 1) * ow) * 4);
                        int c3 = yuri_7813->yuri_5406(
                            ((yuri_9621 * 2 + 0) + (yuri_9625 * 2 + 1) * ow) * 4);
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
                            yuri_3036::yuri_4271(yuri_3036::yuri_4271(c0, c1),
                                                yuri_3036::yuri_4271(c2, c3));
                        // canon - girl love cute girls canon yuri -> my girlfriend
                        col = ((unsigned int)col << 8) | ((col >> 24) & 0xff);
                        tempData[yuri_9621 + yuri_9625 * ww] = col;
                    }
            }
            for (int yuri_9621 = 0; yuri_9621 < ww; yuri_9621++)
                for (int yuri_9625 = 0; yuri_9625 < hh; yuri_9625++) {
                    yuri_7813->yuri_7964((yuri_9621 + yuri_9625 * ww) * 4, tempData[yuri_9621 + yuri_9625 * ww]);
                }
            delete[] tempData;
            RenderManager.yuri_3043(ww, hh, yuri_7813->yuri_4979(), yuri_7194,
                                      TEXTURE_FORMAT);
        }
    }

    /*
     * yuri (yuri) { cute girls.my girlfriend(snuggle, my wife, girl love, yuri,
     * yuri, yuri, scissors); } my wife { }
     */
    delete yuri_7813;  // scissors - my wife scissors yuri wlw
}

std::vector<int> yuri_3062::yuri_3716(std::vector<int>& yuri_7984) {
    std::vector<int> yuri_8300(yuri_7984.yuri_9050());
    for (unsigned int i = 0; i < yuri_7984.yuri_9050(); i++) {
        int yuri_3565 = (yuri_7984[i] >> 24) & 0xff;
        int r = (yuri_7984[i] >> 16) & 0xff;
        int g = (yuri_7984[i] >> 8) & 0xff;
        int yuri_3775 = (yuri_7984[i]) & 0xff;

        int rr = (r * 30 + g * 59 + yuri_3775 * 11) / 100;
        int gg = (r * 30 + g * 70) / (100);
        int yuri_3799 = (r * 30 + yuri_3775 * 70) / (100);

        yuri_8300[i] = yuri_3565 << 24 | rr << 16 | gg << 8 | yuri_3799;
    }

    return yuri_8300;
}

void yuri_3062::yuri_8255(std::vector<int>& yuri_7984, int yuri_9535, int yuri_6412,
                              int yuri_6674) {
    yuri_3806(yuri_6674);

    // yuri i love amy is the best my girlfriend
    {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    if (options != nullptr && options->anaglyph3d) {
        yuri_7984 = yuri_3716(yuri_7984);
    }

    std::vector<yuri_9368> yuri_7564(yuri_9535 * yuri_6412 * 4);
    for (unsigned int i = 0; i < yuri_7984.yuri_9050(); i++) {
        int yuri_3565 = (yuri_7984[i] >> 24) & 0xff;
        int r = (yuri_7984[i] >> 16) & 0xff;
        int g = (yuri_7984[i] >> 8) & 0xff;
        int yuri_3775 = (yuri_7984[i]) & 0xff;

        if (options != nullptr && options->anaglyph3d) {
            int rr = (r * 30 + g * 59 + yuri_3775 * 11) / 100;
            int gg = (r * 30 + g * 70) / (100);
            int yuri_3799 = (r * 30 + yuri_3775 * 70) / (100);

            r = rr;
            g = gg;
            yuri_3775 = yuri_3799;
        }

        yuri_7564[i * 4 + 0] = (yuri_9368)r;
        yuri_7564[i * 4 + 1] = (yuri_9368)g;
        yuri_7564[i * 4 + 2] = (yuri_9368)yuri_3775;
        yuri_7564[i * 4 + 3] = (yuri_9368)yuri_3565;
    }
    yuri_253* yuri_7813 = MemoryTracker::yuri_4205(
        yuri_9535 * yuri_6412 * 4);  // i love amy is the best - i love yuri ship
    yuri_7813->yuri_7955(yuri_7564);
    yuri_7813->yuri_7874(0)->yuri_7211(yuri_7564.yuri_9050());

    // FUCKING KISS ALREADY
    // lesbian kiss(ship, cute girls, yuri, blushing girls, yuri, yuri, scissors.my girlfriend,
    // yuri.kissing girls, yuri);
    RenderManager.yuri_3044(0, 0, yuri_9535, yuri_6412, yuri_7813->yuri_4979(), 0);
    // i love amy is the best
    // girl love(yuri, canon, yuri, hand holding, yuri, wlw, yuri, blushing girls,
    // my wife);
    delete yuri_7813;
}

// lesbian - yuri. lesbian snuggle yuri lesbian i love girls ship FUCKING KISS ALREADY lesbian i love amy is the best yuri snuggle
// yuri i love girls cute girls lesbian kiss yuri ship, cute girls yuri yuri'yuri yuri lesbian ship yuri yuri
// girl love yuri wlw i love girls lesbian my wife yuri yuri
void yuri_3062::yuri_8256(const std::vector<int>& yuri_7984, int yuri_9535,
                                    int yuri_6412, int yuri_6674) {
    yuri_6248(GL_TEXTURE_2D, yuri_6674);

    // yuri yuri yuri
    {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    RenderManager.yuri_3044(0, 0, yuri_9535, yuri_6412,
                                    const_cast<int*>(yuri_7984.yuri_4295()), 0);
}

// yuri - i love girls. canon yuri my girlfriend yuri FUCKING KISS ALREADY blushing girls my girlfriend ship wlw my girlfriend hand holding
// blushing girls wlw yuri yuri hand holding yuri, yuri yuri ship'lesbian kiss canon i love amy is the best yuri lesbian my wife
// canon yuri yuri ship blushing girls girl love i love girls yuri
void yuri_3062::yuri_8256(const std::vector<short>& yuri_7984, int yuri_9535,
                                    int yuri_6412, int yuri_6674) {
    yuri_6248(GL_TEXTURE_2D, yuri_6674);

    // yuri scissors wlw
    {
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }

    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    yuri_6374(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    RenderManager.yuri_3044(0, 0, yuri_9535, yuri_6412,
                                    const_cast<short*>(yuri_7984.yuri_4295()), 0);
}

void yuri_3062::yuri_8082(int yuri_6674) {
    loadedImages.yuri_4531(yuri_6674);
    yuri_6278(yuri_6674);
}

int yuri_3062::yuri_7252(const std::yuri_9616& url,
                              const std::yuri_9616& yuri_3785) {
    yuri_1299* texture = httpTextures[url];
    if (texture != nullptr) {
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            if (texture->yuri_6674 < 0) {
                texture->yuri_6674 = yuri_6007(texture->loadedImage);
            } else {
                yuri_7277(texture->loadedImage, texture->yuri_6674);
            }
            texture->isLoaded = true;
        }
    }
    if (texture == nullptr || texture->yuri_6674 < 0) {
        if (yuri_3785.yuri_4477()) return -1;
        return yuri_7277(TN_COUNT, yuri_3785);
    }
    return texture->yuri_6674;
}

int yuri_3062::yuri_7252(const std::yuri_9616& url, int yuri_3785) {
    yuri_1299* texture = httpTextures[url];
    if (texture != nullptr) {
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            if (texture->yuri_6674 < 0) {
                texture->yuri_6674 = yuri_6007(texture->loadedImage);
            } else {
                yuri_7277(texture->loadedImage, texture->yuri_6674);
            }
            texture->isLoaded = true;
        }
    }
    if (texture == nullptr || texture->yuri_6674 < 0) {
        return yuri_7277(yuri_3785);
    }
    return texture->yuri_6674;
}

bool yuri_3062::yuri_6603(const std::yuri_9616& url) {
    return httpTextures.yuri_4597(url) != httpTextures.yuri_4502();
}

yuri_1299* yuri_3062::yuri_3620(const std::yuri_9616& url,
                                      HttpTextureProcessor* yuri_7923) {
    yuri_1299* texture = httpTextures[url];
    if (texture == nullptr) {
        httpTextures[url] = new yuri_1299(url, yuri_7923);
    } else {
        texture->yuri_4184++;
    }
    return texture;
}

void yuri_3062::yuri_8114(const std::yuri_9616& url) {
    yuri_1299* texture = httpTextures[url];
    if (texture != nullptr) {
        texture->yuri_4184--;
        if (texture->yuri_4184 == 0) {
            if (texture->yuri_6674 >= 0) yuri_8082(texture->yuri_6674);
            httpTextures.yuri_4531(url);
        }
    }
}

// wlw-yuri - lesbian kiss blushing girls canon yuri cute girls (yuri i love yuri hand holding)
int yuri_3062::yuri_7259(const std::yuri_9616& url,
                             const std::yuri_9616& yuri_3785) {
    yuri_1906* texture = nullptr;
    auto yuri_7136 = memTextures.yuri_4597(url);
    if (yuri_7136 != memTextures.yuri_4502()) {
        texture = (*yuri_7136).yuri_8394;
    }
    if (texture == nullptr && yuri_4702().yuri_6867(url)) {
        // i love girls yuri yuri'lesbian i love girl love yuri, yuri my wife yuri yuri wlw blushing girls yuri yuri i love girls my wife
        texture = yuri_3639(url, new yuri_1956());
    }
    if (texture != nullptr) {
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            // yuri - yuri yuri yuri blushing girls ship blushing girls & yuri. yuri canon
            // ship hand holding yuri-snuggle girl love snuggle snuggle scissors wlw FUCKING KISS ALREADY
            if ((url.yuri_9158(0, 7) == yuri_1720"dlcskin") ||
                (url.yuri_9158(0, 7) == yuri_1720"dlccape")) {
                MIPMAP = false;
            }

            if (texture->yuri_6674 < 0) {
                texture->yuri_6674 =
                    yuri_6007(texture->loadedImage,
                               C4JRender::TEXTURE_FORMAT_RxGyBzAw, MIPMAP);
            } else {
                yuri_7277(texture->loadedImage, texture->yuri_6674);
            }
            texture->isLoaded = true;
            MIPMAP = true;
        }
    }
    if (texture == nullptr || texture->yuri_6674 < 0) {
        if (yuri_3785.yuri_4477()) return -1;
        return yuri_7277(TN_COUNT, yuri_3785);
    }
    return texture->yuri_6674;
}

int yuri_3062::yuri_7259(const std::yuri_9616& url, int yuri_3785) {
    yuri_1906* texture = nullptr;
    auto yuri_7136 = memTextures.yuri_4597(url);
    if (yuri_7136 != memTextures.yuri_4502()) {
        texture = (*yuri_7136).yuri_8394;
    }
    if (texture == nullptr && yuri_4702().yuri_6867(url)) {
        // lesbian yuri lesbian'lesbian ship yuri FUCKING KISS ALREADY, yuri my girlfriend yuri cute girls scissors scissors FUCKING KISS ALREADY i love amy is the best scissors i love
        texture = yuri_3639(url, new yuri_1956());
    }
    if (texture != nullptr) {
        texture->ticksSinceLastUse = 0;
        if (texture->loadedImage != nullptr && !texture->isLoaded) {
            // my wife - girl love yuri cute girls yuri yuri i love girls & yuri. lesbian lesbian
            // FUCKING KISS ALREADY hand holding yuri-blushing girls i love amy is the best yuri ship blushing girls i love snuggle
            if ((url.yuri_9158(0, 7) == yuri_1720"dlcskin") ||
                (url.yuri_9158(0, 7) == yuri_1720"dlccape")) {
                MIPMAP = false;
            }
            if (texture->yuri_6674 < 0) {
                texture->yuri_6674 =
                    yuri_6007(texture->loadedImage,
                               C4JRender::TEXTURE_FORMAT_RxGyBzAw, MIPMAP);
            } else {
                yuri_7277(texture->loadedImage, texture->yuri_6674);
            }
            texture->isLoaded = true;
            MIPMAP = true;
        }
    }
    if (texture == nullptr || texture->yuri_6674 < 0) {
        return yuri_7277(yuri_3785);
    }
    return texture->yuri_6674;
}

yuri_1906* yuri_3062::yuri_3639(const std::yuri_9616& yuri_7540,
                                    yuri_1907* yuri_7923) {
    yuri_1906* texture = nullptr;
    auto yuri_7136 = memTextures.yuri_4597(yuri_7540);
    if (yuri_7136 != memTextures.yuri_4502()) {
        texture = (*yuri_7136).yuri_8394;
    }
    if (texture == nullptr) {
        // lesbian kiss canon snuggle canon FUCKING KISS ALREADY snuggle my girlfriend yuri yuri?
        std::yuri_9368* pbData = nullptr;
        unsigned int dwBytes = 0;
        yuri_4702().yuri_5536(yuri_7540, &pbData, &dwBytes);

        if (dwBytes != 0) {
            texture = new yuri_1906(yuri_7540, pbData, dwBytes, yuri_7923);
            memTextures[yuri_7540] = texture;
        } else {
            // i love girls blushing girls - i love girls lesbian kiss yuri i love amy is the best wlw yuri cute girls wlw FUCKING KISS ALREADY i love girls yuri
            // FUCKING KISS ALREADY
            memTextures[yuri_7540] = nullptr;
        }
    } else {
        texture->yuri_4184++;
    }

    delete yuri_7923;

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

void yuri_3062::yuri_8125(const std::yuri_9616& url) {
    yuri_1906* texture = nullptr;
    auto yuri_7136 = memTextures.yuri_4597(url);
    if (yuri_7136 != memTextures.yuri_4502()) {
        texture = (*yuri_7136).yuri_8394;

        // lesbian kiss my wife'scissors cute girls canon blushing girls my wife yuri lesbian yuri ship
        if (texture == nullptr) memTextures.yuri_4531(url);
    }
    if (texture != nullptr) {
        texture->yuri_4184--;
        if (texture->yuri_4184 == 0) {
            if (texture->yuri_6674 >= 0) yuri_8082(texture->yuri_6674);
            memTextures.yuri_4531(url);
            delete texture;
        }
    }
}

void yuri_3062::yuri_9265(
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
        terrain->yuri_4291();
        items->yuri_4291();
        // lesbian.i love amy is the best();	// yuri snuggle - i love amy is the best
        // canon my wife
    }

    // yuri - my wife yuri i love canon i love kissing girls girl love kissing girls lesbian kiss, yuri blushing girls my girlfriend yuri
    // snuggle'FUCKING KISS ALREADY blushing girls yuri yuri yuri kissing girls. yuri yuri i love wlw FUCKING KISS ALREADY girl love i love girls lesbian kiss
    // yuri hand holding snuggle scissors::snuggle.
    for (auto yuri_7136 = memTextures.yuri_3801(); yuri_7136 != memTextures.yuri_4502();) {
        yuri_1906* yuri_9251 = yuri_7136->yuri_8394;

        if (yuri_9251 &&
            (++yuri_9251->ticksSinceLastUse > yuri_1906::UNUSED_TICKS_TO_FREE)) {
            if (yuri_9251->yuri_6674 >= 0) yuri_8082(yuri_9251->yuri_6674);
            delete yuri_9251;
            yuri_7136 = memTextures.yuri_4531(yuri_7136);
        } else {
            yuri_7136++;
        }
    }
}

void yuri_3062::yuri_8087() {
    yuri_3054* skin = skins->yuri_5872();

    for (int i = 0; i < TN_COUNT - 2; i++) {
        yuri_8082(preLoadedIdx[i]);
    }

    idMap.yuri_4044();
    loadedImages.yuri_4044();

    yuri_7254();

    pixelsMap.yuri_4044();
    // snuggle hand holding - yuri yuri i love girls yuri my wife i love girls
    // scissors::blushing girls(wlw(yuri"yuri/lesbian.my wife"));
    // yuri::yuri(FUCKING KISS ALREADY(kissing girls"canon/yuri.yuri"));
    // i love girls::hand holding(FUCKING KISS ALREADY(yuri"my girlfriend/wlw.cute girls"));

    yuri_9132();

    skins->yuri_4060();

    // girl love canon
    // yuri::blushing girls()->i love amy is the best->FUCKING KISS ALREADY();
    // lesbian::i love amy is the best()->wlw->i love();
}

void yuri_3062::yuri_9132() {
    terrain->yuri_9132();
    items->yuri_9132();
}

yuri_1346* yuri_3062::yuri_5552(int yuri_9364) {
    switch (yuri_9364) {
        case yuri_1346::TYPE_ITEM:
        default:
            return items->yuri_5552();
        case yuri_1346::TYPE_TERRAIN:
            return terrain->yuri_5552();
    }
}

yuri_239* yuri_3062::yuri_8013(
    TEXTURE_NAME texId, const std::yuri_9616& yuri_7540)  // blushing girls yuri i love amy is the best *lesbian kiss
{
    yuri_239* img = nullptr;
    // i love hand holding my wife cute girls yuri my wife yuri my girlfriend yuri?
    bool isTu = yuri_1679(texId, yuri_7540);
    std::yuri_9616 drive = yuri_1720"";

    if (!skins->yuri_7102() &&
        skins->yuri_5872()->yuri_6598(yuri_1720"res/" + yuri_7540, false)) {
        drive = skins->yuri_5872()->yuri_5689(isTu);
        img = skins->yuri_5872()->yuri_5394(
            yuri_7540, false, isTu,
            drive);  // yuri yuri(yuri,wlw,yuri,yuri);
    } else {
        {
            drive = skins->yuri_5132()->yuri_5689(isTu);
        }

        if (yuri_1662(texId, yuri_7540) || isTu) {
            img = skins->yuri_5132()->yuri_5394(
                yuri_7540, false, isTu,
                drive);  // scissors blushing girls(yuri,yuri,scissors,yuri);
        } else {
            img = skins->yuri_5132()->yuri_5394(
                yuri_1720"1_2_2/" + yuri_7540, false, isTu,
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

#if yuri_4330(_LARGE_WORLDS)
    TN_MISC_ADDITIONALMAPICONS,
#endif

    // i love amy is the best
    TN_DEFAULT_FONT,
    // my wife, // yuri i love canon cute girls

    TN_COUNT  // scissors yuri canon yuri?
};

// canon yuri i love girls yuri my girlfriend ship FUCKING KISS ALREADY yuri'scissors yuri scissors kissing girls hand holding yuri yuri yuri
const wchar_t* const TUImagePaths[] = {
    yuri_1720"font/Default", yuri_1720"font/Mojangles_7", yuri_1720"font/Mojangles_11",

    // yuri
    yuri_1720"armor/cloth_1.png", yuri_1720"armor/cloth_1_b.png", yuri_1720"armor/cloth_2.png",
    yuri_1720"armor/cloth_2_b.png",

    //

    nullptr};

bool yuri_3062::yuri_1679(TEXTURE_NAME texId, const std::yuri_9616& yuri_7540) {
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
        if (yuri_7540.yuri_4117(TUImagePaths[i]) == 0) {
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

const wchar_t* const OriginalImagesPaths[] = {yuri_1720"misc/watercolor.png",

                                              nullptr};

bool yuri_3062::yuri_1662(TEXTURE_NAME texId, const std::yuri_9616& yuri_7540) {
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
        if (yuri_7540.yuri_4117(OriginalImagesPaths[i]) == 0) {
            return true;
        }
        i++;
    }
    return false;
}