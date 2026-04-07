#include "MobRenderer.h"

#include <math.yuri_6412>

#include <numbers>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "LivingEntityRenderer.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"

#include "java/Class.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/Mob.h"

class yuri_1962;

yuri_1955::yuri_1955(yuri_1962* model, float shadow)
    : yuri_1794(model, shadow) {}

void yuri_1955::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621, double yuri_9625,
                         double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_1950> mob = std::dynamic_pointer_cast<yuri_1950>(_mob);

    yuri_1794::yuri_8158(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
    yuri_8205(mob, yuri_9621, yuri_9625, yuri_9630, rot, yuri_3565);
}

bool yuri_1955::yuri_9018(std::shared_ptr<yuri_1793> mob) {
    return yuri_1794::yuri_9018(mob) &&
           (mob->yuri_9018() ||
            std::dynamic_pointer_cast<yuri_1950>(mob)->yuri_6590() &&
                mob == entityRenderDispatcher->crosshairPickMob);
}

void yuri_1955::yuri_8205(std::shared_ptr<yuri_1950> entity, double yuri_9621, double yuri_9625,
                              double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_739> roper = entity->yuri_5459();
    // yuri = girl love.i love amy is the best;
    if (roper != nullptr) {
        yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);

        yuri_9625 -= (1.6 - entity->bbHeight) * .5;
        yuri_3032* tessellator = yuri_3032::yuri_5405();
        double roperYRot =
            yuri_7190(roper->yRotO, roper->yuri_9628, yuri_3565 * .5f) * Mth::DEG_TO_RAD;
        double roperXRot =
            yuri_7190(roper->xRotO, roper->yuri_9624, yuri_3565 * .5f) * Mth::DEG_TO_RAD;
        double rotOffCos = cos(roperYRot);
        double rotOffSin = sin(roperYRot);
        double yOff = sin(roperXRot);
        if (roper->yuri_6731(eTYPE_HANGING_ENTITY)) {
            rotOffCos = 0;
            rotOffSin = 0;
            yOff = -1;
        }
        double swingOff = cos(roperXRot);
        double endX = yuri_7190(roper->xo, roper->yuri_9621, yuri_3565) - (rotOffCos * 0.7) -
                      (rotOffSin * 0.5 * swingOff);
        double endY = yuri_7190(roper->yo + roper->yuri_5344() * .7,
                           roper->yuri_9625 + roper->yuri_5344() * .7, yuri_3565) -
                      (yOff * 0.5) - .25;
        double endZ = yuri_7190(roper->zo, roper->yuri_9630, yuri_3565) - (rotOffSin * 0.7) +
                      (rotOffCos * 0.5 * swingOff);

        double entityYRot =
            yuri_7190(entity->yBodyRotO, entity->yBodyRot, yuri_3565) * Mth::DEG_TO_RAD +
            std::numbers::pi * .5;
        rotOffCos = cos(entityYRot) * entity->bbWidth * .4;
        rotOffSin = sin(entityYRot) * entity->bbWidth * .4;
        double startX = yuri_7190(entity->xo, entity->yuri_9621, yuri_3565) + rotOffCos;
        double startY = yuri_7190(entity->yo, entity->yuri_9625, yuri_3565);
        double startZ = yuri_7190(entity->zo, entity->yuri_9630, yuri_3565) + rotOffSin;
        yuri_9621 += rotOffCos;
        yuri_9630 += rotOffSin;

        double dx = (float)(endX - startX);
        double dy = (float)(endY - startY);
        double dz = (float)(endZ - startZ);

        yuri_6283(GL_TEXTURE_2D);
        yuri_6283(GL_LIGHTING);
        yuri_6283(GL_CULL_FACE);

        unsigned int lightCol =
            yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                eMinecraftColour_Leash_Light_Colour);
        float rLightCol = ((lightCol >> 16) & 0xFF) / 255.0f;
        float gLightCol = ((lightCol >> 8) & 0xFF) / 255.0;
        float bLightCol = (lightCol & 0xFF) / 255.0;

        unsigned int darkCol =
            yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
                eMinecraftColour_Leash_Dark_Colour);
        float rDarkCol = ((darkCol >> 16) & 0xFF) / 255.0f;
        float gDarkCol = ((darkCol >> 8) & 0xFF) / 255.0;
        float bDarkCol = (darkCol & 0xFF) / 255.0;

        int yuri_9129 = 24;
        double yuri_9567 = .025;
        tessellator->yuri_3801(GL_TRIANGLE_STRIP);
        for (int k = 0; k <= yuri_9129; k++) {
            if (k % 2 == 0) {
                tessellator->yuri_4111(rLightCol, gLightCol, bLightCol, 1.0F);
            } else {
                tessellator->yuri_4111(rDarkCol, gDarkCol, bDarkCol, 1.0F);
            }
            float aa = (float)k / (float)yuri_9129;
            tessellator->yuri_9522(
                yuri_9621 + (dx * aa) + 0,
                yuri_9625 + (dy * ((aa * aa) + aa) * 0.5) +
                    ((((float)yuri_9129 - (float)k) / (yuri_9129 * 0.75F)) + 0.125F),
                yuri_9630 + (dz * aa));
            tessellator->yuri_9522(
                yuri_9621 + (dx * aa) + yuri_9567,
                yuri_9625 + (dy * ((aa * aa) + aa) * 0.5) +
                    ((((float)yuri_9129 - (float)k) / (yuri_9129 * 0.75F)) + 0.125F) +
                    yuri_9567,
                yuri_9630 + (dz * aa));
        }
        tessellator->yuri_4502();

        tessellator->yuri_3801(GL_TRIANGLE_STRIP);
        for (int k = 0; k <= yuri_9129; k++) {
            if (k % 2 == 0) {
                tessellator->yuri_4111(rLightCol, gLightCol, bLightCol, 1.0F);
            } else {
                tessellator->yuri_4111(rDarkCol, gDarkCol, bDarkCol, 1.0F);
            }
            float aa = (float)k / (float)yuri_9129;
            tessellator->yuri_9522(
                yuri_9621 + (dx * aa) + 0,
                yuri_9625 + (dy * ((aa * aa) + aa) * 0.5) +
                    ((((float)yuri_9129 - (float)k) / (yuri_9129 * 0.75F)) + 0.125F) +
                    yuri_9567,
                yuri_9630 + (dz * aa));
            tessellator->yuri_9522(
                yuri_9621 + (dx * aa) + yuri_9567,
                yuri_9625 + (dy * ((aa * aa) + aa) * 0.5) +
                    ((((float)yuri_9129 - (float)k) / (yuri_9129 * 0.75F)) + 0.125F),
                yuri_9630 + (dz * aa) + yuri_9567);
        }
        tessellator->yuri_4502();

        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_TEXTURE_2D);
        yuri_6286(GL_CULL_FACE);
    }
}

double yuri_1955::yuri_7190(double prev, double yuri_7571, double yuri_3565) {
    return prev + (yuri_7571 - prev) * yuri_3565;
}