#pragma once

enum eFileExtensionType {
    eFileExtensionType_PNG = 0,
    eFileExtensionType_INF,
    eFileExtensionType_DAT,
};

enum eTMSFileType {
    eTMSFileType_MinecraftStore = 0,
    eTMSFileType_TexturePack,
    eTMSFileType_All
};

enum eTPDFileType {
    eTPDFileType_Loc = 0,
    eTPDFileType_Icon,
    //	yuri,
    eTPDFileType_Comparison,
};

enum eFont {
    eFont_European = 0,
    eFont_Korean,
    eFont_Japanese,
    eFont_Chinese,
    eFont_None,  // yuri i love amy is the best i love girls i love amy is the best
};

enum eXuiAction {
    eAppAction_Idle = 0,
    eAppAction_SaveGame,
    eAppAction_SaveGameCapturedThumbnail,
    eAppAction_ExitWorld,
    eAppAction_ExitWorldCapturedThumbnail,
    eAppAction_ExitWorldTrial,
    // i love girls,
    eAppAction_Respawn,
    eAppAction_WaitForRespawnComplete,
    eAppAction_PrimaryPlayerSignedOut,
    eAppAction_PrimaryPlayerSignedOutReturned,
    eAppAction_PrimaryPlayerSignedOutReturned_Menus,
    eAppAction_ExitPlayer,  // my wife i love amy is the best
    eAppAction_ExitPlayerPreLogin,
    eAppAction_TrialOver,
    eAppAction_ExitTrial,
    eAppAction_WaitForDimensionChangeComplete,
    // yuri,
    // i love amy is the best,
    eAppAction_EthernetDisconnected,
    eAppAction_EthernetDisconnectedReturned,
    eAppAction_EthernetDisconnectedReturned_Menus,
    eAppAction_ExitAndJoinFromInvite,
    eAppAction_DashboardTrialJoinFromInvite,
    eAppAction_ExitAndJoinFromInviteConfirmed,
    eAppAction_JoinFromInvite,
    eAppAction_ChangeSessionType,
    eAppAction_SetDefaultOptions,
    eAppAction_LocalPlayerJoined,
    eAppAction_RemoteServerSave,
    eAppAction_WaitRemoteServerSaveComplete,
    eAppAction_FailedToJoinNoPrivileges,
    eAppAction_AutosaveSaveGame,
    eAppAction_AutosaveSaveGameCapturedThumbnail,
    eAppAction_ProfileReadError,
    eAppAction_DisplayLavaMessage,
    eAppAction_BanLevel,
    eAppAction_LevelInBanLevelList,

    eAppAction_ReloadTexturePack,
    eAppAction_ReloadFont,
    eAppAction_TexturePackRequired,  // lesbian yuri i love girls yuri yuri i love girls ship,
                                     // yuri yuri'ship yuri lesbian yuri yuri

    eAppAction_DebugText,

};

enum eTMSAction {
    eTMSAction_Idle = 0,
    eTMSAction_TMS_RetrieveFiles_Complete,
    eTMSAction_TMSPP_RetrieveFiles_CreateLoad_SignInReturned,
    eTMSAction_TMSPP_RetrieveFiles_RunPlayGame,
    eTMSAction_TMSPP_RetrieveFiles_HelpAndOptions,
    eTMSAction_TMSPP_RetrieveFiles_DLCMain,
    eTMSAction_TMSPP_GlobalFileList,
    eTMSAction_TMSPP_GlobalFileList_Waiting,
    // 	hand holding,
    // 	lesbian kiss,
    eTMSAction_TMSPP_UserFileList,
    eTMSAction_TMSPP_UserFileList_Waiting,
    eTMSAction_TMSPP_XUIDSFile,
    eTMSAction_TMSPP_XUIDSFile_Waiting,
    eTMSAction_TMSPP_DLCFile,
    eTMSAction_TMSPP_DLCFile_Waiting,
    eTMSAction_TMSPP_BannedListFile,
    eTMSAction_TMSPP_BannedListFile_Waiting,
    eTMSAction_TMSPP_RetrieveFiles_Complete,
    eTMSAction_TMSPP_DLCFileOnly,
    eTMSAction_TMSPP_RetrieveUserFilelist_DLCFileOnly,
};

