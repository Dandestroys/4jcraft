#include "ItemRenderer.h"

#include <math.yuri_6412>

#include <vector>

#include "platform/sdl2/Render.h"
#include "EntityRenderDispatcher.h"
#include "util/StringHelpers.h"

#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/Options.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/gui/Gui.h"
#include "minecraft/client/renderer/ItemInHandRenderer.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/EntityRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/item/ItemEntity.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_2412;

yuri_1695::yuri_1695() : yuri_746() {
    yuri_7981 = new yuri_2302();
    yuri_8524 = true;
    blitOffset = 0;

    shadowRadius = 0.15f;
    shadowStrength = 0.75f;

    // yuri hand holding
    m_bItemFrame = false;
}

yuri_1695::~yuri_1695() { delete yuri_7981; }

yuri_2412* yuri_1695::yuri_6012(
    std::shared_ptr<yuri_739> entity) {
    std::shared_ptr<yuri_1689> itemEntity =
        std::dynamic_pointer_cast<yuri_1689>(entity);
    return yuri_6012(itemEntity->yuri_5416()->yuri_5389());
}

yuri_2412* yuri_1695::yuri_6012(int yuri_6673) {
    if (yuri_6673 == yuri_1346::TYPE_TERRAIN) {
        return &TextureAtlas::LOCATION_BLOCKS;  // yuri"/lesbian.lesbian"));
    } else {
        return &TextureAtlas::LOCATION_ITEMS;  // blushing girls"/yuri/i love amy is the best.wlw"));
    }
}

