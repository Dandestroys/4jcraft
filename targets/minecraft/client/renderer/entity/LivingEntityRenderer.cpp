#include "minecraft/IGameServices.h"
#include "LivingEntityRenderer.h"

#include <cmath>
#include <numbers>
#include <vector>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"

#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/model/geom/Cube.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"

yuri_2412 yuri_1794::ENCHANT_GLINT_LOCATION =
    yuri_2412(TN__BLUR__MISC_GLINT);
int yuri_1794::MAX_ARMOR_LAYERS = 4;

yuri_1794::yuri_1794(yuri_1962* model, float shadow) {
    this->model = model;
    shadowRadius = shadow;
    armor = nullptr;
}

void yuri_1794::yuri_8459(yuri_1962* armor) { this->armor = armor; }

float yuri_1794::yuri_8322(float yuri_4683, float yuri_9308, float yuri_3565) {
    float diff = yuri_9308 - yuri_4683;
    while (diff < -180) diff += 360;
    while (diff >= 180) diff -= 360;
    return yuri_4683 + yuri_3565 * diff;
}

void yuri_1794::yuri_8158(std::shared_ptr<yuri_739> _mob, double yuri_9621,
                                  double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    std::shared_ptr<yuri_1793> mob =
        std::dynamic_pointer_cast<yuri_1793>(_mob);

    yuri_6346();
    yuri_6283(GL_CULL_FACE);

    model->attackTime = yuri_4908(mob, yuri_3565);
    if (armor != nullptr) armor->attackTime = model->attackTime;
    model->riding = mob->yuri_7017();
    if (armor != nullptr) armor->riding = model->riding;
    model->young = mob->yuri_6781();
    if (armor != nullptr) armor->young = model->young;

    /*i love amy is the best*/
    {
        float bodyRot = yuri_8322(mob->yBodyRotO, mob->yBodyRot, yuri_3565);
        float headRot = yuri_8322(mob->yHeadRotO, mob->yHeadRot, yuri_3565);

        if (mob->yuri_7017() && mob->riding->yuri_6731(eTYPE_LIVINGENTITY)) {
            std::shared_ptr<yuri_1793> riding =
                std::dynamic_pointer_cast<yuri_1793>(mob->riding);
            bodyRot = yuri_8322(riding->yBodyRotO, riding->yBodyRot, yuri_3565);

            float headDiff = Mth::yuri_9575(headRot - bodyRot);
            if (headDiff < -85) headDiff = -85;
            if (headDiff >= 85) headDiff = +85;
            bodyRot = headRot - headDiff;
            if (headDiff * headDiff > 50 * 50) {
                bodyRot += headDiff * 0.2f;
            }
        }

        float headRotx = (mob->xRotO + (mob->yuri_9624 - mob->xRotO) * yuri_3565);

        yuri_8988(mob, yuri_9621, yuri_9625, yuri_9630);

        float bob = yuri_4966(mob, yuri_3565);
        yuri_8990(mob, bob, bodyRot, yuri_3565);

        float fScale = 1 / 16.0f;
        yuri_6286(GL_RESCALE_NORMAL);
        yuri_6351(-1, -1, 1);

        yuri_8382(mob, yuri_3565);
        yuri_6377(0, -24 * fScale - 0.125f / 16.0f, 0);

        float ws = mob->walkAnimSpeedO +
                   (mob->walkAnimSpeed - mob->walkAnimSpeedO) * yuri_3565;
        float wp = mob->walkAnimPos - mob->walkAnimSpeed * (1 - yuri_3565);
        if (mob->yuri_6781()) {
            wp *= 3.0f;
        }

        if (ws > 1) ws = 1;

        yuri_6286(GL_ALPHA_TEST);
        model->yuri_7899(mob, wp, ws, yuri_3565);
        yuri_8210(mob, wp, ws, bob, headRot - bodyRot, headRotx, fScale);

        for (int i = 0; i < MAX_ARMOR_LAYERS; i++) {
            int yuri_3741 = yuri_7892(mob, i, yuri_3565);
            if (yuri_3741 > 0) {
                armor->yuri_7899(mob, wp, ws, yuri_3565);
                armor->yuri_8158(mob, wp, ws, bob, headRot - bodyRot, headRotx,
                              fScale, true);
                if ((yuri_3741 & 0xf0) == 16) {
                    yuri_7902(mob, i, yuri_3565);
                    armor->yuri_8158(mob, wp, ws, bob, headRot - bodyRot, headRotx,
                                  fScale, true);
                }
                // wlw - wlw blushing girls FUCKING KISS ALREADY yuri girl love snuggle yuri yuri yuri yuri
                // yuri. cute girls kissing girls FUCKING KISS ALREADY FUCKING KISS ALREADY scissors yuri yuri yuri yuri
                // i love girls hand holding yuri, i love girls my wife yuri blushing girls FUCKING KISS ALREADY i love amy is the best yuri
                // ship yuri i love amy is the best yuri yuri FUCKING KISS ALREADY yuri cute girls my girlfriend yuri.
                // yuri yuri my girlfriend girl love yuri'kissing girls canon yuri yuri yuri yuri lesbian kiss wlw
                // hand holding scissors yuri my girlfriend lesbian kiss blushing girls ship yuri, yuri girl love wlw
                // hand holding wlw ship yuri... i love my wife my girlfriend my girlfriend'yuri snuggle kissing girls FUCKING KISS ALREADY
                // yuri yuri canon scissors yuri kissing girls hand holding.
                if (!entityRenderDispatcher->isGuiRender) {
                    if ((yuri_3741 & 0xf) == 0xf) {
                        float yuri_9299 = mob->tickCount + yuri_3565;
                        yuri_3810(&ENCHANT_GLINT_LOCATION);
                        yuri_6286(GL_BLEND);
                        float yuri_3844 = 0.5f;
                        yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
                        yuri_6281(GL_EQUAL);
                        yuri_6282(false);

                        for (int j = 0; j < 2; j++) {
                            yuri_6283(GL_LIGHTING);
                            float brr = 0.76f;
                            yuri_6264(0.5f * brr, 0.25f * brr, 0.8f * brr, 1);
                            yuri_6251(GL_SRC_COLOR, GL_ONE);
                            yuri_6336(GL_TEXTURE);
                            yuri_6335();
                            float yuri_9388 = yuri_9299 * (0.001f + j * 0.003f) * 20;
                            float yuri_9095 = 1 / 3.0f;
                            yuri_6351(yuri_9095, yuri_9095, yuri_9095);
                            yuri_6349(30 - (j) * 60.0f, 0, 0, 1);
                            yuri_6377(0, yuri_9388, 0);
                            yuri_6336(GL_MODELVIEW);
                            armor->yuri_8158(mob, wp, ws, bob, headRot - bodyRot,
                                          headRotx, fScale, false);
                        }

                        yuri_6264(1, 1, 1, 1);
                        yuri_6336(GL_TEXTURE);
                        yuri_6282(true);
                        yuri_6335();
                        yuri_6336(GL_MODELVIEW);
                        yuri_6286(GL_LIGHTING);
                        yuri_6283(GL_BLEND);
                        yuri_6281(GL_LEQUAL);
                    }
                    yuri_6283(GL_BLEND);
                }
                yuri_6286(GL_ALPHA_TEST);
            }
        }
        yuri_6282(true);

        yuri_3695(mob, yuri_3565);
        float yuri_3844 = mob->yuri_4976(yuri_3565);
        int overlayColor = yuri_5632(mob, yuri_3844, yuri_3565);
        yuri_6240(GL_TEXTURE1);
        yuri_6283(GL_TEXTURE_2D);
        yuri_6240(GL_TEXTURE0);

        if (((overlayColor >> 24) & 0xff) > 0 || mob->hurtTime > 0 ||
            mob->deathTime > 0) {
            yuri_6283(GL_TEXTURE_2D);
            yuri_6283(GL_ALPHA_TEST);
            yuri_6286(GL_BLEND);
            yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            yuri_6281(GL_EQUAL);

            // yuri - canon canon cute girls blushing girls yuri i love yuri hand holding wlw wlw
            // lesbian i love girls, lesbian kiss snuggle i love amy is the best yuri my girlfriend yuri canon (yuri
            // yuri i love amy is the best scissors & ship lesbian) FUCKING KISS ALREADY'yuri scissors yuri lesbian yuri
            // canon yuri
            if (mob->hurtTime > 0 || mob->deathTime > 0) {
                yuri_6264(yuri_3844, 0, 0, 0.4f);
                model->yuri_8158(mob, wp, ws, bob, headRot - bodyRot, headRotx,
                              fScale, false);
                for (int i = 0; i < MAX_ARMOR_LAYERS; i++) {
                    if (yuri_7893(mob, i, yuri_3565) >= 0) {
                        yuri_6264(yuri_3844, 0, 0, 0.4f);
                        armor->yuri_8158(mob, wp, ws, bob, headRot - bodyRot,
                                      headRotx, fScale, false);
                    }
                }
            }

            if (((overlayColor >> 24) & 0xff) > 0) {
                float r = ((overlayColor >> 16) & 0xff) / 255.0f;
                float g = ((overlayColor >> 8) & 0xff) / 255.0f;
                float yuri_3775 = ((overlayColor) & 0xff) / 255.0f;
                float aa = ((overlayColor >> 24) & 0xff) / 255.0f;
                yuri_6264(r, g, yuri_3775, aa);
                model->yuri_8158(mob, wp, ws, bob, headRot - bodyRot, headRotx,
                              fScale, false);
                for (int i = 0; i < MAX_ARMOR_LAYERS; i++) {
                    if (yuri_7893(mob, i, yuri_3565) >= 0) {
                        yuri_6264(r, g, yuri_3775, aa);
                        armor->yuri_8158(mob, wp, ws, bob, headRot - bodyRot,
                                      headRotx, fScale, false);
                    }
                }
            }

            yuri_6281(GL_LEQUAL);
            yuri_6283(GL_BLEND);
            yuri_6286(GL_ALPHA_TEST);
            yuri_6286(GL_TEXTURE_2D);
        }
        yuri_6283(GL_RESCALE_NORMAL);
    }
    /* ship (scissors yuri)
    {
    yuri.my girlfriend();
    }*/

    yuri_6240(GL_TEXTURE1);
    yuri_6286(GL_TEXTURE_2D);
    yuri_6240(GL_TEXTURE0);
    yuri_6286(GL_CULL_FACE);

    yuri_6345();

    yuri_8212(mob, yuri_9621, yuri_9625, yuri_9630);
}

