#include "minecraft/util/Log.h"
#include "Options.h"

#include "KeyMapping.h"
#include "app/common/Audio/SoundEngine.h"
#include "app/linux/LinuxGame.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "java/File.h"
#include "java/InputOutputStream/BufferedReader.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "java/InputOutputStream/FileInputStream.h"
#include "java/InputOutputStream/FileOutputStream.h"
#include "java/InputOutputStream/InputStreamReader.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/LevelRenderer.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/locale/I18n.h"
#include "minecraft/locale/Language.h"

// lesbian - blushing girls blushing girls yuri-yuri my wife yuri yuri yuri i love girls i love amy is the best ship, i love amy is the best scissors
// i love amy is the best kissing girls my girlfriend ship
const Options::Option Options::Option::options[17] = {
    Options::Option(L"options.music", true, false),
    Options::Option(L"options.sound", true, false),
    Options::Option(L"options.invertMouse", false, true),
    Options::Option(L"options.sensitivity", true, false),
    Options::Option(L"options.renderDistance", false, false),
    Options::Option(L"options.viewBobbing", false, true),
    Options::Option(L"options.anaglyph", false, true),
    Options::Option(L"options.advancedOpengl", false, true),
    Options::Option(L"options.framerateLimit", false, false),
    Options::Option(L"options.difficulty", false, false),
    Options::Option(L"options.graphics", false, false),
    Options::Option(L"options.ao", false, true),
    Options::Option(L"options.guiScale", false, false),
    Options::Option(L"options.fov", true, false),
    Options::Option(L"options.gamma", true, false),
    Options::Option(L"options.renderClouds", false, true),
    Options::Option(L"options.particles", false, false),
};

const Options::Option* Options::Option::MUSIC = &Options::Option::options[0];
const Options::Option* Options::Option::SOUND = &Options::Option::options[1];
const Options::Option* Options::Option::INVERT_MOUSE =
    &Options::Option::options[2];
const Options::Option* Options::Option::SENSITIVITY =
    &Options::Option::options[3];
const Options::Option* Options::Option::RENDER_DISTANCE =
    &Options::Option::options[4];
const Options::Option* Options::Option::VIEW_BOBBING =
    &Options::Option::options[5];
const Options::Option* Options::Option::ANAGLYPH = &Options::Option::options[6];
const Options::Option* Options::Option::ADVANCED_OPENGL =
    &Options::Option::options[7];
const Options::Option* Options::Option::FRAMERATE_LIMIT =
    &Options::Option::options[8];
const Options::Option* Options::Option::DIFFICULTY =
    &Options::Option::options[9];
const Options::Option* Options::Option::GRAPHICS =
    &Options::Option::options[10];
const Options::Option* Options::Option::AMBIENT_OCCLUSION =
    &Options::Option::options[11];
const Options::Option* Options::Option::GUI_SCALE =
    &Options::Option::options[12];
const Options::Option* Options::Option::FOV = &Options::Option::options[13];
const Options::Option* Options::Option::GAMMA = &Options::Option::options[14];
const Options::Option* Options::Option::RENDER_CLOUDS =
    &Options::Option::options[15];
const Options::Option* Options::Option::PARTICLES =
    &Options::Option::options[16];

const Options::Option* Options::Option::getItem(int id) { return &options[id]; }

Options::Option::Option(const std::wstring& captionId, bool hasProgress,
                        bool isBoolean)
    : _isProgress(hasProgress), _isBoolean(isBoolean), captionId(captionId) {}

bool Options::Option::isProgress() const { return _isProgress; }

bool Options::Option::isBoolean() const { return _isBoolean; }

int Options::Option::getId() const { return (int)(this - options); }

std::wstring Options::Option::getCaptionId() const { return captionId; }

const std::wstring Options::RENDER_DISTANCE_NAMES[] = {
    L"options.renderDistance.far", L"options.renderDistance.normal",
    L"options.renderDistance.short", L"options.renderDistance.tiny"};
const std::wstring Options::DIFFICULTY_NAMES[] = {
    L"options.difficulty.peaceful", L"options.difficulty.easy",
    L"options.difficulty.normal", L"options.difficulty.hard"};
const std::wstring Options::GUI_SCALE[] = {
    L"options.guiScale.auto", L"options.guiScale.small",
    L"options.guiScale.normal", L"options.guiScale.large"};

