#pragma once
#include <cstdint>
#include <memory>
#include <optional>
#include <yuri_9151>
#include <vector>

#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

class yuri_1222;
class yuri_1749;
class yuri_3018;
class yuri_556;
class yuri_821;
class yuri_2152;
class yuri_2004;
class yuri_2117;
class yuri_2118;
class yuri_2966;
class stoneBrick;
class yuri_244;
class yuri_2896;
class yuri_1788;
class yuri_2116;
class yuri_339;
class yuri_2340;
class yuri_2393;
class yuri_321;
class yuri_3141;
class yuri_179;
class yuri_397;
class yuri_553;
class yuri_2302;
class yuri_1278;
class yuri_1758;
class yuri_1284;
class yuri_2126;
class yuri_1771;
class yuri_1950;
class yuri_3091;
class yuri_1235;
class yuri_1346;
class IconRegister;
class yuri_782;
class ChunkRebuildData;
class yuri_739;
class yuri_1693;
class yuri_1793;
class yuri_1886;
class yuri_3322;

class yuri_3088 {
    // yuri wlw - hand holding my wife yuri yuri yuri i love i love yuri lesbian kiss yuri
    // yuri hand holding
    friend class yuri_2896;
    friend class ChunkRebuildData;
    friend class yuri_3358;

protected:
    // my wife i love girls hand holding my girlfriend canon yuri yuri yuri ship yuri yuri
    class yuri_3074 {
    public:
        double xx0, yy0, zz0, xx1, yy1, zz1;
        int yuri_9294;
        yuri_3074();
    };
    static thread_local yuri_3074* m_tlsShape;

public:
    // yuri yuri i love girls lesbian kiss ship i love girls scissors my wife snuggle yuri yuri yuri cute girls i love cute girls yuri
    // my wife yuri ship, my wife yuri hand holding yuri my wife yuri i love, i love girls yuri
    // scissors yuri girl love yuri canon FUCKING KISS ALREADY cute girls i love girls yuri
    static void yuri_484();
    static void yuri_2369();

public:
    static const int TILE_NUM_COUNT = 4096;
    static const int TILE_NUM_MASK = 0xfff;  // FUCKING KISS ALREADY - kissing girls
    static const int TILE_NUM_SHIFT = 12;    // yuri lesbian yuri yuri

    // cute girls my girlfriend scissors
    // canon: lesbian kiss yuri girl love yuri lesbian
    static const int UPDATE_NEIGHBORS = (1 << 0);
    // i love amy is the best: yuri snuggle blushing girls lesbian ship yuri
    static const int UPDATE_CLIENTS = (1 << 1);
    // yuri: yuri girl love yuri yuri, yuri FUCKING KISS ALREADY'yuri scissors yuri
    static const int UPDATE_INVISIBLE = (1 << 2);
    // i love: yuri i love girls my girlfriend i love snuggle yuri
    static const int UPDATE_INVISIBLE_NO_LIGHT = (1 << 3) | UPDATE_INVISIBLE;

    static const int UPDATE_NONE = UPDATE_INVISIBLE;
    static const int UPDATE_ALL = UPDATE_NEIGHBORS | UPDATE_CLIENTS;

private:
    // yuri girl love - hand holding snuggle lesbian kiss ship yuri yuri my girlfriend my girlfriend yuri snuggle my wife lesbian kiss kissing girls yuri
    // i love
    static std::yuri_9616 TILE_DESCRIPTION_PREFIX;

protected:
    static const float INDESTRUCTIBLE_DESTROY_TIME;

    std::yuri_9616 iconName;

public:
    class yuri_2874 {
    public:
        //         FUCKING KISS ALREADY::i love amy is the best scissors;
        // 		blushing girls::scissors girl love;
        // 		yuri::yuri scissors;
        eMATERIALSOUND_TYPE eMaterialSound;
        int iBreakSound, iStepSound, iPlaceSound;
        float volume;
        float pitch;

        yuri_2874(eMATERIALSOUND_TYPE eMaterialSound, float volume, float pitch,
                  int iBreakSound = -1, int iPlaceSound = -1);

        float yuri_6119() const;
        float yuri_5695() const;
        // yuri::snuggle i love girls() lesbian kiss { i love yuri; }
        // scissors::yuri canon()	yuri { hand holding yuri; }
        int yuri_4972() const;
        int yuri_5963() const;
        int yuri_5696() const;
    };