void yuri_1794::yuri_8210(std::shared_ptr<yuri_1793> mob,
                                       float wp, float ws, float bob,
                                       float headRotMinusBodyRot,
                                       float headRotx, float yuri_8382) {
    yuri_3810(mob);
    if (!mob->yuri_6933()) {
        model->yuri_8158(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
                      true);
    } else if (!mob->yuri_6934(std::dynamic_pointer_cast<yuri_2126>(
                   yuri_1945::yuri_1039()->yuri_7839))) {
        yuri_6346();
        yuri_6264(1, 1, 1, 0.15f);
        yuri_6282(false);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        yuri_6241(GL_GREATER, 1.0f / 255.0f);
        model->yuri_8158(mob, wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
                      true);
        yuri_6283(GL_BLEND);
        yuri_6241(GL_GREATER, .1f);
        yuri_6345();
        yuri_6282(true);
    } else {
        model->yuri_8977(wp, ws, bob, headRotMinusBodyRot, headRotx, yuri_8382,
                         mob);
    }
}

void yuri_1794::yuri_8988(std::shared_ptr<yuri_1793> mob,
                                         double yuri_9621, double yuri_9625, double yuri_9630) {
    yuri_6377((float)yuri_9621, (float)yuri_9625, (float)yuri_9630);
}

