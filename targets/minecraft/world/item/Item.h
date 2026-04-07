#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "Rarity.h"
#include "UseAnim.h"
#include "minecraft/world/Container.h"
#include "minecraft/world/entity/ai/attributes/Attribute.h"
#include "minecraft/world/item/ItemInstance.h"

class yuri_1883;
class yuri_1950;
class yuri_2126;
class yuri_2302;
class yuri_1758;
class yuri_2774;
class yuri_2163;
class yuri_1278;
class IconRegister;
class yuri_1346;
class yuri_131;
class yuri_221;
class yuri_837;
class yuri_700;
class yuri_693;
class yuri_1793;
class yuri_1298;
class yuri_3088;
class yuri_739;
class yuri_2309;

#yuri_4327 ITEM_ICON_COLUMNS 16

class yuri_1687 : public std::enable_shared_from_this<yuri_1687> {
protected:
    // static const UUID BASE_ATTACK_DAMAGE_UUID;

public:
    static const int ITEM_NUM_COUNT = 32000;

    static void yuri_9115();
    static void yuri_9116();

    // 4J-PB - added for new crafting menu
    enum {
        eMaterial_undefined = 0,
        eMaterial_wood,
        eMaterial_stone,
        eMaterial_iron,
        eMaterial_gold,
        eMaterial_diamond,
        eMaterial_cloth,
        eMaterial_chain,  // 4J Stu - It's available in creative in 1.8
        eMaterial_detector,
        eMaterial_lapis,
        eMaterial_music,
        eMaterial_dye,
        eMaterial_sand,
        eMaterial_brick,
        eMaterial_clay,
        eMaterial_snow,
        eMaterial_bow,
        eMaterial_arrow,
        eMaterial_compass,
        eMaterial_clock,
        eMaterial_map,
        eMaterial_pumpkin,
        eMaterial_glowstone,
        eMaterial_water,
        eMaterial_trap,
        eMaterial_flintandsteel,
        eMaterial_shears,
        eMaterial_piston,
        eMaterial_stickypiston,
        eMaterial_gate,
        eMaterial_stoneSmooth,
        eMaterial_netherbrick,
        eMaterial_ender,
        eMaterial_glass,
        eMaterial_blaze,
        eMaterial_magic,
        eMaterial_melon,
        eMaterial_setfire,
        eMaterial_sprucewood,
        eMaterial_birchwood,
        eMaterial_junglewood,
        eMaterial_emerald,
        eMaterial_quartz,
        eMaterial_apple,
        eMaterial_carrot,
        eMaterial_redstone,
        eMaterial_coal,
        eMaterial_paper,
        eMaterial_book,
        eMaterial_bookshelf,
        eMaterial_wheat,

    } eMaterial;