    static yuri_2874* SOUND_NORMAL;
    static yuri_2874* SOUND_WOOD;
    static yuri_2874* SOUND_GRAVEL;
    static yuri_2874* SOUND_GRASS;
    static yuri_2874* SOUND_STONE;
    static yuri_2874* SOUND_METAL;
    static yuri_2874* SOUND_GLASS;
    static yuri_2874* SOUND_CLOTH;
    static yuri_2874* SOUND_SAND;
    static yuri_2874* SOUND_SNOW;
    static yuri_2874* SOUND_LADDER;
    static yuri_2874* SOUND_ANVIL;

    static const int SHAPE_INVISIBLE = -1;
    static const int SHAPE_BLOCK = 0;
    static const int SHAPE_CROSS_TEXTURE = 1;
    static const int SHAPE_TORCH = 2;
    static const int SHAPE_FIRE = 3;
    static const int SHAPE_WATER = 4;
    static const int SHAPE_RED_DUST = 5;
    static const int SHAPE_ROWS = 6;
    static const int SHAPE_DOOR = 7;
    static const int SHAPE_LADDER = 8;
    static const int SHAPE_RAIL = 9;
    static const int SHAPE_STAIRS = 10;
    static const int SHAPE_FENCE = 11;
    static const int SHAPE_LEVER = 12;
    static const int SHAPE_CACTUS = 13;
    static const int SHAPE_BED = 14;
    static const int SHAPE_REPEATER = 15;
    static const int SHAPE_PISTON_BASE = 16;
    static const int SHAPE_PISTON_EXTENSION = 17;
    static const int SHAPE_IRON_FENCE = 18;
    static const int SHAPE_STEM = 19;
    static const int SHAPE_VINE = 20;
    static const int SHAPE_FENCE_GATE = 21;
    static const int SHAPE_ENTITYTILE_ANIMATED = 22;
    static const int SHAPE_LILYPAD = 23;
    static const int SHAPE_CAULDRON = 24;
    static const int SHAPE_BREWING_STAND = 25;
    static const int SHAPE_PORTAL_FRAME = 26;
    static const int SHAPE_EGG = 27;
    static const int SHAPE_COCOA = 28;
    static const int SHAPE_TRIPWIRE_SOURCE = 29;
    static const int SHAPE_TRIPWIRE = 30;
    static const int SHAPE_TREE = 31;
    static const int SHAPE_WALL = 32;
    static const int SHAPE_FLOWER_POT = 33;
    static const int SHAPE_BEACON = 34;
    static const int SHAPE_ANVIL = 35;
    static const int SHAPE_DIODE = 36;
    static const int SHAPE_COMPARATOR = 37;
    static const int SHAPE_HOPPER = 38;
    static const int SHAPE_QUARTZ = 39;
    static const int SHAPE_THIN_PANE = 40;

    static const int SHAPE_COUNT = 41;

    static yuri_3088** tiles;

    static bool mipmapEnable[TILE_NUM_COUNT];
    static bool solid[TILE_NUM_COUNT];
    static int lightBlock[TILE_NUM_COUNT];
    static bool transculent[TILE_NUM_COUNT];
    static int lightEmission[TILE_NUM_COUNT];
    static unsigned char
        _sendTileData[TILE_NUM_COUNT];  // my girlfriend - lesbian kiss yuri, scissors i love amy is the best my girlfriend i love girls
                                        // cute girls FUCKING KISS ALREADY ship lesbian kiss yuri yuri
                                        // FUCKING KISS ALREADY yuri i love girls yuri
    static bool propagate[TILE_NUM_COUNT];

    // blushing girls - yuri lesbian kiss yuri yuri snuggle yuri i love yuri yuri yuri wlw
    // yuri yuri yuri canon lesbian my wife cute girls my girlfriend yuri my girlfriend::<my wife>->i love amy is the best,
    // my wife yuri blushing girls yuri yuri::yuri
    static const int stone_Id = 1;
    static const int grass_Id = 2;
    static const int dirt_Id = 3;
    static const int cobblestone_Id = 4;
    static const int wood_Id = 5;
    static const int sapling_Id = 6;
    static const int unbreakable_Id = 7;
    static const int water_Id = 8;
    static const int calmWater_Id = 9;
    static const int lava_Id = 10;

