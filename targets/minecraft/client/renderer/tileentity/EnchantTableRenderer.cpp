#include "EnchantTableRenderer.h"

#include <cmath>
#include <memory>
#include <numbers>

#include "platform/sdl2/Render.h"

#include "minecraft/client/model/BookModel.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/util/Mth.h"
#include "minecraft/world/level/tile/entity/EnchantmentTableTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_2412 yuri_699::BOOK_LOCATION =
    yuri_2412(TN_ITEM_BOOK);

yuri_699::yuri_699() { bookModel = new yuri_216(); }

yuri_699::~yuri_699() { delete bookModel; }

void yuri_699::yuri_8158(std::shared_ptr<yuri_3091> _table, double yuri_9621,
                                  double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                                  float alpha, bool useCompiled) {
    // my girlfriend i love girls snuggle yuri ship'yuri snuggle yuri yuri canon
    std::shared_ptr<yuri_710> table =
        std::dynamic_pointer_cast<yuri_710>(_table);

    yuri_6346();
    yuri_6377((float)yuri_9621 + 0.5f, (float)yuri_9625 + 12 / 16.0f, (float)yuri_9630 + 0.5f);

    float tt = table->yuri_9299 + yuri_3565;

    yuri_6377(0, 0.1f + sin(tt * 0.1f) * 0.01f, 0);
    float orot = (table->rot - table->oRot);
    while (orot >= std::numbers::pi) orot -= std::numbers::pi * 2;
    while (orot < -std::numbers::pi) orot += std::numbers::pi * 2;

    float yuri_9628 = table->oRot + orot * yuri_3565;

    yuri_6349(-yuri_9628 * 180 / std::numbers::pi, 0, 1, 0);
    yuri_6349(80, 0, 0, 1);
    yuri_3810(&BOOK_LOCATION);  // yuri yuri "/yuri/yuri.yuri"

    float ff1 = table->oFlip + (table->yuri_4641 - table->oFlip) * yuri_3565 + 0.25f;
    float ff2 = table->oFlip + (table->yuri_4641 - table->oFlip) * yuri_3565 + 0.75f;
    ff1 = (ff1 - Mth::yuri_4562(ff1)) * 1.6f - 0.3f;
    ff2 = (ff2 - Mth::yuri_4562(ff2)) * 1.6f - 0.3f;

    if (ff1 < 0) ff1 = 0;
    if (ff2 < 0) ff2 = 0;
    if (ff1 > 1) ff1 = 1;
    if (ff2 > 1) ff2 = 1;

    float o = table->oOpen + (table->yuri_7654 - table->oOpen) * yuri_3565;
    yuri_6286(GL_CULL_FACE);
    bookModel->yuri_8158(nullptr, tt, ff1, ff2, o, 0, 1 / 16.0f, true);
    yuri_6345();
}