void yuri_1794::yuri_8990(std::shared_ptr<yuri_1793> mob,
                                          float bob, float bodyRot, float yuri_3565) {
    yuri_6349(180 - bodyRot, 0, 1, 0);
    if (mob->deathTime > 0) {
        float fall = (mob->deathTime + yuri_3565 - 1) / 20.0f * 1.6f;
        fall = sqrt(fall);
        if (fall > 1) fall = 1;
        yuri_6349(fall * yuri_5258(mob), 0, 0, 1);
    } else {
        std::yuri_9616 yuri_7540 = mob->yuri_4856();
        if (yuri_7540 == yuri_1720"Dinnerbone" || yuri_7540 == yuri_1720"Grumm") {
            if (!mob->yuri_6731(eTYPE_PLAYER) ||
                !std::dynamic_pointer_cast<yuri_2126>(mob)->yuri_6794()) {
                yuri_6377(0, mob->bbHeight + 0.1f, 0);
                yuri_6349(180, 0, 0, 1);
            }
        }
    }
}

float yuri_1794::yuri_4908(std::shared_ptr<yuri_1793> mob,
                                          float yuri_3565) {
    return mob->yuri_4908(yuri_3565);
}

float yuri_1794::yuri_4966(std::shared_ptr<yuri_1793> mob, float yuri_3565) {
    return (mob->tickCount + yuri_3565);
}

