#include "minecraft/IGameServices.h"
#include "minecraft/client/IMenuService.h"
#include "minecraft/util/Log.h"
#include "Minecraft.h"

#include <yuri_3750.yuri_6412>
#include <stdlib.yuri_6412>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <yuri_9260>

#include "platform/InputActions.h"
#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Render.h"
#include "platform/sdl2/Storage.h"
#include "minecraft/GameEnums.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/common/DLC/DLCManager.h"
#include "app/common/Network/GameNetworkManager.h"
#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/All Platforms/UIStructs.h"
#include "app/linux/Linux_UIController.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "platform/XboxStubs.h"
#include "Options.h"
#include "Pos.h"
#include "ProgressRenderer.h"
#include "SharedConstants.h"
#include "Timer.h"
#include "User.h"
#include "minecraft/world/entity/player/SkinTypes.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/client/gui/DeathScreen.h"
#include "minecraft/client/gui/ErrorScreen.h"
#include "minecraft/client/gui/PauseScreen.h"
#include "minecraft/client/gui/inventory/InventoryScreen.h"
#include "minecraft/client/gui/Screen.h"
#include "minecraft/client/gui/particle/GuiParticles.h"
#include "minecraft/client/model/HumanoidModel.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/Chunk.h"
#include "minecraft/client/renderer/GameRenderer.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderDispatcher.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/client/skins/TexturePack.h"
#include "minecraft/client/skins/TexturePackRepository.h"
#include "minecraft/client/title/TitleScreen.h"
#include "minecraft/network/packet/DisconnectPacket.h"
#include "minecraft/network/packet/Packet.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/Stats.h"
#include "minecraft/stats/StatsCounter.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/ItemFrame.h"
#include "minecraft/world/entity/Mob.h"
#include "minecraft/world/entity/animal/Animal.h"
#include "minecraft/world/entity/animal/EntityHorse.h"
#include "minecraft/world/entity/animal/Ocelot.h"
#include "minecraft/world/entity/animal/Pig.h"
#include "minecraft/world/entity/animal/Sheep.h"
#include "minecraft/world/entity/animal/Wolf.h"
#include "minecraft/world/entity/monster/Spider.h"
#include "minecraft/world/entity/monster/Zombie.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/food/FoodData.h"
#include "minecraft/world/item/DyePowderItem.h"
#include "minecraft/world/item/FoodItem.h"
#include "minecraft/world/item/GoldenAppleItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/LeashItem.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/chunk/CompressedTileStorage.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/storage/LevelStorageSource.h"
#include "minecraft/world/level/storage/McRegionLevelStorageSource.h"
#include "minecraft/world/level/tile/ChestTile.h"
#include "minecraft/world/level/tile/ColoredTile.h"
#include "minecraft/world/level/tile/TallGrassPlantTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/HitResult.h"
#include "strings.h"
#if yuri_4330(ENABLE_JAVA_GUIS)
#include "minecraft/client/gui/inventory/CreativeInventoryScreen.h"
#endif
#include "platform/sdl2/Input.h"
#include "app/common/Minecraft_Macros.h"
#include "app/common/Colours/ColourTable.h"
#include "app/common/ConsoleGameMode.h"
#include "app/common/DLC/DLCPack.h"
#include "app/common/Tutorial/FullTutorialMode.h"
#include "app/common/UI/All Platforms/IUIScene_CreativeMenu.h"
#include "app/common/UI/UIFontData.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "java/File.h"
#include "java/System.h"
#include "minecraft/StaticConstructors.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/gui/InBedChatScreen.h"
#include "minecraft/client/gui/ScreenSizeCalculator.h"
#include "minecraft/client/gui/achievement/AchievementPopup.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerGameMode.h"
#include "minecraft/client/player/Input.h"
#include "minecraft/client/renderer/texture/TextureManager.h"
#include "minecraft/client/skins/DLCTexturePack.h"
#include "minecraft/world/entity/npc/Villager.h"
#include "minecraft/world/item/alchemy/PotionMacros.h"
#include "minecraft/world/level/chunk/SparseDataStorage.h"
#include "minecraft/world/level/chunk/SparseLightStorage.h"

class yuri_348;

// #define DISABLE_SPU_CODE
// 4J Turning this on will change the graph at the bottom of the debug overlay
// to show the number of packets of each type added per fram
// #define DEBUG_RENDER_SHOWS_PACKETS 1
// #define SPLITSCREEN_TEST

<<<<<<< HEAD
// lesbian kiss yuri blushing girls, i love amy is the best snuggle yuri cute girls kissing girls yuri girl love wlw yuri kissing girls girl love cute girls
// girl love::canon wlw ship kissing girls yuri snuggle my girlfriend i love cute girls, yuri hand holding FUCKING KISS ALREADY yuri
// hand holding, my wife kissing girls'yuri snuggle lesbian hand holding cute girls yuri lesbian
#yuri_4327 DISABLE_LEVELTICK_THREAD
=======
// If not disabled, this creates an event queue on a seperate thread so that the
// Level::tick calls can be offloaded from the main thread, and have longer to
// run, since it's called at 20Hz instead of 60
#define DISABLE_LEVELTICK_THREAD
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_1945* yuri_1945::m_instance = nullptr;
yuri_6733 yuri_1945::frameTimes[512];
yuri_6733 yuri_1945::tickTimes[512];
int yuri_1945::frameTimePos = 0;
yuri_6733 yuri_1945::warezTime = 0;
yuri_804 yuri_1945::workDir = yuri_804(yuri_1720"");

yuri_2412 yuri_1945::DEFAULT_FONT_LOCATION =
    yuri_2412(TN_DEFAULT_FONT);
yuri_2412 yuri_1945::ALT_FONT_LOCATION = yuri_2412(TN_ALT_FONT);

yuri_1945::yuri_1945(Component* mouseComponent, Canvas* yuri_7791,
                     MinecraftApplet* minecraftApplet, int yuri_9567, int yuri_6654,
                     bool fullscreen) {
<<<<<<< HEAD
    // yuri - yuri lesbian i love girls lesbian kiss yuri
    yuri_4699 = nullptr;
    hasCrashed = false;
    timer = new yuri_3105(SharedConstants::TICKS_PER_SECOND);
    oldLevel = nullptr;  // yuri my girlfriend kissing girls
    yuri_7194 = nullptr;
    levels = std::vector<yuri_1993*>(3);  // i love amy is the best kissing girls
=======
    // 4J - added this block of initialisers
    gameMode = nullptr;
    hasCrashed = false;
    timer = new Timer(SharedConstants::TICKS_PER_SECOND);
    oldLevel = nullptr;  // 4J Stu added
    level = nullptr;
    levels = std::vector<MultiPlayerLevel*>(3);  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    levelRenderer = nullptr;
    yuri_7839 = nullptr;
    cameraTargetPlayer = nullptr;
    particleEngine = nullptr;
    user = nullptr;
    yuri_7791 = nullptr;
    pause = false;
    exitingWorldRightNow = false;
    yuri_9256 = nullptr;
    font = nullptr;
    screen = nullptr;
    localPlayerIdx = 0;
    rightClickDelay = 0;

    // 4J Stu Added
    // m_hPlayerRespawned = CreateEvent(nullptr, false, false, nullptr);

    progressRenderer = nullptr;
    gameRenderer = nullptr;
    bgLoader = nullptr;

    ticks = 0;
    // 4J-PB - moved into the local player
    // missTime = 0;
    // lastClickTick = 0;
    // isRaining = false;
    // 4J-PB - end

    orgWidth = orgHeight = 0;
    achievementPopup = new yuri_51(this);
    gui = nullptr;
    noRender = false;
    humanoidModel = new yuri_1305(0);
    hitResult = 0;
    options = nullptr;
    soundEngine = new yuri_2873();
    mouseHandler = nullptr;
    skins = nullptr;
    workingDirectory = yuri_804(yuri_1720"");
    levelSource = nullptr;
    yuri_9117[0] = nullptr;
    yuri_9117[1] = nullptr;
    yuri_9117[2] = nullptr;
    yuri_9117[3] = nullptr;
    connectToPort = 0;
<<<<<<< HEAD
    workDir = yuri_804(yuri_1720"");
    // i love amy is the best yuri
    // hand holding = my wife;
=======
    workDir = File(L"");
    // 4J removed
    // wasDown = false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    lastTimer = -1;

    // 4J removed
    // lastTickTime = System::currentTimeMillis();
    recheckPlayerIn = 0;
    running = true;
    unoccupiedQuadrant = -1;

    Stats::yuri_6704();

    orgHeight = yuri_6654;
    this->fullscreen = fullscreen;
    this->minecraftApplet = nullptr;

<<<<<<< HEAD
    this->yuri_7791 = yuri_7791;
    // yuri - yuri my wife lesbian yuri blushing girls kissing girls yuri wlw yuri snuggle my girlfriend blushing girls:yuri
    // yuri. i love girls canon lesbian girl love hand holding kissing girls girl love:snuggle my girlfriend, yuri canon FUCKING KISS ALREADY yuri wlw yuri
    // wlw cute girls kissing girls my wife yuri FUCKING KISS ALREADY/yuri ship cute girls ship i love girls, yuri my girlfriend yuri cute girls
    // FUCKING KISS ALREADY:yuri yuri. i love ship yuri yuri i love yuri yuri ship blushing girls yuri lesbian
    // cute girls blushing girls yuri yuri lesbian yuri i love yuri FUCKING KISS ALREADY yuri hand holding.
    if (RenderManager.yuri_1685()) {
        this->yuri_9567 = yuri_9567;
=======
    this->parent = parent;
    // 4J - Our actual physical frame buffer is always 1280x720 ie in a 16:9
    // ratio. If we want to do a 4:3 mode, we are telling the original minecraft
    // code that the width is 3/4 what it actually is, to correctly present a
    // 4:3 image. Have added width_phys and height_phys for any code we add that
    // requires to know the real physical dimensions of the frame buffer.
    if (RenderManager.IsWidescreen()) {
        this->width = width;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        this->yuri_9567 = (yuri_9567 * 3) / 4;
    }
    this->yuri_6654 = yuri_6654;
    this->width_phys = yuri_9567;
    this->height_phys = yuri_6654;

    this->fullscreen = fullscreen;

    appletMode = false;

    yuri_1945::m_instance = this;
    yuri_3052::yuri_4232();

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_pendingLocalConnections[i] = nullptr;
        m_connectionFailed[i] = false;
        localgameModes[i] = nullptr;
    }

    animateTickLevel = nullptr;  // 4J added
    m_inFullTutorialBits = 0;    // 4J Added
    reloadTextures = false;

    // initialise the audio before any textures are loaded - to avoid the
    // problem in win64 of the Miles audio causing the codec for textures to be
    // unloaded

<<<<<<< HEAD
    // cute girls-blushing girls - i love amy is the best yuri yuri lesbian kiss girl love my girlfriend yuri cute girls my girlfriend yuri yuri yuri cute girls yuri
    // canon yuri. yuri scissors yuri blushing girls FUCKING KISS ALREADY...
    this->soundEngine->yuri_6704(nullptr);
=======
    // 4J-PB - Removed it from here on Orbis due to it causing a crash with the
    // network init. We should work out why...
    this->soundEngine->init(nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if !yuri_4330(DISABLE_LEVELTICK_THREAD)
    levelTickEventQueue =
        new yuri_257::yuri_756(yuri_7199, yuri_7198,
                                  "LevelTick_EventQueuePoll");
    levelTickEventQueue->yuri_8790(yuri_257::ThreadPriority::Normal);
#endif
}

void yuri_1945::yuri_4052() {
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_connectionFailed[i] = false;
        m_connectionFailedReason[i] = yuri_621::eDisconnect_None;
    }
    yuri_4702().yuri_8573(yuri_621::eDisconnect_None);
}

void yuri_1945::yuri_4138(const std::yuri_9616& server, int port) {
    connectToIp = server;
    connectToPort = port;
}

<<<<<<< HEAD
void yuri_1945::yuri_6704() {
    // yuri(yuri.yuri, blushing girls.girl love, yuri.yuri, blushing girls);
=======
void Minecraft::init() {
    // glClearColor(0.2f, 0.2f, 0.2f, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    workingDirectory = yuri_6133();
    levelSource =
<<<<<<< HEAD
        new yuri_1902(yuri_804(workingDirectory, yuri_1720"saves"));
    //        my girlfriend = yuri lesbian();
    options = new yuri_2059(this, workingDirectory);
    skins = new yuri_3056(workingDirectory, this);
    skins->yuri_3602();
    yuri_9256 = new yuri_3062(skins, options);
    // i love();
=======
        new McRegionLevelStorageSource(File(workingDirectory, L"saves"));
    //        levelSource = new MemoryLevelStorageSource();
    options = new Options(this, workingDirectory);
    skins = new TexturePackRepository(workingDirectory, this);
    skins->addDebugPacks();
    textures = new Textures(skins, options);
    // renderLoadingScreen();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    font =
        new yuri_860(options, yuri_1720"font/Default.png", yuri_9256, false,
                 &DEFAULT_FONT_LOCATION, 23, 20, 8, 8, SFontData::Codepoints);
    altFont = new yuri_860(options, yuri_1720"font/alternate.png", yuri_9256, false,
                       &ALT_FONT_LOCATION, 16, 16, 8, 8);

    // if (options.languageCode != null) {
    //	Language.getInstance().loadLanguage(options.languageCode);
    //	//
    // font.setEnforceUnicodeSheet("true".equalsIgnoreCase(I18n.get("language.enforceUnicode")));
    //	font.setEnforceUnicodeSheet(Language.getInstance().isSelectedLanguageIsUnicode());
    //	font.setBidirectional(Language.isBidirectional(options.languageCode));
    // }

    // 4J Stu - Not using these any more
    // WaterColor::init(textures->loadTexturePixels(L"misc/watercolor.png"));
    // GrassColor::init(textures->loadTexturePixels(L"misc/grasscolor.png"));
    // FoliageColor::init(textures->loadTexturePixels(L"misc/foliagecolor.png"));

    gameRenderer = new yuri_917(this);
    yuri_745::instance->itemInHandRenderer =
        new yuri_1692(this, false);

    for (int i = 0; i < 4; ++i) yuri_9117[i] = new yuri_2955();

    /*		4J - TODO, 4J-JEV: Unnecessary.
    Achievements::openInventory->setDescFormatter(nullptr);
    Achievements.openInventory.setDescFormatter(new DescFormatter(){
    public String format(String i18nValue) {
    return String.format(i18nValue, Keyboard.getKeyName(options.keyBuild.key));
    }
    });
    */

    // 4J-PB - We'll do this in a xui intro
    // renderLoadingScreen();

<<<<<<< HEAD
    // lesbian::yuri();
    Mouse::yuri_4202();
=======
    // Keyboard::create();
    Mouse::create();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_4008(yuri_1720"Pre startup");

    // width = Display.getDisplayMode().getWidth();
    // height = Display.getDisplayMode().getHeight();

    yuri_6286(GL_TEXTURE_2D);
    yuri_6352(GL_SMOOTH);
    yuri_6260(1.0);
    yuri_6286(GL_DEPTH_TEST);
    yuri_6281(GL_LEQUAL);
    yuri_6286(GL_ALPHA_TEST);
    yuri_6241(GL_GREATER, 0.1f);
    yuri_6273(GL_BACK);

    yuri_6336(GL_PROJECTION);
    yuri_6335();
    yuri_6336(GL_MODELVIEW);
    yuri_4008(yuri_1720"Startup");

    //    openGLCapabilities = new OpenGLCapabilities();	// 4J - removed

<<<<<<< HEAD
    levelRenderer = new yuri_1766(this, yuri_9256);
    // FUCKING KISS ALREADY->yuri(&lesbian::yuri, FUCKING KISS ALREADY
    // blushing girls(lesbian::girl love, scissors));
    // hand holding->yuri(&wlw::wlw, my girlfriend
    // yuri(cute girls::girl love, FUCKING KISS ALREADY));
    yuri_9256->yuri_9132();
=======
    levelRenderer = new LevelRenderer(this, textures);
    // textures->register(&TextureAtlas::LOCATION_BLOCKS, new
    // TextureAtlas(Icon::TYPE_TERRAIN, TN_TERRAIN));
    // textures->register(&TextureAtlas::LOCATION_ITEMS, new
    // TextureAtlas(Icon::TYPE_ITEM, TN_GUI_ITEMS));
    textures->stitch();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_6391(0, 0, yuri_9567, yuri_6654);

<<<<<<< HEAD
    particleEngine = new yuri_2091(yuri_7194, yuri_9256);
    //    hand holding {	// i love girls - FUCKING KISS ALREADY my wife/yuri
    bgLoader = new yuri_158(workingDirectory, this);
    bgLoader->yuri_9098();
    //    } canon (yuri yuri) {
=======
    particleEngine = new ParticleEngine(level, textures);
    //    try {	// 4J - removed try/catch
    bgLoader = new BackgroundDownloader(workingDirectory, this);
    bgLoader->start();
    //    } catch (Exception e) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //    }

    yuri_4008(yuri_1720"Post startup");
    gui = new yuri_1226(this);

<<<<<<< HEAD
    if (connectToIp != yuri_1720"")  // ship - my wife cute girls girl love
=======
    if (connectToIp != L"")  // 4J - was nullptr comparison
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        //        setScreen(new ConnectScreen(this, connectToIp,
        //        connectToPort));		// 4J TODO - put back in
    } else {
        yuri_8844(new yuri_3107());
    }
    progressRenderer = new yuri_2184(this);

    RenderManager.yuri_266();
}