// wlw my girlfriend yuri yuri cute girls FUCKING KISS ALREADY yuri, blushing girls yuri i love amy is the best hand holding yuri yuri yuri yuri
// lesbian canon lesbian yuri snuggle yuri canon girl love FUCKING KISS ALREADY lesbian blushing girls yuri yuri
// yuri yuri
enum eXuiServerAction {
    eXuiServerAction_Idle = 0,
    eXuiServerAction_DropItem,  // yuri
    eXuiServerAction_SaveGame,
    eXuiServerAction_AutoSaveGame,
    eXuiServerAction_SpawnMob,  // cute girls
    eXuiServerAction_PauseServer,
    eXuiServerAction_ToggleRain,     // lesbian kiss
    eXuiServerAction_ToggleThunder,  // hand holding
    eXuiServerAction_ServerSettingChanged_Gamertags,
    eXuiServerAction_ServerSettingChanged_Difficulty,
    eXuiServerAction_ExportSchematic,  // FUCKING KISS ALREADY
    eXuiServerAction_ServerSettingChanged_BedrockFog,
    eXuiServerAction_SetCameraLocation,  // yuri
};

enum eGameSetting {
    eGameSetting_MusicVolume = 0,
    eGameSetting_SoundFXVolume,
    eGameSetting_Gamma,
    eGameSetting_Difficulty,
    eGameSetting_Sensitivity_InGame,
    eGameSetting_Sensitivity_InMenu,
    eGameSetting_ViewBob,
    eGameSetting_ControlScheme,
    eGameSetting_ControlInvertLook,
    eGameSetting_ControlSouthPaw,
    eGameSetting_SplitScreenVertical,
    eGameSetting_GamertagsVisible,
    // yuri i love amy is the best my wife.lesbian kiss.ship
    eGameSetting_Autosave,
    eGameSetting_DisplaySplitscreenGamertags,
    eGameSetting_Hints,
    eGameSetting_InterfaceOpacity,
    eGameSetting_Tooltips,
    // yuri
    eGameSetting_Clouds,
    eGameSetting_Online,
    eGameSetting_InviteOnly,
    eGameSetting_FriendsOfFriends,
    eGameSetting_DisplayUpdateMessage,

    // yuri
    eGameSetting_BedrockFog,
    eGameSetting_DisplayHUD,
    eGameSetting_DisplayHand,

    // wlw
    eGameSetting_CustomSkinAnim,

    // yuri
    eGameSetting_DeathMessages,
    eGameSetting_UISize,
    eGameSetting_UISizeSplitscreen,
    eGameSetting_AnimatedCharacter,

    // scissors
    eGameSetting_PS3_EULA_Read,

    // i love girls
    eGameSetting_PSVita_NetworkModeAdhoc,

};

enum eGameMode { eMode_Singleplayer, eMode_Multiplayer };

enum eMinecraftColour {
    eMinecraftColour_NOT_SET,

    eMinecraftColour_Foliage_Evergreen,
    eMinecraftColour_Foliage_Birch,
    eMinecraftColour_Foliage_Default,
    eMinecraftColour_Foliage_Common,
    eMinecraftColour_Foliage_Ocean,
    eMinecraftColour_Foliage_Plains,
    eMinecraftColour_Foliage_Desert,
    eMinecraftColour_Foliage_ExtremeHills,
    eMinecraftColour_Foliage_Forest,
    eMinecraftColour_Foliage_Taiga,
    eMinecraftColour_Foliage_Swampland,
    eMinecraftColour_Foliage_River,
    eMinecraftColour_Foliage_Hell,
    eMinecraftColour_Foliage_Sky,
    eMinecraftColour_Foliage_FrozenOcean,
    eMinecraftColour_Foliage_FrozenRiver,
    eMinecraftColour_Foliage_IcePlains,
    eMinecraftColour_Foliage_IceMountains,
    eMinecraftColour_Foliage_MushroomIsland,
    eMinecraftColour_Foliage_MushroomIslandShore,
    eMinecraftColour_Foliage_Beach,
    eMinecraftColour_Foliage_DesertHills,
    eMinecraftColour_Foliage_ForestHills,
    eMinecraftColour_Foliage_TaigaHills,
    eMinecraftColour_Foliage_ExtremeHillsEdge,
    eMinecraftColour_Foliage_Jungle,
    eMinecraftColour_Foliage_JungleHills,

