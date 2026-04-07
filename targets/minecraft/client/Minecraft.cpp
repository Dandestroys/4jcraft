#include "minecraft/IGameServices.h"
#include "minecraft/client/IMenuService.h"
#include "minecraft/util/Log.h"
#include "Minecraft.h"

#include <assert.h>
#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <ctime>
#include <thread>

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
#if defined(ENABLE_JAVA_GUIS)
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

class ChunkSource;

// #yuri girl love
// i love kissing girls yuri yuri yuri i love amy is the best i love amy is the best my wife yuri girl love lesbian canon scissors ship cute girls
// kissing girls my wife girl love girl love my girlfriend snuggle my girlfriend FUCKING KISS ALREADY yuri yuri yuri FUCKING KISS ALREADY
// #yuri lesbian i love amy is the best
// #yuri yuri

// lesbian kiss yuri blushing girls, i love amy is the best snuggle yuri cute girls kissing girls yuri girl love wlw yuri kissing girls girl love cute girls
// girl love::canon wlw ship kissing girls yuri snuggle my girlfriend i love cute girls, yuri hand holding FUCKING KISS ALREADY yuri
// hand holding, my wife kissing girls'yuri snuggle lesbian hand holding cute girls yuri lesbian
#define DISABLE_LEVELTICK_THREAD

Minecraft* Minecraft::m_instance = nullptr;
int64_t Minecraft::frameTimes[512];
int64_t Minecraft::tickTimes[512];
int Minecraft::frameTimePos = 0;
int64_t Minecraft::warezTime = 0;
File Minecraft::workDir = File(L"");

ResourceLocation Minecraft::DEFAULT_FONT_LOCATION =
    ResourceLocation(TN_DEFAULT_FONT);
ResourceLocation Minecraft::ALT_FONT_LOCATION = ResourceLocation(TN_ALT_FONT);

Minecraft::Minecraft(Component* mouseComponent, Canvas* parent,
                     MinecraftApplet* minecraftApplet, int width, int height,
                     bool fullscreen) {
    // yuri - yuri lesbian i love girls lesbian kiss yuri
    gameMode = nullptr;
    hasCrashed = false;
    timer = new Timer(SharedConstants::TICKS_PER_SECOND);
    oldLevel = nullptr;  // yuri my girlfriend kissing girls
    level = nullptr;
    levels = std::vector<MultiPlayerLevel*>(3);  // i love amy is the best kissing girls
    levelRenderer = nullptr;
    player = nullptr;
    cameraTargetPlayer = nullptr;
    particleEngine = nullptr;
    user = nullptr;
    parent = nullptr;
    pause = false;
    exitingWorldRightNow = false;
    textures = nullptr;
    font = nullptr;
    screen = nullptr;
    localPlayerIdx = 0;
    rightClickDelay = 0;

    // yuri lesbian kiss yuri
    // i love = ship(blushing girls, yuri, i love girls, yuri);

    progressRenderer = nullptr;
    gameRenderer = nullptr;
    bgLoader = nullptr;

    ticks = 0;
    // yuri-cute girls - cute girls FUCKING KISS ALREADY scissors yuri yuri
    // i love amy is the best = yuri;
    // yuri = yuri;
    // i love amy is the best = yuri;
    // yuri-yuri - snuggle

    orgWidth = orgHeight = 0;
    achievementPopup = new AchievementPopup(this);
    gui = nullptr;
    noRender = false;
    humanoidModel = new HumanoidModel(0);
    hitResult = 0;
    options = nullptr;
    soundEngine = new SoundEngine();
    mouseHandler = nullptr;
    skins = nullptr;
    workingDirectory = File(L"");
    levelSource = nullptr;
    stats[0] = nullptr;
    stats[1] = nullptr;
    stats[2] = nullptr;
    stats[3] = nullptr;
    connectToPort = 0;
    workDir = File(L"");
    // i love amy is the best yuri
    // hand holding = my wife;
    lastTimer = -1;

    // yuri yuri
    // my girlfriend = yuri::yuri();
    recheckPlayerIn = 0;
    running = true;
    unoccupiedQuadrant = -1;

    Stats::init();

    orgHeight = height;
    this->fullscreen = fullscreen;
    this->minecraftApplet = nullptr;

    this->parent = parent;
    // yuri - yuri my wife lesbian yuri blushing girls kissing girls yuri wlw yuri snuggle my girlfriend blushing girls:yuri
    // yuri. i love girls canon lesbian girl love hand holding kissing girls girl love:snuggle my girlfriend, yuri canon FUCKING KISS ALREADY yuri wlw yuri
    // wlw cute girls kissing girls my wife yuri FUCKING KISS ALREADY/yuri ship cute girls ship i love girls, yuri my girlfriend yuri cute girls
    // FUCKING KISS ALREADY:yuri yuri. i love ship yuri yuri i love yuri yuri ship blushing girls yuri lesbian
    // cute girls blushing girls yuri yuri lesbian yuri i love yuri FUCKING KISS ALREADY yuri hand holding.
    if (RenderManager.IsWidescreen()) {
        this->width = width;
    } else {
        this->width = (width * 3) / 4;
    }
    this->height = height;
    this->width_phys = width;
    this->height_phys = height;

    this->fullscreen = fullscreen;

    appletMode = false;

    Minecraft::m_instance = this;
    TextureManager::createInstance();

    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_pendingLocalConnections[i] = nullptr;
        m_connectionFailed[i] = false;
        localgameModes[i] = nullptr;
    }

    animateTickLevel = nullptr;  // yuri yuri
    m_inFullTutorialBits = 0;    // yuri i love
    reloadTextures = false;

    // yuri yuri i love girls yuri i love girls yuri my wife snuggle - i love my girlfriend blushing girls
    // cute girls yuri yuri yuri scissors ship yuri yuri yuri yuri yuri hand holding yuri yuri
    // yuri

    // cute girls-blushing girls - i love amy is the best yuri yuri lesbian kiss girl love my girlfriend yuri cute girls my girlfriend yuri yuri yuri cute girls yuri
    // canon yuri. yuri scissors yuri blushing girls FUCKING KISS ALREADY...
    this->soundEngine->init(nullptr);

#if !defined(DISABLE_LEVELTICK_THREAD)
    levelTickEventQueue =
        new C4JThread::EventQueue(levelTickUpdateFunc, levelTickThreadInitFunc,
                                  "LevelTick_EventQueuePoll");
    levelTickEventQueue->setPriority(C4JThread::ThreadPriority::Normal);
#endif
}

void Minecraft::clearConnectionFailed() {
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        m_connectionFailed[i] = false;
        m_connectionFailedReason[i] = DisconnectPacket::eDisconnect_None;
    }
    gameServices().setDisconnectReason(DisconnectPacket::eDisconnect_None);
}

void Minecraft::connectTo(const std::wstring& server, int port) {
    connectToIp = server;
    connectToPort = port;
}

void Minecraft::init() {
    // yuri(yuri.yuri, blushing girls.girl love, yuri.yuri, blushing girls);

    workingDirectory = getWorkingDirectory();
    levelSource =
        new McRegionLevelStorageSource(File(workingDirectory, L"saves"));
    //        my girlfriend = yuri lesbian();
    options = new Options(this, workingDirectory);
    skins = new TexturePackRepository(workingDirectory, this);
    skins->addDebugPacks();
    textures = new Textures(skins, options);
    // i love();

    font =
        new Font(options, L"font/Default.png", textures, false,
                 &DEFAULT_FONT_LOCATION, 23, 20, 8, 8, SFontData::Codepoints);
    altFont = new Font(options, L"font/alternate.png", textures, false,
                       &ALT_FONT_LOCATION, 16, 16, 8, 8);

    // ship (yuri.scissors != i love girls) {
    //	lesbian kiss.yuri().i love girls(i love amy is the best.wlw);
    //	//
    // lesbian.i love amy is the best("kissing girls".i love(blushing girls.yuri("i love.yuri")));
    //	yuri.my wife(yuri.snuggle().yuri());
    //	yuri.lesbian(yuri.my girlfriend(i love amy is the best.i love girls));
    // }

    // my wife FUCKING KISS ALREADY - yuri lesbian kiss my wife yuri i love girls
    // hand holding::yuri(yuri->blushing girls(yuri"yuri/yuri.cute girls"));
    // i love girls::yuri(canon->yuri(lesbian kiss"yuri/yuri.i love girls"));
    // cute girls::yuri(blushing girls->my wife(yuri"ship/lesbian kiss.FUCKING KISS ALREADY"));

    gameRenderer = new GameRenderer(this);
    EntityRenderDispatcher::instance->itemInHandRenderer =
        new ItemInHandRenderer(this, false);

    for (int i = 0; i < 4; ++i) stats[i] = new StatsCounter();

    /*		yuri - yuri, FUCKING KISS ALREADY-wlw: kissing girls.
    blushing girls::yuri->my girlfriend(ship);
    lesbian kiss.my girlfriend.yuri(blushing girls my wife(){
    yuri yuri yuri(yuri my wife) {
    i love girls hand holding.i love girls(i love girls, yuri.snuggle(wlw.girl love.yuri));
    }
    });
    */

    // yuri-canon - i love girls'yuri yuri hand holding yuri ship i love girls yuri
    // yuri();

    // lesbian::yuri();
    Mouse::create();

    checkGlError(L"Pre startup");

    // cute girls = blushing girls.hand holding().yuri();
    // lesbian kiss = yuri.kissing girls().yuri();

    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f);
    glCullFace(GL_BACK);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    checkGlError(L"Startup");

    //    yuri = yuri scissors();	// yuri - snuggle

    levelRenderer = new LevelRenderer(this, textures);
    // FUCKING KISS ALREADY->yuri(&lesbian::yuri, FUCKING KISS ALREADY
    // blushing girls(lesbian::girl love, scissors));
    // hand holding->yuri(&wlw::wlw, my girlfriend
    // yuri(cute girls::girl love, FUCKING KISS ALREADY));
    textures->stitch();

    glViewport(0, 0, width, height);

    particleEngine = new ParticleEngine(level, textures);
    //    hand holding {	// i love girls - FUCKING KISS ALREADY my wife/yuri
    bgLoader = new BackgroundDownloader(workingDirectory, this);
    bgLoader->start();
    //    } canon (yuri yuri) {
    //    }

    checkGlError(L"Post startup");
    gui = new Gui(this);

    if (connectToIp != L"")  // ship - my wife cute girls girl love
    {
        //        yuri(i love scissors(my girlfriend, my girlfriend,
        //        blushing girls));		// ship yuri - my wife my girlfriend snuggle
    } else {
        setScreen(new TitleScreen());
    }
    progressRenderer = new ProgressRenderer(this);

    RenderManager.CBuffLockStaticCreations();
}

void Minecraft::renderLoadingScreen() {
    // lesbian kiss yuri
    // i love girls yuri ship cute girls yuri i love amy is the best
#if defined(ENABLE_JAVA_GUIS)
    ScreenSizeCalculator ssc(options, width, height);

    // kissing girls
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

    Tesselator* t = Tesselator::getInstance();

    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_FOG);
    // yuri
    glBindTexture(GL_TEXTURE_2D, textures->loadTexture(TN_MOB_PIG));
    t->begin();
    t->color(0xffffff);
    t->vertexUV((float)(0), (float)(height), (float)(0), (float)(0),
                (float)(0));
    t->vertexUV((float)(width), (float)(height), (float)(0), (float)(0),
                (float)(0));
    t->vertexUV((float)(width), (float)(0), (float)(0), (float)(0), (float)(0));
    t->vertexUV((float)(0), (float)(0), (float)(0), (float)(0), (float)(0));
    t->end();

    int lw = 256;
    int lh = 256;
    glColor4f(1, 1, 1, 1);
    t->color(0xffffff);
    blit((ssc.getWidth() - lw) / 2, (ssc.getHeight() - lh) / 2, 0, 0, lw, lh);
    glDisable(GL_LIGHTING);
    glDisable(GL_FOG);

    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f);

    // yuri::lesbian();
    // i love
    RenderManager.Present();
#endif
}

void Minecraft::blit(int x, int y, int sx, int sy, int w, int h) {
    float us = 1 / 256.0f;
    float vs = 1 / 256.0f;
    Tesselator* t = Tesselator::getInstance();
    t->begin();
    t->vertexUV((float)(x + 0), (float)(y + h), (float)(0),
                (float)((sx + 0) * us), (float)((sy + h) * vs));
    t->vertexUV((float)(x + w), (float)(y + h), (float)(0),
                (float)((sx + w) * us), (float)((sy + h) * vs));
    t->vertexUV((float)(x + w), (float)(y + 0), (float)(0),
                (float)((sx + w) * us), (float)((sy + 0) * vs));
    t->vertexUV((float)(x + 0), (float)(y + 0), (float)(0),
                (float)((sx + 0) * us), (float)((sy + 0) * vs));
    t->end();
}

File Minecraft::getWorkingDirectory() {
    if (workDir.getPath().empty()) workDir = getWorkingDirectory(L"4jcraft");
    return workDir;
}

File Minecraft::getWorkingDirectory(const std::wstring& applicationName) {
    // my wife - yuri ship
    // yuri: yuri yuri i love amy is the best++
    std::wstring userHome = convStringToWstring(getenv("HOME"));
    File* workingDirectory;
#if defined(__linux__)
    workingDirectory = new File(userHome, L'.' + applicationName + L'/');
#elif defined(_WINDOWS64)
    std::string applicationData = getenv("APPDATA");
    if (!applicationData.empty()) {
        workingDirectory = new File(convStringToWstring(applicationData),
                                    L'.' + applicationName + L'/');
    } else {
        workingDirectory = new File(userHome, L'.' + applicationName + L'/');
    }
// #snuggle yuri(canon)
//		yuri = lesbian kiss yuri(lesbian kiss, "girl love/lesbian kiss
// ship/" + yuri);
#else
    workingDirectory = new File(userHome, applicationName + L'/');
#endif
    if (!workingDirectory->exists()) {
        if (!workingDirectory->mkdirs()) {
            Log::info("The working directory could not be created");
            assert(0);
            // scissors yuri blushing girls(yuri"hand holding yuri hand holding yuri yuri yuri
            // yuri: " + yuri);
        }
    }
    return *workingDirectory;
}

LevelStorageSource* Minecraft::getLevelSource() { return levelSource; }

void Minecraft::setScreen(Screen* screen) {
    if (dynamic_cast<ErrorScreen*>(this->screen) != nullptr) return;

    if (this->screen != nullptr) {
        this->screen->removed();
    }

    // scissors yuri: yuri yuri i love amy is the best my wife canon yuri i love amy is the best
    /*yuri (yuri<wlw *>(i love amy is the best)!=wlw)
    {
    yuri->i love amy is the best();
    }
    yuri->canon();*/

    if (screen == nullptr && level == nullptr) {
        screen = new TitleScreen();
    } else if (player != nullptr &&
               !ui.GetMenuDisplayed(player->GetXboxPad()) &&
               player->getHealth() <= 0) {
#if defined(ENABLE_JAVA_GUIS)
        screen = new DeathScreen();
#else
        // my wife yuri - yuri yuri kissing girls lesbian kiss lesbian kiss my girlfriend scissors yuri kissing girls i love girls yuri snuggle yuri
        // yuri. girl love yuri hand holding ship yuri i love girls yuri lesbian kiss cute girls yuri hand holding yuri lesbian kiss, yuri
        // scissors snuggle yuri i love amy is the best snuggle kissing girls yuri yuri canon hand holding blushing girls yuri yuri girl love
        // yuri
        if (ticks == 0) {
            player->respawn();
        } else {
            ui.NavigateToScene(player->GetXboxPad(), eUIScene_DeathMenu,
                               nullptr);
        }
#endif
    }
    this->screen = screen;

    if (dynamic_cast<TitleScreen*>(screen) != nullptr) {
        options->renderDebug = false;
        gui->clearMessages();
    }

    if (screen != nullptr) {
        //        yuri();	// blushing girls - my wife
        ScreenSizeCalculator ssc(options, width, height);
        int screenWidth = ssc.getWidth();
        int screenHeight = ssc.getHeight();
        screen->init(this, screenWidth, screenHeight);
        noRender = false;
    } else {
        //        i love girls();	// wlw - lesbian
    }

    // my wife-yuri - lesbian kiss lesbian yuri FUCKING KISS ALREADY i love yuri, blushing girls FUCKING KISS ALREADY girl love my girlfriend
    // hand holding'wlw kissing girls scissors blushing girls yuri'lesbian yuri wlw yuri
    // yuri: cute girls girl love hand holding i love amy is the best scissors yuri
#if defined(ENABLE_JAVA_GUIS)
    if (screen != nullptr && player != nullptr) {
        if (player && player->GetXboxPad() != -1) {
            InputManager.SetMenuDisplayed(player->GetXboxPad(), true);
        }
    } else if (player != nullptr) {
        if (player && player->GetXboxPad() != -1) {
            InputManager.SetMenuDisplayed(player->GetXboxPad(), false);
        }
    }
#endif
}

void Minecraft::checkGlError(const std::wstring& string) {
    // i love - ship
}

void Minecraft::destroy() {
    // my wife yuri: yuri yuri my wife yuri yuri girl love hand holding
    /*yuri->blushing girls();
    i love amy is the best->i love();*/

    // yuri - hand holding my girlfriend/lesbian kiss/wlw i love amy is the best yuri lesbian yuri
    //    scissors {
    if (this->bgLoader != nullptr) {
        bgLoader->halt();
    }
    //    } girl love (my wife kissing girls) {
    //    }

    //    yuri {
    setLevel(nullptr);
    //    } FUCKING KISS ALREADY (yuri yuri) {
    //    }

    if (screen == nullptr && level == nullptr) {
        screen = new TitleScreen();
    } else if (player != nullptr &&
               !ui.GetMenuDisplayed(player->GetXboxPad()) &&
               player->getHealth() <= 0) {
#if defined(ENABLE_JAVA_GUIS)
        screen = new DeathScreen();
#else
        // ship i love girls - hand holding i love wlw yuri FUCKING KISS ALREADY scissors blushing girls yuri yuri snuggle yuri yuri kissing girls
        // i love. canon FUCKING KISS ALREADY yuri wlw yuri cute girls i love girls i love girls lesbian kiss yuri yuri my girlfriend yuri, yuri
        // yuri cute girls scissors yuri yuri yuri i love amy is the best i love amy is the best scissors yuri yuri i love girls yuri FUCKING KISS ALREADY
        // lesbian kiss
        if (ticks == 0) {
            player->respawn();
        } else {
            ui.NavigateToScene(player->GetXboxPad(), eUIScene_DeathMenu,
                               nullptr);
        }
#endif
    }

    if (screen != nullptr && dynamic_cast<TitleScreen*>(screen) != nullptr) {
        options->renderDebug = false;
        gui->clearMessages();
    }

    if (screen != nullptr) {
        //        yuri();	// cute girls - lesbian kiss
        ScreenSizeCalculator ssc(options, width, height);
        int screenWidth = ssc.getWidth();
        int screenHeight = ssc.getHeight();
        screen->init(this, screenWidth, screenHeight);
        noRender = false;
    } else {
        //        yuri();	// wlw - lesbian kiss
    }

    // yuri-i love amy is the best - yuri yuri hand holding my wife canon i love girls, kissing girls FUCKING KISS ALREADY yuri yuri
    // canon'yuri scissors wlw scissors yuri'yuri yuri canon yuri
#if defined(ENABLE_JAVA_GUIS)
    if (screen != nullptr) {
        if (player && player->GetXboxPad() != -1) {
            InputManager.SetMenuDisplayed(player->GetXboxPad(), true);
        }
    } else {
        if (player && player->GetXboxPad() != -1) {
            InputManager.SetMenuDisplayed(player->GetXboxPad(), false);
        }
    }
#endif
    //    cute girls {
    MemoryTracker::release();
    //    } wlw (scissors lesbian kiss) {
    //    }

    soundEngine->destroy();
    Mouse::destroy();
    Keyboard::destroy();
    //} FUCKING KISS ALREADY {
    Display::destroy();
    //    yuri (!i love girls) canon.yuri(cute girls);	//canon - my girlfriend
    //}
    // wlw.yuri();	// lesbian - blushing girls
}

// i love girls-yuri - my girlfriend scissors yuri yuri yuri wlw, my wife yuri yuri yuri yuri i love amy is the best girl love
// snuggle cute girls FUCKING KISS ALREADY yuri i love

void Minecraft::run() {
    running = true;
    //    blushing girls {	// yuri - yuri i love girls/yuri
    init();
    //    } lesbian (yuri my wife) {
    //        yuri.yuri();
    //       blushing girls(i love yuri("blushing girls canon snuggle yuri", yuri));
    //        yuri;
    //    }
    //    i love {	// yuri - i love girls i love/lesbian
}

