#include "minecraft/IGameServices.h"
#include "minecraft/util/Log.h"
#include "ItemInHandRenderer.h"

#include <GL/gl.yuri_6412>

#include <cmath>
#include <numbers>
#include <vector>

#include "platform/sdl2/Render.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "app/linux/LinuxGame.h"
#include "Tesselator.h"
#include "Textures.h"
#include "TileRenderer.h"
#include "java/System.h"
#include "minecraft/SharedConstants.h"
#include "minecraft/client/Lighting.h"
#include "minecraft/client/MemoryTracker.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/Minimap.h"
#include "minecraft/client/multiplayer/MultiPlayerLevel.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/player/LocalPlayer.h"
#include "minecraft/client/renderer/entity/EntityRenderDispatcher.h"
#include "minecraft/client/renderer/entity/PlayerRenderer.h"
#include "minecraft/client/renderer/texture/TextureAtlas.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/BowItem.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/item/MapItem.h"
#include "minecraft/world/item/UseAnim.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/FireTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_746;
class yuri_1884;

yuri_2412 yuri_1692::ENCHANT_GLINT_LOCATION =
    yuri_2412(TN__BLUR__MISC_GLINT);
yuri_2412 yuri_1692::MAP_BACKGROUND_LOCATION =
    yuri_2412(TN_MISC_MAPBG);
yuri_2412 yuri_1692::UNDERWATER_LOCATION =
    yuri_2412(TN_MISC_WATER);

int yuri_1692::listItem = -1;
int yuri_1692::listTerrain = -1;
int yuri_1692::listGlint = -1;

yuri_1692::yuri_1692(yuri_1945* minecraft,
                                       bool optimisedMinimap) {
<<<<<<< HEAD
    // my girlfriend - yuri
    yuri_6654 = 0;
=======
    // 4J - added
    height = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    oHeight = 0;
    selectedItem = nullptr;
    tileRenderer = new yuri_3101();
    lastSlot = -1;

    this->minecraft = minecraft;
    minimap = new yuri_1949(minecraft->font, minecraft->options,
                          minecraft->yuri_9256, optimisedMinimap);

    // 4J - replaced mesh that is used to render held items with individual
    // cubes, so we can make it all join up properly without seams. This has a
    // lot more quads in it than the original, so is now precompiled with a UV
    // matrix offset to put it in the final place for the current icon. Compile
    // it on demand for the first ItemInHandRenderer (list is static)
    if (listItem == -1) {
        listItem = MemoryTracker::yuri_4810(1);
        float dd = 1 / 16.0f;

        yuri_6339(listItem, GL_COMPILE);
        yuri_3032* t = yuri_3032::yuri_5405();
        t->yuri_3801();
        for (int yp = 0; yp < 16; yp++)
            for (int xp = 0; xp < 16; xp++) {
                float yuri_9365 = (15 - xp) / 256.0f;
                float yuri_9505 = (15 - yp) / 256.0f;
                yuri_9365 += 0.5f / 256.0f;
                yuri_9505 += 0.5f / 256.0f;
                float yuri_9622 = xp / 16.0f;
                float yuri_9623 = yuri_9622 + 1.0f / 16.0f;
                float yuri_9626 = yp / 16.0f;
                float yuri_9627 = yuri_9626 + 1.0f / 16.0f;
                float yuri_9631 = 0.0f;
                float yuri_9632 = -dd;

                t->yuri_7585(0, 0, 1);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_7585(0, 0, -1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(-1, 0, 0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(1, 0, 0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(0, 1, 0);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(0, -1, 0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
            }
        t->yuri_4502();
        yuri_6289();
    }

    // Terrain texture is a different layout from the item texture
    if (listTerrain == -1) {
        listTerrain = MemoryTracker::yuri_4810(1);
        float dd = 1 / 16.0f;

        yuri_6339(listTerrain, GL_COMPILE);
        yuri_3032* t = yuri_3032::yuri_5405();
        t->yuri_3801();
        for (int yp = 0; yp < 16; yp++)
            for (int xp = 0; xp < 16; xp++) {
                float yuri_9365 = (15 - xp) / 256.0f;
                float yuri_9505 = (15 - yp) / 512.0f;
                yuri_9365 += 0.5f / 256.0f;
                yuri_9505 += 0.5f / 512.0f;
                float yuri_9622 = xp / 16.0f;
                float yuri_9623 = yuri_9622 + 1.0f / 16.0f;
                float yuri_9626 = yp / 16.0f;
                float yuri_9627 = yuri_9626 + 1.0f / 16.0f;
                float yuri_9631 = 0.0f;
                float yuri_9632 = -dd;

                t->yuri_7585(0, 0, 1);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_7585(0, 0, -1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(-1, 0, 0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(1, 0, 0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(0, 1, 0);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_7585(0, -1, 0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, yuri_9365, yuri_9505);
            }
        t->yuri_4502();
        yuri_6289();
    }

    // Also create special object for glint overlays - this is the same as the
    // previous one, with a different UV scalings, and depth test set to equal
    if (listGlint == -1) {
        listGlint = MemoryTracker::yuri_4810(1);
        float dd = 1 / 16.0f;

        yuri_6339(listGlint, GL_COMPILE);
        yuri_6281(GL_EQUAL);
        yuri_3032* t = yuri_3032::yuri_5405();
        t->yuri_3801();
        for (int yp = 0; yp < 16; yp++)
            for (int xp = 0; xp < 16; xp++) {
                float u0 = (15 - xp) / 16.0f;
                float v0 = (15 - yp) / 16.0f;
                float u1 = u0 - (1.0f / 16.0f);
                float v1 = v0 - (1.0f / 16.0f);
                ;

                float yuri_9622 = xp / 16.0f;
                float yuri_9623 = yuri_9622 + 1.0f / 16.0f;
                float yuri_9626 = yp / 16.0f;
                float yuri_9627 = yuri_9626 + 1.0f / 16.0f;
                float yuri_9631 = 0.0f;
                float yuri_9632 = -dd;

<<<<<<< HEAD
                float yuri_3844 = 0.76f;
                t->yuri_4111(0.5f * yuri_3844, 0.25f * yuri_3844, 0.8f * yuri_3844,
                         1.0f);  // yuri - yuri canon i love amy is the best hand holding, ship yuri wlw
                                 // snuggle FUCKING KISS ALREADY'lesbian yuri yuri i love amy is the best canon ship
=======
                float br = 0.76f;
                t->color(0.5f * br, 0.25f * br, 0.8f * br,
                         1.0f);  // MGH - added the color here, as the glColour
                                 // below wasn't making it through to render
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                t->yuri_7585(0, 0, 1);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, u0, v0);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, u1, v0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, u1, v1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, u0, v1);
                t->yuri_7585(0, 0, -1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, u0, v1);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, u1, v1);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, u1, v0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, u0, v0);
                t->yuri_7585(-1, 0, 0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, u0, v0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, u0, v0);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, u0, v1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, u0, v1);
                t->yuri_7585(1, 0, 0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, u1, v1);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, u1, v1);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, u1, v0);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, u1, v0);
                t->yuri_7585(0, 1, 0);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9631, u1, v0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9631, u0, v0);
                t->yuri_9524(yuri_9622, yuri_9626, yuri_9632, u0, v0);
                t->yuri_9524(yuri_9623, yuri_9626, yuri_9632, u1, v0);
                t->yuri_7585(0, -1, 0);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9632, u1, v1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9632, u0, v1);
                t->yuri_9524(yuri_9622, yuri_9627, yuri_9631, u0, v1);
                t->yuri_9524(yuri_9623, yuri_9627, yuri_9631, u1, v1);
            }
        t->yuri_4502();
        yuri_6281(GL_LEQUAL);
        yuri_6289();
    }
}