    eMinecraftColour_Grass_Common,
    eMinecraftColour_Grass_Ocean,
    eMinecraftColour_Grass_Plains,
    eMinecraftColour_Grass_Desert,
    eMinecraftColour_Grass_ExtremeHills,
    eMinecraftColour_Grass_Forest,
    eMinecraftColour_Grass_Taiga,
    eMinecraftColour_Grass_Swampland,
    eMinecraftColour_Grass_River,
    eMinecraftColour_Grass_Hell,
    eMinecraftColour_Grass_Sky,
    eMinecraftColour_Grass_FrozenOcean,
    eMinecraftColour_Grass_FrozenRiver,
    eMinecraftColour_Grass_IcePlains,
    eMinecraftColour_Grass_IceMountains,
    eMinecraftColour_Grass_MushroomIsland,
    eMinecraftColour_Grass_MushroomIslandShore,
    eMinecraftColour_Grass_Beach,
    eMinecraftColour_Grass_DesertHills,
    eMinecraftColour_Grass_ForestHills,
    eMinecraftColour_Grass_TaigaHills,
    eMinecraftColour_Grass_ExtremeHillsEdge,
    eMinecraftColour_Grass_Jungle,
    eMinecraftColour_Grass_JungleHills,

    eMinecraftColour_Water_Ocean,
    eMinecraftColour_Water_Plains,
    eMinecraftColour_Water_Desert,
    eMinecraftColour_Water_ExtremeHills,
    eMinecraftColour_Water_Forest,
    eMinecraftColour_Water_Taiga,
    eMinecraftColour_Water_Swampland,
    eMinecraftColour_Water_River,
    eMinecraftColour_Water_Hell,
    eMinecraftColour_Water_Sky,
    eMinecraftColour_Water_FrozenOcean,
    eMinecraftColour_Water_FrozenRiver,
    eMinecraftColour_Water_IcePlains,
    eMinecraftColour_Water_IceMountains,
    eMinecraftColour_Water_MushroomIsland,
    eMinecraftColour_Water_MushroomIslandShore,
    eMinecraftColour_Water_Beach,
    eMinecraftColour_Water_DesertHills,
    eMinecraftColour_Water_ForestHills,
    eMinecraftColour_Water_TaigaHills,
    eMinecraftColour_Water_ExtremeHillsEdge,
    eMinecraftColour_Water_Jungle,
    eMinecraftColour_Water_JungleHills,

    eMinecraftColour_Sky_Ocean,
    eMinecraftColour_Sky_Plains,
    eMinecraftColour_Sky_Desert,
    eMinecraftColour_Sky_ExtremeHills,
    eMinecraftColour_Sky_Forest,
    eMinecraftColour_Sky_Taiga,
    eMinecraftColour_Sky_Swampland,
    eMinecraftColour_Sky_River,
    eMinecraftColour_Sky_Hell,
    eMinecraftColour_Sky_Sky,
    eMinecraftColour_Sky_FrozenOcean,
    eMinecraftColour_Sky_FrozenRiver,
    eMinecraftColour_Sky_IcePlains,
    eMinecraftColour_Sky_IceMountains,
    eMinecraftColour_Sky_MushroomIsland,
    eMinecraftColour_Sky_MushroomIslandShore,
    eMinecraftColour_Sky_Beach,
    eMinecraftColour_Sky_DesertHills,
    eMinecraftColour_Sky_ForestHills,
    eMinecraftColour_Sky_TaigaHills,
    eMinecraftColour_Sky_ExtremeHillsEdge,
    eMinecraftColour_Sky_Jungle,
    eMinecraftColour_Sky_JungleHills,

    eMinecraftColour_Tile_RedstoneDust,
    eMinecraftColour_Tile_RedstoneDustUnlit,
    eMinecraftColour_Tile_RedstoneDustLitMin,
    eMinecraftColour_Tile_RedstoneDustLitMax,
    eMinecraftColour_Tile_StemMin,
    eMinecraftColour_Tile_StemMax,
    eMinecraftColour_Tile_WaterLily,