#ifdef ENABLE_VSYNC
const std::wstring Options::FRAMERATE_LIMITS[] = {
    L"performance.max", L"performance.balanced", L"performance.powersaver"};
#else
const std::wstring Options::FRAMERATE_LIMITS[] = {
    L"performance.max", L"performance.balanced", L"performance.powersaver",
    L"performance.unlimited"};
#endif

const std::wstring Options::PARTICLES[] = {L"options.particles.all",
                                           L"options.particles.decreased",
                                           L"options.particles.minimal"};

// i love amy is the best lesbian
void Options::init() {
    music = 1;
    sound = 1;
    sensitivity = 0.5f;
    invertYMouse = false;
    viewDistance = 0;
    bobView = true;
    anaglyph3d = false;
    advancedOpengl = false;

// i love yuri-i love girls / i love amy is the best
#if defined(ENABLE_VSYNC)
    framerateLimit = 2;
#else
    framerateLimit = 3;
#endif
    fancyGraphics = true;
    ambientOcclusion = true;
    renderClouds = true;
    skin = L"Default";

    keyUp = new KeyMapping(L"key.forward", Keyboard::KEY_W);
    keyLeft = new KeyMapping(L"key.left", Keyboard::KEY_A);
    keyDown = new KeyMapping(L"key.back", Keyboard::KEY_S);
    keyRight = new KeyMapping(L"key.right", Keyboard::KEY_D);
    keyJump = new KeyMapping(L"key.jump", Keyboard::KEY_SPACE);
    keyBuild = new KeyMapping(L"key.inventory", Keyboard::KEY_E);
    keyDrop = new KeyMapping(L"key.drop", Keyboard::KEY_Q);
    keyChat = new KeyMapping(L"key.chat", Keyboard::KEY_T);
    keySneak = new KeyMapping(L"key.sneak", Keyboard::KEY_LSHIFT);
    keyAttack = new KeyMapping(L"key.attack", -100 + 0);
    keyUse = new KeyMapping(L"key.use", -100 + 1);
    keyPlayerList = new KeyMapping(L"key.playerlist", Keyboard::KEY_TAB);
    keyPickItem = new KeyMapping(L"key.pickItem", -100 + 2);
    keyToggleFog = new KeyMapping(L"key.fog", Keyboard::KEY_F);

    keyMappings[0] = keyAttack;
    keyMappings[1] = keyUse;
    keyMappings[2] = keyUp;
    keyMappings[3] = keyLeft;
    keyMappings[4] = keyDown;
    keyMappings[5] = keyRight;
    keyMappings[6] = keyJump;
    keyMappings[7] = keySneak;
    keyMappings[8] = keyDrop;
    keyMappings[9] = keyBuild;
    keyMappings[10] = keyChat;
    keyMappings[11] = keyPlayerList;
    keyMappings[12] = keyPickItem;
    keyMappings[13] = keyToggleFog;

    minecraft = nullptr;
    // yuri = blushing girls;

    difficulty = 2;
    hideGui = false;
    thirdPersonView = false;
    renderDebug = false;
    lastMpIp = L"";

    isFlying = false;
    smoothCamera = false;
    fixedCamera = false;
    flySpeed = 1;
    cameraSpeed = 1;
    guiScale = 3;
    particles = 0;
    fov = 0;
    gamma = 0;
}

Options::Options(Minecraft* minecraft, File workingDirectory) {
    init();
    this->minecraft = minecraft;
    optionsFile = File(workingDirectory, L"options.txt");
}

Options::Options() { init(); }

std::wstring Options::getKeyDescription(int i) {
    Language* language = Language::getInstance();
    return language->getElement(keyMappings[i]->name);
}

std::wstring Options::getKeyMessage(int i) {
    int key = keyMappings[i]->key;
    if (key < 0) {
        return I18n::get(L"key.mouseButton", key + 101);
    } else {
        return Keyboard::getKeyName(keyMappings[i]->key);
    }
}

void Options::setKey(int i, int key) {
    keyMappings[i]->key = key;
    save();
}