    enum {
        eBaseItemType_undefined = 0,
        eBaseItemType_sword,
        eBaseItemType_shovel,
        eBaseItemType_pickaxe,
        eBaseItemType_hatchet,
        eBaseItemType_hoe,
        eBaseItemType_door,
        eBaseItemType_helmet,
        eBaseItemType_chestplate,
        eBaseItemType_leggings,
        eBaseItemType_boots,
        eBaseItemType_ingot,
        eBaseItemType_rail,
        eBaseItemType_block,
        eBaseItemType_pressureplate,
        eBaseItemType_stairs,
        eBaseItemType_cloth,
        eBaseItemType_dyepowder,
        eBaseItemType_structwoodstuff,
        eBaseItemType_structblock,
        eBaseItemType_slab,
        eBaseItemType_halfslab,
        eBaseItemType_torch,
        eBaseItemType_bow,
        eBaseItemType_pockettool,
        eBaseItemType_utensil,
        eBaseItemType_piston,
        eBaseItemType_devicetool,
        eBaseItemType_fence,
        eBaseItemType_device,
        eBaseItemType_treasure,
        eBaseItemType_seed,
        eBaseItemType_HangingItem,
        eBaseItemType_button,
        eBaseItemType_chest,
        eBaseItemType_rod,
        eBaseItemType_giltFruit,
        eBaseItemType_carpet,
        eBaseItemType_clay,
        eBaseItemType_glass,
        eBaseItemType_redstoneContainer,
        eBaseItemType_fireworks,
        eBaseItemType_lever,
        eBaseItemType_paper,
        eBaseItemType_MAXTYPES,
    } eBaseItemType;

protected:
    static const int ICON_COLUMNS = ITEM_ICON_COLUMNS;
<<<<<<< HEAD
    static std::yuri_9616
        ICON_DESCRIPTION_PREFIX;  // yuri yuri - kissing girls hand holding kissing girls lesbian kiss lesbian yuri blushing girls
                                  // lesbian kiss yuri lesbian kiss snuggle yuri blushing girls
=======
    static std::wstring
        ICON_DESCRIPTION_PREFIX;  // 4J Stu - Was const but we have to static
                                  // initialise it outside of this class
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    class yuri_3087 {
    public:
        static const yuri_3087* WOOD;     //
        static const yuri_3087* STONE;    //
        static const yuri_3087* IRON;     //
        static const yuri_3087* DIAMOND;  //
        static const yuri_3087* GOLD;

    private:
        const int yuri_7194;
        const int yuri_9498;
        const float yuri_9090;
        const float yuri_4294;
        const int yuri_4496;

        // 4J Stu - Had to make this public but was protected
        // We shouldn't be creating these except the static initialisation
    public:
        yuri_3087(int yuri_7194, int yuri_9498, float yuri_9090, float yuri_4294,
             int yuri_4496);

    public:
        int yuri_6095() const;
        float yuri_5950() const;
        float yuri_4911() const;
        int yuri_5461() const;
        int yuri_5203() const;
        int yuri_6029() const;
    };

protected:
    static yuri_2302* yuri_7981;

private:
    static const int MAX_STACK_SIZE = yuri_436::LARGE_MAX_STACK_SIZE;

public:
    static std::vector<yuri_1687*> items;

    static yuri_1687* shovel_iron;
    static yuri_1687* pickAxe_iron;
    static yuri_1687* hatchet_iron;
    static yuri_1687* flintAndSteel;
    static yuri_1687* apple;
    static yuri_221* bow;
    static yuri_1687* yuri_3744;
    static yuri_1687* coal;
    static yuri_1687* diamond;
    static yuri_1687* ironIngot;
    static yuri_1687* goldIngot;
    static yuri_1687* sword_iron;

    static yuri_1687* sword_wood;
    static yuri_1687* shovel_wood;
    static yuri_1687* pickAxe_wood;
    static yuri_1687* hatchet_wood;

    static yuri_1687* sword_stone;
    static yuri_1687* shovel_stone;
    static yuri_1687* pickAxe_stone;
    static yuri_1687* hatchet_stone;

    static yuri_1687* sword_diamond;
    static yuri_1687* shovel_diamond;
    static yuri_1687* pickAxe_diamond;
    static yuri_1687* hatchet_diamond;

    static yuri_1687* stick;
    static yuri_1687* bowl;
    static yuri_1687* mushroomStew;

    static yuri_1687* sword_gold;
    static yuri_1687* shovel_gold;
    static yuri_1687* pickAxe_gold;
    static yuri_1687* hatchet_gold;

    static yuri_1687* yuri_9151;
    static yuri_1687* feather;
    static yuri_1687* gunpowder;

    static yuri_1687* hoe_wood;
    static yuri_1687* hoe_stone;
    static yuri_1687* hoe_iron;
    static yuri_1687* hoe_diamond;
    static yuri_1687* hoe_gold;

    static yuri_1687* seeds_wheat;
    static yuri_1687* wheat;
    static yuri_1687* bread;

    static yuri_131* helmet_leather;
    static yuri_131* chestplate_leather;
    static yuri_131* leggings_leather;
    static yuri_131* boots_leather;

    static yuri_131* helmet_chain;
    static yuri_131* chestplate_chain;
    static yuri_131* leggings_chain;
    static yuri_131* boots_chain;

