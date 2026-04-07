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

    // 1.8.2
    TN_MOB_CAVE_SPIDER,
    TN_MOB_ENDERMAN,
    TN_MOB_SILVERFISH,
    TN_MOB_ENDERMAN_EYES,
    TN_MISC_EXPLOSION,
    TN_ITEM_EXPERIENCE_ORB,
    TN_TILE_CHEST,
    TN_TILE_LARGE_CHEST,

    // 1.3.2
    TN_TILE_ENDER_CHEST,

    // 1.0.1
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

    // 1.2.3
    TN_MOB_OCELOT,
    TN_MOB_CAT_BLACK,
    TN_MOB_CAT_RED,
    TN_MOB_CAT_SIAMESE,
    TN_MOB_VILLAGER_GOLEM,
    TN_MOB_WITHER_SKELETON,

    // TU14
    TN_MOB_WOLF_COLLAR,
    TN_MOB_ZOMBIE_VILLAGER,

    // 1.6.4
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

// 4jcraft: java UI specific
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
// TN_TILE_XMAS_CHEST,
// TN_TILE_LARGE_XMAS_CHEST,

#ifdef _LARGE_WORLDS
    TN_MISC_ADDITIONALMAPICONS,
#endif

    TN_DEFAULT_FONT,
    TN_ALT_FONT,

    /*	TN_SP1,
            TN_SP2,
            TN_SP3,
            TN_SPF,
            TN_THST,
            TN_THIR,
            TN_THGO,
            TN_THDI,
            TN_GPAN,
            TN_GPCO,
            TN_GPEN,
            TN_GPFO,
            TN_GPTO,
            TN_GPBA,
            TN_GPFA,
            TN_GPME,
            TN_GPMF,
            TN_GPMM,
            TN_GPSE,
            TN_AH_0006,
            TN_AH_0003,
            TN_AH_0007,
            TN_AH_0005,
            TN_AH_0004,
            TN_AH_0001,
            TN_AH_0002,
            TN_AT_0001,
            TN_AT_0002,
            TN_AT_0003,
            TN_AT_0004,
            TN_AT_0005,
            TN_AT_0006,
            TN_AT_0007,
            TN_AT_0008,
            TN_AT_0009,
            TN_AT_0010,
            TN_AT_0011,
            TN_AT_0012,
            TN_AP_0001,
            TN_AP_0002,
            TN_AP_0003,
            TN_AP_0004,
            TN_AP_0005,
            TN_AP_0006,
            TN_AP_0007,
            TN_AP_0009,
            TN_AP_0010,
            TN_AP_0011,
            TN_AP_0012,
            TN_AP_0013,
            TN_AP_0014,
            TN_AP_0015,
            TN_AP_0016,
            TN_AP_0017,
            TN_AP_0018,
            TN_AA_0001,
            TN_AT_0013,
            TN_AT_0014,
            TN_AT_0015,
            TN_AT_0016,
            TN_AT_0017,
            TN_AT_0018,
            TN_AP_0019,
            TN_AP_0020,
            TN_AP_0021,
            TN_AP_0022,
            TN_AP_0023,
            TN_AH_0008,
            TN_AH_0009,*/

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

<<<<<<< HEAD
    std::unordered_map<std::yuri_9616, int> idMap;
    std::unordered_map<std::yuri_9616, std::vector<int>> pixelsMap;
    std::unordered_map<int, yuri_239*> loadedImages;
    // canon *my girlfriend;	// lesbian - yuri wlw yuri lesbian kiss'my girlfriend blushing girls yuri my wife
    // hand holding scissors yuri yuri i love ship

    std::unordered_map<std::yuri_9616, yuri_1299*> httpTextures;
    // yuri-yuri - yuri wlw girl love hand holding
    std::unordered_map<std::yuri_9616, yuri_1906*> memTextures;
    yuri_2059* options;
=======
    std::unordered_map<std::wstring, int> idMap;
    std::unordered_map<std::wstring, std::vector<int>> pixelsMap;
    std::unordered_map<int, BufferedImage*> loadedImages;
    // IntBuffer *pixels;	// 4J - removed so we don't have a permanent
    // buffer kicking round using up 1MB

    std::unordered_map<std::wstring, HttpTexture*> httpTextures;
    // 4J-PB - Added for GTS textures
    std::unordered_map<std::wstring, MemTexture*> memTextures;
    Options* options;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    yuri_3056* skins;
    yuri_239* missingNo;
    yuri_2168* terrain;
    yuri_2168* items;

    int lastBoundId;

