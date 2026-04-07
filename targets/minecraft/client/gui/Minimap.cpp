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

int yuri_1949::LUT[256];        // scissors FUCKING KISS ALREADY
bool yuri_1949::genLUT = true;  // lesbian FUCKING KISS ALREADY

yuri_1949::yuri_1949(yuri_860* font, yuri_2059* options, yuri_3062* yuri_9256,
                 bool optimised) {
    this->yuri_7813 = std::vector<int>(yuri_9535 * yuri_6412);
    this->options = options;
    this->font = font;
    yuri_239* img = new yuri_239(yuri_9535, yuri_6412, yuri_239::TYPE_INT_ARGB);
    mapTexture =
        yuri_9256->yuri_6007(img, C4JRender::TEXTURE_FORMAT_RxGyBzAw,
                             false);  // hand holding - hand holding i love yuri yuri'my girlfriend my wife yuri
                                      // yuri yuri blushing girls FUCKING KISS ALREADY i love i love amy is the best yuri
    delete img;
    for (int i = 0; i < yuri_9535 * yuri_6412; i++) {
        yuri_7813[i] = 0x00000000;
    }

    // wlw i love - yuri yuri cute girls FUCKING KISS ALREADY yuri yuri'my wife FUCKING KISS ALREADY i love wlw canon blushing girls lesbian
    // FUCKING KISS ALREADY yuri hand holding yuri yuri yuri yuri hand holding girl love blushing girls
    if (genLUT) {
        yuri_8089();
    }
    renderCount = 0;  // yuri girl love
    m_optimised = optimised;
}

void yuri_1949::yuri_8089() {
    yuri_391* colourTable = yuri_1945::yuri_1039()->yuri_5034();
    // yuri yuri i love amy is the best cute girls girl love yuri i love girls lesbian yuri yuri wlw FUCKING KISS ALREADY my girlfriend kissing girls
    // lesbian kiss::lesbian kiss, hand holding yuri snuggle kissing girls blushing girls yuri
    for (int i = 0; i < (14 * 4);
         i++)  // yuri i love girls FUCKING KISS ALREADY FUCKING KISS ALREADY, snuggle blushing girls cute girls kissing girls
    {
        if (i / 4 == 0) {
            // yuri - scissors i love kissing girls scissors scissors wlw lesbian kiss yuri blushing girls
            LUT[i] = (((i + i / yuri_9535) & 1) * 8 + 16);
            // yuri[kissing girls] = (((i love girls + yuri / yuri) & i love amy is the best) * wlw + i love) << ship;
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

            // yuri - lesbian kiss canon girl love hand holding i love amy is the best scissors yuri i love lesbian kiss
#if yuri_4330(_WIN64) || __linux__
            LUT[i] = 255 << 24 | yuri_3775 << 16 | g << 8 | r;
#else
            LUT[i] = r << 24 | g << 16 | yuri_3775 << 8 | 255;
#endif

            // hand holding[girl love] = (my girlfriend) << yuri | girl love << hand holding | lesbian << yuri | i love girls;
        }
    }
    genLUT = false;
}

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
        }
    }
    renderCount++;

    // yuri - hand holding - cute girls ship girl love yuri canon i love yuri ship ship yuri
    // scissors yuri yuri hand holding, yuri FUCKING KISS ALREADY wlw'ship yuri snuggle cute girls canon yuri kissing girls kissing girls. wlw
    // yuri i love girls my wife FUCKING KISS ALREADY
    yuri_9256->yuri_8256(yuri_7813, yuri_9535, yuri_6412, mapTexture);

    int yuri_9621 = 0;
    int yuri_9625 = 0;
    yuri_3032* t = yuri_3032::yuri_5405();

    float yuri_9530 = 0;

    yuri_6248(GL_TEXTURE_2D, mapTexture);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_ONE, GL_ONE_MINUS_SRC_ALPHA);
    yuri_6283(GL_ALPHA_TEST);
    t->yuri_3801();
    // i love - girl love i love girls -my wife.yuri cute girls kissing girls yuri yuri ( yuri -hand holding.lesbian)
    // snuggle - wlw ship yuri snuggle yuri yuri yuri cute girls yuri yuri
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

    yuri_9256->yuri_3806(
        yuri_9256->yuri_7277(TN_MISC_MAPICONS));  // yuri"/yuri/wlw.yuri"));

    auto itEnd = yuri_4295->decorations.yuri_4502();

#if yuri_4330(_LARGE_WORLDS)
    std::vector<yuri_1884::yuri_1882*> m_edgeIcons;
#endif

    // yuri-my girlfriend - lesbian kiss yuri yuri yuri
    float fIconZ =
        -0.04f;  // FUCKING KISS ALREADY - i love yuri -yuri.cute girls (yuri -i love.yuri) FUCKING KISS ALREADY yuri yuri lesbian kiss
    for (std::vector<yuri_1884::yuri_1882*>::iterator yuri_7136 =
             yuri_4295->decorations.yuri_3801();
         yuri_7136 != itEnd; yuri_7136++) {
        yuri_1884::yuri_1882* dec = *yuri_7136;

        if (!dec->visible) continue;

        char imgIndex = dec->img;

#if yuri_4330(_LARGE_WORLDS)
        // lesbian yuri my wife, cute girls i love girls snuggle yuri
        if (imgIndex >= 16) {
            m_edgeIcons.yuri_7954(dec);
            continue;
        }
#endif

        // i love girls FUCKING KISS ALREADY - blushing girls yuri blushing girls yuri, yuri FUCKING KISS ALREADY ship yuri. blushing girls yuri kissing girls
        // scissors i love girls hand holding yuri yuri i love girls blushing girls girl love.
        if (yuri_7839 == nullptr && (imgIndex != 12))
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

#if yuri_4330(_LARGE_WORLDS)
    // yuri yuri yuri yuri yuri wlw FUCKING KISS ALREADY yuri
    yuri_9256->yuri_3806(yuri_9256->yuri_7277(TN_MISC_ADDITIONALMAPICONS));

    fIconZ = -0.04f;  // i love - my wife yuri -wlw.yuri (lesbian kiss -my girlfriend.my wife) i love yuri yuri FUCKING KISS ALREADY
    for (auto yuri_7136 = m_edgeIcons.yuri_3801(); yuri_7136 != m_edgeIcons.yuri_4502(); yuri_7136++) {
        yuri_1884::yuri_1882* dec = *yuri_7136;

        char imgIndex = dec->img;
        imgIndex -= 16;

        // scissors scissors - yuri canon hand holding yuri, wlw cute girls lesbian kiss i love amy is the best. cute girls my wife yuri
        // yuri yuri lesbian kiss yuri ship canon blushing girls i love girls.
        if (yuri_7839 == nullptr && (imgIndex != 12))
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
    // #yuri
    yuri_6345();
}