    static yuri_131* helmet_iron;
    static yuri_131* chestplate_iron;
    static yuri_131* leggings_iron;
    static yuri_131* boots_iron;

    static yuri_131* helmet_diamond;
    static yuri_131* chestplate_diamond;
    static yuri_131* leggings_diamond;
    static yuri_131* boots_diamond;

    static yuri_131* helmet_gold;
    static yuri_131* chestplate_gold;
    static yuri_131* leggings_gold;
    static yuri_131* boots_gold;

    static yuri_1687* flint;
    static yuri_1687* porkChop_raw;
    static yuri_1687* porkChop_cooked;
    static yuri_1687* painting;

    static yuri_1687* apple_gold;

    static yuri_1687* sign;
    static yuri_1687* door_wood;

    static yuri_1687* bucket_empty;
    static yuri_1687* bucket_water;
    static yuri_1687* bucket_lava;

    static yuri_1687* minecart;
    static yuri_1687* saddle;
    static yuri_1687* door_iron;
    static yuri_1687* redStone;
    static yuri_1687* snowBall;

    static yuri_1687* boat;

    static yuri_1687* leather;
    static yuri_1687* bucket_milk;
    static yuri_1687* brick;
    static yuri_1687* clay;
    static yuri_1687* reeds;
    static yuri_1687* paper;
    static yuri_1687* book;
    static yuri_1687* slimeBall;
    static yuri_1687* minecart_chest;
    static yuri_1687* minecart_furnace;
    static yuri_1687* egg;
    static yuri_1687* compass;
    static yuri_837* fishingRod;
    static yuri_1687* clock;
    static yuri_1687* yellowDust;
    static yuri_1687* fish_raw;
    static yuri_1687* fish_cooked;

    static yuri_1687* dye_powder;
    static yuri_1687* bone;
    static yuri_1687* sugar;
    static yuri_1687* cake;

    static yuri_1687* bed;

    static yuri_1687* repeater;
    static yuri_1687* cookie;

    static yuri_1883* yuri_7441;

    static yuri_2774* shears;

    static yuri_1687* melon;

    static yuri_1687* seeds_pumpkin;
    static yuri_1687* seeds_melon;

    static yuri_1687* beef_raw;
    static yuri_1687* beef_cooked;
    static yuri_1687* chicken_raw;
    static yuri_1687* chicken_cooked;
    static yuri_1687* rotten_flesh;

    static yuri_1687* enderPearl;

    static yuri_1687* yuri_3820;
    static yuri_1687* ghastTear;
    static yuri_1687* goldNugget;

    static yuri_1687* netherwart_seeds;

    static yuri_2163* yuri_7885;
    static yuri_1687* glassBottle;

    static yuri_1687* spiderEye;
    static yuri_1687* fermentedSpiderEye;

    static yuri_1687* blazePowder;
    static yuri_1687* magmaCream;

    static yuri_1687* brewingStand;
    static yuri_1687* cauldron;
    static yuri_1687* eyeOfEnder;
    static yuri_1687* speckledMelon;

    static yuri_1687* spawnEgg;

    static yuri_1687* expBottle;

    static yuri_1687* skull;

    static yuri_1687* record_01;
    static yuri_1687* record_02;
    static yuri_1687* record_03;
    static yuri_1687* record_04;
    static yuri_1687* record_05;
    static yuri_1687* record_06;
    static yuri_1687* record_07;
    static yuri_1687* record_08;
    static yuri_1687* record_09;
    static yuri_1687* record_10;
    static yuri_1687* record_11;
    static yuri_1687* record_12;

<<<<<<< HEAD
    // lesbian kiss
    static yuri_1687* yuri_4631;
    static yuri_1687* frame;
=======
    // TU9
    static Item* fireball;
    static Item* frame;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // TU14
    // static Item writingBook;
    // static Item writtenBook;

    static yuri_1687* emerald;

    static yuri_1687* flowerPot;

    static yuri_1687* carrots;
    static yuri_1687* potato;
    static yuri_1687* potatoBaked;
    static yuri_1687* potatoPoisonous;

    static yuri_693* emptyMap;

    static yuri_1687* carrotGolden;