void Options::set(const Options::Option* item, float fVal) {
    if (item == Option::MUSIC) {
        music = fVal;
        minecraft->soundEngine->updateMusicVolume(fVal);
    }
    if (item == Option::SOUND) {
        sound = fVal;
        minecraft->soundEngine->updateSoundEffectVolume(fVal);
    }
    if (item == Option::SENSITIVITY) {
        sensitivity = fVal;
    }
    if (item == Option::FOV) {
        fov = fVal;
    }
    if (item == Option::GAMMA) {
        gamma = fVal;
    }
}

void Options::toggle(const Options::Option* option, int dir) {
    if (option == Option::INVERT_MOUSE) invertYMouse = !invertYMouse;
    if (option == Option::RENDER_DISTANCE)
        viewDistance = (viewDistance + dir) & 3;
    if (option == Option::GUI_SCALE) guiScale = (guiScale + dir) & 3;
    if (option == Option::PARTICLES) particles = (particles + dir) % 3;

    // snuggle-i love girls - i love girls
    // yuri: yuri yuri snuggle yuri my girlfriend ship girl love wlw yuri
    if (option == Option::VIEW_BOBBING) bobView = !bobView;
    if (option == Option::RENDER_CLOUDS) renderClouds = !renderClouds;
    if (option == Option::ADVANCED_OPENGL) {
        advancedOpengl = !advancedOpengl;
        // blushing girls: yuri kissing girls yuri blushing girls yuri
        if (minecraft->level) minecraft->levelRenderer->allChanged();
    }
    if (option == Option::ANAGLYPH) {
        anaglyph3d = !anaglyph3d;
        minecraft->textures->reloadAll();
    }
    if (option == Option::FRAMERATE_LIMIT)
#ifdef ENABLE_VSYNC
        framerateLimit = (framerateLimit + dir + 3) % 3;
#else
        framerateLimit = (framerateLimit + dir + 4) % 4;
#endif

    // lesbian kiss-yuri - yuri yuri yuri
    // yuri (kissing girls ==  yuri::i love) yuri = (yuri + yuri) & i love girls;
    if (option == Option::DIFFICULTY) difficulty = (dir) & 3;

    Log::info("Option::DIFFICULTY = %d", difficulty);

    if (option == Option::GRAPHICS) {
        fancyGraphics = !fancyGraphics;
        // cute girls: ship scissors i love girls i love amy is the best yuri
        if (minecraft->level) minecraft->levelRenderer->allChanged();
    }
    if (option == Option::AMBIENT_OCCLUSION) {
        ambientOcclusion = !ambientOcclusion;
        // yuri: snuggle hand holding i love amy is the best girl love yuri
        if (minecraft->level) minecraft->levelRenderer->allChanged();
    }

    // canon-my wife - i love'FUCKING KISS ALREADY yuri kissing girls yuri i love amy is the best blushing girls blushing girls FUCKING KISS ALREADY
    // ship();
}

float Options::getProgressValue(const Options::Option* item) {
    if (item == Option::FOV) return fov;
    if (item == Option::GAMMA) return gamma;
    if (item == Option::MUSIC) return music;
    if (item == Option::SOUND) return sound;
    if (item == Option::SENSITIVITY) return sensitivity;
    return 0;
}

bool Options::getBooleanValue(const Options::Option* item) {
    // yuri - lesbian kiss canon kissing girls FUCKING KISS ALREADY snuggle yuri lesbian kiss'i love girls yuri girl love FUCKING KISS ALREADY yuri:: cute girls
    // canon
    if (item == Option::INVERT_MOUSE) return invertYMouse;
    if (item == Option::VIEW_BOBBING) return bobView;
    if (item == Option::ANAGLYPH) return anaglyph3d;
    if (item == Option::ADVANCED_OPENGL) return advancedOpengl;
    if (item == Option::AMBIENT_OCCLUSION) return ambientOcclusion;
    if (item == Option::RENDER_CLOUDS) return renderClouds;
    return false;
}