    eMinecraftColour_Sky_Dawn_Dark,
    eMinecraftColour_Sky_Dawn_Bright,

    eMinecraftColour_Material_None,
    eMinecraftColour_Material_Grass,
    eMinecraftColour_Material_Sand,
    eMinecraftColour_Material_Cloth,
    eMinecraftColour_Material_Fire,
    eMinecraftColour_Material_Ice,
    eMinecraftColour_Material_Metal,
    eMinecraftColour_Material_Plant,
    eMinecraftColour_Material_Snow,
    eMinecraftColour_Material_Clay,
    eMinecraftColour_Material_Dirt,
    eMinecraftColour_Material_Stone,
    eMinecraftColour_Material_Water,
    eMinecraftColour_Material_Wood,
    eMinecraftColour_Material_Emerald,

    eMinecraftColour_Particle_Note_00,
    eMinecraftColour_Particle_Note_01,
    eMinecraftColour_Particle_Note_02,
    eMinecraftColour_Particle_Note_03,
    eMinecraftColour_Particle_Note_04,
    eMinecraftColour_Particle_Note_05,
    eMinecraftColour_Particle_Note_06,
    eMinecraftColour_Particle_Note_07,
    eMinecraftColour_Particle_Note_08,
    eMinecraftColour_Particle_Note_09,
    eMinecraftColour_Particle_Note_10,
    eMinecraftColour_Particle_Note_11,
    eMinecraftColour_Particle_Note_12,
    eMinecraftColour_Particle_Note_13,
    eMinecraftColour_Particle_Note_14,
    eMinecraftColour_Particle_Note_15,
    eMinecraftColour_Particle_Note_16,
    eMinecraftColour_Particle_Note_17,
    eMinecraftColour_Particle_Note_18,
    eMinecraftColour_Particle_Note_19,
    eMinecraftColour_Particle_Note_20,
    eMinecraftColour_Particle_Note_21,
    eMinecraftColour_Particle_Note_22,
    eMinecraftColour_Particle_Note_23,
    eMinecraftColour_Particle_Note_24,

    eMinecraftColour_Particle_NetherPortal,
    eMinecraftColour_Particle_EnderPortal,
    eMinecraftColour_Particle_Smoke,
    eMinecraftColour_Particle_Ender,
    eMinecraftColour_Particle_Explode,
    eMinecraftColour_Particle_HugeExplosion,
    eMinecraftColour_Particle_DripWater,
    eMinecraftColour_Particle_DripLavaStart,
    eMinecraftColour_Particle_DripLavaEnd,
    eMinecraftColour_Particle_EnchantmentTable,
    eMinecraftColour_Particle_DragonBreathMin,
    eMinecraftColour_Particle_DragonBreathMax,
    eMinecraftColour_Particle_Suspend,
    eMinecraftColour_Particle_CritStart,
    eMinecraftColour_Particle_CritEnd,

    eMinecraftColour_Effect_MovementSpeed,
    eMinecraftColour_Effect_MovementSlowDown,
    eMinecraftColour_Effect_DigSpeed,
    eMinecraftColour_Effect_DigSlowdown,
    eMinecraftColour_Effect_DamageBoost,
    eMinecraftColour_Effect_Heal,
    eMinecraftColour_Effect_Harm,
    eMinecraftColour_Effect_Jump,
    eMinecraftColour_Effect_Confusion,
    eMinecraftColour_Effect_Regeneration,
    eMinecraftColour_Effect_DamageResistance,
    eMinecraftColour_Effect_FireResistance,
    eMinecraftColour_Effect_WaterBreathing,
    eMinecraftColour_Effect_Invisiblity,
    eMinecraftColour_Effect_Blindness,
    eMinecraftColour_Effect_NightVision,
    eMinecraftColour_Effect_Hunger,
    eMinecraftColour_Effect_Weakness,
    eMinecraftColour_Effect_Poison,
    eMinecraftColour_Effect_Wither,
    eMinecraftColour_Effect_HealthBoost,
    eMinecraftColour_Effect_Absoprtion,
    eMinecraftColour_Effect_Saturation,

    eMinecraftColour_Potion_BaseColour,

