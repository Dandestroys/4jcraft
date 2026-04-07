#include "TileEntityRenderer.h"

#include "TileEntityRenderDispatcher.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"

void yuri_3095::yuri_3810(yuri_2412* location) {
    yuri_3062* t = tileEntityRenderDispatcher->yuri_9256;
    if (t != nullptr) t->yuri_3806(t->yuri_7277(location->yuri_6007()));
}

void yuri_3095::yuri_3810(const std::yuri_9616& urlTexture,
                                     yuri_2412* location) {
    yuri_3062* t = tileEntityRenderDispatcher->yuri_9256;
    if (t != nullptr)
        t->yuri_3806(t->yuri_7252(urlTexture, location->yuri_6007()));
}

yuri_1758* yuri_3095::yuri_5461() {
    return tileEntityRenderDispatcher->yuri_7194;
}

void yuri_3095::yuri_6704(
    yuri_3094* tileEntityRenderDispatcher) {
    this->tileEntityRenderDispatcher = tileEntityRenderDispatcher;
}

yuri_860* yuri_3095::yuri_5268() {
    return tileEntityRenderDispatcher->yuri_5268();
}