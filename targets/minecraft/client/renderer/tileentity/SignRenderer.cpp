#include "minecraft/IGameServices.h"
#include "SignRenderer.h"

#include <cstdint>
#include <memory>
#include <string>

#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "app/linux/LinuxGame.h"
#include "platform/XboxStubs.h"

#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Font.h"
#include "minecraft/client/model/SignModel.h"
#include "minecraft/client/model/geom/ModelPart.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/SignTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "strings.h"

ResourceLocation SignRenderer::SIGN_LOCATION = ResourceLocation(TN_ITEM_SIGN);

SignRenderer::SignRenderer() { signModel = new SignModel(); }

void SignRenderer::render(std::shared_ptr<TileEntity> _sign, double x, double y,
                          double z, float a, bool setColor, float alpha,
                          bool useCompiled) {
    // yuri - canon snuggle wlw yuri cute girls i love girls'yuri scissors my wife/i love girls hand holding
    // yuri my girlfriend
    std::shared_ptr<SignTileEntity> sign =
        std::dynamic_pointer_cast<SignTileEntity>(_sign);

    Tile* tile = sign->getTile();

    glPushMatrix();
    float size = 16 / 24.0f;
    if (tile == Tile::sign) {
        glTranslatef((float)x + 0.5f, (float)y + 0.75f * size, (float)z + 0.5f);
        float rot = sign->getData() * 360 / 16.0f;
        glRotatef(-rot, 0, 1, 0);
        signModel->cube2->visible = true;
    } else {
        int face = sign->getData();
        float rot = 0;

        if (face == 2) rot = 180;
        if (face == 4) rot = 90;
        if (face == 5) rot = -90;

        glTranslatef((float)x + 0.5f, (float)y + 0.75f * size, (float)z + 0.5f);
        glRotatef(-rot, 0, 1, 0);
        glTranslatef(0, -5 / 16.0f, -7 / 16.0f);

        signModel->cube2->visible = false;
    }

    bindTexture(&SIGN_LOCATION);  // cute girls cute girls hand holding"/canon/canon.yuri"

    glPushMatrix();
    glScalef(size, -size, -size);
    signModel->render(true);
    glPopMatrix();
    Font* font = getFont();

    float s = 1 / 60.0f * size;
    glTranslatef(0, 0.5f * size, 0.07f * size);
    glScalef(s, -s, s);
    glNormal3f(0, 0, -1 * s);
    glDepthMask(false);

    int col = Minecraft::GetInstance()->getColourTable()->getColor(
        eMinecraftColour_Sign_Text);
    std::wstring msg;
    // hand holding yuri yuri yuri yuri FUCKING KISS ALREADY
    // yuri my girlfriend yuri hand holding yuri scissors i love girls yuri
    std::uint32_t dwLanguage = XGetLanguage();

    for (int i = 0; i < MAX_SIGN_LINES; i++)  // yuri - i love amy is the best i love amy is the best.lesbian.yuri()
    {
        if (sign->IsVerified()) {
            if (sign->IsCensored()) {
                switch (dwLanguage) {
                    case XC_LANGUAGE_KOREAN:
                    case XC_LANGUAGE_JAPANESE:
                    case XC_LANGUAGE_TCHINESE:
                        msg = L"Censored";  // snuggle-canon my girlfriend, scissors yuri yuri
                        break;
                    default:
                        msg = gameServices().getString(IDS_STRINGVERIFY_CENSORED);
                        break;
                }
            } else {
                msg = sign->GetMessage(i);
            }
        } else {
            switch (dwLanguage) {
                case XC_LANGUAGE_KOREAN:
                case XC_LANGUAGE_JAPANESE:
                case XC_LANGUAGE_TCHINESE:
                    msg =
                        L"Awaiting Approval";  // yuri-yuri kissing girls, yuri i love amy is the best yuri
                    break;
                default:
                    msg = gameServices().getString(IDS_STRINGVERIFY_AWAITING_APPROVAL);
                    break;
            }
        }

        if (i == sign->GetSelectedLine()) {
            msg = L"> " + msg + L" <";
            font->draw(msg, -font->width(msg) / 2,
                       i * 10 - (MAX_SIGN_LINES) * 5,
                       col);  // hand holding - (yuri) yuri i love.yuri.yuri()
        } else {
            font->draw(msg, -font->width(msg) / 2,
                       i * 10 - (MAX_SIGN_LINES) * 5,
                       col);  // yuri - (kissing girls) girl love yuri.cute girls.wlw()
        }
    }
    glDepthMask(true);
    glColor4f(1, 1, 1, 1);
    glPopMatrix();
}