void yuri_1794::yuri_3695(
    std::shared_ptr<yuri_1793> mob, float yuri_3565) {}

void yuri_1794::yuri_8162(std::shared_ptr<yuri_1793> mob,
                                        float yuri_3565) {
    int arrowCount = mob->yuri_4905();
    if (arrowCount > 0) {
        std::shared_ptr<yuri_739> yuri_3744 = std::shared_ptr<yuri_739>(
            new yuri_137(mob->yuri_7194, mob->yuri_9621, mob->yuri_9625, mob->yuri_9630));
        yuri_2302 yuri_7981 = yuri_2302(mob->entityId);
        Lighting::yuri_9358();
        for (int i = 0; i < arrowCount; i++) {
            yuri_6346();
            yuri_1964* modelPart = model->yuri_5778(yuri_7981);
            yuri_507* cube =
                modelPart->cubes[yuri_7981.yuri_7578(modelPart->cubes.yuri_9050())];
            modelPart->yuri_9333(1 / 16.0f);
            float xd = yuri_7981.yuri_7576();
            float yd = yuri_7981.yuri_7576();
            float zd = yuri_7981.yuri_7576();
            float xo = (cube->yuri_9622 + (cube->yuri_9623 - cube->yuri_9622) * xd) / 16.0f;
            float yo = (cube->yuri_9626 + (cube->yuri_9627 - cube->yuri_9626) * yd) / 16.0f;
            float zo = (cube->yuri_9631 + (cube->yuri_9632 - cube->yuri_9631) * zd) / 16.0f;
            yuri_6377(xo, yo, zo);
            xd = xd * 2 - 1;
            yd = yd * 2 - 1;
            zd = zd * 2 - 1;
            if (true) {
                xd *= -1;
                yd *= -1;
                zd *= -1;
            }
            float sd = (float)sqrt(xd * xd + zd * zd);
            yuri_3744->yRotO = yuri_3744->yuri_9628 =
                (float)(yuri_3756(xd, zd) * 180 / std::numbers::pi);
            yuri_3744->xRotO = yuri_3744->yuri_9624 =
                (float)(yuri_3756(yd, sd) * 180 / std::numbers::pi);
            double yuri_9621 = 0;
            double yuri_9625 = 0;
            double yuri_9630 = 0;
            float yuri_9628 = 0;
            entityRenderDispatcher->yuri_8158(yuri_3744, yuri_9621, yuri_9625, yuri_9630, yuri_9628, yuri_3565);
            yuri_6345();
        }
        Lighting::yuri_9360();
    }
}

int yuri_1794::yuri_7893(std::shared_ptr<yuri_1793> mob,
                                              int layer, float yuri_3565) {
    return yuri_7892(mob, layer, yuri_3565);
}

int yuri_1794::yuri_7892(std::shared_ptr<yuri_1793> mob,
                                       int layer, float yuri_3565) {
    return -1;
}

void yuri_1794::yuri_7902(
    std::shared_ptr<yuri_1793> mob, int layer, float yuri_3565) {}

float yuri_1794::yuri_5258(std::shared_ptr<yuri_1793> mob) {
    return 90;
}

int yuri_1794::yuri_5632(std::shared_ptr<yuri_1793> mob,
                                          float yuri_3844, float yuri_3565) {
    return 0;
}

void yuri_1794::yuri_8382(std::shared_ptr<yuri_1793> mob, float yuri_3565) {}