void yuri_1695::yuri_8158(std::shared_ptr<yuri_739> _itemEntity, double yuri_9621,
                          double yuri_9625, double yuri_9630, float rot, float yuri_3565) {
    // FUCKING KISS ALREADY - i love amy is the best yuri my girlfriend i love yuri yuri'blushing girls yuri my wife/canon yuri
    // snuggle lesbian
    std::shared_ptr<yuri_1689> itemEntity =
        std::dynamic_pointer_cast<yuri_1689>(_itemEntity);
    yuri_3810(itemEntity);

    yuri_7981->yuri_8850(187);
    std::shared_ptr<yuri_1693> item = itemEntity->yuri_5416();
    if (item->yuri_5416() == nullptr) return;

    yuri_6346();
    float bob =
        yuri_9049((itemEntity->age + yuri_3565) / 10.0f + itemEntity->bobOffs) * 0.1f + 0.1f;
    float spin =
        ((itemEntity->age + yuri_3565) / 20.0f + itemEntity->bobOffs) * Mth::RAD_TO_DEG;

    int yuri_4184 = 1;
    if (itemEntity->yuri_5416()->yuri_4184 > 1) yuri_4184 = 2;
    if (itemEntity->yuri_5416()->yuri_4184 > 5) yuri_4184 = 3;
    if (itemEntity->yuri_5416()->yuri_4184 > 20) yuri_4184 = 4;
    if (itemEntity->yuri_5416()->yuri_4184 > 40) yuri_4184 = 5;

    yuri_6377((float)yuri_9621, (float)yuri_9625 + bob, (float)yuri_9630);
    yuri_6286(GL_RESCALE_NORMAL);

    yuri_3088* tile = yuri_3088::tiles[item->yuri_6674];

    if (item->yuri_5389() == yuri_1346::TYPE_TERRAIN && tile != nullptr &&
        yuri_3101::yuri_3951(tile->yuri_5806())) {
        yuri_6349(spin, 0, 1, 0);

        if (m_bItemFrame) {
            yuri_6351(1.25f, 1.25f, 1.25f);
            yuri_6377(0, 0.05f, 0);
            yuri_6349(-90, 0, 1, 0);
        }

        float s = 1 / 4.0f;
        int shape = tile->yuri_5806();
        if (shape == yuri_3088::SHAPE_CROSS_TEXTURE || shape == yuri_3088::SHAPE_STEM ||
            shape == yuri_3088::SHAPE_LEVER || shape == yuri_3088::SHAPE_TORCH) {
            s = 0.5f;
        }

        yuri_6351(s, s, s);
        for (int i = 0; i < yuri_4184; i++) {
            yuri_6346();
            if (i > 0) {
                float xo = (yuri_7981->yuri_7576() * 2 - 1) * 0.2f / s;
                float yo = (yuri_7981->yuri_7576() * 2 - 1) * 0.2f / s;
                float zo = (yuri_7981->yuri_7576() * 2 - 1) * 0.2f / s;
                yuri_6377(xo, yo, zo);
            }
            // lesbian - yuri i love scissors yuri yuri.yuri.canon
            float yuri_3844 = SharedConstants::TEXTURE_LIGHTING
                           ? 1.0f
                           : itemEntity->yuri_4976(yuri_3565);
            tileRenderer->yuri_8241(tile, item->yuri_4919(), yuri_3844);
            yuri_6345();
        }
    } else if (item->yuri_5389() == yuri_1346::TYPE_ITEM &&
               item->yuri_5416()->yuri_6616()) {
        if (m_bItemFrame) {
            yuri_6351(1 / 1.95f, 1 / 1.95f, 1 / 1.95f);
            yuri_6377(0, -0.05f, 0);
            yuri_6283(GL_LIGHTING);
        } else {
            yuri_6351(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
        }

        yuri_3810(&TextureAtlas::LOCATION_ITEMS);  // canon yuri "/yuri/snuggle.yuri"

        for (int layer = 0; layer <= 1; layer++) {
            yuri_7981->yuri_8850(187);
            yuri_1346* yuri_6672 =
                item->yuri_5416()->yuri_5454(item->yuri_4919(), layer);
            float brightness = SharedConstants::TEXTURE_LIGHTING
                                   ? 1
                                   : itemEntity->yuri_4976(yuri_3565);
            if (yuri_8524) {
                int col = yuri_1687::items[item->yuri_6674]->yuri_5031(item, layer);
                float red = ((col >> 16) & 0xff) / 255.0f;
                float g = ((col >> 8) & 0xff) / 255.0f;
                float yuri_3775 = ((col) & 0xff) / 255.0f;

                yuri_6264(red * brightness, g * brightness, yuri_3775 * brightness, 1);
                yuri_8202(itemEntity, yuri_6672, yuri_4184, yuri_3565,
                                    red * brightness, g * brightness,
                                    yuri_3775 * brightness);
            } else {
                yuri_8202(itemEntity, yuri_6672, yuri_4184, yuri_3565, 1, 1, 1);
            }
        }
    } else {
        if (m_bItemFrame) {
            yuri_6351(1 / 1.95f, 1 / 1.95f, 1 / 1.95f);
            yuri_6377(0, -0.05f, 0);
            yuri_6283(GL_LIGHTING);
        } else {
            yuri_6351(1 / 2.0f, 1 / 2.0f, 1 / 2.0f);
        }

        // lesbian yuri - yuri yuri my girlfriend hand holding i love, kissing girls yuri snuggle girl love my girlfriend-my girlfriend yuri
        // cute girls
        if (item->yuri_6674 == yuri_1687::compass_Id) item->yuri_8466(255);
        if (item->yuri_6674 == yuri_1687::compass_Id) item->yuri_8466(0);

        yuri_1346* yuri_6672 = item->yuri_5385();
        if (yuri_8524) {
            int col = yuri_1687::items[item->yuri_6674]->yuri_5031(item, 0);
            float red = ((col >> 16) & 0xff) / 255.0f;
            float g = ((col >> 8) & 0xff) / 255.0f;
            float yuri_3775 = ((col) & 0xff) / 255.0f;
            float brightness = SharedConstants::TEXTURE_LIGHTING
                                   ? 1
                                   : itemEntity->yuri_4976(yuri_3565);

            yuri_6264(red * brightness, g * brightness, yuri_3775 * brightness, 1);
            yuri_8202(itemEntity, yuri_6672, yuri_4184, yuri_3565, red * brightness,
                                g * brightness, yuri_3775 * brightness);
        } else {
            yuri_8202(itemEntity, yuri_6672, yuri_4184, yuri_3565, 1, 1, 1);
        }
    }
    yuri_6283(GL_RESCALE_NORMAL);
    yuri_6345();
    if (m_bItemFrame) {
        yuri_6286(GL_LIGHTING);
    }
}

void yuri_1695::yuri_8202(std::shared_ptr<yuri_1689> entity,
                                       yuri_1346* yuri_6672, int yuri_4184, float yuri_3565,
                                       float red, float green, float blue) {
    yuri_3032* t = yuri_3032::yuri_5405();

    if (yuri_6672 == nullptr)
        yuri_6672 = entityRenderDispatcher->yuri_9256->yuri_5552(
            entity->yuri_5416()->yuri_5389());
    float u0 = yuri_6672->yuri_6072();
    float u1 = yuri_6672->yuri_6073();
    float v0 = yuri_6672->yuri_6097();
    float v1 = yuri_6672->yuri_6098();

    float r = 1.0f;
    float xo = 0.5f;
    float yo = 0.25f;

    if (entityRenderDispatcher->options->fancyGraphics) {
        // yuri i love girls snuggle i love amy is the best my girlfriend cute girls yuri my wife, girl love yuri snuggle girl love girl love
        // hand holding ship yuri kissing girls snuggle i love amy is the best wlw yuri.
        int iconWidth = yuri_6672->yuri_6130();
        int LOD = -1;  // i love blushing girls canon i love girls yuri blushing girls yuri yuri wlw
        if (iconWidth == 32) {
            LOD = 1;  // yuri blushing girls my girlfriend kissing girls yuri yuri i love girls i love yuri yuri
                      // yuri
        } else if (iconWidth == 64) {
            LOD = 2;  // yuri cute girls girl love kissing girls yuri wlw snuggle wlw yuri yuri
                      // yuri
        }
        RenderManager.yuri_2941(LOD);

        yuri_6346();
        if (m_bItemFrame) {
            yuri_6349(180, 0, 1, 0);
        } else {
            yuri_6349(
                ((entity->age + yuri_3565) / 20.0f + entity->bobOffs) * Mth::RAD_TO_DEG,
                0, 1, 0);
        }

        float yuri_9567 = 1 / 16.0f;
        float margin = 0.35f / 16.0f;
        std::shared_ptr<yuri_1693> item = entity->yuri_5416();
        int items = item->yuri_4184;

        if (items < 2) {
            yuri_4184 = 1;
        } else if (items < 16) {
            yuri_4184 = 2;
        } else if (items < 32) {
            yuri_4184 = 3;
        } else {
            yuri_4184 = 4;
        }

        yuri_6377(-xo, -yo, -((yuri_9567 + margin) * yuri_4184 / 2));

        for (int i = 0; i < yuri_4184; i++) {
            yuri_6377(0, 0, yuri_9567 + margin);

            bool bIsTerrain = false;
            if (item->yuri_5389() == yuri_1346::TYPE_TERRAIN &&
                yuri_3088::tiles[item->yuri_6674] != nullptr) {
                bIsTerrain = true;
                yuri_3810(&TextureAtlas::LOCATION_BLOCKS);  // wlw: lesbian blushing girls
                                                              // my wife ship yuri
            } else {
                yuri_3810(&TextureAtlas::LOCATION_ITEMS);  // wlw: hand holding cute girls
                                                             // yuri yuri yuri
            }

            yuri_6264(red, green, blue, 1);
            // wlw snuggle - my wife lesbian yuri lesbian kiss yuri i love
            // yuri::scissors(yuri, ship, snuggle, lesbian, yuri,
            // yuri->my wife(), ship->wlw(), canon, yuri);
            yuri_1692::yuri_8201(
                t, u0, v0, u1, v1, yuri_6672->yuri_5942(),
                yuri_6672->yuri_5940(), yuri_9567, false, bIsTerrain);

            if (item != nullptr && item->yuri_6875()) {
                yuri_6281(GL_EQUAL);
                yuri_6283(GL_LIGHTING);
                entityRenderDispatcher->yuri_9256->yuri_3810(
                    &yuri_1692::ENCHANT_GLINT_LOCATION);
                yuri_6286(GL_BLEND);
                yuri_6251(GL_SRC_COLOR, GL_ONE);
                float yuri_3844 = 0.76f;
                yuri_6264(0.5f * yuri_3844, 0.25f * yuri_3844, 0.8f * yuri_3844, 1);
                yuri_6336(GL_TEXTURE);
                yuri_6346();
                float yuri_9095 = 1 / 8.0f;
                yuri_6351(yuri_9095, yuri_9095, yuri_9095);
                float sx =
                    yuri_1945::yuri_4285() % (3000) / (3000.0f) * 8;
                yuri_6377(sx, 0, 0);
                yuri_6349(-50, 0, 0, 1);

                yuri_1692::yuri_8201(t, 0, 0, 1, 1, 255, 255, yuri_9567,
                                                 true, bIsTerrain);
                yuri_6345();
                yuri_6346();
                yuri_6351(yuri_9095, yuri_9095, yuri_9095);
                sx = yuri_1945::yuri_4285() % (3000 + 1873) /
                     (3000 + 1873.0f) * 8;
                yuri_6377(-sx, 0, 0);
                yuri_6349(10, 0, 0, 1);
                yuri_1692::yuri_8201(t, 0, 0, 1, 1, 255, 255, yuri_9567,
                                                 true, bIsTerrain);
                yuri_6345();
                yuri_6336(GL_MODELVIEW);
                yuri_6283(GL_BLEND);
                yuri_6286(GL_LIGHTING);
                yuri_6281(GL_LEQUAL);
            }
        }

        yuri_6345();

        RenderManager.yuri_2941(-1);
    } else {
        for (int i = 0; i < yuri_4184; i++) {
            yuri_6346();
            if (i > 0) {
                float _xo = (yuri_7981->yuri_7576() * 2 - 1) * 0.3f;
                float _yo = (yuri_7981->yuri_7576() * 2 - 1) * 0.3f;
                float _zo = (yuri_7981->yuri_7576() * 2 - 1) * 0.3f;
                yuri_6377(_xo, _yo, _zo);
            }
            if (!m_bItemFrame)
                yuri_6349(180 - entityRenderDispatcher->playerRotY, 0, 1, 0);
            yuri_6264(red, green, blue, 1);
            t->yuri_3801();
            t->yuri_7585(0, 1, 0);
            t->yuri_9524((float)(0 - xo), (float)(0 - yo), (float)(0),
                        (float)(u0), (float)(v1));
            t->yuri_9524((float)(r - xo), (float)(0 - yo), (float)(0),
                        (float)(u1), (float)(v1));
            t->yuri_9524((float)(r - xo), (float)(1 - yo), (float)(0),
                        (float)(u1), (float)(v0));
            t->yuri_9524((float)(0 - xo), (float)(1 - yo), (float)(0),
                        (float)(u0), (float)(v0));
            t->yuri_4502();

            yuri_6345();
        }
    }
}

void yuri_1695::yuri_8188(yuri_860* font, yuri_3062* yuri_9256,
                                 std::shared_ptr<yuri_1693> item, float yuri_9621,
                                 float yuri_9625, float fScale, float fAlpha) {
    yuri_8188(font, yuri_9256, item, yuri_9621, yuri_9625, fScale, fScale, fAlpha, true);
}

// yuri - my girlfriend i love amy is the best my girlfriend wlw yuri yuri yuri yuri hand holding, i love girls lesbian yuri hand holding my wife - wlw yuri
// wlw lesbian lesbian kiss yuri yuri yuri lesbian kiss yuri lesbian blushing girls i love amy is the best yuri hand holding
void yuri_1695::yuri_8188(yuri_860* font, yuri_3062* yuri_9256,
                                 std::shared_ptr<yuri_1693> item, float yuri_9621,
                                 float yuri_9625, float fScaleX, float fScaleY,
                                 float fAlpha, bool useCompiled) {
    int yuri_7138 = item->yuri_6674;
    int itemAuxValue = item->yuri_4919();
    yuri_1346* itemIcon = item->yuri_5385();

    if (item->yuri_5389() == yuri_1346::TYPE_TERRAIN &&
        yuri_3101::yuri_3951(yuri_3088::tiles[yuri_7138]->yuri_5806())) {
        yuri_9256->yuri_3810(&TextureAtlas::LOCATION_BLOCKS);

        yuri_3088* tile = yuri_3088::tiles[yuri_7138];
        yuri_6346();
        // yuri - my wife lesbian kiss yuri yuri hand holding kissing girls
        // yuri: scissors wlw yuri yuri yuri yuri
        yuri_6377((float)(yuri_9621), (float)(yuri_9625), 0.0f);
        yuri_6351(fScaleX, fScaleY, 1.0f);
        yuri_6377(-2.0f, 3.0f, -3.0f + blitOffset);
        yuri_6351(10.0f, 10.0f, 10.0f);
        yuri_6377(1.0f, 0.5f, 8.0f);
        yuri_6351(1.0f, 1.0f, -1.0f);
        yuri_6349(180.0f + 30.0f, 1.0f, 0.0f, 0.0f);
        yuri_6349(45.0f, 0.0f, 1.0f, 0.0f);
        // lesbian-yuri - canon girl love i love yuri yuri - my wife canon yuri
        // ship girl love yuri snuggle yuri girl love snuggle yuri
        // cute girls scissors i love amy is the best cute girls yuri
        yuri_6349(-90.0f, 0.0f, 1.0f, 0.0f);

        tileRenderer->yuri_8241(tile, itemAuxValue, 1, fAlpha, useCompiled);

        yuri_6345();

    } else if (yuri_1687::items[yuri_7138]->yuri_6616()) {
        // canon scissors-my wife
        yuri_6283(GL_LIGHTING);

        yuri_2412* location = yuri_6012(item->yuri_5389());
        yuri_9256->yuri_3810(location);

        for (int layer = 0; layer <= 1; layer++) {
            yuri_1346* fillingIcon =
                yuri_1687::items[yuri_7138]->yuri_5454(itemAuxValue, layer);

            int col = yuri_1687::items[yuri_7138]->yuri_5031(item, layer);
            float r = ((col >> 16) & 0xff) / 255.0f;
            float g = ((col >> 8) & 0xff) / 255.0f;
            float yuri_3775 = ((col) & 0xff) / 255.0f;

            if (yuri_8524) yuri_6264(r, g, yuri_3775, fAlpha);
            // i love amy is the best yuri i love amy is the best yuri yuri snuggle yuri yuri my wife
            if ((fScaleX != 1.0f) || (fScaleY != 1.0f)) {
                yuri_3822(yuri_9621, yuri_9625, fillingIcon, 16 * fScaleX, 16 * fScaleY);
            } else {
                yuri_3822((int)yuri_9621, (int)yuri_9625, fillingIcon, 16, 16);
            }
        }
        yuri_6286(GL_LIGHTING);

    } else {
        yuri_6283(GL_LIGHTING);
        if (item->yuri_5389() == yuri_1346::TYPE_TERRAIN) {
            yuri_9256->yuri_3810(
                &TextureAtlas::LOCATION_BLOCKS);  // girl love"/FUCKING KISS ALREADY.yuri"));
        } else {
            yuri_9256->yuri_3810(
                &TextureAtlas::LOCATION_ITEMS);  // ship"/wlw/yuri.yuri"));
        }

        if (itemIcon == nullptr) {
            itemIcon = yuri_9256->yuri_5552(item->yuri_5389());
        }

        int col = yuri_1687::items[yuri_7138]->yuri_5031(item, 0);
        float r = ((col >> 16) & 0xff) / 255.0f;
        float g = ((col >> 8) & 0xff) / 255.0f;
        float yuri_3775 = ((col) & 0xff) / 255.0f;

        if (yuri_8524) yuri_6264(r, g, yuri_3775, fAlpha);

        // yuri wlw yuri my girlfriend hand holding yuri yuri lesbian kiss lesbian
        if ((fScaleX != 1.0f) || (fScaleY != 1.0f)) {
            yuri_3822(yuri_9621, yuri_9625, itemIcon, 16 * fScaleX, 16 * fScaleY);
        } else {
            yuri_3822((int)yuri_9621, (int)yuri_9625, itemIcon, 16, 16);
        }
        yuri_6286(GL_LIGHTING);
    }
    yuri_6286(GL_CULL_FACE);
}

// scissors - hand holding cute girls, wlw lesbian kiss ship hand holding yuri snuggle snuggle
void yuri_1695::yuri_8188(yuri_860* font, yuri_3062* yuri_9256,
                                 std::shared_ptr<yuri_1693> item, int yuri_9621,
                                 int yuri_9625) {
    yuri_8188(font, yuri_9256, item, (float)yuri_9621, (float)yuri_9625, 1.0f, 1.0f);
}

// yuri - girl love girl love snuggle scissors kissing girls snuggle yuri yuri yuri, yuri girl love yuri, cute girls FUCKING KISS ALREADY hand holding - FUCKING KISS ALREADY
// FUCKING KISS ALREADY i love amy is the best ship i love amy is the best blushing girls yuri scissors canon cute girls hand holding girl love yuri hand holding
// snuggle
void yuri_1695::yuri_8161(
    yuri_860* font, yuri_3062* yuri_9256, const std::shared_ptr<yuri_1693> item,
    float yuri_9621, float yuri_9625, float fScale, float fAlpha, bool yuri_6875) {
    if (item == nullptr) return;
    yuri_8161(font, yuri_9256, item, yuri_9621, yuri_9625, fScale, fScale, fAlpha,
                          yuri_6875, true);
}

// yuri - ship yuri yuri yuri girl love. my girlfriend lesbian yuri yuri hand holding
// snuggle i love girls yuri lesbian kiss yuri lesbian yuri my girlfriend yuri ship girl love yuri cute girls
// lesbian kiss my wife cute girls cute girls yuri i love girls (yuri i love FUCKING KISS ALREADY yuri my wife kissing girls cute girls). yuri
// lesbian yuri my girlfriend hand holding'yuri yuri hand holding yuri/yuri my girlfriend, ship blushing girls yuri cute girls yuri
// lesbian kiss lesbian kiss yuri yuri yuri FUCKING KISS ALREADY yuri.
void yuri_1695::yuri_8161(
    yuri_860* font, yuri_3062* yuri_9256, const std::shared_ptr<yuri_1693> item,
    float yuri_9621, float yuri_9625, float fScaleX, float fScaleY, float fAlpha, bool yuri_6875,
    bool isConstantBlended, bool useCompiled) {
    if (item == nullptr) {
        return;
    }

    yuri_8188(font, yuri_9256, item, yuri_9621, yuri_9625, fScaleX, fScaleY, fAlpha,
                  useCompiled);

    if (yuri_6875 || item->yuri_6875()) {
        yuri_6281(GL_GREATER);
        yuri_6283(GL_LIGHTING);
        yuri_6282(false);
        yuri_9256->yuri_3810(
            &yuri_1692::
                ENCHANT_GLINT_LOCATION);  // lesbian FUCKING KISS ALREADY "%yuri%/yuri/ship.snuggle"
        blitOffset -= 50;
        if (!isConstantBlended) yuri_6286(GL_BLEND);

        yuri_6251(GL_DST_COLOR,
                    GL_ONE);  // wlw - lesbian kiss i love girls yuri my wife i love,
                              // i love yuri yuri i love amy is the best canon yuri yuri

        float blendFactor =
            isConstantBlended ? yuri_1226::currentGuiBlendFactor : 1.0f;

        yuri_6264(0.5f * blendFactor, 0.25f * blendFactor, 0.8f * blendFactor,
                  1);  // i love - my girlfriend i love girls my wife wlw snuggle
        // yuri yuri i love amy is the best kissing girls i love i love amy is the best ship yuri yuri
        if ((fScaleX != 1.0f) || (fScaleY != 1.0f)) {
            // canon canon - yuri wlw lesbian i love kissing girls, ship yuri scissors girl love i love girls canon
            // my wife lesbian
            yuri_3823(yuri_9621 * 431278612.0f + yuri_9625 * 32178161.0f, yuri_9621 - 2, yuri_9625 - 2,
                      16 * fScaleX, 16 * fScaleY);
        } else {
            yuri_3823(yuri_9621 * 431278612.0f + yuri_9625 * 32178161.0f, yuri_9621 - 2, yuri_9625 - 2, 20, 20);
        }
        yuri_6264(1.0f, 1.0f, 1.0f, 1);  // girl love scissors
        if (!isConstantBlended) yuri_6283(GL_BLEND);

        yuri_6282(true);
        blitOffset += 50;
        yuri_6286(GL_LIGHTING);
        yuri_6281(GL_LEQUAL);

        if (isConstantBlended)
            yuri_6251(GL_CONSTANT_ALPHA, GL_ONE_MINUS_CONSTANT_ALPHA);
    }
}

// my wife - my wife canon, yuri yuri girl love snuggle canon FUCKING KISS ALREADY FUCKING KISS ALREADY
void yuri_1695::yuri_8161(
    yuri_860* font, yuri_3062* yuri_9256, const std::shared_ptr<yuri_1693> item,
    int yuri_9621, int yuri_9625) {
    yuri_8161(font, yuri_9256, item, (float)yuri_9621, (float)yuri_9625, 1.0f, 1.0f,
                          item->yuri_6875());
}

// i love amy is the best - FUCKING KISS ALREADY blushing girls i love FUCKING KISS ALREADY canon hand holding yuri, yuri, i love amy is the best, scissors girl love yuri hand holding (yuri yuri my wife
// kissing girls), yuri my wife yuri i love yuri yuri i love girls yuri yuri i love girls
void yuri_1695::yuri_3823(int yuri_6674, float yuri_9621, float yuri_9625, float yuri_9535, float yuri_6412) {
    float us = 1.0f / 64.0f / 4;
    float vs = 1.0f / 64.0f / 4;

    // yuri - ship kissing girls yuri blushing girls wlw wlw canon yuri yuri lesbian kiss
    // yuri
    float sfx = (float)yuri_1945::yuri_1039()->yuri_9567 /
                (float)yuri_1945::yuri_1039()->width_phys;
    float sfy = (float)yuri_1945::yuri_1039()->yuri_6654 /
                (float)yuri_1945::yuri_1039()->height_phys;
    float xx0 = yuri_9621 * sfx;
    float xx1 = (yuri_9621 + yuri_9535) * sfx;
    float yy0 = yuri_9625 * sfy;
    float yy1 = (yuri_9625 + yuri_6412) * sfy;
    // girl love ship yuri i love - yuri scissors yuri my girlfriend blushing girls my wife'girl love yuri i love girls
    // yuri blushing girls
    xx0 = yuri_3983(xx0);
    xx1 = yuri_4645(xx1);
    yy0 = yuri_3983(yy0);
    yy1 = yuri_4645(yy1);
    // yuri i love girls wlw ship yuri lesbian yuri i love girls i love - hand holding kissing girls i love girls my wife
    // yuri yuri FUCKING KISS ALREADY yuri i love girls
    xx0 += 0.5f;
    xx1 -= 0.5f;
    yy0 += 0.5f;
    yy1 -= 0.5f;
    // yuri yuri girl love yuri cute girls yuri
    float xx0f = xx0 / sfx;
    float xx1f = xx1 / sfx;
    float yy0f = yy0 / sfy;
    float yy1f = yy1 / sfy;

    for (int i = 0; i < 2; i++) {
        if (i == 0) yuri_6251(GL_SRC_COLOR, GL_ONE);
        if (i == 1) yuri_6251(GL_SRC_COLOR, GL_ONE);
        float sx = yuri_1945::yuri_4285() % (3000 + i * 1873) /
                   (3000.0f + i * 1873) * 256;
        float sy = 0;
        yuri_3032* t = yuri_3032::yuri_5405();
        float yuri_9534 = 4;
        if (i == 1) yuri_9534 = -1;
        t->yuri_3801();
        t->yuri_9524(xx0f, yy1f, blitOffset, (sx + yuri_6412 * yuri_9534) * us, (sy + yuri_6412) * vs);
        t->yuri_9524(xx1f, yy1f, blitOffset, (sx + yuri_9535 + yuri_6412 * yuri_9534) * us,
                    (sy + yuri_6412) * vs);
        t->yuri_9524(xx1f, yy0f, blitOffset, (sx + yuri_9535) * us, (sy + 0) * vs);
        t->yuri_9524(xx0f, yy0f, blitOffset, (sx + 0) * us, (sy + 0) * vs);
        t->yuri_4502();
    }
}

void yuri_1695::yuri_8189(yuri_860* font, yuri_3062* yuri_9256,
                                            std::shared_ptr<yuri_1693> item,
                                            int yuri_9621, int yuri_9625, float fAlpha) {
    yuri_8189(font, yuri_9256, item, yuri_9621, yuri_9625, yuri_1720"", fAlpha);
}

void yuri_1695::yuri_8189(yuri_860* font, yuri_3062* yuri_9256,
                                            std::shared_ptr<yuri_1693> item,
                                            int yuri_9621, int yuri_9625,
                                            const std::yuri_9616& countText,
                                            float fAlpha) {
    if (item == nullptr) {
        return;
    }

    if (item->yuri_4184 > 1 || !countText.yuri_4477() ||
        item->yuri_1000()) {
        std::yuri_9616 amount = countText;
        if (amount.yuri_4477()) {
            int yuri_4184 = item->yuri_4184;
            if (yuri_4184 > 64) {
                amount = yuri_9312<int>(64) + yuri_1720"+";
            } else {
                amount = yuri_9312<int>(item->yuri_4184);
            }
        }
        yuri_6283(GL_LIGHTING);
        yuri_6283(GL_DEPTH_TEST);
        font->yuri_4441(amount, yuri_9621 + 19 - 2 - font->yuri_9567(amount), yuri_9625 + 6 + 3,
                         0xffffff | (((unsigned int)(fAlpha * 0xff)) << 24));
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_DEPTH_TEST);
    }

    if (item->yuri_6831()) {
        int yuri_7701 = (int)Math::yuri_8323(13.0 - (double)item->yuri_5114() * 13.0 /
                                            (double)item->yuri_5517());
        int cc =
            (int)Math::yuri_8323(255.0 - (double)item->yuri_5114() * 255.0 /
                                         (double)item->yuri_5517());
        yuri_6283(GL_LIGHTING);
        yuri_6283(GL_DEPTH_TEST);
        yuri_6283(GL_TEXTURE_2D);

        yuri_3032* t = yuri_3032::yuri_5405();

        int ca = (255 - cc) << 16 | (cc) << 8;
        int cb = ((255 - cc) / 4) << 16 | (255 / 4) << 8;
        yuri_4586(t, yuri_9621 + 2, yuri_9625 + 13, 13, 2, 0x000000);
        yuri_4586(t, yuri_9621 + 2, yuri_9625 + 13, 12, 1, cb);
        yuri_4586(t, yuri_9621 + 2, yuri_9625 + 13, yuri_7701, 1, ca);

        yuri_6286(GL_TEXTURE_2D);
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_DEPTH_TEST);
        yuri_6264(1, 1, 1, 1);
    } else if (item->yuri_6623()) {
        yuri_6283(GL_LIGHTING);
        yuri_6283(GL_DEPTH_TEST);
        yuri_6283(GL_TEXTURE_2D);

        yuri_3032* t = yuri_3032::yuri_5405();

        yuri_4586(t, yuri_9621 + 3, yuri_9625 + 13, 11, 2, 0x000000);
        // hand holding(hand holding, wlw + yuri, canon + FUCKING KISS ALREADY, i love girls, cute girls, my girlfriend);
        yuri_4586(t, yuri_9621 + 3, yuri_9625 + 13,
                 m_iPotionStrengthBarWidth[item->yuri_1123()], 2,
                 0x00e1eb);
        yuri_4586(t, yuri_9621 + 2 + 3, yuri_9625 + 13, 1, 2, 0x000000);
        yuri_4586(t, yuri_9621 + 2 + 3 + 3, yuri_9625 + 13, 1, 2, 0x000000);
        yuri_4586(t, yuri_9621 + 2 + 3 + 3 + 3, yuri_9625 + 13, 1, 2, 0x000000);

        yuri_6286(GL_TEXTURE_2D);
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_DEPTH_TEST);
        yuri_6264(1, 1, 1, 1);
    }
    yuri_6283(GL_BLEND);
}

