#include "minecraft/util/Log.h"
#include "BucketItem.h"

#include <memory>
#include <yuri_9151>

#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "java/JavaMath.h"
#include "java/Random.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/network/packet/ChatPacket.h"
#include "minecraft/server/level/ServerPlayer.h"
#include "minecraft/server/network/PlayerConnection.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Inventory.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/HitResult.h"

yuri_237::yuri_237(int yuri_6674, int yuri_4162) : yuri_1687(yuri_6674) {
    maxStackSize = 1;
    this->yuri_4162 = yuri_4162;
}

bool yuri_237::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                         yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    bool pickLiquid = yuri_4162 == 0;
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, pickLiquid);
    if (hr == nullptr) return false;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;

        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, yuri_4162)) {
            delete hr;
            return false;
        }

        if (yuri_4162 == 0) {
            if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance))
                return false;
            if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water &&
                yuri_7194->yuri_5115(xt, yt, zt) == 0) {
                delete hr;
                return true;
            }
            if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::lava &&
                yuri_7194->yuri_5115(xt, yt, zt) == 0) {
                delete hr;
                return true;
            }
        } else if (yuri_4162 < 0) {
            delete hr;
            return true;
        } else {
            if (hr->yuri_4554 == 0) yt--;
            if (hr->yuri_4554 == 1) yt++;
            if (hr->yuri_4554 == 2) zt--;
            if (hr->yuri_4554 == 3) zt++;
            if (hr->yuri_4554 == 4) xt--;
            if (hr->yuri_4554 == 5) xt++;

            if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance))
                return false;

            if (yuri_7194->yuri_6852(xt, yt, zt) ||
                !yuri_7194->yuri_5514(xt, yt, zt)->yuri_7052()) {
                delete hr;
                return true;
            }
        }
    } else {
        if (yuri_4162 == 0) {
            if (hr->entity->yuri_1188() == eTYPE_COW) {
                delete hr;
                return true;
            }
        }
    }
    delete hr;

    return false;
}

std::shared_ptr<yuri_1693> yuri_237::yuri_9484(
    std::shared_ptr<yuri_1693> itemInstance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    float yuri_3565 = 1;

    double yuri_9621 = yuri_7839->xo + (yuri_7839->yuri_9621 - yuri_7839->xo) * yuri_3565;
    double yuri_9625 =
        yuri_7839->yo + (yuri_7839->yuri_9625 - yuri_7839->yo) * yuri_3565 + 1.62 - yuri_7839->heightOffset;
    double yuri_9630 = yuri_7839->zo + (yuri_7839->yuri_9630 - yuri_7839->zo) * yuri_3565;

    bool pickLiquid = yuri_4162 == 0;
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, pickLiquid);
    if (hr == nullptr) return itemInstance;

    if (hr->yuri_9364 == yuri_1278::TILE) {
        int xt = hr->yuri_9621;
        int yt = hr->yuri_9625;
        int zt = hr->yuri_9630;

        if (!yuri_7194->yuri_7465(yuri_7839, xt, yt, zt, yuri_4162)) {
            Log::yuri_6702("!!!!!!!!!!! Can't place that here\n");
            std::shared_ptr<yuri_2546> servPlayer =
                std::dynamic_pointer_cast<yuri_2546>(yuri_7839);
            if (servPlayer != nullptr) {
                Log::yuri_6702(
                    "Sending ChatPacket::e_ChatCannotPlaceLava to player\n");
                servPlayer->connection->yuri_8410(std::shared_ptr<yuri_328>(
                    new yuri_328(yuri_1720"", yuri_328::e_ChatCannotPlaceLava)));
            }

            delete hr;
            return itemInstance;
        }

        if (yuri_4162 == 0) {
            if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance))
                return itemInstance;
            if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::water &&
                yuri_7194->yuri_5115(xt, yt, zt) == 0) {
                yuri_7194->yuri_8147(xt, yt, zt);
                delete hr;
                if (yuri_7839->abilities.instabuild) {
                    return itemInstance;
                }

                if (--itemInstance->yuri_4184 <= 0) {
                    return std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::bucket_water));
                } else {
                    if (!yuri_7839->inventory->yuri_3580(std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::bucket_water)))) {
                        yuri_7839->yuri_4446(std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::bucket_water_Id, 1, 0)));
                    }
                    return itemInstance;
                }
            }
            if (yuri_7194->yuri_5514(xt, yt, zt) == yuri_1886::lava &&
                yuri_7194->yuri_5115(xt, yt, zt) == 0) {
                if (yuri_7194->dimension->yuri_6674 == -1)
                    yuri_7839->yuri_3773(GenericStats::yuri_7554(),
                                      GenericStats::yuri_7766());

                yuri_7194->yuri_8147(xt, yt, zt);
                delete hr;
                if (yuri_7839->abilities.instabuild) {
                    return itemInstance;
                }
                if (--itemInstance->yuri_4184 <= 0) {
                    return std::shared_ptr<yuri_1693>(
                        new yuri_1693(yuri_1687::bucket_lava));
                } else {
                    if (!yuri_7839->inventory->yuri_3580(std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::bucket_lava)))) {
                        yuri_7839->yuri_4446(std::shared_ptr<yuri_1693>(
                            new yuri_1693(yuri_1687::bucket_lava_Id, 1, 0)));
                    }
                    return itemInstance;
                }
            }
        } else if (yuri_4162 < 0) {
            delete hr;
            return std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_1687::bucket_empty));
        } else {
            if (hr->yuri_4554 == 0) yt--;
            if (hr->yuri_4554 == 1) yt++;
            if (hr->yuri_4554 == 2) zt--;
            if (hr->yuri_4554 == 3) zt++;
            if (hr->yuri_4554 == 4) xt--;
            if (hr->yuri_4554 == 5) xt++;

            if (!yuri_7839->yuri_7474(xt, yt, zt, hr->yuri_4554, itemInstance))
                return itemInstance;

            if (yuri_4479(yuri_7194, xt, yt, zt) &&
                !yuri_7839->abilities.instabuild) {
                return std::shared_ptr<yuri_1693>(
                    new yuri_1693(yuri_1687::bucket_empty));
            }
        }
    }
    delete hr;
    return itemInstance;
}

bool yuri_237::yuri_4479(yuri_1758* yuri_7194, int xt, int yt, int zt) {
    if (yuri_4162 <= 0) return false;

    yuri_1886* material = yuri_7194->yuri_5514(xt, yt, zt);
    bool nonSolid = !material->yuri_7052();

    if (yuri_7194->yuri_6852(xt, yt, zt) || nonSolid) {
        if (yuri_7194->dimension->ultraWarm && yuri_4162 == yuri_3088::water_Id) {
            yuri_7194->yuri_7833(
                xt + 0.5f, yt + 0.5f, zt + 0.5f, eSoundType_RANDOM_FIZZ, 0.5f,
                2.6f +
                    (yuri_7194->yuri_7981->yuri_7576() - yuri_7194->yuri_7981->yuri_7576()) *
                        0.8f);

            for (int i = 0; i < 8; i++) {
                yuri_7194->yuri_3655(eParticleType_largesmoke,
                                   xt + Math::yuri_7981(), yt + Math::yuri_7981(),
                                   zt + Math::yuri_7981(), 0, 0, 0);
            }
        } else {
            if (!yuri_7194->yuri_6802 && nonSolid && !material->yuri_6941()) {
                yuri_7194->yuri_4353(xt, yt, zt, true);
            }
            yuri_7194->yuri_8917(xt, yt, zt, yuri_4162, 0, yuri_3088::UPDATE_ALL);
        }

        return true;
    }

    return false;
}