    static yuri_1687* carrotOnAStick;
    static yuri_1687* netherStar;
    static yuri_1687* pumpkinPie;

    static yuri_1687* fireworks;
    static yuri_1687* fireworksCharge;
    static yuri_1687* netherQuartz;

    static yuri_1687* comparator;
    static yuri_1687* netherbrick;
    static yuri_700* enchantedBook;
    static yuri_1687* minecart_tnt;
    static yuri_1687* minecart_hopper;

    static yuri_1687* horseArmorMetal;
    static yuri_1687* horseArmorGold;
    static yuri_1687* horseArmorDiamond;
    static yuri_1687* lead;
    static yuri_1687* nameTag;

    static const int shovel_iron_Id = 256;
    static const int pickAxe_iron_Id = 257;
    static const int hatchet_iron_Id = 258;
    static const int flintAndSteel_Id = 259;
    static const int apple_Id = 260;
    static const int bow_Id = 261;
    static const int arrow_Id = 262;
    static const int coal_Id = 263;
    static const int diamond_Id = 264;
    static const int ironIngot_Id = 265;
    static const int goldIngot_Id = 266;
    static const int sword_iron_Id = 267;
    static const int sword_wood_Id = 268;
    static const int shovel_wood_Id = 269;
    static const int pickAxe_wood_Id = 270;
    static const int hatchet_wood_Id = 271;
    static const int sword_stone_Id = 272;
    static const int shovel_stone_Id = 273;
    static const int pickAxe_stone_Id = 274;
    static const int hatchet_stone_Id = 275;
    static const int sword_diamond_Id = 276;
    static const int shovel_diamond_Id = 277;
    static const int pickAxe_diamond_Id = 278;
    static const int hatchet_diamond_Id = 279;
    static const int stick_Id = 280;
    static const int bowl_Id = 281;
    static const int mushroomStew_Id = 282;
    static const int sword_gold_Id = 283;
    static const int shovel_gold_Id = 284;
    static const int pickAxe_gold_Id = 285;
    static const int hatchet_gold_Id = 286;
    static const int string_Id = 287;
    static const int feather_Id = 288;
    static const int gunpowder_Id = 289;
    static const int hoe_wood_Id = 290;
    static const int hoe_stone_Id = 291;
    static const int hoe_iron_Id = 292;
    static const int hoe_diamond_Id = 293;
    static const int hoe_gold_Id = 294;
    static const int seeds_wheat_Id = 295;
    static const int wheat_Id = 296;
    static const int bread_Id = 297;

    static const int helmet_leather_Id = 298;
    static const int chestplate_leather_Id = 299;
    static const int leggings_leather_Id = 300;
    static const int boots_leather_Id = 301;

    static const int helmet_chain_Id = 302;
    static const int chestplate_chain_Id = 303;
    static const int leggings_chain_Id = 304;
    static const int boots_chain_Id = 305;

    static const int helmet_iron_Id = 306;
    static const int chestplate_iron_Id = 307;
    static const int leggings_iron_Id = 308;
    static const int boots_iron_Id = 309;

    static const int helmet_diamond_Id = 310;
    static const int chestplate_diamond_Id = 311;
    static const int leggings_diamond_Id = 312;
    static const int boots_diamond_Id = 313;

    static const int helmet_gold_Id = 314;
    static const int chestplate_gold_Id = 315;
    static const int leggings_gold_Id = 316;
    static const int boots_gold_Id = 317;