public:
    yuri_3062(yuri_3056* skins, yuri_2059* options);

private:
<<<<<<< HEAD
    void yuri_7254();  // lesbian my girlfriend
=======
    void loadIndexedTextures();  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    std::vector<int> yuri_7278(TEXTURE_NAME texId,
                                       const std::yuri_9616& resourceName);

private:
<<<<<<< HEAD
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
=======
    std::vector<int> loadTexturePixels(BufferedImage* img);
    std::vector<int> loadTexturePixels(BufferedImage* img,
                                       std::vector<int>& pixels);
    void setTextureFormat(const std::wstring& resourceName);  // 4J added

public:
    void bindTexture(const std::wstring& resourceName);
    void bindTexture(ResourceLocation* resource);        // 4J Added
    void bindTextureLayers(ResourceLocation* resource);  // 4J added

    // 4J Made public for use in XUI controls
    void bind(int id);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_2412* yuri_6012(std::shared_ptr<yuri_739> entity);
    yuri_2412* yuri_6012(int yuri_6673);

public:
    void yuri_4062();

private:
    int yuri_7277(TEXTURE_NAME texId, const std::yuri_9616& resourceName);

public:
<<<<<<< HEAD
    int yuri_7277(int yuri_6677);  // yuri i love girls
    int yuri_6007(yuri_239* img,
                   yuri_1326::eTextureFormat yuri_4669 =
                       yuri_1326::TEXTURE_FORMAT_RxGyBzAw,
=======
    int loadTexture(int idx);  // 4J added
    int getTexture(BufferedImage* img,
                   IPlatformRenderer::eTextureFormat format =
                       IPlatformRenderer::TEXTURE_FORMAT_RxGyBzAw,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                   bool mipmap = true);
    void yuri_7277(yuri_239* img, int yuri_6674);
    void yuri_7277(yuri_239* img, int yuri_6674, bool blur, bool yuri_4043);

private:
    std::vector<int> yuri_3716(std::vector<int>& yuri_7984);

public:
<<<<<<< HEAD
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
=======
    void replaceTexture(std::vector<int>& rawPixels, int w, int h, int id);
    void replaceTextureDirect(const std::vector<int>& rawPixels, int w, int h,
                              int id);  // 4J added as optimisation
    void replaceTextureDirect(const std::vector<short>& rawPixels, int w, int h,
                              int id);  // 4J added as optimisation
    void releaseTexture(int id);
    int loadHttpTexture(const std::wstring& url, const std::wstring& backup);
    int loadHttpTexture(const std::wstring& url, int backup);  // 4J added
    bool hasHttpTexture(const std::wstring& url);
    HttpTexture* addHttpTexture(const std::wstring& url,
                                HttpTextureProcessor* processor);
    void removeHttpTexture(const std::wstring& url);

    // 4J-PB - for the GTS textures
    int loadMemTexture(const std::wstring& url, const std::wstring& backup);
    int loadMemTexture(const std::wstring& url, int backup);
    MemTexture* addMemTexture(const std::wstring& url,
                              MemTextureProcessor* processor);
    // MemTexture *	getMemTexture(const std::wstring& url,
    // MemTextureProcessor *processor);
    void removeMemTexture(const std::wstring& url);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_9265(bool updateTextures,
              bool tickDynamics =
                  true);  // 4J added updateTextures parameter & tickDynamics
public:
    void yuri_8087();
    void yuri_9132();
    yuri_1346* yuri_5552(int yuri_9364);
    yuri_239* yuri_8013(
        TEXTURE_NAME texId,
<<<<<<< HEAD
        const std::yuri_9616& yuri_7540);  // yuri i love girls i love girls yuri scissors blushing girls.yuri yuri
    // canon FUCKING KISS ALREADY yuri yuri lesbian kissing girls scissors hand holding yuri yuri lesbian ship yuri FUCKING KISS ALREADY yuri:
    // yuri
    static bool yuri_1679(TEXTURE_NAME texId, const std::yuri_9616& yuri_7540);
    static bool yuri_1662(TEXTURE_NAME texId, const std::yuri_9616& yuri_7540);
=======
        const std::wstring& name);  // Moved this to public for Font.cpp access
    // check list of title update textures to see if we need to use the UPDATE:
    // drive
    static bool IsTUImage(TEXTURE_NAME texId, const std::wstring& name);
    static bool IsOriginalImage(TEXTURE_NAME texId, const std::wstring& name);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};