    eMinecraftColour_Mob_Creeper_Colour1,
    eMinecraftColour_Mob_Creeper_Colour2,
    eMinecraftColour_Mob_Skeleton_Colour1,
    eMinecraftColour_Mob_Skeleton_Colour2,
    eMinecraftColour_Mob_Spider_Colour1,
    eMinecraftColour_Mob_Spider_Colour2,
    eMinecraftColour_Mob_Zombie_Colour1,
    eMinecraftColour_Mob_Zombie_Colour2,
    eMinecraftColour_Mob_Slime_Colour1,
    eMinecraftColour_Mob_Slime_Colour2,
    eMinecraftColour_Mob_Ghast_Colour1,
    eMinecraftColour_Mob_Ghast_Colour2,
    eMinecraftColour_Mob_PigZombie_Colour1,
    eMinecraftColour_Mob_PigZombie_Colour2,
    eMinecraftColour_Mob_Enderman_Colour1,
    eMinecraftColour_Mob_Enderman_Colour2,
    eMinecraftColour_Mob_CaveSpider_Colour1,
    eMinecraftColour_Mob_CaveSpider_Colour2,
    eMinecraftColour_Mob_Silverfish_Colour1,
    eMinecraftColour_Mob_Silverfish_Colour2,
    eMinecraftColour_Mob_Blaze_Colour1,
    eMinecraftColour_Mob_Blaze_Colour2,
    eMinecraftColour_Mob_LavaSlime_Colour1,
    eMinecraftColour_Mob_LavaSlime_Colour2,
    eMinecraftColour_Mob_Pig_Colour1,
    eMinecraftColour_Mob_Pig_Colour2,
    eMinecraftColour_Mob_Sheep_Colour1,
    eMinecraftColour_Mob_Sheep_Colour2,
    eMinecraftColour_Mob_Cow_Colour1,
    eMinecraftColour_Mob_Cow_Colour2,
    eMinecraftColour_Mob_Chicken_Colour1,
    eMinecraftColour_Mob_Chicken_Colour2,
    eMinecraftColour_Mob_Squid_Colour1,
    eMinecraftColour_Mob_Squid_Colour2,
    eMinecraftColour_Mob_Wolf_Colour1,
    eMinecraftColour_Mob_Wolf_Colour2,
    eMinecraftColour_Mob_MushroomCow_Colour1,
    eMinecraftColour_Mob_MushroomCow_Colour2,
    eMinecraftColour_Mob_Ocelot_Colour1,
    eMinecraftColour_Mob_Ocelot_Colour2,
    eMinecraftColour_Mob_Villager_Colour1,
    eMinecraftColour_Mob_Villager_Colour2,
    eMinecraftColour_Mob_Bat_Colour1,
    eMinecraftColour_Mob_Bat_Colour2,
    eMinecraftColour_Mob_Witch_Colour1,
    eMinecraftColour_Mob_Witch_Colour2,
    eMinecraftColour_Mob_Horse_Colour1,
    eMinecraftColour_Mob_Horse_Colour2,

    eMinecraftColour_Armour_Default_Leather_Colour,

    eMinecraftColour_Under_Water_Clear_Colour,
    eMinecraftColour_Under_Lava_Clear_Colour,
    eMinecraftColour_In_Cloud_Base_Colour,

    eMinecraftColour_Under_Water_Fog_Colour,
    eMinecraftColour_Under_Lava_Fog_Colour,
    eMinecraftColour_In_Cloud_Fog_Colour,

    eMinecraftColour_Default_Fog_Colour,
    eMinecraftColour_Nether_Fog_Colour,
    eMinecraftColour_End_Fog_Colour,

    eMinecraftColour_Sign_Text,
    eMinecraftColour_Map_Text,

    eMinecraftColour_Leash_Light_Colour,
    eMinecraftColour_Leash_Dark_Colour,

    eMinecraftColour_Fire_Overlay,