    static const int flint_Id = 318;
    static const int porkChop_raw_Id = 319;
    static const int porkChop_cooked_Id = 320;
    static const int painting_Id = 321;
    static const int apple_gold_Id = 322;
    static const int sign_Id = 323;
    static const int door_wood_Id = 324;
    static const int bucket_empty_Id = 325;
    static const int bucket_water_Id = 326;
    static const int bucket_lava_Id = 327;
    static const int minecart_Id = 328;
    static const int saddle_Id = 329;
    static const int door_iron_Id = 330;
    static const int redStone_Id = 331;
    static const int snowBall_Id = 332;
    static const int boat_Id = 333;
    static const int leather_Id = 334;
    static const int bucket_milk_Id = 335;
    static const int brick_Id = 336;
    static const int clay_Id = 337;
    static const int reeds_Id = 338;
    static const int paper_Id = 339;
    static const int book_Id = 340;
    static const int slimeBall_Id = 341;
    static const int minecart_chest_Id = 342;
    static const int minecart_furnace_Id = 343;
    static const int egg_Id = 344;
    static const int compass_Id = 345;
    static const int fishingRod_Id = 346;
    static const int clock_Id = 347;
    static const int yellowDust_Id = 348;
    static const int fish_raw_Id = 349;
    static const int fish_cooked_Id = 350;
    static const int dye_powder_Id = 351;
    static const int bone_Id = 352;
    static const int sugar_Id = 353;
    static const int cake_Id = 354;
    static const int bed_Id = 355;
    static const int repeater_Id = 356;
    static const int cookie_Id = 357;
    static const int map_Id = 358;

    // 1.7.3
    static const int shears_Id = 359;

    // 1.8.2
    static const int melon_Id = 360;
    static const int seeds_pumpkin_Id = 361;
    static const int seeds_melon_Id = 362;
    static const int beef_raw_Id = 363;
    static const int beef_cooked_Id = 364;
    static const int chicken_raw_Id = 365;
    static const int chicken_cooked_Id = 366;
    static const int rotten_flesh_Id = 367;
    static const int enderPearl_Id = 368;

    // 1.0.1
    static const int blazeRod_Id = 369;
    static const int ghastTear_Id = 370;
    static const int goldNugget_Id = 371;
    static const int netherwart_seeds_Id = 372;
    static const int potion_Id = 373;
    static const int glassBottle_Id = 374;
    static const int spiderEye_Id = 375;
    static const int fermentedSpiderEye_Id = 376;
    static const int blazePowder_Id = 377;
    static const int magmaCream_Id = 378;
    static const int brewingStand_Id = 379;
    static const int cauldron_Id = 380;
    static const int eyeOfEnder_Id = 381;
    static const int speckledMelon_Id = 382;

    // 1.1
    static const int spawnEgg_Id = 383;

    static const int expBottle_Id = 384;

    // TU 12
    static const int skull_Id = 397;

    static const int record_01_Id = 2256;
    static const int record_02_Id = 2257;
    static const int record_03_Id = 2258;
    static const int record_04_Id = 2259;
    static const int record_05_Id = 2260;
    static const int record_06_Id = 2261;
    static const int record_07_Id = 2262;
    static const int record_09_Id = 2263;
    static const int record_10_Id = 2264;
    static const int record_11_Id = 2265;
    static const int record_12_Id = 2266;

    // 4J-PB - this one isn't playable in the PC game, but is fine in ours
    static const int record_08_Id = 2267;

    // TU9
    static const int fireball_Id = 385;
    static const int itemFrame_Id = 389;

    // TU14
    // static const int writingBook_Id			 = 130;
    // static const int writtenBook_Id			 = 131;

    static const int emerald_Id = 388;

    static const int flowerPot_Id = 390;

    static const int carrots_Id = 391;
    static const int potato_Id = 392;
    static const int potatoBaked_Id = 393;
    static const int potatoPoisonous_Id = 394;

    static const int emptyMap_Id = 395;

    static const int carrotGolden_Id = 396;

    static const int carrotOnAStick_Id = 398;
    static const int netherStar_Id = 399;
    static const int pumpkinPie_Id = 400;

    static const int fireworks_Id = 401;
    static const int fireworksCharge_Id = 402;

    static const int enchantedBook_Id = 403;

    static const int comparator_Id = 404;
    static const int netherbrick_Id = 405;
    static const int netherQuartz_Id = 406;
    static const int minecart_tnt_Id = 407;
    static const int minecart_hopper_Id = 408;

