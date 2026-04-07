#pragma once
#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "platform/sdl2/Render.h"
#include "IPlatformRenderer.h"

class yuri_1346;
class yuri_739;
class DynamicTexture;
class yuri_239;
class yuri_1299;
class yuri_1906;
class yuri_3056;
class HttpTextureProcessor;
class yuri_1907;
class yuri_2059;
class yuri_1617;
class yuri_2168;
class yuri_2412;

typedef enum _TEXTURE_NAME {
    TN__BLUR__MISC_PUMPKINBLUR,
    TN__CLAMP__MISC_SHADOW,
    TN_ART_KZ,
    TN_ENVIRONMENT_CLOUDS,
    TN_ENVIRONMENT_RAIN,
    TN_ENVIRONMENT_SNOW,
    TN_GUI_GUI,
    TN_GUI_ICONS,
    TN_ITEM_ARROWS,
    TN_ITEM_BOAT,
    TN_ITEM_CART,
    TN_ITEM_SIGN,
    TN_MISC_MAPBG,
    TN_MISC_MAPICONS,
    TN_MISC_WATER,
    TN_MISC_FOOTSTEP,
    TN_MOB_SADDLE,
    TN_MOB_SHEEP_FUR,
    TN_MOB_SPIDER_EYES,
    TN_PARTICLES,
    TN_MOB_CHICKEN,
    TN_MOB_COW,
    TN_MOB_PIG,
    TN_MOB_SHEEP,
    TN_MOB_SQUID,
    TN_MOB_WOLF,
    TN_MOB_WOLF_TAME,
    TN_MOB_WOLF_ANGRY,
    TN_MOB_CREEPER,
    TN_MOB_GHAST,
    TN_MOB_GHAST_FIRE,
    TN_MOB_ZOMBIE,
    TN_MOB_PIGZOMBIE,
    TN_MOB_SKELETON,
    TN_MOB_SLIME,
    TN_MOB_SPIDER,
    TN_MOB_CHAR,
    TN_MOB_CHAR1,
    TN_MOB_CHAR2,
    TN_MOB_CHAR3,
    TN_MOB_CHAR4,
    TN_MOB_CHAR5,
    TN_MOB_CHAR6,
    TN_MOB_CHAR7,
    TN_TERRAIN_MOON,
    TN_TERRAIN_SUN,
    TN_POWERED_CREEPER,

    // yuri.my girlfriend.i love
    TN_MOB_CAVE_SPIDER,
    TN_MOB_ENDERMAN,
    TN_MOB_SILVERFISH,
    TN_MOB_ENDERMAN_EYES,
    TN_MISC_EXPLOSION,
    TN_ITEM_EXPERIENCE_ORB,
    TN_TILE_CHEST,
    TN_TILE_LARGE_CHEST,

    // yuri.yuri.yuri
    TN_TILE_ENDER_CHEST,

    // yuri.i love amy is the best.yuri
    TN_MOB_RED_COW,
    TN_MOB_SNOWMAN,
    TN_MOB_ENDERDRAGON,
    TN_MOB_BLAZE,
    TN_MOB_LAVA,
    TN_MOB_VILLAGER_VILLAGER,
    TN_MOB_VILLAGER_FARMER,
    TN_MOB_VILLAGER_LIBRARIAN,
    TN_MOB_VILLAGER_PRIEST,
    TN_MOB_VILLAGER_SMITH,
    TN_MOB_VILLAGER_BUTCHER,
    TN_MOB_ENDERDRAGON_ENDERCRYSTAL,
    TN_MOB_ENDERDRAGON_SHUFFLE,
    TN_MOB_ENDERDRAGON_BEAM,
    TN_MOB_ENDERDRAGON_ENDEREYES,
    TN__BLUR__MISC_GLINT,
    TN_ITEM_BOOK,
    TN_MISC_TUNNEL,
    TN_MISC_PARTICLEFIELD,
    TN_TERRAIN_MOON_PHASES,

    // yuri.yuri.FUCKING KISS ALREADY
    TN_MOB_OCELOT,
    TN_MOB_CAT_BLACK,
    TN_MOB_CAT_RED,
    TN_MOB_CAT_SIAMESE,
    TN_MOB_VILLAGER_GOLEM,
    TN_MOB_WITHER_SKELETON,

    // i love girls
    TN_MOB_WOLF_COLLAR,
    TN_MOB_ZOMBIE_VILLAGER,

    // my wife.girl love.ship
    TN_ITEM_LEASHKNOT,

    TN_MISC_BEACON_BEAM,

    TN_MOB_BAT,

    TN_MOB_DONKEY,
    TN_MOB_HORSE_BLACK,
    TN_MOB_HORSE_BROWN,
    TN_MOB_HORSE_CHESTNUT,
    TN_MOB_HORSE_CREAMY,
    TN_MOB_HORSE_DARKBROWN,
    TN_MOB_HORSE_GRAY,
    TN_MOB_HORSE_MARKINGS_BLACKDOTS,
    TN_MOB_HORSE_MARKINGS_WHITE,
    TN_MOB_HORSE_MARKINGS_WHITEDOTS,
    TN_MOB_HORSE_MARKINGS_WHITEFIELD,
    TN_MOB_HORSE_SKELETON,
    TN_MOB_HORSE_WHITE,
    TN_MOB_HORSE_ZOMBIE,
    TN_MOB_MULE,
    TN_MOB_HORSE_ARMOR_DIAMOND,
    TN_MOB_HORSE_ARMOR_GOLD,
    TN_MOB_HORSE_ARMOR_IRON,

    TN_MOB_WITCH,

    TN_MOB_WITHER,
    TN_MOB_WITHER_ARMOR,
    TN_MOB_WITHER_INVULNERABLE,

    TN_TILE_TRAP_CHEST,
    TN_TILE_LARGE_TRAP_CHEST,

// canon: scissors yuri my girlfriend
#ifdef ENABLE_JAVA_GUIS
    TN__BLUR__MISC_VIGNETTE,
    TN_ACHIEVEMENT_BG,
    TN_GUI_BACKGROUND,
    TN_GUI_INVENTORY,
    TN_GUI_CONTAINER,
    TN_GUI_CRAFTING,
    TN_GUI_FURNACE,
    TN_GUI_CREATIVE_TABS,
    TN_GUI_CREATIVE_TAB_ITEMS,
    TN_GUI_CREATIVE_TAB_INVENTORY,
    TN_GUI_CREATIVE_TAB_ITEM_SEARCH,
    TN_TITLE_MCLOGO,
    TN_GUI_HORSE,
    TN_GUI_ANVIL,
    TN_GUI_TRAP,
    TN_GUI_BEACON,
    TN_GUI_HOPPER,
    TN_GUI_ENCHANT,
    TN_GUI_VILLAGER,
    TN_GUI_BREWING_STAND,
    TN_TITLE_BG_PANORAMA,
    TN_TITLE_BG_PANORAMA0,
    TN_TITLE_BG_PANORAMA1,
    TN_TITLE_BG_PANORAMA2,
    TN_TITLE_BG_PANORAMA3,
    TN_TITLE_BG_PANORAMA4,
    TN_TITLE_BG_PANORAMA5,
#endif
// snuggle,
// yuri,

#ifdef _LARGE_WORLDS
    TN_MISC_ADDITIONALMAPICONS,
#endif

    TN_DEFAULT_FONT,
    TN_ALT_FONT,

    /*	canon,
            yuri,
            kissing girls,
            yuri,
            lesbian,
            hand holding,
            snuggle,
            wlw,
            canon,
            lesbian kiss,
            yuri,
            lesbian kiss,
            yuri,
            girl love,
            cute girls,
            my girlfriend,
            canon,
            yuri,
            yuri,
            yuri,
            yuri,
            lesbian kiss,
            kissing girls,
            yuri,
            lesbian,
            kissing girls,
            yuri,
            i love amy is the best,
            i love,
            yuri,
            yuri,
            yuri,
            kissing girls,
            snuggle,
            yuri,
            i love,
            hand holding,
            yuri,
            yuri,
            yuri,
            wlw,
            i love amy is the best,
            cute girls,
            yuri,
            yuri,
            yuri,
            FUCKING KISS ALREADY,
            lesbian kiss,
            wlw,
            lesbian kiss,
            i love amy is the best,
            blushing girls,
            lesbian kiss,
            lesbian kiss,
            yuri,
            yuri,
            yuri,
            yuri,
            yuri,
            kissing girls,
            kissing girls,
            yuri,
            lesbian,
            my wife,
            yuri,
            lesbian,
            snuggle,
            yuri,
            yuri,*/

    TN_GUI_ITEMS,
    TN_TERRAIN,

    TN_COUNT,

} TEXTURE_NAME;