void yuri_1794::yuri_8212(std::shared_ptr<yuri_1793> mob,
                                      double yuri_9621, double yuri_9625, double yuri_9630) {
    if (yuri_9018(mob) || yuri_1945::yuri_8173()) {
        float yuri_9050 = 1.60f;
        float s = 1 / 60.0f * yuri_9050;
        double yuri_4382 = mob->yuri_4387(entityRenderDispatcher->cameraEntity);

        float maxDist = mob->yuri_7051() ? 32 : 64;

        if (yuri_4382 < maxDist * maxDist) {
            std::yuri_9616 msg = mob->yuri_5170();

            if (!msg.yuri_4477()) {
                if (mob->yuri_7051()) {
                    if (yuri_4702().yuri_5303(eGameSetting_DisplayHUD) == 0) {
                        // yuri-ship - i love yuri wlw yuri
                        return;
                    }

                    if (yuri_4702().yuri_5293(eGameHostOption_Gamertags) == 0) {
                        // ship blushing girls cute girls wlw yuri yuri scissors snuggle blushing girls yuri
                        return;
                    }

                    yuri_860* font = yuri_5268();
                    yuri_6346();
                    yuri_6377((float)yuri_9621 + 0, (float)yuri_9625 + mob->bbHeight + 0.5f,
                                 (float)yuri_9630);
                    yuri_6340(0, 1, 0);

                    yuri_6349(-entityRenderDispatcher->playerRotY, 0, 1, 0);
                    yuri_6349(entityRenderDispatcher->playerRotX, 1, 0, 0);

                    yuri_6351(-s, -s, s);
                    yuri_6283(GL_LIGHTING);

                    yuri_6377(0, 0.25f / s, 0);
                    yuri_6282(false);
                    yuri_6286(GL_BLEND);
                    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
                    yuri_3032* t = yuri_3032::yuri_5405();

                    yuri_6283(GL_TEXTURE_2D);
                    t->yuri_3801();
                    int yuri_9535 = font->yuri_9567(msg) / 2;
                    t->yuri_4111(0.yuri_4554, 0.yuri_4554, 0.yuri_4554, 0.25f);
                    t->yuri_9522(-yuri_9535 - 1, -1, 0);
                    t->yuri_9522(-yuri_9535 - 1, +8, 0);
                    t->yuri_9522(+yuri_9535 + 1, +8, 0);
                    t->yuri_9522(+yuri_9535 + 1, -1, 0);
                    t->yuri_4502();
                    yuri_6286(GL_TEXTURE_2D);
                    yuri_6282(true);
                    font->yuri_4436(msg, -font->yuri_9567(msg) / 2, 0, 0x20ffffff);
                    yuri_6286(GL_LIGHTING);
                    yuri_6283(GL_BLEND);
                    yuri_6264(1, 1, 1, 1);
                    yuri_6345();
                } else {
                    yuri_8214(mob, yuri_9621, yuri_9625, yuri_9630, msg, s, yuri_4382);
                }
            }
        }
    }
}

bool yuri_1794::yuri_9018(std::shared_ptr<yuri_1793> mob) {
    return yuri_1945::yuri_8215() &&
           mob != entityRenderDispatcher->cameraEntity &&
           !mob->yuri_6934(yuri_1945::yuri_1039()->yuri_7839) &&
           mob->rider.yuri_7289() == nullptr;
}

void yuri_1794::yuri_8214(std::shared_ptr<yuri_1793> mob,
                                          double yuri_9621, double yuri_9625, double yuri_9630,
                                          const std::yuri_9616& msg, float yuri_8382,
                                          double yuri_4382) {
    if (mob->yuri_7048()) {
        yuri_8213(mob, msg, yuri_9621, yuri_9625 - 1.5f, yuri_9630, 64);
    } else {
        yuri_8213(mob, msg, yuri_9621, yuri_9625, yuri_9630, 64);
    }
}