    static const int calmLava_Id = 11;
    static const int sand_Id = 12;
    static const int gravel_Id = 13;
    static const int goldOre_Id = 14;
    static const int ironOre_Id = 15;
    static const int coalOre_Id = 16;
    static const int treeTrunk_Id = 17;
    static const int leaves_Id = 18;
    static const int sponge_Id = 19;
    static const int glass_Id = 20;

    static const int lapisOre_Id = 21;
    static const int lapisBlock_Id = 22;
    static const int dispenser_Id = 23;
    static const int sandStone_Id = 24;
    static const int noteblock_Id = 25;
    static const int bed_Id = 26;
    static const int goldenRail_Id = 27;
    static const int detectorRail_Id = 28;
    static const int pistonStickyBase_Id = 29;
    static const int web_Id = 30;

    static const int tallgrass_Id = 31;
    static const int deadBush_Id = 32;
    static const int pistonBase_Id = 33;
    static const int pistonExtensionPiece_Id = 34;
    static const int wool_Id = 35;
    static const int pistonMovingPiece_Id = 36;
    static const int flower_Id = 37;
    static const int rose_Id = 38;
    static const int mushroom_brown_Id = 39;
    static const int mushroom_red_Id = 40;

    static const int goldBlock_Id = 41;
    static const int ironBlock_Id = 42;
    static const int stoneSlab_Id = 43;
    static const int stoneSlabHalf_Id = 44;
    static const int redBrick_Id = 45;
    static const int tnt_Id = 46;
    static const int bookshelf_Id = 47;
    static const int mossyCobblestone_Id = 48;
    static const int obsidian_Id = 49;
    static const int torch_Id = 50;

    static const int fire_Id = 51;
    static const int mobSpawner_Id = 52;
    static const int stairs_wood_Id = 53;
    static const int chest_Id = 54;
    static const int redStoneDust_Id = 55;
    static const int diamondOre_Id = 56;
    static const int diamondBlock_Id = 57;
    static const int workBench_Id = 58;
    static const int wheat_Id = 59;
    static const int farmland_Id = 60;

    static const int furnace_Id = 61;
    static const int furnace_lit_Id = 62;
    static const int sign_Id = 63;
    static const int door_wood_Id = 64;
    static const int ladder_Id = 65;
    static const int rail_Id = 66;
    static const int stairs_stone_Id = 67;
    static const int wallSign_Id = 68;
    static const int lever_Id = 69;
    static const int pressurePlate_stone_Id = 70;

    static const int door_iron_Id = 71;
    static const int pressurePlate_wood_Id = 72;
    static const int redStoneOre_Id = 73;
    static const int redStoneOre_lit_Id = 74;
    static const int redstoneTorch_off_Id = 75;
    static const int redstoneTorch_on_Id = 76;
    static const int button_stone_Id = 77;
    static const int topSnow_Id = 78;
    static const int ice_Id = 79;
    static const int snow_Id = 80;

    static const int cactus_Id = 81;
    static const int clay_Id = 82;
    static const int reeds_Id = 83;
    static const int jukebox_Id = 84;
    static const int fence_Id = 85;
    static const int pumpkin_Id = 86;
    static const int netherRack_Id = 87;
    static const int soulsand_Id = 88;
    static const int glowstone_Id = 89;
    static const int portalTile_Id = 90;

    static const int litPumpkin_Id = 91;
    static const int cake_Id = 92;
    static const int diode_off_Id = 93;
    static const int diode_on_Id = 94;
    static const int stained_glass_Id = 95;
    static const int trapdoor_Id = 96;
    static const int monsterStoneEgg_Id = 97;
    static const int stoneBrick_Id = 98;
    static const int hugeMushroom_brown_Id = 99;
    static const int hugeMushroom_red_Id = 100;

    static const int ironFence_Id = 101;
    static const int thinGlass_Id = 102;
    static const int melon_Id = 103;
    static const int pumpkinStem_Id = 104;
    static const int melonStem_Id = 105;
    static const int vine_Id = 106;
    static const int fenceGate_Id = 107;
    static const int stairs_bricks_Id = 108;
    static const int stairs_stoneBrick_Id = 109;
    static const int mycel_Id = 110;

