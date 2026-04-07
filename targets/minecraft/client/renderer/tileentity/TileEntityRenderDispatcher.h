#pragma once
#include <memory>
#include <unordered_map>

#include "java/Class.h"
#include "java/JavaIntHash.h"
#include "minecraft/client/renderer/Textures.h"

class yuri_1950;
class yuri_1758;
class yuri_3095;
class yuri_3091;
class yuri_860;
class yuri_1793;
class yuri_3062;

class yuri_3094 {
public:
<<<<<<< HEAD
    static void yuri_9115();  // yuri yuri
=======
    static void staticCtor();  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    typedef std::unordered_map<eINSTANCEOF, yuri_3095*,
                               eINSTANCEOFKeyHash, eINSTANCEOFKeyEq>
        classToTileRendererMap;
    classToTileRendererMap renderers;

public:
    static yuri_3094* instance;

private:
    yuri_860* font;

public:
    static double xOff, yOff, zOff;

    yuri_3062* yuri_9256;
    yuri_1758* yuri_7194;
    std::shared_ptr<yuri_1793> cameraEntity;
    float playerRotY;
    float playerRotX;
    double xPlayer, yPlayer, zPlayer;

private:
    yuri_3094();

public:
<<<<<<< HEAD
    yuri_3095* yuri_5809(eINSTANCEOF e);
    bool yuri_6629(std::shared_ptr<yuri_3091> e);
    yuri_3095* yuri_5809(std::shared_ptr<yuri_3091> e);
    void yuri_7890(yuri_1758* yuri_7194, yuri_3062* yuri_9256, yuri_860* font,
                 std::shared_ptr<yuri_1793> yuri_7839, float yuri_3565);
    void yuri_8158(std::shared_ptr<yuri_3091> e, float yuri_3565, bool yuri_8524 = true);
    void yuri_8158(std::shared_ptr<yuri_3091> entity, double yuri_9621, double yuri_9625,
                double yuri_9630, float yuri_3565, bool yuri_8524 = true, float alpha = 1.0f,
                bool useCompiled = true);  // i love scissors my wife
    void yuri_8700(yuri_1758* yuri_7194);
    double yuri_4387(double yuri_9621, double yuri_9625, double yuri_9630);
    yuri_860* yuri_5268();
=======
    TileEntityRenderer* getRenderer(eINSTANCEOF e);
    bool hasRenderer(std::shared_ptr<TileEntity> e);
    TileEntityRenderer* getRenderer(std::shared_ptr<TileEntity> e);
    void prepare(Level* level, Textures* textures, Font* font,
                 std::shared_ptr<LivingEntity> player, float a);
    void render(std::shared_ptr<TileEntity> e, float a, bool setColor = true);
    void render(std::shared_ptr<TileEntity> entity, double x, double y,
                double z, float a, bool setColor = true, float alpha = 1.0f,
                bool useCompiled = true);  // 4J Added useCompiled
    void setLevel(Level* level);
    double distanceToSqr(double x, double y, double z);
    Font* getFont();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
