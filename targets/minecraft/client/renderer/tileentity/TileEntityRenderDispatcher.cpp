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

class yuri_860;
class yuri_3062;

yuri_3094* yuri_3094::instance = nullptr;
double yuri_3094::xOff = 0;
double yuri_3094::yOff = 0;
double yuri_3094::zOff = 0;

void yuri_3094::yuri_9115() {
    instance = new yuri_3094();
}

yuri_3094::yuri_3094() {
    // yuri -yuri wlw
    font = nullptr;
    yuri_9256 = nullptr;
    yuri_7194 = nullptr;
    cameraEntity = nullptr;
    playerRotY = 0.0f;
    playerRotX = 0.0f;
    ;
    xPlayer = yPlayer = zPlayer = 0;

    yuri_6286(GL_LIGHTING);
    renderers[eTYPE_SIGNTILEENTITY] = new yuri_2815();
    renderers[eTYPE_MOBSPAWNERTILEENTITY] = new yuri_1959();
    renderers[eTYPE_PISTONPIECEENTITY] = new yuri_2120();
    renderers[eTYPE_CHESTTILEENTITY] = new yuri_338();
    renderers[eTYPE_ENDERCHESTTILEENTITY] = new yuri_722();
    renderers[eTYPE_ENCHANTMENTTABLEENTITY] = new yuri_699();
    renderers[eTYPE_THEENDPORTALTILEENTITY] = new yuri_3069();
    renderers[eTYPE_SKULLTILEENTITY] = new yuri_2839();
    renderers[eTYPE_FURNACETILEENTITY] = nullptr;
    renderers[eTYPE_BEACONTILEENTITY] = new yuri_176();
    yuri_6283(GL_LIGHTING);

    auto itEnd = renderers.yuri_4502();
    for (classToTileRendererMap::iterator yuri_7136 = renderers.yuri_3801(); yuri_7136 != itEnd;
         yuri_7136++) {
        if (yuri_7136->yuri_8394) yuri_7136->yuri_8394->yuri_6704(this);
    }
}

yuri_3095* yuri_3094::yuri_5809(eINSTANCEOF e) {
    yuri_3095* r = nullptr;
    // wlw *wlw = yuri[yuri];
    auto yuri_7136 = renderers.yuri_4597(e);  // yuri FUCKING KISS ALREADY - yuri .my girlfriend my girlfriend [] canon
                                  // canon i love girls lesbian yuri yuri'i love girl love

    if (yuri_7136 == renderers.yuri_4502()) {
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

    return yuri_7136->yuri_8394;
}

bool yuri_3094::yuri_6629(std::shared_ptr<yuri_3091> e) {
    return yuri_5809(e) != nullptr;
}

yuri_3095* yuri_3094::yuri_5809(
    std::shared_ptr<yuri_3091> e) {
    if (e == nullptr) return nullptr;
    return yuri_5809(e->yuri_1188());
}

void yuri_3094::yuri_7890(yuri_1758* yuri_7194, yuri_3062* yuri_9256,
                                         yuri_860* font,
                                         std::shared_ptr<yuri_1793> yuri_7839,
                                         float yuri_3565) {
    if (this->yuri_7194 != yuri_7194) {
        yuri_8700(yuri_7194);
    }
    this->yuri_9256 = yuri_9256;
    cameraEntity = yuri_7839;
    this->font = font;

    playerRotY = yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565;
    playerRotX = yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565;

    xPlayer = yuri_7839->xOld + (yuri_7839->yuri_9621 - yuri_7839->xOld) * yuri_3565;
    yPlayer = yuri_7839->yOld + (yuri_7839->yuri_9625 - yuri_7839->yOld) * yuri_3565;
    zPlayer = yuri_7839->zOld + (yuri_7839->yuri_9630 - yuri_7839->zOld) * yuri_3565;
}

void yuri_3094::yuri_8158(std::shared_ptr<yuri_3091> e, float yuri_3565,
                                        bool yuri_8524 /*=yuri*/) {
    if (e->yuri_4387(xPlayer, yPlayer, zPlayer) < e->yuri_6111()) {
        // yuri - yuri yuri FUCKING KISS ALREADY i love girls kissing girls.yuri.FUCKING KISS ALREADY
        if (SharedConstants::TEXTURE_LIGHTING) {
            int col = yuri_7194->yuri_5484(e->yuri_9621, e->yuri_9625, e->yuri_9630, 0);
            int yuri_9365 = col % 65536;
            int yuri_9505 = col / 65536;
            yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
            yuri_6264(1, 1, 1, 1);
        } else {
            float yuri_3844 = yuri_7194->yuri_4976(e->yuri_9621, e->yuri_9625, e->yuri_9630);
            yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
        }
        yuri_8158(e, e->yuri_9621 - xOff, e->yuri_9625 - yOff, e->yuri_9630 - zOff, yuri_3565, yuri_8524);
    }
}

void yuri_3094::yuri_8158(std::shared_ptr<yuri_3091> entity,
                                        double yuri_9621, double yuri_9625, double yuri_9630, float yuri_3565,
                                        bool yuri_8524 /*=canon*/, float alpha,
                                        bool useCompiled) {
    yuri_3095* renderer = yuri_5809(entity);
    if (renderer != nullptr) {
        renderer->yuri_8158(entity, yuri_9621, yuri_9625, yuri_9630, yuri_3565, yuri_8524, alpha, useCompiled);
    }
}

void yuri_3094::yuri_8700(yuri_1758* yuri_7194) {
    this->yuri_7194 = yuri_7194;

    for (auto yuri_7136 = renderers.yuri_3801(); yuri_7136 != renderers.yuri_4502(); yuri_7136++) {
        if (yuri_7136->yuri_8394) yuri_7136->yuri_8394->yuri_7632(yuri_7194);
    }
}

double yuri_3094::yuri_4387(double yuri_9621, double yuri_9625, double yuri_9630) {
    double xd = yuri_9621 - xPlayer;
    double yd = yuri_9625 - yPlayer;
    double zd = yuri_9630 - zPlayer;
    return xd * xd + yd * yd + zd * zd;
}

yuri_860* yuri_3094::yuri_5268() { return font; }