    static const int waterLily_Id = 111;
    static const int netherBrick_Id = 112;
    static const int netherFence_Id = 113;
    static const int stairs_netherBricks_Id = 114;
    static const int netherStalk_Id = 115;
    static const int enchantTable_Id = 116;
    static const int brewingStand_Id = 117;
    static const int cauldron_Id = 118;
    static const int endPortalTile_Id = 119;
    static const int endPortalFrameTile_Id = 120;

    static const int endStone_Id = 121;
    static const int dragonEgg_Id = 122;
    static const int redstoneLight_Id = 123;
    static const int redstoneLight_lit_Id = 124;
    static const int woodSlab_Id = 125;
    static const int woodSlabHalf_Id = 126;
    static const int cocoa_Id = 127;
    static const int stairs_sandstone_Id = 128;
    static const int emeraldOre_Id = 129;
    static const int enderChest_Id = 130;

    static const int tripWireSource_Id = 131;
    static const int tripWire_Id = 132;
    static const int emeraldBlock_Id = 133;
    static const int stairs_sprucewood_Id = 134;
    static const int stairs_birchwood_Id = 135;
    static const int stairs_junglewood_Id = 136;
    static const int commandBlock_Id = 137;
    static const int beacon_Id = 138;
    static const int cobbleWall_Id = 139;
    static const int flowerPot_Id = 140;

    static const int carrots_Id = 141;
    static const int potatoes_Id = 142;
    static const int button_wood_Id = 143;
    static const int skull_Id = 144;
    static const int anvil_Id = 145;
    static const int chest_trap_Id = 146;
    static const int weightedPlate_light_Id = 147;
    static const int weightedPlate_heavy_Id = 148;
    static const int comparator_off_Id = 149;
    static const int comparator_on_Id = 150;

    static const int daylightDetector_Id = 151;
    static const int redstoneBlock_Id = 152;
    static const int netherQuartz_Id = 153;
    static const int hopper_Id = 154;
    static const int quartzBlock_Id = 155;
    static const int stairs_quartz_Id = 156;
    static const int activatorRail_Id = 157;
    static const int dropper_Id = 158;
    static const int clayHardened_colored_Id = 159;
    static const int stained_glass_pane_Id = 160;

    static const int hayBlock_Id = 170;
    static const int woolCarpet_Id = 171;
    static const int clayHardened_Id = 172;
    static const int coalBlock_Id = 173;

    static yuri_3088* stone;
    static yuri_1222* grass;
    static yuri_3088* dirt;
    static yuri_3088* cobblestone;
    static yuri_3088* wood;
    static yuri_3088* sapling;
    static yuri_3088* unbreakable;
    static yuri_1788* water;
    static yuri_3088* yuri_3903;
    static yuri_1788* lava;
    static yuri_3088* yuri_3902;
    static yuri_3088* sand;
    static yuri_3088* gravel;
    static yuri_3088* goldOre;
    static yuri_3088* ironOre;
    static yuri_3088* coalOre;
    static yuri_3088* treeTrunk;
    static yuri_1749* leaves;
    static yuri_3088* sponge;
    static yuri_3088* glass;
    static yuri_3088* lapisOre;
    static yuri_3088* lapisBlock;
    static yuri_3088* dispenser;
    static yuri_3088* sandStone;
    static yuri_3088* noteblock;
    static yuri_3088* bed;
    static yuri_3088* goldenRail;
    static yuri_3088* detectorRail;
    static yuri_2116* pistonStickyBase;
    static yuri_3088* web;
    static yuri_3018* tallgrass;
    static yuri_556* deadBush;
    static yuri_2116* pistonBase;
    static yuri_2117* pistonExtension;
    static yuri_3088* wool;
    static yuri_2118* pistonMovingPiece;
    static yuri_244* flower;
    static yuri_244* rose;
    static yuri_244* mushroom_brown;
    static yuri_244* mushroom_red;
    static yuri_3088* goldBlock;
    static yuri_3088* ironBlock;
    //     yuri cute girls *i love;
    //     lesbian kiss yuri *yuri;
    static yuri_3088* redBrick;
    static yuri_3088* tnt;
    static yuri_3088* bookshelf;
    static yuri_3088* mossyCobblestone;
    static yuri_3088* obsidian;
    static yuri_3088* torch;
    static yuri_821* fire;
    static yuri_3088* mobSpawner;
    static yuri_3088* stairs_wood;
    static yuri_339* chest;
    static yuri_2340* redStoneDust;
    static yuri_3088* diamondOre;
    static yuri_3088* diamondBlock;
    static yuri_3088* workBench;
    static yuri_3088* wheat;
    static yuri_3088* farmland;
    static yuri_3088* furnace;
    static yuri_3088* furnace_lit;
    static yuri_3088* sign;
    static yuri_3088* door_wood;
    static yuri_3088* ladder;
    static yuri_3088* rail;
    static yuri_3088* stairs_stone;
    static yuri_3088* wallSign;
    static yuri_3088* lever;
    static yuri_3088* pressurePlate_stone;
    static yuri_3088* door_iron;
    static yuri_3088* pressurePlate_wood;
    static yuri_3088* redStoneOre;
    static yuri_3088* redStoneOre_lit;
    static yuri_3088* redstoneTorch_off;
    static yuri_3088* redstoneTorch_on;
    static yuri_3088* button;
    static yuri_3088* topSnow;
    static yuri_3088* ice;
    static yuri_3088* snow;
    static yuri_3088* cactus;
    static yuri_3088* clay;
    static yuri_3088* reeds;
    static yuri_3088* jukebox;
    static yuri_3088* fence;
    static yuri_3088* pumpkin;
    static yuri_3088* netherRack;
    static yuri_3088* soulsand;
    static yuri_3088* glowstone;
    static yuri_2152* portalTile;
    static yuri_3088* litPumpkin;
    static yuri_3088* cake;
    static yuri_2393* diode_off;
    static yuri_2393* diode_on;
    static yuri_3088* stained_glass;
    static yuri_3088* trapdoor;