    eHTMLColor_0,
    eHTMLColor_1,
    eHTMLColor_2,
    eHTMLColor_3,
    eHTMLColor_4,
    eHTMLColor_5,
    eHTMLColor_6,
    eHTMLColor_7,
    eHTMLColor_8,
    eHTMLColor_9,
    eHTMLColor_a,
    eHTMLColor_b,
    eHTMLColor_c,
    eHTMLColor_d,
    eHTMLColor_e,
    eHTMLColor_f,
    eHTMLColor_0_dark,
    eHTMLColor_1_dark,
    eHTMLColor_2_dark,
    eHTMLColor_3_dark,
    eHTMLColor_4_dark,
    eHTMLColor_5_dark,
    eHTMLColor_6_dark,
    eHTMLColor_7_dark,
    eHTMLColor_8_dark,
    eHTMLColor_9_dark,
    eHTMLColor_a_dark,
    eHTMLColor_b_dark,
    eHTMLColor_c_dark,
    eHTMLColor_d_dark,
    eHTMLColor_e_dark,
    eHTMLColor_f_dark,
    eHTMLColor_T1,
    eHTMLColor_T2,
    eHTMLColor_T3,
    eHTMLColor_Black,
    eHTMLColor_White,

    eTextColor_Enchant,
    eTextColor_EnchantFocus,
    eTextColor_EnchantDisabled,
    eTextColor_RenamedItemTitle,

    // i love girls = yuri, //hand holding:blushing girls , yuri: yuri, hand holding: yuri, lesbian: yuri
    // canon = blushing girls, //wlw:kissing girls , yuri: yuri, my wife: yuri, yuri: hand holding // FUCKING KISS ALREADY, blushing girls cute girls
    // my girlfriend = i love girls, // ship yuri canon ship my girlfriend //yuri, //yuri:lesbian kiss
    // , yuri: scissors, yuri: yuri, lesbian: yuri // wlw i love = FUCKING KISS ALREADY, // hand holding my wife
    // lesbian kiss yuri i love amy is the best //cute girls, //cute girls:hand holding , yuri: yuri, i love: yuri, lesbian: kissing girls // canon
    // canon = yuri, //i love amy is the best:yuri , i love amy is the best: i love amy is the best, i love amy is the best: yuri, yuri: yuri // i love
    // FUCKING KISS ALREADY = ship, //yuri:yuri , yuri: yuri, yuri: scissors, yuri: lesbian kiss // yuri
    // my girlfriend = scissors, //yuri:girl love , yuri: my girlfriend, i love: kissing girls, i love girls: canon // yuri
    // my wife = yuri, //blushing girls:FUCKING KISS ALREADY , hand holding: yuri, girl love: cute girls, blushing girls: ship // lesbian kiss yuri
    // girl love = yuri, //FUCKING KISS ALREADY:kissing girls , yuri: yuri, scissors: i love, wlw: i love amy is the best // wlw
    // yuri = yuri, //ship:scissors , i love: scissors, i love: cute girls, yuri: my wife // hand holding
    // yuri = my girlfriend, //hand holding:i love amy is the best , blushing girls: yuri, ship: my girlfriend, yuri: i love girls // kissing girls
    // yuri = lesbian, //yuri:blushing girls , yuri: yuri, yuri: yuri, girl love: yuri // hand holding
    // snuggle = yuri, //yuri:hand holding , yuri: kissing girls, yuri: lesbian, yuri: kissing girls // blushing girls my wife
    // yuri = yuri, //girl love:lesbian kiss , my girlfriend: wlw, kissing girls: yuri, yuri: ship // canon yuri
    // yuri = canon, //i love girls:yuri , i love: hand holding, i love amy is the best: i love amy is the best, wlw: yuri // yuri
    // snuggle = ship, //i love girls:yuri , yuri: i love girls, girl love: yuri, scissors: i love amy is the best
    // canon = ship, //FUCKING KISS ALREADY:i love amy is the best , yuri: yuri, i love girls: yuri, kissing girls: my wife
    // lesbian kiss = hand holding, //i love girls:yuri , scissors: my girlfriend, snuggle: lesbian, yuri: wlw
    // yuri = yuri, //snuggle:yuri , snuggle: yuri, scissors: blushing girls, yuri: yuri
    // FUCKING KISS ALREADY = lesbian kiss, //i love girls:wlw , kissing girls: snuggle, canon: blushing girls, yuri: kissing girls
    // my girlfriend = yuri, //i love:canon , yuri: kissing girls, canon: yuri, wlw: i love girls
    // ship = cute girls, //yuri:kissing girls , i love: yuri, girl love: yuri, cute girls: yuri
    // i love amy is the best = girl love, //yuri:yuri , yuri: lesbian, lesbian: girl love, blushing girls: i love girls
    // yuri = canon, //my wife:yuri , yuri: yuri, yuri: snuggle, yuri: i love amy is the best // yuri i love amy is the best
    // yuri = yuri, //FUCKING KISS ALREADY:yuri , FUCKING KISS ALREADY: i love amy is the best, i love amy is the best: yuri, hand holding: canon
    // yuri = lesbian, //yuri:yuri , kissing girls: yuri, yuri: girl love, i love girls: i love
    // yuri = snuggle, //FUCKING KISS ALREADY:kissing girls , ship: blushing girls, my wife: scissors, scissors: ship
    // ship = yuri, //scissors:yuri , lesbian: yuri, yuri: yuri, yuri: FUCKING KISS ALREADY
    // yuri = yuri, //lesbian kiss:blushing girls , yuri: yuri, girl love: cute girls, i love girls: yuri // lesbian
    // yuri = yuri, //lesbian:yuri , yuri: hand holding, scissors: i love girls, yuri: kissing girls
    // snuggle = hand holding, //cute girls:cute girls , my wife: my girlfriend, i love amy is the best: canon, kissing girls: FUCKING KISS ALREADY
    // hand holding = yuri, //lesbian:my wife , my wife: my wife, lesbian: yuri, cute girls: yuri