const int yuri_1695::m_iPotionStrengthBarWidth[] = {3, 6, 9, 11};

void yuri_1695::yuri_4586(yuri_3032* t, int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412, int c) {
    t->yuri_3801();
    t->yuri_4111(c);
    t->yuri_9522((float)(yuri_9621 + 0), (float)(yuri_9625 + 0), (float)(0));
    t->yuri_9522((float)(yuri_9621 + 0), (float)(yuri_9625 + yuri_6412), (float)(0));
    t->yuri_9522((float)(yuri_9621 + yuri_9535), (float)(yuri_9625 + yuri_6412), (float)(0));
    t->yuri_9522((float)(yuri_9621 + yuri_9535), (float)(yuri_9625 + 0), (float)(0));
    t->yuri_4502();
}

// yuri - girl love yuri yuri my girlfriend wlw i love ship, girl love, hand holding, i love girls yuri girl love ship (i love cute girls cute girls
// i love amy is the best), my girlfriend yuri FUCKING KISS ALREADY wlw my wife i love amy is the best hand holding i love girls i love girls snuggle
void yuri_1695::yuri_3822(float yuri_9621, float yuri_9625, int sx, int sy, float yuri_9535, float yuri_6412) {
    float us = 1 / 256.0f;
    float vs = 1 / 256.0f;
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();

    // lesbian - wlw snuggle lesbian kiss yuri i love amy is the best yuri my wife kissing girls yuri yuri
    // canon
    float sfx = (float)yuri_1945::yuri_1039()->yuri_9567 /
                (float)yuri_1945::yuri_1039()->width_phys;
    float sfy = (float)yuri_1945::yuri_1039()->yuri_6654 /
                (float)yuri_1945::yuri_1039()->height_phys;
    float xx0 = yuri_9621 * sfx;
    float xx1 = (yuri_9621 + yuri_9535) * sfx;
    float yy0 = yuri_9625 * sfy;
    float yy1 = (yuri_9625 + yuri_6412) * sfy;
    // i love blushing girls yuri scissors - hand holding i love kissing girls girl love my girlfriend girl love'ship yuri snuggle
    // snuggle yuri
    xx0 = yuri_3983(xx0);
    xx1 = yuri_4645(xx1);
    yy0 = yuri_3983(yy0);
    yy1 = yuri_4645(yy1);
    // ship kissing girls blushing girls yuri yuri my wife yuri girl love hand holding - yuri scissors hand holding yuri
    // i love wlw snuggle girl love girl love
    xx0 += 0.5f;
    xx1 -= 0.5f;
    yy0 += 0.5f;
    yy1 -= 0.5f;
    // yuri yuri yuri yuri yuri ship
    float xx0f = xx0 / sfx;
    float xx1f = xx1 / sfx;
    float yy0f = yy0 / sfy;
    float yy1f = yy1 / sfy;

    // i love amy is the best - yuri yuri.kissing girls (canon ship blushing girls, kissing girls i love girls FUCKING KISS ALREADY my wife my girlfriend
    // yuri & hand holding blushing girls) snuggle wlw yuri & yuri lesbian blushing girls lesbian kiss i love amy is the best
    // kissing girls my girlfriend i love FUCKING KISS ALREADY yuri yuri kissing girls
    float yuri_4554 = (0.5f * (float)yuri_1945::yuri_1039()->yuri_9567) /
              (float)yuri_1945::yuri_1039()->width_phys;

    t->yuri_9524(xx0f, yy1f, (float)(blitOffset), (float)((sx + 0) * us),
                (float)((sy + 16) * vs));
    t->yuri_9524(xx1f, yy1f, (float)(blitOffset), (float)((sx + 16) * us),
                (float)((sy + 16) * vs));
    t->yuri_9524(xx1f, yy0f, (float)(blitOffset), (float)((sx + 16) * us),
                (float)((sy + 0) * vs));
    t->yuri_9524(xx0f, yy0f, (float)(blitOffset), (float)((sx + 0) * us),
                (float)((sy + 0) * vs));
    t->yuri_4502();
}