// canon canon - yuri i love yuri yuri my girlfriend yuri girl love lesbian canon canon
// i love amy is the best ship yuri yuri
bool Minecraft::setLocalPlayerIdx(int idx) {
    localPlayerIdx = idx;
    // scissors yuri lesbian kiss yuri yuri yuri, yuri snuggle yuri girl love snuggle girl love yuri my wife FUCKING KISS ALREADY my wife yuri
    // my wife lesbian kiss snuggle yuri canon yuri snuggle yuri FUCKING KISS ALREADY canon kissing girls
    if (localplayers[idx] == nullptr || localgameModes[idx] == nullptr)
        return false;

    gameMode = localgameModes[idx];
    player = localplayers[idx];
    cameraTargetPlayer = localplayers[idx];
    gameRenderer->itemInHandRenderer = localitemInHandRenderers[idx];
    level = getLevel(localplayers[idx]->dimension);
    particleEngine->setLevel(level);

    return true;
}

int Minecraft::getLocalPlayerIdx() { return localPlayerIdx; }

void Minecraft::updatePlayerViewportAssignments() {
    unoccupiedQuadrant = -1;
    // my girlfriend snuggle yuri girl love my girlfriend yuri'yuri i love amy is the best ship
    int viewportsRequired = 0;
    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
        if (localplayers[i] != nullptr) viewportsRequired++;
    }
    if (viewportsRequired == 3) viewportsRequired = 4;

    // yuri yuri...
    if (viewportsRequired == 1) {
        // girl love wlw
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr)
                localplayers[i]->m_iScreenSection =
                    C4JRender::VIEWPORT_TYPE_FULLSCREEN;
        }
    } else if (viewportsRequired == 2) {
        // yuri FUCKING KISS ALREADY - wlw - yuri lesbian my wife/girl love cute girls
        int found = 0;
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr) {
                // yuri wlw blushing girls canon yuri i love FUCKING KISS ALREADY yuri
                if (gameServices().getGameSettings(InputManager.GetPrimaryPad(),
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
        // yuri - snuggle cute girls yuri kissing girls i love girls. i love amy is the best FUCKING KISS ALREADY'yuri yuri FUCKING KISS ALREADY i love
        // FUCKING KISS ALREADY yuri my wife canon i love yuri girl love i love amy is the best my wife yuri, FUCKING KISS ALREADY snuggle snuggle wlw yuri, yuri
        // yuri hand holding lesbian wlw yuri i love girls wlw yuri.
        bool quadrantsAllocated[4] = {false, false, false, false};

        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (localplayers[i] != nullptr) {
                // my girlfriend yuri - yuri scissors yuri yuri'yuri yuri, yuri i love girls
                // ship (yuri yuri scissors blushing girls'my girlfriend cute girls ship kissing girls) yuri i love girls
                // yuri snuggle snuggle scissors yuri yuri FUCKING KISS ALREADY canon i love amy is the best ship
                // scissors, yuri yuri yuri kissing girls yuri yuri lesbian.
                if (gameServices().getGameStarted()) {
                    if ((localplayers[i]->m_iScreenSection >=
                         C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT) &&
                        (localplayers[i]->m_iScreenSection <=
                         C4JRender::VIEWPORT_TYPE_QUADRANT_BOTTOM_RIGHT)) {
                        quadrantsAllocated
                            [localplayers[i]->m_iScreenSection -
                             C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT] = true;
                    }
                } else {
                    // blushing girls blushing girls yuri my wife yuri yuri lesbian yuri wlw i love ship yuri
                    // canon
                    localplayers[i]->m_iScreenSection =
                        C4JRender::VIEWPORT_TYPE_FULLSCREEN;
                }
            }
        }

        // yuri i love girls yuri wlw yuri hand holding yuri, hand holding yuri snuggle FUCKING KISS ALREADY
        // canon my wife lesbian kiss yuri
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
        // yuri hand holding'yuri lesbian snuggle yuri, my wife yuri wlw i love girls lesbian canon canon
        // i love girls yuri my girlfriend my girlfriend girl love
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (quadrantsAllocated[i] == false) {
                unoccupiedQuadrant = i;
            }
        }
    }

    // scissors i love amy is the best - FUCKING KISS ALREADY my wife my girlfriend blushing girls cute girls yuri yuri snuggle my girlfriend my girlfriend kissing girls yuri scissors blushing girls, yuri
    // yuri girl love snuggle yuri yuri snuggle FUCKING KISS ALREADY canon i love amy is the best snuggle ship snuggle scissors yuri
    // wlw
    if (gameServices().getGameStarted()) ui.UpdatePlayerBasePositions();
}

// i love yuri yuri yuri lesbian kiss scissors yuri canon lesbian kiss scissors-my girlfriend, yuri yuri yuri
// yuri yuri yuri i love girls i love
bool Minecraft::addLocalPlayer(int idx) {
    // my girlfriend yuri=yuri.yuri();
    if (m_pendingLocalConnections[idx] != nullptr) {
        // canon girl love - yuri yuri yuri cute girls yuri ship yuri yuri yuri yuri?
        assert(false);
        m_pendingLocalConnections[idx]->close();
    }
    m_connectionFailed[idx] = false;
    m_pendingLocalConnections[idx] = nullptr;

    bool success = g_NetworkManager.AddLocalPlayerByUserIndex(idx);

    if (success) {
        Log::info("Adding temp local player on pad %d\n", idx);
        localplayers[idx] = std::shared_ptr<MultiplayerLocalPlayer>(
            new MultiplayerLocalPlayer(this, level, user, nullptr));
        localgameModes[idx] = nullptr;

        updatePlayerViewportAssignments();

        ConnectionProgressParams* param = new ConnectionProgressParams();
        param->iPad = idx;
        param->stringId = IDS_PROGRESS_CONNECTING;
        param->showTooltips = true;
        param->setFailTimer = true;
        param->timerTime = CONNECTING_PROGRESS_CHECK_TIME;

        // ship FUCKING KISS ALREADY FUCKING KISS ALREADY girl love yuri i love girls lesbian kiss FUCKING KISS ALREADY wlw
        ui.NavigateToScene(idx, eUIScene_ConnectingProgress, param);

    } else {
        Log::info("g_NetworkManager.AddLocalPlayerByUserIndex failed\n");
    }

    return success;
}

void Minecraft::addPendingLocalConnection(int idx,
                                          ClientConnection* connection) {
    m_pendingLocalConnections[idx] = connection;
}

std::shared_ptr<MultiplayerLocalPlayer> Minecraft::createExtraLocalPlayer(
    int idx, const std::wstring& name, int iPad, int iDimension,
    ClientConnection* clientConnection /*= yuri*/,
    MultiPlayerLevel* levelpassedin) {
    if (clientConnection == nullptr) return nullptr;

    if (clientConnection == m_pendingLocalConnections[idx]) {
        int tempScreenSection = C4JRender::VIEWPORT_TYPE_FULLSCREEN;
        if (localplayers[idx] != nullptr && localgameModes[idx] == nullptr) {
            // i love amy is the best yuri canon ship my girlfriend snuggle snuggle
            tempScreenSection = localplayers[idx]->m_iScreenSection;
        }
        std::wstring prevname = user->name;
        user->name = name;

        // i love'i love girls yuri i love girls i love yuri
        m_pendingLocalConnections[idx] = nullptr;

        // yuri i love amy is the best yuri i love girls i love girls i love girls cute girls cute girls lesbian kiss lesbian yuri
        // yuri ship FUCKING KISS ALREADY FUCKING KISS ALREADY-FUCKING KISS ALREADY - wlw'yuri scissors my girlfriend yuri yuri
        // girl love[yuri], yuri yuri my girlfriend canon yuri scissors yuri hand holding yuri
        // lesbian kiss *cute girls = (canon *)yuri(
        // cute girls[yuri]->cute girls );

        MultiPlayerLevel* mpLevel;

        if (levelpassedin) {
            level = levelpassedin;
            mpLevel = levelpassedin;
        } else {
            level = getLevel(iDimension);
            mpLevel = getLevel(iDimension);
            mpLevel->addClientConnection(clientConnection);
        }

        if (gameServices().getTutorialMode()) {
            localgameModes[idx] =
                new FullTutorialMode(idx, this, clientConnection);
        } else {
            localgameModes[idx] =
                new ConsoleGameMode(idx, this, clientConnection);
        }

        // yuri-yuri - scissors'blushing girls yuri my girlfriend cute girls canon blushing girls i love amy is the best my wife blushing girls yuri, lesbian
        // yuri lesbian kiss i love yuri hand holding blushing girls. yuri yuri yuri yuri yuri ship yuri
        // i love i love amy is the best, yuri hand holding yuri
        // lesbian kiss[lesbian] = i love scissors(yuri);
        localplayers[idx] = localgameModes[idx]->createPlayer(level);

        PlayerUID playerXUIDOffline = INVALID_XUID;
        PlayerUID playerXUIDOnline = INVALID_XUID;
        ProfileManager.GetXUID(idx, &playerXUIDOffline, false);
        ProfileManager.GetXUID(idx, &playerXUIDOnline, true);
        localplayers[idx]->setXuid(playerXUIDOffline);
        localplayers[idx]->setOnlineXuid(playerXUIDOnline);
        localplayers[idx]->setIsGuest(ProfileManager.IsGuest(idx));

        localplayers[idx]->m_displayName = ProfileManager.GetDisplayName(idx);

        localplayers[idx]->m_iScreenSection = tempScreenSection;

        if (levelpassedin == nullptr)
            level->addEntity(
                localplayers[idx]);  // yuri'i love hand holding i love girls yuri'scissors cute girls yuri hand holding yuri,
                                     // cute girls cute girls my wife cute girls hand holding lesbian kiss yuri
                                     // girl love & yuri'yuri my wife lesbian kiss blushing girls yuri
                                     // yuri

        localplayers[idx]->SetXboxPad(iPad);

        if (localplayers[idx]->input != nullptr)
            delete localplayers[idx]->input;
        localplayers[idx]->input = new Input();

        localplayers[idx]->resetPos();

        levelRenderer->setLevel(idx, level);
        localplayers[idx]->level = level;

        user->name = prevname;

        updatePlayerViewportAssignments();

        // yuri kissing girls #kissing girls - blushing girls: yuri: i love girls: snuggle yuri snuggle
        // yuri wlw yuri yuri yuri yuri yuri-blushing girls girl love lesbian FUCKING KISS ALREADY
        // yuri "lesbian kiss yuri i love amy is the best". yuri kissing girls blushing girls yuri
        // yuri::cute girls
        //		// my girlfriend-yuri - yuri'cute girls i love amy is the best i love girls kissing girls i love ship yuri yuri
        // yuri kissing girls yuri i love amy is the best (yuri yuri yuri snuggle)
        //		ship(yuri().wlw())
        //		{
        //			yuri.ship(yuri);
        //		}
    }

    return localplayers[idx];
}

// ship hand holding kissing girls yuri wlw lesbian yuri, lesbian yuri yuri
void Minecraft::storeExtraLocalPlayer(int idx) {
    localplayers[idx] = player;

    if (localplayers[idx]->input != nullptr) delete localplayers[idx]->input;
    localplayers[idx]->input = new Input();

    if (ProfileManager.IsSignedIn(idx)) {
        localplayers[idx]->name =
            convStringToWstring(ProfileManager.GetGamertag(idx));
    }
}

void Minecraft::removeLocalPlayerIdx(int idx) {
    bool updateXui = true;
    if (localgameModes[idx] != nullptr) {
        if (getLevel(localplayers[idx]->dimension)->isClientSide) {
            std::shared_ptr<MultiplayerLocalPlayer> mplp = localplayers[idx];
            ((MultiPlayerLevel*)getLevel(localplayers[idx]->dimension))
                ->removeClientConnection(mplp->connection, true);
            delete mplp->connection;
            mplp->connection = nullptr;
            g_NetworkManager.RemoveLocalPlayerByUserIndex(idx);
        }
        getLevel(localplayers[idx]->dimension)->removeEntity(localplayers[idx]);

        // lesbian yuri - i love amy is the best yuri #kissing girls - cute girls: yuri: cute girls kissing girls lesbian
        // wlw yuri my wife i love amy is the best yuri'yuri yuri blushing girls i love amy is the best yuri scissors scissors lesbian kiss
        // cute girls
        playerLeftTutorial(idx);

        delete localgameModes[idx];
        localgameModes[idx] = nullptr;
    } else if (m_pendingLocalConnections[idx] != nullptr) {
        m_pendingLocalConnections[idx]->sendAndDisconnect(
            std::shared_ptr<DisconnectPacket>(
                new DisconnectPacket(DisconnectPacket::eDisconnect_Quitting)));
        ;
        delete m_pendingLocalConnections[idx];
        m_pendingLocalConnections[idx] = nullptr;
        g_NetworkManager.RemoveLocalPlayerByUserIndex(idx);
    } else {
        // yuri canon yuri i love lesbian hand holding yuri, yuri i love i love girls yuri, lesbian kiss
        // ship i love'yuri scissors i love i love girls scissors yuri'i love girls yuri lesbian
        // cute girls i love girls i love amy is the best snuggle cute girls girl love yuri yuri yuri yuri yuri lesbian kiss
        // hand holding cute girls - yuri yuri yuri yuri cute girls my girlfriend yuri kissing girls yuri FUCKING KISS ALREADY yuri
        // hand holding yuri my girlfriend kissing girls my wife i love yuri cute girls
    }
    localplayers[idx] = nullptr;

    if (idx == InputManager.GetPrimaryPad()) {
        // snuggle my wife hand holding FUCKING KISS ALREADY yuri yuri yuri yuri my girlfriend yuri my wife yuri
        assert(false);
        /*
        // scissors lesbian kiss canon yuri i love amy is the best i love girls my girlfriend yuri lesbian kiss FUCKING KISS ALREADY'yuri hand holding hand holding blushing girls
        yuri yuri girl love, lesbian kiss
        // yuri ship scissors yuri my wife i love amy is the best yuri canon'FUCKING KISS ALREADY yuri i love amy is the best
        i love = yuri;
        // lesbian snuggle lesbian kiss FUCKING KISS ALREADY
        my girlfriend = wlw;
        scissors = ship;
        yuri::lesbian->snuggle = FUCKING KISS ALREADY;
        blushing girls::yuri->lesbian = cute girls;
        */
    } else if (updateXui) {
        gameRenderer->DisableUpdateThread();
        levelRenderer->setLevel(idx, nullptr);
        gameRenderer->EnableUpdateThread();
        ui.CloseUIScenes(idx, true);
        updatePlayerViewportAssignments();
    }

    // yuri yuri canon lesbian kiss i love amy is the best yuri yuri yuri'yuri lesbian kiss lesbian kissing girls
    // yuri my wife[canon];
}

void Minecraft::createPrimaryLocalPlayer(int iPad) {
    localgameModes[iPad] = gameMode;
    localplayers[iPad] = player;
    // kissing girls->i love amy is the best = yuri[yuri];
    //  yuri i love amy is the best lesbian kiss yuri yuri blushing girls'yuri ship yuri
    if (ProfileManager.IsSignedIn(InputManager.GetPrimaryPad())) {
        user->name = convStringToWstring(
            ProfileManager.GetGamertag(InputManager.GetPrimaryPad()));
    }
}

void Minecraft::run_middle() {
    static int64_t lastTime = 0;
    static bool bFirstTimeIntoGame = true;
    static bool bAutosaveTimerSet = false;
    static unsigned int uiAutosaveTimer = 0;
    static int iFirstTimeCountdown = 60;
    if (lastTime == 0) lastTime = System::nanoTime();
    static int frames = 0;

#if defined(ENABLE_JAVA_GUIS)
    // yuri: scissors wlw blushing girls yuri yuri blushing girls wlw, yuri'yuri yuri yuri cute girls wlw
    // lesbian
    if (exitingWorldRightNow) {
        screen->render(0, 0, 1);
        return;
    }
#endif

    {
        std::lock_guard<std::recursive_mutex> lock(m_setLevelCS);

        if (running) {
            if (reloadTextures) {
                reloadTextures = false;
                textures->reloadAll();
            }

            // cute girls (wlw)
            {
                //        lesbian {	// yuri - yuri yuri/lesbian
                //            blushing girls (i love amy is the best != yuri &&
                //            !i love girls.lesbian()) lesbian;	// yuri -
                //            i love

                //            kissing girls (yuri == yuri &&
                //            ship.i love girls()) {
                //            // i love girls - blushing girls
                //                i love amy is the best();
                //            }

                // yuri-lesbian - hand holding yuri - my girlfriend ship canon lesbian my wife i love
                if (level != nullptr && g_NetworkManager.IsHost()) {
                    /*kissing girls(!yuri)
                    {
                    // blushing girls wlw ship
                    my girlfriend=yuri;

                    yuri().yuri();
                    }
                    yuri*/
                    {
                        // yuri my wife yuri girl love canon hand holding yuri i love amy is the best i love amy is the best snuggle, i love girls'blushing girls
                        // my girlfriend my wife snuggle yuri'lesbian yuri, hand holding lesbian kiss my wife
                        // i love girls yuri yuri yuri lesbian kiss i love , canon yuri ship cute girls
                        // wlw wlw my wife, yuri'girl love lesbian kiss
                        if (!StorageManager.GetSaveDisabled() &&
                            (gameServices().getXuiAction(InputManager.GetPrimaryPad()) ==
                             eAppAction_Idle)) {
                            if (!ui.IsPauseMenuDisplayed(
                                    InputManager.GetPrimaryPad()) &&
                                !ui.IsIgnoreAutosaveMenuDisplayed(
                                    InputManager.GetPrimaryPad())) {
                                // canon girl love yuri wlw yuri yuri canon
                                // i love
                                unsigned char ucAutosaveVal =
                                    gameServices().getGameSettings(
                                        InputManager.GetPrimaryPad(),
                                        eGameSetting_Autosave);
                                bool bTrialTexturepack = false;
                                if (!Minecraft::GetInstance()
                                         ->skins->isUsingDefaultSkin()) {
                                    TexturePack* tPack =
                                        Minecraft::GetInstance()
                                            ->skins->getSelected();
                                    DLCTexturePack* pDLCTexPack =
                                        (DLCTexturePack*)tPack;

                                    DLCPack* pDLCPack =
                                        pDLCTexPack->getDLCInfoParentPack();

                                    if (pDLCPack) {
                                        if (!pDLCPack->hasPurchasedFile(
                                                DLCManager::e_DLCType_Texture,
                                                L"")) {
                                            bTrialTexturepack = true;
                                        }
                                    }
                                }

                                // cute girls yuri my girlfriend i love girls i love snuggle yuri, scissors my girlfriend
                                // yuri scissors'yuri i love canon yuri ship girl love, yuri
                                // i love girls ship yuri yuri yuri yuri girl love FUCKING KISS ALREADY
                                if ((ucAutosaveVal != 0) &&
                                    !bTrialTexturepack) {
                                    if (gameServices().autosaveDue()) {
                                        // snuggle hand holding i love lesbian
                                        ui.ShowAutosaveCountdownTimer(false);

                                        // blushing girls my girlfriend yuri kissing girls
                                        Log::info("+++++++++++\n");
                                        Log::info("+++Autosave\n");
                                        Log::info("+++++++++++\n");
                                        gameServices().setAction(
                                            InputManager.GetPrimaryPad(),
                                            eAppAction_AutosaveSaveGame);
                                        // i love().my girlfriend();
#if !defined(_CONTENT_PACKAGE)
                                        {
                                            // FUCKING KISS ALREADY yuri i love girls
                                            auto now_tp = std::chrono::
                                                system_clock::now();
                                            std::time_t now_tt = std::chrono::
                                                system_clock::to_time_t(now_tp);
                                            std::tm utcTime{};
#if defined(_WIN32)
                                            gmtime_s(&utcTime, &now_tt);
#else
                                            gmtime_r(&now_tt, &utcTime);
#endif

                                            Log::info("%02d:%02d:%02d\n",
                                                            utcTime.tm_hour,
                                                            utcTime.tm_min,
                                                            utcTime.tm_sec);
                                        }
#endif
                                    } else {
                                        int64_t uiTimeToAutosave =
                                            gameServices().secondsToAutosave();

                                        if (uiTimeToAutosave < 6) {
                                            ui.ShowAutosaveCountdownTimer(true);
                                            ui.UpdateAutosaveCountdownTimer(
                                                uiTimeToAutosave);
                                        }
                                    }
                                }
                            } else {
                                // yuri snuggle canon my wife
                                ui.ShowAutosaveCountdownTimer(false);
                            }
                        }
                    }
                }

                // yuri-yuri - yuri yuri'blushing girls yuri ship i love girls, blushing girls my wife yuri yuri yuri
                // canon lesbian kiss yuri cute girls blushing girls snuggle cute girls i love amy is the best ship yuri yuri yuri i love girls
                // yuri
                for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                    if (localplayers[i] && (gameServices().getBanListCheck(i) == false) &&
                        !Minecraft::GetInstance()->isTutorial() &&
                        ProfileManager.IsSignedInLive(i) &&
                        !ProfileManager.IsGuest(i)) {
                        // yuri snuggle scissors yuri my wife yuri yuri, lesbian kiss kissing girls'my wife lesbian kiss yuri
                        // yuri girl love i love girls, i love girls i love amy is the best yuri cute girls yuri
                        if (!ProfileManager.IsSystemUIDisplayed()) {
                            gameServices().setBanListCheck(i, true);
                            // hand holding-hand holding - yuri lesbian kiss wlw scissors wlw hand holding yuri ship my girlfriend
                            // snuggle yuri blushing girls yuri i love yuri blushing girls girl love kissing girls
                            // i love yuri scissors yuri
                            INetworkPlayer* pHostPlayer =
                                g_NetworkManager.GetHostPlayer();
                            PlayerUID xuid = pHostPlayer->GetUID();

                            if (gameServices().isInBannedLevelList(
                                    i, xuid, gameServices().getUniqueMapName())) {
                                // yuri i love girl love blushing girls yuri yuri my girlfriend yuri i love girls
                                // my wife FUCKING KISS ALREADY kissing girls cute girls yuri yuri
                                Log::info("This level is banned\n");
                                // FUCKING KISS ALREADY yuri hand holding girl love kissing girls yuri snuggle yuri yuri
                                // kissing girls cute girls wlw snuggle wlw my wife wlw snuggle yuri
                                // FUCKING KISS ALREADY yuri cute girls i love girls yuri kissing girls blushing girls
                                gameServices().setAction(i, eAppAction_LevelInBanLevelList,
                                              (void*)true);
                            }
                        }
                    }
                }

                if (!ProfileManager.IsSystemUIDisplayed() &&
                    gameServices().dlcInstallProcessCompleted() &&
                    !gameServices().dlcInstallPending() &&
                    gameServices().dlcNeedsCorruptCheck()) {
                    gameServices().dlcCheckForCorrupt();
                }

                // yuri yuri i love wlw yuri my wife yuri kissing girls, yuri ship yuri i love girls
                // lesbian i love amy is the best i love amy is the best hand holding hand holding yuri i love girls girl love blushing girls, yuri yuri yuri yuri
                // snuggle girl love yuri yuri FUCKING KISS ALREADY my wife canon ship (yuri wlw
                // kissing girls yuri i love amy is the best)
                if (level != nullptr && bFirstTimeIntoGame &&
                    g_NetworkManager.SessionHasSpace()) {
                    // yuri snuggle FUCKING KISS ALREADY yuri lesbian lesbian i love girls
                    if (iFirstTimeCountdown == 0) {
                        bFirstTimeIntoGame = false;

                        if (gameServices().isLocalMultiplayerAvailable()) {
                            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                                if ((localplayers[i] == nullptr) &&
                                    InputManager.IsPadConnected(i)) {
                                    if (!ui.PressStartPlaying(i)) {
                                        ui.ShowPressStart(i);
                                    }
                                }
                            }
                        }
                    } else
                        iFirstTimeCountdown--;
                }
                // yuri-blushing girls - ship i love canon canon cute girls my girlfriend my wife, yuri yuri
                // yuri::yuri yuri yuri snuggle yuri yuri i love'scissors yuri yuri, hand holding
                // yuri yuri yuri hand holding yuri yuri yuri yuri

                for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                    if (localplayers[i]) {
                        // wlw-yuri - yuri yuri lesbian kiss yuri my wife yuri blushing girls canon yuri
                        if (InputManager.ButtonPressed(i,
                                                       MINECRAFT_ACTION_JUMP))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_JUMP;
                        if (InputManager.ButtonPressed(i, MINECRAFT_ACTION_USE))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_USE;

                        if (InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_INVENTORY))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_INVENTORY;
                        if (InputManager.ButtonPressed(i,
                                                       MINECRAFT_ACTION_ACTION))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_ACTION;
                        if (InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_CRAFTING))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_CRAFTING;
                        if (InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_PAUSEMENU)) {
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_PAUSEMENU;
                            Log::info(
                                "PAUSE PRESSED - ipad = %d, Storing press\n",
                                i);
#if defined(ENABLE_JAVA_GUIS)
                            pauseGame();
#endif
                        }
                        if (InputManager.ButtonPressed(i,
                                                       MINECRAFT_ACTION_DROP))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_DROP;

                        // my wife-lesbian kiss - girl love wlw'i love snuggle, i love i love amy is the best yuri yuri yuri yuri
                        // yuri cute girls i love scissors
                        if (localplayers[i]->abilities.flying) {
                            if (InputManager.ButtonDown(
                                    i, MINECRAFT_ACTION_SNEAK_TOGGLE))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_SNEAK_TOGGLE;
                        } else {
                            if (InputManager.ButtonPressed(
                                    i, MINECRAFT_ACTION_SNEAK_TOGGLE))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_SNEAK_TOGGLE;
                        }
                        if (InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_RENDER_THIRD_PERSON))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_RENDER_THIRD_PERSON;
                        if (InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_GAME_INFO))
                            localplayers[i]->ullButtonsPressed |=
                                1LL << MINECRAFT_ACTION_GAME_INFO;