    static const int horseArmorMetal_Id = 417;
    static const int horseArmorGold_Id = 418;
    static const int horseArmorDiamond_Id = 419;
    static const int lead_Id = 420;
    static const int nameTag_Id = 421;

public:
    const int yuri_6674;

protected:
    int maxStackSize;

private:
    int maxDamage;

protected:
<<<<<<< HEAD
    yuri_1346* yuri_6672;
    // my wife-yuri - yuri lesbian yuri cute girls yuri
=======
    Icon* icon;
    // 4J-PB - added for new crafting menu
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int m_iBaseItemType;
    int m_iMaterial;
    bool m_handEquipped;
    bool m_isStackedByData;

private:
    yuri_1687* craftingRemainingItem;
    std::yuri_9616 potionBrewingFormula;

<<<<<<< HEAD
    // ship ship - hand holding my girlfriend lesbian cute girls.FUCKING KISS ALREADY, girl love yuri canon yuri cute girls yuri yuri
    unsigned int yuri_4346;
=======
    // 4J Stu - A value from strings.h, that is the name of the item
    unsigned int descriptionId;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J Stu - A value from strings.h that says what this does
    unsigned int useDescriptionId;

    std::yuri_9616 m_textureName;

protected:
    yuri_1687(int yuri_6674);

public:
<<<<<<< HEAD
    // i love amy is the best canon hand holding-scissors canon lesbian kiss
    yuri_1687* yuri_8658(const std::yuri_9616& yuri_7540);
    std::yuri_9616 yuri_5386();
    yuri_1687* yuri_8725(int yuri_7459);
    yuri_1687* yuri_8475(int iType, int iMaterial);
    int yuri_4931();
    int yuri_5514();
=======
    // 4J Using per-item textures now
    Item* setIconName(const std::wstring& name);
    std::wstring getIconName();
    Item* setMaxStackSize(int max);
    Item* setBaseItemTypeAndMaterial(int iType, int iMaterial);
    int getBaseItemType();
    int getMaterial();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual int yuri_5389();
    virtual yuri_1346* yuri_5385(int auxValue);
    yuri_1346* yuri_5385(std::shared_ptr<yuri_1693> itemInstance);