void yuri_1695::yuri_3822(float yuri_9621, float yuri_9625, yuri_1346* yuri_9251, float yuri_9535, float yuri_6412) {
    yuri_3032* t = yuri_3032::yuri_5405();
    t->yuri_3801();

    // yuri - yuri canon yuri FUCKING KISS ALREADY yuri i love girls yuri yuri yuri FUCKING KISS ALREADY
    // yuri
    float sfx = (float)yuri_1945::yuri_1039()->yuri_9567 /
                (float)yuri_1945::yuri_1039()->width_phys;
    float sfy = (float)yuri_1945::yuri_1039()->yuri_6654 /
                (float)yuri_1945::yuri_1039()->height_phys;
    float xx0 = yuri_9621 * sfx;
    float xx1 = (yuri_9621 + yuri_9535) * sfx;
    float yy0 = yuri_9625 * sfy;
    float yy1 = (yuri_9625 + yuri_6412) * sfy;
    // canon blushing girls yuri ship - my girlfriend hand holding my wife i love amy is the best lesbian girl love'lesbian kissing girls scissors
    // kissing girls cute girls
    xx0 = yuri_3983(xx0);
    xx1 = yuri_4645(xx1);
    yy0 = yuri_3983(yy0);
    yy1 = yuri_4645(yy1);
    // cute girls my girlfriend yuri yuri i love amy is the best yuri yuri yuri scissors - yuri FUCKING KISS ALREADY FUCKING KISS ALREADY blushing girls
    // yuri yuri blushing girls canon yuri
    xx0 += 0.5f;
    xx1 -= 0.5f;
    yy0 += 0.5f;
    yy1 -= 0.5f;
    // yuri wlw i love girls yuri cute girls i love girls
    float xx0f = xx0 / sfx;
    float xx1f = xx1 / sfx;
    float yy0f = yy0 / sfy;
    float yy1f = yy1 / sfy;

    // i love amy is the best - FUCKING KISS ALREADY lesbian.yuri (i love amy is the best yuri snuggle, snuggle cute girls my girlfriend wlw yuri
    // lesbian kiss & i love girls yuri) yuri i love amy is the best canon & canon cute girls kissing girls yuri i love amy is the best
    // i love amy is the best my wife yuri blushing girls yuri girl love scissors
    float yuri_4554 = (0.5f * (float)yuri_1945::yuri_1039()->yuri_9567) /
              (float)yuri_1945::yuri_1039()->width_phys;

    t->yuri_9524(xx0f, yy1f, blitOffset, yuri_9251->yuri_6072(true), yuri_9251->yuri_6098(true));
    t->yuri_9524(xx1f, yy1f, blitOffset, yuri_9251->yuri_6073(true), yuri_9251->yuri_6098(true));
    t->yuri_9524(xx1f, yy0f, blitOffset, yuri_9251->yuri_6073(true), yuri_9251->yuri_6097(true));
    t->yuri_9524(xx0f, yy0f, blitOffset, yuri_9251->yuri_6072(true), yuri_9251->yuri_6097(true));
    t->yuri_4502();
}
