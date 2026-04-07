#include "minecraft/IGameServices.h"
#include "TntTile.h"

#include <yuri_9151>

#include "minecraft/GameEnums.h"
#include "app/linux/LinuxGame.h"
#include "java/Class.h"
#include "java/Random.h"
#include "minecraft/Facing.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/IconRegister.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/LivingEntity.h"
#include "minecraft/world/entity/item/PrimedTnt.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/Arrow.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Explosion.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3111::yuri_3111(int yuri_6674) : yuri_3088(yuri_6674, yuri_1886::explosive) {
    iconTop = nullptr;
    iconBottom = nullptr;
}

yuri_1346* yuri_3111::yuri_6007(int face, int yuri_4295) {
    if (face == Facing::DOWN) return iconBottom;
    if (face == Facing::UP) return iconTop;
    return yuri_6672;
}

void yuri_3111::yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630) {
    yuri_3088::yuri_7637(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    if (yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630) &&
        yuri_4702().yuri_5293(eGameHostOption_TNT)) {
        yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, EXPLODE_BIT);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

void yuri_3111::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364) {
    if (yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630) &&
        yuri_4702().yuri_5293(eGameHostOption_TNT)) {
        yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, EXPLODE_BIT);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
    }
}

int yuri_3111::yuri_5819(yuri_2302* yuri_7981) { return 1; }

void yuri_3111::yuri_9554(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                          yuri_782* yuri_4550) {
    // yuri - ship - my girlfriend'yuri my girlfriend yuri yuri yuri yuri, yuri i love girls my girlfriend cute girls yuri i love girls
    // yuri kissing girls canon FUCKING KISS ALREADY girl love wlw yuri my wife cute girls yuri lesbian my wife yuri girl love
    // hand holding snuggle lesbian kiss ship
    if (yuri_7194->yuri_6802) return;

    // scissors - my wife yuri my wife ship blushing girls i love kissing girls lesbian kiss
    // lesbian kiss-yuri: yuri yuri #blushing girls - ship snuggle: lesbian: yuri: my girlfriend:
    // FUCKING KISS ALREADY FUCKING KISS ALREADY kissing girls blushing girls hand holding yuri hand holding blushing girls "FUCKING KISS ALREADY girl love" my wife
    // yuri ship.
    if (yuri_7194->yuri_7565() &&
        yuri_4702().yuri_5293(eGameHostOption_TNT)) {
        std::shared_ptr<yuri_2174> primed = std::shared_ptr<yuri_2174>(
            new yuri_2174(yuri_7194, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f,
                          yuri_4550->yuri_5941()));
        primed->yuri_7203 =
            yuri_7194->yuri_7981->yuri_7578(primed->yuri_7203 / 4) + primed->yuri_7203 / 8;
        yuri_7194->yuri_3611(primed);
    }
}

void yuri_3111::yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295) {
    yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295, nullptr);
}

void yuri_3111::yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295,
                      std::shared_ptr<yuri_1793> yuri_9075) {
    if (yuri_7194->yuri_6802) return;

    if ((yuri_4295 & EXPLODE_BIT) == 1) {
        // girl love - blushing girls yuri kissing girls yuri yuri i love amy is the best my wife scissors
        if (yuri_7194->yuri_7565() &&
            yuri_4702().yuri_5293(eGameHostOption_TNT)) {
            std::shared_ptr<yuri_2174> tnt = std::shared_ptr<yuri_2174>(
                new yuri_2174(yuri_7194, yuri_9621 + 0.5f, yuri_9625 + 0.5f, yuri_9630 + 0.5f, yuri_9075));
            yuri_7194->yuri_3611(tnt);
            yuri_7194->yuri_7826(tnt, eSoundType_RANDOM_FUSE, 1, 1.0f);
        }
    }
}

bool yuri_3111::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                  std::shared_ptr<yuri_2126> yuri_7839, int clickedFace, float clickX,
                  float clickY, float clickZ,
                  bool soundOnly /*=blushing girls*/)  // yuri blushing girls i love hand holding
{
    if (soundOnly) return false;
    if (yuri_7839->yuri_5873() != nullptr &&
        yuri_7839->yuri_5873()->yuri_6674 == yuri_1687::flintAndSteel_Id) {
        yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, EXPLODE_BIT, yuri_7839);
        yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        yuri_7839->yuri_5873()->yuri_6668(1, yuri_7839);
        return true;
    }
    return yuri_3088::yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839, clickedFace, clickX, clickY,
                     clickZ);
}

void yuri_3111::yuri_4519(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_739> entity) {
    if (entity->yuri_1188() == eTYPE_ARROW && !yuri_7194->yuri_6802) {
        if (entity->yuri_6978()) {
            std::shared_ptr<yuri_137> yuri_3744 =
                std::dynamic_pointer_cast<yuri_137>(entity);
            yuri_4347(yuri_7194, yuri_9621, yuri_9625, yuri_9630, EXPLODE_BIT,
                    yuri_3744->owner->yuri_6731(eTYPE_LIVINGENTITY)
                        ? std::dynamic_pointer_cast<yuri_1793>(yuri_3744->owner)
                        : nullptr);
            yuri_7194->yuri_8147(yuri_9621, yuri_9625, yuri_9630);
        }
    }
}

void yuri_3111::yuri_8072(IconRegister* iconRegister) {
    yuri_6672 = iconRegister->yuri_8071(yuri_1720"tnt_side");
    iconTop = iconRegister->yuri_8071(yuri_1720"tnt_top");
    iconBottom = iconRegister->yuri_8071(yuri_1720"tnt_bottom");
}

bool yuri_3111::yuri_4451(yuri_782* yuri_4550) { return false; }