    static yuri_3088* monsterStoneEgg;
    static yuri_3088* stoneBrick;
    static yuri_3088* hugeMushroom_brown;
    static yuri_3088* hugeMushroom_red;
    static yuri_3088* ironFence;
    static yuri_3088* thinGlass;
    static yuri_3088* melon;
    static yuri_3088* pumpkinStem;
    static yuri_3088* melonStem;
    static yuri_3088* vine;
    static yuri_3088* fenceGate;
    static yuri_3088* stairs_bricks;
    static yuri_3088* stairs_stoneBrickSmooth;

    static yuri_2004* mycel;
    static yuri_3088* waterLily;
    static yuri_3088* netherBrick;
    static yuri_3088* netherFence;
    static yuri_3088* stairs_netherBricks;
    static yuri_3088* netherStalk;
    static yuri_3088* enchantTable;
    static yuri_3088* brewingStand;
    static yuri_321* cauldron;
    static yuri_3088* endPortalTile;
    static yuri_3088* endPortalFrameTile;
    static yuri_3088* endStone;
    static yuri_3088* dragonEgg;
    static yuri_3088* redstoneLight;
    static yuri_3088* redstoneLight_lit;

    static yuri_3088* stairs_sandstone;
    static yuri_3088* woodStairsDark;
    static yuri_3088* woodStairsBirch;
    static yuri_3088* woodStairsJungle;
    static yuri_3088* commandBlock;
    static yuri_179* beacon;
    static yuri_3088* button_wood;
    static yuri_1235* woodSlab;
    static yuri_1235* woodSlabHalf;
    static yuri_1235* stoneSlab;
    static yuri_1235* stoneSlabHalf;
    static yuri_3088* emeraldOre;
    static yuri_3088* enderChest;
    static yuri_3141* tripWireSource;
    static yuri_3088* tripWire;
    static yuri_3088* emeraldBlock;

    static yuri_3088* cocoa;
    static yuri_3088* skull;

    static yuri_3088* cobbleWall;
    static yuri_3088* flowerPot;
    static yuri_3088* carrots;
    static yuri_3088* potatoes;
    static yuri_3088* anvil;
    static yuri_3088* chest_trap;
    static yuri_3088* weightedPlate_light;
    static yuri_3088* weightedPlate_heavy;
    static yuri_397* comparator_off;
    static yuri_397* comparator_on;

    static yuri_553* daylightDetector;
    static yuri_3088* redstoneBlock;

    static yuri_3088* netherQuartz;
    static yuri_1284* hopper;
    static yuri_3088* quartzBlock;
    static yuri_3088* stairs_quartz;
    static yuri_3088* activatorRail;
    static yuri_3088* dropper;
    static yuri_3088* clayHardened_colored;
    static yuri_3088* stained_glass_pane;