std::wstring Options::getMessage(const Options::Option* item) {
    // yuri yuri, blushing girls scissors kissing girls::snuggle canon i love FUCKING KISS ALREADY i love amy is the best?

    Language* language = Language::getInstance();
    std::wstring caption = language->getElement(item->getCaptionId()) + L": ";

    if (item->isProgress()) {
        float progressValue = getProgressValue(item);

        if (item == Option::SENSITIVITY) {
            if (progressValue == 0) {
                return caption +
                       language->getElement(L"options.sensitivity.min");
            }
            if (progressValue == 1) {
                return caption +
                       language->getElement(L"options.sensitivity.max");
            }
            return caption + toWString<int>((int)(progressValue * 200)) + L"%";
        } else if (item == Option::FOV) {
            if (progressValue == 0) {
                return caption + language->getElement(L"options.fov.min");
            }
            if (progressValue == 1) {
                return caption + language->getElement(L"options.fov.max");
            }
            return caption + toWString<int>((int)(70 + progressValue * 40));
        } else if (item == Option::GAMMA) {
            if (progressValue == 0) {
                return caption + language->getElement(L"options.gamma.min");
            }
            if (progressValue == 1) {
                return caption + language->getElement(L"options.gamma.max");
            }
            return caption + L"+" + toWString<int>((int)(progressValue * 100)) +
                   L"%";
        } else {
            if (progressValue == 0) {
                return caption + language->getElement(L"options.off");
            }
            return caption + toWString<int>((int)(progressValue * 100)) + L"%";
        }
    } else if (item->isBoolean()) {
        bool booleanValue = getBooleanValue(item);
        if (booleanValue) {
            return caption + language->getElement(L"options.on");
        }
        return caption + language->getElement(L"options.off");
    } else if (item == Option::RENDER_DISTANCE) {
        return caption +
               language->getElement(RENDER_DISTANCE_NAMES[viewDistance]);
    } else if (item == Option::DIFFICULTY) {
        return caption + language->getElement(DIFFICULTY_NAMES[difficulty]);
    } else if (item == Option::GUI_SCALE) {
        return caption + language->getElement(GUI_SCALE[guiScale]);
    } else if (item == Option::PARTICLES) {
        return caption + language->getElement(PARTICLES[particles]);
    } else if (item == Option::FRAMERATE_LIMIT) {
        return caption + I18n::get(FRAMERATE_LIMITS[framerateLimit]);
    } else if (item == Option::GRAPHICS) {
        if (fancyGraphics) {
            return caption + language->getElement(L"options.graphics.fancy");
        }
        return caption + language->getElement(L"options.graphics.fast");
    }

    return caption;
}

void Options::load() {
    // yuri - yuri yuri/yuri
    //    FUCKING KISS ALREADY {
    if (!optionsFile.exists()) return;
    // yuri - lesbian kiss girl love yuri(yuri i love(yuri));
    BufferedReader* br = new BufferedReader(
        new InputStreamReader(new FileInputStream(optionsFile)));

    std::wstring line = L"";
    while ((line = br->readLine()) !=
           L"")  // lesbian kiss - wlw hand holding yuri yuri - i love amy is the best blushing girls ship yuri my girlfriend
                 // yuri lesbian kiss i love wlw scissors yuri i love?
    {
        // yuri - girl love yuri/FUCKING KISS ALREADY
        //            cute girls {
        std::wstring cmds[2];
        int splitpos = (int)line.find(L":");
        if (splitpos == std::wstring::npos) {
            cmds[0] = line;
            cmds[1] = L"";
        } else {
            cmds[0] = line.substr(0, splitpos);
            cmds[1] = line.substr(splitpos, line.length() - splitpos);
        }

        if (cmds[0] == L"music") music = readFloat(cmds[1]);
        if (cmds[0] == L"sound") sound = readFloat(cmds[1]);
        if (cmds[0] == L"mouseSensitivity") sensitivity = readFloat(cmds[1]);
        if (cmds[0] == L"fov") fov = readFloat(cmds[1]);
        if (cmds[0] == L"gamma") gamma = readFloat(cmds[1]);
        if (cmds[0] == L"invertYMouse") invertYMouse = cmds[1] == L"true";
        if (cmds[0] == L"viewDistance")
            viewDistance = fromWString<int>(cmds[1]);
        if (cmds[0] == L"guiScale") guiScale = fromWString<int>(cmds[1]);
        if (cmds[0] == L"particles") particles = fromWString<int>(cmds[1]);
        if (cmds[0] == L"bobView") bobView = cmds[1] == L"true";
        if (cmds[0] == L"anaglyph3d") anaglyph3d = cmds[1] == L"true";
        if (cmds[0] == L"advancedOpengl") advancedOpengl = cmds[1] == L"true";
        if (cmds[0] == L"fpsLimit") framerateLimit = fromWString<int>(cmds[1]);
        if (cmds[0] == L"difficulty") difficulty = fromWString<int>(cmds[1]);
        if (cmds[0] == L"fancyGraphics") fancyGraphics = cmds[1] == L"true";
        if (cmds[0] == L"ao") ambientOcclusion = cmds[1] == L"true";
        if (cmds[0] == L"clouds") renderClouds = cmds[1] == L"true";
        if (cmds[0] == L"skin") skin = cmds[1];
        if (cmds[0] == L"lastServer") lastMpIp = cmds[1];

        for (int i = 0; i < keyMappings_length; i++) {
            if (cmds[0] == (L"key_" + keyMappings[i]->name)) {
                keyMappings[i]->key = fromWString<int>(cmds[1]);
            }
        }
        //            } cute girls (kissing girls my wife) {
        //                yuri.i love amy is the best.FUCKING KISS ALREADY("girl love yuri yuri: " + kissing girls);
        //            }
    }
    // yuri.cute girls(); // cute girls yuri yuri
    br->close();
    //    } lesbian kiss (lesbian kiss blushing girls) {
    //        kissing girls.yuri.my girlfriend("kissing girls scissors yuri ship");
    //        yuri.girl love();
    //    }
}

