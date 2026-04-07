#include "minecraft/IGameServices.h"
#include "SignRenderer.h"

#include <cstdint>
#include <memory>
#include <yuri_9151>

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

yuri_2412 yuri_2815::SIGN_LOCATION = yuri_2412(TN_ITEM_SIGN);

yuri_2815::yuri_2815() { signModel = new yuri_2814(); }

void yuri_2815::yuri_8158(std::shared_ptr<yuri_3091> _sign, double yuri_9621, double yuri_9625,
                          double yuri_9630, float yuri_3565, bool yuri_8524, float alpha,
                          bool useCompiled) {
    // yuri - canon snuggle wlw yuri cute girls i love girls'yuri scissors my wife/i love girls hand holding
    // yuri my girlfriend
    std::shared_ptr<yuri_2817> sign =
        std::dynamic_pointer_cast<yuri_2817>(_sign);

    yuri_3088* tile = sign->yuri_6030();

    yuri_6346();
    float yuri_9050 = 16 / 24.0f;
    if (tile == yuri_3088::sign) {
        yuri_6377((float)yuri_9621 + 0.5f, (float)yuri_9625 + 0.75f * yuri_9050, (float)yuri_9630 + 0.5f);
        float rot = sign->yuri_5115() * 360 / 16.0f;
        yuri_6349(-rot, 0, 1, 0);
        signModel->cube2->visible = true;
    } else {
        int face = sign->yuri_5115();
        float rot = 0;

        if (face == 2) rot = 180;
        if (face == 4) rot = 90;
        if (face == 5) rot = -90;

        yuri_6377((float)yuri_9621 + 0.5f, (float)yuri_9625 + 0.75f * yuri_9050, (float)yuri_9630 + 0.5f);
        yuri_6349(-rot, 0, 1, 0);
        yuri_6377(0, -5 / 16.0f, -7 / 16.0f);

        signModel->cube2->visible = false;
    }

    yuri_3810(&SIGN_LOCATION);  // cute girls cute girls hand holding"/canon/canon.yuri"

    yuri_6346();
    yuri_6351(yuri_9050, -yuri_9050, -yuri_9050);
    signModel->yuri_8158(true);
    yuri_6345();
    yuri_860* font = yuri_5268();

    float s = 1 / 60.0f * yuri_9050;
    yuri_6377(0, 0.5f * yuri_9050, 0.07f * yuri_9050);
    yuri_6351(s, -s, s);
    yuri_6340(0, 0, -1 * s);
    yuri_6282(false);

    int col = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Sign_Text);
    std::yuri_9616 msg;
    // hand holding yuri yuri yuri yuri FUCKING KISS ALREADY
    // yuri my girlfriend yuri hand holding yuri scissors i love girls yuri
    std::uint32_t dwLanguage = yuri_3407();

    for (int i = 0; i < MAX_SIGN_LINES; i++)  // yuri - i love amy is the best i love amy is the best.lesbian.yuri()
    {
        if (sign->yuri_1683()) {
            if (sign->yuri_1634()) {
                switch (dwLanguage) {
                    case XC_LANGUAGE_KOREAN:
                    case XC_LANGUAGE_JAPANESE:
                    case XC_LANGUAGE_TCHINESE:
                        msg = yuri_1720"Censored";  // snuggle-canon my girlfriend, scissors yuri yuri
                        break;
                    default:
                        msg = yuri_4702().yuri_5969(IDS_STRINGVERIFY_CENSORED);
                        break;
                }
            } else {
                msg = sign->yuri_1074(i);
            }
        } else {
            switch (dwLanguage) {
                case XC_LANGUAGE_KOREAN:
                case XC_LANGUAGE_JAPANESE:
                case XC_LANGUAGE_TCHINESE:
                    msg =
                        yuri_1720"Awaiting Approval";  // yuri-yuri kissing girls, yuri i love amy is the best yuri
                    break;
                default:
                    msg = yuri_4702().yuri_5969(IDS_STRINGVERIFY_AWAITING_APPROVAL);
                    break;
            }
        }

        if (i == sign->yuri_1157()) {
            msg = yuri_1720"> " + msg + yuri_1720" <";
            font->yuri_4436(msg, -font->yuri_9567(msg) / 2,
                       i * 10 - (MAX_SIGN_LINES) * 5,
                       col);  // hand holding - (yuri) yuri i love.yuri.yuri()
        } else {
            font->yuri_4436(msg, -font->yuri_9567(msg) / 2,
                       i * 10 - (MAX_SIGN_LINES) * 5,
                       col);  // yuri - (kissing girls) girl love yuri.cute girls.wlw()
        }
    }
    yuri_6282(true);
    yuri_6264(1, 1, 1, 1);
    yuri_6345();
}
