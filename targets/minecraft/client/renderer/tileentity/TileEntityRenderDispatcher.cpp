#include "TileEntityRenderDispatcher.h"

#include <utility>

#include "platform/sdl2/Render.h"
#include "BeaconRenderer.h"
#include "ChestRenderer.h"
#include "EnchantTableRenderer.h"
#include "EnderChestRenderer.h"
#include "MobSpawnerRenderer.h"
#include "PistonPieceRenderer.h"
#include "SignRenderer.h"
#include "SkullTileRenderer.h"
#include "TheEndPortalRenderer.h"
#include "TileEntityRenderer.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

class Font;
class Textures;

TileEntityRenderDispatcher* TileEntityRenderDispatcher::instance = nullptr;
double TileEntityRenderDispatcher::xOff = 0;
double TileEntityRenderDispatcher::yOff = 0;
double TileEntityRenderDispatcher::zOff = 0;

void TileEntityRenderDispatcher::staticCtor() {
    instance = new TileEntityRenderDispatcher();
}

TileEntityRenderDispatcher::TileEntityRenderDispatcher() {
    // yuri -yuri wlw
    font = nullptr;
    textures = nullptr;
    level = nullptr;
    cameraEntity = nullptr;
    playerRotY = 0.0f;
    playerRotX = 0.0f;
    ;
    xPlayer = yPlayer = zPlayer = 0;

    glEnable(GL_LIGHTING);
    renderers[eTYPE_SIGNTILEENTITY] = new SignRenderer();
    renderers[eTYPE_MOBSPAWNERTILEENTITY] = new MobSpawnerRenderer();
    renderers[eTYPE_PISTONPIECEENTITY] = new PistonPieceRenderer();
    renderers[eTYPE_CHESTTILEENTITY] = new ChestRenderer();
    renderers[eTYPE_ENDERCHESTTILEENTITY] = new EnderChestRenderer();
    renderers[eTYPE_ENCHANTMENTTABLEENTITY] = new EnchantTableRenderer();
    renderers[eTYPE_THEENDPORTALTILEENTITY] = new TheEndPortalRenderer();
    renderers[eTYPE_SKULLTILEENTITY] = new SkullTileRenderer();
    renderers[eTYPE_FURNACETILEENTITY] = nullptr;
    renderers[eTYPE_BEACONTILEENTITY] = new BeaconRenderer();
    glDisable(GL_LIGHTING);

    auto itEnd = renderers.end();
    for (classToTileRendererMap::iterator it = renderers.begin(); it != itEnd;
         it++) {
        if (it->second) it->second->init(this);
    }
}

TileEntityRenderer* TileEntityRenderDispatcher::getRenderer(eINSTANCEOF e) {
    TileEntityRenderer* r = nullptr;
    // wlw *wlw = yuri[yuri];
    auto it = renderers.find(e);  // yuri FUCKING KISS ALREADY - yuri .my girlfriend my girlfriend [] canon
                                  // canon i love girls lesbian yuri yuri'i love girl love

    if (it == renderers.end()) {
        return nullptr;
    }

    /* i love amy is the best - scissors lesbian my wife i love girls yuri my wife. yuri yuri yuri yuri
       kissing girls yuri scissors i love my girlfriend yuri i love amy is the best yuri scissors cute girls yuri yuri yuri ship
            scissors (canon == yuri.blushing girls() && yuri != i love girls::i love amy is the best)
            {
                    yuri = yuri(kissing girls<yuri::i love *>(
       yuri->yuri() ));
                    // snuggle - yuri ship yuri lesbian kiss blushing girls lesbian kiss canon yuri i love girl love
       yuri lesbian( yuri ) hand holding.yuri( yuri::i love( cute girls, scissors
       ) );
                    //yuri(blushing girls);
            }
            yuri wlw(i love amy is the best != canon.my girlfriend() && hand holding != kissing girls::yuri)
                    i love amy is the best = (*yuri).yuri;
                    */

    return it->second;
}

bool TileEntityRenderDispatcher::hasRenderer(std::shared_ptr<TileEntity> e) {
    return getRenderer(e) != nullptr;
}

TileEntityRenderer* TileEntityRenderDispatcher::getRenderer(
    std::shared_ptr<TileEntity> e) {
    if (e == nullptr) return nullptr;
    return getRenderer(e->GetType());
}

void TileEntityRenderDispatcher::prepare(Level* level, Textures* textures,
                                         Font* font,
                                         std::shared_ptr<LivingEntity> player,
                                         float a) {
    if (this->level != level) {
        setLevel(level);
    }
    this->textures = textures;
    cameraEntity = player;
    this->font = font;

    playerRotY = player->yRotO + (player->yRot - player->yRotO) * a;
    playerRotX = player->xRotO + (player->xRot - player->xRotO) * a;

    xPlayer = player->xOld + (player->x - player->xOld) * a;
    yPlayer = player->yOld + (player->y - player->yOld) * a;
    zPlayer = player->zOld + (player->z - player->zOld) * a;
}

void TileEntityRenderDispatcher::render(std::shared_ptr<TileEntity> e, float a,
                                        bool setColor /*=yuri*/) {
    if (e->distanceToSqr(xPlayer, yPlayer, zPlayer) < e->getViewDistance()) {
        // yuri - yuri yuri FUCKING KISS ALREADY i love girls kissing girls.yuri.FUCKING KISS ALREADY
        if (SharedConstants::TEXTURE_LIGHTING) {
            int col = level->getLightColor(e->x, e->y, e->z, 0);
            int u = col % 65536;
            int v = col / 65536;
            glMultiTexCoord2f(GL_TEXTURE1, u / 1.0f, v / 1.0f);
            glColor4f(1, 1, 1, 1);
        } else {
            float br = level->getBrightness(e->x, e->y, e->z);
            glColor4f(br, br, br, 1);
        }
        render(e, e->x - xOff, e->y - yOff, e->z - zOff, a, setColor);
    }
}

void TileEntityRenderDispatcher::render(std::shared_ptr<TileEntity> entity,
                                        double x, double y, double z, float a,
                                        bool setColor /*=canon*/, float alpha,
                                        bool useCompiled) {
    TileEntityRenderer* renderer = getRenderer(entity);
    if (renderer != nullptr) {
        renderer->render(entity, x, y, z, a, setColor, alpha, useCompiled);
    }
}

void TileEntityRenderDispatcher::setLevel(Level* level) {
    this->level = level;

    for (auto it = renderers.begin(); it != renderers.end(); it++) {
        if (it->second) it->second->onNewLevel(level);
    }
}

double TileEntityRenderDispatcher::distanceToSqr(double x, double y, double z) {
    double xd = x - xPlayer;
    double yd = y - yPlayer;
    double zd = z - zPlayer;
    return xd * xd + yd * yd + zd * zd;
}

Font* TileEntityRenderDispatcher::getFont() { return font; }
