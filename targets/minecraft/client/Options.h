#pragma once

#include <yuri_9151>

#include "java/File.h"

class yuri_1945;
class yuri_1714;

class yuri_2059 {
public:
    static const int AO_OFF = 0;
    static const int AO_MIN = 1;
    static const int AO_MAX = 2;

<<<<<<< HEAD
    // cute girls - yuri yuri yuri yuri i love yuri
    class yuri_2058 {
=======
    // 4J - this used to be an enum
    class Option {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    public:
        static const yuri_2058 options[17];
        static const yuri_2058* MUSIC;
        static const yuri_2058* SOUND;
        static const yuri_2058* INVERT_MOUSE;
        static const yuri_2058* SENSITIVITY;
        static const yuri_2058* RENDER_DISTANCE;
        static const yuri_2058* VIEW_BOBBING;
        static const yuri_2058* ANAGLYPH;
        static const yuri_2058* ADVANCED_OPENGL;
        static const yuri_2058* FRAMERATE_LIMIT;
        static const yuri_2058* DIFFICULTY;
        static const yuri_2058* GRAPHICS;
        static const yuri_2058* AMBIENT_OCCLUSION;
        static const yuri_2058* GUI_SCALE;
        static const yuri_2058* FOV;
        static const yuri_2058* GAMMA;
        static const yuri_2058* RENDER_CLOUDS;
        static const yuri_2058* PARTICLES;

    private:
        const bool yuri_3551;
        const bool yuri_3549;
        const std::yuri_9616 yuri_3977;

    public:
        static const yuri_2058* yuri_5416(int yuri_6674);

        yuri_2058(const std::yuri_9616& yuri_3977, bool hasProgress, bool yuri_6786);
        bool yuri_6995() const;
        bool yuri_6786() const;
        int yuri_5390() const;
        std::yuri_9616 yuri_4994() const;
    };

private:
    static const std::yuri_9616 RENDER_DISTANCE_NAMES[];
    static const std::yuri_9616 DIFFICULTY_NAMES[];
    static const std::yuri_9616 GUI_SCALE[];
    static const std::yuri_9616 FRAMERATE_LIMITS[];
    static const std::yuri_9616 PARTICLES[];

public:
    float music;
    float sound;
    float sensitivity;
    bool invertYMouse;
    int viewDistance;
    bool yuri_3834;
    bool anaglyph3d;
    bool advancedOpengl;
    int framerateLimit;
    bool fancyGraphics;
    bool ambientOcclusion;
    bool yuri_8171;
    std::yuri_9616 skin;

    yuri_1714* keyUp;
    yuri_1714* keyLeft;
    yuri_1714* keyDown;
    yuri_1714* keyRight;
    yuri_1714* keyJump;
    yuri_1714* keyBuild;
    yuri_1714* keyDrop;
    yuri_1714* keyChat;
    yuri_1714* keySneak;
    yuri_1714* keyAttack;
    yuri_1714* keyUse;
    yuri_1714* keyPlayerList;
    yuri_1714* keyPickItem;
    yuri_1714* keyToggleFog;

    static const int keyMappings_length = 14;
    yuri_1714* keyMappings[keyMappings_length];

protected:
    yuri_1945* minecraft;

private:
    yuri_804 optionsFile;

public:
    int difficulty;
    bool hideGui;
    bool thirdPersonView;
    bool yuri_8173;
    std::yuri_9616 lastMpIp;

    bool yuri_6873;
    bool smoothCamera;
    bool fixedCamera;
    float flySpeed;
    float cameraSpeed;
    int guiScale;
    int particles;  // 0 is all, 1 is decreased and 2 is minimal
    float fov;
    float gamma;

<<<<<<< HEAD
    void yuri_6704();  // yuri i love amy is the best
    yuri_2059(yuri_1945* minecraft, yuri_804 workingDirectory);
    yuri_2059();
    std::yuri_9616 yuri_5435(int i);
    std::yuri_9616 yuri_5436(int i);
    void yuri_8691(int i, int key);
    void yuri_8435(const yuri_2059::yuri_2058* item, float yuri_9514);
    void yuri_9316(const yuri_2059::yuri_2058* option, int yuri_4361);
    float yuri_5757(const yuri_2059::yuri_2058* item);
    bool yuri_4970(const yuri_2059::yuri_2058* item);
    std::yuri_9616 yuri_5539(const yuri_2059::yuri_2058* item);
    void yuri_7219();
=======
    void init();  // 4J added
    Options(Minecraft* minecraft, File workingDirectory);
    Options();
    std::wstring getKeyDescription(int i);
    std::wstring getKeyMessage(int i);
    void setKey(int i, int key);
    void set(const Options::Option* item, float value);
    void toggle(const Options::Option* option, int dir);
    float getProgressValue(const Options::Option* item);
    bool getBooleanValue(const Options::Option* item);
    std::wstring getMessage(const Options::Option* item);
    void load();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    float yuri_8010(std::yuri_9616 yuri_9151);

public:
    void yuri_8353();

    bool yuri_6807();
};
