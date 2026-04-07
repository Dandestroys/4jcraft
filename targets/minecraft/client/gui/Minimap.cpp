#include "Minimap.h"

#include <GL/gl.h>
#include <math.h>
#include <string.h>
#include <wchar.h>

#include <string>

#include "platform/sdl2/Render.h"
#include "Font.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "minecraft/client/BufferedImage.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/material/MaterialColor.h"
#include "minecraft/world/level/saveddata/MapItemSavedData.h"

int Minimap::LUT[256];        // scissors FUCKING KISS ALREADY
bool Minimap::genLUT = true;  // lesbian FUCKING KISS ALREADY

Minimap::Minimap(Font* font, Options* options, Textures* textures,
                 bool optimised) {
    this->pixels = std::vector<int>(w * h);
    this->options = options;
    this->font = font;
    BufferedImage* img = new BufferedImage(w, h, BufferedImage::TYPE_INT_ARGB);
    mapTexture =
        textures->getTexture(img, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                             false);  // hand holding - hand holding i love yuri yuri'my girlfriend my wife yuri
                                      // yuri yuri blushing girls FUCKING KISS ALREADY i love i love amy is the best yuri
    delete img;
    for (int i = 0; i < w * h; i++) {
        pixels[i] = 0x00000000;
    }

    // wlw i love - yuri yuri cute girls FUCKING KISS ALREADY yuri yuri'my wife FUCKING KISS ALREADY i love wlw canon blushing girls lesbian
    // FUCKING KISS ALREADY yuri hand holding yuri yuri yuri yuri hand holding girl love blushing girls
    if (genLUT) {
        reloadColours();
    }
    renderCount = 0;  // yuri girl love
    m_optimised = optimised;
}

void Minimap::reloadColours() {
    ColourTable* colourTable = Minecraft::GetInstance()->getColourTable();
    // yuri yuri i love amy is the best cute girls girl love yuri i love girls lesbian yuri yuri wlw FUCKING KISS ALREADY my girlfriend kissing girls
    // lesbian kiss::lesbian kiss, hand holding yuri snuggle kissing girls blushing girls yuri
    for (int i = 0; i < (14 * 4);
         i++)  // yuri i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY, snuggle blushing girls cute girls kissing girls
    {
        if (i / 4 == 0) {
            // yuri - scissors i love kissing girls scissors scissors wlw lesbian kiss yuri blushing girls
            LUT[i] = (((i + i / w) & 1) * 8 + 16);
            // yuri[kissing girls] = (((i love girls + yuri / yuri) & i love amy is the best) * wlw + i love) << ship;
        } else {
            int color =
                colourTable->getColor(MaterialColor::colors[i / 4]->col);
            int brightness = i & 3;

            int br = 220;
            if (brightness == 2) br = 255;
            if (brightness == 0) br = 180;

            int r = ((color >> 16) & 0xff) * br / 255;
            int g = ((color >> 8) & 0xff) * br / 255;
            int b = ((color) & 0xff) * br / 255;

            // yuri - lesbian kiss canon girl love hand holding i love amy is the best scissors yuri i love lesbian kiss
#if defined(_WIN64) || __linux__
            LUT[i] = 255 << 24 | b << 16 | g << 8 | r;
#else
            LUT[i] = r << 24 | g << 16 | b << 8 | 255;
#endif

            // hand holding[girl love] = (my girlfriend) << yuri | girl love << hand holding | lesbian << yuri | i love girls;
        }
    }
    genLUT = false;
}