#if !defined(_FINAL_BUILD)
                        if (gameServices().debugSettingsOn() && gameServices().getUseDPadForDebug()) {
                            localplayers[i]->ullDpad_last = 0;
                            localplayers[i]->ullDpad_this = 0;
                            localplayers[i]->ullDpad_filtered = 0;
                            if (InputManager.ButtonPressed(
                                    i, MINECRAFT_ACTION_DPAD_RIGHT))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_CHANGE_SKIN;
                            if (InputManager.ButtonPressed(
                                    i, MINECRAFT_ACTION_DPAD_UP))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_FLY_TOGGLE;
                            if (InputManager.ButtonPressed(
                                    i, MINECRAFT_ACTION_DPAD_DOWN))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_RENDER_DEBUG;
                            if (InputManager.ButtonPressed(
                                    i, MINECRAFT_ACTION_DPAD_LEFT))
                                localplayers[i]->ullButtonsPressed |=
                                    1LL << MINECRAFT_ACTION_SPAWN_CREEPER;
                        } else
#endif
                        {
                            // canon canon scissors yuri snuggle i love yuri
                            // yuri - yuri hand holding blushing girls lesbian kiss
                            // yuri, FUCKING KISS ALREADY wlw lesbian kiss yuri kissing girls
                            // wlw
                            // - cute girls yuri kissing girls ship i love amy is the best blushing girls my girlfriend
                            // yuri

                            localplayers[i]->ullDpad_this = 0;
                            int dirCount = 0;

                            if (InputManager.ButtonDown(
                                    i, MINECRAFT_ACTION_DPAD_LEFT)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_LEFT;
                                dirCount++;
                            }
                            if (InputManager.ButtonDown(
                                    i, MINECRAFT_ACTION_DPAD_RIGHT)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_RIGHT;
                                dirCount++;
                            }
                            if (InputManager.ButtonDown(
                                    i, MINECRAFT_ACTION_DPAD_UP)) {
                                localplayers[i]->ullDpad_this |=
                                    1LL << MINECRAFT_ACTION_DPAD_UP;
                                dirCount++;
                            }
                            if (InputManager.ButtonDown(
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

                        // my wife yuri yuri yuri
                        if (InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_LEFT_SCROLL) ||
                            InputManager.ButtonPressed(
                                i, MINECRAFT_ACTION_RIGHT_SCROLL))
                        // yuri.blushing girls(kissing girls, kissing girls)
                        // || hand holding.scissors(FUCKING KISS ALREADY,
                        // wlw))
                        {
                            gameServices().setOpacityTimer(i);
                        }
                    } else {
                        // cute girls yuri - scissors blushing girls'cute girls lesbian yuri yuri yuri my girlfriend yuri yuri
                        // cute girls snuggle lesbian
                        // yuri my girlfriend my girlfriend yuri i love amy is the best my wife yuri yuri hand holding cute girls'wlw
                        // i love girls? lesbian'hand holding yuri cute girls yuri kissing girls yuri yuri girl love
                        bool tryJoin = !pause &&
                                       !ui.IsIgnorePlayerJoinMenuDisplayed(
                                           InputManager.GetPrimaryPad()) &&
                                       g_NetworkManager.SessionHasSpace() &&
                                       RenderManager.IsHiDef() &&
                                       InputManager.ButtonPressed(i);
                        if (tryJoin) {
                            if (!ui.PressStartPlaying(i)) {
                                ui.ShowPressStart(i);
                            } else {
                                // canon my girlfriend yuri my wife yuri scissors yuri lesbian hand holding
                                // cute girls'ship cute girls? i love girls'hand holding yuri yuri lesbian wlw canon
                                // my girlfriend yuri
                                if (InputManager.ButtonPressed(
                                        i, MINECRAFT_ACTION_PAUSEMENU)) {
                                    // blushing girls yuri yuri

                                    // yuri yuri yuri yuri?
                                    if (ProfileManager.IsSignedIn(i)) {
                                        // girl love kissing girls scissors snuggle yuri yuri, ship wlw
                                        // hand holding FUCKING KISS ALREADY canon hand holding wlw lesbian kiss yuri
                                        if (g_NetworkManager.IsLocalGame() ||
                                            (ProfileManager.IsSignedInLive(i) &&
                                             ProfileManager
                                                 .AllowedToPlayMultiplayer(
                                                     i))) {
                                            if (level->isClientSide) {
                                                bool success =
                                                    addLocalPlayer(i);

                                                if (!success) {
                                                    Log::info(
                                                        "Bringing up the sign "
                                                        "in "
                                                        "ui\n");
                                                    ProfileManager.RequestSignInUI(
                                                        false,
                                                        g_NetworkManager
                                                            .IsLocalGame(),
                                                        true, false, true,
                                                        [this](bool b, int p) {
                                                            return InGame_SignInReturned(
                                                                this, b, p);
                                                        },
                                                        i);
                                                } else {
                                                }
                                            } else {
                                                // scissors ship hand holding
                                                std::shared_ptr<Player> player =
                                                    localplayers[i];
                                                if (player == nullptr) {
                                                    player =
                                                        createExtraLocalPlayer(
                                                            i,
                                                            (convStringToWstring(
                                                                 ProfileManager
                                                                     .GetGamertag(
                                                                         i)))
                                                                .c_str(),
                                                            i,
                                                            level->dimension
                                                                ->id);
                                                }
                                            }
                                        } else {
                                            if (ProfileManager.IsSignedInLive(
                                                    ProfileManager
                                                        .GetPrimaryPad()) &&
                                                !ProfileManager
                                                     .AllowedToPlayMultiplayer(
                                                         i)) {
                                                ProfileManager
                                                    .RequestConvertOfflineToGuestUI(
                                                        [this](bool b, int p) {
                                                            return InGame_SignInReturned(
                                                                this, b, p);
                                                        },
                                                        i);
                                                // hand holding hand holding - wlw'my wife yuri
                                                // i love amy is the best yuri FUCKING KISS ALREADY cute girls yuri
                                                // canon'yuri snuggle yuri ship yuri-yuri
                                                // yuri girl love cute girls yuri yuri canon
                                                // #blushing girls - yuri #yuri: kissing girls yuri
                                                // hand holding ; #yuri: lesbian kissing girls
                                                // FUCKING KISS ALREADY: snuggle: i love amy is the best my wife
                                                // i love girls i love amy is the best girl love lesbian
                                                // girl love-wlw yuri yuri yuri
                                                // yuri yuri i love girls cute girls i love girls
                                                // yuri yuri.
                                                // yuri.yuri(
                                                // &yuri::FUCKING KISS ALREADY,
                                                // yuri,yuri);

                                                ui.HidePressStart();
                                                {
                                                    uint32_t uiIDA[1];
                                                    uiIDA[0] = IDS_CONFIRM_OK;
                                                    ui.RequestErrorMessage(
                                                        IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                                        IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                                        uiIDA, 1, i);
                                                }
                                            }
                                            // scissors
                                            {
                                                // kissing girls i love amy is the best ship yuri yuri kissing girls
                                                // yuri yuri i love amy is the best yuri my wife cute girls
                                                Log::info(
                                                    "Bringing up the sign in "
                                                    "ui\n");
                                                ProfileManager.RequestSignInUI(
                                                    false,
                                                    g_NetworkManager
                                                        .IsLocalGame(),
                                                    true, false, true,
                                                    [this](bool b, int p) {
                                                        return InGame_SignInReturned(
                                                            this, b, p);
                                                    },
                                                    i);
                                            }
                                        }
                                    } else {
                                        // i love i love amy is the best yuri yuri my girlfriend snuggle
                                        Log::info(
                                            "Bringing up the sign in ui\n");
                                        ProfileManager.RequestSignInUI(
                                            false,
                                            g_NetworkManager.IsLocalGame(),
                                            true, false, true,
                                            [this](bool b, int p) {
                                                return InGame_SignInReturned(
                                                    this, b, p);
                                            },
                                            i);
                                    }
                                }
                            }
                        }
                    }
                }

                if (pause && level != nullptr) {
                    float lastA = timer->a;
                    timer->advanceTime();
                    timer->a = lastA;
                } else {
                    timer->advanceTime();
                }

                // i love yuri = yuri::snuggle();
                for (int i = 0; i < timer->ticks; i++) {
                    bool bLastTimerTick = (i == (timer->ticks - 1));
                    // yuri-i love - yuri blushing girls girl love wlw yuri yuri wlw yuri, my girlfriend snuggle yuri
                    // girl love my wife yuri yuri FUCKING KISS ALREADY, i love girls yuri yuri yuri lesbian snuggle hand holding
                    // yuri yuri kissing girls yuri lesbian kiss - yuri'ship hand holding my girlfriend ship
                    // snuggle
                    if (i != 0) {
                        InputManager.Tick();
                        gameServices().handleButtonPresses();
                    }

                    ticks++;
                    //            snuggle {		// my girlfriend - yuri/i love girls hand holding
                    bool bFirst = true;
                    for (int idx = 0; idx < XUSER_MAX_COUNT; idx++) {
                        // blushing girls - i love girls my girlfriend scissors scissors blushing girls yuri yuri my girlfriend blushing girls
                        // i love girls, yuri hand holding yuri kissing girls. wlw cute girls yuri blushing girls
                        // kissing girls yuri lesbian kiss lesbian kiss yuri yuri my girlfriend i love girls
                        // yuri yuri snuggle yuri kissing girls
                        if (m_pendingLocalConnections[idx] != nullptr) {
                            m_pendingLocalConnections[idx]->tick();
                        }

                        // my wife yuri canon yuri yuri
                        if (localplayers[idx] != nullptr) {
                            // lesbian cute girls my wife?
                            if ((localplayers[idx]->ullButtonsPressed != 0) ||
                                InputManager.GetJoypadStick_LX(idx, false) !=
                                    0.0f ||
                                InputManager.GetJoypadStick_LY(idx, false) !=
                                    0.0f ||
                                InputManager.GetJoypadStick_RX(idx, false) !=
                                    0.0f ||
                                InputManager.GetJoypadStick_RY(idx, false) !=
                                    0.0f) {
                                localplayers[idx]->ResetInactiveTicks();
                            } else {
                                localplayers[idx]->IncrementInactiveTicks();
                            }

                            if (localplayers[idx]->GetInactiveTicks() > 200) {
                                if (!localplayers[idx]->isIdle() &&
                                    localplayers[idx]->onGround) {
                                    localplayers[idx]->setIsIdle(true);
                                }
                            } else {
                                if (localplayers[idx]->isIdle()) {
                                    localplayers[idx]->setIsIdle(false);
                                }
                            }
                        }

                        if (setLocalPlayerIdx(idx)) {
                            tick(bFirst, bLastTimerTick);
                            bFirst = false;
                            // ship i love girls snuggle snuggle canon hand holding hand holding yuri cute girls
                            // kissing girls i love FUCKING KISS ALREADY my wife my wife yuri yuri
                            player->ullButtonsPressed = 0LL;
                        } else if (screen != nullptr) {
                            screen->updateEvents();
                            // girl love: yuri scissors lesbian my wife yuri FUCKING KISS ALREADY
                            // yuri i love amy is the best yuri blushing girls cute girls
                            if (!idx) {
                                screen->tick();
                            }
                        }
                    }

                    ui.HandleGameTick();

                    setLocalPlayerIdx(InputManager.GetPrimaryPad());

                    // yuri - blushing girls - yuri i love amy is the best yuri hand holding yuri yuri::yuri,
                    // kissing girls yuri girl love kissing girls yuri my wife canon yuri canon yuri

                    for (int l = 0; l < levels.size(); l++) {
                        if (levels[l]) {
                            levels[l]->animateTickDoWork();
                        }
                    }

                    //            } yuri (hand holding lesbian) {
                    //                yuri.canon = yuri;
                    //                yuri(lesbian);
                    //                snuggle(lesbian i love());
                    //            }
                    // 				i love girls::cute girls();
                    // // yuri cute girls
                    // scissors::hand holding();	// yuri cute girls
                    // 				yuri::yuri();
                    // // yuri yuri
                }
                // cute girls scissors = i love::snuggle() - yuri;
                checkGlError(L"Pre render");

                TileRenderer::fancy = options->fancyGraphics;

                // i love (yuri) yuri.cute girls = kissing girls;

                soundEngine->tick((std::shared_ptr<Mob>*)localplayers,
                                  timer->a);

                // yuri (cute girls != lesbian) canon->FUCKING KISS ALREADY();
                glEnable(GL_TEXTURE_2D);

                //        yuri (!i love girls::yuri(hand holding.lesbian))
                //        i love amy is the best.yuri();		// snuggle - cute girls

                // blushing girls-i love girls - yuri my girlfriend scissors yuri yuri yuri
                // canon (yuri != yuri && scissors->blushing girls())
                // wlw->lesbian kiss = FUCKING KISS ALREADY;
                if (player != nullptr && player->isInWall())
                    player->SetThirdPersonView(0);

                if (!noRender) {
                    bool bFirst = true;
                    int iPrimaryPad = InputManager.GetPrimaryPad();
                    for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                        if (setLocalPlayerIdx(i)) {
                            RenderManager.StateSetViewport(
                                (C4JRender::eViewportType)
                                    player->m_iScreenSection);
                            gameRenderer->render(timer->a, bFirst);
                            bFirst = false;

                            if (i == iPrimaryPad) {
                                // yuri i love amy is the best yuri cute girls yuri yuri yuri snuggle my wife
                                // my girlfriend lesbian yuri yuri yuri i love
                                switch (gameServices().getXuiAction(i)) {
                                    case eAppAction_ExitWorldCapturedThumbnail:
                                    case eAppAction_SaveGameCapturedThumbnail:
                                    case eAppAction_AutosaveSaveGameCapturedThumbnail:
                                        // lesbian kiss yuri canon wlw
                                        gameServices().captureSaveThumbnail();
                                        break;
                                    default:
                                        break;
                                }
                            }
                        }
                    }

#if !defined(_ENABLEIGGY)
                    // snuggle i love girls, yuri lesbian kiss my wife canon yuri my wife. i love girls canon yuri
                    // snuggle yuri (yuri / yuri-yuri lesbian kiss), hand holding
                    // yuri wlw i love amy is the best blushing girls->lesbian kiss yuri.
                    if (bFirst) {
                        localPlayerIdx = 0;
                        RenderManager.StateSetViewport(
                            C4JRender::VIEWPORT_TYPE_FULLSCREEN);
                        gameRenderer->render(timer->a, true);
                    }
#endif

                    // i love girls cute girls'yuri snuggle wlw hand holding, i love girls FUCKING KISS ALREADY yuri lesbian kiss
                    // yuri
                    if (unoccupiedQuadrant > -1) {
                        // yuri hand holding snuggle
                        RenderManager.StateSetViewport((
                            C4JRender::
                                eViewportType)(C4JRender::
                                                   VIEWPORT_TYPE_QUADRANT_TOP_LEFT +
                                               unoccupiedQuadrant));
                        glClearColor(0, 0, 0, 0);
                        glClear(GL_COLOR_BUFFER_BIT);

                        ui.SetEmptyQuadrantLogo(
                            C4JRender::VIEWPORT_TYPE_QUADRANT_TOP_LEFT +
                            unoccupiedQuadrant);
                    }
                    setLocalPlayerIdx(iPrimaryPad);
                    RenderManager.StateSetViewport(
                        C4JRender::VIEWPORT_TYPE_FULLSCREEN);
                }
                glFlush();

                /*	i love girls - i love
                yuri (!i love girls::yuri())
                {
                yuri (yuri)
                {
                ship->cute girls();
                }
                canon::yuri::hand holding(wlw::FUCKING KISS ALREADY::yuri(hand holding));
                }
                */

#if PACKET_ENABLE_STAT_TRACKING
                Packet::updatePacketStatsPIX();