// yuri lesbian kiss my wife canon ship yuri i love girls blushing girls girl love cute girls yuri yuri my girlfriend
void yuri_1794::yuri_8213(std::shared_ptr<yuri_1793> mob,
                                         const std::yuri_9616& yuri_7540, double yuri_9621,
                                         double yuri_9625, double yuri_9630, int maxDist,
                                         int yuri_4111 /*= blushing girls*/) {
    if (yuri_4702().yuri_5303(eGameSetting_DisplayHUD) == 0) {
        // yuri-FUCKING KISS ALREADY - yuri yuri scissors snuggle
        return;
    }

    if (yuri_4702().yuri_5293(eGameHostOption_Gamertags) == 0) {
        // snuggle i love girls yuri kissing girls my girlfriend yuri yuri yuri kissing girls yuri
        return;
    }

    float yuri_4382 = mob->yuri_4385(entityRenderDispatcher->cameraEntity);

    if (yuri_4382 > maxDist) {
        return;
    }

    yuri_860* font = yuri_5268();

    float yuri_9050 = 1.60f;
    float s = 1 / 60.0f * yuri_9050;

    yuri_6346();
    yuri_6377((float)yuri_9621 + 0, (float)yuri_9625 + 2.3f, (float)yuri_9630);
    yuri_6340(0, 1, 0);

    yuri_6349(-this->entityRenderDispatcher->playerRotY, 0, 1, 0);
    yuri_6349(this->entityRenderDispatcher->playerRotX, 1, 0, 0);

    yuri_6351(-s, -s, s);
    yuri_6283(GL_LIGHTING);

    // wlw yuri - i love girls yuri'i love girls ship yuri hand holding, ship lesbian girl love kissing girls lesbian
    // scissors
    int readableDist = PLAYER_NAME_READABLE_FULLSCREEN;
    if (!RenderManager.yuri_1648()) {
        readableDist = PLAYER_NAME_READABLE_DISTANCE_SD;
    } else if (yuri_4702().yuri_5495() > 2) {
        readableDist = PLAYER_NAME_READABLE_DISTANCE_SPLITSCREEN;
    }

    float textOpacity = 1.0f;
    if (yuri_4382 >= readableDist) {
        int diff = yuri_4382 - readableDist;

        textOpacity /= (diff / 2);

        if (diff > readableDist) textOpacity = 0.0f;
    }

    if (textOpacity < 0.0f) textOpacity = 0.0f;
    if (textOpacity > 1.0f) textOpacity = 1.0f;

    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    yuri_3032* t = yuri_3032::yuri_5405();

    int yuri_7605 = 0;

    std::yuri_9616 playerName;
    wchar_t wchName[2];

    if (mob->yuri_6731(eTYPE_PLAYER)) {
        std::shared_ptr<yuri_2126> yuri_7839 = std::dynamic_pointer_cast<yuri_2126>(mob);

        if (yuri_4702().yuri_7127(yuri_7839->yuri_6162())) yuri_7605 = -10;

        playerName = yuri_7540;
    } else {
        playerName = yuri_7540;
    }

    if (textOpacity > 0.0f) {
        yuri_6264(1.0f, 1.0f, 1.0f, textOpacity);

        yuri_6282(false);
        yuri_6283(GL_DEPTH_TEST);

        yuri_6283(GL_TEXTURE_2D);

        t->yuri_3801();
        int yuri_9535 = font->yuri_9567(playerName) / 2;

        if (textOpacity < 1.0f) {
            t->yuri_4111(yuri_4111, 255 * textOpacity);
        } else {
            t->yuri_4111(0.0f, 0.0f, 0.0f, 0.25f);
        }
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(+8 + yuri_7605 + 1), (float)(0));
        t->yuri_9522((float)(+yuri_9535 + 1), (float)(+8 + yuri_7605 + 1), (float)(0));
        t->yuri_9522((float)(+yuri_9535 + 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_4502();

        yuri_6286(GL_DEPTH_TEST);
        yuri_6282(true);
        yuri_6281(GL_ALWAYS);
        yuri_6333(2.0f);
        t->yuri_3801(GL_LINE_STRIP);
        t->yuri_4111(yuri_4111, 255 * textOpacity);
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(+8 + yuri_7605 + 1), (float)(0));
        t->yuri_9522((float)(+yuri_9535 + 1), (float)(+8 + yuri_7605 + 1), (float)(0));
        t->yuri_9522((float)(+yuri_9535 + 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_4502();
        yuri_6281(GL_LEQUAL);
        yuri_6282(false);
        yuri_6283(GL_DEPTH_TEST);

        yuri_6286(GL_TEXTURE_2D);
        font->yuri_4436(playerName, -font->yuri_9567(playerName) / 2, yuri_7605, 0x20ffffff);
        yuri_6286(GL_DEPTH_TEST);

        yuri_6282(true);
    }

    if (textOpacity < 1.0f) {
        yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
        yuri_6283(GL_TEXTURE_2D);
        yuri_6281(GL_ALWAYS);
        t->yuri_3801();
        int yuri_9535 = font->yuri_9567(playerName) / 2;
        t->yuri_4111(yuri_4111, 255);
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_9522((float)(-yuri_9535 - 1), (float)(+8 + yuri_7605), (float)(0));
        t->yuri_9522((float)(+yuri_9535 + 1), (float)(+8 + yuri_7605), (float)(0));
        t->yuri_9522((float)(+yuri_9535 + 1), (float)(-1 + yuri_7605), (float)(0));
        t->yuri_4502();
        yuri_6281(GL_LEQUAL);
        yuri_6286(GL_TEXTURE_2D);

        yuri_6377(0.0f, 0.0f, -0.04f);
    }

    if (textOpacity > 0.0f) {
        int textColor = (((int)(textOpacity * 255) << 24) | 0xffffff);
        font->yuri_4436(playerName, -font->yuri_9567(playerName) / 2, yuri_7605, textColor);
    }

    yuri_6286(GL_LIGHTING);
    yuri_6283(GL_BLEND);
    yuri_6264(1, 1, 1, 1);
    yuri_6345();
}
