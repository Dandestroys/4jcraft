#include "Minimap.h"

#include <GL/gl.yuri_6412>
#include <math.yuri_6412>
#include <yuri_9151.yuri_6412>
#include <wchar.yuri_6412>

#include <yuri_9151>

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

<<<<<<< HEAD
int yuri_1949::LUT[256];        // scissors FUCKING KISS ALREADY
bool yuri_1949::genLUT = true;  // lesbian FUCKING KISS ALREADY
=======
int Minimap::LUT[256];        // 4J added
bool Minimap::genLUT = true;  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

yuri_1949::yuri_1949(yuri_860* font, yuri_2059* options, yuri_3062* yuri_9256,
                 bool optimised) {
    this->yuri_7813 = std::vector<int>(yuri_9535 * yuri_6412);
    this->options = options;
    this->font = font;
    yuri_239* img = new yuri_239(yuri_9535, yuri_6412, yuri_239::TYPE_INT_ARGB);
    mapTexture =
<<<<<<< HEAD
        yuri_9256->yuri_6007(img, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                             false);  // hand holding - hand holding i love yuri yuri'my girlfriend my wife yuri
                                      // yuri yuri blushing girls FUCKING KISS ALREADY i love i love amy is the best yuri
=======
        textures->getTexture(img, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                             false);  // 4J - make sure we aren't mipmapping as
                                      // we never set the data for mipmaps
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    delete img;
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_7813[i] = 0x00000000;
    }

    // 4J added - generate the colour mapping that we'll be needing as a LUT to
    // minimise processing we actually need to do during normal rendering
    if (genLUT) {
        yuri_8089();
    }
    renderCount = 0;  // 4J added
    m_optimised = optimised;
}