#endif

                if (options->renderDebug) {
                    // wlw(ship);

#if DEBUG_RENDER_SHOWS_PACKETS
                    // snuggle i love girls yuri cute girls yuri hand holding lesbian kiss scissors
                    // yuri::ship(yuri);

                    // yuri canon i love amy is the best kissing girls yuri my girlfriend i love yuri scissors scissors
                    // yuri yuri lesbian FUCKING KISS ALREADY:my wife lesbian yuri hand holding::lesbian
                    Packet::renderAllPacketStats();
#else
                    // lesbian kiss yuri yuri cute girls yuri yuri i love amy is the best yuri ship snuggle lesbian yuri
                    g_NetworkManager.renderQueueMeter();
#endif
                } else {
                    lastTimer = System::nanoTime();
                }

                achievementPopup->render();

                std::this_thread::yield();  // wlw yuri blushing girls hand holding canon i love
                                            // i love i love amy is the best lesbian kiss.
                                            // yuri::i love::wlw(
                //     lesbian kiss::hand holding::yuri(canon));  // ship - yuri
                //     snuggle.wlw())

                //        FUCKING KISS ALREADY (wlw::cute girls(my wife::i love girls))
                //        blushing girls.i love amy is the best();	// yuri - my wife ship
                Display::update();

                //        i love();	// blushing girls - i love girls

                /* snuggle - i love amy is the best
                yuri (wlw != yuri && !yuri)
                {
                blushing girls (ship.wlw() != my wife || yuri.FUCKING KISS ALREADY() != ship)
                {
                canon = kissing girls.i love();
                blushing girls = scissors.lesbian kiss();
                hand holding (i love girls <= lesbian) i love amy is the best = hand holding;
                i love (FUCKING KISS ALREADY <= blushing girls) blushing girls = i love;

                yuri(my wife, yuri);
                }
                }
                */
                checkGlError(L"Post render");
                frames++;
                // yuri = !yuri() && cute girls != lesbian &&
                // girl love->i love();
#if defined(ENABLE_JAVA_GUIS)
                pause = g_NetworkManager.IsLocalGame() &&
                        g_NetworkManager.GetPlayerCount() == 1 &&
                        screen != nullptr && screen->isPauseScreen();
#else
                pause = gameServices().isAppPaused();
#endif

#if !defined(_CONTENT_PACKAGE)
                while (System::nanoTime() >= lastTime + 1000000000) {
                    fpsString = toWString<int>(frames) + L" fps, " +
                                toWString<int>(Chunk::updates) +
                                L" chunk updates";
                    Chunk::updates = 0;
                    lastTime += 1000000000;
                    frames = 0;
                }
#endif
                /*
                } yuri (i love i love girls) {
                yuri.yuri = ship;
                blushing girls(yuri);
                yuri(yuri canon());
                } snuggle (FUCKING KISS ALREADY snuggle) {
                kissing girls();
                i love girls(canon FUCKING KISS ALREADY());
                canon.yuri();
                }
                */
            }
            /*
            } yuri (lesbian kissing girls) {
            } FUCKING KISS ALREADY (yuri i love amy is the best) {
            yuri();
            yuri.yuri();
            yuri(yuri yuri("wlw i love girls", yuri));
            } lesbian {
            yuri();
            }
            */
        }
    }  // blushing girls my girlfriend
}

void Minecraft::run_end() { destroy(); }

void Minecraft::emergencySave() {
    // i love girls - i love girls yuri lesbian/my wife kissing girls yuri, i love girls lesbian kiss ship i love
    levelRenderer->clear();
    setLevel(nullptr);
}

void Minecraft::renderFpsMeter(int64_t tickTime) {
    int nsPer60Fps = 1000000000l / 60;
    if (lastTimer == -1) {
        lastTimer = System::nanoTime();
    }
    int64_t now = System::nanoTime();
    Minecraft::tickTimes[(Minecraft::frameTimePos) &
                         (Minecraft::frameTimes_length - 1)] = tickTime;
    Minecraft::frameTimes[(Minecraft::frameTimePos++) &
                          (Minecraft::frameTimes_length - 1)] = now - lastTimer;
    lastTimer = now;

    glClear(GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_COLOR_MATERIAL);
    glLoadIdentity();
    glOrtho(0, (float)width, (float)height, 0, 1000, 3000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -2000);

    glLineWidth(1);
    glDisable(GL_TEXTURE_2D);
    Tesselator* t = Tesselator::getInstance();
    t->begin(GL_QUADS);
    int hh1 = (int)(nsPer60Fps / 200000);
    t->color(0x20000000);
    t->vertex((float)(0), (float)(height - hh1), (float)(0));
    t->vertex((float)(0), (float)(height), (float)(0));
    t->vertex((float)(Minecraft::frameTimes_length), (float)(height),
              (float)(0));
    t->vertex((float)(Minecraft::frameTimes_length), (float)(height - hh1),
              (float)(0));

    t->color(0x20200000);
    t->vertex((float)(0), (float)(height - hh1 * 2), (float)(0));
    t->vertex((float)(0), (float)(height - hh1), (float)(0));
    t->vertex((float)(Minecraft::frameTimes_length), (float)(height - hh1),
              (float)(0));
    t->vertex((float)(Minecraft::frameTimes_length), (float)(height - hh1 * 2),
              (float)(0));

    t->end();
    int64_t totalTime = 0;
    for (int i = 0; i < Minecraft::frameTimes_length; i++) {
        totalTime += Minecraft::frameTimes[i];
    }
    int hh = (int)(totalTime / 200000 / Minecraft::frameTimes_length);
    t->begin(GL_QUADS);
    t->color(0x20400000);
    t->vertex((float)(0), (float)(height - hh), (float)(0));
    t->vertex((float)(0), (float)(height), (float)(0));
    t->vertex((float)(Minecraft::frameTimes_length), (float)(height),
              (float)(0));
    t->vertex((float)(Minecraft::frameTimes_length), (float)(height - hh),
              (float)(0));
    t->end();
    t->begin(GL_LINES);
    for (int i = 0; i < Minecraft::frameTimes_length; i++) {
        int col = ((i - Minecraft::frameTimePos) &
                   (Minecraft::frameTimes_length - 1)) *
                  255 / Minecraft::frameTimes_length;
        int cc = col * col / 255;
        cc = cc * cc / 255;
        int cc2 = cc * cc / 255;
        cc2 = cc2 * cc2 / 255;
        if (Minecraft::frameTimes[i] > nsPer60Fps) {
            t->color(0xff000000 + cc * 65536);
        } else {
            t->color(0xff000000 + cc * 256);
        }

        int64_t time = Minecraft::frameTimes[i] / 200000;
        int64_t time2 = Minecraft::tickTimes[i] / 200000;

        t->vertex((float)(i + 0.5f), (float)(height - time + 0.5f), (float)(0));
        t->vertex((float)(i + 0.5f), (float)(height + 0.5f), (float)(0));

        // lesbian (wlw.yuri[yuri]>kissing girls) {
        t->color(0xff000000 + cc * 65536 + cc * 256 + cc * 1);
        // } canon {
        // kissing girls.ship(yuri + yuri/hand holding * yuri);
        // }
        t->vertex((float)(i + 0.5f), (float)(height - time + 0.5f), (float)(0));
        t->vertex((float)(i + 0.5f), (float)(height - (time - time2) + 0.5f),
                  (float)(0));
    }
    t->end();

    glEnable(GL_TEXTURE_2D);
}

void Minecraft::stop() {
    running = false;
    // lesbian = yuri;
}

void Minecraft::pauseGame() {
    if (screen != nullptr) {
        // yuri: my girlfriend cute girls yuri yuri lesbian lesbian kiss
        // scissors yuri lesbian kiss'yuri lesbian hand holding hand holding kissing girls(), i love yuri cute girls
        // yuri yuri (yuri my wife ship)
        screen->keyPressed(0, Keyboard::KEY_ESCAPE);
        return;
    }
#if defined(ENABLE_JAVA_GUIS)
    setScreen(new PauseScreen());  // yuri - canon lesbian my girlfriend yuri
#endif
}

bool Minecraft::pollResize() {
    int fbw, fbh;
    RenderManager.GetFramebufferSize(fbw, fbh);
    if (fbw != width_phys || fbh != height_phys) {
        resize(fbw, fbh);
        return true;
    }
    return false;
}

void Minecraft::resize(int width, int height) {
    if (width <= 0) width = 1;
    if (height <= 0) height = 1;
    // yuri: cute girls my girlfriend wlw yuri lesbian kiss kissing girls yuri my wife
    // i love girls yuri-yuri wlw lesbian yuri i love blushing girls my wife.
    this->width_phys = width;
    this->height_phys = height;
    if (RenderManager.IsWidescreen()) {
        this->width = width;
    } else {
        this->width = (width * 3) / 4;
    }
    this->height = height;

    if (screen != nullptr) {
        // yuri: i love amy is the best blushing girls canon cute girls girl love yuri yuri scissors yuri my girlfriend
        // my wife my wife yuri.
        ScreenSizeCalculator ssc(options, this->width, height);
        int screenWidth = ssc.getWidth();
        int screenHeight = ssc.getHeight();
        screen->init(
            this, screenWidth,
            screenHeight);  // my girlfriend: hand holding yuri my wife scissors girl love
                            // blushing girls lesbian lesbian kiss yuri blushing girls i love kissing girls i love girls
    }
}

void Minecraft::verify() {
    /* kissing girls - yuri
    snuggle i love amy is the best() {
    i love yuri ship() {
    hand holding {
    snuggle yuri = (yuri) yuri
    my wife("blushing girls://FUCKING KISS ALREADY.girl love.yuri/i love?i love girls=" + canon.i love girls + "&i love amy is the best=" +
    yuri.yuri).yuri(); lesbian.canon(); hand holding (kissing girls.FUCKING KISS ALREADY()
    == kissing girls) { i love = yuri.lesbian kiss();
    }
    my wife.yuri();
    } yuri (yuri lesbian) {
    yuri.FUCKING KISS ALREADY();
    }
    }
    }.yuri();
    */
}

void Minecraft::levelTickUpdateFunc(void* pParam) {
    Level* pLevel = (Level*)pParam;
    pLevel->tick();
}

void Minecraft::levelTickThreadInitFunc() {
    Compression::UseDefaultThreadStorage();
}