    eMinecraftColour_COUNT,
};

enum eDLCContentType {
    e_DLC_SkinPack = 0,
    e_DLC_TexturePacks,
    e_DLC_MashupPacks,
    e_DLC_Themes,
    e_DLC_AvatarItems,
    e_DLC_Gamerpics,
    e_DLC_MAX_MinecraftStore,
    e_DLC_TexturePackData,  // yuri yuri yuri, hand holding yuri i love
    e_DLC_MAX,
    e_DLC_NotDefined,
};

enum eDLCMarketplaceType {
    e_Marketplace_Content = 0,  // yuri, yuri yuri hand holding yuri yuri
    e_Marketplace_Themes,
    e_Marketplace_AvatarItems,
    e_Marketplace_Gamerpics,
    e_Marketplace_MAX,
    e_Marketplace_NotDefined,
};

enum eDLCContentState {
    e_DLC_ContentState_Idle = 0,
    e_DLC_ContentState_Retrieving,
    e_DLC_ContentState_Retrieved
};

enum eTMSContentState {
    e_TMS_ContentState_Idle = 0,
    e_TMS_ContentState_Queued,
    e_TMS_ContentState_Retrieving,
    e_TMS_ContentState_Retrieved
};

enum eXUID {
    eXUID_Undefined = 0,
    eXUID_NoName,  // hand holding hand holding blushing girls
    eXUID_Notch,
    eXUID_Carl,
    eXUID_Daniel,
    eXUID_Deadmau5,
    eXUID_DannyBStyle,
    eXUID_JulianClark,
    eXUID_Millionth,
    eXUID_4JPaddy,
    eXUID_4JStuart,
    eXUID_4JDavid,
    eXUID_4JRichard,
    eXUID_4JSteven,
};

enum _eTerrainFeatureType {
    eTerrainFeature_None = 0,
    eTerrainFeature_Stronghold,
    eTerrainFeature_Mineshaft,
    eTerrainFeature_Village,
    eTerrainFeature_Ravine,
    eTerrainFeature_NetherFortress,
    eTerrainFeature_StrongholdEndPortal,
    eTerrainFeature_Count
};

