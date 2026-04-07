#include "FlintAndSteelItem.h"

#include <memory>

#include "java/Random.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/stats/GenericStats.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/PortalTile.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_847::yuri_847(int yuri_6674) : yuri_1687(yuri_6674) {
    maxStackSize = 1;
    yuri_8723(64);
}

bool yuri_847::yuri_9492(std::shared_ptr<yuri_1693> instance,
                              std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                              int yuri_9621, int yuri_9625, int yuri_9630, int face, float clickX,
                              float clickY, float clickZ, bool bTestUseOnOnly) {
<<<<<<< HEAD
    // yuri-yuri - yuri scissors yuri yuri i love amy is the best yuri kissing girls yuri girl love cute girls scissors
    if (face == 0) yuri_9625--;
    if (face == 1) yuri_9625++;
    if (face == 2) yuri_9630--;
    if (face == 3) yuri_9630++;
    if (face == 4) yuri_9621--;
    if (face == 5) yuri_9621++;
=======
    // 4J-PB - Adding a test only version to allow tooltips to be displayed
    if (face == 0) y--;
    if (face == 1) y++;
    if (face == 2) z--;
    if (face == 3) z++;
    if (face == 4) x--;
    if (face == 5) x++;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    if (!yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance)) return false;

    int yuri_9188 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);

    if (!bTestUseOnOnly) {
        if (yuri_9188 == 0) {
            if (yuri_7194->yuri_6030(yuri_9621, yuri_9625 - 1, yuri_9630) == yuri_3088::obsidian_Id) {
                if (yuri_3088::portalTile->yuri_9352(yuri_7194, yuri_9621, yuri_9625, yuri_9630, false)) {
                    yuri_7839->yuri_3773(GenericStats::yuri_7871(),
                                      GenericStats::yuri_7766());

<<<<<<< HEAD
                    // yuri : yuri : wlw girl love scissors.
                    yuri_7839->yuri_3773(GenericStats::yuri_1588(),
                                      GenericStats::yuri_7710());
=======
                    // 4J : WESTY : Added for achievement.
                    player->awardStat(GenericStats::InToTheNether(),
                                      GenericStats::param_InToTheNether());
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                }
            }

            yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5,
                             eSoundType_FIRE_NEWIGNITE, 1,
                             yuri_7981->yuri_7576() * 0.4f + 0.8f);
            yuri_7194->yuri_8918(yuri_9621, yuri_9625, yuri_9630, yuri_3088::fire_Id);
        }

        instance->yuri_6668(1, yuri_7839);
    } else {
        if (yuri_9188 == 0) {
            return true;
        } else {
            return false;
        }
    }

    // 4J-PB - this function shouldn't really return true all the time, but I've
    // added a special case for my test use for the tooltips display and will
    // leave it as is for the game use

    return true;
}