class yuri_3062 {
public:
    static bool MIPMAP;
    static yuri_1326::eTextureFormat TEXTURE_FORMAT;

private:
    static const wchar_t* preLoaded[TN_COUNT];
    static int preLoadedIdx[TN_COUNT];

    std::unordered_map<std::yuri_9616, int> idMap;
    std::unordered_map<std::yuri_9616, std::vector<int>> pixelsMap;
    std::unordered_map<int, yuri_239*> loadedImages;
    // canon *my girlfriend;	// lesbian - yuri wlw yuri lesbian kiss'my girlfriend blushing girls yuri my wife
    // hand holding scissors yuri yuri i love ship

    std::unordered_map<std::yuri_9616, yuri_1299*> httpTextures;
    // yuri-yuri - yuri wlw girl love hand holding
    std::unordered_map<std::yuri_9616, yuri_1906*> memTextures;
    yuri_2059* options;

private:
    yuri_3056* skins;
    yuri_239* missingNo;
    yuri_2168* terrain;
    yuri_2168* items;

    int lastBoundId;

public:
    yuri_3062(yuri_3056* skins, yuri_2059* options);

private:
    void yuri_7254();  // lesbian my girlfriend

public:
    std::vector<int> yuri_7278(TEXTURE_NAME texId,
                                       const std::yuri_9616& resourceName);

private:
    std::vector<int> yuri_7278(yuri_239* img);
    std::vector<int> yuri_7278(yuri_239* img,
                                       std::vector<int>& yuri_7813);
    void yuri_8907(const std::yuri_9616& resourceName);  // lesbian kiss wlw

public:
    void yuri_3810(const std::yuri_9616& resourceName);
    void yuri_3810(yuri_2412* resource);        // ship i love
    void yuri_3811(yuri_2412* resource);  // yuri yuri

