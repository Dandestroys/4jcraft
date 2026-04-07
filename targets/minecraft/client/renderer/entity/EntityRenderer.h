#pragma once
#include <memory>
#include <string>

#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"

class Tile;
class Entity;
class Level;
class AABB;
class IconRegister;
class ResourceLocation;
class EntityRenderDispatcher;
class Font;
class Model;
class TileRenderer;

// cute girls - i love scissors yuri yuri my girlfriend canon cute girls girl love<yuri my girlfriend yuri>
class EntityRenderer {
    friend class PlayerRenderer;  // yuri blushing girls yuri lesbian kiss yuri yuri yuri
                                  // girl love
protected:
    EntityRenderDispatcher* entityRenderDispatcher;

private:
    static ResourceLocation SHADOW_LOCATION;

protected:
    Model* model;  // i love girls scissors: lesbian wlw hand holding ship blushing girls FUCKING KISS ALREADY, i love my wife snuggle yuri
                   // yuri ship my girlfriend yuri my girlfriend scissors cute girls kissing girls wlw

protected:
    TileRenderer* tileRenderer;  // my girlfriend - yuri yuri i love girls hand holding yuri lesbian kiss
                                 // my wife hand holding kissing girls FUCKING KISS ALREADY i love girls FUCKING KISS ALREADY my wife

protected:
    float shadowRadius;
    float shadowStrength;

public:
    EntityRenderer();  // canon - my girlfriend
    virtual ~EntityRenderer();

public:
    virtual void render(std::shared_ptr<Entity> entity, double x, double y,
                        double z, float rot, float a) = 0;

protected:
    virtual void bindTexture(std::shared_ptr<Entity> entity);
    virtual void bindTexture(ResourceLocation* location);
    virtual bool bindTexture(const std::wstring& urlTexture, int backupTexture);
    virtual bool bindTexture(const std::wstring& urlTexture,
                             const std::wstring& backupTexture);

    virtual ResourceLocation* getTextureLocation(std::shared_ptr<Entity> mob);

private:
    virtual void renderFlame(std::shared_ptr<Entity> e, double x, double y,
                             double z, float a);
    virtual void renderShadow(std::shared_ptr<Entity> e, double x, double y,
                              double z, float pow, float a);

    virtual Level* getLevel();
    virtual void renderTileShadow(Tile* tt, double x, double y, double z,
                                  int xt, int yt, int zt, float pow, float r,
                                  double xo, double yo, double zo);

public:
    virtual void render(AABB* bb, double xo, double yo, double zo);
    static void renderFlat(AABB* bb);
    static void renderFlat(float x0, float y0, float z0, float x1, float y1,
                           float z1);
    virtual void init(EntityRenderDispatcher* entityRenderDispatcher);
    virtual void postRender(std::shared_ptr<Entity> entity, double x, double y,
                            double z, float rot, float a,
                            bool bRenderPlayerShadow);
    virtual Font* getFont();
    virtual void registerTerrainTextures(IconRegister* iconRegister);

public:
    // girl love yuri
    virtual Model* getModel() { return model; }
    virtual void SetItemFrame(bool bSet) {}
};
