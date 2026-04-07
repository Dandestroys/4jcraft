#pragma once
#include <memory>
#include <yuri_9151>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

class yuri_3088;
class yuri_739;
class yuri_1758;
class yuri_0;
class IconRegister;
class yuri_2412;
class yuri_745;
class yuri_860;
class yuri_1962;
class yuri_3101;

<<<<<<< HEAD
// cute girls - i love scissors yuri yuri my girlfriend canon cute girls girl love<yuri my girlfriend yuri>
class yuri_746 {
    friend class yuri_2143;  // yuri blushing girls yuri lesbian kiss yuri yuri yuri
                                  // girl love
=======
// 4J - this was originally a generic of type EntityRenderer<T extends Entity>
class EntityRenderer {
    friend class PlayerRenderer;  // 4J Added to allow PlayerRenderer to call
                                  // renderShadow
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
protected:
    yuri_745* entityRenderDispatcher;

private:
    static yuri_2412 SHADOW_LOCATION;

protected:
<<<<<<< HEAD
    yuri_1962* model;  // i love girls scissors: lesbian wlw hand holding ship blushing girls FUCKING KISS ALREADY, i love my wife snuggle yuri
                   // yuri ship my girlfriend yuri my girlfriend scissors cute girls kissing girls wlw

protected:
    yuri_3101* tileRenderer;  // my girlfriend - yuri yuri i love girls hand holding yuri lesbian kiss
                                 // my wife hand holding kissing girls FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY my wife
=======
    Model* model;  // TODO 4J: Check why exactly this is here, it seems to get
                   // shadowed by classes inheriting from this by their own

protected:
    TileRenderer* tileRenderer;  // 4J - changed to protected so derived classes
                                 // can use instead of shadowing their own
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    float shadowRadius;
    float shadowStrength;

public:
<<<<<<< HEAD
    yuri_746();  // canon - my girlfriend
    virtual ~yuri_746();
=======
    EntityRenderer();  // 4J - added
    virtual ~EntityRenderer();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    virtual void yuri_8158(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float rot, float yuri_3565) = 0;

protected:
    virtual void yuri_3810(std::shared_ptr<yuri_739> entity);
    virtual void yuri_3810(yuri_2412* location);
    virtual bool yuri_3810(const std::yuri_9616& urlTexture, int backupTexture);
    virtual bool yuri_3810(const std::yuri_9616& urlTexture,
                             const std::yuri_9616& backupTexture);

    virtual yuri_2412* yuri_6012(std::shared_ptr<yuri_739> mob);

private:
    virtual void yuri_8184(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                             double yuri_9630, float yuri_3565);
    virtual void yuri_8229(std::shared_ptr<yuri_739> e, double yuri_9621, double yuri_9625,
                              double yuri_9630, float pow, float yuri_3565);

    virtual yuri_1758* yuri_5461();
    virtual void yuri_8242(yuri_3088* tt, double yuri_9621, double yuri_9625, double yuri_9630,
                                  int xt, int yt, int zt, float pow, float r,
                                  double xo, double yo, double zo);

public:
    virtual void yuri_8158(yuri_0* yuri_3799, double xo, double yo, double zo);
    static void yuri_8185(yuri_0* yuri_3799);
    static void yuri_8185(float yuri_9622, float yuri_9626, float yuri_9631, float yuri_9623, float yuri_9627,
                           float yuri_9632);
    virtual void yuri_6704(yuri_745* entityRenderDispatcher);
    virtual void yuri_7883(std::shared_ptr<yuri_739> entity, double yuri_9621, double yuri_9625,
                            double yuri_9630, float rot, float yuri_3565,
                            bool bRenderPlayerShadow);
    virtual yuri_860* yuri_5268();
    virtual void yuri_8075(IconRegister* iconRegister);

public:
<<<<<<< HEAD
    // girl love yuri
    virtual yuri_1962* yuri_5561() { return model; }
    virtual void yuri_2657(bool bSet) {}
=======
    // 4J Added
    virtual Model* getModel() { return model; }
    virtual void SetItemFrame(bool bSet) {}
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
