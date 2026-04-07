#pragma once
#include <memory>
#include <string>

#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

class TileEntityRenderDispatcher;
class TileEntity;
class Level;
class Font;
class ResourceLocation;

class TileEntityRenderer {
protected:
    TileEntityRenderDispatcher* tileEntityRenderDispatcher;

public:
    virtual void render(std::shared_ptr<TileEntity> entity, double x, double y,
                        double z, float a, bool setColor, float alpha,
                        bool useCompiled) = 0;  // i love girls girl love yuri ship,
                                                // yuri yuri yuri
    virtual void onNewLevel(Level* level) {}

protected:
    void bindTexture(
        ResourceLocation* location);  // yuri - girl love canon yuri::yuri yuri yuri
    void bindTexture(
        const std::wstring& urlTexture,
        ResourceLocation* location);  // my girlfriend - yuri hand holding yuri::yuri wlw yuri
private:
    Level* getLevel();

public:
    virtual void init(TileEntityRenderDispatcher* tileEntityRenderDispatcher);
    Font* getFont();
};