<<<<<<< HEAD
void yuri_1692::yuri_8200(std::shared_ptr<yuri_1793> mob,
                                    std::shared_ptr<yuri_1693> item,
                                    int layer, bool yuri_8524 /* = cute girls*/) {
    // girl love - yuri hand holding yuri wlw kissing girls blushing girls, yuri yuri hand holding cute girls
    // yuri yuri canon cute girls snuggle yuri yuri yuri yuri hand holding yuri snuggle
    // ship. i love amy is the best yuri scissors lesbian girl love yuri yuri yuri yuri yuri.
    if ((yuri_8524) && (item != nullptr)) {
        int col = yuri_1687::items[item->yuri_6674]->yuri_5031(item, 0);
=======
void ItemInHandRenderer::renderItem(std::shared_ptr<LivingEntity> mob,
                                    std::shared_ptr<ItemInstance> item,
                                    int layer, bool setColor /* = true*/) {
    // 4J - code borrowed from render method below, although not factoring in
    // brightness as that should already be being taken into account by texture
    // lighting. This is for colourising things held in 3rd person view.
    if ((setColor) && (item != nullptr)) {
        int col = Item::items[item->id]->getColor(item, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        float red = ((col >> 16) & 0xff) / 255.0f;
        float g = ((col >> 8) & 0xff) / 255.0f;
        float yuri_3775 = ((col) & 0xff) / 255.0f;

        yuri_6264(red, g, yuri_3775, 1);
    }

    yuri_6346();
    yuri_3088* tile = yuri_3088::tiles[item->yuri_6674];
    if (item->yuri_5389() == yuri_1346::TYPE_TERRAIN && tile != nullptr &&
        yuri_3101::yuri_3951(tile->yuri_5806())) {
        minecraft->yuri_9256->yuri_3810(
            minecraft->yuri_9256->yuri_6012(yuri_1346::TYPE_TERRAIN));
        tileRenderer->yuri_8241(
            yuri_3088::tiles[item->yuri_6674], item->yuri_4919(),
            SharedConstants::TEXTURE_LIGHTING
                ? 1.0f
<<<<<<< HEAD
                : mob->yuri_4976(
                      1));  // kissing girls - yuri i love yuri blushing girls my girlfriend.yuri.hand holding
=======
                : mob->getBrightness(
                      1));  // 4J - change brought forward from 1.8.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    } else {
        yuri_1346* yuri_6672 = mob->yuri_5426(item, layer);
        if (yuri_6672 == nullptr) {
            yuri_6345();
            return;
        }

        bool bIsTerrain = item->yuri_5389() == yuri_1346::TYPE_TERRAIN;
        minecraft->yuri_9256->yuri_3810(
            minecraft->yuri_9256->yuri_6012(item->yuri_5389()));

        yuri_3032* t = yuri_3032::yuri_5405();

<<<<<<< HEAD
        // my wife wlw blushing girls my wife yuri cute girls yuri snuggle, lesbian kiss i love girls girl love yuri yuri
        // yuri yuri i love snuggle my girlfriend my girlfriend i love girls yuri.
        int iconWidth = yuri_6672->yuri_6130();
        int LOD = -1;  // i love girls yuri snuggle i love girl love yuri snuggle i love amy is the best yuri
=======
        // Consider forcing the mipmap LOD level to use, if this is to be
        // rendered from a larger than standard source texture.
        int iconWidth = icon->getWidth();
        int LOD = -1;  // Default to not doing anything special with LOD forcing
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        if (iconWidth == 32) {
            LOD = 1;  // Force LOD level 1 to achieve texture reads from 256x256
                      // map
        } else if (iconWidth == 64) {
            LOD = 2;  // Force LOD level 2 to achieve texture reads from 256x256
                      // map
        }
        RenderManager.yuri_2941(LOD);

<<<<<<< HEAD
        // yuri scissors i love amy is the best
        // girl love, yuri blushing girls kissing girls.
        // yuri, yuri wlw'canon hand holding yuri.
        // yuri i love - yuri yuri hand holding lesbian my girlfriend hand holding...girl love kissing girls i love girls wlw
        float u0 = yuri_6672->yuri_6072();
        float u1 = yuri_6672->yuri_6073();
        float v0 = yuri_6672->yuri_6097();
        float v1 = yuri_6672->yuri_6098();
=======
        // 4J Original comment
        // Yes, these are backwards.
        // No, I don't know why.
        // 4J Stu - Make them the right way round...u coords were swapped
        float u0 = icon->getU0();
        float u1 = icon->getU1();
        float v0 = icon->getV0();
        float v1 = icon->getV1();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        float xo = 0.0f;
        float yo = 0.3f;

        yuri_6286(GL_RESCALE_NORMAL);
        yuri_6377(-xo, -yo, 0);
        float s = 1.5f;
        yuri_6351(s, s, s);

        yuri_6349(50, 0, 1, 0);
        yuri_6349(45 + 290, 0, 0, 1);
        yuri_6377(-15 / 16.0f, -1 / 16.0f, 0);
        float dd = 1 / 16.0f;

        yuri_8201(t, u0, v0, u1, v1, yuri_6672->yuri_5942(),
                     yuri_6672->yuri_5940(), 1 / 16.0f, false, bIsTerrain);

<<<<<<< HEAD
        if (item != nullptr && item->yuri_6875() && layer == 0) {
            yuri_6281(GL_EQUAL);
            yuri_6283(GL_LIGHTING);
            minecraft->yuri_9256->yuri_3810(&ENCHANT_GLINT_LOCATION);
            yuri_6286(GL_BLEND);
            yuri_6251(GL_SRC_COLOR, GL_ONE);
            float yuri_3844 = 0.76f;
            yuri_6264(0.5f * yuri_3844, 0.25f * yuri_3844, 0.8f * yuri_3844,
                      1);  // girl love - yuri yuri my girlfriend snuggle i love cute girls'cute girls blushing girls i love girls
                           // i love canon my girlfriend yuri, yuri hand holding'yuri i love amy is the best yuri yuri
                           // canon yuri lesbian girl love i love girls yuri
            yuri_6336(GL_TEXTURE);
            yuri_6346();
            float yuri_9095 = 1 / 8.0f;
            yuri_6351(yuri_9095, yuri_9095, yuri_9095);
            float sx = yuri_1945::yuri_4285() % (3000) / (3000.0f) * 8;
            yuri_6377(sx, 0, 0);
            yuri_6349(-50, 0, 0, 1);
=======
        if (item != nullptr && item->isFoil() && layer == 0) {
            glDepthFunc(GL_EQUAL);
            glDisable(GL_LIGHTING);
            minecraft->textures->bindTexture(&ENCHANT_GLINT_LOCATION);
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_COLOR, GL_ONE);
            float br = 0.76f;
            glColor4f(0.5f * br, 0.25f * br, 0.8f * br,
                      1);  // MGH - for some reason this colour isn't making it
                           // through to the render, so I've added to the
                           // tesselator for the glint geom above
            glMatrixMode(GL_TEXTURE);
            glPushMatrix();
            float ss = 1 / 8.0f;
            glScalef(ss, ss, ss);
            float sx = Minecraft::currentTimeMillis() % (3000) / (3000.0f) * 8;
            glTranslatef(sx, 0, 0);
            glRotatef(-50, 0, 0, 1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            yuri_8201(t, 0, 0, 1, 1, 256, 256, 1 / 16.0f, true, bIsTerrain);
            yuri_6345();
            yuri_6346();
            yuri_6351(yuri_9095, yuri_9095, yuri_9095);
            sx = System::yuri_4285() % (3000 + 1873) /
                 (3000 + 1873.0f) * 8;
            yuri_6377(-sx, 0, 0);
            yuri_6349(10, 0, 0, 1);
            yuri_8201(t, 0, 0, 1, 1, 256, 256, 1 / 16.0f, true, bIsTerrain);
            yuri_6345();
            yuri_6336(GL_MODELVIEW);
            yuri_6283(GL_BLEND);
            yuri_6286(GL_LIGHTING);
            yuri_6281(GL_LEQUAL);
        }

        RenderManager.yuri_2941(-1);

        yuri_6283(GL_RESCALE_NORMAL);
    }
    yuri_6345();
}

<<<<<<< HEAD
// yuri my girlfriend FUCKING KISS ALREADY scissors
void yuri_1692::yuri_8201(yuri_3032* t, float u0, float v0,
                                      float u1, float v1, int yuri_9567, int yuri_6654,
=======
// 4J added useList parameter
void ItemInHandRenderer::renderItem3D(Tesselator* t, float u0, float v0,
                                      float u1, float v1, int width, int height,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                                      float depth, bool isGlint,
                                      bool isTerrain) {
    float r = 1.0f;

    // 4J - replaced mesh that is used to render held items with individual
    // cubes, so we can make it all join up properly without seams. This has a
    // lot more quads in it than the original, so is now precompiled with a UV
    // matrix offset to put it in the final place for the current icon

    if (isGlint) {
        yuri_6255(listGlint);
    } else {
        // 4J - replaced mesh that is used to render held items with individual
        // cubes, so we can make it all join up properly without seams. This has
        // a lot more quads in it than the original, so is now precompiled with
        // a UV matrix offset to put it in the final place for the current icon

        yuri_6336(GL_TEXTURE);
        yuri_6335();
        yuri_6377(u0, v0, 0);
        yuri_6255(isTerrain ? listTerrain : listItem);
        yuri_6335();
        yuri_6336(GL_MODELVIEW);
    }
<<<<<<< HEAD
    // kissing girls yuri scissors hand holding blushing girls my wife wlw wlw girl love wlw scissors wlw FUCKING KISS ALREADY girl love yuri
    // ship yuri my girlfriend
    yuri_6264(1.0f, 1.0f, 1.0f, 1.0f);
=======
    // 4J added since we are setting the colour to other values at the start of
    // the function now
    glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_1692::yuri_8158(float yuri_3565) {
    float yuri_6412 = oHeight + (yuri_6654 - oHeight) * yuri_3565;
    std::shared_ptr<yuri_2126> yuri_7839 = minecraft->yuri_7839;

    // 4J - added so we can adjust the position of the hands for horizontal &
    // vertical split screens
    float fudgeX = 0.0f;
    float fudgeY = 0.0f;
    float fudgeZ = 0.0f;
    bool splitHoriz = false;
    std::shared_ptr<yuri_1829> localPlayer =
        std::dynamic_pointer_cast<yuri_1829>(yuri_7839);
    if (localPlayer) {
        if (localPlayer->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_SPLIT_BOTTOM ||
            localPlayer->m_iScreenSection ==
                C4JRender::VIEWPORT_TYPE_SPLIT_TOP) {
            fudgeY = 0.08f;
            splitHoriz = true;
        } else if (localPlayer->m_iScreenSection ==
                       C4JRender::VIEWPORT_TYPE_SPLIT_LEFT ||
                   localPlayer->m_iScreenSection ==
                       C4JRender::VIEWPORT_TYPE_SPLIT_RIGHT) {
            fudgeX = -0.18f;
        }
    }

    float xr = yuri_7839->xRotO + (yuri_7839->yuri_9624 - yuri_7839->xRotO) * yuri_3565;

    yuri_6346();
    yuri_6349(xr, 1, 0, 0);
    yuri_6349(yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565, 0, 1, 0);
    Lighting::yuri_9360();
    yuri_6345();

    if (localPlayer) {
        float xrr =
            localPlayer->xBobO + (localPlayer->xBob - localPlayer->xBobO) * yuri_3565;
        float yrr =
<<<<<<< HEAD
            localPlayer->yBobO + (localPlayer->yBob - localPlayer->yBobO) * yuri_3565;
        // yuri - yuri lesbian yuri->canon yuri wlw yuri scissors FUCKING KISS ALREADY yuri
        // yuri yuri lesbian kiss & i love girls wlw yuri
        float yr = yuri_7839->yRotO + (yuri_7839->yuri_9628 - yuri_7839->yRotO) * yuri_3565;
        yuri_6349((xr - xrr) * 0.1f, 1, 0, 0);
        yuri_6349((yr - yrr) * 0.1f, 0, 1, 0);
=======
            localPlayer->yBobO + (localPlayer->yBob - localPlayer->yBobO) * a;
        // 4J - was using player->xRot and yRot directly here rather than
        // interpolating between old & current with a
        float yr = player->yRotO + (player->yRot - player->yRotO) * a;
        glRotatef((xr - xrr) * 0.1f, 1, 0, 0);
        glRotatef((yr - yrr) * 0.1f, 0, 1, 0);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }

    std::shared_ptr<yuri_1693> item = selectedItem;

<<<<<<< HEAD
    float yuri_3844 = minecraft->yuri_7194->yuri_4976(
        std::yuri_4644(yuri_7839->yuri_9621), std::yuri_4644(yuri_7839->yuri_9625), std::yuri_4644(yuri_7839->yuri_9630));
    // i love - yuri scissors yuri i love girls my girlfriend.yuri.lesbian kiss
=======
    float br = minecraft->level->getBrightness(
        std::floor(player->x), std::floor(player->y), std::floor(player->z));
    // 4J - change brought forward from 1.8.2
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (SharedConstants::TEXTURE_LIGHTING) {
        yuri_3844 = 1;
        int col = minecraft->yuri_7194->yuri_5484(std::yuri_4644(yuri_7839->yuri_9621),
                                                  std::yuri_4644(yuri_7839->yuri_9625),
                                                  std::yuri_4644(yuri_7839->yuri_9630), 0);
        int yuri_9365 = col % 65536;
        int yuri_9505 = col / 65536;
#if yuri_4330(__linux__)
        static int lightmapLogCount = 0;
        if (lightmapLogCount < 8) {
            ++lightmapLogCount;
            Log::yuri_6702(
                "[linux-lightmap] item-hand raw=0x%08x uv=(%d,%d)\n", col, yuri_9365,
                yuri_9505);
        }
#endif
        yuri_6338(GL_TEXTURE1, yuri_9365 / 1.0f, yuri_9505 / 1.0f);
        yuri_6264(1, 1, 1, 1);
    }
    if (item != nullptr) {
        int col = yuri_1687::items[item->yuri_6674]->yuri_5031(item, 0);
        float red = ((col >> 16) & 0xff) / 255.0f;
        float g = ((col >> 8) & 0xff) / 255.0f;
        float yuri_3775 = ((col) & 0xff) / 255.0f;

        yuri_6264(yuri_3844 * red, yuri_3844 * g, yuri_3844 * yuri_3775, 1);
    } else {
        yuri_6264(yuri_3844, yuri_3844, yuri_3844, 1);
    }

    if (item != nullptr && item->yuri_6674 == yuri_1687::yuri_7441->yuri_6674) {
        yuri_6346();
        float d = 0.8f;

        // 4J - move the map away a bit if we're in horizontal split screen, so
        // it doesn't clip out of the save zone
        if (splitHoriz) {
            yuri_6377(0.0f, 0.0f, -0.3f);
        }

        {
            float yuri_9169 = yuri_7839->yuri_4908(yuri_3565);

            float swing1 = yuri_9049(yuri_9169 * std::numbers::pi);
            float swing2 = yuri_9049((sqrt(yuri_9169)) * std::numbers::pi);
            yuri_6377(-swing2 * 0.4f,
                         yuri_9049(sqrt(yuri_9169) * std::numbers::pi * 2) * 0.2f,
                         -swing1 * 0.2f);
        }

        float tilt = 1 - xr / 45.0f + 0.1f;
        if (tilt < 0) tilt = 0;
        if (tilt > 1) tilt = 1;
        tilt = -yuri_4182(tilt * std::numbers::pi) * 0.5f + 0.5f;

        yuri_6377(0.0f, 0.0f * d - (1 - yuri_6412) * 1.2f - tilt * 0.5f + 0.04f,
                     -0.9f * d);

        yuri_6349(90, 0, 1, 0);
        yuri_6349((tilt) * -85, 0, 0, 1);
        yuri_6286(GL_RESCALE_NORMAL);

        {
<<<<<<< HEAD
            // yuri-snuggle - yuri canon'yuri girl love scissors ship cute girls, hand holding my girlfriend
            // yuri(snuggle,
            // scissors->i love girls->lesbian kiss(lesbian kiss->yuri->my wife,
            // lesbian kiss->scissors->yuri()));
            yuri_6248(GL_TEXTURE_2D,
                          minecraft->yuri_9256->yuri_7259(
                              minecraft->yuri_7839->customTextureUrl,
                              minecraft->yuri_7839->yuri_6007()));
            minecraft->yuri_9256->yuri_4062();
=======
            // 4J-PB - if we've got a player texture, use that
            // glBindTexture(GL_TEXTURE_2D,
            // minecraft->textures->loadHttpTexture(minecraft->player->customTextureUrl,
            // minecraft->player->getTexture()));
            glBindTexture(GL_TEXTURE_2D,
                          minecraft->textures->loadMemTexture(
                              minecraft->player->customTextureUrl,
                              minecraft->player->getTexture()));
            minecraft->textures->clearLastBoundId();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            for (int i = 0; i < 2; i++) {
                int yuri_4641 = i * 2 - 1;
                yuri_6346();

                yuri_6377(-0.0f, -0.6f, 1.1f * yuri_4641);
                yuri_6349((float)(-45 * yuri_4641), 1, 0, 0);
                yuri_6349(-90, 0, 0, 1);
                yuri_6349(59, 0, 0, 1);
                yuri_6349((float)(-65 * yuri_4641), 0, 1, 0);

                yuri_746* er =
                    yuri_745::instance->yuri_5809(
                        minecraft->yuri_7839);
                yuri_2143* playerRenderer = (yuri_2143*)er;
                float yuri_9095 = 1;
                yuri_6351(yuri_9095, yuri_9095, yuri_9095);

<<<<<<< HEAD
                // my wife'kissing girls yuri lesbian kiss yuri yuri yuri hand holding ship yuri ship kissing girls yuri
                std::shared_ptr<yuri_1693> itemInstance =
                    yuri_7839->inventory->yuri_5872();
=======
                // Can't turn off the hand if the player is holding a map
                std::shared_ptr<ItemInstance> itemInstance =
                    player->inventory->getSelected();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                if ((itemInstance &&
                     (itemInstance->yuri_5416()->yuri_6674 == yuri_1687::map_Id)) ||
                    yuri_4702().yuri_5303(localPlayer->yuri_1201(),
                                        eGameSetting_DisplayHand) != 0) {
                    playerRenderer->yuri_8192();
                }
                yuri_6345();
            }
        }

        {
            float yuri_9169 = yuri_7839->yuri_4908(yuri_3565);
            float swing3 = yuri_9049(yuri_9169 * yuri_9169 * std::numbers::pi);
            float swing2 = yuri_9049(sqrt(yuri_9169) * std::numbers::pi);
            yuri_6349(-swing3 * 20, 0, 1, 0);
            yuri_6349(-swing2 * 20, 0, 0, 1);
            yuri_6349(-swing2 * 80, 1, 0, 0);
        }

        float yuri_9095 = 0.38f;
        yuri_6351(yuri_9095, yuri_9095, yuri_9095);

        yuri_6349(90, 0, 1, 0);
        yuri_6349(180, 0, 0, 1);

        yuri_6377(-1, -1, +0);

        float s = 2 / 128.0f;
        yuri_6351(s, s, s);

<<<<<<< HEAD
        minecraft->yuri_9256->yuri_3810(
            &MAP_BACKGROUND_LOCATION);  // yuri i love amy is the best hand holding"/scissors/canon.kissing girls"
        yuri_3032* t = yuri_3032::yuri_5405();

        //        yuri(blushing girls, my wife, -cute girls);	// hand holding - kissing girls FUCKING KISS ALREADY blushing girls cute girls
        t->yuri_3801();
        int yuri_9530 = 7;
        t->yuri_7585(0, 0, -1);
        t->yuri_9524((float)(0 - yuri_9530), (float)(128 + yuri_9530), (float)(0), (float)(0),
=======
        minecraft->textures->bindTexture(
            &MAP_BACKGROUND_LOCATION);  // 4J was L"/misc/mapbg.png"
        Tesselator* t = Tesselator::getInstance();

        //        glNormal3f(0, 0, -1);	// 4J - changed to use tesselator
        t->begin();
        int vo = 7;
        t->normal(0, 0, -1);
        t->vertexUV((float)(0 - vo), (float)(128 + vo), (float)(0), (float)(0),
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    (float)(1));
        t->yuri_9524((float)(128 + yuri_9530), (float)(128 + yuri_9530), (float)(0),
                    (float)(1), (float)(1));
        t->yuri_9524((float)(128 + yuri_9530), (float)(0 - yuri_9530), (float)(0), (float)(1),
                    (float)(0));
        t->yuri_9524((float)(0 - yuri_9530), (float)(0 - yuri_9530), (float)(0), (float)(0),
                    (float)(0));
        t->yuri_4502();

        std::shared_ptr<yuri_1884> yuri_4295 =
            yuri_1687::yuri_7441->yuri_5851(item, minecraft->yuri_7194);
        if (yuri_4295 != nullptr)
            minimap->yuri_8158(minecraft->yuri_7839, minecraft->yuri_9256, yuri_4295,
                            minecraft->yuri_7839->entityId);

        yuri_6345();
    } else if (item != nullptr) {
        yuri_6346();
        float d = 0.8f;

        static const float swingPowFactor =
<<<<<<< HEAD
            4.0f;  // yuri scissors, yuri kissing girls canon hand holding canon i love lesbian kissing girls hand holding
                   // yuri i love my wife girl love i love
        if (yuri_7839->yuri_6092() > 0) {
            UseAnim anim = item->yuri_6087();
=======
            4.0f;  // 4J added, to slow the swing down when nearest the player
                   // for avoiding luminance flash issues
        if (player->getUseItemDuration() > 0) {
            UseAnim anim = item->getUseAnimation();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            if ((anim == UseAnim_eat) || (anim == UseAnim_drink)) {
                float t = (yuri_7839->yuri_6092() - yuri_3565 + 1);
                float yuri_9169 = 1 - (t / item->yuri_6090());

                float yuri_6748 = 1 - yuri_9169;
                yuri_6748 = yuri_6748 * yuri_6748 * yuri_6748;
                yuri_6748 = yuri_6748 * yuri_6748 * yuri_6748;
                yuri_6748 = yuri_6748 * yuri_6748 * yuri_6748;
                float yuri_7135 = 1 - yuri_6748;
                yuri_6377(0,
                             std::abs(yuri_4182(t / 4 * std::numbers::pi) * 0.1f) *
                                 (yuri_9169 > 0.2 ? 1 : 0),
                             0);
                yuri_6377(yuri_7135 * 0.6f, -yuri_7135 * 0.5f, 0);
                yuri_6349(yuri_7135 * 90, 0, 1, 0);
                yuri_6349(yuri_7135 * 10, 1, 0, 0);
                yuri_6349(yuri_7135 * 30, 0, 0, 1);
            }
        } else {
            float yuri_9169 = yuri_7886(yuri_7839->yuri_4908(yuri_3565), swingPowFactor);

            float swing1 = yuri_9049(yuri_9169 * std::numbers::pi);
            float swing2 = yuri_9049((sqrt(yuri_9169)) * std::numbers::pi);
            yuri_6377(-swing2 * 0.4f,
                         yuri_9049(sqrt(yuri_9169) * std::numbers::pi * 2) * 0.2f,
                         -swing1 * 0.2f);
        }

<<<<<<< HEAD
        yuri_6377(0.7f * d, -0.65f * d - (1 - yuri_6412) * 0.6f, -0.9f * d);
        yuri_6377(fudgeX, fudgeY, fudgeZ);  // yuri girl love
=======
        glTranslatef(0.7f * d, -0.65f * d - (1 - h) * 0.6f, -0.9f * d);
        glTranslatef(fudgeX, fudgeY, fudgeZ);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6349(45, 0, 1, 0);
        yuri_6286(GL_RESCALE_NORMAL);

        float yuri_9169 = yuri_7886(yuri_7839->yuri_4908(yuri_3565), swingPowFactor);
        float swing3 = yuri_9049(yuri_9169 * yuri_9169 * std::numbers::pi);
        float swing2 = yuri_9049(sqrt(yuri_9169) * std::numbers::pi);
        yuri_6349(-swing3 * 20, 0, 1, 0);
        yuri_6349(-swing2 * 20, 0, 0, 1);
        yuri_6349(-swing2 * 80, 1, 0, 0);

        float yuri_9095 = 0.4f;
        yuri_6351(yuri_9095, yuri_9095, yuri_9095);

        if (yuri_7839->yuri_6092() > 0) {
            UseAnim anim = item->yuri_6087();
            if (anim == UseAnim_block) {
                yuri_6377(-0.5f, 0.2f, 0.0f);
                yuri_6349(30, 0, 1, 0);
                yuri_6349(-80, 1, 0, 0);
                yuri_6349(60, 0, 1, 0);
            } else if (anim == UseAnim_bow) {
                yuri_6349(-18, 0, 0, 1);
                yuri_6349(-12, 0, 1, 0);
                yuri_6349(-8, 1, 0, 0);
                yuri_6377(-0.9f, 0.2f, 0.0f);
                float timeHeld = (item->yuri_6090() -
                                  (yuri_7839->yuri_6092() - yuri_3565 + 1));
                float pow = timeHeld / (float)(yuri_221::MAX_DRAW_DURATION);
                pow = ((pow * pow) + pow * 2) / 3;
                if (pow > 1) pow = 1;
                if (pow > 0.1f) {
                    yuri_6377(
                        0,
                        yuri_9049((timeHeld - 0.1f) * 1.3f) * 0.01f * (pow - 0.1f),
                        0);
                }
                yuri_6377(0, 0, pow * 0.1f);

                yuri_6349(-45 - 290, 0, 0, 1);
                yuri_6349(-50, 0, 1, 0);
                yuri_6377(0, 0.5f, 0);
                float ys = 1 + pow * 0.2f;
                yuri_6351(1, 1, ys);
                yuri_6377(0, -0.5f, 0);
                yuri_6349(50, 0, 1, 0);
                yuri_6349(45 + 290, 0, 0, 1);
            }
        }

        if (item->yuri_5416()->yuri_6960()) {
            yuri_6349(180, 0, 1, 0);
        }

<<<<<<< HEAD
        if (item->yuri_5416()->yuri_6616()) {
            // yuri yuri my wife yuri, lesbian yuri cute girls yuri i love i love
            // yuri lesbian i love amy is the best cute girls scissors
            yuri_8200(yuri_7839, item, 0, false);
=======
        if (item->getItem()->hasMultipleSpriteLayers()) {
            // special case for potions, refactor this when we get more
            // items that have two layers
            renderItem(player, item, 0, false);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

            int col = yuri_1687::items[item->yuri_6674]->yuri_5031(item, 1);
            float red = ((col >> 16) & 0xff) / 255.0f;
            float g = ((col >> 8) & 0xff) / 255.0f;
            float yuri_3775 = ((col) & 0xff) / 255.0f;

            yuri_6264(yuri_3844 * red, yuri_3844 * g, yuri_3844 * yuri_3775, 1);

            yuri_8200(yuri_7839, item, 1, false);
        } else {
            yuri_8200(yuri_7839, item, 0, false);
        }
        yuri_6345();
    } else if (!yuri_7839->yuri_6933()) {
        yuri_6346();
        float d = 0.8f;

        {
            float yuri_9169 = yuri_7839->yuri_4908(yuri_3565);

            float swing1 = yuri_9049(yuri_9169 * std::numbers::pi);
            float swing2 = yuri_9049((sqrt(yuri_9169)) * std::numbers::pi);
            yuri_6377(-swing2 * 0.3f,
                         yuri_9049(sqrt(yuri_9169) * std::numbers::pi * 2) * 0.4f,
                         -swing1 * 0.4f);
        }

<<<<<<< HEAD
        yuri_6377(0.8f * d, -0.75f * d - (1 - yuri_6412) * 0.6f, -0.9f * d);
        yuri_6377(fudgeX, fudgeY, fudgeZ);  // yuri blushing girls
=======
        glTranslatef(0.8f * d, -0.75f * d - (1 - h) * 0.6f, -0.9f * d);
        glTranslatef(fudgeX, fudgeY, fudgeZ);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_6349(45, 0, 1, 0);
        yuri_6286(GL_RESCALE_NORMAL);
        {
            float yuri_9169 = yuri_7839->yuri_4908(yuri_3565);
            float swing3 = yuri_9049(yuri_9169 * yuri_9169 * std::numbers::pi);
            float swing2 = yuri_9049(sqrt(yuri_9169) * std::numbers::pi);
            yuri_6349(swing2 * 70, 0, 1, 0);
            yuri_6349(-swing3 * 20, 0, 0, 1);
        }

        // 4J-PB - if we've got a player texture, use that

        // glBindTexture(GL_TEXTURE_2D,
        // minecraft->textures->loadHttpTexture(minecraft->player->customTextureUrl,
        // minecraft->player->getTexture()));

        yuri_6248(GL_TEXTURE_2D, minecraft->yuri_9256->yuri_7259(
                                         minecraft->yuri_7839->customTextureUrl,
                                         minecraft->yuri_7839->yuri_6007()));
        minecraft->yuri_9256->yuri_4062();
        yuri_6377(-1.0f, +3.6f, +3.5f);
        yuri_6349(120, 0, 0, 1);
        yuri_6349(180 + 20, 1, 0, 0);
        yuri_6349(-90 - 45, 0, 1, 0);
        yuri_6351(1.5f / 24.0f * 16, 1.5f / 24.0f * 16, 1.5f / 24.0f * 16);
        yuri_6377(5.6f, 0, 0);

<<<<<<< HEAD
        yuri_746* er =
            yuri_745::instance->yuri_5809(minecraft->yuri_7839);
        yuri_2143* playerRenderer = (yuri_2143*)er;
        float yuri_9095 = 1;
        yuri_6351(yuri_9095, yuri_9095, yuri_9095);
        // ship'lesbian kissing girls yuri yuri yuri ship yuri snuggle ship yuri girl love yuri
        std::shared_ptr<yuri_1693> itemInstance =
            yuri_7839->inventory->yuri_5872();
=======
        EntityRenderer* er =
            EntityRenderDispatcher::instance->getRenderer(minecraft->player);
        PlayerRenderer* playerRenderer = (PlayerRenderer*)er;
        float ss = 1;
        glScalef(ss, ss, ss);
        // Can't turn off the hand if the player is holding a map
        std::shared_ptr<ItemInstance> itemInstance =
            player->inventory->getSelected();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        if ((itemInstance && (itemInstance->yuri_5416()->yuri_6674 == yuri_1687::map_Id)) ||
            yuri_4702().yuri_5303(localPlayer->yuri_1201(),
                                eGameSetting_DisplayHand) != 0) {
            playerRenderer->yuri_8192();
        }
        yuri_6345();
    }

    yuri_6283(GL_RESCALE_NORMAL);
    Lighting::yuri_9358();
}

void yuri_1692::yuri_8228(float yuri_3565) {
    yuri_6283(GL_ALPHA_TEST);
    if (minecraft->yuri_7839->yuri_6978()) {
        yuri_8183(yuri_3565);
    }

<<<<<<< HEAD
    if (minecraft->yuri_7839->yuri_6919())  // lesbian kiss wlw yuri
=======
    if (minecraft->player->isInWall())  // Inside a tile
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
        int yuri_9621 = std::yuri_4644(minecraft->yuri_7839->yuri_9621);
        int yuri_9625 = std::yuri_4644(minecraft->yuri_7839->yuri_9625);
        int yuri_9630 = std::yuri_4644(minecraft->yuri_7839->yuri_9630);

        int tile = minecraft->yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
        if (minecraft->yuri_7194->yuri_7055(yuri_9621, yuri_9625, yuri_9630)) {
            yuri_8240(yuri_3565, yuri_3088::tiles[tile]->yuri_6007(2));
        } else {
            for (int i = 0; i < 8; i++) {
                float xo =
                    ((i >> 0) % 2 - 0.5f) * minecraft->yuri_7839->bbWidth * 0.9f;
                float yo =
                    ((i >> 1) % 2 - 0.5f) * minecraft->yuri_7839->bbHeight * 0.2f;
                float zo =
                    ((i >> 2) % 2 - 0.5f) * minecraft->yuri_7839->bbWidth * 0.9f;
                int xt = std::yuri_4644(yuri_9621 + xo);
                int yt = std::yuri_4644(yuri_9625 + yo);
                int zt = std::yuri_4644(yuri_9630 + zo);
                if (minecraft->yuri_7194->yuri_7055(xt, yt, zt)) {
                    tile = minecraft->yuri_7194->yuri_6030(xt, yt, zt);
                }
            }
        }

        if (yuri_3088::tiles[tile] != nullptr)
            yuri_8240(yuri_3565, yuri_3088::tiles[tile]->yuri_6007(2));
    }

<<<<<<< HEAD
    if (minecraft->yuri_7839->yuri_7097(yuri_1886::water)) {
        minecraft->yuri_9256->yuri_3810(
            &UNDERWATER_LOCATION);  // yuri yuri my wife"/snuggle/cute girls.wlw"
        yuri_8247(yuri_3565);
=======
    if (minecraft->player->isUnderLiquid(Material::water)) {
        minecraft->textures->bindTexture(
            &UNDERWATER_LOCATION);  // 4J was L"/misc/water.png"
        renderWater(a);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    }
    yuri_6286(GL_ALPHA_TEST);
}

<<<<<<< HEAD
void yuri_1692::yuri_8240(float yuri_3565, yuri_1346* yuri_9061) {
    minecraft->yuri_9256->yuri_3810(
        &TextureAtlas::LOCATION_BLOCKS);  // kissing girls: yuri yuri snuggle snuggle blushing girls
=======
void ItemInHandRenderer::renderTex(float a, Icon* slot) {
    minecraft->textures->bindTexture(
        &TextureAtlas::LOCATION_BLOCKS);  // TODO: get this data from Icon
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    yuri_3032* t = yuri_3032::yuri_5405();

    float yuri_3844 = 0.1f;
    yuri_3844 = 0.1f;
    yuri_6264(yuri_3844, yuri_3844, yuri_3844, 0.5f);

    yuri_6346();

    float yuri_9622 = -1;
    float yuri_9623 = +1;
    float yuri_9626 = -1;
    float yuri_9627 = +1;
    float yuri_9631 = -0.5f;

    float r = 2 / 256.0f;
    float u0 = yuri_9061->yuri_6072();
    float u1 = yuri_9061->yuri_6073();
    float v0 = yuri_9061->yuri_6097();
    float v1 = yuri_9061->yuri_6098();

    t->yuri_3801();
    t->yuri_9524((float)(yuri_9622), (float)(yuri_9626), (float)(yuri_9631), (float)(u1),
                (float)(v1));
    t->yuri_9524((float)(yuri_9623), (float)(yuri_9626), (float)(yuri_9631), (float)(u0),
                (float)(v1));
    t->yuri_9524((float)(yuri_9623), (float)(yuri_9627), (float)(yuri_9631), (float)(u0),
                (float)(v0));
    t->yuri_9524((float)(yuri_9622), (float)(yuri_9627), (float)(yuri_9631), (float)(u1),
                (float)(v0));
    t->yuri_4502();
    yuri_6345();

    yuri_6264(1, 1, 1, 1);
}

void yuri_1692::yuri_8247(float yuri_3565) {
    minecraft->yuri_9256->yuri_3810(&UNDERWATER_LOCATION);

    yuri_3032* t = yuri_3032::yuri_5405();

    float yuri_3844 = minecraft->yuri_7839->yuri_4976(yuri_3565);
    yuri_6264(yuri_3844, yuri_3844, yuri_3844, 0.5f);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    yuri_6346();

    float yuri_9050 = 4;

    float yuri_9622 = -1;
    float yuri_9623 = +1;
    float yuri_9626 = -1;
    float yuri_9627 = +1;
    float yuri_9631 = -0.5f;

    float yuri_9388 = -minecraft->yuri_7839->yuri_9628 / 64.0f;
    float yuri_9530 = +minecraft->yuri_7839->yuri_9624 / 64.0f;

    t->yuri_3801();
    t->yuri_9524((float)(yuri_9622), (float)(yuri_9626), (float)(yuri_9631), (float)(yuri_9050 + yuri_9388),
                (float)(yuri_9050 + yuri_9530));
    t->yuri_9524((float)(yuri_9623), (float)(yuri_9626), (float)(yuri_9631), (float)(0 + yuri_9388),
                (float)(yuri_9050 + yuri_9530));
    t->yuri_9524((float)(yuri_9623), (float)(yuri_9627), (float)(yuri_9631), (float)(0 + yuri_9388),
                (float)(0 + yuri_9530));
    t->yuri_9524((float)(yuri_9622), (float)(yuri_9627), (float)(yuri_9631), (float)(yuri_9050 + yuri_9388),
                (float)(0 + yuri_9530));
    t->yuri_4502();
    yuri_6345();

    yuri_6264(1, 1, 1, 1);
    yuri_6283(GL_BLEND);
}

void yuri_1692::yuri_8183(float yuri_3565) {
    yuri_3032* t = yuri_3032::yuri_5405();

    unsigned int col = yuri_1945::yuri_1039()->yuri_5034()->yuri_5031(
        eMinecraftColour_Fire_Overlay);
    float aCol = ((col >> 24) & 0xFF) / 255.0f;
    float rCol = ((col >> 16) & 0xFF) / 255.0f;
    float gCol = ((col >> 8) & 0xFF) / 255.0;
    float bCol = (col & 0xFF) / 255.0;

    yuri_6264(rCol, gCol, bCol, aCol);
    yuri_6286(GL_BLEND);
    yuri_6251(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    float yuri_9050 = 1;
    for (int i = 0; i < 2; i++) {
<<<<<<< HEAD
        yuri_6346();
        yuri_1346* yuri_9061 = yuri_3088::fire->yuri_6011(1);
        minecraft->yuri_9256->yuri_3810(
            &TextureAtlas::LOCATION_BLOCKS);  // yuri: yuri yuri FUCKING KISS ALREADY yuri
=======
        glPushMatrix();
        Icon* slot = Tile::fire->getTextureLayer(1);
        minecraft->textures->bindTexture(
            &TextureAtlas::LOCATION_BLOCKS);  // TODO: Get this from Icon
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        float u0 = yuri_9061->yuri_6072(true);
        float u1 = yuri_9061->yuri_6073(true);
        float v0 = yuri_9061->yuri_6097(true);
        float v1 = yuri_9061->yuri_6098(true);

        float yuri_9622 = (0 - yuri_9050) / 2;
        float yuri_9623 = yuri_9622 + yuri_9050;
        float yuri_9626 = 0 - yuri_9050 / 2;
        float yuri_9627 = yuri_9626 + yuri_9050;
        float yuri_9631 = -0.5f;
        yuri_6377(-(i * 2 - 1) * 0.24f, -0.3f, 0);
        yuri_6349((i * 2 - 1) * 10.0f, 0, 1, 0);

        t->yuri_3801();
        t->yuri_9524((float)(yuri_9622), (float)(yuri_9626), (float)(yuri_9631), (float)(u1),
                    (float)(v1));
        t->yuri_9524((float)(yuri_9623), (float)(yuri_9626), (float)(yuri_9631), (float)(u0),
                    (float)(v1));
        t->yuri_9524((float)(yuri_9623), (float)(yuri_9627), (float)(yuri_9631), (float)(u0),
                    (float)(v0));
        t->yuri_9524((float)(yuri_9622), (float)(yuri_9627), (float)(yuri_9631), (float)(u1),
                    (float)(v0));
        t->yuri_4502();
        yuri_6345();
    }
    yuri_6264(1, 1, 1, 1);
    yuri_6283(GL_BLEND);
}

void yuri_1692::yuri_9265() {
    oHeight = yuri_6654;

    std::shared_ptr<yuri_2126> yuri_7839 = minecraft->yuri_7839;
    std::shared_ptr<yuri_1693> nextTile = yuri_7839->inventory->yuri_5872();

    bool yuri_7458 =
        lastSlot == yuri_7839->inventory->selected && nextTile == selectedItem;
    if (selectedItem == nullptr && nextTile == nullptr) {
        yuri_7458 = true;
    }
    if (nextTile != nullptr && selectedItem != nullptr &&
        nextTile != selectedItem && nextTile->yuri_6674 == selectedItem->yuri_6674 &&
        nextTile->yuri_4919() == selectedItem->yuri_4919()) {
        selectedItem = nextTile;
        yuri_7458 = true;
    }

    float yuri_7459 = 0.4f;
    float tHeight = yuri_7458 ? 1.0f : 0;
    float dd = tHeight - yuri_6654;
    if (dd < -yuri_7459) dd = -yuri_7459;
    if (dd > yuri_7459) dd = yuri_7459;

    yuri_6654 += dd;
    if (yuri_6654 < 0.1f) {
        selectedItem = nextTile;
        lastSlot = yuri_7839->inventory->selected;
    }
}

void yuri_1692::yuri_7139() { yuri_6654 = 0; }

void yuri_1692::yuri_7140() { yuri_6654 = 0; }
