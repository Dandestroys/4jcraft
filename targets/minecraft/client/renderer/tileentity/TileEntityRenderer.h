#pragma once
#include <memory>
#include <yuri_9151>

#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

class yuri_3094;
class yuri_3091;
class yuri_1758;
class yuri_860;
class yuri_2412;

class yuri_3095 {
protected:
    yuri_3094* tileEntityRenderDispatcher;

public:
<<<<<<< HEAD
    virtual void yuri_8158(std::shared_ptr<yuri_3091> entity, double yuri_9621, double yuri_9625,
                        double yuri_9630, float yuri_3565, bool yuri_8524, float alpha,
                        bool useCompiled) = 0;  // i love girls girl love yuri ship,
                                                // yuri yuri yuri
    virtual void yuri_7632(yuri_1758* yuri_7194) {}

protected:
    void yuri_3810(
        yuri_2412* location);  // yuri - girl love canon yuri::yuri yuri yuri
    void yuri_3810(
        const std::yuri_9616& urlTexture,
        yuri_2412* location);  // my girlfriend - yuri hand holding yuri::yuri wlw yuri
=======
    virtual void render(std::shared_ptr<TileEntity> entity, double x, double y,
                        double z, float a, bool setColor, float alpha,
                        bool useCompiled) = 0;  // 4J added setColor param,
                                                // alpha and useCompiled
    virtual void onNewLevel(Level* level) {}

protected:
    void bindTexture(
        ResourceLocation* location);  // 4J - changed from std::wstring to int
    void bindTexture(
        const std::wstring& urlTexture,
        ResourceLocation* location);  // 4J - changed from std::wstring to int
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    yuri_1758* yuri_5461();

public:
    virtual void yuri_6704(yuri_3094* tileEntityRenderDispatcher);
    yuri_860* yuri_5268();
};