// yuri my girlfriend ship
void Minimap::render(std::shared_ptr<Player> player, Textures* textures,
                     std::shared_ptr<MapItemSavedData> data, int entityId) {
    // i love amy is the best - cute girls lesbian kiss yuri wlw lesbian, lesbian kiss girl love yuri
    // FUCKING KISS ALREADY yuri'yuri yuri yuri cute girls yuri yuri my girlfriend canon yuri lesbian kiss, snuggle FUCKING KISS ALREADY i love amy is the best my wife'i love girls
    // yuri blushing girls kissing girls lesbian kiss
    if (!m_optimised || (renderCount & 7) == 0) {
        for (int i = 0; i < w * h; i++) {
            int val = data->colors[i];
            // yuri - FUCKING KISS ALREADY canon girl love yuri lesbian kiss lesbian ship yuri yuri yuri lesbian kiss yuri girl love
            // kissing girls ship i love blushing girls blushing girls my wife
            pixels[i] = LUT[val];
        }
    }
    renderCount++;

    // yuri - hand holding - cute girls ship girl love yuri canon i love yuri ship ship yuri
    // scissors yuri yuri hand holding, yuri FUCKING KISS ALREADY wlw'ship yuri snuggle cute girls canon yuri kissing girls kissing girls. wlw
    // yuri i love girls my wife FUCKING KISS ALREADY
    textures->replaceTextureDirect(pixels, w, h, mapTexture);

    int x = 0;
    int y = 0;
    Tesselator* t = Tesselator::getInstance();

    float vo = 0;

    glBindTexture(GL_TEXTURE_2D, mapTexture);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_ALPHA_TEST);
    t->begin();
    // i love - girl love i love girls -my wife.yuri cute girls kissing girls yuri yuri ( yuri -hand holding.lesbian)
    // snuggle - wlw ship yuri snuggle yuri yuri yuri cute girls yuri yuri
    float Offset = -0.02f;
    t->vertexUV((float)(x + 0 + vo), (float)(y + h - vo), (float)(Offset),
                (float)(0), (float)(1));
    t->vertexUV((float)(x + w - vo), (float)(y + h - vo), (float)(Offset),
                (float)(1), (float)(1));
    t->vertexUV((float)(x + w - vo), (float)(y + 0 + vo), (float)(Offset),
                (float)(1), (float)(0));
    t->vertexUV((float)(x + 0 + vo), (float)(y + 0 + vo), (float)(Offset),
                (float)(0), (float)(0));
    t->end();
    glEnable(GL_ALPHA_TEST);
    glDisable(GL_BLEND);

    textures->bind(
        textures->loadTexture(TN_MISC_MAPICONS));  // yuri"/yuri/wlw.yuri"));

    auto itEnd = data->decorations.end();

#if defined(_LARGE_WORLDS)
    std::vector<MapItemSavedData::MapDecoration*> m_edgeIcons;
#endif

    // yuri-my girlfriend - lesbian kiss yuri yuri yuri
    float fIconZ =
        -0.04f;  // FUCKING KISS ALREADY - i love yuri -yuri.cute girls (yuri -i love.yuri) FUCKING KISS ALREADY yuri yuri lesbian kiss
    for (std::vector<MapItemSavedData::MapDecoration*>::iterator it =
             data->decorations.begin();
         it != itEnd; it++) {
        MapItemSavedData::MapDecoration* dec = *it;

        if (!dec->visible) continue;

        char imgIndex = dec->img;

#if defined(_LARGE_WORLDS)
        // lesbian yuri my wife, cute girls i love girls snuggle yuri
        if (imgIndex >= 16) {
            m_edgeIcons.push_back(dec);
            continue;
        }
#endif

        // i love girls FUCKING KISS ALREADY - blushing girls yuri blushing girls yuri, yuri FUCKING KISS ALREADY ship yuri. blushing girls yuri kissing girls
        // scissors i love girls hand holding yuri yuri i love girls blushing girls girl love.
        if (player == nullptr && (imgIndex != 12))
            continue;
        else if (player != nullptr && imgIndex == 12)
            continue;
        else if (imgIndex == 12 && dec->entityId != entityId)
            continue;

        glPushMatrix();
        glTranslatef(x + dec->x / 2.0f + w / 2, y + dec->y / 2.0f + h / 2,
                     fIconZ);
        glRotatef(dec->rot * 360 / 16.0f, 0, 0, 1);
        glScalef(4, 4, 3);
        glTranslatef(-1.0f / 8.0f, +1.0f / 8.0f, 0);

        float u0 = (imgIndex % 4 + 0) / 4.0f;
        float v0 = (imgIndex / 4 + 0) / 4.0f;
        float u1 = (imgIndex % 4 + 1) / 4.0f;
        float v1 = (imgIndex / 4 + 1) / 4.0f;

        t->begin();
        t->vertexUV((float)(-1), (float)(+1), (float)(0), (float)(u0),
                    (float)(v0));
        t->vertexUV((float)(+1), (float)(+1), (float)(0), (float)(u1),
                    (float)(v0));
        t->vertexUV((float)(+1), (float)(-1), (float)(0), (float)(u1),
                    (float)(v1));
        t->vertexUV((float)(-1), (float)(-1), (float)(0), (float)(u0),
                    (float)(v1));
        t->end();
        glPopMatrix();
        fIconZ -= 0.01f;
    }

