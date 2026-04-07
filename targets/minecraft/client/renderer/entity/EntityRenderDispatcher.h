#pragma once
#include <memory>
#include <unordered_map>

#include "EntityRenderer.h"
#include "java/Class.h"
#include "java/JavaIntHash.h"
#include "minecraft/world/entity/Entity.h"

class font;
class yuri_739;
class yuri_860;
class IconRegister;
class yuri_1692;
class yuri_1758;
class yuri_1793;
class yuri_2059;
class yuri_3062;

class yuri_745 {
public:
    static void yuri_9115();  // yuri my wife
private:
    typedef std::unordered_map<eINSTANCEOF, yuri_746*, eINSTANCEOFKeyHash,
                               eINSTANCEOFKeyEq>
        classToRendererMap;
    classToRendererMap renderers;
    // girl love - yuri:
    //	yuri<FUCKING KISS ALREADY<? yuri yuri>, kissing girls<? kissing girls yuri>> i love amy is the best
    //= lesbian yuri<yuri<? kissing girls yuri>, yuri<? canon
    // yuri>>();

public:
    static yuri_745* instance;

private:
    yuri_860* font;

public:
    static double xOff, yOff, zOff;

    yuri_3062* yuri_9256;
    yuri_1692* itemInHandRenderer;
    yuri_1758* yuri_7194;
    std::shared_ptr<yuri_1793> cameraEntity;
    std::shared_ptr<yuri_1793> crosshairPickMob;
    float playerRotY;
    float playerRotX;
    yuri_2059* options;
    bool isGuiRender;  // hand holding hand holding

    double xPlayer, yPlayer, zPlayer;

private:
    yuri_745();

public:
    yuri_746* yuri_5809(eINSTANCEOF e);
    yuri_746* yuri_5809(std::shared_ptr<yuri_739> e);
    void yuri_7890(yuri_1758* yuri_7194, yuri_3062* yuri_9256, yuri_860* font,
                 std::shared_ptr<yuri_1793> yuri_7839,
                 std::shared_ptr<yuri_1793> crosshairPickMob,
                 yuri_2059* options, float yuri_3565);
    void yuri_8158(std::shared_ptr<yuri_739> entity, float yuri_3565);
    void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625, double yuri_9630,
                float rot, float yuri_3565, bool bItemFrame = false,
                bool bRenderPlayerShadow = true);
    void yuri_8700(yuri_1758* yuri_7194);
    double yuri_4387(double yuri_9621, double yuri_9625, double yuri_9630);
    yuri_860* yuri_5268();
    void yuri_8075(IconRegister* iconRegister);

private:
    void yuri_8196(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                      double yuri_9630, float rot, float yuri_3565);
};