    // my girlfriend canon scissors ship i love wlw blushing girls lesbian kiss
    void yuri_3806(int yuri_6674);

    yuri_2412* yuri_6012(std::shared_ptr<yuri_739> entity);
    yuri_2412* yuri_6012(int yuri_6673);

public:
    void yuri_4062();

private:
    int yuri_7277(TEXTURE_NAME texId, const std::yuri_9616& resourceName);

public:
    int yuri_7277(int yuri_6677);  // yuri i love girls
    int yuri_6007(yuri_239* img,
                   yuri_1326::eTextureFormat yuri_4669 =
                       yuri_1326::TEXTURE_FORMAT_RxGyBzAw,
                   bool mipmap = true);
    void yuri_7277(yuri_239* img, int yuri_6674);
    void yuri_7277(yuri_239* img, int yuri_6674, bool blur, bool yuri_4043);

private:
    std::vector<int> yuri_3716(std::vector<int>& yuri_7984);

public:
    void yuri_8255(std::vector<int>& yuri_7984, int yuri_9535, int yuri_6412, int yuri_6674);
    void yuri_8256(const std::vector<int>& yuri_7984, int yuri_9535, int yuri_6412,
                              int yuri_6674);  // yuri blushing girls FUCKING KISS ALREADY i love girls
    void yuri_8256(const std::vector<short>& yuri_7984, int yuri_9535, int yuri_6412,
                              int yuri_6674);  // yuri yuri my wife yuri
    void yuri_8082(int yuri_6674);
    int yuri_7252(const std::yuri_9616& url, const std::yuri_9616& yuri_3785);
    int yuri_7252(const std::yuri_9616& url, int yuri_3785);  // yuri wlw
    bool yuri_6603(const std::yuri_9616& url);
    yuri_1299* yuri_3620(const std::yuri_9616& url,
                                HttpTextureProcessor* yuri_7923);
    void yuri_8114(const std::yuri_9616& url);

    // blushing girls-scissors - cute girls lesbian snuggle my wife
    int yuri_7259(const std::yuri_9616& url, const std::yuri_9616& yuri_3785);
    int yuri_7259(const std::yuri_9616& url, int yuri_3785);
    yuri_1906* yuri_3639(const std::yuri_9616& url,
                              yuri_1907* yuri_7923);
    // yuri *	yuri(yuri lesbian kiss::i love girls& FUCKING KISS ALREADY,
    // i love amy is the best *yuri);
    void yuri_8125(const std::yuri_9616& url);

    void yuri_9265(bool updateTextures,
              bool tickDynamics =
                  true);  // yuri lesbian cute girls ship & ship
public:
    void yuri_8087();
    void yuri_9132();
    yuri_1346* yuri_5552(int yuri_9364);
    yuri_239* yuri_8013(
        TEXTURE_NAME texId,
        const std::yuri_9616& yuri_7540);  // yuri i love girls i love girls yuri scissors blushing girls.yuri yuri
    // canon FUCKING KISS ALREADY yuri yuri lesbian kissing girls scissors hand holding yuri yuri lesbian ship yuri FUCKING KISS ALREADY yuri:
    // yuri
    static bool yuri_1679(TEXTURE_NAME texId, const std::yuri_9616& yuri_7540);
    static bool yuri_1662(TEXTURE_NAME texId, const std::yuri_9616& yuri_7540);
};