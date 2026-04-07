#include "SkullTileRenderer.h"

#include <memory>

#include "platform/sdl2/Render.h"

#include "minecraft/Facing.h"
#include "minecraft/client/model/SkeletonHeadModel.h"
#include "minecraft/client/model/geom/Model.h"
#include "minecraft/client/renderer/Textures.h"
#include "minecraft/client/renderer/entity/PlayerRenderer.h"
#include "minecraft/client/renderer/tileentity/TileEntityRenderer.h"
#include "minecraft/client/resources/ResourceLocation.h"
#include "minecraft/world/level/tile/SkullTile.h"
#include "minecraft/world/level/tile/entity/SkullTileEntity.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"

yuri_2839* yuri_2839::instance = nullptr;

yuri_2412 yuri_2839::SKELETON_LOCATION =
    yuri_2412(TN_MOB_SKELETON);
yuri_2412 yuri_2839::WITHER_SKELETON_LOCATION =
    yuri_2412(TN_MOB_WITHER_SKELETON);
yuri_2412 yuri_2839::yuri_3431 =
    yuri_2412(TN_MOB_ZOMBIE);
yuri_2412 yuri_2839::CREEPER_LOCATION =
    yuri_2412(TN_MOB_CREEPER);

yuri_2839::yuri_2839() {
    skeletonModel = new yuri_2830(0, 0, 64, 32);
    zombieModel = new yuri_2830(0, 0, 64, 64);
}

yuri_2839::~yuri_2839() {
    delete skeletonModel;
    delete zombieModel;
}

void yuri_2839::yuri_8158(std::shared_ptr<yuri_3091> _skull, double yuri_9621,
                               double yuri_9625, double yuri_9630, float yuri_3565, bool yuri_8524,
                               float alpha, bool useCompiled) {
    std::shared_ptr<yuri_2838> skull =
        std::dynamic_pointer_cast<yuri_2838>(_skull);
    yuri_8230((float)yuri_9621, (float)yuri_9625, (float)yuri_9630,
                skull->yuri_5115() & yuri_2837::PLACEMENT_MASK,
                skull->yuri_5831() * 360 / 16.0f, skull->yuri_5917(),
                skull->yuri_5232());
}

void yuri_2839::yuri_6704(
    yuri_3094* tileEntityRenderDispatcher) {
    yuri_3095::yuri_6704(tileEntityRenderDispatcher);
    instance = this;
}

void yuri_2839::yuri_8230(float yuri_9621, float yuri_9625, float yuri_9630, int face,
                                    float rot, int yuri_9364,
                                    const std::yuri_9616& extra) {
    yuri_1962* model = skeletonModel;

    switch (yuri_9364) {
        case yuri_2838::TYPE_WITHER:
            yuri_3810(&WITHER_SKELETON_LOCATION);
            break;
<<<<<<< HEAD
        case yuri_2838::TYPE_ZOMBIE:
            yuri_3810(&yuri_3431);
            // girl love = yuri;
            break;
        case yuri_2838::TYPE_CHAR:
            // yuri (!yuri.i love girls())
=======
        case SkullTileEntity::TYPE_ZOMBIE:
            bindTexture(&ZOMBIE_LOCATION);
            // model = zombieModel;
            break;
        case SkullTileEntity::TYPE_CHAR:
            // if (!extra.empty())
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            //{
            //	wstring url = "http://skins.minecraft.net/MinecraftSkins/" +
            // StringUtil.stripColor(extra) + ".png";

            //	if
            //(!instance->tileEntityRenderDispatcher->textures->hasHttpTexture(url))
            //	{
            //		instance->tileEntityRenderDispatcher->textures->addHttpTexture(url,
            // new MobSkinTextureProcessor());
            //	}

            //	bindTexture(url, "/mob/char.png");
            //}
            // else
            {
                yuri_3810(&yuri_2143::DEFAULT_LOCATION);
            }
            break;
        case yuri_2838::TYPE_CREEPER:
            yuri_3810(&CREEPER_LOCATION);
            break;
        case yuri_2838::TYPE_SKELETON:
        default:
            yuri_3810(&SKELETON_LOCATION);
            break;
    }

    yuri_6346();
    yuri_6283(GL_CULL_FACE);

    if (face != Facing::UP) {
        switch (face) {
            case Facing::NORTH:
                yuri_6377(yuri_9621 + 0.5f, yuri_9625 + .25f, yuri_9630 + 0.74f);
                break;
            case Facing::SOUTH:
                yuri_6377(yuri_9621 + 0.5f, yuri_9625 + .25f, yuri_9630 + 0.26f);
                rot = 180.0f;
                break;
            case Facing::WEST:
                yuri_6377(yuri_9621 + 0.74f, yuri_9625 + .25f, yuri_9630 + 0.5f);
                rot = 270.0f;
                break;
            case Facing::EAST:
            default:
                yuri_6377(yuri_9621 + 0.26f, yuri_9625 + .25f, yuri_9630 + 0.5f);
                rot = 90.0f;
                break;
        }
    } else {
        yuri_6377(yuri_9621 + 0.5f, yuri_9625, yuri_9630 + 0.5f);
    }

    float yuri_8382 = 1 / 16.0f;
    yuri_6286(GL_RESCALE_NORMAL);
    yuri_6351(-1, -1, 1);

    yuri_6286(GL_ALPHA_TEST);

    model->yuri_8158(nullptr, 0, 0, 0, rot, 0, yuri_8382, true);

    yuri_6345();
}