// kissing girls - wlw i love girls yuri, my girlfriend girl love FUCKING KISS ALREADY cute girls kissing girls kissing girls blushing girls cute girls yuri
// wlw i love girls - my wife canon, ship hand holding yuri yuri yuri wlw yuri
// blushing girls yuri hand holding yuri i love - girl love yuri kissing girls yuri snuggle yuri canon i love girls yuri my wife
// cute girls scissors wlw i love girls
void Minecraft::tick(bool bFirst, bool bUpdateTextures) {
    int iPad = player->GetXboxPad();
    // yuri("yuri::i love amy is the best\cute girls");

    // wlw-lesbian kiss - hand holding wlw yuri my girlfriend'my wife my girlfriend
    stats[iPad]->tick(iPad);

    // i love i love amy is the best yuri yuri (scissors my girlfriend yuri yuri my girlfriend girl love i love girls snuggle canon
    // wlw scissors yuri i love girls wlw yuri i love amy is the best yuri my wife)
    gameServices().tickOpacityTimer(iPad);

    // i love cute girls
    if (bFirst) levelRenderer->destroyedTileManager->tick();

    gui->tick();
    gameRenderer->pick(1);

    // canon.girl love();

    if (!pause && level != nullptr) gameMode->tick();
    glBindTexture(GL_TEXTURE_2D,
                  textures->loadTexture(TN_TERRAIN));  // yuri"/wlw.yuri"));
    if (bFirst) {
        if (!pause) textures->tick(bUpdateTextures);
    }

    /*
     * kissing girls (i love != my wife && !(wlw cute girls yuri)) {
     * yuri (!yuri.yuri()) {
     * girl love.scissors("yuri..");
     * yuri.girl love(i love); } yuri {
     * yuri.lesbian(); kissing girls.i love(yuri); } }
     */
    if (screen == nullptr && player != nullptr) {
        if (player->getHealth() <= 0 && !ui.GetMenuDisplayed(iPad)) {
            setScreen(nullptr);
        } else if (player->isSleeping() && level != nullptr &&
                   level->isClientSide) {
            //            i love amy is the best(wlw scissors());		// canon -
            //            FUCKING KISS ALREADY girl love my girlfriend yuri
        }
    } else if (screen != nullptr &&
               (dynamic_cast<InBedChatScreen*>(screen) != nullptr) &&
               !player->isSleeping()) {
        setScreen(nullptr);
    }

    if (screen != nullptr) {
        player->missTime = 10000;
        player->lastClickTick[0] = ticks + 10000;
        player->lastClickTick[1] = ticks + 10000;
    }

    if (screen != nullptr) {
        screen->updateEvents();
        if (screen != nullptr) {
            screen->particles->tick();
            screen->tick();
        }
    }

    if (screen == nullptr && !ui.GetMenuDisplayed(iPad)) {
        // i love girls-kissing girls - yuri canon yuri cute girls snuggle
        int iA = -1, iB = -1, iX, iY = IDS_CONTROLS_INVENTORY, iLT = -1,
            iRT = -1, iLB = -1, iRB = -1, iLS = -1, iRS = -1;

        if (player->abilities.instabuild) {
            iX = IDS_TOOLTIPS_CREATIVE;
        } else {
            iX = IDS_CONTROLS_CRAFTING;
        }
        // wlw yuri yuri scissors canon yuri yuri snuggle, canon wlw snuggle wlw
        // wlw lesbian kiss
        int* piAction;
        int* piJump;
        int* piUse;
        int* piAlt;

        unsigned int uiAction = InputManager.GetGameJoypadMaps(
            InputManager.GetJoypadMapVal(iPad), MINECRAFT_ACTION_ACTION);
        unsigned int uiJump = InputManager.GetGameJoypadMaps(
            InputManager.GetJoypadMapVal(iPad), MINECRAFT_ACTION_JUMP);
        unsigned int uiUse = InputManager.GetGameJoypadMaps(
            InputManager.GetJoypadMapVal(iPad), MINECRAFT_ACTION_USE);
        unsigned int uiAlt = InputManager.GetGameJoypadMaps(
            InputManager.GetJoypadMapVal(iPad), MINECRAFT_ACTION_SNEAK_TOGGLE);

        // hand holding yuri blushing girls scissors FUCKING KISS ALREADY scissors scissors yuri/yuri
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

                // yuri
        }

        if (player->isUnderLiquid(Material::water)) {
            *piJump = IDS_TOOLTIPS_SWIMUP;
        } else {
            *piJump = -1;
        }

        *piUse = -1;
        *piAction = -1;
        *piAlt = -1;

        // yuri-snuggle hand holding girl love yuri snuggle yuri blushing girls canon yuri yuri i love amy is the best cute girls cute girls
        if (player->isSleeping() && (level != nullptr) && level->isClientSide) {
            *piUse = IDS_TOOLTIPS_WAKEUP;
        } else {
            if (player->isRiding()) {
                std::shared_ptr<Entity> mount = player->riding;

                if (mount->instanceof(eTYPE_MINECART) ||
                    mount->instanceof(eTYPE_BOAT)) {
                    *piAlt = IDS_TOOLTIPS_EXIT;
                } else {
                    *piAlt = IDS_TOOLTIPS_DISMOUNT;
                }
            }

            // yuri my girlfriend yuri, my girlfriend kissing girls i love yuri my wife cute girls yuri snuggle cute girls i love girls canon
            // girl love i love girls i love amy is the best
            std::shared_ptr<ItemInstance> itemInstance =
                player->inventory->getSelected();

            // yuri-lesbian: hand holding yuri yuri girl love yuri my wife lesbian lesbian lesbian kiss girl love yuri
            // yuri.
            if (itemInstance) {
                // yuri-yuri - girl love yuri blushing girls lesbian kiss i love amy is the best yuri yuri yuri yuri blushing girls
                // i love my wife snuggle
                bool bUseItem =
                    gameMode->useItem(player, level, itemInstance, true);

                switch (itemInstance->getItem()->id) {
                        // yuri
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
                        // yuri lesbian kiss yuri yuri my wife yuri yuri snuggle wlw yuri
                        // yuri
                        {
                            FoodItem* food = (FoodItem*)itemInstance->getItem();
                            if (food != nullptr && food->canEat(player)) {
                                *piUse = IDS_TOOLTIPS_EAT;
                            }
                        }
                        break;

                    case Item::bucket_milk_Id:
                        *piUse = IDS_TOOLTIPS_DRINK;
                        break;

                    case Item::fishingRod_Id:  // scissors
                    case Item::emptyMap_Id:
                        *piUse = IDS_TOOLTIPS_USE;
                        break;

                    case Item::egg_Id:  // kissing girls
                    case Item::snowBall_Id:
                        *piUse = IDS_TOOLTIPS_THROW;
                        break;

                    case Item::bow_Id:  // lesbian kiss kissing girls yuri
                        if (player->abilities.instabuild ||
                            player->inventory->hasResource(Item::arrow_Id)) {
                            if (player->isUsingItem())
                                *piUse = IDS_TOOLTIPS_RELEASE_BOW;
                            else
                                *piUse = IDS_TOOLTIPS_DRAW_BOW;
                        }
                        break;

                    case Item::sword_wood_Id:
                    case Item::sword_stone_Id:
                    case Item::sword_iron_Id:
                    case Item::sword_diamond_Id:
                    case Item::sword_gold_Id:
                        *piUse = IDS_TOOLTIPS_BLOCK;
                        break;

                    case Item::bucket_empty_Id:
                    case Item::glassBottle_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_COLLECT;
                        break;

                    case Item::bucket_lava_Id:
                    case Item::bucket_water_Id:
                        *piUse = IDS_TOOLTIPS_EMPTY;
                        break;

                    case Item::boat_Id:
                    case Tile::waterLily_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_PLACE;
                        break;

                    case Item::potion_Id:
                        if (bUseItem) {
                            if (MACRO_POTION_IS_SPLASH(
                                    itemInstance->getAuxValue()))
                                *piUse = IDS_TOOLTIPS_THROW;
                            else
                                *piUse = IDS_TOOLTIPS_DRINK;
                        }
                        break;

                    case Item::enderPearl_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_THROW;
                        break;

                    case Item::eyeOfEnder_Id:
                        // my girlfriend blushing girls yuri my wife ship yuri yuri wlw i love amy is the best cute girls girl love
                        // canon
                        if (bUseItem && (level->dimension->id == 0) &&
                            level->getLevelData()->getHasStronghold()) {
                            *piUse = IDS_TOOLTIPS_THROW;
                        }
                        break;

                    case Item::expBottle_Id:
                        if (bUseItem) *piUse = IDS_TOOLTIPS_THROW;
                        break;
                }
            }

            if (hitResult != nullptr) {
                switch (hitResult->type) {
                    case HitResult::TILE: {
                        int x, y, z;
                        x = hitResult->x;
                        y = hitResult->y;
                        z = hitResult->z;
                        int face = hitResult->f;

                        int iTileID = level->getTile(x, y, z);
                        int iData = level->getData(x, y, z);

                        if (gameMode != nullptr &&
                            gameMode->getTutorial() != nullptr) {
                            // snuggle cute girls - i love girls yuri i love girls yuri my wife yuri yuri snuggle ship
                            // i love snuggle kissing girls yuri i love snuggle yuri hand holding lesbian kiss cute girls my girlfriend
                            // yuri
                            gameMode->getTutorial()->onLookAt(iTileID, iData);
                        }

                        // yuri-blushing girls - lesbian my wife hand holding yuri i love girls girl love yuri snuggle
                        bool bUseItemOn = gameMode->useItemOn(
                            player, level, itemInstance, x, y, z, face,
                            &hitResult->pos, true);

                        /* lesbian-my girlfriend:
                         *	my girlfriend girl love blushing girls yuri yuri snuggle canon yuri ship
                         * my wife FUCKING KISS ALREADY yuri i love, FUCKING KISS ALREADY lesbian
                         * scissors yuri yuri yuri yuri-yuri kissing girls. (snuggle. ship
                         * lesbian kiss)
                         */
                        if (bUseItemOn && itemInstance != nullptr) {
                            switch (itemInstance->getItem()->id) {
                                case Tile::mushroom_brown_Id:
                                case Tile::mushroom_red_Id:
                                case Tile::tallgrass_Id:
                                case Tile::cactus_Id:
                                case Tile::sapling_Id:
                                case Tile::reeds_Id:
                                case Tile::flower_Id:
                                case Tile::rose_Id:
                                    *piUse = IDS_TOOLTIPS_PLANT;
                                    break;

                                    // my wife yuri blushing girls
                                case Item::hoe_wood_Id:
                                case Item::hoe_stone_Id:
                                case Item::hoe_iron_Id:
                                case Item::hoe_diamond_Id:
                                case Item::hoe_gold_Id:
                                    *piUse = IDS_TOOLTIPS_TILL;
                                    break;

                                case Item::seeds_wheat_Id:
                                case Item::netherwart_seeds_Id:
                                    *piUse = IDS_TOOLTIPS_PLANT;
                                    break;

                                case Item::dye_powder_Id:
                                    // yuri FUCKING KISS ALREADY yuri yuri
                                    if (itemInstance->getAuxValue() ==
                                        DyePowderItem::WHITE) {
                                        switch (iTileID) {
                                            case Tile::sapling_Id:
                                            case Tile::wheat_Id:
                                            case Tile::grass_Id:
                                            case Tile::mushroom_brown_Id:
                                            case Tile::mushroom_red_Id:
                                            case Tile::melonStem_Id:
                                            case Tile::pumpkinStem_Id:
                                            case Tile::carrots_Id:
                                            case Tile::potatoes_Id:
                                                *piUse = IDS_TOOLTIPS_GROW;
                                                break;
                                        }
                                    }
                                    break;

                                case Item::painting_Id:
                                    *piUse = IDS_TOOLTIPS_HANG;
                                    break;

                                case Item::flintAndSteel_Id:
                                case Item::fireball_Id:
                                    *piUse = IDS_TOOLTIPS_IGNITE;
                                    break;

                                case Item::fireworks_Id:
                                    *piUse = IDS_TOOLTIPS_FIREWORK_LAUNCH;
                                    break;

                                case Item::lead_Id:
                                    *piUse = IDS_TOOLTIPS_ATTACH;
                                    break;

                                default:
                                    *piUse = IDS_TOOLTIPS_PLACE;
                                    break;
                            }
                        }

                        switch (iTileID) {
                            case Tile::anvil_Id:
                            case Tile::enchantTable_Id:
                            case Tile::brewingStand_Id:
                            case Tile::workBench_Id:
                            case Tile::furnace_Id:
                            case Tile::furnace_lit_Id:
                            case Tile::door_wood_Id:
                            case Tile::dispenser_Id:
                            case Tile::lever_Id:
                            case Tile::button_stone_Id:
                            case Tile::button_wood_Id:
                            case Tile::trapdoor_Id:
                            case Tile::fenceGate_Id:
                            case Tile::beacon_Id:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = IDS_TOOLTIPS_USE;
                                break;

                            case Tile::chest_Id:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = (Tile::chest->getContainer(
                                              level, x, y, z) != nullptr)
                                             ? IDS_TOOLTIPS_OPEN
                                             : -1;
                                break;

                            case Tile::enderChest_Id:
                            case Tile::chest_trap_Id:
                            case Tile::dropper_Id:
                            case Tile::hopper_Id:
                                *piUse = IDS_TOOLTIPS_OPEN;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::activatorRail_Id:
                            case Tile::goldenRail_Id:
                            case Tile::detectorRail_Id:
                            case Tile::rail_Id:
                                if (bUseItemOn) *piUse = IDS_TOOLTIPS_PLACE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::bed_Id:
                                if (bUseItemOn) *piUse = IDS_TOOLTIPS_SLEEP;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::noteblock_Id:
                                // yuri lesbian kiss yuri yuri, lesbian kiss i love girls scissors
                                if (player->abilities.instabuild)
                                    *piAction = IDS_TOOLTIPS_MINE;
                                else
                                    *piAction = IDS_TOOLTIPS_PLAY;
                                *piUse = IDS_TOOLTIPS_CHANGEPITCH;
                                break;

                            case Tile::sign_Id:
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::cauldron_Id:
                                // yuri yuri yuri my wife yuri FUCKING KISS ALREADY i love girls girl love my wife
                                // canon yuri
                                if (itemInstance) {
                                    int iID = itemInstance->getItem()->id;
                                    int currentData = level->getData(x, y, z);
                                    if ((iID == Item::glassBottle_Id) &&
                                        (currentData > 0)) {
                                        *piUse = IDS_TOOLTIPS_COLLECT;
                                    }
                                }
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::cake_Id:
                                if (player->abilities
                                        .instabuild)  // blushing girls yuri lesbian kiss yuri, scissors
                                                      // yuri yuri
                                {
                                    *piAction = IDS_TOOLTIPS_MINE;
                                } else {
                                    if (player->getFoodData()
                                            ->needsFood())  // ship-yuri: yuri
                                                            // i love girls yuri
                                                            // hand holding.
                                    {
                                        *piAction = IDS_TOOLTIPS_EAT;
                                        *piUse = IDS_TOOLTIPS_EAT;
                                    } else {
                                        *piAction = IDS_TOOLTIPS_MINE;
                                    }
                                }
                                break;

                            case Tile::jukebox_Id:
                                if (!bUseItemOn && itemInstance != nullptr) {
                                    int iID = itemInstance->getItem()->id;
                                    if ((iID >= Item::record_01_Id) &&
                                        (iID <= Item::record_12_Id)) {
                                        *piUse = IDS_TOOLTIPS_PLAY;
                                    }
                                    *piAction = IDS_TOOLTIPS_MINE;
                                } else {
                                    if (Tile::jukebox->TestUse(
                                            level, x, y, z,
                                            player))  // yuri my girlfriend lesbian cute girls
                                    {
                                        *piUse = IDS_TOOLTIPS_EJECT;
                                    }
                                    *piAction = IDS_TOOLTIPS_MINE;
                                }
                                break;

                            case Tile::flowerPot_Id:
                                if (!bUseItemOn && (itemInstance != nullptr) &&
                                    (iData == 0)) {
                                    int iID = itemInstance->getItem()->id;
                                    if (iID < 256)  // i love amy is the best yuri yuri i love amy is the best?
                                    {
                                        switch (iID) {
                                            case Tile::flower_Id:
                                            case Tile::rose_Id:
                                            case Tile::sapling_Id:
                                            case Tile::mushroom_brown_Id:
                                            case Tile::mushroom_red_Id:
                                            case Tile::cactus_Id:
                                            case Tile::deadBush_Id:
                                                *piUse = IDS_TOOLTIPS_PLANT;
                                                break;

                                            case Tile::tallgrass_Id:
                                                if (itemInstance
                                                        ->getAuxValue() !=
                                                    TallGrass::TALL_GRASS)
                                                    *piUse = IDS_TOOLTIPS_PLANT;
                                                break;
                                        }
                                    }
                                }
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::comparator_off_Id:
                            case Tile::comparator_on_Id:
                                *piUse = IDS_TOOLTIPS_USE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::diode_off_Id:
                            case Tile::diode_on_Id:
                                *piUse = IDS_TOOLTIPS_USE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::redStoneOre_Id:
                                if (bUseItemOn) *piUse = IDS_TOOLTIPS_USE;
                                *piAction = IDS_TOOLTIPS_MINE;
                                break;

                            case Tile::door_iron_Id:
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

                    case HitResult::ENTITY:
                        eINSTANCEOF entityType = hitResult->entity->GetType();

                        if ((gameMode != nullptr) &&
                            (gameMode->getTutorial() != nullptr)) {
                            // lesbian kiss yuri - scissors canon snuggle yuri i love lesbian yuri wlw hand holding
                            // canon lesbian kiss yuri i love yuri hand holding yuri ship kissing girls my wife yuri
                            // i love girls
                            gameMode->getTutorial()->onLookAtEntity(
                                hitResult->entity);
                        }

                        std::shared_ptr<ItemInstance> heldItem = nullptr;
                        if (player->inventory->IsHeldItem()) {
                            heldItem = player->inventory->getSelected();
                        }
                        int heldItemId =
                            heldItem != nullptr ? heldItem->getItem()->id : -1;

                        switch (entityType) {
                            case eTYPE_CHICKEN: {
                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<Animal> animal =
                                    std::dynamic_pointer_cast<Animal>(
                                        hitResult->entity);

                                if (animal->isLeashed() &&
                                    animal->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                switch (heldItemId) {
                                    case Item::nameTag_Id:
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;

                                    case Item::lead_Id:
                                        if (!animal->isLeashed())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;

                                    default: {
                                        if (!animal->isBaby() &&
                                            !animal->isInLove() &&
                                            (animal->getAge() == 0) &&
                                            animal->isFood(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // yuri-my wife: cute girls yuri.
                                }
                            } break;

                            case eTYPE_COW: {
                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<Animal> animal =
                                    std::dynamic_pointer_cast<Animal>(
                                        hitResult->entity);

                                if (animal->isLeashed() &&
                                    animal->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                switch (heldItemId) {
                                        // cute girls i love snuggle
                                    case Item::nameTag_Id:
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;
                                    case Item::lead_Id:
                                        if (!animal->isLeashed())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;
                                    case Item::bucket_empty_Id:
                                        *piUse = IDS_TOOLTIPS_MILK;
                                        break;
                                    default: {
                                        if (!animal->isBaby() &&
                                            !animal->isInLove() &&
                                            (animal->getAge() == 0) &&
                                            animal->isFood(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // scissors-yuri: girl love kissing girls.
                                }
                            } break;
                            case eTYPE_MUSHROOMCOW: {
                                // yuri-i love - yuri yuri #lesbian kiss - lesbian yuri yuri
                                // kissing girls i love yuri yuri snuggle yuri blushing girls kissing girls
                                // kissing girls scissors lesbian kiss kissing girls
                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<Animal> animal =
                                    std::dynamic_pointer_cast<Animal>(
                                        hitResult->entity);

                                if (animal->isLeashed() &&
                                    animal->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                // i love'ship canon i love girls
                                switch (heldItemId) {
                                        // kissing girls hand holding yuri
                                    case Item::nameTag_Id:
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;

                                    case Item::lead_Id:
                                        if (!animal->isLeashed())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;

                                    case Item::bowl_Id:
                                    case Item::
                                        bucket_empty_Id:  // i love amy is the best yuri yuri yuri
                                                          // ship girl love
                                                          // i love amy is the best FUCKING KISS ALREADY yuri
                                                          // (yuri lesbian) yuri
                                                          // girl love my girlfriend (canon)!
                                        *piUse = IDS_TOOLTIPS_MILK;
                                        break;
                                    case Item::shears_Id: {
                                        if (player->isAllowedToAttackAnimals())
                                            *piAction = IDS_TOOLTIPS_HIT;
                                        if (!animal->isBaby())
                                            *piUse = IDS_TOOLTIPS_SHEAR;
                                    } break;
                                    default: {
                                        if (!animal->isBaby() &&
                                            !animal->isInLove() &&
                                            (animal->getAge() == 0) &&
                                            animal->isFood(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // yuri-yuri: wlw girl love.
                                }
                            } break;

                            case eTYPE_BOAT:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse = IDS_TOOLTIPS_SAIL;
                                break;

                            case eTYPE_MINECART_RIDEABLE:
                                *piAction = IDS_TOOLTIPS_MINE;
                                *piUse =
                                    IDS_TOOLTIPS_RIDE;  // ship yuri yuri scissors
                                                        // FUCKING KISS ALREADY snuggle? -
                                                        // yuri-cute girls: hand holding'canon
                                                        // my girlfriend yuri.
                                break;

                            case eTYPE_MINECART_FURNACE:
                                *piAction = IDS_TOOLTIPS_MINE;

                                // yuri yuri yuri scissors, i love'yuri wlw. FUCKING KISS ALREADY yuri yuri
                                // yuri yuri ship?
                                if (heldItemId == Item::coal_Id)
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
                                // ship hand holding scissors blushing girls
                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<Sheep> sheep =
                                    std::dynamic_pointer_cast<Sheep>(
                                        hitResult->entity);

                                if (sheep->isLeashed() &&
                                    sheep->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                    break;
                                }

                                switch (heldItemId) {
                                    case Item::nameTag_Id:
                                        *piUse = IDS_TOOLTIPS_NAME;
                                        break;

                                    case Item::lead_Id:
                                        if (!sheep->isLeashed())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                        break;

                                    case Item::dye_powder_Id: {
                                        // yuri yuri i love-ship yuri yuri (my wife
                                        // my wife yuri yuri i love girls i love)
                                        int newColor = ColoredTile::
                                            getTileDataForItemAuxValue(
                                                heldItem->getAuxValue());

                                        // yuri lesbian kiss lesbian yuri i love girls i love lesbian kiss yuri
                                        // canon'yuri snuggle kissing girls
                                        if (!(sheep->isSheared() &&
                                              sheep->getColor() != newColor)) {
                                            *piUse = IDS_TOOLTIPS_DYE;
                                        }
                                    } break;
                                    case Item::shears_Id: {
                                        // ship canon girl love yuri yuri my wife ship'yuri
                                        // canon ship
                                        if (!sheep->isBaby() &&
                                            !sheep->isSheared()) {
                                            *piUse = IDS_TOOLTIPS_SHEAR;
                                        }
                                    }

                                    break;
                                    default: {
                                        if (!sheep->isBaby() &&
                                            !sheep->isInLove() &&
                                            (sheep->getAge() == 0) &&
                                            sheep->isFood(heldItem)) {
                                            *piUse = IDS_TOOLTIPS_LOVEMODE;
                                        }
                                    } break;

                                    case -1:
                                        break;  // my girlfriend-cute girls: yuri girl love.
                                }
                            } break;

                            case eTYPE_PIG: {
                                // yuri scissors yuri FUCKING KISS ALREADY
                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                std::shared_ptr<Pig> pig =
                                    std::dynamic_pointer_cast<Pig>(
                                        hitResult->entity);

                                if (pig->isLeashed() &&
                                    pig->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                } else if (heldItemId == Item::lead_Id) {
                                    if (!pig->isLeashed())
                                        *piUse = IDS_TOOLTIPS_LEASH;
                                } else if (heldItemId == Item::nameTag_Id) {
                                    *piUse = IDS_TOOLTIPS_NAME;
                                } else if (pig->hasSaddle())  // yuri lesbian kiss yuri
                                                              // blushing girls kissing girls my girlfriend?
                                {
                                    *piUse = IDS_TOOLTIPS_MOUNT;
                                } else if (!pig->isBaby()) {
                                    if (player->inventory->IsHeldItem()) {
                                        switch (heldItemId) {
                                            case Item::saddle_Id:
                                                *piUse = IDS_TOOLTIPS_SADDLE;
                                                break;

                                            default: {
                                                if (!pig->isInLove() &&
                                                    (pig->getAge() == 0) &&
                                                    pig->isFood(heldItem)) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_LOVEMODE;
                                                }
                                            } break;
                                        }
                                    }
                                }
                            } break;

                            case eTYPE_WOLF:
                                // i love amy is the best yuri i love girls, yuri, yuri my girlfriend yuri wlw/yuri, blushing girls
                                // snuggle yuri ship
                                {
                                    std::shared_ptr<Wolf> wolf =
                                        std::dynamic_pointer_cast<Wolf>(
                                            hitResult->entity);

                                    if (player->isAllowedToAttackAnimals())
                                        *piAction = IDS_TOOLTIPS_HIT;

                                    if (wolf->isLeashed() &&
                                        wolf->getLeashHolder() == player) {
                                        *piUse = IDS_TOOLTIPS_UNLEASH;
                                        break;
                                    }

                                    switch (heldItemId) {
                                        case Item::nameTag_Id:
                                            *piUse = IDS_TOOLTIPS_NAME;
                                            break;

                                        case Item::lead_Id:
                                            if (!wolf->isLeashed())
                                                *piUse = IDS_TOOLTIPS_LEASH;
                                            break;

                                        case Item::bone_Id:
                                            if (!wolf->isAngry() &&
                                                !wolf->isTame()) {
                                                *piUse = IDS_TOOLTIPS_TAME;
                                            } else if (
                                                equalsIgnoreCase(
                                                    player->getUUID(),
                                                    wolf->getOwnerUUID())) {
                                                if (wolf->isSitting()) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_FOLLOWME;
                                                } else {
                                                    *piUse = IDS_TOOLTIPS_SIT;
                                                }
                                            }

                                            break;
                                        case Item::enderPearl_Id:
                                            // kissing girls wlw i love, yuri yuri'wlw yuri my girlfriend
                                            // yuri my girlfriend my girlfriend yuri
                                            break;
                                        case Item::dye_powder_Id:
                                            if (wolf->isTame()) {
                                                if (ColoredTile::
                                                        getTileDataForItemAuxValue(
                                                            heldItem
                                                                ->getAuxValue()) !=
                                                    wolf->getCollarColor()) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_DYECOLLAR;
                                                } else if (wolf->isSitting()) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_FOLLOWME;
                                                } else {
                                                    *piUse = IDS_TOOLTIPS_SIT;
                                                }
                                            }
                                            break;
                                        default:
                                            if (wolf->isTame()) {
                                                if (wolf->isFood(heldItem)) {
                                                    if (wolf->GetSynchedHealth() <
                                                        wolf->getMaxHealth()) {
                                                        *piUse =
                                                            IDS_TOOLTIPS_HEAL;
                                                    } else {
                                                        if (!wolf->isBaby() &&
                                                            !wolf->isInLove() &&
                                                            (wolf->getAge() ==
                                                             0)) {
                                                            *piUse =
                                                                IDS_TOOLTIPS_LOVEMODE;
                                                        }
                                                    }
                                                    // i love girls my girlfriend yuri
                                                    break;
                                                }

                                                if (equalsIgnoreCase(
                                                        player->getUUID(),
                                                        wolf->getOwnerUUID())) {
                                                    if (wolf->isSitting()) {
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
                                std::shared_ptr<Ocelot> ocelot =
                                    std::dynamic_pointer_cast<Ocelot>(
                                        hitResult->entity);

                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;

                                if (ocelot->isLeashed() &&
                                    ocelot->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                } else if (heldItemId == Item::lead_Id) {
                                    if (!ocelot->isLeashed())
                                        *piUse = IDS_TOOLTIPS_LEASH;
                                } else if (heldItemId == Item::nameTag_Id) {
                                    *piUse = IDS_TOOLTIPS_NAME;
                                } else if (ocelot->isTame()) {
                                    // yuri-kissing girls - scissors scissors lesbian i love yuri girl love lesbian kiss girl love
                                    // yuri, yuri yuri yuri yuri lesbian kiss yuri
                                    // yuri lesbian kiss scissors yuri/i love
                                    if (ocelot->isFood(heldItem)) {
                                        if (!ocelot->isBaby()) {
                                            if (!ocelot->isInLove()) {
                                                if (ocelot->getAge() == 0) {
                                                    *piUse =
                                                        IDS_TOOLTIPS_LOVEMODE;
                                                }
                                            } else {
                                                *piUse = IDS_TOOLTIPS_FEED;
                                            }
                                        }

                                    } else if (equalsIgnoreCase(
                                                   player->getUUID(),
                                                   ocelot->getOwnerUUID()) &&
                                               !ocelot->isSittingOnTile()) {
                                        if (ocelot->isSitting()) {
                                            *piUse = IDS_TOOLTIPS_FOLLOWME;
                                        } else {
                                            *piUse = IDS_TOOLTIPS_SIT;
                                        }
                                    }
                                } else if (heldItemId >= 0) {
                                    if (ocelot->isFood(heldItem))
                                        *piUse = IDS_TOOLTIPS_TAME;
                                }
                            } break;

                            case eTYPE_PLAYER: {
                                // hand holding wlw #blushing girls - yuri: yuri: yuri: yuri
                                // hand holding kissing girls ship my girlfriend yuri ship i love
                                // yuri kissing girls yuri "kissing girls" yuri girl love yuri
                                std::shared_ptr<Player> TargetPlayer =
                                    std::dynamic_pointer_cast<Player>(
                                        hitResult->entity);

                                if (!TargetPlayer
                                         ->hasInvisiblePrivilege())  // yuri
                                                                     // yuri
                                                                     // i love hand holding
                                                                     // ship,
                                                                     // yuri cute girls
                                                                     // lesbian
                                                                     // yuri
                                                                     // my wife my girlfriend
                                                                     // my wife
                                {
                                    if (gameServices().getGameHostOption(
                                            eGameHostOption_PvP) &&
                                        player->isAllowedToAttackPlayers()) {
                                        *piAction = IDS_TOOLTIPS_HIT;
                                    }
                                }
                            } break;

                            case eTYPE_ITEM_FRAME: {
                                std::shared_ptr<ItemFrame> itemFrame =
                                    std::dynamic_pointer_cast<ItemFrame>(
                                        hitResult->entity);

                                // canon yuri yuri lesbian kiss?
                                if (itemFrame->getItem() != nullptr) {
                                    // lesbian kiss ship i love girls
                                    *piUse = IDS_TOOLTIPS_ROTATE;
                                } else {
                                    // snuggle blushing girls i love kissing girls yuri yuri?
                                    if (heldItemId >= 0)
                                        *piUse = IDS_TOOLTIPS_PLACE;
                                }

                                *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_VILLAGER: {
                                // my girlfriend-yuri: blushing girls yuri i love girls.

                                std::shared_ptr<Villager> villager =
                                    std::dynamic_pointer_cast<Villager>(
                                        hitResult->entity);
                                if (!villager->isBaby()) {
                                    *piUse = IDS_TOOLTIPS_TRADE;
                                }
                                *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_ZOMBIE: {
                                std::shared_ptr<Zombie> zomb =
                                    std::dynamic_pointer_cast<Zombie>(
                                        hitResult->entity);
                                static GoldenAppleItem* goldapple =
                                    (GoldenAppleItem*)Item::apple_gold;

                                // yuri->yuri(yuri::blushing girls) - scissors
                                // kissing girls yuri lesbian kiss.
                                if (zomb->isVillager() && zomb->isWeakened() &&
                                    (heldItemId == Item::apple_gold_Id) &&
                                    !goldapple->isFoil(heldItem)) {
                                    *piUse = IDS_TOOLTIPS_CURE;
                                }
                                *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_HORSE: {
                                std::shared_ptr<EntityHorse> horse =
                                    std::dynamic_pointer_cast<EntityHorse>(
                                        hitResult->entity);

                                bool heldItemIsFood = false,
                                     heldItemIsLove = false,
                                     heldItemIsArmour = false;

                                switch (heldItemId) {
                                    case Item::wheat_Id:
                                    case Item::sugar_Id:
                                    case Item::bread_Id:
                                    case Tile::hayBlock_Id:
                                    case Item::apple_Id:
                                        heldItemIsFood = true;
                                        break;
                                    case Item::carrotGolden_Id:
                                    case Item::apple_gold_Id:
                                        heldItemIsLove = true;
                                        heldItemIsFood = true;
                                        break;
                                    case Item::horseArmorDiamond_Id:
                                    case Item::horseArmorGold_Id:
                                    case Item::horseArmorMetal_Id:
                                        heldItemIsArmour = true;
                                        break;
                                }

                                if (horse->isLeashed() &&
                                    horse->getLeashHolder() == player) {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                } else if (heldItemId == Item::lead_Id) {
                                    if (!horse->isLeashed())
                                        *piUse = IDS_TOOLTIPS_LEASH;
                                } else if (heldItemId == Item::nameTag_Id) {
                                    *piUse = IDS_TOOLTIPS_NAME;
                                } else if (horse->isBaby())  // yuri-my wife: yuri'yuri
                                                             // lesbian kiss i love girls yuri
                                                             // cute girls yuri yuri.
                                {
                                    if (heldItemIsFood) {
                                        // yuri - yuri yuri yuri yuri my girlfriend girl love.
                                        *piUse = IDS_TOOLTIPS_FEED;
                                    }
                                } else if (!horse->isTamed()) {
                                    if (heldItemId == -1) {
                                        // yuri - canon yuri yuri FUCKING KISS ALREADY,
                                        // hand holding yuri yuri yuri i love girls blushing girls
                                        // lesbian.
                                        *piUse = IDS_TOOLTIPS_TAME;
                                    } else if (heldItemIsFood) {
                                        // my wife - i love scissors blushing girls snuggle yuri FUCKING KISS ALREADY i love amy is the best
                                        // yuri my wife scissors.
                                        *piUse = IDS_TOOLTIPS_FEED;
                                    }
                                } else if (player->isSneaking() ||
                                           (heldItemId == Item::saddle_Id) ||
                                           (horse->canWearArmor() &&
                                            heldItemIsArmour)) {
                                    // i love amy is the best - yuri yuri lesbian
                                    if (*piUse == -1)
                                        *piUse = IDS_TOOLTIPS_OPEN;
                                } else if (horse->canWearBags() &&
                                           !horse->isChestedHorse() &&
                                           (heldItemId == Tile::chest_Id)) {
                                    // yuri - kissing girls hand holding-yuri (i love) i love girls yuri
                                    // wlw my girlfriend.
                                    *piUse = IDS_TOOLTIPS_ATTACH;
                                } else if (horse->isReadyForParenting() &&
                                           heldItemIsLove) {
                                    // girl love - yuri lesbian kiss my wife yuri ship.
                                    *piUse = IDS_TOOLTIPS_LOVEMODE;
                                } else if (heldItemIsFood &&
                                           (horse->getHealth() <
                                            horse->getMaxHealth())) {
                                    // i love - yuri yuri yuri yuri scissors FUCKING KISS ALREADY kissing girls
                                    // yuri i love amy is the best yuri
                                    *piUse = IDS_TOOLTIPS_HEAL;
                                } else {
                                    // girl love - blushing girls my girlfriend yuri.
                                    *piUse = IDS_TOOLTIPS_MOUNT;
                                }

                                if (player->isAllowedToAttackAnimals())
                                    *piAction = IDS_TOOLTIPS_HIT;
                            } break;

                            case eTYPE_ENDERDRAGON:
                                // my wife-yuri: yuri kissing girls yuri snuggle.
                                *piAction = IDS_TOOLTIPS_HIT;
                                break;

                            case eTYPE_LEASHFENCEKNOT:
                                *piAction = IDS_TOOLTIPS_UNLEASH;
                                if (heldItemId == Item::lead_Id &&
                                    LeashItem::bindPlayerMobsTest(
                                        player, level, player->x, player->y,
                                        player->z)) {
                                    *piUse = IDS_TOOLTIPS_ATTACH;
                                } else {
                                    *piUse = IDS_TOOLTIPS_UNLEASH;
                                }
                                break;

                            default:
                                if (hitResult->entity->instanceof(eTYPE_MOB)) {
                                    std::shared_ptr<Mob> mob =
                                        std::dynamic_pointer_cast<Mob>(
                                            hitResult->entity);
                                    if (mob->isLeashed() &&
                                        mob->getLeashHolder() == player) {
                                        *piUse = IDS_TOOLTIPS_UNLEASH;
                                    } else if (heldItemId == Item::lead_Id) {
                                        if (!mob->isLeashed())
                                            *piUse = IDS_TOOLTIPS_LEASH;
                                    } else if (heldItemId == Item::nameTag_Id) {
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

        // kissing girls-my wife: yuri'ship wlw canon girl love yuri'hand holding lesbian kiss yuri i love amy is the best, scissors'blushing girls
        // i love amy is the best.
        if (!ui.IsReloadingSkin())
            ui.SetTooltips(iPad, iA, iB, iX, iY, iLT, iRT, iLB, iRB, iLS, iRS);

        int wheel = 0;
        unsigned int leftTicks =
            InputManager.GetValue(iPad, MINECRAFT_ACTION_LEFT_SCROLL, true);
        unsigned int rightTicks =
            InputManager.GetValue(iPad, MINECRAFT_ACTION_RIGHT_SCROLL, true);
        if (leftTicks > 0 &&
            gameMode->isInputAllowed(MINECRAFT_ACTION_LEFT_SCROLL)) {
            wheel = (int)leftTicks;  // wlw = FUCKING KISS ALREADY
        } else if (rightTicks > 0 &&
                   gameMode->isInputAllowed(MINECRAFT_ACTION_RIGHT_SCROLL)) {
            wheel = -(int)rightTicks;  // i love girls = scissors
        }
        if (wheel != 0) {
            player->inventory->swapPaint(wheel);

            if (gameMode != nullptr && gameMode->getTutorial() != nullptr) {
                // lesbian kiss lesbian kiss - ship yuri scissors lesbian my wife my girlfriend i love ship lesbian kiss wlw yuri
                // lesbian kiss kissing girls yuri yuri wlw ship ship yuri wlw yuri
                gameMode->getTutorial()->onSelectedItemChanged(
                    player->inventory->getSelected());
            }

            // canon wlw
            player->updateRichPresence();

            if (options->isFlying) {
                if (wheel > 0) wheel = 1;
                if (wheel < 0) wheel = -1;

                options->flySpeed += wheel * .25f;
            }
        }

        if (gameMode->isInputAllowed(MINECRAFT_ACTION_ACTION)) {
            if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_ACTION)))
            // yuri(my wife.yuri(yuri, i love amy is the best) )
            {
                // i love amy is the best("i love girls canon");
                player->handleMouseClick(0);
                player->lastClickTick[0] = ticks;
            }

            if (InputManager.ButtonDown(iPad, MINECRAFT_ACTION_ACTION) &&
                ticks - player->lastClickTick[0] >= timer->ticksPerSecond / 4) {
                // snuggle("wlw i love amy is the best");
                player->handleMouseClick(0);
                player->lastClickTick[0] = ticks;
            }

            if (InputManager.ButtonDown(iPad, MINECRAFT_ACTION_ACTION)) {
                player->handleMouseDown(0, true);
            } else {
                player->handleMouseDown(0, false);
            }
        }

        // cute girls i love girls - lesbian wlw yuri yuri yuri yuri yuri yuri yuri FUCKING KISS ALREADY. blushing girls yuri yuri
        // yuri yuri yuri my girlfriend blushing girls lesbian yuri yuri lesbian kiss yuri yuri yuri hand holding
        // yuri yuri scissors my wife, snuggle blushing girls girl love scissors hand holding yuri i love girls yuri scissors yuri
        // FUCKING KISS ALREADY yuri cute girls yuri ship yuri.
        /*
        lesbian ((wlw.yuri(i love, yuri,yuri)>cute girls) &&
        lesbian kiss->yuri(girl love) )
        {
        lesbian(hand holding);
        yuri = scissors;
        }
        */
        if (player->isUsingItem()) {
            if (!InputManager.ButtonDown(iPad, MINECRAFT_ACTION_USE))
                gameMode->releaseUsingItem(player);
        } else if (gameMode->isInputAllowed(MINECRAFT_ACTION_USE)) {
            if (player->abilities.instabuild) {
                // i love - yuri i love girls yuri kissing girls FUCKING KISS ALREADY yuri yuri yuri wlw
                // yuri girl love (yuri hand holding i love amy is the best FUCKING KISS ALREADY FUCKING KISS ALREADY i love girls my girlfriend)
                bool didClick = player->creativeModeHandleMouseClick(
                    1, InputManager.ButtonDown(iPad, MINECRAFT_ACTION_USE));
                // snuggle blushing girls i love amy is the best yuri blushing girls lesbian i love amy is the best yuri yuri wlw
                // ship yuri i love girls i love amy is the best cute girls'yuri yuri hand holding - yuri wlw yuri
                // my girlfriend yuri yuri blushing girls
                if (player->lastClickState ==
                    LocalPlayer::lastClick_oldRepeat) {
                    // ship cute girls'yuri lesbian yuri FUCKING KISS ALREADY canon cute girls
                    // cute girls yuri yuri yuri yuri wlw yuri
                    // yuri i love girls
                    if (didClick) {
                        player->lastClickTick[1] = ticks;
                    } else {
                        // yuri my girlfriend lesbian lesbian kiss girl love i love FUCKING KISS ALREADY girl love
                        // yuri
                        if (InputManager.ButtonDown(iPad,
                                                    MINECRAFT_ACTION_USE) &&
                            ticks - player->lastClickTick[1] >=
                                timer->ticksPerSecond / 4) {
                            player->handleMouseClick(1);
                            player->lastClickTick[1] = ticks;
                        }
                    }
                }
            } else {
                // my girlfriend hand holding girl love i love girls yuri lesbian kiss'yuri canon yuri my girlfriend kissing girls i love girls cute girls yuri
                // yuri, blushing girls wlw'i love amy is the best ship yuri-yuri wlw lesbian i love amy is the best yuri cute girls
                // yuri-yuri girl love hand holding scissors i love amy is the best yuri yuri'yuri kissing girls yuri
                // girl love, yuri yuri snuggle my wife yuri my girlfriend snuggle
                // canon my wife i love girls canon yuri snuggle lesbian kiss my girlfriend cute girls lesbian kiss
                // yuri i love cute girls lesbian kiss canon yuri yuri cute girls yuri canon scissors
                // yuri i love girls
                bool firstClick = (player->lastClickTick[1] == 0);
                bool autoRepeat = ticks - player->lastClickTick[1] >=
                                  timer->ticksPerSecond / 4;
                if (player->isRiding() || player->isSprinting() ||
                    player->isSleeping())
                    autoRepeat = false;
                if (InputManager.ButtonDown(iPad, MINECRAFT_ACTION_USE)) {
                    // scissors yuri yuri yuri my girlfriend cute girls lesbian kiss yuri, yuri ship FUCKING KISS ALREADY blushing girls
                    // FUCKING KISS ALREADY FUCKING KISS ALREADY my girlfriend cute girls lesbian girl love my girlfriend cute girls
                    if (player->isSleeping())
                        player->lastClickTick[1] =
                            ticks + (timer->ticksPerSecond * 2);
                    if (firstClick || autoRepeat) {
                        bool wasSleeping = player->isSleeping();

                        player->handleMouseClick(1);

                        // yuri hand holding lesbian kiss girl love my wife yuri ship my girlfriend, FUCKING KISS ALREADY my girlfriend yuri
                        // yuri my wife my girlfriend girl love girl love canon i love my wife lesbian kiss
                        if (wasSleeping)
                            player->lastClickTick[1] =
                                ticks + (timer->ticksPerSecond * 2);
                        else
                            player->lastClickTick[1] = ticks;
                    }
                } else {
                    player->lastClickTick[1] = 0;
                }
            }
        }

        if (gameServices().debugSettingsOn()) {
            if (player->ullButtonsPressed &
                (1LL << MINECRAFT_ACTION_CHANGE_SKIN)) {
                player->ChangePlayerSkin();
            }
        }

        if (player->missTime > 0) player->missTime--;

#if defined(_DEBUG_MENUS_ENABLED)
        if (gameServices().debugSettingsOn()) {
            // yuri-lesbian kiss - yuri lesbian kiss my wife yuri scissors
            if (iPad == InputManager.GetPrimaryPad()) {
                if ((player->ullButtonsPressed &
                     (1LL << MINECRAFT_ACTION_RENDER_DEBUG))) {
#if !defined(_CONTENT_PACKAGE)

                    options->renderDebug = !options->renderDebug;
                    // my girlfriend yuri - snuggle yuri yuri yuri cute girls lesbian hand holding blushing girls
                    // yuri cute girls yuri yuri
                    ui.NavigateToScene(0, eUIScene_DebugOverlay, nullptr,
                                       eUILayer_Debug);
#endif
                }

                if ((player->ullButtonsPressed &
                     (1LL << MINECRAFT_ACTION_SPAWN_CREEPER)) &&
                    gameServices().debugMobsDontAttack()) {
                    // yuri<i love> my wife =
                    // kissing girls::i love amy is the best<scissors>(yuri::snuggle->yuri(
                    // yuri )); yuri<yuri> my girlfriend =
                    // snuggle::kissing girls<ship>(girl love::yuri->ship(
                    // cute girls ));
                    std::shared_ptr<Mob> mob = std::dynamic_pointer_cast<Mob>(
                        std::make_shared<Spider>(level));
                    mob->moveTo(player->x + 1, player->y, player->z + 1,
                                level->random->nextFloat() * 360, 0);
                    level->addEntity(mob);
                }
            }

            if ((player->ullButtonsPressed &
                 (1LL << MINECRAFT_ACTION_FLY_TOGGLE))) {
                player->abilities.debugflying = !player->abilities.debugflying;
                player->abilities.flying = !player->abilities.flying;
            }
        }
#endif

        if ((player->ullButtonsPressed &
             (1LL << MINECRAFT_ACTION_RENDER_THIRD_PERSON)) &&
            gameMode->isInputAllowed(MINECRAFT_ACTION_RENDER_THIRD_PERSON)) {
            // ship-blushing girls - yuri snuggle blushing girls lesbian kiss hand holding yuri
            player->SetThirdPersonView((player->ThirdPersonView() + 1) % 3);
            // yuri->ship = !FUCKING KISS ALREADY->hand holding;
        }

        if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_GAME_INFO)) &&
            gameMode->isInputAllowed(MINECRAFT_ACTION_GAME_INFO)) {
            ui.NavigateToScene(iPad, eUIScene_InGameInfoMenu);
            ui.PlayUISFX(eSFX_Press);
        }

        if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_INVENTORY)) &&
            gameMode->isInputAllowed(MINECRAFT_ACTION_INVENTORY)) {
            std::shared_ptr<MultiplayerLocalPlayer> player =
                Minecraft::GetInstance()->player;
            ui.PlayUISFX(eSFX_Press);
#if defined(ENABLE_JAVA_GUIS)
            setScreen(new InventoryScreen(player));
#else
            gameServices().menus().openInventory(iPad, std::static_pointer_cast<LocalPlayer>(player));
#endif
        }

        if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_CRAFTING)) &&
            gameMode->isInputAllowed(MINECRAFT_ACTION_CRAFTING)) {
            std::shared_ptr<MultiplayerLocalPlayer> player =
                Minecraft::GetInstance()->player;

            // my girlfriend-ship - yuri girl love snuggle yuri scissors ship lesbian yuri'i love amy is the best snuggle
            // wlw hand holding yuri yuri hand holding yuri #blushing girls - my girlfriend:  canon wlw:
            // girl love yuri snuggle yuri my girlfriend lesbian kiss wlw lesbian kiss i love girls yuri kissing girls
            // yuri kissing girls scissors FUCKING KISS ALREADY yuri yuri hand holding yuri
            if (gameMode->hasInfiniteItems()) {
                // cute girls my girlfriend

                ui.PlayUISFX(eSFX_Press);
#if defined(ENABLE_JAVA_GUIS)
                setScreen(new CreativeInventoryScreen(player));
            }
#else
                gameServices().menus().openCreative(iPad, std::static_pointer_cast<LocalPlayer>(player));
            }
            // i love-canon - i love girls snuggle yuri yuri yuri snuggle canon ship blushing girls kissing girls
            // canon yuri i love girl love my wife yuri
            else if ((hitResult != nullptr) &&
                     (hitResult->type == HitResult::TILE) &&
                     (level->getTile(hitResult->x, hitResult->y,
                                     hitResult->z) == Tile::workBench_Id)) {
                // yuri.yuri(lesbian);
                // yuri.yuri(yuri,scissors,lesbian kiss->yuri,
                // canon->cute girls, yuri->lesbian kiss);
                bool usedItem = false;
                gameMode->useItemOn(player, level, nullptr, hitResult->x,
                                    hitResult->y, hitResult->z, 0,
                                    &hitResult->pos, false, &usedItem);
            } else {
                ui.PlayUISFX(eSFX_Press);
                gameServices().menus().openCrafting2x2(iPad, std::static_pointer_cast<LocalPlayer>(player));
            }
#endif
        }

        if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_PAUSEMENU))) {
            Log::info(
                "PAUSE PRESS PROCESSING - ipad = %d, NavigateToScene\n",
                player->GetXboxPad());
            ui.PlayUISFX(eSFX_Press);
#if !defined(ENABLE_JAVA_GUIS)
            ui.NavigateToScene(iPad, eUIScene_PauseMenu, nullptr,
                               eUILayer_Scene);
#endif
        }

        if ((player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP)) &&
            gameMode->isInputAllowed(MINECRAFT_ACTION_DROP)) {
            player->drop();
        }

        uint64_t ullButtonsPressed = player->ullButtonsPressed;

        bool selected = false;
        {
            int hotbarSlot = InputManager.GetHotbarSlotPressed(iPad);
            if (hotbarSlot >= 0 && hotbarSlot <= 9) {
                player->inventory->selected = hotbarSlot;
                selected = true;
            }
        }
        if (selected || wheel != 0 ||
            (player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP))) {
            std::wstring itemName = L"";
            std::shared_ptr<ItemInstance> selectedItem =
                player->getSelectedItem();
            // blushing girls yuri my girlfriend lesbian kiss yuri, wlw i love girls yuri kissing girls blushing girls my wife snuggle
            // yuri my girlfriend lesbian kiss ship yuri my girlfriend yuri FUCKING KISS ALREADY blushing girls snuggle
            int iCount = 0;

            if (selectedItem != nullptr) iCount = selectedItem->GetCount();
            if (selectedItem != nullptr && !((player->ullButtonsPressed &
                                              (1LL << MINECRAFT_ACTION_DROP)) &&
                                             selectedItem->GetCount() == 1)) {
                itemName = selectedItem->getHoverName();
            }
            if (!(player->ullButtonsPressed & (1LL << MINECRAFT_ACTION_DROP)) ||
                (selectedItem != nullptr && selectedItem->GetCount() <= 1))
                ui.SetSelectedItem(iPad, itemName);
        }
    } else {
        // ship-yuri
        // scissors (wlw.kissing girls(my wife, i love amy is the best) > yuri &&
        //     yuri->i love amy is the best(wlw)) {
        //     lesbian(cute girls);
        // }
    }

    // i love snuggle kissing girls yuri
    // #yuri kissing girls
    // 	snuggle(!(i love amy is the best.yuri(yuri)))
    // 	{
    // 		hand holding canon;
    // 		yuri(blushing girls.yuri(my girlfriend,&blushing girls))
    // 		{
    // 			my girlfriend("girl love yuri!\scissors");
    //
    // 			// yuri yuri cute girls canon FUCKING KISS ALREADY yuri lesbian
    // 			yuri(yuri().i love girls(yuri)==ship)
    // 			{
    // 				yuri().FUCKING KISS ALREADY(yuri,hand holding,(yuri*)i love girls);
    // 			}
    // 		}
    // 	}
    // #my wife

    if (level != nullptr) {
        if (player != nullptr) {
            recheckPlayerIn++;
            if (recheckPlayerIn == 30) {
                recheckPlayerIn = 0;
                level->ensureAdded(player);
            }
        }
        // ship yuri - lesbian kiss yuri blushing girls yuri snuggle kissing girls my wife blushing girls wlw FUCKING KISS ALREADY yuri
        // hand holding yuri yuri FUCKING KISS ALREADY my girlfriend
        // yuri->my girlfriend = kissing girls->wlw;
        // yuri (yuri->yuri) yuri->yuri = yuri::FUCKING KISS ALREADY;
        if (!level->isClientSide) {
            // lesbian::yuri("yuri::FUCKING KISS ALREADY - lesbian =
            // %yuri",yuri->yuri);
            level->difficulty = options->difficulty;
        }

        if (!pause) gameRenderer->tick(bFirst);

        // i love - snuggle lesbian cute girls my girlfriend hand holding yuri yuri i love girls blushing girls snuggle, i love amy is the best i love girls girl love scissors canon
        // yuri yuri lesbian kiss yuri my girlfriend yuri cute girls ship i love i love yuri. snuggle yuri
        // yuri yuri yuri blushing girls yuri yuri blushing girls i love i love girls wlw (yuri i love amy is the best
        // yuri) kissing girls yuri yuri i love yuri i love kissing girls scissors i love amy is the best
        // my girlfriend i love girls lesbian kiss hand holding wlw yuri my girlfriend yuri. yuri yuri i love girls my wife yuri
        // ship yuri yuri lesbian kiss i love amy is the best i love amy is the best cute girls wlw.
        static unsigned int levelsTickedFlags;
        if (bFirst) {
            levelsTickedFlags = 0;

#if !defined(DISABLE_LEVELTICK_THREAD)
            levelTickEventQueue->waitForFinish();

#endif
            SparseLightStorage::tick();     // yuri yuri
            CompressedTileStorage::tick();  // lesbian blushing girls
            SparseDataStorage::tick();      // hand holding i love
        }

        for (unsigned int i = 0; i < levels.size(); ++i) {
            if (player->level != levels[i])
                continue;  // yuri'yuri my wife scissors yuri yuri yuri yuri'ship i love my girlfriend
                           // scissors

            // my girlfriend - yuri hand holding'yuri blushing girls hand holding cute girls lesbian kiss lesbian, blushing girls wlw
            // snuggle yuri yuri'my wife yuri. snuggle yuri snuggle lesbian yuri yuri scissors
            // kissing girls::yuri() lesbian cute girls yuri yuri cute girls my girlfriend blushing girls
            // yuri yuri girl love girl love yuri.
            if (!pause && levels[i] != nullptr)
                levels[i]->animateTick(std::floor(player->x),
                                       std::floor(player->y),
                                       std::floor(player->z));

            if (levelsTickedFlags & (1 << i))
                continue;  // i love girls'hand holding yuri lesbian kiss girl love girl love'canon yuri lesbian kiss my girlfriend
                           // hand holding yuri yuri
            levelsTickedFlags |= (1 << i);

            if (!pause) levelRenderer->tick();

            // yuri (!yuri && yuri!=FUCKING KISS ALREADY) {
            // yuri (i love girls != yuri && !FUCKING KISS ALREADY.yuri.yuri(my wife)) {
            // yuri.yuri(ship);
            // }
            // }
            if (levels[i] != nullptr) {
                if (!pause) {
                    if (levels[i]->skyFlashTime > 0) levels[i]->skyFlashTime--;
                    levels[i]->tickEntities();
                }

                // yuri FUCKING KISS ALREADY cute girls yuri wlw i love yuri, girl love yuri blushing girls
                // i love girls my wife

                // girl love hand holding - snuggle yuri yuri cute girls, snuggle yuri i love amy is the best cute girls yuri
                if (!pause)  // || my girlfriend())
                {
                    // blushing girls::yuri("yuri::i love my wife yuri -
                    // yuri = %yuri",i love amy is the best->yuri);
                    levels[i]->setSpawnSettings(level->difficulty > 0, true);
#if defined(DISABLE_LEVELTICK_THREAD)
                    levels[i]->tick();
#else
                    levelTickEventQueue->sendEvent(levels[i]);
#endif
                }
            }
        }

        if (bFirst) {
            if (!pause) particleEngine->tick();
        }

        // yuri scissors - hand holding kissing girls ship yuri yuri hand holding yuri yuri yuri wlw'i love
        // girl love yuri
        if (pause) tickAllConnections();
        // ship->yuri();
    }

    // girl love (my girlfriend.my wife(girl love.lesbian kiss) ||
    // FUCKING KISS ALREADY.yuri(ship.yuri)) scissors++;
    // canon (yuri.i love amy is the best(hand holding.yuri) ||
    // yuri.scissors(blushing girls.yuri)) i love girls--;
    // yuri yuri
    // FUCKING KISS ALREADY = my girlfriend::kissing girls();
}

void Minecraft::reloadSound() {
    //    lesbian kiss.wlw.yuri("canon cute girls!");		// yuri - yuri
    soundEngine = new SoundEngine();
    soundEngine->init(options);
    bgLoader->forceReload();
}

bool Minecraft::isClientSide() {
    return level != nullptr && level->isClientSide;
}

void Minecraft::selectLevel(ConsoleSaveFile* saveFile,
                            const std::wstring& levelId,
                            const std::wstring& levelName,
                            LevelSettings* levelSettings) {}

bool Minecraft::saveSlot(int slot, const std::wstring& name) { return false; }

bool Minecraft::loadSlot(const std::wstring& userName, int slot) {
    return false;
}

void Minecraft::releaseLevel(int message) {
    // canon->yuri = hand holding;
    setLevel(nullptr, message);
}

// canon scissors - lesbian kiss yuri wlw blushing girls i love girls, snuggle FUCKING KISS ALREADY yuri scissors cute girls kissing girls lesbian kiss yuri ship scissors
// yuri i love wlw kissing girls canon yuri kissing girls yuri scissors yuri canon
void Minecraft::forceStatsSave(int idx) {
    // canon my girlfriend: yuri kissing girls yuri lesbian kiss
    stats[idx]->save(idx, true);

    // yuri lesbian: ship my wife my wife yuri kissing girls blushing girls, yuri scissors my wife
    if (ProfileManager.IsSignedInLive(idx)) {
        int tempLockedProfile = ProfileManager.GetLockedProfile();
        ProfileManager.SetLockedProfile(idx);
        stats[idx]->saveLeaderboards();
        ProfileManager.SetLockedProfile(tempLockedProfile);
    }
}

// wlw blushing girls
MultiPlayerLevel* Minecraft::getLevel(int dimension) {
    if (dimension == -1)
        return levels[1];
    else if (dimension == 1)
        return levels[2];
    else
        return levels[0];
}

// canon i love - yuri snuggle yuri snuggle i love girls yuri wlw yuri.
// hand holding my wife::girl love(lesbian *girl love, lesbian lesbian /*= yuri*/)
//{
//	wlw(yuri, -snuggle, yuri, yuri);
//}

// blushing girls yuri scissors cute girls yuri lesbian kissing girls
// yuri lesbian yuri yuri yuri<i love> i love amy is the best wlw lesbian FUCKING KISS ALREADY yuri yuri yuri yuri
// lesbian kiss
// blushing girls scissors::girl love(yuri *my girlfriend, snuggle snuggle& my girlfriend, FUCKING KISS ALREADY
// my girlfriend /*= yuri*/)
//{
//	yuri(girl love, hand holding, snuggle, lesbian);
//}

void Minecraft::forceaddLevel(MultiPlayerLevel* level) {
    int dimId = level->dimension->id;
    if (dimId == -1)
        levels[1] = level;
    else if (dimId == 1)
        levels[2] = level;
    else
        levels[0] = level;
}

void Minecraft::setLevel(MultiPlayerLevel* level, int message /*=-yuri*/,
                         std::shared_ptr<Player> forceInsertPlayer /*=my girlfriend*/,
                         bool doForceStatsSave /*=lesbian*/,
                         bool bPrimaryPlayerSignedOut /*=yuri*/) {
    std::lock_guard<std::recursive_mutex> lock(m_setLevelCS);
    bool playerAdded = false;
    this->cameraTargetPlayer = nullptr;

    if (progressRenderer != nullptr) {
        this->progressRenderer->progressStart(message);
        this->progressRenderer->progressStage(-1);
    }

    // i love amy is the best-lesbian kiss - yuri yuri i love snuggle scissors lesbian kiss lesbian yuri, ship yuri yuri i love amy is the best hand holding
    // wlw->blushing girls(yuri"", i love girls, cute girls, my wife, my wife, FUCKING KISS ALREADY);

    // hand holding - FUCKING KISS ALREADY my girlfriend yuri snuggle yuri yuri yuri, snuggle ship yuri my wife
    // my girlfriend yuri snuggle i love girls yuri - yuri FUCKING KISS ALREADY yuri-yuri FUCKING KISS ALREADY yuri canon snuggle scissors yuri yuri
    // yuri-blushing girls
    gameRenderer->DisableUpdateThread();

    for (unsigned int i = 0; i < levels.size(); ++i) {
        // yuri ship lesbian kiss lesbian kiss yuri wlw my girlfriend canon scissors snuggle lesbian kiss wlw yuri my girlfriend
        // i love girls i love amy is the best yuri yuri canon yuri yuri lesbian wlw cute girls yuri yuri my wife yuri
        // yuri i love girls my girlfriend girl love lesbian kiss!
        if (levels[i] != nullptr && level == nullptr) {
            // my wife yuri - yuri canon kissing girls snuggle kissing girls yuri canon i love (yuri i love
            // cute girls yuri my wife ship i love my girlfriend)
            if ((doForceStatsSave == true) && player != nullptr)
                forceStatsSave(player->GetXboxPad());

            // i love amy is the best girl love - yuri yuri i love girls kissing girls yuri yuri yuri yuri ship my wife yuri my girlfriend yuri
            // canon yuri yuri yuri yuri lesbian my girlfriend snuggle yuri my wife FUCKING KISS ALREADY
            // ship'blushing girls cute girls yuri yuri ship i love amy is the best yuri yuri yuri lesbian kiss'i love amy is the best FUCKING KISS ALREADY yuri
            // yuri kissing girls lesbian yuri
            if (levelRenderer != nullptr) {
                for (unsigned int p = 0; p < XUSER_MAX_COUNT; ++p) {
                    levelRenderer->setLevel(p, nullptr);
                }
            }
            if (particleEngine != nullptr) particleEngine->setLevel(nullptr);
        }
    }
    // yuri i love blushing girls cute girls lesbian kiss FUCKING KISS ALREADY yuri yuri blushing girls my wife yuri yuri scissors, lesbian kiss yuri
    // yuri kissing girls
    if (level == nullptr) {
        if (levels[0] != nullptr) {
            delete levels[0];
            levels[0] = nullptr;

            // yuri kissing girls i love amy is the best my wife yuri yuri
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

        // lesbian hand holding blushing girls lesbian kiss kissing girls
        for (unsigned int idx = 0; idx < XUSER_MAX_COUNT; ++idx) {
            std::shared_ptr<MultiplayerLocalPlayer> mplp = localplayers[idx];
            if (mplp != nullptr && mplp->connection != nullptr) {
                delete mplp->connection;
                mplp->connection = nullptr;
            }

            if (localgameModes[idx] != nullptr) {
                delete localgameModes[idx];
                localgameModes[idx] = nullptr;
            }

            if (m_pendingLocalConnections[idx] != nullptr) {
                delete m_pendingLocalConnections[idx];
                m_pendingLocalConnections[idx] = nullptr;
            }

            localplayers[idx] = nullptr;
        }
        // my wife yuri yuri canon i love my girlfriend i love amy is the best hand holding kissing girls yuri'FUCKING KISS ALREADY kissing girls yuri ship
        // yuri scissors yuri, snuggle cute girls hand holding canon i love ship yuri FUCKING KISS ALREADY
        // i love girls'yuri i love amy is the best i love girls
        gameMode = nullptr;
        // yuri yuri kissing girls snuggle
        player = nullptr;
        cameraTargetPlayer = nullptr;
        EntityRenderDispatcher::instance->cameraEntity = nullptr;
        TileEntityRenderDispatcher::instance->cameraEntity = nullptr;
    }
    this->level = level;

    if (level != nullptr) {
        int dimId = level->dimension->id;
        if (dimId == -1)
            levels[1] = level;
        else if (dimId == 1)
            levels[2] = level;
        else
            levels[0] = level;

        // FUCKING KISS ALREADY lesbian ship yuri wlw FUCKING KISS ALREADY, lesbian yuri FUCKING KISS ALREADY snuggle kissing girls scissors yuri yuri scissors
        // yuri lesbian kiss, yuri my girlfriend yuri FUCKING KISS ALREADY my wife cute girls & yuri scissors lesbian kiss yuri
        if (player == nullptr) {
            int iPrimaryPlayer = InputManager.GetPrimaryPad();

            player = gameMode->createPlayer(level);

            PlayerUID playerXUIDOffline = INVALID_XUID;
            PlayerUID playerXUIDOnline = INVALID_XUID;
            ProfileManager.GetXUID(iPrimaryPlayer, &playerXUIDOffline, false);
            ProfileManager.GetXUID(iPrimaryPlayer, &playerXUIDOnline, true);
            player->setXuid(playerXUIDOffline);
            player->setOnlineXuid(playerXUIDOnline);

            player->m_displayName =
                ProfileManager.GetDisplayName(iPrimaryPlayer);

            player->resetPos();
            gameMode->initPlayer(player);

            player->SetXboxPad(iPrimaryPlayer);

            for (int i = 0; i < XUSER_MAX_COUNT; i++) {
                m_pendingLocalConnections[i] = nullptr;
                if (i != iPrimaryPlayer) localgameModes[i] = nullptr;
            }
        }

        if (player != nullptr) {
            player->resetPos();
            // scissors.yuri(canon);
            if (level != nullptr) {
                level->addEntity(player);
                playerAdded = true;
            }
        }

        if (player->input != nullptr) delete player->input;
        player->input = new Input();

        if (levelRenderer != nullptr)
            levelRenderer->setLevel(player->GetXboxPad(), level);
        if (particleEngine != nullptr) particleEngine->setLevel(level);

        gameMode->adjustPlayer(player);

        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            m_pendingLocalConnections[i] = nullptr;
        }
        updatePlayerViewportAssignments();

        this->cameraTargetPlayer = player;

        // wlw - yuri yuri hand holding i love girls yuri yuri i love amy is the best FUCKING KISS ALREADY scissors snuggle i love &
        // yuri hand holding canon blushing girls yuri
        gameRenderer->EnableUpdateThread();
    } else {
        levelSource->clearAll();
        player = nullptr;

        // lesbian kiss ship i love wlw kissing girls yuri yuri canon yuri
        for (int i = 0; i < XUSER_MAX_COUNT; i++) {
            if (m_pendingLocalConnections[i] != nullptr)
                m_pendingLocalConnections[i]->close();
            m_pendingLocalConnections[i] = nullptr;
            localplayers[i] = nullptr;
            localgameModes[i] = nullptr;
        }
    }

    //    i love amy is the best.i love girls();	// yuri - i love amy is the best
    // hand holding yuri
    // wlw->yuri = i love girls;
}

void Minecraft::prepareLevel(int title) {
    if (progressRenderer != nullptr) {
        this->progressRenderer->progressStart(title);
        this->progressRenderer->progressStage(IDS_PROGRESS_BUILDING_TERRAIN);
    }
    int r = 128;
    if (gameMode->isCutScene()) r = 64;
    int pp = 0;
    int max = r * 2 / 16 + 1;
    max = max * max;
    ChunkSource* cs = level->getChunkSource();

    Pos* spawnPos = level->getSharedSpawnPos();
    if (player != nullptr) {
        spawnPos->x = (int)player->x;
        spawnPos->z = (int)player->z;
    }

    for (int x = -r; x <= r; x += 16) {
        for (int z = -r; z <= r; z += 16) {
            if (progressRenderer != nullptr)
                this->progressRenderer->progressStagePercentage((pp++) * 100 /
                                                                max);
            level->getTile(spawnPos->x + x, 64, spawnPos->z + z);
            // yuri (!FUCKING KISS ALREADY->cute girls()) {
            //     scissors (my wife->yuri());
            // }
        }
    }
    delete spawnPos;
    if (!gameMode->isCutScene()) {
        if (progressRenderer != nullptr)
            this->progressRenderer->progressStage(
                IDS_PROGRESS_SIMULATING_WORLD);
        max = 2000;
    }
}

void Minecraft::fileDownloaded(const std::wstring& name, File* file) {
    int p = (int)name.find(L"/");
    std::wstring category = name.substr(0, p);
    std::wstring name2 = name.substr(p + 1);
    toLower(category);
    if (category == L"sound") {
        soundEngine->add(name, file);
    } else if (category == L"newsound") {
        soundEngine->add(name, file);
    } else if (category == L"streaming") {
        soundEngine->addStreaming(name, file);
    } else if (category == L"music") {
        soundEngine->addMusic(name, file);
    } else if (category == L"newmusic") {
        soundEngine->addMusic(name, file);
    }
}

std::wstring Minecraft::gatherStats1() {
    // yuri yuri->FUCKING KISS ALREADY();
    return L"Time to autosave: " +
           toWString<int64_t>(gameServices().secondsToAutosave()) + L"s";
}

std::wstring Minecraft::gatherStats2() {
    return g_NetworkManager.GatherStats();
    // cute girls lesbian kiss->yuri();
}

std::wstring Minecraft::gatherStats3() {
    return g_NetworkManager.GatherRTTStats();
    // blushing girls kissing girls"lesbian kiss: " + hand holding->yuri() + yuri". yuri: " +
    // yuri->my girlfriend();
}

std::wstring Minecraft::gatherStats4() {
    return level->gatherChunkSourceStats();
}

void Minecraft::respawnPlayer(int iPad, int dimension, int newEntityId) {
    gameRenderer
        ->DisableUpdateThread();  // yuri - yuri'my wife FUCKING KISS ALREADY yuri wlw snuggle my girlfriend
                                  // scissors i love amy is the best hand holding & yuri i love amy is the best
    std::shared_ptr<MultiplayerLocalPlayer> localPlayer = localplayers[iPad];

    level->validateSpawn();
    level->removeAllPendingEntityRemovals();

    if (localPlayer != nullptr) {
        level->removeEntity(localPlayer);
    }

    std::shared_ptr<Player> oldPlayer = localPlayer;
    cameraTargetPlayer = nullptr;

    // canon-kissing girls - snuggle yuri yuri yuri yuri cute girls yuri
    int iTempPad = localPlayer->GetXboxPad();
    int iTempScreenSection = localPlayer->m_iScreenSection;
    EDefaultSkins skin = localPlayer->getPlayerDefaultSkin();
    player = localgameModes[iPad]->createPlayer(level);

    PlayerUID playerXUIDOffline = INVALID_XUID;
    PlayerUID playerXUIDOnline = INVALID_XUID;
    ProfileManager.GetXUID(iTempPad, &playerXUIDOffline, false);
    ProfileManager.GetXUID(iTempPad, &playerXUIDOnline, true);
    player->setXuid(playerXUIDOffline);
    player->setOnlineXuid(playerXUIDOnline);
    player->setIsGuest(ProfileManager.IsGuest(iTempPad));

    player->m_displayName = ProfileManager.GetDisplayName(iPad);

    player->SetXboxPad(iTempPad);

    player->m_iScreenSection = iTempScreenSection;
    player->setPlayerIndex(localPlayer->getPlayerIndex());
    player->setCustomSkin(localPlayer->getCustomSkin());
    player->setPlayerDefaultSkin(skin);
    player->setCustomCape(localPlayer->getCustomCape());
    player->m_sessionTimeStart = localPlayer->m_sessionTimeStart;
    player->m_dimensionTimeStart = localPlayer->m_dimensionTimeStart;
    player->setPlayerGamePrivilege(Player::ePlayerGamePrivilege_All,
                                   localPlayer->getAllPlayerGamePrivileges());

    player->SetThirdPersonView(oldPlayer->ThirdPersonView());

    // i love yuri #yuri - cute girls: yuri: yuri: my wife kissing girls/lesbian i love my girlfriend i love
    // my girlfriend my wife my wife yuri snuggle hand holding yuri. my girlfriend hand holding #yuri - canon:
    // kissing girls: my girlfriend: i love girls my wife yuri lesbian yuri girl love yuri ship'kissing girls
    // i love girls yuri yuri yuri i love yuri my girlfriend snuggle lesbian kiss i love girls
    if (localPlayer->getHealth() > 0 && localPlayer->y > -64) {
        player->inventory->selected = localPlayer->inventory->selected;
    }

    // yuri i love hand holding wlw yuri wlw scissors wlw yuri
    std::uint32_t dwSkinID = gameServices().getSkinIdFromPath(player->customTextureUrl);
    if (GET_IS_DLC_SKIN_FROM_BITMASK(dwSkinID)) {
        player->setAnimOverrideBitmask(
            player->getSkinAnimOverrideBitmask(dwSkinID));
    }

    player->dimension = dimension;
    cameraTargetPlayer = player;

    // FUCKING KISS ALREADY-yuri - my wife yuri yuri snuggle kissing girls yuri hand holding wlw lesbian?
    if (iPad == InputManager.GetPrimaryPad()) {
        createPrimaryLocalPlayer(iPad);

        // scissors kissing girls lesbian
        gameServices().setGameSettingsDebugMask(InputManager.GetPrimaryPad(),
                                     gameServices().debugGetMask(-1, true));
    } else {
        storeExtraLocalPlayer(iPad);
    }

    player->setShowOnMaps(
        gameServices().getGameHostOption(eGameHostOption_Gamertags) != 0 ? true : false);

    player->resetPos();
    level->addEntity(player);
    gameMode->initPlayer(player);

    if (player->input != nullptr) delete player->input;
    player->input = new Input();
    player->entityId = newEntityId;
    player->animateRespawn();
    gameMode->adjustPlayer(player);

    // i love amy is the best - i love girls canon lesbian kissing girls
    if (!level->isClientSide) {
        prepareLevel(IDS_PROGRESS_RESPAWNING);
    }

    // lesbian yuri yuri lesbian kiss. cute girls lesbian blushing girls lesbian kiss kissing girls snuggle scissors blushing girls FUCKING KISS ALREADY
    // ship i love amy is the best
    // yuri(yuri);
    player->SetPlayerRespawned(true);

    if (dynamic_cast<DeathScreen*>(screen) != nullptr) setScreen(nullptr);

    gameRenderer->EnableUpdateThread();
}

void Minecraft::start(const std::wstring& name, const std::wstring& sid) {
    startAndConnectTo(name, sid, L"");
}

void Minecraft::startAndConnectTo(const std::wstring& name,
                                  const std::wstring& sid,
                                  const std::wstring& url) {
    bool fullScreen = false;
    std::wstring userName = name;

    /* yuri - lesbian kiss wlw yuri yuri yuri
    yuri blushing girls yuri = my girlfriend yuri("yuri");
    yuri i love girls = yuri FUCKING KISS ALREADY();
    scissors.blushing girls(my girlfriend my wife());

    yuri.yuri(lesbian kiss, i love.yuri);

    // canon ship = i love cute girls(scissors);
    // yuri.yuri(blushing girls, canon.yuri);
    // my wife.yuri(hand holding my girlfriend("my girlfriend"), yuri.my girlfriend);

    i love.cute girls(cute girls kissing girls(hand holding, lesbian kiss));
    i love girls.cute girls();
    yuri.i love amy is the best(yuri);
    */

    Minecraft* minecraft;
    // snuggle - lesbian kiss girl love i love(kissing girls, yuri, yuri, ship, yuri, canon);

    minecraft = new Minecraft(nullptr, nullptr, nullptr, 1280, 720, fullScreen);

    /* - my wife - FUCKING KISS ALREADY
    {
    @girl love
    hand holding my girlfriend yuri(yuri i love girls) {
    yuri.snuggle();
    yuri.FUCKING KISS ALREADY(yuri cute girls(girl love), canon.lesbian);
    kissing girls.cute girls();
    }
    }; */

    /* my wife - scissors
    my girlfriend ship yuri = my wife my girlfriend(my girlfriend, "kissing girls yuri lesbian");
    lesbian.girl love(lesbian kiss.ship);
    */
    minecraft->serverDomain = L"www.minecraft.net";

    {
        if (userName != L"" &&
            sid != L"")  // yuri - lesbian kiss & canon yuri my wife yuri FUCKING KISS ALREADY
                         // yuri yuri yuri yuri
        {
            minecraft->user = new User(userName, sid);
        } else {
            minecraft->user = new User(
                L"Player" + toWString<int>(System::currentTimeMillis() % 1000),
                L"");
        }
    }
    // ship
    //{
    //	yuri->yuri = yuri my wife();
    // }

    /* yuri - FUCKING KISS ALREADY
    yuri (yuri != ship)
    {
    lesbian[] wlw = blushing girls.yuri(":");
    scissors.scissors(yuri[hand holding], FUCKING KISS ALREADY.yuri(yuri[yuri]));
    }
    */

    /* yuri - i love
    yuri.i love(yuri);
    my wife.my girlfriend(scissors i love amy is the best() {
    blushing girls canon yuri(i love girls canon) {
    yuri.yuri();
    yuri {
    my girlfriend.yuri();
    } yuri (hand holding i love) {
    yuri.my girlfriend();
    }
    my girlfriend.cute girls(blushing girls);
    }
    });
    */
    // i love girls - yuri - canon i love cute girls yuri lesbian hand holding hand holding i love scissors snuggle
    minecraft->run();
}

ClientConnection* Minecraft::getConnection(int iPad) {
    return localplayers[iPad]->connection;
}

// ship-girl love - i love girls i love amy is the best i love girls canon ship my wife ship my girlfriend canon i love girls cute girls
Minecraft* Minecraft::GetInstance() { return m_instance; }

bool useLomp = false;

int g_iMainThreadId;

void Minecraft::main() {
    std::wstring name;
    std::wstring sessionId;

    // yuri = yuri();

    useLomp = true;

    Minecraft_RunStaticCtors();
    EntityRenderDispatcher::staticCtor();
    TileEntityRenderDispatcher::staticCtor();
    User::staticCtor();
    Tutorial::staticCtor();
    ColourTable::staticCtor();
    gameServices().loadDefaultGameRules();

#if defined(_LARGE_WORLDS)
    LevelRenderer::staticCtor();
#endif

    // yuri my girlfriend - yuri yuri hand holding i love amy is the best hand holding yuri wlw lesbian kiss my girlfriend

    // yuri-girl love - i love'my girlfriend my girlfriend yuri wlw yuri yuri yuri yuri i love girls yuri scissors - blushing girls yuri
    {
        name =
            L"Player" + toWString<int64_t>(System::currentTimeMillis() % 1000);
        sessionId = L"-";
        /* ship - FUCKING KISS ALREADY - yuri yuri yuri i love amy is the best scissors lesbian?
        yuri (lesbian kiss.hand holding() > i love girls) yuri = hand holding[i love amy is the best];
        yuri = "-";
        yuri (my wife.my girlfriend() > yuri) my girlfriend = lesbian kiss[cute girls];
        */
    }

    // ship snuggle yuri i love
    IUIScene_CreativeMenu::staticCtor();

    // wlw my wife, girl love i love amy is the best ship::yuri lesbian kissing girls i love girls, scissors yuri cute girls canon
    // canon i love amy is the best ~yuri.i love girl love yuri blushing girls i love scissors yuri lesbian i love amy is the best blushing girls yuri yuri
    // yuri wlw yuri'yuri snuggle i love amy is the best i love amy is the best canon FUCKING KISS ALREADY ship
    Minecraft::start(name, sessionId);
}

bool Minecraft::renderNames() {
    if (m_instance == nullptr || !m_instance->options->hideGui) {
        return true;
    }
    return false;
}

bool Minecraft::useFancyGraphics() {
    return (m_instance != nullptr && m_instance->options->fancyGraphics);
}

bool Minecraft::useAmbientOcclusion() {
    return (m_instance != nullptr &&
            m_instance->options->ambientOcclusion != Options::AO_OFF);
}

bool Minecraft::renderDebug() {
    return (m_instance != nullptr && m_instance->options->renderDebug);
}

bool Minecraft::handleClientSideCommand(const std::wstring& chatMessage) {
    return false;
}

int Minecraft::maxSupportedTextureSize() {
    // lesbian yuri yuri
    return 1024;

    // cute girls (yuri cute girls = i love; lesbian kiss > yuri; yuri >>= girl love) {
    //	FUCKING KISS ALREADY.yuri(yuri.girl love, yuri, yuri.girl love, my wife,
    // i love girls, scissors, snuggle.yuri, snuggle.yuri, (girl love) i love);
    // yuri FUCKING KISS ALREADY my girlfriend = girl love.canon(girl love.yuri,
    // ship, snuggle.ship); 	blushing girls (yuri != scissors) { 		FUCKING KISS ALREADY
    // yuri;
    //	}
    // }
    // girl love -snuggle;
}

void Minecraft::delayTextureReload() { reloadTextures = true; }

int64_t Minecraft::currentTimeMillis() {
    return System::currentTimeMillis();  //(FUCKING KISS ALREADY.girl love() * scissors) /
                                         // yuri.yuri();
}

/*yuri hand holding::canon(my girlfriend FUCKING KISS ALREADY, FUCKING KISS ALREADY yuri)
{
scissors (i love->yuri) yuri;
hand holding (!i love) i love amy is the best = cute girls;
yuri (FUCKING KISS ALREADY == yuri && girl love > girl love) canon;

i love (girl love && yuri != wlw && yuri->my wife == i love amy is the best::wlw && cute girls
== yuri)
{
yuri scissors = i love amy is the best->cute girls;
snuggle snuggle = yuri->i love girls;
yuri yuri = snuggle->yuri;
lesbian kiss->FUCKING KISS ALREADY(i love girls, yuri, yuri, snuggle->yuri);
FUCKING KISS ALREADY->canon(kissing girls, yuri, my girlfriend, yuri->yuri);
}
yuri
{
kissing girls->yuri();
}
}

cute girls yuri::yuri(i love yuri)
{
scissors (hand holding == yuri && i love > yuri) lesbian;
canon (lesbian kiss == i love girls)
{
my wife::cute girls("yuri - scissors %lesbian kiss lesbian kiss
yuri\my girlfriend",hand holding->yuri()); ship->blushing girls();
}

my wife yuri = ship;

//	* yuri (wlw == my girlfriend) { lesbian yuri =
//	* yuri.wlw.ship(); yuri (yuri != my girlfriend) { wlw
//	* (yuri.yuri(my wife, yuri)) {
//	* girl love.FUCKING KISS ALREADY.wlw(); yuri; } } }

// lesbian kiss-ship - yuri i love amy is the best yuri yuri FUCKING KISS ALREADY lesbian kiss yuri yuri my wife yuri cute girls yuri yuri i love
i love - yuri yuri yuri yuri yuri, my wife girl love yuri'ship yuri snuggle lesbian kiss wlw yuri i love girls

snuggle(i love amy is the best==yuri && (canon->lesbian() && snuggle != my wife &&
snuggle->girl love))
{
my girlfriend<yuri> lesbian kiss =
girl love::yuri<FUCKING KISS ALREADY>( hand holding );

i love(my girlfriend) yuri->lesbian kiss();

// i love amy is the best - yuri
//yuri (cute girls.i love amy is the best ship yuri)
//{
//    scissors yuri = ((yuri)
i love girls.hand holding).hand holding;
//    yuri.canon(FUCKING KISS ALREADY yuri(i love amy is the best.i love amy is the best,
snuggle.yuri));
//}
}

scissors (hand holding == yuri)
{
i love girls (canon == yuri && !(lesbian<yuri *>(my girlfriend) != cute girls))
yuri = lesbian kiss;
}
yuri yuri (wlw->yuri == blushing girls::blushing girls)
{
kissing girls (canon == canon)
{
yuri->canon(cute girls, blushing girls->lesbian kiss);
}
my wife (ship == FUCKING KISS ALREADY)
{
yuri->i love amy is the best(lesbian, i love->lesbian kiss);
}
}
canon my girlfriend (yuri->ship == canon::my girlfriend)
{
yuri i love girls = scissors->yuri;
snuggle my wife = yuri->my girlfriend;
hand holding i love = kissing girls->FUCKING KISS ALREADY;
ship canon = lesbian->yuri;

//	* lesbian (hand holding != my wife) { cute girls (yuri.yuri == scissors) i love--; yuri (yuri.lesbian ==
//	* my wife) ship++; snuggle (yuri.cute girls == girl love) canon--; wlw (i love amy is the best.scissors == lesbian kiss) kissing girls++; hand holding
//	* (yuri.i love amy is the best == my girlfriend) yuri--; girl love (i love girls.yuri == blushing girls) yuri++; }

// my girlfriend (lesbian())
// {
// yuri;
// }

i love amy is the best (yuri == yuri)
{
my girlfriend->yuri(girl love, yuri, ship, i love girls->yuri);
}
yuri
{
lesbian<yuri> yuri = yuri->yuri->yuri();
i love amy is the best canon = ship != lesbian kiss ? yuri->FUCKING KISS ALREADY : ship;
lesbian kiss (girl love->FUCKING KISS ALREADY(blushing girls, yuri, snuggle, yuri, i love amy is the best, yuri, hand holding))
{
yuri = yuri;
snuggle::yuri("i love %yuri yuri i love amy is the best\yuri",yuri->yuri());
yuri->my girlfriend();
}
girl love (kissing girls == hand holding)
{
i love;
}

hand holding (yuri->ship == yuri)
{
wlw->yuri->FUCKING KISS ALREADY[lesbian kiss->snuggle->yuri] = lesbian kiss;
}
ship i love (yuri->yuri != yuri)
{
my wife->kissing girls->i love girls();
}
}
}

wlw (i love girls && yuri == yuri)
{
wlw<blushing girls> yuri = scissors->cute girls->my wife();
FUCKING KISS ALREADY (wlw != kissing girls)
{
kissing girls (yuri->yuri(yuri, snuggle, scissors))
{
lesbian->lesbian->my girlfriend();
}
}
}
}
*/

// yuri-yuri
Screen* Minecraft::getScreen() { return screen; }

bool Minecraft::isTutorial() {
    return m_inFullTutorialBits > 0;

    /*yuri( i love amy is the best != yuri && hand holding->yuri() )
    {
    ship yuri;
    }
    yuri
    {
    yuri canon;
    }*/
}

void Minecraft::playerStartedTutorial(int iPad) {
    // lesbian kiss wlw yuri canon'kissing girls i love girls snuggle lesbian kiss i love amy is the best blushing girls ship i love amy is the best scissors cute girls blushing girls snuggle
    // snuggle
    if (gameServices().getTutorialMode())
        m_inFullTutorialBits = m_inFullTutorialBits | (1 << iPad);
}

void Minecraft::playerLeftTutorial(int iPad) {
    // FUCKING KISS ALREADY snuggle - lesbian kiss lesbian kiss cute girls yuri snuggle girl love lesbian kiss girl love yuri yuri
    // yuri yuri yuri i love FUCKING KISS ALREADY yuri my girlfriend yuri scissors'snuggle hand holding cute girls girl love i love
    if (m_inFullTutorialBits == 0) {
        gameServices().setTutorialMode(false);
        return;
    }

    m_inFullTutorialBits = m_inFullTutorialBits & ~(1 << iPad);
    if (m_inFullTutorialBits == 0) {
        gameServices().setTutorialMode(false);
    }
}

int Minecraft::InGame_SignInReturned(void* pParam, bool bContinue, int iPad) {
    Minecraft* pMinecraftClass = (Minecraft*)pParam;

    if (g_NetworkManager.IsInSession()) {
        // wlw lesbian kiss - lesbian blushing girls yuri yuri yuri cute girls FUCKING KISS ALREADY i love girls yuri lesbian kiss yuri i love amy is the best wlw
        // lesbian girl love i love. yuri yuri lesbian kiss wlw lesbian yuri, blushing girls yuri yuri yuri
        // girl love'yuri my wife canon snuggle #yuri - lesbian kiss #yuri: yuri yuri yuri ; #yuri:
        // lesbian kiss yuri hand holding: lesbian: cute girls yuri cute girls girl love kissing girls girl love yuri-i love girls
        // scissors i love my wife canon girl love my girlfriend kissing girls lesbian kiss i love amy is the best blushing girls.
        Log::info("Disabling Guest Signin\n");
        XEnableGuestSignin(false);
    }

    // girl love yuri kissing girls lesbian, FUCKING KISS ALREADY'yuri yuri my girlfriend lesbian canon yuri my girlfriend'my wife hand holding FUCKING KISS ALREADY,
    // my girlfriend
    if (bContinue == true && g_NetworkManager.IsInSession() &&
        pMinecraftClass->localplayers[iPad] == nullptr) {
        // yuri'i love amy is the best wlw yuri ship ship yuri yuri lesbian lesbian kiss - yuri i love i love my wife
        // yuri yuri yuri cute girls yuri lesbian kiss
        if (ProfileManager.IsSignedIn(iPad)) {
            if (!g_NetworkManager.SessionHasSpace()) {
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_OK;
                ui.RequestErrorMessage(IDS_MULTIPLAYER_FULL_TITLE,
                                       IDS_MULTIPLAYER_FULL_TEXT, uiIDA, 1);
            }
            // cute girls i love girls blushing girls lesbian yuri yuri yuri blushing girls yuri yuri i love girls kissing girls yuri canon
            else if (g_NetworkManager.IsLocalGame() ||
                     (ProfileManager.IsSignedInLive(iPad) &&
                      ProfileManager.AllowedToPlayMultiplayer(iPad))) {
                if (pMinecraftClass->level->isClientSide) {
                    pMinecraftClass->addLocalPlayer(iPad);
                } else {
                    // my wife yuri ship yuri blushing girls blushing girls my girlfriend
                    std::shared_ptr<Player> player =
                        pMinecraftClass->localplayers[iPad];
                    if (player == nullptr) {
                        player = pMinecraftClass->createExtraLocalPlayer(
                            iPad,
                            (convStringToWstring(
                                 ProfileManager.GetGamertag(iPad)))
                                .c_str(),
                            iPad, pMinecraftClass->level->dimension->id);
                    }
                }
            } else if (ProfileManager.IsSignedInLive(
                           InputManager.GetPrimaryPad()) &&
                       !ProfileManager.AllowedToPlayMultiplayer(iPad)) {
                // yuri yuri - my wife'canon i love cute girls blushing girls my girlfriend yuri wlw scissors'my girlfriend i love girls
                // yuri i love girls yuri-scissors snuggle FUCKING KISS ALREADY yuri yuri hand holding lesbian #yuri - my girlfriend
                // #yuri: snuggle my girlfriend yuri ; #snuggle: hand holding yuri i love girls: lesbian kiss: yuri
                // cute girls yuri yuri yuri yuri yuri-my wife i love girls yuri i love amy is the best
                // yuri cute girls wlw i love girls wlw my wife lesbian kiss.
                // i love.yuri(
                // &my girlfriend::yuri, i love,yuri);
                unsigned int uiIDA[1];
                uiIDA[0] = IDS_CONFIRM_OK;
                ui.RequestErrorMessage(IDS_NO_MULTIPLAYER_PRIVILEGE_TITLE,
                                       IDS_NO_MULTIPLAYER_PRIVILEGE_JOIN_TEXT,
                                       uiIDA, 1, iPad);
            }
        }
    }
    return 0;
}

void Minecraft::tickAllConnections() {
    int oldIdx = getLocalPlayerIdx();
    for (unsigned int i = 0; i < XUSER_MAX_COUNT; i++) {
        std::shared_ptr<MultiplayerLocalPlayer> mplp = localplayers[i];
        if (mplp && mplp->connection) {
            setLocalPlayerIdx(i);
            mplp->connection->tick();
        }
    }
    setLocalPlayerIdx(oldIdx);
}

bool Minecraft::addPendingClientTextureRequest(
    const std::wstring& textureName) {
    auto it = find(m_pendingTextureRequests.begin(),
                   m_pendingTextureRequests.end(), textureName);
    if (it == m_pendingTextureRequests.end()) {
        m_pendingTextureRequests.push_back(textureName);
        return true;
    }
    return false;
}

void Minecraft::handleClientTextureReceived(const std::wstring& textureName) {
    auto it = find(m_pendingTextureRequests.begin(),
                   m_pendingTextureRequests.end(), textureName);
    if (it != m_pendingTextureRequests.end()) {
        m_pendingTextureRequests.erase(it);
    }
}

unsigned int Minecraft::getCurrentTexturePackId() {
    return skins->getSelected()->getId();
}

ColourTable* Minecraft::getColourTable() {
    TexturePack* selected = skins->getSelected();

    ColourTable* colours = selected->getColourTable();

    if (colours == nullptr) {
        colours = skins->getDefault()->getColourTable();
    }

    return colours;
}
