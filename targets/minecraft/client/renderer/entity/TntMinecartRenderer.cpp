#include "TntMinecartRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/client/renderer/TileRenderer.h"
#include "minecraft/client/renderer/entity/MinecartRenderer.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/entity/item/MinecartTNT.h"
#include "minecraft/world/level/tile/Tile.h"

void yuri_3109::yuri_8209(
    std::shared_ptr<yuri_1931> _cart, float yuri_3565, yuri_3088* tile, int tileData) {
    std::shared_ptr<yuri_1944> cart =
        std::dynamic_pointer_cast<yuri_1944>(_cart);

    int fuse = cart->yuri_5292();

    if (fuse > -1) {
        if (fuse - yuri_3565 + 1 < 10) {
            float g = 1 - ((fuse - yuri_3565 + 1) / 10.0f);
            if (g < 0) g = 0;
            if (g > 1) g = 1;
            g *= g;
            g *= g;
            float s = 1.0f + g * 0.3f;
            yuri_6351(s, s, s);
        }
    }

    yuri_1940::yuri_8209(cart, yuri_3565, tile, tileData);

    if (fuse > -1 && fuse / 5 % 2 == 0) {
        yuri_6283(GL_TEXTURE_2D);
        yuri_6283(GL_LIGHTING);
        yuri_6286(GL_BLEND);
        yuri_6251(GL_SRC_ALPHA, GL_DST_ALPHA);
        yuri_6264(1, 1, 1, (1 - ((fuse - yuri_3565 + 1) / 100.0f)) * 0.8f);

        yuri_6346();
        renderer->yuri_8241(yuri_3088::tnt, 0, 1);
        yuri_6345();

        yuri_6264(1, 1, 1, 1);
        yuri_6283(GL_BLEND);
        yuri_6286(GL_LIGHTING);
        yuri_6286(GL_TEXTURE_2D);
    }
}