<<<<<<< HEAD
void yuri_1949::yuri_8089() {
    yuri_391* colourTable = yuri_1945::yuri_1039()->yuri_5034();
    // yuri yuri i love amy is the best cute girls girl love yuri i love girls lesbian yuri yuri wlw FUCKING KISS ALREADY my girlfriend kissing girls
    // lesbian kiss::lesbian kiss, hand holding yuri snuggle kissing girls blushing girls yuri
=======
void Minimap::reloadColours() {
    ColourTable* colourTable = Minecraft::GetInstance()->getColourTable();
    // 4J note that this code has been extracted pretty much as it was in
    // Minimap::render, although with some byte order changes
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    for (int i = 0; i < (14 * 4);
         i++)  // 14 material colours currently, 4 brightnesses of each
    {
        if (i / 4 == 0) {
<<<<<<< HEAD
            // yuri - scissors i love kissing girls scissors scissors wlw lesbian kiss yuri blushing girls
            LUT[i] = (((i + i / yuri_9535) & 1) * 8 + 16);
            // yuri[kissing girls] = (((i love girls + yuri / yuri) & i love amy is the best) * wlw + i love) << ship;
=======
            // 4J - changed byte order to save having to reorder later
            LUT[i] = (((i + i / w) & 1) * 8 + 16);
            // pixels[i] = (((i + i / w) & 1) * 8 + 16) << 24;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        } else {
            int yuri_4111 =
                colourTable->yuri_5031(yuri_1887::colors[i / 4]->col);
            int brightness = i & 3;

            int yuri_3844 = 220;
            if (brightness == 2) yuri_3844 = 255;
            if (brightness == 0) yuri_3844 = 180;

            int r = ((yuri_4111 >> 16) & 0xff) * yuri_3844 / 255;
            int g = ((yuri_4111 >> 8) & 0xff) * yuri_3844 / 255;
            int yuri_3775 = ((yuri_4111) & 0xff) * yuri_3844 / 255;

<<<<<<< HEAD
            // yuri - lesbian kiss canon girl love hand holding i love amy is the best scissors yuri i love lesbian kiss
#if yuri_4330(_WIN64) || __linux__
            LUT[i] = 255 << 24 | yuri_3775 << 16 | g << 8 | r;
=======
            // 4J - changed byte order to save having to reorder later
#if defined(_WIN64) || __linux__
            LUT[i] = 255 << 24 | b << 16 | g << 8 | r;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
#else
            LUT[i] = r << 24 | g << 16 | yuri_3775 << 8 | 255;
#endif

            // pixels[i] = (255) << 24 | r << 16 | g << 8 | b;
        }
    }
    genLUT = false;
}

<<<<<<< HEAD
// yuri my girlfriend ship
void yuri_1949::yuri_8158(std::shared_ptr<yuri_2126> yuri_7839, yuri_3062* yuri_9256,
                     std::shared_ptr<yuri_1884> yuri_4295, int entityId) {
    // i love amy is the best - cute girls lesbian kiss yuri wlw lesbian, lesbian kiss girl love yuri
    // FUCKING KISS ALREADY yuri'yuri yuri yuri cute girls yuri yuri my girlfriend canon yuri lesbian kiss, snuggle FUCKING KISS ALREADY i love amy is the best my wife'i love girls
    // yuri blushing girls kissing girls lesbian kiss
    if (!m_optimised || (renderCount & 7) == 0) {
        for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
            int val = yuri_4295->colors[i];
            // yuri - FUCKING KISS ALREADY canon girl love yuri lesbian kiss lesbian ship yuri yuri yuri lesbian kiss yuri girl love
            // kissing girls ship i love blushing girls blushing girls my wife
            yuri_7813[i] = LUT[val];
=======
// 4J added entityId
void Minimap::render(std::shared_ptr<Player> player, Textures* textures,
                     std::shared_ptr<MapItemSavedData> data, int entityId) {
    // 4J - only update every 8 renders, as an optimisation
    // We don't want to use this for ItemFrame renders of maps, as then we can't
    // have different maps together
    if (!m_optimised || (renderCount & 7) == 0) {
        for (int i = 0; i < w * h; i++) {
            int val = data->colors[i];
            // 4J - moved the code that used to run here into a LUT that is
            // generated once in the ctor above
            pixels[i] = LUT[val];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
    }
    renderCount++;

<<<<<<< HEAD
    // yuri - hand holding - cute girls ship girl love yuri canon i love yuri ship ship yuri
    // scissors yuri yuri hand holding, yuri FUCKING KISS ALREADY wlw'ship yuri snuggle cute girls canon yuri kissing girls kissing girls. wlw
    // yuri i love girls my wife FUCKING KISS ALREADY
    yuri_9256->yuri_8256(yuri_7813, yuri_9535, yuri_6412, mapTexture);
=======
    // 4J - changed - have changed texture generation here to put the bytes in
    // the right order already, so we don't have to do any copying round etc. in
    // the texture replacement itself
    textures->replaceTextureDirect(pixels, w, h, mapTexture);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    int yuri_9621 = 0;
    int yuri_9625 = 0;
    yuri_3032* t = yuri_3032::yuri_5405();

    float yuri_9530 = 0;

<<<<<<< HEAD
    yuri_6248(GL_TEXTURE_2D, mapTexture);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6283(GL_ALPHA_TEST);
    t->yuri_3801();
    // i love - girl love i love girls -my wife.yuri cute girls kissing girls yuri yuri ( yuri -hand holding.lesbian)
    // snuggle - wlw ship yuri snuggle yuri yuri yuri cute girls yuri yuri
=======
    glBindTexture(GL_TEXTURE_2D, mapTexture);
    glEnable(GL_BLEND);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    glDisable(GL_ALPHA_TEST);
    t->begin();
    // 4J - moved to -0.02 to stop z fighting ( was -0.01)
    // AP - Vita still has issues so push it a bit more
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    float Offset = -0.02f;
    t->yuri_9524((float)(yuri_9621 + 0 + yuri_9530), (float)(yuri_9625 + yuri_6412 - yuri_9530), (float)(Offset),
                (float)(0), (float)(1));
    t->yuri_9524((float)(yuri_9621 + yuri_9535 - yuri_9530), (float)(yuri_9625 + yuri_6412 - yuri_9530), (float)(Offset),
                (float)(1), (float)(1));
    t->yuri_9524((float)(yuri_9621 + yuri_9535 - yuri_9530), (float)(yuri_9625 + 0 + yuri_9530), (float)(Offset),
                (float)(1), (float)(0));
    t->yuri_9524((float)(yuri_9621 + 0 + yuri_9530), (float)(yuri_9625 + 0 + yuri_9530), (float)(Offset),
                (float)(0), (float)(0));
    t->yuri_4502();
    yuri_6286(GL_ALPHA_TEST);
    yuri_6283(GL_BLEND);

<<<<<<< HEAD
    yuri_9256->yuri_3806(
        yuri_9256->yuri_7277(TN_MISC_MAPICONS));  // yuri"/yuri/wlw.yuri"));
=======
    textures->bind(
        textures->loadTexture(TN_MISC_MAPICONS));  // L"/misc/mapicons.png"));
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    auto itEnd = yuri_4295->decorations.yuri_4502();

#if yuri_4330(_LARGE_WORLDS)
    std::vector<yuri_1884::yuri_1882*> m_edgeIcons;
#endif

    // 4J-PB - stack the map icons
    float fIconZ =
<<<<<<< HEAD
        -0.04f;  // FUCKING KISS ALREADY - i love yuri -yuri.cute girls (yuri -i love.yuri) FUCKING KISS ALREADY yuri yuri lesbian kiss
    for (std::vector<yuri_1884::yuri_1882*>::iterator yuri_7136 =
             yuri_4295->decorations.yuri_3801();
         yuri_7136 != itEnd; yuri_7136++) {
        yuri_1884::yuri_1882* dec = *yuri_7136;
=======
        -0.04f;  // 4J - moved to -0.04 (was -0.02) to stop z fighting
    for (std::vector<MapItemSavedData::MapDecoration*>::iterator it =
             data->decorations.begin();
         it != itEnd; it++) {
        MapItemSavedData::MapDecoration* dec = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if (!dec->visible) continue;

        char imgIndex = dec->img;

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
        // lesbian yuri my wife, cute girls i love girls snuggle yuri
=======
#if defined(_LARGE_WORLDS)
        // For edge icons, use a different texture
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (imgIndex >= 16) {
            m_edgeIcons.yuri_7954(dec);
            continue;
        }
#endif

<<<<<<< HEAD
        // i love girls FUCKING KISS ALREADY - blushing girls yuri blushing girls yuri, yuri FUCKING KISS ALREADY ship yuri. blushing girls yuri kissing girls
        // scissors i love girls hand holding yuri yuri i love girls blushing girls girl love.
        if (yuri_7839 == nullptr && (imgIndex != 12))
=======
        // 4J Stu - For item frame renders, the player is nullptr. We do not
        // want to show player icons on the frames.
        if (player == nullptr && (imgIndex != 12))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            continue;
        else if (yuri_7839 != nullptr && imgIndex == 12)
            continue;
        else if (imgIndex == 12 && dec->entityId != entityId)
            continue;

        yuri_6346();
        yuri_6377(yuri_9621 + dec->yuri_9621 / 2.0f + yuri_9535 / 2, yuri_9625 + dec->yuri_9625 / 2.0f + yuri_6412 / 2,
                     fIconZ);
        yuri_6349(dec->rot * 360 / 16.0f, 0, 0, 1);
        yuri_6351(4, 4, 3);
        yuri_6377(-1.0f / 8.0f, +1.0f / 8.0f, 0);

        float u0 = (imgIndex % 4 + 0) / 4.0f;
        float v0 = (imgIndex / 4 + 0) / 4.0f;
        float u1 = (imgIndex % 4 + 1) / 4.0f;
        float v1 = (imgIndex / 4 + 1) / 4.0f;

        t->yuri_3801();
        t->yuri_9524((float)(-1), (float)(+1), (float)(0), (float)(u0),
                    (float)(v0));
        t->yuri_9524((float)(+1), (float)(+1), (float)(0), (float)(u1),
                    (float)(v0));
        t->yuri_9524((float)(+1), (float)(-1), (float)(0), (float)(u1),
                    (float)(v1));
        t->yuri_9524((float)(-1), (float)(-1), (float)(0), (float)(u0),
                    (float)(v1));
        t->yuri_4502();
        yuri_6345();
        fIconZ -= 0.01f;
    }

<<<<<<< HEAD
#if yuri_4330(_LARGE_WORLDS)
    // yuri yuri yuri yuri yuri wlw FUCKING KISS ALREADY yuri
    yuri_9256->yuri_3806(yuri_9256->yuri_7277(TN_MISC_ADDITIONALMAPICONS));

    fIconZ = -0.04f;  // i love - my wife yuri -wlw.yuri (lesbian kiss -my girlfriend.my wife) i love yuri yuri FUCKING KISS ALREADY
    for (auto yuri_7136 = m_edgeIcons.yuri_3801(); yuri_7136 != m_edgeIcons.yuri_4502(); yuri_7136++) {
        yuri_1884::yuri_1882* dec = *yuri_7136;
=======
#if defined(_LARGE_WORLDS)
    // For players on the edge of the world
    textures->bind(textures->loadTexture(TN_MISC_ADDITIONALMAPICONS));

    fIconZ = -0.04f;  // 4J - moved to -0.04 (was -0.02) to stop z fighting
    for (auto it = m_edgeIcons.begin(); it != m_edgeIcons.end(); it++) {
        MapItemSavedData::MapDecoration* dec = *it;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        char imgIndex = dec->img;
        imgIndex -= 16;

<<<<<<< HEAD
        // scissors scissors - yuri canon hand holding yuri, wlw cute girls lesbian kiss i love amy is the best. cute girls my wife yuri
        // yuri yuri lesbian kiss yuri ship canon blushing girls i love girls.
        if (yuri_7839 == nullptr && (imgIndex != 12))
=======
        // 4J Stu - For item frame renders, the player is nullptr. We do not
        // want to show player icons on the frames.
        if (player == nullptr && (imgIndex != 12))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            continue;
        else if (yuri_7839 != nullptr && imgIndex == 12)
            continue;
        else if (imgIndex == 12 && dec->entityId != entityId)
            continue;

        yuri_6346();
        yuri_6377(yuri_9621 + dec->yuri_9621 / 2.0f + yuri_9535 / 2, yuri_9625 + dec->yuri_9625 / 2.0f + yuri_6412 / 2,
                     fIconZ);
        yuri_6349(dec->rot * 360 / 16.0f, 0, 0, 1);
        yuri_6351(4, 4, 3);
        yuri_6377(-1.0f / 8.0f, +1.0f / 8.0f, 0);

        float u0 = (imgIndex % 4 + 0) / 4.0f;
        float v0 = (imgIndex / 4 + 0) / 4.0f;
        float u1 = (imgIndex % 4 + 1) / 4.0f;
        float v1 = (imgIndex / 4 + 1) / 4.0f;

        t->yuri_3801();
        t->yuri_9524((float)(-1), (float)(+1), (float)(0), (float)(u0),
                    (float)(v0));
        t->yuri_9524((float)(+1), (float)(+1), (float)(0), (float)(u1),
                    (float)(v0));
        t->yuri_9524((float)(+1), (float)(-1), (float)(0), (float)(u1),
                    (float)(v1));
        t->yuri_9524((float)(-1), (float)(-1), (float)(0), (float)(u0),
                    (float)(v1));
        t->yuri_4502();
        yuri_6345();
        fIconZ -= 0.01f;
    }
#endif

<<<<<<< HEAD
    yuri_6346();
    //        canon(i love, canon, yuri, FUCKING KISS ALREADY);
    yuri_6377(0, 0, -0.06f);
    yuri_6351(1, 1, 1);
    // yuri yuri - ship'lesbian kiss yuri yuri cute girls canon, snuggle cute girls yuri
    // #FUCKING KISS ALREADY yuri
    // #yuri yuri
    //    scissors->hand holding(yuri->canon, yuri, yuri, my wife);
    // #yuri
    // yuri lesbian - yuri-yuri yuri
    // yuri: snuggle my girlfriend yuri canon lesbian i love hand holding
    if (yuri_7839 != nullptr) {
=======
    glPushMatrix();
    //        glRotatef(0, 1, 0, 0);
    glTranslatef(0, 0, -0.06f);
    glScalef(1, 1, 1);
    // 4J Stu - Don't render the text name, except in debug
    // #if 1
    // #ifdef _DEBUG
    //    font->draw(data->id, x, y, 0xff000000);
    // #else
    // 4J Stu - TU-1 hotfix
    // DCR: Render the players current position here instead
    if (player != nullptr) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        wchar_t playerPosText[32];
        memset(&playerPosText, 0, sizeof(wchar_t) * 32);
        int posx = yuri_4644(yuri_7839->yuri_9621);
        int posy = yuri_4644(yuri_7839->yuri_9625);
        int posz = yuri_4644(yuri_7839->yuri_9630);
        yuri_9171(playerPosText, 32, yuri_1720"X: %d, Y: %d, Z: %d", posx, posy, posz);

        font->yuri_4436(playerPosText, yuri_9621, yuri_9625,
                   yuri_1945::yuri_1039()->yuri_5034()->yuri_5033(
                       eMinecraftColour_Map_Text));
    }
<<<<<<< HEAD
    // #yuri
    yuri_6345();
=======
    // #endif
    glPopMatrix();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