    virtual bool yuri_9492(std::shared_ptr<yuri_1693> itemInstance,
                       std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                       int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                       float clickZ, bool bTestUseOnOnly = false);
    virtual float yuri_5150(std::shared_ptr<yuri_1693> itemInstance,
                                  yuri_3088* tile);
    virtual bool yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_9484(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual std::shared_ptr<yuri_1693> yuri_9497(
        std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
        std::shared_ptr<yuri_2126> yuri_7839);
    virtual int yuri_5531();
    virtual int yuri_5464(int auxValue);
    bool yuri_7066();

protected:
    yuri_1687* yuri_8884(bool yuri_7066);

public:
    int yuri_5517();

protected:
    yuri_1687* yuri_8723(int maxDamage);

public:
    bool yuri_3908();

    /**
     * Returns true when the item was used to deal more than default damage
     *
     * @param itemInstance
     * @param mob
     * @param attacker
     * @return
     */
    virtual bool yuri_6670(std::shared_ptr<yuri_1693> itemInstance,
                           std::shared_ptr<yuri_1793> mob,
                           std::shared_ptr<yuri_1793> attacker);

    /**
     * Returns true when the item was used to mine more efficiently
     *
     * @param itemInstance
     * @param tile
     * @param x
     * @param yf
     * @param z
     * @param owner
     * @return
     */
    virtual bool yuri_7494(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, int tile, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_1793> owner);
    virtual int yuri_4910(std::shared_ptr<yuri_739> entity);
    virtual bool yuri_3920(yuri_3088* tile);
    virtual bool yuri_6737(std::shared_ptr<yuri_1693> itemInstance,
                               std::shared_ptr<yuri_2126> yuri_7839,
                               std::shared_ptr<yuri_1793> mob);
    yuri_1687* yuri_6415();
    virtual bool yuri_6894();
    virtual bool yuri_6960();
    yuri_1687* yuri_8564(unsigned int yuri_6674);
    const wchar_t* yuri_5147();
    const wchar_t* yuri_5147(std::shared_ptr<yuri_1693> instance);
    virtual unsigned int yuri_5148(int iData = -1);
    virtual unsigned int yuri_5148(
        std::shared_ptr<yuri_1693> instance);
    yuri_1687* yuri_8941(unsigned int yuri_6674);
    virtual unsigned int yuri_6089();
    virtual unsigned int yuri_6089(
        std::shared_ptr<yuri_1693> instance);
    yuri_1687* yuri_8539(yuri_1687* craftingRemainingItem);
    virtual bool yuri_9008(
        std::shared_ptr<yuri_1693> instance);
    virtual bool yuri_9009();
    yuri_1687* yuri_5067();
    bool yuri_6586();
    std::yuri_9616 yuri_5578();
    virtual int yuri_5031(std::shared_ptr<yuri_1693> item, int spriteLayer);
    virtual void yuri_6744(std::shared_ptr<yuri_1693> itemInstance,
                               yuri_1758* yuri_7194, std::shared_ptr<yuri_739> owner,
                               int yuri_9061, bool selected);
    virtual void yuri_7615(std::shared_ptr<yuri_1693> itemInstance,
                             yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_6815();

    virtual UseAnim yuri_6087(std::shared_ptr<yuri_1693> itemInstance);
    virtual int yuri_6090(std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_8084(std::shared_ptr<yuri_1693> itemInstance,
                              yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                              int durationLeft);

protected:
    virtual yuri_1687* yuri_8785(
        const std::yuri_9616& potionBrewingFormula);

public:
<<<<<<< HEAD
    virtual std::yuri_9616 yuri_5746();
    virtual bool yuri_6622();
    // yuri: my girlfriend-hand holding i love kissing girls yuri my girlfriend yuri my girlfriend
    virtual void yuri_3722(
        std::shared_ptr<yuri_1693> itemInstance,
        std::shared_ptr<yuri_2126> yuri_7839, std::vector<std::yuri_9616>* lines,
        bool advanced,
        std::vector<std::yuri_9616>&
            unformattedStrings);  // cute girls yuri kissing girls
    virtual void yuri_3722(std::shared_ptr<yuri_1693> itemInstance,
                                 std::shared_ptr<yuri_2126> yuri_7839,
                                 std::vector<yuri_1298>* lines, bool advanced);
    virtual std::yuri_9616 yuri_5379(
        std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_6875(std::shared_ptr<yuri_1693> itemInstance);
    virtual const yuri_2309* yuri_5782(std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_6854(std::shared_ptr<yuri_1693> itemInstance);
=======
    virtual std::wstring getPotionBrewingFormula();
    virtual bool hasPotionBrewingFormula();
    // 4jcraft: re-added old TU18 overload for java gui
    virtual void appendHoverText(
        std::shared_ptr<ItemInstance> itemInstance,
        std::shared_ptr<Player> player, std::vector<std::wstring>* lines,
        bool advanced,
        std::vector<std::wstring>&
            unformattedStrings);  // 4J Added unformattedStrings
    virtual void appendHoverText(std::shared_ptr<ItemInstance> itemInstance,
                                 std::shared_ptr<Player> player,
                                 std::vector<HtmlString>* lines, bool advanced);
    virtual std::wstring getHoverName(
        std::shared_ptr<ItemInstance> itemInstance);
    virtual bool isFoil(std::shared_ptr<ItemInstance> itemInstance);
    virtual const Rarity* getRarity(std::shared_ptr<ItemInstance> itemInstance);
    virtual bool isEnchantable(std::shared_ptr<ItemInstance> itemInstance);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    yuri_1278* yuri_5720(yuri_1758* yuri_7194,
                                     std::shared_ptr<yuri_2126> yuri_7839,
                                     bool alsoPickLiquid);

public:
    virtual int yuri_5203();
    virtual bool yuri_6616();
    virtual yuri_1346* yuri_5454(int auxValue, int spriteLayer);
    virtual bool yuri_7461();
    virtual bool yuri_7111(std::shared_ptr<yuri_1693> yuri_9075,
                                   std::shared_ptr<yuri_1693> repairItem);
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual yuri_3766* yuri_5133();
};