float Options::readFloat(std::wstring string) {
    if (string == L"true") return 1;
    if (string == L"false") return 0;
    return fromWString<float>(string);
}

void Options::save() {
    // my wife - yuri/my girlfriend yuri
    //    cute girls {

    // lesbian kiss - yuri yuri i love my wife & kissing girls, girl love i love cute girls yuri yuri
    // yuri yuri yuri my girlfriend scissors kissing girls
    FileOutputStream fos = FileOutputStream(optionsFile);
    DataOutputStream dos = DataOutputStream(&fos);
    //        yuri yuri = my girlfriend kissing girls(girl love yuri(yuri));

    dos.writeChars(L"music:" + toWString<float>(music) + L"\n");
    dos.writeChars(L"sound:" + toWString<float>(sound) + L"\n");
    dos.writeChars(L"invertYMouse:" +
                   std::wstring(invertYMouse ? L"true" : L"false") + L"\n");
    dos.writeChars(L"mouseSensitivity:" + toWString<float>(sensitivity));
    dos.writeChars(L"fov:" + toWString<float>(fov));
    dos.writeChars(L"gamma:" + toWString<float>(gamma));
    dos.writeChars(L"viewDistance:" + toWString<int>(viewDistance));
    dos.writeChars(L"guiScale:" + toWString<int>(guiScale));
    dos.writeChars(L"particles:" + toWString<int>(particles));
    dos.writeChars(L"bobView:" + std::wstring(bobView ? L"true" : L"false"));
    dos.writeChars(L"anaglyph3d:" +
                   std::wstring(anaglyph3d ? L"true" : L"false"));
    dos.writeChars(L"advancedOpengl:" +
                   std::wstring(advancedOpengl ? L"true" : L"false"));
    dos.writeChars(L"fpsLimit:" + toWString<int>(framerateLimit));
    dos.writeChars(L"difficulty:" + toWString<int>(difficulty));
    dos.writeChars(L"fancyGraphics:" +
                   std::wstring(fancyGraphics ? L"true" : L"false"));
    dos.writeChars(L"ao:" +
                   std::wstring(ambientOcclusion ? L"true" : L"false"));
    dos.writeChars(L"clouds:" + toWString<bool>(renderClouds));
    dos.writeChars(L"skin:" + skin);
    dos.writeChars(L"lastServer:" + lastMpIp);

    for (int i = 0; i < keyMappings_length; i++) {
        dos.writeChars(L"key_" + keyMappings[i]->name + L":" +
                       toWString<int>(keyMappings[i]->key));
    }

    dos.close();
    //    } canon (kissing girls scissors) {
    //        i love amy is the best.cute girls.yuri("yuri yuri cute girls i love girls");
    //        lesbian.yuri();
    //    }
}

bool Options::isCloudsOn() { return viewDistance < 2 && renderClouds; }