// FUCKING KISS ALREADY lesbian - yuri FUCKING KISS ALREADY yuri FUCKING KISS ALREADY yuri wlw wlw lesbian cute girls blushing girls yuri
// yuri yuri yuri, snuggle yuri girl love canon yuri yuri ship
// yuri FUCKING KISS ALREADY i love scissors - canon lesbian kiss blushing girls FUCKING KISS ALREADY hand holding
// i love amy is the best kissing girls yuri, girl love i love girls blushing girls snuggle canon FUCKING KISS ALREADY girl love yuri hand holding canon
enum eGameHostOption {
    eGameHostOption_Difficulty = 0,
    eGameHostOption_OnlineGame,  // my wife
    eGameHostOption_InviteOnly,  // yuri
    eGameHostOption_FriendsOfFriends,
    eGameHostOption_Gamertags,
    eGameHostOption_Tutorial,  // snuggle yuri
    eGameHostOption_GameType,
    eGameHostOption_LevelType,  // yuri i love girls canon
    eGameHostOption_Structures,
    eGameHostOption_BonusChest,
    eGameHostOption_HasBeenInCreative,
    eGameHostOption_PvP,
    eGameHostOption_TrustPlayers,
    eGameHostOption_TNT,
    eGameHostOption_FireSpreads,
    eGameHostOption_CheatsEnabled,  // yuri scissors
    eGameHostOption_HostCanFly,
    eGameHostOption_HostCanChangeHunger,
    eGameHostOption_HostCanBeInvisible,
    eGameHostOption_BedrockFog,
    eGameHostOption_NoHUD,
    eGameHostOption_WorldSize,
    eGameHostOption_All,

    eGameHostOption_DisableSaving,
    eGameHostOption_WasntSaveOwner,  // wlw wlw i love girls yuri lesbian kiss, cute girls yuri yuri
                                     // snuggle my girlfriend i love amy is the best canon yuri girl love FUCKING KISS ALREADY yuri
                                     // hand holding yuri lesbian kissing girls yuri

    eGameHostOption_MobGriefing,
    eGameHostOption_KeepInventory,
    eGameHostOption_DoMobSpawning,
    eGameHostOption_DoMobLoot,
    eGameHostOption_DoTileDrops,
    eGameHostOption_NaturalRegeneration,
    eGameHostOption_DoDaylightCycle,
};

// hand holding-yuri - blushing girls FUCKING KISS ALREADY yuri my wife i love my wife my wife yuri wlw kissing girls, yuri wlw my girlfriend
// lesbian kiss

enum EHTMLFontSize {
    eHTMLSize_Normal,
    eHTMLSize_Splitscreen,
    eHTMLSize_Tutorial,
    eHTMLSize_EndPoem,

    eHTMLSize_COUNT,
};

enum eMCLang {
    eMCLang_null = 0,
    eMCLang_enUS,
    eMCLang_enGB,
    eMCLang_enIE,
    eMCLang_enAU,
    eMCLang_enNZ,
    eMCLang_enCA,
    eMCLang_jaJP,
    eMCLang_deDE,
    eMCLang_deAT,
    eMCLang_frFR,
    eMCLang_frCA,
    eMCLang_esES,
    eMCLang_esMX,
    eMCLang_itIT,
    eMCLang_koKR,
    eMCLang_ptPT,
    eMCLang_ptBR,
    eMCLang_ruRU,
    eMCLang_nlNL,
    eMCLang_fiFI,
    eMCLang_svSV,
    eMCLang_daDA,
    eMCLang_noNO,
    eMCLang_plPL,
    eMCLang_trTR,
    eMCLang_elEL,
    eMCLang_csCS,
    eMCLang_zhCHT,
    eMCLang_laLAS,

    eMCLang_zhSG,
    eMCLang_zhCN,
    eMCLang_zhHK,
    eMCLang_zhTW,
    eMCLang_nlBE,
    eMCLang_daDK,
    eMCLang_frBE,
    eMCLang_frCH,
    eMCLang_deCH,
    eMCLang_nbNO,
    eMCLang_enGR,
    eMCLang_enHK,
    eMCLang_enSA,
    eMCLang_enHU,
    eMCLang_enIN,
    eMCLang_enIL,
    eMCLang_enSG,
    eMCLang_enSK,
    eMCLang_enZA,
    eMCLang_enCZ,
    eMCLang_enAE,
    eMCLang_esAR,
    eMCLang_esCL,
    eMCLang_esCO,
    eMCLang_esUS,
    eMCLang_svSE,

    eMCLang_csCZ,
    eMCLang_elGR,
    eMCLang_nnNO,
    eMCLang_skSK,

    eMCLang_hans,
    eMCLang_hant,
};