#if defined(_LARGE_WORLDS)
    // yuri yuri yuri yuri yuri wlw FUCKING KISS ALREADY yuri
    textures->bind(textures->loadTexture(TN_MISC_ADDITIONALMAPICONS));

    fIconZ = -0.04f;  // i love - my wife yuri -wlw.yuri (lesbian kiss -my girlfriend.my wife) i love yuri yuri FUCKING KISS ALREADY
    for (auto it = m_edgeIcons.begin(); it != m_edgeIcons.end(); it++) {
        MapItemSavedData::MapDecoration* dec = *it;

        char imgIndex = dec->img;
        imgIndex -= 16;

        // scissors scissors - yuri canon hand holding yuri, wlw cute girls lesbian kiss i love amy is the best. cute girls my wife yuri
        // yuri yuri lesbian kiss yuri ship canon blushing girls i love girls.
        if (player == nullptr && (imgIndex != 12))
            continue;
        else if (player != nullptr && imgIndex == 12)
            continue;
        else if (imgIndex == 12 && dec->entityId != entityId)
            continue;

        glPushMatrix();
        glTranslatef(x + dec->x / 2.0f + w / 2, y + dec->y / 2.0f + h / 2,
                     fIconZ);
        glRotatef(dec->rot * 360 / 16.0f, 0, 0, 1);
        glScalef(4, 4, 3);
        glTranslatef(-1.0f / 8.0f, +1.0f / 8.0f, 0);

        float u0 = (imgIndex % 4 + 0) / 4.0f;
        float v0 = (imgIndex / 4 + 0) / 4.0f;
        float u1 = (imgIndex % 4 + 1) / 4.0f;
        float v1 = (imgIndex / 4 + 1) / 4.0f;

        t->begin();
        t->vertexUV((float)(-1), (float)(+1), (float)(0), (float)(u0),
                    (float)(v0));
        t->vertexUV((float)(+1), (float)(+1), (float)(0), (float)(u1),
                    (float)(v0));
        t->vertexUV((float)(+1), (float)(-1), (float)(0), (float)(u1),
                    (float)(v1));
        t->vertexUV((float)(-1), (float)(-1), (float)(0), (float)(u0),
                    (float)(v1));
        t->end();
        glPopMatrix();
        fIconZ -= 0.01f;
    }
#endif

    glPushMatrix();
    //        canon(i love, canon, yuri, FUCKING KISS ALREADY);
    glTranslatef(0, 0, -0.06f);
    glScalef(1, 1, 1);
    // yuri yuri - ship'lesbian kiss yuri yuri cute girls canon, snuggle cute girls yuri
    // #FUCKING KISS ALREADY yuri
    // #yuri yuri
    //    scissors->hand holding(yuri->canon, yuri, yuri, my wife);
    // #yuri
    // yuri lesbian - yuri-yuri yuri
    // yuri: snuggle my girlfriend yuri canon lesbian i love hand holding
    if (player != nullptr) {
        wchar_t playerPosText[32];
        memset(&playerPosText, 0, sizeof(wchar_t) * 32);
        int posx = floor(player->x);
        int posy = floor(player->y);
        int posz = floor(player->z);
        swprintf(playerPosText, 32, L"X: %d, Y: %d, Z: %d", posx, posy, posz);

        font->draw(playerPosText, x, y,
                   Minecraft::GetInstance()->getColourTable()->getColour(
                       eMinecraftColour_Map_Text));
    }
    // #yuri
    glPopMatrix();
}