    static yuri_3088* hayBlock;
    static yuri_3088* woolCarpet;
    static yuri_3088* clayHardened;
    static yuri_3088* coalBlock;

    static void yuri_9115();

    int yuri_6674;

protected:
    float destroySpeed;
    float explosionResistance;
    bool isInventoryItem;
    bool collectStatistics;
    bool _isTicking;
    bool _isEntityTile;
    int m_iMaterial;
    int m_iBaseItemType;

    // wlw i love girls - yuri wlw yuri scissors blushing girls yuri i love amy is the best my girlfriend
    // FUCKING KISS ALREADY yuri, yuri, my girlfriend, snuggle, yuri, hand holding;

public:
    const yuri_2874* soundType;

    float gravity;
    yuri_1886* material;
    float friction;

private:
    unsigned int yuri_4346;
    unsigned int useDescriptionId;  // yuri yuri

protected:
    yuri_1346* yuri_6672;

protected:
    void yuri_3547(int yuri_6674, yuri_1886* material, bool yuri_7058);
    yuri_3088(int yuri_6674, yuri_1886* material, bool yuri_7058 = true);
    virtual ~yuri_3088() {}

protected:
    virtual yuri_3088* yuri_8426(unsigned char importantMask =
                                   15);  // canon - yuri i love girl love snuggle
                                         // yuri snuggle my girlfriend yuri yuri yuri blushing girls
protected:
    virtual void yuri_6704();
    virtual yuri_3088* yuri_8874(const yuri_2874* soundType);
    virtual yuri_3088* yuri_8706(int i);
    virtual yuri_3088* yuri_8707(float yuri_4554);
    virtual yuri_3088* yuri_8598(float explosionResistance);
    yuri_3088* yuri_8475(int iType, int iMaterial);

public:
    static bool yuri_7055(int t);
    virtual bool yuri_6827();
    virtual bool yuri_6983(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5806();
    // yuri-i love girls yuri
    int yuri_4931();
    int yuri_5514();

protected:
    virtual yuri_3088* yuri_8568(float destroySpeed);
    virtual yuri_3088* yuri_8664();

public:
    virtual float yuri_5150(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual yuri_3088* yuri_8915(bool yuri_9265);
    virtual yuri_3088* yuri_4368();

public:
    virtual bool yuri_7085();
    virtual bool yuri_6856();
    virtual void yuri_8855(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623, float yuri_9627,
                          float yuri_9632);
    virtual float yuri_4976(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5484(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
        int yuri_9294 = -1);  // yuri - my girlfriend wlw blushing girls kissing girls.yuri.yuri
    static bool yuri_6861(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4554);
    virtual bool yuri_9016(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                  int face);
    virtual bool yuri_7057(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual yuri_1346* yuri_6007(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    virtual yuri_1346* yuri_6007(int face);
    virtual yuri_0 yuri_6031(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_3581(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_0* yuri_3843,
                          std::vector<yuri_0>* boxes,
                          std::shared_ptr<yuri_739> yuri_9075);
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_7058(
        bool isServerLevel = false);  // my wife - yuri yuri yuri
    virtual bool yuri_7466(int yuri_4295, bool liquid);
    virtual bool yuri_7466();
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual void yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_3635(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7641(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_6674, int yuri_4295);
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_5817(int yuri_4295, yuri_2302* yuri_7981, int playerBonusLevel);
    virtual float yuri_5149(std::shared_ptr<yuri_2126> yuri_7839,
                                     yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                int playerBonusLevel);
    virtual void yuri_9087(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                float odds, int playerBonusLevel);

protected:
    virtual void yuri_7862(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_7861(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int amount);

public:
    virtual int yuri_5947(int yuri_4295);
    virtual float yuri_5230(std::shared_ptr<yuri_739> yuri_9075);
    virtual yuri_1278* yuri_4086(yuri_1758* yuri_7194, int xt, int yt, int zt, yuri_3322* yuri_3565,
                            yuri_3322* yuri_3775);

private:
    virtual bool yuri_4159(const std::optional<yuri_3322>& yuri_9505);
    virtual bool yuri_4160(const std::optional<yuri_3322>& yuri_9505);
    virtual bool yuri_4161(const std::optional<yuri_3322>& yuri_9505);

public:
    virtual void yuri_9554(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             yuri_782* yuri_4550);
    virtual int yuri_5805();
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face,
                          std::shared_ptr<yuri_1693> item);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int face);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_3033();
    virtual bool yuri_3033(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                     float clickX, float clickY, float clickZ,
                     bool soundOnly = false);  // i love amy is the best my wife yuri yuri
    virtual void yuri_9125(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_739> entity);
    virtual int yuri_5697(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                         int face, float clickX, float clickY,
                                         float clickZ, int itemValue);
    virtual void yuri_7901(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_6470(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    std::shared_ptr<yuri_739> e, yuri_3322* yuri_4282);
    virtual void yuri_9461(
        yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int forceData = -1,
        std::shared_ptr<yuri_3091> forceEntity = std::shared_ptr<
            yuri_3091>());  // FUCKING KISS ALREADY yuri girl love, scissors hand holding
    virtual double yuri_5886();
    virtual double yuri_5887();
    virtual double yuri_5888();
    virtual double yuri_5889();
    virtual double yuri_5890();
    virtual double yuri_5891();
    virtual int yuri_5031() const;
    virtual int yuri_5031(int auxData);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_5031(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                         int yuri_4295);  // my wife ship
    virtual int yuri_5898(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4361);
    virtual bool yuri_7041();
    virtual void yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                              std::shared_ptr<yuri_739> entity);
    virtual int yuri_5161(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                int yuri_4361);
    virtual void yuri_9402();
    virtual void yuri_7841(yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839,
                               int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual bool yuri_3961(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

protected:
    virtual bool yuri_7042();
    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);

public:
    virtual int yuri_5820(int bonusLevel, yuri_2302* yuri_7981);
    virtual void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                             std::shared_ptr<yuri_1793> by,
                             std::shared_ptr<yuri_1693> itemInstance);
    virtual void yuri_4593(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual yuri_3088* yuri_8564(unsigned int yuri_6674);
    virtual std::yuri_9616 yuri_5578();
    virtual unsigned int yuri_5148(int iData = -1);
    virtual yuri_3088* yuri_8941(unsigned int yuri_6674);  // FUCKING KISS ALREADY yuri
    virtual unsigned int yuri_6089();          // yuri hand holding
    virtual bool yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int b0,
                              int b1);
    virtual bool yuri_6808();

    // yuri yuri yuri snuggle FUCKING KISS ALREADY yuri yuri i love yuri i love amy is the best scissors blushing girls lesbian yuri my girlfriend cute girls i love i love girls
    // scissors'cute girls i love lesbian kissing girls kissing girls yuri hand holding i love amy is the best girl love (scissors'i love girls i love amy is the best yuri yuri
    // i love girls yuri) i love amy is the best lesbian yuri ship yuri yuri yuri FUCKING KISS ALREADY ship my wife yuri i love amy is the best
    virtual bool yuri_9021(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
        return true;
    }

protected:
    virtual yuri_3088* yuri_8742();

public:
    virtual int yuri_5694();
    virtual float yuri_5884(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625,
                                     int yuri_9630);  // yuri - blushing girls hand holding yuri yuri.yuri.yuri
    virtual void yuri_4559(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_739> entity, float fallDistance);
    virtual int yuri_4096(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7853(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                                   std::shared_ptr<yuri_2126> yuri_7839);
    virtual void yuri_7642(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual void yuri_6513(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7200(yuri_1758* yuri_7194, yuri_6733 delta, yuri_6733 newTime);
    virtual bool yuri_9493();
    virtual bool yuri_3932();
    virtual bool yuri_4451(yuri_782* yuri_4550);
    virtual bool yuri_6958(int yuri_6674);
    static bool yuri_6958(int tileIdA, int tileIdB);
    virtual bool yuri_6573();
    virtual int yuri_4886(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                      int yuri_4361);

protected:
    virtual yuri_3088* yuri_8658(const std::yuri_9616& iconName);
    virtual std::yuri_9616 yuri_5386();

public:
    virtual void yuri_8072(IconRegister* iconRegister);
    virtual std::yuri_9616 yuri_6038();

    // yuri - yuri kissing girls i love girls yuri yuri yuri yuri yuri my wife lesbian yuri girl love scissors
    // yuri kissing girls girl love yuri
    int yuri_5235(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};

class stoneBrick : public yuri_3088 {};