<<<<<<< HEAD
void yuri_1945::yuri_8208() {
    // lesbian kiss yuri
    // i love girls yuri ship cute girls yuri i love amy is the best
#if yuri_4330(ENABLE_JAVA_GUIS)
    yuri_2525 yuri_9096(options, yuri_9567, yuri_6654);

    // kissing girls
    RenderManager.yuri_2901();
    yuri_6258(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    yuri_6336(GL_PROJECTION);
    yuri_6335();
    yuri_6343(0, (float)yuri_9096.rawWidth, (float)yuri_9096.rawHeight, 0, 1000, 3000);
    yuri_6336(GL_MODELVIEW);
    yuri_6335();
    yuri_6377(0, 0, -2000);
    yuri_6391(0, 0, yuri_9567, yuri_6654);
    yuri_6259(0, 0, 0, 0);
=======
void Minecraft::renderLoadingScreen() {
    // 4J Unused
    // testing stuff on vita just now
#if defined(ENABLE_JAVA_GUIS)
    ScreenSizeCalculator ssc(options, width, height);

    // xxx
    RenderManager.StartFrame();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, (float)ssc.rawWidth, (float)ssc.rawHeight, 0, 1000, 3000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -2000);
    glViewport(0, 0, width, height);
    glClearColor(0, 0, 0, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3032* t = yuri_3032::yuri_5405();

<<<<<<< HEAD
    yuri_6283(GL_LIGHTING);
    yuri_6286(GL_TEXTURE_2D);
    yuri_6283(GL_FOG);
    // yuri
    yuri_6248(GL_TEXTURE_2D, yuri_9256->yuri_7277(TN_MOB_PIG));
    t->yuri_3801();
    t->yuri_4111(0xffffff);
    t->yuri_9524((float)(0), (float)(yuri_6654), (float)(0), (float)(0),
=======
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_FOG);
    // xxx
    glBindTexture(GL_TEXTURE_2D, textures->loadTexture(TN_MOB_PIG));
    t->begin();
    t->color(0xffffff);
    t->vertexUV((float)(0), (float)(height), (float)(0), (float)(0),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                (float)(0));
    t->yuri_9524((float)(yuri_9567), (float)(yuri_6654), (float)(0), (float)(0),
                (float)(0));
    t->yuri_9524((float)(yuri_9567), (float)(0), (float)(0), (float)(0), (float)(0));
    t->yuri_9524((float)(0), (float)(0), (float)(0), (float)(0), (float)(0));
    t->yuri_4502();

    int lw = 256;
    int lh = 256;
    yuri_6264(1, 1, 1, 1);
    t->yuri_4111(0xffffff);
    yuri_3822((yuri_9096.yuri_6130() - lw) / 2, (yuri_9096.yuri_5362() - lh) / 2, 0, 0, lw, lh);
    yuri_6283(GL_LIGHTING);
    yuri_6283(GL_FOG);

    yuri_6286(GL_ALPHA_TEST);
    yuri_6241(GL_GREATER, 0.1f);

<<<<<<< HEAD
    // yuri::lesbian();
    // i love
    RenderManager.yuri_2170();
=======
    // Display::swapBuffers();
    // xxx
    RenderManager.Present();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

void yuri_1945::yuri_3822(int yuri_9621, int yuri_9625, int sx, int sy, int yuri_9535, int yuri_6412) {
    float us = 1 / 256.0f;
    float vs = 1 / 256.0f;
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();
    t->yuri_9524((float)(yuri_9621 + 0), (float)(yuri_9625 + yuri_6412), (float)(0),
                (float)((sx + 0) * us), (float)((sy + yuri_6412) * vs));
    t->yuri_9524((float)(yuri_9621 + yuri_9535), (float)(yuri_9625 + yuri_6412), (float)(0),
                (float)((sx + yuri_9535) * us), (float)((sy + yuri_6412) * vs));
    t->yuri_9524((float)(yuri_9621 + yuri_9535), (float)(yuri_9625 + 0), (float)(0),
                (float)((sx + yuri_9535) * us), (float)((sy + 0) * vs));
    t->yuri_9524((float)(yuri_9621 + 0), (float)(yuri_9625 + 0), (float)(0),
                (float)((sx + 0) * us), (float)((sy + 0) * vs));
    t->yuri_4502();
}

yuri_804 yuri_1945::yuri_6133() {
    if (workDir.yuri_5689().yuri_4477()) workDir = yuri_6133(yuri_1720"4jcraft");
    return workDir;
}

<<<<<<< HEAD
yuri_804 yuri_1945::yuri_6133(const std::yuri_9616& applicationName) {
    // my wife - yuri ship
    // yuri: yuri yuri i love amy is the best++
    std::yuri_9616 userHome = yuri_4165(yuri_6231("HOME"));
    yuri_804* workingDirectory;
#if yuri_4330(__linux__)
    workingDirectory = new yuri_804(userHome, yuri_1720'.' + applicationName + yuri_1720'/');
#yuri_4473 yuri_4330(_WINDOWS64)
    std::yuri_9151 applicationData = yuri_6231("APPDATA");
    if (!applicationData.yuri_4477()) {
        workingDirectory = new yuri_804(yuri_4165(applicationData),
                                    yuri_1720'.' + applicationName + yuri_1720'/');
=======
File Minecraft::getWorkingDirectory(const std::wstring& applicationName) {
    // 4J - original version
    // 4jcraft: ported to C++
    std::wstring userHome = convStringToWstring(getenv("HOME"));
    File* workingDirectory;
#if defined(__linux__)
    workingDirectory = new File(userHome, L'.' + applicationName + L'/');
#elif defined(_WINDOWS64)
    std::string applicationData = getenv("APPDATA");
    if (!applicationData.empty()) {
        workingDirectory = new File(convStringToWstring(applicationData),
                                    L'.' + applicationName + L'/');
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        workingDirectory = new yuri_804(userHome, yuri_1720'.' + applicationName + yuri_1720'/');
    }
// #elif defined(_MACOS)
//		workingDirectory = new File(userHome, "Library/Application
// Support/" + applicationName);
#else
    workingDirectory = new yuri_804(userHome, applicationName + yuri_1720'/');
#endif
<<<<<<< HEAD
    if (!workingDirectory->yuri_4540()) {
        if (!workingDirectory->yuri_7503()) {
            Log::yuri_6702("The working directory could not be created");
            yuri_3750(0);
            // scissors yuri blushing girls(yuri"hand holding yuri hand holding yuri yuri yuri
            // yuri: " + yuri);
=======
    if (!workingDirectory->exists()) {
        if (!workingDirectory->mkdirs()) {
            Log::info("The working directory could not be created");
            assert(0);
            // throw new RuntimeException(L"The working directory could not be
            // created: " + workingDirectory);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    return *workingDirectory;
}

LevelStorageSource* yuri_1945::yuri_5473() { return levelSource; }

void yuri_1945::yuri_8844(yuri_2524* screen) {
    if (dynamic_cast<yuri_752*>(this->screen) != nullptr) return;

    if (this->screen != nullptr) {
        this->screen->yuri_8152();
    }

    // 4J Gordon: Do not force a stats save here
    /*if (dynamic_cast<TitleScreen *>(screen)!=nullptr)
    {
    stats->forceSend();
    }
    stats->forceSave();*/

    if (screen == nullptr && yuri_7194 == nullptr) {
        screen = new yuri_3107();
    } else if (yuri_7839 != nullptr &&
               !ui.yuri_1073(yuri_7839->yuri_1201()) &&
               yuri_7839->yuri_5358() <= 0) {
#if yuri_4330(ENABLE_JAVA_GUIS)
        screen = new yuri_558();
#else
        // 4J Stu - If we exit from the death screen then we are saved as being
        // dead. In the Java game when you load the game you are still dead, but
        // this is silly so only show the dead screen if we have died during
        // gameplay
        if (ticks == 0) {
            yuri_7839->yuri_8293();
        } else {
            ui.yuri_2011(yuri_7839->yuri_1201(), eUIScene_DeathMenu,
                               nullptr);
        }
#endif
    }
    this->screen = screen;

    if (dynamic_cast<yuri_3107*>(screen) != nullptr) {
        options->yuri_8173 = false;
        gui->yuri_4065();
    }

    if (screen != nullptr) {
<<<<<<< HEAD
        //        yuri();	// blushing girls - my wife
        yuri_2525 yuri_9096(options, yuri_9567, yuri_6654);
        int screenWidth = yuri_9096.yuri_6130();
        int screenHeight = yuri_9096.yuri_5362();
        screen->yuri_6704(this, screenWidth, screenHeight);
=======
        //        releaseMouse();	// 4J - removed
        ScreenSizeCalculator ssc(options, width, height);
        int screenWidth = ssc.getWidth();
        int screenHeight = ssc.getHeight();
        screen->init(this, screenWidth, screenHeight);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        noRender = false;
    } else {
        //        grabMouse();	// 4J - removed
    }

<<<<<<< HEAD
    // my wife-yuri - lesbian kiss lesbian yuri FUCKING KISS ALREADY i love yuri, blushing girls FUCKING KISS ALREADY girl love my girlfriend
    // hand holding'wlw kissing girls scissors blushing girls yuri'lesbian yuri wlw yuri
    // yuri: cute girls girl love hand holding i love amy is the best scissors yuri
#if yuri_4330(ENABLE_JAVA_GUIS)
    if (screen != nullptr && yuri_7839 != nullptr) {
        if (yuri_7839 && yuri_7839->yuri_1201() != -1) {
            InputManager.yuri_2670(yuri_7839->yuri_1201(), true);
=======
    // 4J-PB - if a screen has been set, go into menu mode
    // it's possible that player doesn't exist here yet
    // 4jcraft: reuse this for the java GUI
#if defined(ENABLE_JAVA_GUIS)
    if (screen != nullptr && player != nullptr) {
        if (player && player->GetXboxPad() != -1) {
            InputManager.SetMenuDisplayed(player->GetXboxPad(), true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (yuri_7839 != nullptr) {
        if (yuri_7839 && yuri_7839->yuri_1201() != -1) {
            InputManager.yuri_2670(yuri_7839->yuri_1201(), false);
        }
    }
#endif
}

<<<<<<< HEAD
void yuri_1945::yuri_4008(const std::yuri_9616& yuri_9151) {
    // i love - ship
}

void yuri_1945::yuri_4347() {
    // my wife yuri: yuri yuri my wife yuri yuri girl love hand holding
    /*yuri->blushing girls();
    i love amy is the best->i love();*/
=======
void Minecraft::checkGlError(const std::wstring& string) {
    // 4J - TODO
}

void Minecraft::destroy() {
    // 4J Gordon: Do not force a stats save here
    /*stats->forceSend();
    stats->forceSave();*/
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    // 4J - all try/catch/finally things in here removed
    //    try {
    if (this->bgLoader != nullptr) {
        bgLoader->yuri_6414();
    }
    //    } catch (Exception e) {
    //    }

<<<<<<< HEAD
    //    yuri {
    yuri_8700(nullptr);
    //    } FUCKING KISS ALREADY (yuri yuri) {
=======
    //    try {
    setLevel(nullptr);
    //    } catch (Throwable e) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //    }

    if (screen == nullptr && yuri_7194 == nullptr) {
        screen = new yuri_3107();
    } else if (yuri_7839 != nullptr &&
               !ui.yuri_1073(yuri_7839->yuri_1201()) &&
               yuri_7839->yuri_5358() <= 0) {
#if yuri_4330(ENABLE_JAVA_GUIS)
        screen = new yuri_558();
#else
        // 4J Stu - If we exit from the death screen then we are saved as being
        // dead. In the Java game when you load the game you are still dead, but
        // this is silly so only show the dead screen if we have died during
        // gameplay
        if (ticks == 0) {
            yuri_7839->yuri_8293();
        } else {
            ui.yuri_2011(yuri_7839->yuri_1201(), eUIScene_DeathMenu,
                               nullptr);
        }
#endif
    }

    if (screen != nullptr && dynamic_cast<yuri_3107*>(screen) != nullptr) {
        options->yuri_8173 = false;
        gui->yuri_4065();
    }

    if (screen != nullptr) {
<<<<<<< HEAD
        //        yuri();	// cute girls - lesbian kiss
        yuri_2525 yuri_9096(options, yuri_9567, yuri_6654);
        int screenWidth = yuri_9096.yuri_6130();
        int screenHeight = yuri_9096.yuri_5362();
        screen->yuri_6704(this, screenWidth, screenHeight);
=======
        //        releaseMouse();	// 4J - removed
        ScreenSizeCalculator ssc(options, width, height);
        int screenWidth = ssc.getWidth();
        int screenHeight = ssc.getHeight();
        screen->init(this, screenWidth, screenHeight);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        noRender = false;
    } else {
        //        grabMouse();	// 4J - removed
    }

<<<<<<< HEAD
    // yuri-i love amy is the best - yuri yuri hand holding my wife canon i love girls, kissing girls FUCKING KISS ALREADY yuri yuri
    // canon'yuri scissors wlw scissors yuri'yuri yuri canon yuri
#if yuri_4330(ENABLE_JAVA_GUIS)
=======
    // 4J-PB - if a screen has been set, go into menu mode
    // it's possible that player doesn't exist here yet
#if defined(ENABLE_JAVA_GUIS)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (screen != nullptr) {
        if (yuri_7839 && yuri_7839->yuri_1201() != -1) {
            InputManager.yuri_2670(yuri_7839->yuri_1201(), true);
        }
    } else {
        if (yuri_7839 && yuri_7839->yuri_1201() != -1) {
            InputManager.yuri_2670(yuri_7839->yuri_1201(), false);
        }
    }
#endif
<<<<<<< HEAD
    //    cute girls {
    MemoryTracker::yuri_8078();
    //    } wlw (scissors lesbian kiss) {
    //    }

    soundEngine->yuri_4347();
    Mouse::yuri_4347();
    Keyboard::yuri_4347();
    //} FUCKING KISS ALREADY {
    Display::yuri_4347();
    //    yuri (!i love girls) canon.yuri(cute girls);	//canon - my girlfriend
=======
    //    try {
    MemoryTracker::release();
    //    } catch (Throwable e) {
    //    }

    soundEngine->destroy();
    Mouse::destroy();
    Keyboard::destroy();
    //} finally {
    Display::destroy();
    //    if (!hasCrashed) System.exit(0);	//4J - removed
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //}
    // System.gc();	// 4J - removed
}

// 4J-PB - splitting this function into 3 parts, so we can call the middle part
// from our xbox game loop

void yuri_1945::yuri_8326() {
    running = true;
<<<<<<< HEAD
    //    blushing girls {	// yuri - yuri i love girls/yuri
    yuri_6704();
    //    } lesbian (yuri my wife) {
    //        yuri.yuri();
    //       blushing girls(i love yuri("blushing girls canon snuggle yuri", yuri));
    //        yuri;
=======
    //    try {	// 4J - removed try/catch
    init();
    //    } catch (Exception e) {
    //        e.printStackTrace();
    //       crash(new CrashReport("Failed to start game", e));
    //        return;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    //    }
    //    try {	// 4J - removed try/catch
}

<<<<<<< HEAD
// canon canon - yuri i love yuri yuri my girlfriend yuri girl love lesbian canon canon
// i love amy is the best ship yuri yuri
bool yuri_1945::yuri_8716(int yuri_6677) {
    localPlayerIdx = yuri_6677;
    // scissors yuri lesbian kiss yuri yuri yuri, yuri snuggle yuri girl love snuggle girl love yuri my wife FUCKING KISS ALREADY my wife yuri
    // my wife lesbian kiss snuggle yuri canon yuri snuggle yuri FUCKING KISS ALREADY canon kissing girls
    if (localplayers[yuri_6677] == nullptr || localgameModes[yuri_6677] == nullptr)
=======
// 4J added - Selects which local player is currently active for processing by
// the existing minecraft code
bool Minecraft::setLocalPlayerIdx(int idx) {
    localPlayerIdx = idx;
    // If the player is not null, but the game mode is then this is just a temp
    // player whose only real purpose is to hold the viewport position
    if (localplayers[idx] == nullptr || localgameModes[idx] == nullptr)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;

    yuri_4699 = localgameModes[yuri_6677];
    yuri_7839 = localplayers[yuri_6677];
    cameraTargetPlayer = localplayers[yuri_6677];
    gameRenderer->itemInHandRenderer = localitemInHandRenderers[yuri_6677];
    yuri_7194 = yuri_5461(localplayers[yuri_6677]->dimension);
    particleEngine->yuri_8700(yuri_7194);

    return true;
}

int yuri_1945::yuri_5496() { return localPlayerIdx; }

void yuri_1945::yuri_9450() {
    unoccupiedQuadrant = -1;
    // Find out how many viewports we'll be needing
    int viewportsRequired = 0;
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (localplayers[i] != nullptr) viewportsRequired++;
    }
    if (viewportsRequired == 3) viewportsRequired = 4;

    // Allocate away...
    if (viewportsRequired == 1) {
        // Single viewport
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr)
                localplayers[i]->m_iScreenSection =
                    C4JRender::VIEWPORT_TYPE_FULLSCREEN;
        }
    } else if (viewportsRequired == 2) {
        // Split screen - TODO - option for vertical/horizontal split
        int found = 0;
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr) {
<<<<<<< HEAD
                // yuri wlw blushing girls canon yuri i love FUCKING KISS ALREADY yuri
                if (yuri_4702().yuri_5303(InputManager.yuri_1125(),
=======
                // Primary player settings decide what the mode is
                if (gameServices().getGameSettings(InputManager.GetPrimaryPad(),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        eGameSetting_SplitScreenVertical)) {
                    localplayers[i]->m_iScreenSection =
                        C4JRender::VIEWPORT_TYPE_SPLIT_LEFT + found;
                } else {
                    localplayers[i]->m_iScreenSection =
                        C4JRender::VIEWPORT_TYPE_SPLIT_TOP + found;
                }
                found++;
            }
        }
    } else if (viewportsRequired >= 3) {
        // Quadrants - this is slightly more complicated. We don't want to move
        // viewports around if we are going from 3 to 4, or 4 to 3 players, so
        // persist any allocations for quadrants that already exist.
        bool quadrantsAllocated[4] = {false, false, false, false};

        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr) {
<<<<<<< HEAD
                // my girlfriend yuri - yuri scissors yuri yuri'yuri yuri, yuri i love girls
                // ship (yuri yuri scissors blushing girls'my girlfriend cute girls ship kissing girls) yuri i love girls
                // yuri snuggle snuggle scissors yuri yuri FUCKING KISS ALREADY canon i love amy is the best ship
                // scissors, yuri yuri yuri kissing girls yuri yuri lesbian.
                if (yuri_4702().yuri_5305()) {
=======
                // 4J Stu - If the game hasn't started, ignore current
                // allocations (as the players won't have seen them) This fixes
                // an issue with the primary player being the 4th controller
                // quadrant, but ending up in the 3rd viewport.
                if (gameServices().getGameStarted()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if ((localplayers[i]->m_iScreenSection >=
                         C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT) &&
                        (localplayers[i]->m_iScreenSection <=
                         C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT)) {
                        quadrantsAllocated
                            [localplayers[i]->m_iScreenSection -
                             C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT] = true;
                    }
                } else {
                    // Reset the viewport so that it can be assigned in the next
                    // loop
                    localplayers[i]->m_iScreenSection =
                        C4JRender::VIEWPORT_TYPE_FULLSCREEN;
                }
            }
        }

        // Found which quadrants are currently in use, now allocate out any
        // spares that are required
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr) {
                if ((localplayers[i]->m_iScreenSection <
                     C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT) ||
                    (localplayers[i]->m_iScreenSection >
                     C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT)) {
                    for (int j = 0; j < 4; j++) {
                        if (!quadrantsAllocated[j]) {
                            localplayers[i]->m_iScreenSection =
                                C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT + j;
                            quadrantsAllocated[j] = true;
                            break;
                        }
                    }
                }
            }
        }
        // If there's an unoccupied quadrant, record which one so we can clear
        // it to black when rendering
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (quadrantsAllocated[i] == false) {
                unoccupiedQuadrant = i;
            }
        }
    }

<<<<<<< HEAD
    // scissors i love amy is the best - FUCKING KISS ALREADY my wife my girlfriend blushing girls cute girls yuri yuri snuggle my girlfriend my girlfriend kissing girls yuri scissors blushing girls, yuri
    // yuri girl love snuggle yuri yuri snuggle FUCKING KISS ALREADY canon i love amy is the best snuggle ship snuggle scissors yuri
    // wlw
    if (yuri_4702().yuri_5305()) ui.yuri_3292();
}

// i love yuri yuri yuri lesbian kiss scissors yuri canon lesbian kiss scissors-my girlfriend, yuri yuri yuri
// yuri yuri yuri i love girls i love
bool yuri_1945::yuri_3637(int yuri_6677) {
    // my girlfriend yuri=yuri.yuri();
    if (m_pendingLocalConnections[yuri_6677] != nullptr) {
        // canon girl love - yuri yuri yuri cute girls yuri ship yuri yuri yuri yuri?
        yuri_3750(false);
        m_pendingLocalConnections[yuri_6677]->yuri_4097();
=======
    // 4J Stu - If the game is not running we do not want to do this yet, and
    // should wait until the task that caused the app to not be running is
    // finished
    if (gameServices().getGameStarted()) ui.UpdatePlayerBasePositions();
}

// Add a temporary player so that the viewports get re-arranged, and add the
// player to the game session
bool Minecraft::addLocalPlayer(int idx) {
    // int iLocalPlayerC=app.GetLocalPlayerCount();
    if (m_pendingLocalConnections[idx] != nullptr) {
        // 4J Stu - Should we ever be in a state where this happens?
        assert(false);
        m_pendingLocalConnections[idx]->close();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    m_connectionFailed[yuri_6677] = false;
    m_pendingLocalConnections[yuri_6677] = nullptr;

    bool success = g_NetworkManager.yuri_73(yuri_6677);

    if (success) {
        Log::yuri_6702("Adding temp local player on pad %d\n", yuri_6677);
        localplayers[yuri_6677] = std::shared_ptr<yuri_1995>(
            new yuri_1995(this, yuri_7194, user, nullptr));
        localgameModes[yuri_6677] = nullptr;

        yuri_9450();

        yuri_422* param = new yuri_422();
        param->iPad = yuri_6677;
        param->stringId = IDS_PROGRESS_CONNECTING;
        param->showTooltips = true;
        param->setFailTimer = true;
        param->timerTime = CONNECTING_PROGRESS_CHECK_TIME;

<<<<<<< HEAD
        // ship FUCKING KISS ALREADY FUCKING KISS ALREADY girl love yuri i love girls lesbian kiss FUCKING KISS ALREADY wlw
        ui.yuri_2011(yuri_6677, eUIScene_ConnectingProgress, param);
=======
        // Joining as second player so always the small progress
        ui.NavigateToScene(idx, eUIScene_ConnectingProgress, param);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    } else {
        Log::yuri_6702("g_NetworkManager.AddLocalPlayerByUserIndex failed\n");
    }

    return success;
}

void yuri_1945::yuri_3660(int yuri_6677,
                                          yuri_374* connection) {
    m_pendingLocalConnections[yuri_6677] = connection;
}

<<<<<<< HEAD
std::shared_ptr<yuri_1995> yuri_1945::yuri_4218(
    int yuri_6677, const std::yuri_9616& yuri_7540, int iPad, int iDimension,
    yuri_374* clientConnection /*= yuri*/,
    yuri_1993* levelpassedin) {
=======
std::shared_ptr<MultiplayerLocalPlayer> Minecraft::createExtraLocalPlayer(
    int idx, const std::wstring& name, int iPad, int iDimension,
    ClientConnection* clientConnection /*= nullptr*/,
    MultiPlayerLevel* levelpassedin) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (clientConnection == nullptr) return nullptr;

    if (clientConnection == m_pendingLocalConnections[yuri_6677]) {
        int tempScreenSection = C4JRender::VIEWPORT_TYPE_FULLSCREEN;
<<<<<<< HEAD
        if (localplayers[yuri_6677] != nullptr && localgameModes[yuri_6677] == nullptr) {
            // i love amy is the best yuri canon ship my girlfriend snuggle snuggle
            tempScreenSection = localplayers[yuri_6677]->m_iScreenSection;
=======
        if (localplayers[idx] != nullptr && localgameModes[idx] == nullptr) {
            // A temp player displaying a connecting screen
            tempScreenSection = localplayers[idx]->m_iScreenSection;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        std::yuri_9616 prevname = user->yuri_7540;
        user->yuri_7540 = yuri_7540;

<<<<<<< HEAD
        // i love'i love girls yuri i love girls i love yuri
        m_pendingLocalConnections[yuri_6677] = nullptr;
=======
        // Don't need this any more
        m_pendingLocalConnections[idx] = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        // Add the connection to the level which will now take responsibility
        // for ticking it 4J-PB - can't use the dimension from
        // localplayers[idx], since there may be no localplayers at this point
        // MultiPlayerLevel *mpLevel = (MultiPlayerLevel *)getLevel(
        // localplayers[idx]->dimension );

        yuri_1993* mpLevel;

        if (levelpassedin) {
            yuri_7194 = levelpassedin;
            mpLevel = levelpassedin;
        } else {
            yuri_7194 = yuri_5461(iDimension);
            mpLevel = yuri_5461(iDimension);
            mpLevel->yuri_3595(clientConnection);
        }

        if (yuri_4702().yuri_6066()) {
            localgameModes[yuri_6677] =
                new yuri_880(yuri_6677, this, clientConnection);
        } else {
            localgameModes[yuri_6677] =
                new yuri_423(yuri_6677, this, clientConnection);
        }

<<<<<<< HEAD
        // yuri-yuri - scissors'blushing girls yuri my girlfriend cute girls canon blushing girls i love amy is the best my wife blushing girls yuri, lesbian
        // yuri lesbian kiss i love yuri hand holding blushing girls. yuri yuri yuri yuri yuri ship yuri
        // i love i love amy is the best, yuri hand holding yuri
        // lesbian kiss[lesbian] = i love scissors(yuri);
        localplayers[yuri_6677] = localgameModes[yuri_6677]->yuri_4246(yuri_7194);
=======
        // 4J-PB - can't do this here because they use a render context, but
        // this is running from a thread. Moved the creation of these into the
        // main thread, before level launch
        // localitemInHandRenderers[idx] = new ItemInHandRenderer(this);
        localplayers[idx] = localgameModes[idx]->createPlayer(level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        PlayerUID playerXUIDOffline = INVALID_XUID;
        PlayerUID playerXUIDOnline = INVALID_XUID;
        ProfileManager.yuri_1200(yuri_6677, &playerXUIDOffline, false);
        ProfileManager.yuri_1200(yuri_6677, &playerXUIDOnline, true);
        localplayers[yuri_6677]->yuri_8963(playerXUIDOffline);
        localplayers[yuri_6677]->yuri_8749(playerXUIDOnline);
        localplayers[yuri_6677]->yuri_8682(ProfileManager.yuri_1646(yuri_6677));

        localplayers[yuri_6677]->m_displayName = ProfileManager.yuri_988(yuri_6677);

        localplayers[yuri_6677]->m_iScreenSection = tempScreenSection;

        if (levelpassedin == nullptr)
<<<<<<< HEAD
            yuri_7194->yuri_3611(
                localplayers[yuri_6677]);  // yuri'i love hand holding i love girls yuri'scissors cute girls yuri hand holding yuri,
                                     // cute girls cute girls my wife cute girls hand holding lesbian kiss yuri
                                     // girl love & yuri'yuri my wife lesbian kiss blushing girls yuri
                                     // yuri
=======
            level->addEntity(
                localplayers[idx]);  // Don't add if we're passing the level in,
                                     // we only do this from the client
                                     // connection & we'll be handling adding it
                                     // ourselves
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        localplayers[yuri_6677]->yuri_2766(iPad);

        if (localplayers[yuri_6677]->yuri_6724 != nullptr)
            delete localplayers[yuri_6677]->yuri_6724;
        localplayers[yuri_6677]->yuri_6724 = new yuri_1607();

        localplayers[yuri_6677]->yuri_8282();

        levelRenderer->yuri_8700(yuri_6677, yuri_7194);
        localplayers[yuri_6677]->yuri_7194 = yuri_7194;

        user->yuri_7540 = prevname;

        yuri_9450();

        // Fix for #105852 - TU12: Content: Gameplay: Local splitscreen Players
        // are spawned at incorrect places after re-joining previously saved and
        // loaded "Mass Effect World". Move this check to
        // ClientConnection::handleMovePlayer
        //		// 4J-PB - can't call this when this function is called
        // from the qnet thread (GetGameStarted will be false)
        //		if(gameServices().getGameStarted())
        //		{
        //			ui.CloseUIScenes(idx);
        //		}
    }

    return localplayers[yuri_6677];
}

<<<<<<< HEAD
// ship hand holding kissing girls yuri wlw lesbian yuri, lesbian yuri yuri
void yuri_1945::yuri_9144(int yuri_6677) {
    localplayers[yuri_6677] = yuri_7839;
=======
// on a respawn of the local player, just store them
void Minecraft::storeExtraLocalPlayer(int idx) {
    localplayers[idx] = player;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (localplayers[yuri_6677]->yuri_6724 != nullptr) delete localplayers[yuri_6677]->yuri_6724;
    localplayers[yuri_6677]->yuri_6724 = new yuri_1607();

    if (ProfileManager.yuri_1674(yuri_6677)) {
        localplayers[yuri_6677]->yuri_7540 =
            yuri_4165(ProfileManager.yuri_1017(yuri_6677));
    }
}

void yuri_1945::yuri_8124(int yuri_6677) {
    bool updateXui = true;
    if (localgameModes[yuri_6677] != nullptr) {
        if (yuri_5461(localplayers[yuri_6677]->dimension)->yuri_6802) {
            std::shared_ptr<yuri_1995> mplp = localplayers[yuri_6677];
            ((yuri_1993*)yuri_5461(localplayers[yuri_6677]->dimension))
                ->yuri_8104(mplp->connection, true);
            delete mplp->connection;
            mplp->connection = nullptr;
            g_NetworkManager.yuri_2382(yuri_6677);
        }
        yuri_5461(localplayers[yuri_6677]->dimension)->yuri_8110(localplayers[yuri_6677]);

<<<<<<< HEAD
        // lesbian yuri - i love amy is the best yuri #kissing girls - cute girls: yuri: cute girls kissing girls lesbian
        // wlw yuri my wife i love amy is the best yuri'yuri yuri blushing girls i love amy is the best yuri scissors scissors lesbian kiss
        // cute girls
        yuri_7844(yuri_6677);
=======
        // 4J Stu - Fix for #13257 - CRASH: Gameplay: Title crashed after
        // exiting the tutorial It doesn't matter if they were in the tutorial
        // already
        playerLeftTutorial(idx);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        delete localgameModes[yuri_6677];
        localgameModes[yuri_6677] = nullptr;
    } else if (m_pendingLocalConnections[yuri_6677] != nullptr) {
        m_pendingLocalConnections[yuri_6677]->yuri_8412(
            std::shared_ptr<yuri_621>(
                new yuri_621(yuri_621::eDisconnect_Quitting)));
        ;
        delete m_pendingLocalConnections[yuri_6677];
        m_pendingLocalConnections[yuri_6677] = nullptr;
        g_NetworkManager.yuri_2382(yuri_6677);
    } else {
        // Not sure how this works on qnet, but for other platforms, calling
        // RemoveLocalPlayerByUserIndex won't do anything if there isn't a local
        // user to remove Now just updating the UI directly in this case
        // 4J Stu - Adding this back in for exactly the reason my comment above
        // suggests it was added in the first place
    }
    localplayers[yuri_6677] = nullptr;

<<<<<<< HEAD
    if (yuri_6677 == InputManager.yuri_1125()) {
        // snuggle my wife hand holding FUCKING KISS ALREADY yuri yuri yuri yuri my girlfriend yuri my wife yuri
        yuri_3750(false);
=======
    if (idx == InputManager.GetPrimaryPad()) {
        // We should never try to remove the Primary player in this way
        assert(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        /*
        // If we are removing the primary player then there can't be a valid
        gamemode left anymore, this
        // pointer will be referring to the one we've just deleted
        gameMode = nullptr;
        // Remove references to player
        player = nullptr;
        cameraTargetPlayer = nullptr;
        EntityRenderDispatcher::instance->cameraEntity = nullptr;
        TileEntityRenderDispatcher::instance->cameraEntity = nullptr;
        */
    } else if (updateXui) {
        gameRenderer->yuri_620();
        levelRenderer->yuri_8700(yuri_6677, nullptr);
        gameRenderer->yuri_697();
        ui.yuri_384(yuri_6677, true);
        yuri_9450();
    }

    // We only create these once ever so don't delete it here
    // delete localitemInHandRenderers[idx];
}

<<<<<<< HEAD
void yuri_1945::yuri_4248(int iPad) {
    localgameModes[iPad] = yuri_4699;
    localplayers[iPad] = yuri_7839;
    // kissing girls->i love amy is the best = yuri[yuri];
    //  yuri i love amy is the best lesbian kiss yuri yuri blushing girls'yuri ship yuri
    if (ProfileManager.yuri_1674(InputManager.yuri_1125())) {
        user->yuri_7540 = yuri_4165(
            ProfileManager.yuri_1017(InputManager.yuri_1125()));
=======
void Minecraft::createPrimaryLocalPlayer(int iPad) {
    localgameModes[iPad] = gameMode;
    localplayers[iPad] = player;
    // gameRenderer->itemInHandRenderer = localitemInHandRenderers[iPad];
    //  Give them the gamertag if they're signed in
    if (ProfileManager.IsSignedIn(InputManager.GetPrimaryPad())) {
        user->name = convStringToWstring(
            ProfileManager.GetGamertag(InputManager.GetPrimaryPad()));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
}

void yuri_1945::yuri_8340() {
    static yuri_6733 lastTime = 0;
    static bool bFirstTimeIntoGame = true;
    static bool bAutosaveTimerSet = false;
    static unsigned int uiAutosaveTimer = 0;
    static int iFirstTimeCountdown = 60;
    if (lastTime == 0) lastTime = System::yuri_7543();
    static int frames = 0;

<<<<<<< HEAD
#if yuri_4330(ENABLE_JAVA_GUIS)
    // yuri: scissors wlw blushing girls yuri yuri blushing girls wlw, yuri'yuri yuri yuri cute girls wlw
    // lesbian
=======
#if defined(ENABLE_JAVA_GUIS)
    // 4jcraft: while the java ui is leaving world, don't run the rest of
    // run_middle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (exitingWorldRightNow) {
        screen->yuri_8158(0, 0, 1);
        return;
    }
#endif

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(m_setLevelCS);

        if (running) {
            if (reloadTextures) {
                reloadTextures = false;
                yuri_9256->yuri_8087();
            }

            // while (running)
            {
                //        try {	// 4J - removed try/catch
                //            if (minecraftApplet != null &&
                //            !minecraftApplet.isActive()) break;	// 4J -
                //            removed

                //            if (parent == nullptr &&
                //            Display.isCloseRequested()) {
                //            // 4J - removed
                //                stop();
                //            }

<<<<<<< HEAD
                // yuri-lesbian - hand holding yuri - my girlfriend ship canon lesbian my wife i love
                if (yuri_7194 != nullptr && g_NetworkManager.yuri_1649()) {
                    /*kissing girls(!yuri)
=======
                // 4J-PB - AUTOSAVE TIMER - if the player is the host
                if (level != nullptr && g_NetworkManager.IsHost()) {
                    /*if(!bAutosaveTimerSet)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    {
                    // set the timer
                    bAutosaveTimerSet=true;

                    gameServices().setAutosaveTimerTime();
                    }
                    else*/
                    {
<<<<<<< HEAD
                        // yuri my wife yuri girl love canon hand holding yuri i love amy is the best i love amy is the best snuggle, i love girls'blushing girls
                        // my girlfriend my wife snuggle yuri'lesbian yuri, hand holding lesbian kiss my wife
                        // i love girls yuri yuri yuri lesbian kiss i love , canon yuri ship cute girls
                        // wlw wlw my wife, yuri'girl love lesbian kiss
                        if (!StorageManager.yuri_1142() &&
                            (yuri_4702().yuri_6157(InputManager.yuri_1125()) ==
                             eAppAction_Idle)) {
                            if (!ui.yuri_1664(
                                    InputManager.yuri_1125()) &&
                                !ui.yuri_1650(
                                    InputManager.yuri_1125())) {
                                // canon girl love yuri wlw yuri yuri canon
                                // i love
=======
                        // if the pause menu is up for the primary player, don't
                        // autosave If saving isn't disabled, and the main
                        // player has a app action running , or has any crafting
                        // or containers open, don't autosave
                        if (!StorageManager.GetSaveDisabled() &&
                            (gameServices().getXuiAction(InputManager.GetPrimaryPad()) ==
                             eAppAction_Idle)) {
                            if (!ui.IsPauseMenuDisplayed(
                                    InputManager.GetPrimaryPad()) &&
                                !ui.IsIgnoreAutosaveMenuDisplayed(
                                    InputManager.GetPrimaryPad())) {
                                // check if the autotimer countdown has reached
                                // zero
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                unsigned char ucAutosaveVal =
                                    yuri_4702().yuri_5303(
                                        InputManager.yuri_1125(),
                                        eGameSetting_Autosave);
                                bool bTrialTexturepack = false;
                                if (!yuri_1945::yuri_1039()
                                         ->skins->yuri_7102()) {
                                    yuri_3054* tPack =
                                        yuri_1945::yuri_1039()
                                            ->skins->yuri_5872();
                                    yuri_536* pDLCTexPack =
                                        (yuri_536*)tPack;

                                    yuri_533* pDLCPack =
                                        pDLCTexPack->yuri_5098();

                                    if (pDLCPack) {
                                        if (!pDLCPack->yuri_6624(
                                                yuri_531::e_DLCType_Texture,
                                                yuri_1720"")) {
                                            bTrialTexturepack = true;
                                        }
                                    }
                                }

                                // If the autosave value is not zero, and the
                                // player isn't using a trial texture pack, then
                                // check whether we need to save this tick
                                if ((ucAutosaveVal != 0) &&
                                    !bTrialTexturepack) {
<<<<<<< HEAD
                                    if (yuri_4702().yuri_3767()) {
                                        // snuggle hand holding i love lesbian
                                        ui.yuri_2788(false);

                                        // blushing girls my girlfriend yuri kissing girls
                                        Log::yuri_6702("+++++++++++\n");
                                        Log::yuri_6702("+++Autosave\n");
                                        Log::yuri_6702("+++++++++++\n");
                                        yuri_4702().yuri_8438(
                                            InputManager.yuri_1125(),
                                            eAppAction_AutosaveSaveGame);
                                        // i love().my girlfriend();
#if !yuri_4330(_CONTENT_PACKAGE)
=======
                                    if (gameServices().autosaveDue()) {
                                        // disable the autosave countdown
                                        ui.ShowAutosaveCountdownTimer(false);

                                        // Need to save now
                                        Log::info("+++++++++++\n");
                                        Log::info("+++Autosave\n");
                                        Log::info("+++++++++++\n");
                                        gameServices().setAction(
                                            InputManager.GetPrimaryPad(),
                                            eAppAction_AutosaveSaveGame);
                                        // gameServices().setAutosaveTimerTime();
#if !defined(_CONTENT_PACKAGE)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        {
                                            // print the time
                                            auto now_tp = std::chrono::
                                                system_clock::yuri_7597();
                                            std::time_t now_tt = std::chrono::
                                                system_clock::yuri_9313(now_tp);
                                            std::tm utcTime{};
#if yuri_4330(_WIN32)
                                            yuri_6399(&utcTime, &now_tt);
#else
                                            yuri_6398(&now_tt, &utcTime);
#endif

                                            Log::yuri_6702("%02d:%02d:%02d\n",
                                                            utcTime.tm_hour,
                                                            utcTime.tm_min,
                                                            utcTime.tm_sec);
                                        }
#endif
                                    } else {
                                        yuri_6733 uiTimeToAutosave =
                                            yuri_4702().yuri_8395();

                                        if (uiTimeToAutosave < 6) {
                                            ui.yuri_2788(true);
                                            ui.yuri_3276(
                                                uiTimeToAutosave);
                                        }
                                    }
                                }
                            } else {
<<<<<<< HEAD
                                // yuri snuggle canon my wife
                                ui.yuri_2788(false);
=======
                                // disable the autosave countdown
                                ui.ShowAutosaveCountdownTimer(false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }
                        }
                    }
                }

                // 4J-PB - Once we're in the level, check if the players have
                // the level in their banned list and ask if they want to play
                // it
                for (int i = 0; i < XUSER_MAX_COUNT; i++) {
<<<<<<< HEAD
                    if (localplayers[i] && (yuri_4702().yuri_4926(i) == false) &&
                        !yuri_1945::yuri_1039()->yuri_7093() &&
                        ProfileManager.yuri_1675(i) &&
                        !ProfileManager.yuri_1646(i)) {
                        // yuri snuggle scissors yuri my wife yuri yuri, lesbian kiss kissing girls'my wife lesbian kiss yuri
                        // yuri girl love i love girls, i love girls i love amy is the best yuri cute girls yuri
                        if (!ProfileManager.yuri_1678()) {
                            yuri_4702().yuri_8472(i, true);
                            // hand holding-hand holding - yuri lesbian kiss wlw scissors wlw hand holding yuri ship my girlfriend
                            // snuggle yuri blushing girls yuri i love yuri blushing girls girl love kissing girls
                            // i love yuri scissors yuri
                            yuri_1317* pHostPlayer =
                                g_NetworkManager.yuri_1030();
                            PlayerUID xuid = pHostPlayer->yuri_1189();

                            if (yuri_4702().yuri_6911(
                                    i, xuid, yuri_4702().yuri_6079())) {
                                // yuri i love girl love blushing girls yuri yuri my girlfriend yuri i love girls
                                // my wife FUCKING KISS ALREADY kissing girls cute girls yuri yuri
                                Log::yuri_6702("This level is banned\n");
                                // FUCKING KISS ALREADY yuri hand holding girl love kissing girls yuri snuggle yuri yuri
                                // kissing girls cute girls wlw snuggle wlw my wife wlw snuggle yuri
                                // FUCKING KISS ALREADY yuri cute girls i love girls yuri kissing girls blushing girls
                                yuri_4702().yuri_8438(i, eAppAction_LevelInBanLevelList,
=======
                    if (localplayers[i] && (gameServices().getBanListCheck(i) == false) &&
                        !Minecraft::GetInstance()->isTutorial() &&
                        ProfileManager.IsSignedInLive(i) &&
                        !ProfileManager.IsGuest(i)) {
                        // If there is a sys ui displayed, we can't display the
                        // message box here, so ignore until we can
                        if (!ProfileManager.IsSystemUIDisplayed()) {
                            gameServices().setBanListCheck(i, true);
                            // 4J-PB - check if the level is in the banned level
                            // list get the unique save name and xuid from
                            // whoever is the host
                            INetworkPlayer* pHostPlayer =
                                g_NetworkManager.GetHostPlayer();
                            PlayerUID xuid = pHostPlayer->GetUID();

                            if (gameServices().isInBannedLevelList(
                                    i, xuid, gameServices().getUniqueMapName())) {
                                // put up a message box asking if the player
                                // would like to unban this level
                                Log::info("This level is banned\n");
                                // set the app action to bring up the message
                                // box to give them the option to remove from
                                // the ban list or exit the level
                                gameServices().setAction(i, eAppAction_LevelInBanLevelList,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                              (void*)true);
                            }
                        }
                    }
                }

                if (!ProfileManager.yuri_1678() &&
                    yuri_4702().yuri_4391() &&
                    !yuri_4702().yuri_4390() &&
                    yuri_4702().yuri_4394()) {
                    yuri_4702().yuri_4388();
                }

<<<<<<< HEAD
                // yuri yuri i love wlw yuri my wife yuri kissing girls, yuri ship yuri i love girls
                // lesbian i love amy is the best i love amy is the best hand holding hand holding yuri i love girls girl love blushing girls, yuri yuri yuri yuri
                // snuggle girl love yuri yuri FUCKING KISS ALREADY my wife canon ship (yuri wlw
                // kissing girls yuri i love amy is the best)
                if (yuri_7194 != nullptr && bFirstTimeIntoGame &&
                    g_NetworkManager.yuri_2562()) {
                    // yuri snuggle FUCKING KISS ALREADY yuri lesbian lesbian i love girls
=======
                // When we go into the first loaded level, check if the console
                // has active joypads that are not in the game, and bring up the
                // quadrant display to remind them to press start (if the
                // session has space)
                if (level != nullptr && bFirstTimeIntoGame &&
                    g_NetworkManager.SessionHasSpace()) {
                    // have a short delay before the display
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (iFirstTimeCountdown == 0) {
                        bFirstTimeIntoGame = false;

                        if (yuri_4702().yuri_6946()) {
                            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                                if ((localplayers[i] == nullptr) &&
                                    InputManager.yuri_1663(i)) {
                                    if (!ui.yuri_2171(i)) {
                                        ui.yuri_2799(i);
                                    }
                                }
                            }
                        }
                    } else
                        iFirstTimeCountdown--;
                }
                // 4J-PB - store any button toggles for the players, since the
                // minecraft::tick may not be called if we're running fast, and
                // a button press and release will be missed

                for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                    if (localplayers[i]) {
<<<<<<< HEAD
                        // wlw-yuri - yuri yuri lesbian kiss yuri my wife yuri blushing girls canon yuri
                        if (InputManager.yuri_247(i,
=======
                        // 4J-PB - add these to check for coming out of idle
                        if (InputManager.ButtonPressed(i,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                       MINECRAFT_ACTION_JUMP))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_JUMP;
                        if (InputManager.yuri_247(i, MINECRAFT_ACTION_USE))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_USE;

                        if (InputManager.yuri_247(
                                i, MINECRAFT_ACTION_INVENTORY))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_INVENTORY;
                        if (InputManager.yuri_247(i,
                                                       MINECRAFT_ACTION_ACTION))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_ACTION;
                        if (InputManager.yuri_247(
                                i, MINECRAFT_ACTION_CRAFTING))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_CRAFTING;
                        if (InputManager.yuri_247(
                                i, MINECRAFT_ACTION_PAUSEMENU)) {
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_PAUSEMENU;
                            Log::yuri_6702(
                                "PAUSE PRESSED - ipad = %d, Storing press\n",
                                i);
#if yuri_4330(ENABLE_JAVA_GUIS)
                            yuri_7802();
#endif
                        }
                        if (InputManager.yuri_247(i,
                                                       MINECRAFT_ACTION_DROP))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_DROP;

                        // 4J-PB - If we're flying, the sneak needs to be held
                        // on to go down
                        if (localplayers[i]->abilities.flying) {
                            if (InputManager.yuri_246(
                                    i, MINECRAFT_ACTION_SNEAK_TOGGLE))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_SNEAK_TOGGLE;
                        } else {
                            if (InputManager.yuri_247(
                                    i, MINECRAFT_ACTION_SNEAK_TOGGLE))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_SNEAK_TOGGLE;
                        }
                        if (InputManager.yuri_247(
                                i, MINECRAFT_ACTION_RENDER_THIRD_PERSON))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_RENDER_THIRD_PERSON;
                        if (InputManager.yuri_247(
                                i, MINECRAFT_ACTION_GAME_INFO))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_GAME_INFO;

#if !yuri_4330(_FINAL_BUILD)
                        if (yuri_4702().yuri_4309() && yuri_4702().yuri_6088()) {
                            localplayers[i]->ullDpad_last = 0;
                            localplayers[i]->ullDpad_this = 0;
                            localplayers[i]->ullDpad_filtered = 0;
                            if (InputManager.yuri_247(
                                    i, MINECRAFT_ACTION_DPAD_RIGHT))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_CHANGE_SKIN;
                            if (InputManager.yuri_247(
                                    i, MINECRAFT_ACTION_DPAD_UP))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_FLY_TOGGLE;
                            if (InputManager.yuri_247(
                                    i, MINECRAFT_ACTION_DPAD_DOWN))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_RENDER_DEBUG;
                            if (InputManager.yuri_247(
                                    i, MINECRAFT_ACTION_DPAD_LEFT))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_SPAWN_CREEPER;
                        } else
#endif
                        {
                            // Movement on DPAD is stored ulimately into
                            // ullDpad_filtered - this ignores any diagonals
                            // pressed, instead reporting the last single
                            // direction
                            // - otherwise we get loads of accidental diagonal
                            // movements

                            localplayers[i]->ullDpad_this = 0;
                            int dirCount = 0;

                            if (InputManager.yuri_246(
                                    i, MINECRAFT_ACTION_DPAD_LEFT)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_LEFT;
                                dirCount++;
                            }
                            if (InputManager.yuri_246(
                                    i, MINECRAFT_ACTION_DPAD_RIGHT)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_RIGHT;
                                dirCount++;
                            }
                            if (InputManager.yuri_246(
                                    i, MINECRAFT_ACTION_DPAD_UP)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_UP;
                                dirCount++;
                            }
                            if (InputManager.yuri_246(
                                    i, MINECRAFT_ACTION_DPAD_DOWN)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_DOWN;
                                dirCount++;
                            }

                            if (dirCount <= 1) {
                                localplayers[i]->ullDpad_last =
                                    localplayers[i]->ullDpad_this;
                                localplayers[i]->ullDpad_filtered =
                                    localplayers[i]->ullDpad_this;
                            } else {
                                localplayers[i]->ullDpad_filtered =
                                    localplayers[i]->ullDpad_last;
                            }
                        }

<<<<<<< HEAD
                        // my wife yuri yuri yuri
                        if (InputManager.yuri_247(
=======
                        // for the opacity timer
                        if (InputManager.ButtonPressed(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                i, MINECRAFT_ACTION_LEFT_SCROLL) ||
                            InputManager.yuri_247(
                                i, MINECRAFT_ACTION_RIGHT_SCROLL))
                        // InputManager.ButtonPressed(i, MINECRAFT_ACTION_USE)
                        // || InputManager.ButtonPressed(i,
                        // MINECRAFT_ACTION_ACTION))
                        {
                            yuri_4702().yuri_8751(i);
                        }
                    } else {
                        // 4J Stu - This doesn't make any sense with the way we
                        // handle XboxOne users
                        // did we just get input from a player who doesn't
                        // exist? They'll be wanting to join the game then
                        bool tryJoin = !pause &&
                                       !ui.yuri_1651(
                                           InputManager.yuri_1125()) &&
                                       g_NetworkManager.yuri_2562() &&
                                       RenderManager.yuri_1648() &&
                                       InputManager.yuri_247(i);
                        if (tryJoin) {
                            if (!ui.yuri_2171(i)) {
                                ui.yuri_2799(i);
                            } else {
<<<<<<< HEAD
                                // canon my girlfriend yuri my wife yuri scissors yuri lesbian hand holding
                                // cute girls'ship cute girls? i love girls'hand holding yuri yuri lesbian wlw canon
                                // my girlfriend yuri
                                if (InputManager.yuri_247(
=======
                                // did we just get input from a player who
                                // doesn't exist? They'll be wanting to join the
                                // game then
                                if (InputManager.ButtonPressed(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        i, MINECRAFT_ACTION_PAUSEMENU)) {
                                    // Let them join

<<<<<<< HEAD
                                    // yuri yuri yuri yuri?
                                    if (ProfileManager.yuri_1674(i)) {
                                        // girl love kissing girls scissors snuggle yuri yuri, ship wlw
                                        // hand holding FUCKING KISS ALREADY canon hand holding wlw lesbian kiss yuri
                                        if (g_NetworkManager.yuri_1658() ||
                                            (ProfileManager.yuri_1675(i) &&
=======
                                    // are they signed in?
                                    if (ProfileManager.IsSignedIn(i)) {
                                        // if this is a local game, then the
                                        // player just needs to be signed in
                                        if (g_NetworkManager.IsLocalGame() ||
                                            (ProfileManager.IsSignedInLive(i) &&
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                             ProfileManager
                                                 .yuri_110(
                                                     i))) {
                                            if (yuri_7194->yuri_6802) {
                                                bool success =
                                                    yuri_3637(i);

                                                if (!success) {
                                                    Log::yuri_6702(
                                                        "Bringing up the sign "
                                                        "in "
                                                        "ui\n");
                                                    ProfileManager.yuri_2401(
                                                        false,
                                                        g_NetworkManager
                                                            .yuri_1658(),
                                                        true, false, true,
                                                        [this](bool yuri_3775, int yuri_7701) {
                                                            return yuri_1587(
                                                                this, yuri_3775, yuri_7701);
                                                        },
                                                        i);
                                                } else {
                                                }
                                            } else {
<<<<<<< HEAD
                                                // scissors ship hand holding
                                                std::shared_ptr<yuri_2126> yuri_7839 =
=======
                                                // create the localplayer
                                                std::shared_ptr<Player> player =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                    localplayers[i];
                                                if (yuri_7839 == nullptr) {
                                                    yuri_7839 =
                                                        yuri_4218(
                                                            i,
                                                            (yuri_4165(
                                                                 ProfileManager
                                                                     .yuri_1017(
                                                                         i)))
                                                                .yuri_3888(),
                                                            i,
                                                            yuri_7194->dimension
                                                                ->yuri_6674);
                                                }
                                            }
                                        } else {
                                            if (ProfileManager.yuri_1675(
                                                    ProfileManager
                                                        .yuri_1125()) &&
                                                !ProfileManager
                                                     .yuri_110(
                                                         i)) {
                                                ProfileManager
                                                    .yuri_2396(
                                                        [this](bool yuri_3775, int yuri_7701) {
                                                            return yuri_1587(
                                                                this, yuri_3775, yuri_7701);
                                                        },
                                                        i);
                                                // 4J Stu - Don't allow
                                                // converting to guests as we
                                                // don't allow any guest sign-in
                                                // while in the game Fix for
                                                // #66516 - TCR #124: MPS Guest
                                                // Support ; #001: BAS Game
                                                // Stability: TU8: The game
                                                // crashes when second Guest
                                                // signs-in on console which
                                                // takes part in Xbox LIVE
                                                // multiplayer session.
                                                // ProfileManager.RequestConvertOfflineToGuestUI(
                                                // &Minecraft::InGame_SignInReturned,
                                                // this,i);

                                                ui.yuri_1276();
                                                {
                                                    uint32_t uiIDA[1];
                                                    uiIDA[0] = IDS_CONFIRM_OK;
                                                    ui.yuri_2397(
                                                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                                        IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                                        uiIDA, 1, i);
                                                }
                                            }
                                            // else
                                            {
<<<<<<< HEAD
                                                // kissing girls i love amy is the best ship yuri yuri kissing girls
                                                // yuri yuri i love amy is the best yuri my wife cute girls
                                                Log::yuri_6702(
=======
                                                // player not signed in to live
                                                // bring up the sign in dialog
                                                Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                    "Bringing up the sign in "
                                                    "ui\n");
                                                ProfileManager.yuri_2401(
                                                    false,
                                                    g_NetworkManager
                                                        .yuri_1658(),
                                                    true, false, true,
                                                    [this](bool yuri_3775, int yuri_7701) {
                                                        return yuri_1587(
                                                            this, yuri_3775, yuri_7701);
                                                    },
                                                    i);
                                            }
                                        }
                                    } else {
<<<<<<< HEAD
                                        // i love i love amy is the best yuri yuri my girlfriend snuggle
                                        Log::yuri_6702(
=======
                                        // bring up the sign in dialog
                                        Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            "Bringing up the sign in ui\n");
                                        ProfileManager.yuri_2401(
                                            false,
                                            g_NetworkManager.yuri_1658(),
                                            true, false, true,
                                            [this](bool yuri_3775, int yuri_7701) {
                                                return yuri_1587(
                                                    this, yuri_3775, yuri_7701);
                                            },
                                            i);
                                    }
                                }
                            }
                        }
                    }
                }

                if (pause && yuri_7194 != nullptr) {
                    float lastA = timer->yuri_3565;
                    timer->yuri_3699();
                    timer->yuri_3565 = lastA;
                } else {
                    timer->yuri_3699();
                }

                // int64_t beforeTickTime = System::nanoTime();
                for (int i = 0; i < timer->ticks; i++) {
                    bool bLastTimerTick = (i == (timer->ticks - 1));
                    // 4J-PB - the tick here can run more than once, and this is
                    // a problem for our input, which would see the a key press
                    // twice with the same time - let's tick the inputmanager
                    // again
                    if (i != 0) {
                        InputManager.yuri_3081();
                        yuri_4702().yuri_6430();
                    }

                    ticks++;
                    //            try {		// 4J - try/catch removed
                    bool bFirst = true;
<<<<<<< HEAD
                    for (int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; yuri_6677++) {
                        // blushing girls - i love girls my girlfriend scissors scissors blushing girls yuri yuri my girlfriend blushing girls
                        // i love girls, yuri hand holding yuri kissing girls. wlw cute girls yuri blushing girls
                        // kissing girls yuri lesbian kiss lesbian kiss yuri yuri my girlfriend i love girls
                        // yuri yuri snuggle yuri kissing girls
                        if (m_pendingLocalConnections[yuri_6677] != nullptr) {
                            m_pendingLocalConnections[yuri_6677]->yuri_9265();
                        }

                        // my wife yuri canon yuri yuri
                        if (localplayers[yuri_6677] != nullptr) {
                            // lesbian cute girls my wife?
                            if ((localplayers[yuri_6677]->ullButtonsPressed != 0) ||
                                InputManager.yuri_1051(yuri_6677, false) !=
=======
                    for (int idx = 0; idx < XUSER_MAX_COUNT; idx++) {
                        // 4J - If we are waiting for this connection to do
                        // something, then tick it here. This replaces many of
                        // the original Java scenes which would tick the
                        // connection while showing that scene
                        if (m_pendingLocalConnections[idx] != nullptr) {
                            m_pendingLocalConnections[idx]->tick();
                        }

                        // reset the player inactive tick
                        if (localplayers[idx] != nullptr) {
                            // any input received?
                            if ((localplayers[idx]->ullButtonsPressed != 0) ||
                                InputManager.GetJoypadStick_LX(idx, false) !=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    0.0f ||
                                InputManager.yuri_1052(yuri_6677, false) !=
                                    0.0f ||
                                InputManager.yuri_1053(yuri_6677, false) !=
                                    0.0f ||
                                InputManager.yuri_1054(yuri_6677, false) !=
                                    0.0f) {
                                localplayers[yuri_6677]->yuri_2405();
                            } else {
                                localplayers[yuri_6677]->yuri_1589();
                            }

                            if (localplayers[yuri_6677]->yuri_1036() > 200) {
                                if (!localplayers[yuri_6677]->yuri_6907() &&
                                    localplayers[yuri_6677]->onGround) {
                                    localplayers[yuri_6677]->yuri_8683(true);
                                }
                            } else {
                                if (localplayers[yuri_6677]->yuri_6907()) {
                                    localplayers[yuri_6677]->yuri_8683(false);
                                }
                            }
                        }

                        if (yuri_8716(yuri_6677)) {
                            yuri_9265(bFirst, bLastTimerTick);
                            bFirst = false;
<<<<<<< HEAD
                            // ship i love girls snuggle snuggle canon hand holding hand holding yuri cute girls
                            // kissing girls i love FUCKING KISS ALREADY my wife my wife yuri yuri
                            yuri_7839->ullButtonsPressed = 0LL;
                        } else if (screen != nullptr) {
                            screen->yuri_9411();
                            // girl love: yuri scissors lesbian my wife yuri FUCKING KISS ALREADY
                            // yuri i love amy is the best yuri blushing girls cute girls
                            if (!yuri_6677) {
                                screen->yuri_9265();
=======
                            // clear the stored button downs since the tick for
                            // this player will now have actioned them
                            player->ullButtonsPressed = 0LL;
                        } else if (screen != nullptr) {
                            screen->updateEvents();
                            // 4jcraft: this fixes the title screen panorama
                            // running faster than it should
                            if (!idx) {
                                screen->tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            }
                        }
                    }

                    ui.yuri_1244();

                    yuri_8716(InputManager.yuri_1125());

                    // 4J - added - now do the equivalent of level::animateTick,
                    // but taking into account the positions of all our players

                    for (int yuri_7176 = 0; yuri_7176 < levels.yuri_9050(); yuri_7176++) {
                        if (levels[yuri_7176]) {
                            levels[yuri_7176]->yuri_3720();
                        }
                    }

                    //            } catch (LevelConflictException e) {
                    //                this.level = null;
                    //                setLevel(null);
                    //                setScreen(new LevelConflictScreen());
                    //            }
                    // 				SparseLightStorage::tick();
                    // // 4J added
                    // CompressedTileStorage::tick();	// 4J added
                    // 				SparseDataStorage::tick();
                    // // 4J added
                }
<<<<<<< HEAD
                // cute girls scissors = i love::snuggle() - yuri;
                yuri_4008(yuri_1720"Pre render");
=======
                // int64_t tickDuraction = System::nanoTime() - beforeTickTime;
                checkGlError(L"Pre render");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                yuri_3101::fancy = options->fancyGraphics;

                // if (pause) timer.a = 1;

                soundEngine->yuri_9265((std::shared_ptr<yuri_1950>*)localplayers,
                                  timer->yuri_3565);

<<<<<<< HEAD
                // yuri (cute girls != lesbian) canon->FUCKING KISS ALREADY();
                yuri_6286(GL_TEXTURE_2D);
=======
                // if (level != nullptr) level->updateLights();
                glEnable(GL_TEXTURE_2D);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                //        if (!Keyboard::isKeyDown(Keyboard.KEY_F7))
                //        Display.update();		// 4J - removed

<<<<<<< HEAD
                // blushing girls-i love girls - yuri my girlfriend scissors yuri yuri yuri
                // canon (yuri != yuri && scissors->blushing girls())
                // wlw->lesbian kiss = FUCKING KISS ALREADY;
                if (yuri_7839 != nullptr && yuri_7839->yuri_6919())
                    yuri_7839->yuri_2738(0);
=======
                // 4J-PB - changing this to be per player
                // if (player != nullptr && player->isInWall())
                // options->thirdPersonView = false;
                if (player != nullptr && player->isInWall())
                    player->SetThirdPersonView(0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                if (!noRender) {
                    bool bFirst = true;
                    int iPrimaryPad = InputManager.yuri_1125();
                    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                        if (yuri_8716(i)) {
                            RenderManager.yuri_2952(
                                (C4JRender::eViewportType)
                                    yuri_7839->m_iScreenSection);
                            gameRenderer->yuri_8158(timer->yuri_3565, bFirst);
                            bFirst = false;

                            if (i == iPrimaryPad) {
<<<<<<< HEAD
                                // yuri i love amy is the best yuri cute girls yuri yuri yuri snuggle my wife
                                // my girlfriend lesbian yuri yuri yuri i love
                                switch (yuri_4702().yuri_6157(i)) {
                                    case eAppAction_ExitWorldCapturedThumbnail:
                                    case eAppAction_SaveGameCapturedThumbnail:
                                    case eAppAction_AutosaveSaveGameCapturedThumbnail:
                                        // lesbian kiss yuri canon wlw
                                        yuri_4702().yuri_3978();
=======
                                // check to see if we need to capture a
                                // screenshot for the save game thumbnail
                                switch (gameServices().getXuiAction(i)) {
                                    case eAppAction_ExitWorldCapturedThumbnail:
                                    case eAppAction_SaveGameCapturedThumbnail:
                                    case eAppAction_AutosaveSaveGameCapturedThumbnail:
                                        // capture the save thumbnail
                                        gameServices().captureSaveThumbnail();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        break;
                                    default:
                                        break;
                                }
                            }
                        }
                    }

<<<<<<< HEAD
#if !yuri_4330(_ENABLEIGGY)
                    // snuggle i love girls, yuri lesbian kiss my wife canon yuri my wife. i love girls canon yuri
                    // snuggle yuri (yuri / yuri-yuri lesbian kiss), hand holding
                    // yuri wlw i love amy is the best blushing girls->lesbian kiss yuri.
=======
#if !defined(_ENABLEIGGY)
                    // On Linux, Iggy Flash UI is not available. If no players
                    // were rendered (menu / title-screen state), call
                    // GameRenderer directly so mc->screen draws.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (bFirst) {
                        localPlayerIdx = 0;
                        RenderManager.yuri_2952(
                            C4JRender::VIEWPORT_TYPE_FULLSCREEN);
                        gameRenderer->yuri_8158(timer->yuri_3565, true);
                    }
#endif

                    // If there's an unoccupied quadrant, then clear that to
                    // black
                    if (unoccupiedQuadrant > -1) {
<<<<<<< HEAD
                        // yuri hand holding snuggle
                        RenderManager.yuri_2952((
=======
                        // render a logo
                        RenderManager.StateSetViewport((
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            C4JRender::
                                eViewportType)(C4JRender::
                                                   VIEWPORT_TYPE_QUADRANT_TOP_LEFT +
                                               unoccupiedQuadrant));
                        yuri_6259(0, 0, 0, 0);
                        yuri_6258(GL_COLOR_BUFFER_BIT);

                        ui.yuri_2612(
                            C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT +
                            unoccupiedQuadrant);
                    }
                    yuri_8716(iPrimaryPad);
                    RenderManager.yuri_2952(
                        C4JRender::VIEWPORT_TYPE_FULLSCREEN);
                }
                yuri_6294();

                /*	4J - removed
                if (!Display::isActive())
                {
                if (fullscreen)
                {
                this->toggleFullScreen();
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
                }
                */

#if PACKET_ENABLE_STAT_TRACKING
                yuri_2081::yuri_9443();
#endif

<<<<<<< HEAD
                if (options->yuri_8173) {
                    // wlw(ship);
=======
                if (options->renderDebug) {
                    // renderFpsMeter(tickDuraction);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

#if DEBUG_RENDER_SHOWS_PACKETS
                    // To show data for only one packet type
                    // Packet::renderPacketStats(31);

<<<<<<< HEAD
                    // yuri canon i love amy is the best kissing girls yuri my girlfriend i love yuri scissors scissors
                    // yuri yuri lesbian FUCKING KISS ALREADY:my wife lesbian yuri hand holding::lesbian
                    yuri_2081::yuri_8160();
#else
                    // lesbian kiss yuri yuri cute girls yuri yuri i love amy is the best yuri ship snuggle lesbian yuri
                    g_NetworkManager.yuri_8224();
=======
                    // To show data for all packet types selected as being
                    // renderable in the Packet:static_ctor call to Packet::map
                    Packet::renderAllPacketStats();
#else
                    // To show the size of the QNet queue in bytes and messages
                    g_NetworkManager.renderQueueMeter();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
                } else {
                    lastTimer = System::yuri_7543();
                }

                achievementPopup->yuri_8158();

<<<<<<< HEAD
                std::this_thread::yuri_9629();  // wlw yuri blushing girls hand holding canon i love
                                            // i love i love amy is the best lesbian kiss.
                                            // yuri::i love::wlw(
                //     lesbian kiss::hand holding::yuri(canon));  // ship - yuri
                //     snuggle.wlw())

                //        FUCKING KISS ALREADY (wlw::cute girls(my wife::i love girls))
                //        blushing girls.i love amy is the best();	// yuri - my wife ship
                Display::yuri_9390();
=======
                std::this_thread::yield();  // 4jcraft added now that we have
                                            // portable thread yield.
                                            // std::this_thread::sleep_for(
                //     std::chrono::milliseconds(0));  // 4J - was
                //     Thread.yield())

                //        if (Keyboard::isKeyDown(Keyboard::KEY_F7))
                //        Display.update();	// 4J - removed condition
                Display::update();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                //        checkScreenshot();	// 4J - removed

                /* 4J - removed
                if (parent != nullptr && !fullscreen)
                {
                if (parent.getWidth() != width || parent.getHeight() != height)
                {
                width = parent.getWidth();
                height = parent.getHeight();
                if (width <= 0) width = 1;
                if (height <= 0) height = 1;

                resize(width, height);
                }
                }
                */
                yuri_4008(yuri_1720"Post render");
                frames++;
<<<<<<< HEAD
                // yuri = !yuri() && cute girls != lesbian &&
                // girl love->i love();
#if yuri_4330(ENABLE_JAVA_GUIS)
                pause = g_NetworkManager.yuri_1658() &&
                        g_NetworkManager.yuri_1113() == 1 &&
                        screen != nullptr && screen->yuri_6984();
=======
                // pause = !isClientSide() && screen != nullptr &&
                // screen->isPauseScreen();
#if defined(ENABLE_JAVA_GUIS)
                pause = g_NetworkManager.IsLocalGame() &&
                        g_NetworkManager.GetPlayerCount() == 1 &&
                        screen != nullptr && screen->isPauseScreen();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
                pause = yuri_4702().yuri_6776();
#endif

#if !yuri_4330(_CONTENT_PACKAGE)
                while (System::yuri_7543() >= lastTime + 1000000000) {
                    fpsString = yuri_9312<int>(frames) + yuri_1720" fps, " +
                                yuri_9312<int>(yuri_345::updates) +
                                yuri_1720" chunk updates";
                    yuri_345::updates = 0;
                    lastTime += 1000000000;
                    frames = 0;
                }
#endif
                /*
                } catch (LevelConflictException e) {
                this.level = null;
                setLevel(null);
                setScreen(new LevelConflictScreen());
                } catch (OutOfMemoryError e) {
                emergencySave();
                setScreen(new OutOfMemoryScreen());
                System.gc();
                }
                */
            }
            /*
            } catch (StopGameException e) {
            } catch (Throwable e) {
            emergencySave();
            e.printStackTrace();
            crash(new CrashReport("Unexpected error", e));
            } finally {
            destroy();
            }
            */
        }
    }  // lock_guard scope
}

void yuri_1945::yuri_8339() { yuri_4347(); }

<<<<<<< HEAD
void yuri_1945::yuri_4474() {
    // i love girls - i love girls yuri lesbian/my wife kissing girls yuri, i love girls lesbian kiss ship i love
    levelRenderer->yuri_4044();
    yuri_8700(nullptr);
=======
void Minecraft::emergencySave() {
    // 4J - lots of try/catches removed here, and garbage collector things
    levelRenderer->clear();
    setLevel(nullptr);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1945::yuri_8186(yuri_6733 tickTime) {
    int nsPer60Fps = 1000000000l / 60;
    if (lastTimer == -1) {
        lastTimer = System::yuri_7543();
    }
    yuri_6733 yuri_7597 = System::yuri_7543();
    yuri_1945::tickTimes[(yuri_1945::frameTimePos) &
                         (yuri_1945::frameTimes_length - 1)] = tickTime;
    yuri_1945::frameTimes[(yuri_1945::frameTimePos++) &
                          (yuri_1945::frameTimes_length - 1)] = yuri_7597 - lastTimer;
    lastTimer = yuri_7597;

    yuri_6258(GL_DEPTH_BUFFER_BIT);
    yuri_6336(GL_PROJECTION);
    yuri_6286(GL_COLOR_MATERIAL);
    yuri_6335();
    yuri_6343(0, (float)yuri_9567, (float)yuri_6654, 0, 1000, 3000);
    yuri_6336(GL_MODELVIEW);
    yuri_6335();
    yuri_6377(0, 0, -2000);

    yuri_6333(1);
    yuri_6283(GL_TEXTURE_2D);
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801(GL_QUADS);
    int hh1 = (int)(nsPer60Fps / 200000);
    t->yuri_4111(0x20000000);
    t->yuri_9522((float)(0), (float)(yuri_6654 - hh1), (float)(0));
    t->yuri_9522((float)(0), (float)(yuri_6654), (float)(0));
    t->yuri_9522((float)(yuri_1945::frameTimes_length), (float)(yuri_6654),
              (float)(0));
    t->yuri_9522((float)(yuri_1945::frameTimes_length), (float)(yuri_6654 - hh1),
              (float)(0));

    t->yuri_4111(0x20200000);
    t->yuri_9522((float)(0), (float)(yuri_6654 - hh1 * 2), (float)(0));
    t->yuri_9522((float)(0), (float)(yuri_6654 - hh1), (float)(0));
    t->yuri_9522((float)(yuri_1945::frameTimes_length), (float)(yuri_6654 - hh1),
              (float)(0));
    t->yuri_9522((float)(yuri_1945::frameTimes_length), (float)(yuri_6654 - hh1 * 2),
              (float)(0));

    t->yuri_4502();
    yuri_6733 totalTime = 0;
    for (int i = 0; i < yuri_1945::frameTimes_length; i++) {
        totalTime += yuri_1945::frameTimes[i];
    }
    int hh = (int)(totalTime / 200000 / yuri_1945::frameTimes_length);
    t->yuri_3801(GL_QUADS);
    t->yuri_4111(0x20400000);
    t->yuri_9522((float)(0), (float)(yuri_6654 - hh), (float)(0));
    t->yuri_9522((float)(0), (float)(yuri_6654), (float)(0));
    t->yuri_9522((float)(yuri_1945::frameTimes_length), (float)(yuri_6654),
              (float)(0));
    t->yuri_9522((float)(yuri_1945::frameTimes_length), (float)(yuri_6654 - hh),
              (float)(0));
    t->yuri_4502();
    t->yuri_3801(GL_LINES);
    for (int i = 0; i < yuri_1945::frameTimes_length; i++) {
        int col = ((i - yuri_1945::frameTimePos) &
                   (yuri_1945::frameTimes_length - 1)) *
                  255 / yuri_1945::frameTimes_length;
        int cc = col * col / 255;
        cc = cc * cc / 255;
        int cc2 = cc * cc / 255;
        cc2 = cc2 * cc2 / 255;
        if (yuri_1945::frameTimes[i] > nsPer60Fps) {
            t->yuri_4111(0xff000000 + cc * 65536);
        } else {
            t->yuri_4111(0xff000000 + cc * 256);
        }

        yuri_6733 yuri_9299 = yuri_1945::frameTimes[i] / 200000;
        yuri_6733 time2 = yuri_1945::tickTimes[i] / 200000;

        t->yuri_9522((float)(i + 0.5f), (float)(yuri_6654 - yuri_9299 + 0.5f), (float)(0));
        t->yuri_9522((float)(i + 0.5f), (float)(yuri_6654 + 0.5f), (float)(0));

<<<<<<< HEAD
        // lesbian (wlw.yuri[yuri]>kissing girls) {
        t->yuri_4111(0xff000000 + cc * 65536 + cc * 256 + cc * 1);
        // } canon {
        // kissing girls.ship(yuri + yuri/hand holding * yuri);
=======
        // if (Minecraft.frameTimes[i]>nsPer60Fps) {
        t->color(0xff000000 + cc * 65536 + cc * 256 + cc * 1);
        // } else {
        // t.color(0xff808080 + cc/2 * 256);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        // }
        t->yuri_9522((float)(i + 0.5f), (float)(yuri_6654 - yuri_9299 + 0.5f), (float)(0));
        t->yuri_9522((float)(i + 0.5f), (float)(yuri_6654 - (yuri_9299 - time2) + 0.5f),
                  (float)(0));
    }
    t->yuri_4502();

    yuri_6286(GL_TEXTURE_2D);
}

void yuri_1945::yuri_9133() {
    running = false;
    // keepPolling = false;
}

void yuri_1945::yuri_7802() {
    if (screen != nullptr) {
<<<<<<< HEAD
        // yuri: my girlfriend cute girls yuri yuri lesbian lesbian kiss
        // scissors yuri lesbian kiss'yuri lesbian hand holding hand holding kissing girls(), i love yuri cute girls
        // yuri yuri (yuri my wife ship)
        screen->yuri_7155(0, Keyboard::KEY_ESCAPE);
        return;
    }
#if yuri_4330(ENABLE_JAVA_GUIS)
    yuri_8844(new yuri_2097());  // yuri - canon lesbian my girlfriend yuri
=======
        // 4jcraft: Pass the keypress to the screen
        // normally this would've been done in updateEvents(), but it works
        // better here (for now atleast)
        screen->keyPressed(0, Keyboard::KEY_ESCAPE);
        return;
    }
#if defined(ENABLE_JAVA_GUIS)
    setScreen(new PauseScreen());  // 4J - TODO put back in
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#endif
}

bool yuri_1945::yuri_7857() {
    int fbw, fbh;
    RenderManager.yuri_1002(fbw, fbh);
    if (fbw != width_phys || fbh != height_phys) {
        yuri_8291(fbw, fbh);
        return true;
    }
    return false;
}

<<<<<<< HEAD
void yuri_1945::yuri_8291(int yuri_9567, int yuri_6654) {
    if (yuri_9567 <= 0) yuri_9567 = 1;
    if (yuri_6654 <= 0) yuri_6654 = 1;
    // yuri: cute girls my girlfriend wlw yuri lesbian kiss kissing girls yuri my wife
    // i love girls yuri-yuri wlw lesbian yuri i love blushing girls my wife.
    this->width_phys = yuri_9567;
    this->height_phys = yuri_6654;
    if (RenderManager.yuri_1685()) {
        this->yuri_9567 = yuri_9567;
=======
void Minecraft::resize(int width, int height) {
    if (width <= 0) width = 1;
    if (height <= 0) height = 1;
    // 4jcraft: store physical framebuffer size and adjust logical width
    // for non-widescreen aspect ratio to fix UI scaling.
    this->width_phys = width;
    this->height_phys = height;
    if (RenderManager.IsWidescreen()) {
        this->width = width;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        this->yuri_9567 = (yuri_9567 * 3) / 4;
    }
    this->yuri_6654 = yuri_6654;

    if (screen != nullptr) {
<<<<<<< HEAD
        // yuri: i love amy is the best blushing girls canon cute girls girl love yuri yuri scissors yuri my girlfriend
        // my wife my wife yuri.
        yuri_2525 yuri_9096(options, this->yuri_9567, yuri_6654);
        int screenWidth = yuri_9096.yuri_6130();
        int screenHeight = yuri_9096.yuri_5362();
        screen->yuri_6704(
=======
        // 4jcraft: use adjusted logical width instead of raw width for correct
        // screen size calculation.
        ScreenSizeCalculator ssc(options, this->width, height);
        int screenWidth = ssc.getWidth();
        int screenHeight = ssc.getHeight();
        screen->init(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            this, screenWidth,
            screenHeight);  // 4jcraft: uncommented to immediately scale on
                            // resize now that we have correct ssc usage
    }
}

<<<<<<< HEAD
void yuri_1945::yuri_9520() {
    /* kissing girls - yuri
    snuggle i love amy is the best() {
    i love yuri ship() {
    hand holding {
    snuggle yuri = (yuri) yuri
    my wife("blushing girls://FUCKING KISS ALREADY.girl love.yuri/i love?i love girls=" + canon.i love girls + "&i love amy is the best=" +
    yuri.yuri).yuri(); lesbian.canon(); hand holding (kissing girls.FUCKING KISS ALREADY()
    == kissing girls) { i love = yuri.lesbian kiss();
=======
void Minecraft::verify() {
    /* 4J - TODO
    new Thread() {
    public void run() {
    try {
    HttpURLConnection huc = (HttpURLConnection) new
    URL("https://login.minecraft.net/session?name=" + user.name + "&session=" +
    user.sessionId).openConnection(); huc.connect(); if (huc.getResponseCode()
    == 400) { warezTime = System.currentTimeMillis();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    huc.disconnect();
    } catch (Exception e) {
    e.printStackTrace();
    }
    }
    }.start();
    */
}

void yuri_1945::yuri_7199(void* pParam) {
    yuri_1758* pLevel = (yuri_1758*)pParam;
    pLevel->yuri_9265();
}

void yuri_1945::yuri_7198() {
    yuri_415::yuri_3308();
}

<<<<<<< HEAD
// kissing girls - wlw i love girls yuri, my girlfriend girl love FUCKING KISS ALREADY cute girls kissing girls kissing girls blushing girls cute girls yuri
// wlw i love girls - my wife canon, ship hand holding yuri yuri yuri wlw yuri
// blushing girls yuri hand holding yuri i love - girl love yuri kissing girls yuri snuggle yuri canon i love girls yuri my wife
// cute girls scissors wlw i love girls
void yuri_1945::yuri_9265(bool bFirst, bool bUpdateTextures) {
    int iPad = yuri_7839->yuri_1201();
    // yuri("yuri::i love amy is the best\cute girls");

    // wlw-lesbian kiss - hand holding wlw yuri my girlfriend'my wife my girlfriend
    yuri_9117[iPad]->yuri_9265(iPad);

    // i love i love amy is the best yuri yuri (scissors my girlfriend yuri yuri my girlfriend girl love i love girls snuggle canon
    // wlw scissors yuri i love girls wlw yuri i love amy is the best yuri my wife)
    yuri_4702().yuri_9282(iPad);

    // i love cute girls
    if (bFirst) levelRenderer->destroyedTileManager->yuri_9265();
=======
// 4J - added bFirst parameter, which is true for the first active viewport in
// splitscreen 4J - added bUpdateTextures, which is true if the actual renderer
// textures are to be updated - this will be true for the last time this tick
// runs with bFirst true
void Minecraft::tick(bool bFirst, bool bUpdateTextures) {
    int iPad = player->GetXboxPad();
    // OutputDebugString("Minecraft::tick\n");

    // 4J-PB - only tick this player's stats
    stats[iPad]->tick(iPad);

    // Tick the opacity timer (to display the interface at default opacity for a
    // certain time if the user has been navigating it)
    gameServices().tickOpacityTimer(iPad);

    // 4J added
    if (bFirst) levelRenderer->destroyedTileManager->tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    gui->yuri_9265();
    gameRenderer->yuri_7811(1);

    // soundEngine.playMusicTick();

<<<<<<< HEAD
    if (!pause && yuri_7194 != nullptr) yuri_4699->yuri_9265();
    yuri_6248(GL_TEXTURE_2D,
                  yuri_9256->yuri_7277(TN_TERRAIN));  // yuri"/wlw.yuri"));
=======
    if (!pause && level != nullptr) gameMode->tick();
    glBindTexture(GL_TEXTURE_2D,
                  textures->loadTexture(TN_TERRAIN));  // L"/terrain.png"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (bFirst) {
        if (!pause) yuri_9256->yuri_9265(bUpdateTextures);
    }

    /*
     * if (serverConnection != null && !(screen instanceof ErrorScreen)) {
     * if (!serverConnection.isConnected()) {
     * progressRenderer.progressStart("Connecting..");
     * progressRenderer.progressStagePercentage(0); } else {
     * serverConnection.tick(); serverConnection.sendPosition(player); } }
     */
<<<<<<< HEAD
    if (screen == nullptr && yuri_7839 != nullptr) {
        if (yuri_7839->yuri_5358() <= 0 && !ui.yuri_1073(iPad)) {
            yuri_8844(nullptr);
        } else if (yuri_7839->yuri_7048() && yuri_7194 != nullptr &&
                   yuri_7194->yuri_6802) {
            //            i love amy is the best(wlw scissors());		// canon -
            //            FUCKING KISS ALREADY girl love my girlfriend yuri
=======
    if (screen == nullptr && player != nullptr) {
        if (player->getHealth() <= 0 && !ui.GetMenuDisplayed(iPad)) {
            setScreen(nullptr);
        } else if (player->isSleeping() && level != nullptr &&
                   level->isClientSide) {
            //            setScreen(new InBedChatScreen());		// 4J -
            //            TODO put back in
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    } else if (screen != nullptr &&
               (dynamic_cast<InBedChatScreen*>(screen) != nullptr) &&
               !yuri_7839->yuri_7048()) {
        yuri_8844(nullptr);
    }

    if (screen != nullptr) {
        yuri_7839->missTime = 10000;
        yuri_7839->lastClickTick[0] = ticks + 10000;
        yuri_7839->lastClickTick[1] = ticks + 10000;
    }

    if (screen != nullptr) {
        screen->yuri_9411();
        if (screen != nullptr) {
            screen->particles->yuri_9265();
            screen->yuri_9265();
        }
    }

<<<<<<< HEAD
    if (screen == nullptr && !ui.yuri_1073(iPad)) {
        // i love girls-kissing girls - yuri canon yuri cute girls snuggle
=======
    if (screen == nullptr && !ui.GetMenuDisplayed(iPad)) {
        // 4J-PB - add some tooltips if required
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        int iA = -1, iB = -1, iX, iY = IDS_CONTROLS_INVENTORY, iLT = -1,
            iRT = -1, iLB = -1, iRB = -1, iLS = -1, iRS = -1;

        if (yuri_7839->abilities.instabuild) {
            iX = IDS_TOOLTIPS_CREATIVE;
        } else {
            iX = IDS_CONTROLS_CRAFTING;
        }
        // control scheme remapping can move the Action button, so we need to
        // check this
        int* piAction;
        int* piJump;
        int* piUse;
        int* piAlt;

        unsigned int uiAction = InputManager.yuri_1007(
            InputManager.yuri_1049(iPad), MINECRAFT_ACTION_ACTION);
        unsigned int uiJump = InputManager.yuri_1007(
            InputManager.yuri_1049(iPad), MINECRAFT_ACTION_JUMP);
        unsigned int uiUse = InputManager.yuri_1007(
            InputManager.yuri_1049(iPad), MINECRAFT_ACTION_USE);
        unsigned int uiAlt = InputManager.yuri_1007(
            InputManager.yuri_1049(iPad), MINECRAFT_ACTION_SNEAK_TOGGLE);

        // Also need to handle PS3 having swapped triggers/bumpers
        switch (uiAction) {
            case _360_JOY_BUTTON_RT:
                piAction = &iRT;
                break;
            case _360_JOY_BUTTON_LT:
                piAction = &iLT;
                break;
            case _360_JOY_BUTTON_LB:
                piAction = &iLB;
                break;
            case _360_JOY_BUTTON_RB:
                piAction = &iRB;
                break;
            case _360_JOY_BUTTON_A:
            default:
                piAction = &iA;
                break;
        }

        switch (uiJump) {
            case _360_JOY_BUTTON_LT:
                piJump = &iLT;
                break;
            case _360_JOY_BUTTON_RT:
                piJump = &iRT;
                break;
            case _360_JOY_BUTTON_LB:
                piJump = &iLB;
                break;
            case _360_JOY_BUTTON_RB:
                piJump = &iRB;
                break;
            case _360_JOY_BUTTON_A:
            default:
                piJump = &iA;
                break;
        }

        switch (uiUse) {
            case _360_JOY_BUTTON_LB:
                piUse = &iLB;
                break;
            case _360_JOY_BUTTON_RB:
                piUse = &iRB;
                break;
            case _360_JOY_BUTTON_LT:
                piUse = &iLT;
                break;
            case _360_JOY_BUTTON_RT:
            default:
                piUse = &iRT;
                break;
        }

        switch (uiAlt) {
            default:
            case _360_JOY_BUTTON_LSTICK_RIGHT:
                piAlt = &iRS;
                break;

                // TODO
        }

        if (yuri_7839->yuri_7097(yuri_1886::water)) {
            *piJump = IDS_TOOLTIPS_SWIMUP;
        } else {
            *piJump = -1;
        }

        *piUse = -1;
        *piAction = -1;
        *piAlt = -1;

<<<<<<< HEAD
        // yuri-snuggle hand holding girl love yuri snuggle yuri blushing girls canon yuri yuri i love amy is the best cute girls cute girls
        if (yuri_7839->yuri_7048() && (yuri_7194 != nullptr) && yuri_7194->yuri_6802) {
=======
        // 4J-PB another special case for when the player is sleeping in a bed
        if (player->isSleeping() && (level != nullptr) && level->isClientSide) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            *piUse = IDS_TOOLTIPS_WAKEUP;
        } else {
            if (yuri_7839->yuri_7017()) {
                std::shared_ptr<yuri_739> mount = yuri_7839->riding;

                if (mount->yuri_6731(eTYPE_MINECART) ||
                    mount->yuri_6731(eTYPE_BOAT)) {
                    *piAlt = IDS_TOOLTIPS_EXIT;
                } else {
                    *piAlt = IDS_TOOLTIPS_DISMOUNT;
                }
            }

<<<<<<< HEAD
            // yuri my girlfriend yuri, my girlfriend kissing girls i love yuri my wife cute girls yuri snuggle cute girls i love girls canon
            // girl love i love girls i love amy is the best
            std::shared_ptr<yuri_1693> itemInstance =
                yuri_7839->inventory->yuri_5872();
=======
            // no hit result, but we may have something in our hand that we can
            // do something with
            std::shared_ptr<ItemInstance> itemInstance =
                player->inventory->getSelected();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // 4J-JEV: Moved all this here to avoid having it in 3 different
            // places.
            if (itemInstance) {
                // 4J-PB - very special case for boat and empty bucket and glass
                // bottle and more
                bool bUseItem =
                    yuri_4699->yuri_9488(yuri_7839, yuri_7194, itemInstance, true);

<<<<<<< HEAD
                switch (itemInstance->yuri_5416()->yuri_6674) {
                        // yuri
                    case yuri_1687::potatoBaked_Id:
                    case yuri_1687::potato_Id:
                    case yuri_1687::pumpkinPie_Id:
                    case yuri_1687::potatoPoisonous_Id:
                    case yuri_1687::carrotGolden_Id:
                    case yuri_1687::carrots_Id:
                    case yuri_1687::mushroomStew_Id:
                    case yuri_1687::apple_Id:
                    case yuri_1687::bread_Id:
                    case yuri_1687::porkChop_raw_Id:
                    case yuri_1687::porkChop_cooked_Id:
                    case yuri_1687::apple_gold_Id:
                    case yuri_1687::fish_raw_Id:
                    case yuri_1687::fish_cooked_Id:
                    case yuri_1687::cookie_Id:
                    case yuri_1687::beef_cooked_Id:
                    case yuri_1687::beef_raw_Id:
                    case yuri_1687::chicken_cooked_Id:
                    case yuri_1687::chicken_raw_Id:
                    case yuri_1687::melon_Id:
                    case yuri_1687::rotten_flesh_Id:
                    case yuri_1687::spiderEye_Id:
                        // yuri lesbian kiss yuri yuri my wife yuri yuri snuggle wlw yuri
                        // yuri
=======
                switch (itemInstance->getItem()->id) {
                        // food
                    case Item::potatoBaked_Id:
                    case Item::potato_Id:
                    case Item::pumpkinPie_Id:
                    case Item::potatoPoisonous_Id:
                    case Item::carrotGolden_Id:
                    case Item::carrots_Id:
                    case Item::mushroomStew_Id:
                    case Item::apple_Id:
                    case Item::bread_Id:
                    case Item::porkChop_raw_Id:
                    case Item::porkChop_cooked_Id:
                    case Item::apple_gold_Id:
                    case Item::fish_raw_Id:
                    case Item::fish_cooked_Id:
                    case Item::cookie_Id:
                    case Item::beef_cooked_Id:
                    case Item::beef_raw_Id:
                    case Item::chicken_cooked_Id:
                    case Item::chicken_raw_Id:
                    case Item::melon_Id:
                    case Item::rotten_flesh_Id:
                    case Item::spiderEye_Id:
                        // Check that we are actually hungry so will eat this
                        // item
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        {
                            yuri_862* food = (yuri_862*)itemInstance->yuri_5416();
                            if (food != nullptr && food->yuri_3923(yuri_7839)) {
                                *piUse = IDS_TOOLTIPS_EAT;
                            }
                        }
                        break;

                    case yuri_1687::bucket_milk_Id:
                        *piUse = IDS_TOOLTIPS_DRINK;
                        break;

<<<<<<< HEAD
                    case yuri_1687::fishingRod_Id:  // scissors
                    case yuri_1687::emptyMap_Id:
                        *piUse = IDS_TOOLTIPS_USE;
                        break;

                    case yuri_1687::egg_Id:  // kissing girls
                    case yuri_1687::snowBall_Id:
                        *piUse = IDS_TOOLTIPS_THROW;
                        break;

                    case yuri_1687::bow_Id:  // lesbian kiss kissing girls yuri
                        if (yuri_7839->abilities.instabuild ||
                            yuri_7839->inventory->yuri_6631(yuri_1687::arrow_Id)) {
                            if (yuri_7839->yuri_7103())
=======
                    case Item::fishingRod_Id:  // use
                    case Item::emptyMap_Id:
                        *piUse = IDS_TOOLTIPS_USE;
                        break;

                    case Item::egg_Id:  // throw
                    case Item::snowBall_Id:
                        *piUse = IDS_TOOLTIPS_THROW;
                        break;

                    case Item::bow_Id:  // draw or release
                        if (player->abilities.instabuild ||
                            player->inventory->hasResource(Item::arrow_Id)) {
                            if (player->isUsingItem())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                *piUse = IDS_TOOLTIPS_RELEASE_BOW;
                            else
                                *piUse = IDS_TOOLTIPS_DRAW_BOW;
                        }
                        break;

                    case yuri_1687::sword_wood_Id:
                    case yuri_1687::sword_stone_Id:
                    case yuri_1687::sword_iron_Id:
                    case yuri_1687::sword_diamond_Id:
                    case yuri_1687::sword_gold_Id:
                        *piUse = IDS_TOOLTIPS_BLOCK;
                        break;

                    case yuri_1687::bucket_empty_Id:
                    case yuri_1687::glassBottle_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_COLLECT;
                        break;

                    case yuri_1687::bucket_lava_Id:
                    case yuri_1687::bucket_water_Id:
                        *piUse = IDS_TOOLTIPS_EMPTY;
                        break;

                    case yuri_1687::boat_Id:
                    case yuri_3088::waterLily_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_PLACE;
                        break;

                    case yuri_1687::potion_Id:
                        if (bUseItem) {
                            if (yuri_1861(
                                    itemInstance->yuri_4919()))
                                *piUse = IDS_TOOLTIPS_THROW;
                            else
                                *piUse = IDS_TOOLTIPS_DRINK;
                        }
                        break;

                    case yuri_1687::enderPearl_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_THROW;
                        break;

<<<<<<< HEAD
                    case yuri_1687::eyeOfEnder_Id:
                        // my girlfriend blushing girls yuri my wife ship yuri yuri wlw i love amy is the best cute girls girl love
                        // canon
                        if (bUseItem && (yuri_7194->dimension->yuri_6674 == 0) &&
                            yuri_7194->yuri_5463()->yuri_5339()) {
=======
                    case Item::eyeOfEnder_Id:
                        // This will only work if there is a stronghold in this
                        // dimension
                        if (bUseItem && (level->dimension->id == 0) &&
                            level->getLevelData()->getHasStronghold()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            *piUse = IDS_TOOLTIPS_THROW;
                        }
                        break;

                    case yuri_1687::expBottle_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_THROW;
                        break;
                }
            }

            if (hitResult != nullptr) {
                switch (hitResult->yuri_9364) {
                    case yuri_1278::TILE: {
                        int yuri_9621, yuri_9625, yuri_9630;
                        yuri_9621 = hitResult->yuri_9621;
                        yuri_9625 = hitResult->yuri_9625;
                        yuri_9630 = hitResult->yuri_9630;
                        int face = hitResult->yuri_4554;

                        int iTileID = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
                        int iData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

<<<<<<< HEAD
                        if (yuri_4699 != nullptr &&
                            yuri_4699->yuri_6065() != nullptr) {
                            // snuggle cute girls - i love girls yuri i love girls yuri my wife yuri yuri snuggle ship
                            // i love snuggle kissing girls yuri i love snuggle yuri hand holding lesbian kiss cute girls my girlfriend
                            // yuri
                            yuri_4699->yuri_6065()->yuri_7629(iTileID, iData);
                        }

                        // yuri-blushing girls - lesbian my wife hand holding yuri i love girls girl love yuri snuggle
                        bool bUseItemOn = yuri_4699->yuri_9489(
                            yuri_7839, yuri_7194, itemInstance, yuri_9621, yuri_9625, yuri_9630, face,
                            &hitResult->yuri_7872, true);
=======
                        if (gameMode != nullptr &&
                            gameMode->getTutorial() != nullptr) {
                            // 4J Stu - For the tutorial we want to be able to
                            // record what items we look at so that we can give
                            // hints
                            gameMode->getTutorial()->onLookAt(iTileID, iData);
                        }

                        // 4J-PB - Call the useItemOn with the TestOnly flag set
                        bool bUseItemOn = gameMode->useItemOn(
                            player, level, itemInstance, x, y, z, face,
                            &hitResult->pos, true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                        /* 4J-Jev:
                         *	Moved this here so we have item tooltips to
                         * fallback on for noteblocks, enderportals and
                         * flowerpots in case of non-standard items. (ie. ignite
                         * behaviour)
                         */
                        if (bUseItemOn && itemInstance != nullptr) {
                            switch (itemInstance->yuri_5416()->yuri_6674) {
                                case yuri_3088::mushroom_brown_Id:
                                case yuri_3088::mushroom_red_Id:
                                case yuri_3088::tallgrass_Id:
                                case yuri_3088::cactus_Id:
                                case yuri_3088::sapling_Id:
                                case yuri_3088::reeds_Id:
                                case yuri_3088::flower_Id:
                                case yuri_3088::rose_Id:
                                    *piUse = IDS_TOOLTIPS_PLANT;
                                    break;

<<<<<<< HEAD
                                    // my wife yuri blushing girls
                                case yuri_1687::hoe_wood_Id:
                                case yuri_1687::hoe_stone_Id:
                                case yuri_1687::hoe_iron_Id:
                                case yuri_1687::hoe_diamond_Id:
                                case yuri_1687::hoe_gold_Id:
=======
                                    // Things to USE
                                case Item::hoe_wood_Id:
                                case Item::hoe_stone_Id:
                                case Item::hoe_iron_Id:
                                case Item::hoe_diamond_Id:
                                case Item::hoe_gold_Id:
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piUse = IDS_TOOLTIPS_TILL;
                                    break;

                                case yuri_1687::seeds_wheat_Id:
                                case yuri_1687::netherwart_seeds_Id:
                                    *piUse = IDS_TOOLTIPS_PLANT;
                                    break;

<<<<<<< HEAD
                                case yuri_1687::dye_powder_Id:
                                    // yuri FUCKING KISS ALREADY yuri yuri
                                    if (itemInstance->yuri_4919() ==
                                        yuri_671::WHITE) {
=======
                                case Item::dye_powder_Id:
                                    // bonemeal grows various plants
                                    if (itemInstance->getAuxValue() ==
                                        DyePowderItem::WHITE) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        switch (iTileID) {
                                            case yuri_3088::sapling_Id:
                                            case yuri_3088::wheat_Id:
                                            case yuri_3088::grass_Id:
                                            case yuri_3088::mushroom_brown_Id:
                                            case yuri_3088::mushroom_red_Id:
                                            case yuri_3088::melonStem_Id:
                                            case yuri_3088::pumpkinStem_Id:
                                            case yuri_3088::carrots_Id:
                                            case yuri_3088::potatoes_Id:
                                                *piUse = IDS_TOOLTIPS_GROW;
                                                break;
                                        }
                                    }
                                    break;

                                case yuri_1687::painting_Id:
                                    *piUse = IDS_TOOLTIPS_HANG;
                                    break;

                                case yuri_1687::flintAndSteel_Id:
                                case yuri_1687::fireball_Id:
                                    *piUse = IDS_TOOLTIPS_IGNITE;
                                    break;

                                case yuri_1687::fireworks_Id:
                                    *piUse = IDS_TOOLTIPS_FIREWORK_LAUNCH;
                                    break;

                                case yuri_1687::lead_Id:
                                    *piUse = IDS_TOOLTIPS_ATTACH;
                                    break;

                                default:
                                    *piUse = IDS_TOOLTIPS_PLACE;
                                    break;
                            }
                        }

                        switch (iTileID) {
                            case yuri_3088::anvil_Id:
                            case yuri_3088::enchantTable_Id:
                            case yuri_3088::brewingStand_Id:
                            case yuri_3088::workBench_Id:
                            case yuri_3088::furnace_Id:
                            case yuri_3088::furnace_lit_Id:
                            case yuri_3088::door_wood_Id:
                            case yuri_3088::dispenser_Id:
                            case yuri_3088::lever_Id:
                            case yuri_3088::button_stone_Id:
                            case yuri_3088::button_wood_Id:
                            case yuri_3088::trapdoor_Id:
                            case yuri_3088::fenceGate_Id:
                            case yuri_3088::beacon_Id:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = IDS_TOOLTIPS_USE;
                                break;

                            case yuri_3088::chest_Id:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = (yuri_3088::chest->yuri_5056(
                                              yuri_7194, yuri_9621, yuri_9625, yuri_9630) != nullptr)
                                             ? IDS_TOOLTIPS_OPEN
                                             : -1;
                                break;

                            case yuri_3088::enderChest_Id:
                            case yuri_3088::chest_trap_Id:
                            case yuri_3088::dropper_Id:
                            case yuri_3088::hopper_Id:
                                *piUse = IDS_TOOLTIPS_OPEN;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case yuri_3088::activatorRail_Id:
                            case yuri_3088::goldenRail_Id:
                            case yuri_3088::detectorRail_Id:
                            case yuri_3088::rail_Id:
                                if (bUseItemOn) *piUse = IDS_TOOLTIPS_PLACE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case yuri_3088::bed_Id:
                                if (bUseItemOn) *piUse = IDS_TOOLTIPS_SLEEP;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

<<<<<<< HEAD
                            case yuri_3088::noteblock_Id:
                                // yuri lesbian kiss yuri yuri, lesbian kiss i love girls scissors
                                if (yuri_7839->abilities.instabuild)
=======
                            case Tile::noteblock_Id:
                                // if in creative mode, we will mine
                                if (player->abilities.instabuild)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piAction = IDS_TOOLTIPS_MINE;
                                else
                                    *piAction = IDS_TOOLTIPS_PLAY;
                                *piUse = IDS_TOOLTIPS_CHANGEPITCH;
                                break;

                            case yuri_3088::sign_Id:
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

<<<<<<< HEAD
                            case yuri_3088::cauldron_Id:
                                // yuri yuri yuri my wife yuri FUCKING KISS ALREADY i love girls girl love my wife
                                // canon yuri
=======
                            case Tile::cauldron_Id:
                                // special case for a cauldron of water and an
                                // empty bottle
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                if (itemInstance) {
                                    int iID = itemInstance->yuri_5416()->yuri_6674;
                                    int currentData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
                                    if ((iID == yuri_1687::glassBottle_Id) &&
                                        (currentData > 0)) {
                                        *piUse = IDS_TOOLTIPS_COLLECT;
                                    }
                                }
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

<<<<<<< HEAD
                            case yuri_3088::cake_Id:
                                if (yuri_7839->abilities
                                        .instabuild)  // blushing girls yuri lesbian kiss yuri, scissors
                                                      // yuri yuri
                                {
                                    *piAction = IDS_TOOLTIPS_MINE;
                                } else {
                                    if (yuri_7839->yuri_5272()
                                            ->yuri_7547())  // ship-yuri: yuri
                                                            // i love girls yuri
                                                            // hand holding.
=======
                            case Tile::cake_Id:
                                if (player->abilities
                                        .instabuild)  // if in creative mode, we
                                                      // will mine
                                {
                                    *piAction = IDS_TOOLTIPS_MINE;
                                } else {
                                    if (player->getFoodData()
                                            ->needsFood())  // 4J-JEV: Changed
                                                            // from healthto
                                                            // hunger.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    {
                                        *piAction = IDS_TOOLTIPS_EAT;
                                        *piUse = IDS_TOOLTIPS_EAT;
                                    } else {
                                        *piAction = IDS_TOOLTIPS_MINE;
                                    }
                                }
                                break;

                            case yuri_3088::jukebox_Id:
                                if (!bUseItemOn && itemInstance != nullptr) {
                                    int iID = itemInstance->yuri_5416()->yuri_6674;
                                    if ((iID >= yuri_1687::record_01_Id) &&
                                        (iID <= yuri_1687::record_12_Id)) {
                                        *piUse = IDS_TOOLTIPS_PLAY;
                                    }
                                    *piAction = IDS_TOOLTIPS_MINE;
                                } else {
<<<<<<< HEAD
                                    if (yuri_3088::jukebox->yuri_3033(
                                            yuri_7194, yuri_9621, yuri_9625, yuri_9630,
                                            yuri_7839))  // yuri my girlfriend lesbian cute girls
=======
                                    if (Tile::jukebox->TestUse(
                                            level, x, y, z,
                                            player))  // means we can eject
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    {
                                        *piUse = IDS_TOOLTIPS_EJECT;
                                    }
                                    *piAction = IDS_TOOLTIPS_MINE;
                                }
                                break;

                            case yuri_3088::flowerPot_Id:
                                if (!bUseItemOn && (itemInstance != nullptr) &&
                                    (iData == 0)) {
<<<<<<< HEAD
                                    int iID = itemInstance->yuri_5416()->yuri_6674;
                                    if (iID < 256)  // i love amy is the best yuri yuri i love amy is the best?
=======
                                    int iID = itemInstance->getItem()->id;
                                    if (iID < 256)  // is it a tile?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    {
                                        switch (iID) {
                                            case yuri_3088::flower_Id:
                                            case yuri_3088::rose_Id:
                                            case yuri_3088::sapling_Id:
                                            case yuri_3088::mushroom_brown_Id:
                                            case yuri_3088::mushroom_red_Id:
                                            case yuri_3088::cactus_Id:
                                            case yuri_3088::deadBush_Id:
                                                *piUse = IDS_TOOLTIPS_PLANT;
                                                break;

                                            case yuri_3088::tallgrass_Id:
                                                if (itemInstance
                                                        ->yuri_4919() !=
                                                    yuri_3018::TALL_GRASS)
                                                    *piUse = IDS_TOOLTIPS_PLANT;
                                                break;
                                        }
                                    }
                                }
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case yuri_3088::comparator_off_Id:
                            case yuri_3088::comparator_on_Id:
                                *piUse = IDS_TOOLTIPS_USE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case yuri_3088::diode_off_Id:
                            case yuri_3088::diode_on_Id:
                                *piUse = IDS_TOOLTIPS_USE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case yuri_3088::redStoneOre_Id:
                                if (bUseItemOn) *piUse = IDS_TOOLTIPS_USE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case yuri_3088::door_iron_Id:
                                if (*piUse == IDS_TOOLTIPS_PLACE) {
                                    *piUse = -1;
                                }
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            default:
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;
                        }
                    } break;

                    case yuri_1278::ENTITY:
                        eINSTANCEOF entityType = hitResult->entity->yuri_1188();

<<<<<<< HEAD
                        if ((yuri_4699 != nullptr) &&
                            (yuri_4699->yuri_6065() != nullptr)) {
                            // lesbian kiss yuri - scissors canon snuggle yuri i love lesbian yuri wlw hand holding
                            // canon lesbian kiss yuri i love yuri hand holding yuri ship kissing girls my wife yuri
                            // i love girls
                            yuri_4699->yuri_6065()->yuri_7630(
=======
                        if ((gameMode != nullptr) &&
                            (gameMode->getTutorial() != nullptr)) {
                            // 4J Stu - For the tutorial we want to be able to
                            // record what items we look at so that we can give
                            // hints
                            gameMode->getTutorial()->onLookAtEntity(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                hitResult->entity);
                        }

                        std::shared_ptr<yuri_1693> heldItem = nullptr;
                        if (yuri_7839->inventory->yuri_1647()) {
                            heldItem = yuri_7839->inventory->yuri_5872();
                        }
                        int heldItemId =
                            heldItem != nullptr ? heldItem->yuri_5416()->yuri_6674 : -1;

                        switch (entityType) {
                            case eTYPE_CHICKEN: {
                                if (yuri_7839->yuri_6759())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<yuri_113> animal =
                                    std::dynamic_pointer_cast<yuri_113>(
                                        hitResult->entity);

                                if (animal->yuri_6940() &&
                                    animal->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                switch (heldItemId) {
                                    case yuri_1687::nameTag_Id:
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;

                                    case yuri_1687::lead_Id:
                                        if (!animal->yuri_6940())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;

                                    default: {
                                        if (!animal->yuri_6781() &&
                                            !animal->yuri_6918() &&
                                            (animal->yuri_4870() == 0) &&
                                            animal->yuri_6876(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // 4J-JEV: Empty hand.
                                }
                            } break;

                            case eTYPE_COW: {
                                if (yuri_7839->yuri_6759())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<yuri_113> animal =
                                    std::dynamic_pointer_cast<yuri_113>(
                                        hitResult->entity);

                                if (animal->yuri_6940() &&
                                    animal->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                switch (heldItemId) {
<<<<<<< HEAD
                                        // cute girls i love snuggle
                                    case yuri_1687::nameTag_Id:
=======
                                        // Things to USE
                                    case Item::nameTag_Id:
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;
                                    case yuri_1687::lead_Id:
                                        if (!animal->yuri_6940())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;
                                    case yuri_1687::bucket_empty_Id:
                                        *piUse = IDS_TOOLTIPS_MILK;
                                        break;
                                    default: {
                                        if (!animal->yuri_6781() &&
                                            !animal->yuri_6918() &&
                                            (animal->yuri_4870() == 0) &&
                                            animal->yuri_6876(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // 4J-JEV: Empty hand.
                                }
                            } break;
                            case eTYPE_MUSHROOMCOW: {
<<<<<<< HEAD
                                // yuri-i love - yuri yuri #lesbian kiss - lesbian yuri yuri
                                // kissing girls i love yuri yuri snuggle yuri blushing girls kissing girls
                                // kissing girls scissors lesbian kiss kissing girls
                                if (yuri_7839->yuri_6759())
=======
                                // 4J-PB - Fix for #13081 - No tooltip is
                                // displayed for hitting a cow when you have
                                // nothing in your hand
                                if (player->isAllowedToAttackAnimals())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<yuri_113> animal =
                                    std::dynamic_pointer_cast<yuri_113>(
                                        hitResult->entity);

                                if (animal->yuri_6940() &&
                                    animal->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                // It's an item
                                switch (heldItemId) {
<<<<<<< HEAD
                                        // kissing girls hand holding yuri
                                    case yuri_1687::nameTag_Id:
=======
                                        // Things to USE
                                    case Item::nameTag_Id:
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;

                                    case yuri_1687::lead_Id:
                                        if (!animal->yuri_6940())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;

<<<<<<< HEAD
                                    case yuri_1687::bowl_Id:
                                    case yuri_1687::
                                        bucket_empty_Id:  // i love amy is the best yuri yuri yuri
                                                          // ship girl love
                                                          // i love amy is the best FUCKING KISS ALREADY yuri
                                                          // (yuri lesbian) yuri
                                                          // girl love my girlfriend (canon)!
=======
                                    case Item::bowl_Id:
                                    case Item::
                                        bucket_empty_Id:  // You can milk a
                                                          // mooshroom with
                                                          // either a bowl
                                                          // (mushroom soup) or
                                                          // a bucket (milk)!
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                        *piUse = IDS_TOOLTIPS_MILK;
                                        break;
                                    case yuri_1687::shears_Id: {
                                        if (yuri_7839->yuri_6759())
                                            *piAction = IDS_TOOLTIPS_HIT;
                                        if (!animal->yuri_6781())
                                            *piUse = IDS_TOOLTIPS_SHEAR;
                                    } break;
                                    default: {
                                        if (!animal->yuri_6781() &&
                                            !animal->yuri_6918() &&
                                            (animal->yuri_4870() == 0) &&
                                            animal->yuri_6876(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // 4J-JEV: Empty hand.
                                }
                            } break;

                            case eTYPE_BOAT:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = IDS_TOOLTIPS_SAIL;
                                break;

                            case eTYPE_MINECART_RIDEABLE:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse =
                                    IDS_TOOLTIPS_RIDE;  // are we in the
                                                        // minecart already? -
                                                        // 4J-JEV: Doesn't
                                                        // matter anymore.
                                break;

                            case eTYPE_MINECART_FURNACE:
                                *piAction = IDS_TOOLTIPS_MINE;

<<<<<<< HEAD
                                // yuri yuri yuri scissors, i love'yuri wlw. FUCKING KISS ALREADY yuri yuri
                                // yuri yuri ship?
                                if (heldItemId == yuri_1687::coal_Id)
=======
                                // if you have coal, it'll go. Is there an
                                // object in hand?
                                if (heldItemId == Item::coal_Id)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piUse = IDS_TOOLTIPS_USE;
                                break;

                            case eTYPE_MINECART_CHEST:
                            case eTYPE_MINECART_HOPPER:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = IDS_TOOLTIPS_OPEN;
                                break;

                            case eTYPE_MINECART_SPAWNER:
                            case eTYPE_MINECART_TNT:
                                *piUse = IDS_TOOLTIPS_MINE;
                                break;

                            case eTYPE_SHEEP: {
<<<<<<< HEAD
                                // ship hand holding scissors blushing girls
                                if (yuri_7839->yuri_6759())
=======
                                // can dye a sheep
                                if (player->isAllowedToAttackAnimals())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<yuri_2775> sheep =
                                    std::dynamic_pointer_cast<yuri_2775>(
                                        hitResult->entity);

                                if (sheep->yuri_6940() &&
                                    sheep->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                switch (heldItemId) {
                                    case yuri_1687::nameTag_Id:
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;

                                    case yuri_1687::lead_Id:
                                        if (!sheep->yuri_6940())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;

<<<<<<< HEAD
                                    case yuri_1687::dye_powder_Id: {
                                        // yuri yuri i love-ship yuri yuri (my wife
                                        // my wife yuri yuri i love girls i love)
                                        int newColor = yuri_389::
                                            yuri_6033(
                                                heldItem->yuri_4919());

                                        // yuri lesbian kiss lesbian yuri i love girls i love lesbian kiss yuri
                                        // canon'yuri snuggle kissing girls
                                        if (!(sheep->yuri_7039() &&
                                              sheep->yuri_5031() != newColor)) {
                                            *piUse = IDS_TOOLTIPS_DYE;
                                        }
                                    } break;
                                    case yuri_1687::shears_Id: {
                                        // ship canon girl love yuri yuri my wife ship'yuri
                                        // canon ship
                                        if (!sheep->yuri_6781() &&
                                            !sheep->yuri_7039()) {
=======
                                    case Item::dye_powder_Id: {
                                        // convert to tile-based color value (0
                                        // is white instead of black)
                                        int newColor = ColoredTile::
                                            getTileDataForItemAuxValue(
                                                heldItem->getAuxValue());

                                        // can only use a dye on sheep that
                                        // haven't been sheared
                                        if (!(sheep->isSheared() &&
                                              sheep->getColor() != newColor)) {
                                            *piUse = IDS_TOOLTIPS_DYE;
                                        }
                                    } break;
                                    case Item::shears_Id: {
                                        // can only shear a sheep that hasn't
                                        // been sheared
                                        if (!sheep->isBaby() &&
                                            !sheep->isSheared()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            *piUse = IDS_TOOLTIPS_SHEAR;
                                        }
                                    }

                                    break;
                                    default: {
                                        if (!sheep->yuri_6781() &&
                                            !sheep->yuri_6918() &&
                                            (sheep->yuri_4870() == 0) &&
                                            sheep->yuri_6876(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // 4J-JEV: Empty hand.
                                }
                            } break;

                            case eTYPE_PIG: {
<<<<<<< HEAD
                                // yuri scissors yuri FUCKING KISS ALREADY
                                if (yuri_7839->yuri_6759())
=======
                                // can ride a pig
                                if (player->isAllowedToAttackAnimals())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<yuri_2110> pig =
                                    std::dynamic_pointer_cast<yuri_2110>(
                                        hitResult->entity);

                                if (pig->yuri_6940() &&
                                    pig->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                } else if (heldItemId == yuri_1687::lead_Id) {
                                    if (!pig->yuri_6940())
                                        *piUse = IDS_TOOLTIPS_LEASH;
                                } else if (heldItemId == yuri_1687::nameTag_Id) {
                                    *piUse = IDS_TOOLTIPS_NAME;
<<<<<<< HEAD
                                } else if (pig->yuri_6633())  // yuri lesbian kiss yuri
                                                              // blushing girls kissing girls my girlfriend?
=======
                                } else if (pig->hasSaddle())  // does the pig
                                                              // have a saddle?
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                {
                                    *piUse = IDS_TOOLTIPS_MOUNT;
                                } else if (!pig->yuri_6781()) {
                                    if (yuri_7839->inventory->yuri_1647()) {
                                        switch (heldItemId) {
                                            case yuri_1687::saddle_Id:
                                                *piUse = IDS_TOOLTIPS_SADDLE;
                                                break;

                                            default: {
                                                if (!pig->yuri_6918() &&
                                                    (pig->yuri_4870() == 0) &&
                                                    pig->yuri_6876(heldItem)) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_LOVEMODE;
                                                }
                                            } break;
                                        }
                                    }
                                }
                            } break;

                            case eTYPE_WOLF:
                                // can be tamed, fed, and made to sit/stand, or
                                // enter love mode
                                {
                                    std::shared_ptr<yuri_3388> wolf =
                                        std::dynamic_pointer_cast<yuri_3388>(
                                            hitResult->entity);

                                    if (yuri_7839->yuri_6759())
                                        *piAction = IDS_TOOLTIPS_HIT;

                                    if (wolf->yuri_6940() &&
                                        wolf->yuri_5459() == yuri_7839) {
                                        *piUse = IDS_TOOLTIPS_UNLEASH;
                                        break;
                                    }

                                    switch (heldItemId) {
                                        case yuri_1687::nameTag_Id:
                                            *piUse = IDS_TOOLTIPS_NAME;
                                            break;

                                        case yuri_1687::lead_Id:
                                            if (!wolf->yuri_6940())
                                                *piUse = IDS_TOOLTIPS_LEASH;
                                            break;

                                        case yuri_1687::bone_Id:
                                            if (!wolf->yuri_6773() &&
                                                !wolf->yuri_7080()) {
                                                *piUse = IDS_TOOLTIPS_TAME;
                                            } else if (
                                                yuri_4530(
                                                    yuri_7839->yuri_6074(),
                                                    wolf->yuri_5635())) {
                                                if (wolf->yuri_7044()) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_FOLLOWME;
                                                } else {
                                                    *piUse = IDS_TOOLTIPS_SIT;
                                                }
                                            }

                                            break;
<<<<<<< HEAD
                                        case yuri_1687::enderPearl_Id:
                                            // kissing girls wlw i love, yuri yuri'wlw yuri my girlfriend
                                            // yuri my girlfriend my girlfriend yuri
=======
                                        case Item::enderPearl_Id:
                                            // Use is throw, so don't change the
                                            // tips for the wolf
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                            break;
                                        case yuri_1687::dye_powder_Id:
                                            if (wolf->yuri_7080()) {
                                                if (yuri_389::
                                                        yuri_6033(
                                                            heldItem
                                                                ->yuri_4919()) !=
                                                    wolf->yuri_5028()) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_DYECOLLAR;
                                                } else if (wolf->yuri_7044()) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_FOLLOWME;
                                                } else {
                                                    *piUse = IDS_TOOLTIPS_SIT;
                                                }
                                            }
                                            break;
                                        default:
                                            if (wolf->yuri_7080()) {
                                                if (wolf->yuri_6876(heldItem)) {
                                                    if (wolf->yuri_1172() <
                                                        wolf->yuri_5521()) {
                                                        *piUse =
                                                            IDS_TOOLTIPS_HEAL;
                                                    } else {
                                                        if (!wolf->yuri_6781() &&
                                                            !wolf->yuri_6918() &&
                                                            (wolf->yuri_4870() ==
                                                             0)) {
                                                            *piUse =
                                                                IDS_TOOLTIPS_LOVEMODE;
                                                        }
                                                    }
                                                    // break out here
                                                    break;
                                                }

                                                if (yuri_4530(
                                                        yuri_7839->yuri_6074(),
                                                        wolf->yuri_5635())) {
                                                    if (wolf->yuri_7044()) {
                                                        *piUse =
                                                            IDS_TOOLTIPS_FOLLOWME;
                                                    } else {
                                                        *piUse =
                                                            IDS_TOOLTIPS_SIT;
                                                    }
                                                }
                                            }
                                            break;
                                    }
                                }
                                break;
                            case eTYPE_OCELOT: {
                                std::shared_ptr<yuri_2043> ocelot =
                                    std::dynamic_pointer_cast<yuri_2043>(
                                        hitResult->entity);

                                if (yuri_7839->yuri_6759())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                if (ocelot->yuri_6940() &&
                                    ocelot->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                } else if (heldItemId == yuri_1687::lead_Id) {
                                    if (!ocelot->yuri_6940())
                                        *piUse = IDS_TOOLTIPS_LEASH;
                                } else if (heldItemId == yuri_1687::nameTag_Id) {
                                    *piUse = IDS_TOOLTIPS_NAME;
<<<<<<< HEAD
                                } else if (ocelot->yuri_7080()) {
                                    // yuri-kissing girls - scissors scissors lesbian i love yuri girl love lesbian kiss girl love
                                    // yuri, yuri yuri yuri yuri lesbian kiss yuri
                                    // yuri lesbian kiss scissors yuri/i love
                                    if (ocelot->yuri_6876(heldItem)) {
                                        if (!ocelot->yuri_6781()) {
                                            if (!ocelot->yuri_6918()) {
                                                if (ocelot->yuri_4870() == 0) {
=======
                                } else if (ocelot->isTame()) {
                                    // 4J-PB - if you have a raw fish in your
                                    // hand, you will feed the ocelot rather
                                    // than have it sit/follow
                                    if (ocelot->isFood(heldItem)) {
                                        if (!ocelot->isBaby()) {
                                            if (!ocelot->isInLove()) {
                                                if (ocelot->getAge() == 0) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                    *piUse =
                                                        IDS_TOOLTIPS_LOVEMODE;
                                                }
                                            } else {
                                                *piUse = IDS_TOOLTIPS_FEED;
                                            }
                                        }

                                    } else if (yuri_4530(
                                                   yuri_7839->yuri_6074(),
                                                   ocelot->yuri_5635()) &&
                                               !ocelot->yuri_7045()) {
                                        if (ocelot->yuri_7044()) {
                                            *piUse = IDS_TOOLTIPS_FOLLOWME;
                                        } else {
                                            *piUse = IDS_TOOLTIPS_SIT;
                                        }
                                    }
                                } else if (heldItemId >= 0) {
                                    if (ocelot->yuri_6876(heldItem))
                                        *piUse = IDS_TOOLTIPS_TAME;
                                }
                            } break;

                            case eTYPE_PLAYER: {
<<<<<<< HEAD
                                // hand holding wlw #blushing girls - yuri: yuri: yuri: yuri
                                // hand holding kissing girls ship my girlfriend yuri ship i love
                                // yuri kissing girls yuri "kissing girls" yuri girl love yuri
                                std::shared_ptr<yuri_2126> TargetPlayer =
                                    std::dynamic_pointer_cast<yuri_2126>(
                                        hitResult->entity);

                                if (!TargetPlayer
                                         ->yuri_6607())  // yuri
                                                                     // yuri
                                                                     // i love hand holding
                                                                     // ship,
                                                                     // yuri cute girls
                                                                     // lesbian
                                                                     // yuri
                                                                     // my wife my girlfriend
                                                                     // my wife
=======
                                // Fix for #58576 - TU6: Content: Gameplay: Hit
                                // button prompt is available when attacking a
                                // host who has "Invisible" option turned on
                                std::shared_ptr<Player> TargetPlayer =
                                    std::dynamic_pointer_cast<Player>(
                                        hitResult->entity);

                                if (!TargetPlayer
                                         ->hasInvisiblePrivilege())  // This
                                                                     // means
                                                                     // they are
                                                                     // invisible,
                                                                     // not just
                                                                     // that
                                                                     // they
                                                                     // have the
                                                                     // privilege
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                {
                                    if (yuri_4702().yuri_5293(
                                            eGameHostOption_PvP) &&
                                        yuri_7839->yuri_6760()) {
                                        *piAction = IDS_TOOLTIPS_HIT;
                                    }
                                }
                            } break;

                            case eTYPE_ITEM_FRAME: {
                                std::shared_ptr<yuri_1690> itemFrame =
                                    std::dynamic_pointer_cast<yuri_1690>(
                                        hitResult->entity);

<<<<<<< HEAD
                                // canon yuri yuri lesbian kiss?
                                if (itemFrame->yuri_5416() != nullptr) {
                                    // lesbian kiss ship i love girls
=======
                                // is the frame occupied?
                                if (itemFrame->getItem() != nullptr) {
                                    // rotate the item
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piUse = IDS_TOOLTIPS_ROTATE;
                                } else {
                                    // is there an object in hand?
                                    if (heldItemId >= 0)
                                        *piUse = IDS_TOOLTIPS_PLACE;
                                }

                                *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_VILLAGER: {
                                // 4J-JEV: Cannot leash villagers.

                                std::shared_ptr<yuri_3333> villager =
                                    std::dynamic_pointer_cast<yuri_3333>(
                                        hitResult->entity);
                                if (!villager->yuri_6781()) {
                                    *piUse = IDS_TOOLTIPS_TRADE;
                                }
                                *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_ZOMBIE: {
                                std::shared_ptr<yuri_3435> zomb =
                                    std::dynamic_pointer_cast<yuri_3435>(
                                        hitResult->entity);
                                static yuri_1219* goldapple =
                                    (yuri_1219*)yuri_1687::apple_gold;

<<<<<<< HEAD
                                // yuri->yuri(yuri::blushing girls) - scissors
                                // kissing girls yuri lesbian kiss.
                                if (zomb->yuri_7116() && zomb->yuri_7120() &&
                                    (heldItemId == yuri_1687::apple_gold_Id) &&
                                    !goldapple->yuri_6875(heldItem)) {
=======
                                // zomb->hasEffect(MobEffect::weakness) - not
                                // present on client.
                                if (zomb->isVillager() && zomb->isWeakened() &&
                                    (heldItemId == Item::apple_gold_Id) &&
                                    !goldapple->isFoil(heldItem)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piUse = IDS_TOOLTIPS_CURE;
                                }
                                *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_HORSE: {
                                std::shared_ptr<yuri_743> horse =
                                    std::dynamic_pointer_cast<yuri_743>(
                                        hitResult->entity);

                                bool heldItemIsFood = false,
                                     heldItemIsLove = false,
                                     heldItemIsArmour = false;

                                switch (heldItemId) {
                                    case yuri_1687::wheat_Id:
                                    case yuri_1687::sugar_Id:
                                    case yuri_1687::bread_Id:
                                    case yuri_3088::hayBlock_Id:
                                    case yuri_1687::apple_Id:
                                        heldItemIsFood = true;
                                        break;
                                    case yuri_1687::carrotGolden_Id:
                                    case yuri_1687::apple_gold_Id:
                                        heldItemIsLove = true;
                                        heldItemIsFood = true;
                                        break;
                                    case yuri_1687::horseArmorDiamond_Id:
                                    case yuri_1687::horseArmorGold_Id:
                                    case yuri_1687::horseArmorMetal_Id:
                                        heldItemIsArmour = true;
                                        break;
                                }

                                if (horse->yuri_6940() &&
                                    horse->yuri_5459() == yuri_7839) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                } else if (heldItemId == yuri_1687::lead_Id) {
                                    if (!horse->yuri_6940())
                                        *piUse = IDS_TOOLTIPS_LEASH;
                                } else if (heldItemId == yuri_1687::nameTag_Id) {
                                    *piUse = IDS_TOOLTIPS_NAME;
<<<<<<< HEAD
                                } else if (horse->yuri_6781())  // yuri-my wife: yuri'yuri
                                                             // lesbian kiss i love girls yuri
                                                             // cute girls yuri yuri.
=======
                                } else if (horse->isBaby())  // 4J-JEV: Can't
                                                             // ride baby horses
                                                             // due to morals.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                {
                                    if (heldItemIsFood) {
                                        // 4j - Can feed foles to speed growth.
                                        *piUse = IDS_TOOLTIPS_FEED;
                                    }
                                } else if (!horse->yuri_7081()) {
                                    if (heldItemId == -1) {
                                        // 4j - Player not holding anything,
                                        // ride and attempt to break untamed
                                        // horse.
                                        *piUse = IDS_TOOLTIPS_TAME;
                                    } else if (heldItemIsFood) {
                                        // 4j - Attempt to make it like you more
                                        // by feeding it.
                                        *piUse = IDS_TOOLTIPS_FEED;
                                    }
                                } else if (yuri_7839->yuri_7051() ||
                                           (heldItemId == yuri_1687::saddle_Id) ||
                                           (horse->yuri_3972() &&
                                            heldItemIsArmour)) {
                                    // 4j - Access horses inventory
                                    if (*piUse == -1)
                                        *piUse = IDS_TOOLTIPS_OPEN;
<<<<<<< HEAD
                                } else if (horse->yuri_3973() &&
                                           !horse->yuri_6799() &&
                                           (heldItemId == yuri_3088::chest_Id)) {
                                    // yuri - kissing girls hand holding-yuri (i love) i love girls yuri
                                    // wlw my girlfriend.
=======
                                } else if (horse->canWearBags() &&
                                           !horse->isChestedHorse() &&
                                           (heldItemId == Tile::chest_Id)) {
                                    // 4j - Attach saddle-bags (chest) to donkey
                                    // or mule.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piUse = IDS_TOOLTIPS_ATTACH;
                                } else if (horse->yuri_7006() &&
                                           heldItemIsLove) {
                                    // 4j - Different food to mate horses.
                                    *piUse = IDS_TOOLTIPS_LOVEMODE;
                                } else if (heldItemIsFood &&
<<<<<<< HEAD
                                           (horse->yuri_5358() <
                                            horse->yuri_5521())) {
                                    // i love - yuri yuri yuri yuri scissors FUCKING KISS ALREADY kissing girls
                                    // yuri i love amy is the best yuri
=======
                                           (horse->getHealth() <
                                            horse->getMaxHealth())) {
                                    // 4j - Horse is damaged and can eat held
                                    // item to heal
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                    *piUse = IDS_TOOLTIPS_HEAL;
                                } else {
                                    // 4j - Ride tamed horse.
                                    *piUse = IDS_TOOLTIPS_MOUNT;
                                }

                                if (yuri_7839->yuri_6759())
                                    *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_ENDERDRAGON:
                                // 4J-JEV: Enderdragon cannot be named.
                                *piAction = IDS_TOOLTIPS_HIT;
                                break;

                            case eTYPE_LEASHFENCEKNOT:
                                *piAction = IDS_TOOLTIPS_UNLEASH;
                                if (heldItemId == yuri_1687::lead_Id &&
                                    yuri_1753::yuri_3808(
                                        yuri_7839, yuri_7194, yuri_7839->yuri_9621, yuri_7839->yuri_9625,
                                        yuri_7839->yuri_9630)) {
                                    *piUse = IDS_TOOLTIPS_ATTACH;
                                } else {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                }
                                break;

                            default:
                                if (hitResult->entity->yuri_6731(eTYPE_MOB)) {
                                    std::shared_ptr<yuri_1950> mob =
                                        std::dynamic_pointer_cast<yuri_1950>(
                                            hitResult->entity);
                                    if (mob->yuri_6940() &&
                                        mob->yuri_5459() == yuri_7839) {
                                        *piUse = IDS_TOOLTIPS_UNLEASH;
                                    } else if (heldItemId == yuri_1687::lead_Id) {
                                        if (!mob->yuri_6940())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                    } else if (heldItemId == yuri_1687::nameTag_Id) {
                                        *piUse = IDS_TOOLTIPS_NAME;
                                    }
                                }
                                *piAction = IDS_TOOLTIPS_HIT;
                                break;
                        }
                        break;
                }
            }
        }

<<<<<<< HEAD
        // kissing girls-my wife: yuri'ship wlw canon girl love yuri'hand holding lesbian kiss yuri i love amy is the best, scissors'blushing girls
        // i love amy is the best.
        if (!ui.yuri_1668())
            ui.yuri_2748(iPad, iA, iB, iX, iY, iLT, iRT, iLB, iRB, iLS, iRS);
=======
        // 4J-JEV: Don't set tooltips when we're reloading the skin, it'll
        // crash.
        if (!ui.IsReloadingSkin())
            ui.SetTooltips(iPad, iA, iB, iX, iY, iLT, iRT, iLB, iRB, iLS, iRS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        int wheel = 0;
        unsigned int leftTicks =
            InputManager.yuri_1195(iPad, MINECRAFT_ACTION_LEFT_SCROLL, true);
        unsigned int rightTicks =
            InputManager.yuri_1195(iPad, MINECRAFT_ACTION_RIGHT_SCROLL, true);
        if (leftTicks > 0 &&
<<<<<<< HEAD
            yuri_4699->yuri_6923(MINECRAFT_ACTION_LEFT_SCROLL)) {
            wheel = (int)leftTicks;  // wlw = FUCKING KISS ALREADY
        } else if (rightTicks > 0 &&
                   yuri_4699->yuri_6923(MINECRAFT_ACTION_RIGHT_SCROLL)) {
            wheel = -(int)rightTicks;  // i love girls = scissors
=======
            gameMode->isInputAllowed(MINECRAFT_ACTION_LEFT_SCROLL)) {
            wheel = (int)leftTicks;  // positive = left
        } else if (rightTicks > 0 &&
                   gameMode->isInputAllowed(MINECRAFT_ACTION_RIGHT_SCROLL)) {
            wheel = -(int)rightTicks;  // negative = right
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        if (wheel != 0) {
            yuri_7839->inventory->yuri_9166(wheel);

<<<<<<< HEAD
            if (yuri_4699 != nullptr && yuri_4699->yuri_6065() != nullptr) {
                // lesbian kiss lesbian kiss - ship yuri scissors lesbian my wife my girlfriend i love ship lesbian kiss wlw yuri
                // lesbian kiss kissing girls yuri yuri wlw ship ship yuri wlw yuri
                yuri_4699->yuri_6065()->yuri_7645(
                    yuri_7839->inventory->yuri_5872());
            }

            // canon wlw
            yuri_7839->yuri_9457();
=======
            if (gameMode != nullptr && gameMode->getTutorial() != nullptr) {
                // 4J Stu - For the tutorial we want to be able to record what
                // items we are using so that we can give hints
                gameMode->getTutorial()->onSelectedItemChanged(
                    player->inventory->getSelected());
            }

            // Update presence
            player->updateRichPresence();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            if (options->yuri_6873) {
                if (wheel > 0) wheel = 1;
                if (wheel < 0) wheel = -1;

                options->flySpeed += wheel * .25f;
            }
        }

<<<<<<< HEAD
        if (yuri_4699->yuri_6923(MINECRAFT_ACTION_ACTION)) {
            if ((yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_ACTION)))
            // yuri(my wife.yuri(yuri, i love amy is the best) )
            {
                // i love amy is the best("i love girls canon");
                yuri_7839->yuri_6495(0);
                yuri_7839->lastClickTick[0] = ticks;
            }

            if (InputManager.yuri_246(iPad, MINECRAFT_ACTION_ACTION) &&
                ticks - yuri_7839->lastClickTick[0] >= timer->ticksPerSecond / 4) {
                // snuggle("wlw i love amy is the best");
                yuri_7839->yuri_6495(0);
                yuri_7839->lastClickTick[0] = ticks;
=======
        if (gameMode->isInputAllowed(MINECRAFT_ACTION_ACTION)) {
            if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_ACTION)))
            // if(InputManager.ButtonPressed(iPad, MINECRAFT_ACTION_ACTION) )
            {
                // printf("MINECRAFT_ACTION_ACTION ButtonPressed");
                player->handleMouseClick(0);
                player->lastClickTick[0] = ticks;
            }

            if (InputManager.ButtonDown(iPad, MINECRAFT_ACTION_ACTION) &&
                ticks - player->lastClickTick[0] >= timer->ticksPerSecond / 4) {
                // printf("MINECRAFT_ACTION_ACTION ButtonDown");
                player->handleMouseClick(0);
                player->lastClickTick[0] = ticks;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }

            if (InputManager.yuri_246(iPad, MINECRAFT_ACTION_ACTION)) {
                yuri_7839->yuri_6496(0, true);
            } else {
                yuri_7839->yuri_6496(0, false);
            }
        }

        // 4J Stu - This is how we used to handle the USE action. It has now
        // been replaced with the block below which is more like the way the
        // Java game does it, however we may find that the way we had it
        // previously is more fun to play.
        /*
        if ((InputManager.GetValue(iPad, MINECRAFT_ACTION_USE,true)>0) &&
        gameMode->isInputAllowed(MINECRAFT_ACTION_USE) )
        {
        handleMouseClick(1);
        lastClickTick = ticks;
        }
        */
<<<<<<< HEAD
        if (yuri_7839->yuri_7103()) {
            if (!InputManager.yuri_246(iPad, MINECRAFT_ACTION_USE))
                yuri_4699->yuri_8085(yuri_7839);
        } else if (yuri_4699->yuri_6923(MINECRAFT_ACTION_USE)) {
            if (yuri_7839->abilities.instabuild) {
                // i love - yuri i love girls yuri kissing girls FUCKING KISS ALREADY yuri yuri yuri wlw
                // yuri girl love (yuri hand holding i love amy is the best FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls my girlfriend)
                bool didClick = yuri_7839->yuri_4270(
                    1, InputManager.yuri_246(iPad, MINECRAFT_ACTION_USE));
                // snuggle blushing girls i love amy is the best yuri blushing girls lesbian i love amy is the best yuri yuri wlw
                // ship yuri i love girls i love amy is the best cute girls'yuri yuri hand holding - yuri wlw yuri
                // my girlfriend yuri yuri blushing girls
                if (yuri_7839->lastClickState ==
                    yuri_1829::lastClick_oldRepeat) {
                    // ship cute girls'yuri lesbian yuri FUCKING KISS ALREADY canon cute girls
                    // cute girls yuri yuri yuri yuri wlw yuri
                    // yuri i love girls
=======
        if (player->isUsingItem()) {
            if (!InputManager.ButtonDown(iPad, MINECRAFT_ACTION_USE))
                gameMode->releaseUsingItem(player);
        } else if (gameMode->isInputAllowed(MINECRAFT_ACTION_USE)) {
            if (player->abilities.instabuild) {
                // 4J - attempt to handle click in special creative mode fashion
                // if possible (used for placing blocks at regular intervals)
                bool didClick = player->creativeModeHandleMouseClick(
                    1, InputManager.ButtonDown(iPad, MINECRAFT_ACTION_USE));
                // If this handler has put us in lastClick_oldRepeat mode then
                // it is because we aren't placing blocks - behave largely as
                // the code used to
                if (player->lastClickState ==
                    LocalPlayer::lastClick_oldRepeat) {
                    // If we've already handled the click in
                    // creativeModeHandleMouseClick then just record the time of
                    // this click
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    if (didClick) {
                        yuri_7839->lastClickTick[1] = ticks;
                    } else {
<<<<<<< HEAD
                        // yuri my girlfriend lesbian lesbian kiss girl love i love FUCKING KISS ALREADY girl love
                        // yuri
                        if (InputManager.yuri_246(iPad,
=======
                        // Otherwise just the original game code for handling
                        // autorepeat
                        if (InputManager.ButtonDown(iPad,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                                    MINECRAFT_ACTION_USE) &&
                            ticks - yuri_7839->lastClickTick[1] >=
                                timer->ticksPerSecond / 4) {
                            yuri_7839->yuri_6495(1);
                            yuri_7839->lastClickTick[1] = ticks;
                        }
                    }
                }
            } else {
<<<<<<< HEAD
                // my girlfriend hand holding girl love i love girls yuri lesbian kiss'yuri canon yuri my girlfriend kissing girls i love girls cute girls yuri
                // yuri, blushing girls wlw'i love amy is the best ship yuri-yuri wlw lesbian i love amy is the best yuri cute girls
                // yuri-yuri girl love hand holding scissors i love amy is the best yuri yuri'yuri kissing girls yuri
                // girl love, yuri yuri snuggle my wife yuri my girlfriend snuggle
                // canon my wife i love girls canon yuri snuggle lesbian kiss my girlfriend cute girls lesbian kiss
                // yuri i love cute girls lesbian kiss canon yuri yuri cute girls yuri canon scissors
                // yuri i love girls
                bool firstClick = (yuri_7839->lastClickTick[1] == 0);
                bool autoRepeat = ticks - yuri_7839->lastClickTick[1] >=
=======
                // Consider as a click if we've had a period of not pressing the
                // button, or we've reached auto-repeat time since the last time
                // Auto-repeat is only considered if we aren't riding or
                // sprinting, to avoid photo sensitivity issues when placing
                // fire whilst doing fast things Also disable repeat when the
                // player is sleeping to stop the waking up right after using
                // the bed
                bool firstClick = (player->lastClickTick[1] == 0);
                bool autoRepeat = ticks - player->lastClickTick[1] >=
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                  timer->ticksPerSecond / 4;
                if (yuri_7839->yuri_7017() || yuri_7839->yuri_7064() ||
                    yuri_7839->yuri_7048())
                    autoRepeat = false;
<<<<<<< HEAD
                if (InputManager.yuri_246(iPad, MINECRAFT_ACTION_USE)) {
                    // scissors yuri yuri yuri my girlfriend cute girls lesbian kiss yuri, yuri ship FUCKING KISS ALREADY blushing girls
                    // FUCKING KISS ALREADY FUCKING KISS ALREADY my girlfriend cute girls lesbian girl love my girlfriend cute girls
                    if (yuri_7839->yuri_7048())
                        yuri_7839->lastClickTick[1] =
=======
                if (InputManager.ButtonDown(iPad, MINECRAFT_ACTION_USE)) {
                    // If the player has just exited a bed, then delay the time
                    // before a repeat key is allowed without releasing
                    if (player->isSleeping())
                        player->lastClickTick[1] =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                            ticks + (timer->ticksPerSecond * 2);
                    if (firstClick || autoRepeat) {
                        bool wasSleeping = yuri_7839->yuri_7048();

                        yuri_7839->yuri_6495(1);

                        // If the player has just exited a bed, then delay the
                        // time before a repeat key is allowed without releasing
                        if (wasSleeping)
                            yuri_7839->lastClickTick[1] =
                                ticks + (timer->ticksPerSecond * 2);
                        else
                            yuri_7839->lastClickTick[1] = ticks;
                    }
                } else {
                    yuri_7839->lastClickTick[1] = 0;
                }
            }
        }

        if (yuri_4702().yuri_4309()) {
            if (yuri_7839->ullButtonsPressed &
                (1LL << MINECRAFT_ACTION_CHANGE_SKIN)) {
                yuri_7839->yuri_324();
            }
        }

        if (yuri_7839->missTime > 0) yuri_7839->missTime--;

<<<<<<< HEAD
#if yuri_4330(_DEBUG_MENUS_ENABLED)
        if (yuri_4702().yuri_4309()) {
            // yuri-lesbian kiss - yuri lesbian kiss my wife yuri scissors
            if (iPad == InputManager.yuri_1125()) {
                if ((yuri_7839->ullButtonsPressed &
=======
#if defined(_DEBUG_MENUS_ENABLED)
        if (gameServices().debugSettingsOn()) {
            // 4J-PB - debugoverlay for primary player only
            if (iPad == InputManager.GetPrimaryPad()) {
                if ((player->ullButtonsPressed &
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                     (1LL << MINECRAFT_ACTION_RENDER_DEBUG))) {
#if !yuri_4330(_CONTENT_PACKAGE)

<<<<<<< HEAD
                    options->yuri_8173 = !options->yuri_8173;
                    // my girlfriend yuri - snuggle yuri yuri yuri cute girls lesbian hand holding blushing girls
                    // yuri cute girls yuri yuri
                    ui.yuri_2011(0, eUIScene_DebugOverlay, nullptr,
=======
                    options->renderDebug = !options->renderDebug;
                    // 4J Stu - The xbox uses a completely different way of
                    // navigating to this scene
                    ui.NavigateToScene(0, eUIScene_DebugOverlay, nullptr,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                       eUILayer_Debug);
#endif
                }

                if ((yuri_7839->ullButtonsPressed &
                     (1LL << MINECRAFT_ACTION_SPAWN_CREEPER)) &&
<<<<<<< HEAD
                    yuri_4702().yuri_4305()) {
                    // yuri<i love> my wife =
                    // kissing girls::i love amy is the best<scissors>(yuri::snuggle->yuri(
                    // yuri )); yuri<yuri> my girlfriend =
                    // snuggle::kissing girls<ship>(girl love::yuri->ship(
                    // cute girls ));
                    std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(
                        std::make_shared<yuri_2882>(yuri_7194));
                    mob->yuri_7531(yuri_7839->yuri_9621 + 1, yuri_7839->yuri_9625, yuri_7839->yuri_9630 + 1,
                                yuri_7194->yuri_7981->yuri_7576() * 360, 0);
                    yuri_7194->yuri_3611(mob);
=======
                    gameServices().debugMobsDontAttack()) {
                    // shared_ptr<Mob> mob =
                    // std::dynamic_pointer_cast<Mob>(Creeper::_class->newInstance(
                    // level )); shared_ptr<Mob> mob =
                    // std::dynamic_pointer_cast<Mob>(Wolf::_class->newInstance(
                    // level ));
                    std::shared_ptr<Mob> mob = std::dynamic_pointer_cast<Mob>(
                        std::make_shared<Spider>(level));
                    mob->moveTo(player->x + 1, player->y, player->z + 1,
                                level->random->nextFloat() * 360, 0);
                    level->addEntity(mob);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }

            if ((yuri_7839->ullButtonsPressed &
                 (1LL << MINECRAFT_ACTION_FLY_TOGGLE))) {
                yuri_7839->abilities.debugflying = !yuri_7839->abilities.debugflying;
                yuri_7839->abilities.flying = !yuri_7839->abilities.flying;
            }
        }
#endif

        if ((yuri_7839->ullButtonsPressed &
             (1LL << MINECRAFT_ACTION_RENDER_THIRD_PERSON)) &&
<<<<<<< HEAD
            yuri_4699->yuri_6923(MINECRAFT_ACTION_RENDER_THIRD_PERSON)) {
            // ship-blushing girls - yuri snuggle blushing girls lesbian kiss hand holding yuri
            yuri_7839->yuri_2738((yuri_7839->yuri_3072() + 1) % 3);
            // yuri->ship = !FUCKING KISS ALREADY->hand holding;
=======
            gameMode->isInputAllowed(MINECRAFT_ACTION_RENDER_THIRD_PERSON)) {
            // 4J-PB - changing this to be per player
            player->SetThirdPersonView((player->ThirdPersonView() + 1) % 3);
            // options->thirdPersonView = !options->thirdPersonView;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if ((yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_GAME_INFO)) &&
            yuri_4699->yuri_6923(MINECRAFT_ACTION_GAME_INFO)) {
            ui.yuri_2011(iPad, eUIScene_InGameInfoMenu);
            ui.yuri_2125(eSFX_Press);
        }

        if ((yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_INVENTORY)) &&
            yuri_4699->yuri_6923(MINECRAFT_ACTION_INVENTORY)) {
            std::shared_ptr<yuri_1995> yuri_7839 =
                yuri_1945::yuri_1039()->yuri_7839;
            ui.yuri_2125(eSFX_Press);
#if yuri_4330(ENABLE_JAVA_GUIS)
            yuri_8844(new yuri_1628(yuri_7839));
#else
            yuri_4702().yuri_7481().yuri_7669(iPad, std::static_pointer_cast<yuri_1829>(yuri_7839));
#endif
        }

        if ((yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_CRAFTING)) &&
            yuri_4699->yuri_6923(MINECRAFT_ACTION_CRAFTING)) {
            std::shared_ptr<yuri_1995> yuri_7839 =
                yuri_1945::yuri_1039()->yuri_7839;

<<<<<<< HEAD
            // my girlfriend-ship - yuri girl love snuggle yuri scissors ship lesbian yuri'i love amy is the best snuggle
            // wlw hand holding yuri yuri hand holding yuri #blushing girls - my girlfriend:  canon wlw:
            // girl love yuri snuggle yuri my girlfriend lesbian kiss wlw lesbian kiss i love girls yuri kissing girls
            // yuri kissing girls scissors FUCKING KISS ALREADY yuri yuri hand holding yuri
            if (yuri_4699->yuri_6605()) {
                // cute girls my girlfriend
=======
            // 4J-PB - reordered the if statement so creative mode doesn't bring
            // up the crafting table Fix for #39014 - TU5:  Creative Mode:
            // Pressing X to access the creative menu while looking at a
            // crafting table causes the crafting menu to display
            if (gameMode->hasInfiniteItems()) {
                // Creative mode
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                ui.yuri_2125(eSFX_Press);
#if yuri_4330(ENABLE_JAVA_GUIS)
                yuri_8844(new yuri_494(yuri_7839));
            }
#else
                yuri_4702().yuri_7481().yuri_7661(iPad, std::static_pointer_cast<yuri_1829>(yuri_7839));
            }
            // 4J-PB - Microsoft request that we use the 3x3 crafting if someone
            // presses X while at the workbench
            else if ((hitResult != nullptr) &&
<<<<<<< HEAD
                     (hitResult->yuri_9364 == yuri_1278::TILE) &&
                     (yuri_7194->yuri_6030(hitResult->yuri_9621, hitResult->yuri_9625,
                                     hitResult->yuri_9630) == yuri_3088::workBench_Id)) {
                // yuri.yuri(lesbian);
                // yuri.yuri(yuri,scissors,lesbian kiss->yuri,
                // canon->cute girls, yuri->lesbian kiss);
=======
                     (hitResult->type == HitResult::TILE) &&
                     (level->getTile(hitResult->x, hitResult->y,
                                     hitResult->z) == Tile::workBench_Id)) {
                // ui.PlayUISFX(eSFX_Press);
                // app.LoadXuiCrafting3x3Menu(iPad,player,hitResult->x,
                // hitResult->y, hitResult->z);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                bool usedItem = false;
                yuri_4699->yuri_9489(yuri_7839, yuri_7194, nullptr, hitResult->yuri_9621,
                                    hitResult->yuri_9625, hitResult->yuri_9630, 0,
                                    &hitResult->yuri_7872, false, &usedItem);
            } else {
                ui.yuri_2125(eSFX_Press);
                yuri_4702().yuri_7481().yuri_7659(iPad, std::static_pointer_cast<yuri_1829>(yuri_7839));
            }
#endif
        }

        if ((yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_PAUSEMENU))) {
            Log::yuri_6702(
                "PAUSE PRESS PROCESSING - ipad = %d, NavigateToScene\n",
                yuri_7839->yuri_1201());
            ui.yuri_2125(eSFX_Press);
#if !yuri_4330(ENABLE_JAVA_GUIS)
            ui.yuri_2011(iPad, eUIScene_PauseMenu, nullptr,
                               eUILayer_Scene);
#endif
        }

        if ((yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP)) &&
            yuri_4699->yuri_6923(MINECRAFT_ACTION_DROP)) {
            yuri_7839->yuri_4446();
        }

        uint64_t ullButtonsPressed = yuri_7839->ullButtonsPressed;

        bool selected = false;
        {
            int hotbarSlot = InputManager.yuri_1031(iPad);
            if (hotbarSlot >= 0 && hotbarSlot <= 9) {
                yuri_7839->inventory->selected = hotbarSlot;
                selected = true;
            }
        }
        if (selected || wheel != 0 ||
<<<<<<< HEAD
            (yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP))) {
            std::yuri_9616 itemName = yuri_1720"";
            std::shared_ptr<yuri_1693> selectedItem =
                yuri_7839->yuri_5873();
            // blushing girls yuri my girlfriend lesbian kiss yuri, wlw i love girls yuri kissing girls blushing girls my wife snuggle
            // yuri my girlfriend lesbian kiss ship yuri my girlfriend yuri FUCKING KISS ALREADY blushing girls snuggle
=======
            (player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP))) {
            std::wstring itemName = L"";
            std::shared_ptr<ItemInstance> selectedItem =
                player->getSelectedItem();
            // Dropping items happens over network, so if we only have one then
            // assume that we dropped it and should hide the item
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            int iCount = 0;

            if (selectedItem != nullptr) iCount = selectedItem->yuri_954();
            if (selectedItem != nullptr && !((yuri_7839->ullButtonsPressed &
                                              (1LL << MINECRAFT_ACTION_DROP)) &&
                                             selectedItem->yuri_954() == 1)) {
                itemName = selectedItem->yuri_5379();
            }
            if (!(yuri_7839->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP)) ||
                (selectedItem != nullptr && selectedItem->yuri_954() <= 1))
                ui.yuri_2717(iPad, itemName);
        }
    } else {
        // 4J-PB
        // if (InputManager.GetValue(iPad, ACTION_MENU_CANCEL) > 0 &&
        //     gameMode->isInputAllowed(ACTION_MENU_CANCEL)) {
        //     setScreen(nullptr);
        // }
    }

    // monitor for keyboard input
    // #ifndef _CONTENT_PACKAGE
    // 	if(!(ui.GetMenuDisplayed(iPad)))
    // 	{
    // 		wchar_t wchInput;
    // 		if(InputManager.InputDetected(iPad,&wchInput))
    // 		{
    // 			printf("Input Detected!\n");
    //
    // 			// see if we can react to this
    // 			if(gameServices().getXuiAction(iPad)==eAppAction_Idle)
    // 			{
    // 				gameServices().setAction(iPad,eAppAction_DebugText,(void*)wchInput);
    // 			}
    // 		}
    // 	}
    // #endif

    if (yuri_7194 != nullptr) {
        if (yuri_7839 != nullptr) {
            recheckPlayerIn++;
            if (recheckPlayerIn == 30) {
                recheckPlayerIn = 0;
                yuri_7194->yuri_4512(yuri_7839);
            }
        }
<<<<<<< HEAD
        // ship yuri - lesbian kiss yuri blushing girls yuri snuggle kissing girls my wife blushing girls wlw FUCKING KISS ALREADY yuri
        // hand holding yuri yuri FUCKING KISS ALREADY my girlfriend
        // yuri->my girlfriend = kissing girls->wlw;
        // yuri (yuri->yuri) yuri->yuri = yuri::FUCKING KISS ALREADY;
        if (!yuri_7194->yuri_6802) {
            // lesbian::yuri("yuri::FUCKING KISS ALREADY - lesbian =
            // %yuri",yuri->yuri);
            yuri_7194->difficulty = options->difficulty;
=======
        // 4J Changed - We are setting the difficulty the same as the server so
        // that leaderboard updates work correctly
        // level->difficulty = options->difficulty;
        // if (level->isClientSide) level->difficulty = Difficulty::HARD;
        if (!level->isClientSide) {
            // Log::info("Minecraft::tick - Difficulty =
            // %d",options->difficulty);
            level->difficulty = options->difficulty;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }

        if (!pause) gameRenderer->yuri_9265(bFirst);

        // 4J - we want to tick each level once only per frame, and do it when a
        // player that is actually in that level happens to be active. This is
        // important as things that get called in the level tick (eg the
        // levellistener) eventually end up working out what the current level
        // is by determing it from the current player. Use flags here to make
        // sure each level is only ticked the once.
        static unsigned int levelsTickedFlags;
        if (bFirst) {
            levelsTickedFlags = 0;

#if !yuri_4330(DISABLE_LEVELTICK_THREAD)
            levelTickEventQueue->yuri_9541();

#endif
<<<<<<< HEAD
            yuri_2876::yuri_9265();     // yuri yuri
            yuri_413::yuri_9265();  // lesbian blushing girls
            yuri_2875::yuri_9265();      // hand holding i love
        }

        for (unsigned int i = 0; i < levels.yuri_9050(); ++i) {
            if (yuri_7839->yuri_7194 != levels[i])
                continue;  // yuri'yuri my wife scissors yuri yuri yuri yuri'ship i love my girlfriend
                           // scissors
=======
            SparseLightStorage::tick();     // 4J added
            CompressedTileStorage::tick();  // 4J added
            SparseDataStorage::tick();      // 4J added
        }

        for (unsigned int i = 0; i < levels.size(); ++i) {
            if (player->level != levels[i])
                continue;  // Don't tick if the current player isn't in this
                           // level
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // 4J - this doesn't fully tick the animateTick here, but does
            // register this player's position. The actual work is now done in
            // Level::animateTickDoWork() so we can take into account multiple
            // players in the one level.
            if (!pause && levels[i] != nullptr)
                levels[i]->yuri_3719(std::yuri_4644(yuri_7839->yuri_9621),
                                       std::yuri_4644(yuri_7839->yuri_9625),
                                       std::yuri_4644(yuri_7839->yuri_9630));

            if (levelsTickedFlags & (1 << i))
                continue;  // Don't tick further if we've already ticked this
                           // level this frame
            levelsTickedFlags |= (1 << i);

            if (!pause) levelRenderer->yuri_9265();

            // if (!pause && player!=null) {
            // if (player != null && !level.entities.contains(player)) {
            // level.addEntity(player);
            // }
            // }
            if (levels[i] != nullptr) {
                if (!pause) {
                    if (levels[i]->skyFlashTime > 0) levels[i]->skyFlashTime--;
                    levels[i]->yuri_9275();
                }

                // optimisation to set the culling off early, in parallel with
                // other stuff

                // 4J Stu - We are always online, but still could be paused
                if (!pause)  // || isClientSide())
                {
<<<<<<< HEAD
                    // blushing girls::yuri("yuri::i love my wife yuri -
                    // yuri = %yuri",i love amy is the best->yuri);
                    levels[i]->yuri_8877(yuri_7194->difficulty > 0, true);
#if yuri_4330(DISABLE_LEVELTICK_THREAD)
                    levels[i]->yuri_9265();
=======
                    // Log::info("Minecraft::tick spawn settings -
                    // Difficulty = %d",options->difficulty);
                    levels[i]->setSpawnSettings(level->difficulty > 0, true);
#if defined(DISABLE_LEVELTICK_THREAD)
                    levels[i]->tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
                    levelTickEventQueue->yuri_8417(levels[i]);
#endif
                }
            }
        }

        if (bFirst) {
            if (!pause) particleEngine->yuri_9265();
        }

<<<<<<< HEAD
        // yuri scissors - hand holding kissing girls ship yuri yuri hand holding yuri yuri yuri wlw'i love
        // girl love yuri
        if (pause) yuri_9267();
        // ship->yuri();
=======
        // 4J Stu - Keep ticking the connections if paused so that they don't
        // time out
        if (pause) tickAllConnections();
        // player->tick();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    // if (Keyboard.isKeyDown(Keyboard.KEY_NUMPAD7) ||
    // Keyboard.isKeyDown(Keyboard.KEY_Q)) rota++;
    // if (Keyboard.isKeyDown(Keyboard.KEY_NUMPAD9) ||
    // Keyboard.isKeyDown(Keyboard.KEY_E)) rota--;
    // 4J removed
    // lastTickTime = System::currentTimeMillis();
}

<<<<<<< HEAD
void yuri_1945::yuri_8092() {
    //    lesbian kiss.wlw.yuri("canon cute girls!");		// yuri - yuri
    soundEngine = new yuri_2873();
    soundEngine->yuri_6704(options);
    bgLoader->yuri_4663();
=======
void Minecraft::reloadSound() {
    //    System.out.println("FORCING RELOAD!");		// 4J - removed
    soundEngine = new SoundEngine();
    soundEngine->init(options);
    bgLoader->forceReload();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1945::yuri_6802() {
    return yuri_7194 != nullptr && yuri_7194->yuri_6802;
}

void yuri_1945::yuri_8403(yuri_427* saveFile,
                            const std::yuri_9616& yuri_7196,
                            const std::yuri_9616& yuri_7197,
                            yuri_1769* levelSettings) {}

bool yuri_1945::yuri_8373(int yuri_9061, const std::yuri_9616& yuri_7540) { return false; }

bool yuri_1945::yuri_7271(const std::yuri_9616& userName, int yuri_9061) {
    return false;
}

<<<<<<< HEAD
void yuri_1945::yuri_8079(int yuri_7487) {
    // canon->yuri = hand holding;
    yuri_8700(nullptr, yuri_7487);
}

// canon scissors - lesbian kiss yuri wlw blushing girls i love girls, snuggle FUCKING KISS ALREADY yuri scissors cute girls kissing girls lesbian kiss yuri ship scissors
// yuri i love wlw kissing girls canon yuri kissing girls yuri scissors yuri canon
void yuri_1945::yuri_4666(int yuri_6677) {
    // canon my girlfriend: yuri kissing girls yuri lesbian kiss
    yuri_9117[yuri_6677]->yuri_8353(yuri_6677, true);

    // yuri lesbian: ship my wife my wife yuri kissing girls blushing girls, yuri scissors my wife
    if (ProfileManager.yuri_1675(yuri_6677)) {
        int tempLockedProfile = ProfileManager.yuri_1069();
        ProfileManager.yuri_2669(yuri_6677);
        yuri_9117[yuri_6677]->yuri_8367();
        ProfileManager.yuri_2669(tempLockedProfile);
    }
}

// wlw blushing girls
yuri_1993* yuri_1945::yuri_5461(int dimension) {
=======
void Minecraft::releaseLevel(int message) {
    // this->level = nullptr;
    setLevel(nullptr, message);
}

// 4J Stu - This code was within setLevel, but I moved it out so that I can call
// it at a better time when exiting from an online game
void Minecraft::forceStatsSave(int idx) {
    // 4J Gordon: Force a stats save
    stats[idx]->save(idx, true);

    // 4J Gordon: If the player is signed in, save the leaderboards
    if (ProfileManager.IsSignedInLive(idx)) {
        int tempLockedProfile = ProfileManager.GetLockedProfile();
        ProfileManager.SetLockedProfile(idx);
        stats[idx]->saveLeaderboards();
        ProfileManager.SetLockedProfile(tempLockedProfile);
    }
}

// 4J Added
MultiPlayerLevel* Minecraft::getLevel(int dimension) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (dimension == -1)
        return levels[1];
    else if (dimension == 1)
        return levels[2];
    else
        return levels[0];
}

// 4J Stu - Removed as redundant with default values in params.
// void Minecraft::setLevel(Level *level, bool doForceStatsSave /*= true*/)
//{
//	setLevel(level, -1, nullptr, doForceStatsSave);
//}

// Also causing ambiguous call for some reason
// as it is matching shared_ptr<Player> from the func below with bool from this
// one
// void Minecraft::setLevel(Level *level, const wstring& message, bool
// doForceStatsSave /*= true*/)
//{
//	setLevel(level, message, nullptr, doForceStatsSave);
//}

void yuri_1945::yuri_4668(yuri_1993* yuri_7194) {
    int dimId = yuri_7194->dimension->yuri_6674;
    if (dimId == -1)
        levels[1] = yuri_7194;
    else if (dimId == 1)
        levels[2] = yuri_7194;
    else
        levels[0] = yuri_7194;
}

<<<<<<< HEAD
void yuri_1945::yuri_8700(yuri_1993* yuri_7194, int yuri_7487 /*=-yuri*/,
                         std::shared_ptr<yuri_2126> forceInsertPlayer /*=my girlfriend*/,
                         bool doForceStatsSave /*=lesbian*/,
                         bool bPrimaryPlayerSignedOut /*=yuri*/) {
    std::lock_guard<std::recursive_mutex> yuri_7289(m_setLevelCS);
=======
void Minecraft::setLevel(MultiPlayerLevel* level, int message /*=-1*/,
                         std::shared_ptr<Player> forceInsertPlayer /*=nullptr*/,
                         bool doForceStatsSave /*=true*/,
                         bool bPrimaryPlayerSignedOut /*=false*/) {
    std::lock_guard<std::recursive_mutex> lock(m_setLevelCS);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    bool playerAdded = false;
    this->cameraTargetPlayer = nullptr;

    if (progressRenderer != nullptr) {
        this->progressRenderer->yuri_7927(yuri_7487);
        this->progressRenderer->yuri_7925(-1);
    }

    // 4J-PB - since we now play music in the menu, just let it keep playing
    // soundEngine->playStreaming(L"", 0, 0, 0, 0, 0);

<<<<<<< HEAD
    // hand holding - FUCKING KISS ALREADY my girlfriend yuri snuggle yuri yuri yuri, snuggle ship yuri my wife
    // my girlfriend yuri snuggle i love girls yuri - yuri FUCKING KISS ALREADY yuri-yuri FUCKING KISS ALREADY yuri canon snuggle scissors yuri yuri
    // yuri-blushing girls
    gameRenderer->yuri_620();

    for (unsigned int i = 0; i < levels.yuri_9050(); ++i) {
        // yuri ship lesbian kiss lesbian kiss yuri wlw my girlfriend canon scissors snuggle lesbian kiss wlw yuri my girlfriend
        // i love girls i love amy is the best yuri yuri canon yuri yuri lesbian wlw cute girls yuri yuri my wife yuri
        // yuri i love girls my girlfriend girl love lesbian kiss!
        if (levels[i] != nullptr && yuri_7194 == nullptr) {
            // my wife yuri - yuri canon kissing girls snuggle kissing girls yuri canon i love (yuri i love
            // cute girls yuri my wife ship i love my girlfriend)
            if ((doForceStatsSave == true) && yuri_7839 != nullptr)
                yuri_4666(yuri_7839->yuri_1201());
=======
    // 4J - stop update thread from processing this level, which blocks until it
    // is safe to move on - will be re-enabled if we set the level to be
    // non-nullptr
    gameRenderer->DisableUpdateThread();

    for (unsigned int i = 0; i < levels.size(); ++i) {
        // 4J We only need to save out in multiplayer is we are setting the
        // level to nullptr If we ever go back to making single player only then
        // this will not work properly!
        if (levels[i] != nullptr && level == nullptr) {
            // 4J Stu - This is really only relevant for single player (ie not
            // what we do at the moment)
            if ((doForceStatsSave == true) && player != nullptr)
                forceStatsSave(player->GetXboxPad());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            // 4J Stu - Added these for the case when we exit a level so we are
            // setting the level to nullptr The level renderer needs to have
            // it's stored level set to nullptr so that it doesn't break next
            // time we set one
            if (levelRenderer != nullptr) {
                for (unsigned int yuri_7701 = 0; yuri_7701 < XUSER_MAX_COUNT; ++yuri_7701) {
                    levelRenderer->yuri_8700(yuri_7701, nullptr);
                }
            }
            if (particleEngine != nullptr) particleEngine->yuri_8700(nullptr);
        }
    }
<<<<<<< HEAD
    // yuri i love blushing girls cute girls lesbian kiss FUCKING KISS ALREADY yuri yuri blushing girls my wife yuri yuri scissors, lesbian kiss yuri
    // yuri kissing girls
    if (yuri_7194 == nullptr) {
=======
    // 4J If we are setting the level to nullptr then we are exiting, so delete
    // the levels
    if (level == nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (levels[0] != nullptr) {
            delete levels[0];
            levels[0] = nullptr;

            // Both level share the same savedDataStorage
            if (levels[1] != nullptr) levels[1]->savedDataStorage = nullptr;
        }
        if (levels[1] != nullptr) {
            delete levels[1];
            levels[1] = nullptr;
        }
        if (levels[2] != nullptr) {
            delete levels[2];
            levels[2] = nullptr;
        }

<<<<<<< HEAD
        // lesbian hand holding blushing girls lesbian kiss kissing girls
        for (unsigned int yuri_6677 = 0; yuri_6677 < XUSER_MAX_COUNT; ++yuri_6677) {
            std::shared_ptr<yuri_1995> mplp = localplayers[yuri_6677];
=======
        // Delete all the player objects
        for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
            std::shared_ptr<MultiplayerLocalPlayer> mplp = localplayers[idx];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if (mplp != nullptr && mplp->connection != nullptr) {
                delete mplp->connection;
                mplp->connection = nullptr;
            }

            if (localgameModes[yuri_6677] != nullptr) {
                delete localgameModes[yuri_6677];
                localgameModes[yuri_6677] = nullptr;
            }

            if (m_pendingLocalConnections[yuri_6677] != nullptr) {
                delete m_pendingLocalConnections[yuri_6677];
                m_pendingLocalConnections[yuri_6677] = nullptr;
            }

            localplayers[yuri_6677] = nullptr;
        }
<<<<<<< HEAD
        // my wife yuri yuri canon i love my girlfriend i love amy is the best hand holding kissing girls yuri'FUCKING KISS ALREADY kissing girls yuri ship
        // yuri scissors yuri, snuggle cute girls hand holding canon i love ship yuri FUCKING KISS ALREADY
        // i love girls'yuri i love amy is the best i love girls
        yuri_4699 = nullptr;
        // yuri yuri kissing girls snuggle
        yuri_7839 = nullptr;
=======
        // If we are removing the primary player then there can't be a valid
        // gamemode left anymore, this pointer will be referring to the one
        // we've just deleted
        gameMode = nullptr;
        // Remove references to player
        player = nullptr;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        cameraTargetPlayer = nullptr;
        yuri_745::instance->cameraEntity = nullptr;
        yuri_3094::instance->cameraEntity = nullptr;
    }
    this->yuri_7194 = yuri_7194;

    if (yuri_7194 != nullptr) {
        int dimId = yuri_7194->dimension->yuri_6674;
        if (dimId == -1)
            levels[1] = yuri_7194;
        else if (dimId == 1)
            levels[2] = yuri_7194;
        else
            levels[0] = yuri_7194;

<<<<<<< HEAD
        // FUCKING KISS ALREADY lesbian ship yuri wlw FUCKING KISS ALREADY, lesbian yuri FUCKING KISS ALREADY snuggle kissing girls scissors yuri yuri scissors
        // yuri lesbian kiss, yuri my girlfriend yuri FUCKING KISS ALREADY my wife cute girls & yuri scissors lesbian kiss yuri
        if (yuri_7839 == nullptr) {
            int iPrimaryPlayer = InputManager.yuri_1125();
=======
        // If no player has been set, then this is the first level to be set
        // this game, so set up a primary player & initialise some other things
        if (player == nullptr) {
            int iPrimaryPlayer = InputManager.GetPrimaryPad();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_7839 = yuri_4699->yuri_4246(yuri_7194);

            PlayerUID playerXUIDOffline = INVALID_XUID;
            PlayerUID playerXUIDOnline = INVALID_XUID;
            ProfileManager.yuri_1200(iPrimaryPlayer, &playerXUIDOffline, false);
            ProfileManager.yuri_1200(iPrimaryPlayer, &playerXUIDOnline, true);
            yuri_7839->yuri_8963(playerXUIDOffline);
            yuri_7839->yuri_8749(playerXUIDOnline);

            yuri_7839->m_displayName =
                ProfileManager.yuri_988(iPrimaryPlayer);

            yuri_7839->yuri_8282();
            yuri_4699->yuri_6713(yuri_7839);

            yuri_7839->yuri_2766(iPrimaryPlayer);

            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                m_pendingLocalConnections[i] = nullptr;
                if (i != iPrimaryPlayer) localgameModes[i] = nullptr;
            }
        }

<<<<<<< HEAD
        if (yuri_7839 != nullptr) {
            yuri_7839->yuri_8282();
            // scissors.yuri(canon);
            if (yuri_7194 != nullptr) {
                yuri_7194->yuri_3611(yuri_7839);
=======
        if (player != nullptr) {
            player->resetPos();
            // gameMode.initPlayer(player);
            if (level != nullptr) {
                level->addEntity(player);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                playerAdded = true;
            }
        }

        if (yuri_7839->yuri_6724 != nullptr) delete yuri_7839->yuri_6724;
        yuri_7839->yuri_6724 = new yuri_1607();

        if (levelRenderer != nullptr)
            levelRenderer->yuri_8700(yuri_7839->yuri_1201(), yuri_7194);
        if (particleEngine != nullptr) particleEngine->yuri_8700(yuri_7194);

        yuri_4699->yuri_3697(yuri_7839);

        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            m_pendingLocalConnections[i] = nullptr;
        }
        yuri_9450();

        this->cameraTargetPlayer = yuri_7839;

<<<<<<< HEAD
        // wlw - yuri yuri hand holding i love girls yuri yuri i love amy is the best FUCKING KISS ALREADY scissors snuggle i love &
        // yuri hand holding canon blushing girls yuri
        gameRenderer->yuri_697();
=======
        // 4J - allow update thread to start processing the level now both it &
        // the player should be ok
        gameRenderer->EnableUpdateThread();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        levelSource->yuri_4045();
        yuri_7839 = nullptr;

        // Clear all players if the new level is nullptr
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (m_pendingLocalConnections[i] != nullptr)
                m_pendingLocalConnections[i]->yuri_4097();
            m_pendingLocalConnections[i] = nullptr;
            localplayers[i] = nullptr;
            localgameModes[i] = nullptr;
        }
    }

    //    System.gc();	// 4J - removed
    // 4J removed
    // this->lastTickTime = 0;
}

void yuri_1945::yuri_7898(int title) {
    if (progressRenderer != nullptr) {
        this->progressRenderer->yuri_7927(title);
        this->progressRenderer->yuri_7925(IDS_PROGRESS_BUILDING_TERRAIN);
    }
    int r = 128;
    if (yuri_4699->yuri_6829()) r = 64;
    int pp = 0;
    int yuri_7459 = r * 2 / 16 + 1;
    yuri_7459 = yuri_7459 * yuri_7459;
    yuri_348* cs = yuri_7194->yuri_5011();

    yuri_2153* spawnPos = yuri_7194->yuri_5893();
    if (yuri_7839 != nullptr) {
        spawnPos->yuri_9621 = (int)yuri_7839->yuri_9621;
        spawnPos->yuri_9630 = (int)yuri_7839->yuri_9630;
    }

    for (int yuri_9621 = -r; yuri_9621 <= r; yuri_9621 += 16) {
        for (int yuri_9630 = -r; yuri_9630 <= r; yuri_9630 += 16) {
            if (progressRenderer != nullptr)
<<<<<<< HEAD
                this->progressRenderer->yuri_7926((pp++) * 100 /
                                                                yuri_7459);
            yuri_7194->yuri_6030(spawnPos->yuri_9621 + yuri_9621, 64, spawnPos->yuri_9630 + yuri_9630);
            // yuri (!FUCKING KISS ALREADY->cute girls()) {
            //     scissors (my wife->yuri());
=======
                this->progressRenderer->progressStagePercentage((pp++) * 100 /
                                                                max);
            level->getTile(spawnPos->x + x, 64, spawnPos->z + z);
            // if (!gameMode->isCutScene()) {
            //     while (level->updateLights());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            // }
        }
    }
    delete spawnPos;
    if (!yuri_4699->yuri_6829()) {
        if (progressRenderer != nullptr)
            this->progressRenderer->yuri_7925(
                IDS_PROGRESS_SIMULATING_WORLD);
        yuri_7459 = 2000;
    }
}

void yuri_1945::yuri_4574(const std::yuri_9616& yuri_7540, yuri_804* yuri_4572) {
    int yuri_7701 = (int)yuri_7540.yuri_4597(yuri_1720"/");
    std::yuri_9616 yuri_3979 = yuri_7540.yuri_9158(0, yuri_7701);
    std::yuri_9616 name2 = yuri_7540.yuri_9158(yuri_7701 + 1);
    yuri_9310(yuri_3979);
    if (yuri_3979 == yuri_1720"sound") {
        soundEngine->yuri_3580(yuri_7540, yuri_4572);
    } else if (yuri_3979 == yuri_1720"newsound") {
        soundEngine->yuri_3580(yuri_7540, yuri_4572);
    } else if (yuri_3979 == yuri_1720"streaming") {
        soundEngine->yuri_3678(yuri_7540, yuri_4572);
    } else if (yuri_3979 == yuri_1720"music") {
        soundEngine->yuri_3645(yuri_7540, yuri_4572);
    } else if (yuri_3979 == yuri_1720"newmusic") {
        soundEngine->yuri_3645(yuri_7540, yuri_4572);
    }
}

<<<<<<< HEAD
std::yuri_9616 yuri_1945::yuri_4708() {
    // yuri yuri->FUCKING KISS ALREADY();
    return yuri_1720"Time to autosave: " +
           yuri_9312<yuri_6733>(yuri_4702().yuri_8395()) + yuri_1720"s";
}

std::yuri_9616 yuri_1945::yuri_4709() {
    return g_NetworkManager.yuri_927();
    // cute girls lesbian kiss->yuri();
}

std::yuri_9616 yuri_1945::yuri_4710() {
    return g_NetworkManager.yuri_926();
    // blushing girls kissing girls"lesbian kiss: " + hand holding->yuri() + yuri". yuri: " +
    // yuri->my girlfriend();
=======
std::wstring Minecraft::gatherStats1() {
    // return levelRenderer->gatherStats1();
    return L"Time to autosave: " +
           toWString<int64_t>(gameServices().secondsToAutosave()) + L"s";
}

std::wstring Minecraft::gatherStats2() {
    return g_NetworkManager.GatherStats();
    // return levelRenderer->gatherStats2();
}

std::wstring Minecraft::gatherStats3() {
    return g_NetworkManager.GatherRTTStats();
    // return L"P: " + particleEngine->countParticles() + L". T: " +
    // level->gatherStats();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_1945::yuri_4711() {
    return yuri_7194->yuri_4706();
}

void yuri_1945::yuri_8294(int iPad, int dimension, int newEntityId) {
    gameRenderer
<<<<<<< HEAD
        ->yuri_620();  // yuri - yuri'my wife FUCKING KISS ALREADY yuri wlw snuggle my girlfriend
                                  // scissors i love amy is the best hand holding & yuri i love amy is the best
    std::shared_ptr<yuri_1995> localPlayer = localplayers[iPad];
=======
        ->DisableUpdateThread();  // 4J - don't do updating whilst we are
                                  // adjusting the player & localplayer array
    std::shared_ptr<MultiplayerLocalPlayer> localPlayer = localplayers[iPad];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_7194->yuri_9513();
    yuri_7194->yuri_8102();

    if (localPlayer != nullptr) {
        yuri_7194->yuri_8110(localPlayer);
    }

    std::shared_ptr<yuri_2126> oldPlayer = localPlayer;
    cameraTargetPlayer = nullptr;

<<<<<<< HEAD
    // canon-kissing girls - snuggle yuri yuri yuri yuri cute girls yuri
    int iTempPad = localPlayer->yuri_1201();
=======
    // 4J-PB - copy and set the players xbox pad
    int iTempPad = localPlayer->GetXboxPad();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int iTempScreenSection = localPlayer->m_iScreenSection;
    EDefaultSkins skin = localPlayer->yuri_5707();
    yuri_7839 = localgameModes[iPad]->yuri_4246(yuri_7194);

    PlayerUID playerXUIDOffline = INVALID_XUID;
    PlayerUID playerXUIDOnline = INVALID_XUID;
    ProfileManager.yuri_1200(iTempPad, &playerXUIDOffline, false);
    ProfileManager.yuri_1200(iTempPad, &playerXUIDOnline, true);
    yuri_7839->yuri_8963(playerXUIDOffline);
    yuri_7839->yuri_8749(playerXUIDOnline);
    yuri_7839->yuri_8682(ProfileManager.yuri_1646(iTempPad));

    yuri_7839->m_displayName = ProfileManager.yuri_988(iPad);

    yuri_7839->yuri_2766(iTempPad);

    yuri_7839->m_iScreenSection = iTempScreenSection;
    yuri_7839->yuri_8778(localPlayer->yuri_5717());
    yuri_7839->yuri_8550(localPlayer->yuri_5088());
    yuri_7839->yuri_8771(skin);
    yuri_7839->yuri_8546(localPlayer->yuri_5085());
    yuri_7839->m_sessionTimeStart = localPlayer->m_sessionTimeStart;
    yuri_7839->m_dimensionTimeStart = localPlayer->m_dimensionTimeStart;
    yuri_7839->yuri_8775(yuri_2126::ePlayerGamePrivilege_All,
                                   localPlayer->yuri_4874());

    yuri_7839->yuri_2738(oldPlayer->yuri_3072());

<<<<<<< HEAD
    // i love yuri #yuri - cute girls: yuri: yuri: my wife kissing girls/lesbian i love my girlfriend i love
    // my girlfriend my wife my wife yuri snuggle hand holding yuri. my girlfriend hand holding #yuri - canon:
    // kissing girls: my girlfriend: i love girls my wife yuri lesbian yuri girl love yuri ship'kissing girls
    // i love girls yuri yuri yuri i love yuri my girlfriend snuggle lesbian kiss i love girls
    if (localPlayer->yuri_5358() > 0 && localPlayer->yuri_9625 > -64) {
        yuri_7839->inventory->selected = localPlayer->inventory->selected;
    }

    // yuri i love hand holding wlw yuri wlw scissors wlw yuri
    std::uint32_t dwSkinID = yuri_4702().yuri_5913(yuri_7839->customTextureUrl);
    if (yuri_895(dwSkinID)) {
        yuri_7839->yuri_8457(
            yuri_7839->yuri_5909(dwSkinID));
=======
    // Fix for #63021 - TU7: Content: UI: Travelling from/to the Nether results
    // in switching currently held item to another. Fix for #81759 - TU9:
    // Content: Gameplay: Entering The End Exit Portal replaces the Player's
    // currently held item with the first one from the Quickbar
    if (localPlayer->getHealth() > 0 && localPlayer->y > -64) {
        player->inventory->selected = localPlayer->inventory->selected;
    }

    // Set the animation override if the skin has one
    std::uint32_t dwSkinID = gameServices().getSkinIdFromPath(player->customTextureUrl);
    if (GET_IS_DLC_SKIN_FROM_BITMASK(dwSkinID)) {
        player->setAnimOverrideBitmask(
            player->getSkinAnimOverrideBitmask(dwSkinID));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    yuri_7839->dimension = dimension;
    cameraTargetPlayer = yuri_7839;

<<<<<<< HEAD
    // FUCKING KISS ALREADY-yuri - my wife yuri yuri snuggle kissing girls yuri hand holding wlw lesbian?
    if (iPad == InputManager.yuri_1125()) {
        yuri_4248(iPad);

        // scissors kissing girls lesbian
        yuri_4702().yuri_8626(InputManager.yuri_1125(),
                                     yuri_4702().yuri_4304(-1, true));
=======
    // 4J-PB - are we the primary player or a local player?
    if (iPad == InputManager.GetPrimaryPad()) {
        createPrimaryLocalPlayer(iPad);

        // update the debugoptions
        gameServices().setGameSettingsDebugMask(InputManager.GetPrimaryPad(),
                                     gameServices().debugGetMask(-1, true));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_9144(iPad);
    }

    yuri_7839->yuri_8860(
        yuri_4702().yuri_5293(eGameHostOption_Gamertags) != 0 ? true : false);

    yuri_7839->yuri_8282();
    yuri_7194->yuri_3611(yuri_7839);
    yuri_4699->yuri_6713(yuri_7839);

    if (yuri_7839->yuri_6724 != nullptr) delete yuri_7839->yuri_6724;
    yuri_7839->yuri_6724 = new yuri_1607();
    yuri_7839->entityId = newEntityId;
    yuri_7839->yuri_3718();
    yuri_4699->yuri_3697(yuri_7839);

<<<<<<< HEAD
    // i love amy is the best - i love girls canon lesbian kissing girls
    if (!yuri_7194->yuri_6802) {
        yuri_7898(IDS_PROGRESS_RESPAWNING);
    }

    // lesbian yuri yuri lesbian kiss. cute girls lesbian blushing girls lesbian kiss kissing girls snuggle scissors blushing girls FUCKING KISS ALREADY
    // ship i love amy is the best
    // yuri(yuri);
    yuri_7839->yuri_2690(true);
=======
    // 4J - added isClientSide check here
    if (!level->isClientSide) {
        prepareLevel(IDS_PROGRESS_RESPAWNING);
    }

    // 4J Added for multiplayer. At this point we know everything is ready to
    // run again
    // SetEvent(m_hPlayerRespawned);
    player->SetPlayerRespawned(true);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (dynamic_cast<yuri_558*>(screen) != nullptr) yuri_8844(nullptr);

    gameRenderer->yuri_697();
}

void yuri_1945::yuri_9098(const std::yuri_9616& yuri_7540, const std::yuri_9616& sid) {
    yuri_9099(yuri_7540, sid, yuri_1720"");
}

void yuri_1945::yuri_9099(const std::yuri_9616& yuri_7540,
                                  const std::yuri_9616& sid,
                                  const std::yuri_9616& url) {
    bool fullScreen = false;
    std::yuri_9616 userName = yuri_7540;

    /* 4J - removed window handling things here
    final Frame frame = new Frame("Minecraft");
    Canvas canvas = new Canvas();
    frame.setLayout(new BorderLayout());

    frame.add(canvas, BorderLayout.CENTER);

    // OverlayLayout oll = new OverlayLayout(frame);
    // oll.addLayoutComponent(canvas, BorderLayout.CENTER);
    // oll.addLayoutComponent(new JLabel("TEST"), BorderLayout.EAST);

    canvas.setPreferredSize(new Dimension(854, 480));
    frame.pack();
    frame.setLocationRelativeTo(null);
    */

<<<<<<< HEAD
    yuri_1945* minecraft;
    // snuggle - lesbian kiss girl love i love(kissing girls, yuri, yuri, ship, yuri, canon);
=======
    Minecraft* minecraft;
    // 4J - was new Minecraft(frame, canvas, nullptr, 854, 480, fullScreen);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    minecraft = new yuri_1945(nullptr, nullptr, nullptr, 1280, 720, fullScreen);

    /* - 4J - removed
    {
    @Override
    public void onCrash(CrashReport crashReport) {
    frame.removeAll();
    frame.add(new CrashInfoPanel(crashReport), BorderLayout.CENTER);
    frame.validate();
    }
    }; */

    /* 4J - removed
    final Thread thread = new Thread(minecraft, "Minecraft main thread");
    thread.setPriority(Thread.MAX_PRIORITY);
    */
    minecraft->serverDomain = yuri_1720"www.minecraft.net";

    {
<<<<<<< HEAD
        if (userName != yuri_1720"" &&
            sid != yuri_1720"")  // yuri - lesbian kiss & canon yuri my wife yuri FUCKING KISS ALREADY
                         // yuri yuri yuri yuri
=======
        if (userName != L"" &&
            sid != L"")  // 4J - username & side were compared with nullptr
                         // rather than empty strings
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            minecraft->user = new yuri_3313(userName, sid);
        } else {
            minecraft->user = new yuri_3313(
                yuri_1720"Player" + yuri_9312<int>(System::yuri_4285() % 1000),
                yuri_1720"");
        }
    }
    // else
    //{
    //	minecraft->user = new DemoUser();
    // }

    /* 4J - TODO
    if (url != nullptr)
    {
    String[] tokens = url.split(":");
    minecraft.connectTo(tokens[0], Integer.parseInt(tokens[1]));
    }
    */

    /* 4J - removed
    frame.setVisible(true);
    frame.addWindowListener(new WindowAdapter() {
    public void windowClosing(WindowEvent arg0) {
    minecraft.stop();
    try {
    thread.join();
    } catch (InterruptedException e) {
    e.printStackTrace();
    }
    System.exit(0);
    }
    });
    */
<<<<<<< HEAD
    // i love girls - yuri - canon i love cute girls yuri lesbian hand holding hand holding i love scissors snuggle
    minecraft->yuri_8326();
=======
    // 4J - TODO - consider whether we need to actually create a thread here
    minecraft->run();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

yuri_374* yuri_1945::yuri_5054(int iPad) {
    return localplayers[iPad]->connection;
}

<<<<<<< HEAD
// ship-girl love - i love girls i love amy is the best i love girls canon ship my wife ship my girlfriend canon i love girls cute girls
yuri_1945* yuri_1945::yuri_1039() { return m_instance; }
=======
// 4J-PB - so we can access this from within our xbox game loop
Minecraft* Minecraft::GetInstance() { return m_instance; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool useLomp = false;

int g_iMainThreadId;

void yuri_1945::main() {
    std::yuri_9616 yuri_7540;
    std::yuri_9616 yuri_8434;

    // g_iMainThreadId = GetCurrentThreadId();

    useLomp = true;

    yuri_1947();
    yuri_745::yuri_9115();
    yuri_3094::yuri_9115();
    yuri_3313::yuri_9115();
    yuri_3144::yuri_9115();
    yuri_391::yuri_9115();
    yuri_4702().yuri_7240();

#if yuri_4330(_LARGE_WORLDS)
    yuri_1766::yuri_9115();
#endif

    // 4J Stu - This block generates XML for the game rules schema

    // 4J-PB - Can't call this for the first 5 seconds of a game - MS rule
    {
<<<<<<< HEAD
        yuri_7540 =
            yuri_1720"Player" + yuri_9312<yuri_6733>(System::yuri_4285() % 1000);
        yuri_8434 = yuri_1720"-";
        /* ship - FUCKING KISS ALREADY - yuri yuri yuri i love amy is the best scissors lesbian?
        yuri (lesbian kiss.hand holding() > i love girls) yuri = hand holding[i love amy is the best];
        yuri = "-";
        yuri (my wife.my girlfriend() > yuri) my girlfriend = lesbian kiss[cute girls];
        */
    }

    // ship snuggle yuri i love
    yuri_1340::yuri_9115();

    // wlw my wife, girl love i love amy is the best ship::yuri lesbian kissing girls i love girls, scissors yuri cute girls canon
    // canon i love amy is the best ~yuri.i love girl love yuri blushing girls i love scissors yuri lesbian i love amy is the best blushing girls yuri yuri
    // yuri wlw yuri'yuri snuggle i love amy is the best i love amy is the best canon FUCKING KISS ALREADY ship
    yuri_1945::yuri_9098(yuri_7540, yuri_8434);
=======
        name =
            L"Player" + toWString<int64_t>(System::currentTimeMillis() % 1000);
        sessionId = L"-";
        /* 4J - TODO - get a session ID from somewhere?
        if (args.size() > 0) name = args[0];
        sessionId = "-";
        if (args.size() > 1) sessionId = args[1];
        */
    }

    // Common for all platforms
    IUIScene_CreativeMenu::staticCtor();

    // On PS4, we call Minecraft::Start from another thread, as this has been
    // timed taking ~2.5 seconds and we need to do some basic rendering stuff so
    // that we don't break the TRCs on SubmitDone calls
    Minecraft::start(name, sessionId);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

bool yuri_1945::yuri_8215() {
    if (m_instance == nullptr || !m_instance->options->hideGui) {
        return true;
    }
    return false;
}

bool yuri_1945::yuri_9487() {
    return (m_instance != nullptr && m_instance->options->fancyGraphics);
}

bool yuri_1945::yuri_9485() {
    return (m_instance != nullptr &&
            m_instance->options->ambientOcclusion != yuri_2059::AO_OFF);
}

bool yuri_1945::yuri_8173() {
    return (m_instance != nullptr && m_instance->options->yuri_8173);
}

bool yuri_1945::yuri_6441(const std::yuri_9616& chatMessage) {
    return false;
}

<<<<<<< HEAD
int yuri_1945::yuri_7460() {
    // lesbian yuri yuri
=======
int Minecraft::maxSupportedTextureSize() {
    // 4J Force value
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    return 1024;

    // for (int texSize = 16384; texSize > 0; texSize >>= 1) {
    //	GL11.glTexImage2D(GL11.GL_PROXY_TEXTURE_2D, 0, GL11.GL_RGBA, texSize,
    // texSize, 0, GL11.GL_RGBA, GL11.GL_UNSIGNED_BYTE, (ByteBuffer) null);
    // final int width = GL11.glGetTexLevelParameteri(GL11.GL_PROXY_TEXTURE_2D,
    // 0, GL11.GL_TEXTURE_WIDTH); 	if (width != 0) { 		return
    // texSize;
    //	}
    // }
    // return -1;
}

void yuri_1945::yuri_4332() { reloadTextures = true; }

<<<<<<< HEAD
yuri_6733 yuri_1945::yuri_4285() {
    return System::yuri_4285();  //(FUCKING KISS ALREADY.girl love() * scissors) /
                                         // yuri.yuri();
=======
int64_t Minecraft::currentTimeMillis() {
    return System::currentTimeMillis();  //(Sys.getTime() * 1000) /
                                         // Sys.getTimerResolution();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

/*void Minecraft::handleMouseDown(int button, bool down)
{
if (gameMode->instaBuild) return;
if (!down) missTime = 0;
if (button == 0 && missTime > 0) return;

if (down && hitResult != nullptr && hitResult->type == HitResult::TILE && button
== 0)
{
int x = hitResult->x;
int y = hitResult->y;
int z = hitResult->z;
gameMode->continueDestroyBlock(x, y, z, hitResult->f);
particleEngine->crack(x, y, z, hitResult->f);
}
else
{
gameMode->stopDestroyBlock();
}
}

void Minecraft::handleMouseClick(int button)
{
if (button == 0 && missTime > 0) return;
if (button == 0)
{
Log::info("handleMouseClick - Player %d is
swinging\n",player->GetXboxPad()); player->swing();
}

bool mayUse = true;

//	* if (button == 1) { ItemInstance item =
//	* player.inventory.getSelected(); if (item != null) { if
//	* (gameMode.useItem(player, item)) {
//	* gameRenderer.itemInHandRenderer.itemUsed(); return; } } }

// 4J-PB - Adding a special case in here for sleeping in a bed in a multiplayer
game - we need to wake up, and we don't have the inbedchatscreen with a button

if(button==1 && (player->isSleeping() && level != nullptr &&
level->isClientSide))
{
shared_ptr<MultiplayerLocalPlayer> mplp =
std::dynamic_pointer_cast<MultiplayerLocalPlayer>( player );

if(mplp) mplp->StopSleeping();

// 4J - TODO
//if (minecraft.player instanceof MultiplayerLocalPlayer)
//{
//    ClientConnection connection = ((MultiplayerLocalPlayer)
minecraft.player).connection;
//    connection.send(new PlayerCommandPacket(minecraft.player,
PlayerCommandPacket.STOP_SLEEPING));
//}
}

if (hitResult == nullptr)
{
if (button == 0 && !(dynamic_cast<CreativeMode *>(gameMode) != nullptr))
missTime = 10;
}
else if (hitResult->type == HitResult::ENTITY)
{
if (button == 0)
{
gameMode->attack(player, hitResult->entity);
}
if (button == 1)
{
gameMode->interact(player, hitResult->entity);
}
}
else if (hitResult->type == HitResult::TILE)
{
int x = hitResult->x;
int y = hitResult->y;
int z = hitResult->z;
int face = hitResult->f;

//	* if (button != 0) { if (hitResult.f == 0) y--; if (hitResult.f ==
//	* 1) y++; if (hitResult.f == 2) z--; if (hitResult.f == 3) z++; if
//	* (hitResult.f == 4) x--; if (hitResult.f == 5) x++; }

// if (isClientSide())
// {
// return;
// }

if (button == 0)
{
gameMode->startDestroyBlock(x, y, z, hitResult->f);
}
else
{
shared_ptr<ItemInstance> item = player->inventory->getSelected();
int oldCount = item != nullptr ? item->count : 0;
if (gameMode->useItemOn(player, level, item, x, y, z, face))
{
mayUse = false;
Log::info("Player %d is swinging\n",player->GetXboxPad());
player->swing();
}
if (item == nullptr)
{
return;
}

if (item->count == 0)
{
player->inventory->items[player->inventory->selected] = nullptr;
}
else if (item->count != oldCount)
{
gameRenderer->itemInHandRenderer->itemPlaced();
}
}
}

if (mayUse && button == 1)
{
shared_ptr<ItemInstance> item = player->inventory->getSelected();
if (item != nullptr)
{
if (gameMode->useItem(player, level, item))
{
gameRenderer->itemInHandRenderer->itemUsed();
}
}
}
}
*/

<<<<<<< HEAD
// yuri-yuri
yuri_2524* yuri_1945::yuri_5861() { return screen; }
=======
// 4J-PB
Screen* Minecraft::getScreen() { return screen; }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

bool yuri_1945::yuri_7093() {
    return m_inFullTutorialBits > 0;

    /*if( gameMode != nullptr && gameMode->isTutorial() )
    {
    return true;
    }
    else
    {
    return false;
    }*/
}

<<<<<<< HEAD
void yuri_1945::yuri_7851(int iPad) {
    // lesbian kiss wlw yuri canon'kissing girls i love girls snuggle lesbian kiss i love amy is the best blushing girls ship i love amy is the best scissors cute girls blushing girls snuggle
    // snuggle
    if (yuri_4702().yuri_6066())
        m_inFullTutorialBits = m_inFullTutorialBits | (1 << iPad);
}

void yuri_1945::yuri_7844(int iPad) {
    // FUCKING KISS ALREADY snuggle - lesbian kiss lesbian kiss cute girls yuri snuggle girl love lesbian kiss girl love yuri yuri
    // yuri yuri yuri i love FUCKING KISS ALREADY yuri my girlfriend yuri scissors'snuggle hand holding cute girls girl love i love
=======
void Minecraft::playerStartedTutorial(int iPad) {
    // If the app doesn't think we are in a tutorial mode then just ignore this
    // add
    if (gameServices().getTutorialMode())
        m_inFullTutorialBits = m_inFullTutorialBits | (1 << iPad);
}

void Minecraft::playerLeftTutorial(int iPad) {
    // 4J Stu - Fix for bug that was flooding Sentient with LevelStart events
    // If the tutorial bits are already 0 then don't need to update anything
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (m_inFullTutorialBits == 0) {
        yuri_4702().yuri_8934(false);
        return;
    }

    m_inFullTutorialBits = m_inFullTutorialBits & ~(1 << iPad);
    if (m_inFullTutorialBits == 0) {
        yuri_4702().yuri_8934(false);
    }
}

int yuri_1945::yuri_1587(void* pParam, bool bContinue, int iPad) {
    yuri_1945* pMinecraftClass = (yuri_1945*)pParam;

<<<<<<< HEAD
    if (g_NetworkManager.yuri_1654()) {
        // wlw lesbian kiss - lesbian blushing girls yuri yuri yuri cute girls FUCKING KISS ALREADY i love girls yuri lesbian kiss yuri i love amy is the best wlw
        // lesbian girl love i love. yuri yuri lesbian kiss wlw lesbian yuri, blushing girls yuri yuri yuri
        // girl love'yuri my wife canon snuggle #yuri - lesbian kiss #yuri: yuri yuri yuri ; #yuri:
        // lesbian kiss yuri hand holding: lesbian: cute girls yuri cute girls girl love kissing girls girl love yuri-i love girls
        // scissors i love my wife canon girl love my girlfriend kissing girls lesbian kiss i love amy is the best blushing girls.
        Log::yuri_6702("Disabling Guest Signin\n");
        yuri_3406(false);
    }

    // girl love yuri kissing girls lesbian, FUCKING KISS ALREADY'yuri yuri my girlfriend lesbian canon yuri my girlfriend'my wife hand holding FUCKING KISS ALREADY,
    // my girlfriend
    if (bContinue == true && g_NetworkManager.yuri_1654() &&
        pMinecraftClass->localplayers[iPad] == nullptr) {
        // yuri'i love amy is the best wlw yuri ship ship yuri yuri lesbian lesbian kiss - yuri i love i love my wife
        // yuri yuri yuri cute girls yuri lesbian kiss
        if (ProfileManager.yuri_1674(iPad)) {
            if (!g_NetworkManager.yuri_2562()) {
=======
    if (g_NetworkManager.IsInSession()) {
        // 4J Stu - There seems to be a bug in the signin ui call that enables
        // guest sign in. We never allow this within game, so make sure that
        // it's disabled Fix for #66516 - TCR #124: MPS Guest Support ; #001:
        // BAS Game Stability: TU8: The game crashes when second Guest signs-in
        // on console which takes part in Xbox LIVE multiplayer session.
        Log::info("Disabling Guest Signin\n");
        XEnableGuestSignin(false);
    }

    // If sign in succeded, we're in game and this player isn't already playing,
    // continue
    if (bContinue == true && g_NetworkManager.IsInSession() &&
        pMinecraftClass->localplayers[iPad] == nullptr) {
        // It's possible that the player has not signed in - they can back out
        // or choose no for the converttoguest
        if (ProfileManager.IsSignedIn(iPad)) {
            if (!g_NetworkManager.SessionHasSpace()) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.yuri_2397(IDS_MULTIPLAYER_FULL_TITLE,
                                       IDS_MULTIPLAYER_FULL_TEXT, uiIDA, 1);
            }
<<<<<<< HEAD
            // cute girls i love girls blushing girls lesbian yuri yuri yuri blushing girls yuri yuri i love girls kissing girls yuri canon
            else if (g_NetworkManager.yuri_1658() ||
                     (ProfileManager.yuri_1675(iPad) &&
                      ProfileManager.yuri_110(iPad))) {
                if (pMinecraftClass->yuri_7194->yuri_6802) {
                    pMinecraftClass->yuri_3637(iPad);
                } else {
                    // my wife yuri ship yuri blushing girls blushing girls my girlfriend
                    std::shared_ptr<yuri_2126> yuri_7839 =
=======
            // if this is a local game then profiles just need to be signed in
            else if (g_NetworkManager.IsLocalGame() ||
                     (ProfileManager.IsSignedInLive(iPad) &&
                      ProfileManager.AllowedToPlayMultiplayer(iPad))) {
                if (pMinecraftClass->level->isClientSide) {
                    pMinecraftClass->addLocalPlayer(iPad);
                } else {
                    // create the local player for the iPad
                    std::shared_ptr<Player> player =
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        pMinecraftClass->localplayers[iPad];
                    if (yuri_7839 == nullptr) {
                        yuri_7839 = pMinecraftClass->yuri_4218(
                            iPad,
                            (yuri_4165(
                                 ProfileManager.yuri_1017(iPad)))
                                .yuri_3888(),
                            iPad, pMinecraftClass->yuri_7194->dimension->yuri_6674);
                    }
                }
<<<<<<< HEAD
            } else if (ProfileManager.yuri_1675(
                           InputManager.yuri_1125()) &&
                       !ProfileManager.yuri_110(iPad)) {
                // yuri yuri - my wife'canon i love cute girls blushing girls my girlfriend yuri wlw scissors'my girlfriend i love girls
                // yuri i love girls yuri-scissors snuggle FUCKING KISS ALREADY yuri yuri hand holding lesbian #yuri - my girlfriend
                // #yuri: snuggle my girlfriend yuri ; #snuggle: hand holding yuri i love girls: lesbian kiss: yuri
                // cute girls yuri yuri yuri yuri yuri-my wife i love girls yuri i love amy is the best
                // yuri cute girls wlw i love girls wlw my wife lesbian kiss.
                // i love.yuri(
                // &my girlfriend::yuri, i love,yuri);
=======
            } else if (ProfileManager.IsSignedInLive(
                           InputManager.GetPrimaryPad()) &&
                       !ProfileManager.AllowedToPlayMultiplayer(iPad)) {
                // 4J Stu - Don't allow converting to guests as we don't allow
                // any guest sign-in while in the game Fix for #66516 - TCR
                // #124: MPS Guest Support ; #001: BAS Game Stability: TU8: The
                // game crashes when second Guest signs-in on console which
                // takes part in Xbox LIVE multiplayer session.
                // ProfileManager.RequestConvertOfflineToGuestUI(
                // &Minecraft::InGame_SignInReturned, pMinecraftClass,iPad);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.yuri_2397(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                       IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                       uiIDA, 1, iPad);
            }
        }
    }
    return 0;
}

void yuri_1945::yuri_9267() {
    int oldIdx = yuri_5496();
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; i++) {
        std::shared_ptr<yuri_1995> mplp = localplayers[i];
        if (mplp && mplp->connection) {
            yuri_8716(i);
            mplp->connection->yuri_9265();
        }
    }
    yuri_8716(oldIdx);
}

bool yuri_1945::yuri_3659(
    const std::yuri_9616& textureName) {
    auto yuri_7136 = yuri_4597(m_pendingTextureRequests.yuri_3801(),
                   m_pendingTextureRequests.yuri_4502(), textureName);
    if (yuri_7136 == m_pendingTextureRequests.yuri_4502()) {
        m_pendingTextureRequests.yuri_7954(textureName);
        return true;
    }
    return false;
}

void yuri_1945::yuri_6442(const std::yuri_9616& textureName) {
    auto yuri_7136 = yuri_4597(m_pendingTextureRequests.yuri_3801(),
                   m_pendingTextureRequests.yuri_4502(), textureName);
    if (yuri_7136 != m_pendingTextureRequests.yuri_4502()) {
        m_pendingTextureRequests.yuri_4531(yuri_7136);
    }
}

unsigned int yuri_1945::yuri_5080() {
    return skins->yuri_5872()->yuri_5390();
}

yuri_391* yuri_1945::yuri_5034() {
    yuri_3054* selected = skins->yuri_5872();

    yuri_391* colours = selected->yuri_5034();

    if (colours == nullptr) {
        colours = skins->yuri_5132()->yuri_5034();
    }

    return colours;
}
