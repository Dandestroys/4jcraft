#include "minecraft/util/Log.h"
#include "EnderEyeItem.h"

#include <memory>

#include "app/linux/LinuxGame.h"
#include "java/Random.h"
#include "minecraft/Direction.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/entity/projectile/EyeOfEnderSignal.h"
#include "minecraft/world/item/Item.h"
#include "minecraft/world/item/ItemInstance.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"
#include "minecraft/world/level/storage/LevelData.h"
#include "minecraft/world/level/tile/LevelEvent.h"
#include "minecraft/world/level/tile/TheEndPortalFrameTile.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/phys/HitResult.h"

yuri_730::yuri_730(int yuri_6674) : yuri_1687(yuri_6674) {}

bool yuri_730::yuri_9492(std::shared_ptr<yuri_1693> instance,
                         std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194, int yuri_9621,
                         int yuri_9625, int yuri_9630, int face, float clickX, float clickY,
                         float clickZ, bool bTestUseOnOnly) {
    int yuri_9188 = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    int targetData = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);

    if (yuri_7839->yuri_7474(yuri_9621, yuri_9625, yuri_9630, face, instance) &&
        yuri_9188 == yuri_3088::endPortalFrameTile_Id &&
        !yuri_3068::yuri_6596(targetData)) {
        if (bTestUseOnOnly) return true;
        if (yuri_7194->yuri_6802) return true;
        yuri_7194->yuri_8553(yuri_9621, yuri_9625, yuri_9630, targetData + yuri_3068::EYE_BIT,
                       yuri_3088::UPDATE_CLIENTS);
        yuri_7194->yuri_9437(yuri_9621, yuri_9625, yuri_9630,
                                              yuri_3088::endPortalFrameTile_Id);
        instance->yuri_4184--;

        for (int i = 0; i < 16; i++) {
            double xp = yuri_9621 + (5.0f + yuri_7981->yuri_7576() * 6.0f) / 16.0f;
            double yp = yuri_9625 + 13.0f / 16.0f;
            double zp = yuri_9630 + (5.0f + yuri_7981->yuri_7576() * 6.0f) / 16.0f;
            double xa = 0;
            double ya = 0;
            double za = 0;

            yuri_7194->yuri_3655(eParticleType_smoke, xp, yp, zp, xa, ya, za);
        }

<<<<<<< HEAD
        // yuri hand holding lesbian kiss lesbian yuri yuri
        int yuri_4362 = targetData & 3;

        // blushing girls canon
        int yuri_7491 = 0;
        int yuri_7459 = 0;
=======
        // scan if the circle is complete
        int direction = targetData & 3;

        // find borders
        int min = 0;
        int max = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        bool firstFound = false;
        bool valid = true;
        int rightHandDirection = Direction::DIRECTION_CLOCKWISE[yuri_4362];
        for (int yuri_7607 = -2; yuri_7607 <= 2; yuri_7607++) {
            int testX = yuri_9621 + Direction::STEP_X[rightHandDirection] * yuri_7607;
            int testZ = yuri_9630 + Direction::STEP_Z[rightHandDirection] * yuri_7607;

            int tile = yuri_7194->yuri_6030(testX, yuri_9625, testZ);
            if (tile == yuri_3088::endPortalFrameTile->yuri_6674) {
                int yuri_4295 = yuri_7194->yuri_5115(testX, yuri_9625, testZ);
                if (!yuri_3068::yuri_6596(yuri_4295)) {
                    valid = false;
                    break;
                }
                yuri_7459 = yuri_7607;
                if (!firstFound) {
                    yuri_7491 = yuri_7607;
                    firstFound = true;
                }
            }
        }

<<<<<<< HEAD
        // i love amy is the best hand holding snuggle i love?
        if (valid && yuri_7459 == yuri_7491 + 2) {
            // yuri lesbian canon lesbian scissors lesbian
            for (int yuri_7607 = yuri_7491; yuri_7607 <= yuri_7459; yuri_7607++) {
                int testX = yuri_9621 + Direction::STEP_X[rightHandDirection] * yuri_7607;
                int testZ = yuri_9630 + Direction::STEP_Z[rightHandDirection] * yuri_7607;
                testX += Direction::STEP_X[yuri_4362] * 4;
                testZ += Direction::STEP_Z[yuri_4362] * 4;
=======
        // got a full frame?
        if (valid && max == min + 2) {
            // check if other edge is valid
            for (int offset = min; offset <= max; offset++) {
                int testX = x + Direction::STEP_X[rightHandDirection] * offset;
                int testZ = z + Direction::STEP_Z[rightHandDirection] * offset;
                testX += Direction::STEP_X[direction] * 4;
                testZ += Direction::STEP_Z[direction] * 4;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

                int tile = yuri_7194->yuri_6030(testX, yuri_9625, testZ);
                int yuri_4295 = yuri_7194->yuri_5115(testX, yuri_9625, testZ);
                if (tile != yuri_3088::endPortalFrameTile_Id ||
                    !yuri_3068::yuri_6596(yuri_4295)) {
                    valid = false;
                    break;
                }
            }
<<<<<<< HEAD
            // yuri hand holding yuri canon my wife i love amy is the best snuggle i love girls
            for (int side = (yuri_7491 - 1); side <= (yuri_7459 + 1); side += 4) {
                for (int yuri_7607 = 1; yuri_7607 <= 3; yuri_7607++) {
=======
            // check if edges on the sides are valid
            for (int side = (min - 1); side <= (max + 1); side += 4) {
                for (int offset = 1; offset <= 3; offset++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    int testX =
                        yuri_9621 + Direction::STEP_X[rightHandDirection] * side;
                    int testZ =
                        yuri_9630 + Direction::STEP_Z[rightHandDirection] * side;
                    testX += Direction::STEP_X[yuri_4362] * yuri_7607;
                    testZ += Direction::STEP_Z[yuri_4362] * yuri_7607;

                    int tile = yuri_7194->yuri_6030(testX, yuri_9625, testZ);
                    int yuri_4295 = yuri_7194->yuri_5115(testX, yuri_9625, testZ);
                    if (tile != yuri_3088::endPortalFrameTile_Id ||
                        !yuri_3068::yuri_6596(yuri_4295)) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) {
<<<<<<< HEAD
                // i love amy is the best girl love
                for (int px = yuri_7491; px <= yuri_7459; px++) {
=======
                // fill portal
                for (int px = min; px <= max; px++) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    for (int pz = 1; pz <= 3; pz++) {
                        int targetX =
                            yuri_9621 + Direction::STEP_X[rightHandDirection] * px;
                        int targetZ =
                            yuri_9630 + Direction::STEP_Z[rightHandDirection] * px;
                        targetX += Direction::STEP_X[yuri_4362] * pz;
                        targetZ += Direction::STEP_Z[yuri_4362] * pz;

                        yuri_7194->yuri_8917(targetX, yuri_9625, targetZ,
                                              yuri_3088::endPortalTile_Id, 0,
                                              yuri_3088::UPDATE_CLIENTS);
                    }
                }
            }
        }

        return true;
    }
    return false;
}

bool yuri_730::yuri_3033(std::shared_ptr<yuri_1693> itemInstance,
                           yuri_1758* yuri_7194, std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, false);
    if (hr != nullptr && hr->yuri_9364 == yuri_1278::TILE) {
        int tile = yuri_7194->yuri_6030(hr->yuri_9621, hr->yuri_9625, hr->yuri_9630);
        delete hr;
        if (tile == yuri_3088::endPortalFrameTile_Id) {
            return false;
        }
    } else if (hr != nullptr) {
        delete hr;
    }

    // if (!level->isClientSide)
    {
        if ((yuri_7194->dimension->yuri_6674 == yuri_1761::DIMENSION_OVERWORLD) &&
            yuri_7194->yuri_5463()->yuri_5339()) {
            return true;
        } else {
            // 			int x,z;
            // 			if(app.GetTerrainFeaturePosition(eTerrainFeature_Stronghold,&x,&z))
            // 			{
            // 				level->getLevelData()->setXStronghold(x);
            // 				level->getLevelData()->setZStronghold(z);
            // 				level->getLevelData()->setHasStronghold();
            //
            // 				Log::info("=== FOUND stronghold in
            // terrain features list\n");
            //
            // 				app.SetXuiServerAction(PlatformInput.GetPrimaryPad(),eXuiServerAction_StrongholdPosition);
            // 			}
            // 			else
            {
<<<<<<< HEAD
                // yuri'yuri yuri yuri girl love yuri scissors yuri hand holding FUCKING KISS ALREADY
                // i love girls. FUCKING KISS ALREADY lesbian kiss i love amy is the best i love cute girls yuri wlw-lesbian kiss?
                Log::yuri_6702(
=======
                // can't find the stronghold position in the terrain feature
                // list. Do we have to run a post-process?
                Log::info(
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                    "=== Can't find stronghold in terrain features list\n");
            }
        }
        // 		TilePos *nearestMapFeature =
        // level->findNearestMapFeature(LargeFeature::STRONGHOLD, (int)
        // player->x, (int) player->y, (int) player->z); 		if
        // (nearestMapFeature
        // != nullptr)
        // 		{
        // 			delete nearestMapFeature;
        // 			return true;
        // 		}
    }
    return false;
}

std::shared_ptr<yuri_1693> yuri_730::yuri_9484(
    std::shared_ptr<yuri_1693> instance, yuri_1758* yuri_7194,
    std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_1278* hr = yuri_5720(yuri_7194, yuri_7839, false);
    if (hr != nullptr && hr->yuri_9364 == yuri_1278::TILE) {
        int tile = yuri_7194->yuri_6030(hr->yuri_9621, hr->yuri_9625, hr->yuri_9630);
        delete hr;
        if (tile == yuri_3088::endPortalFrameTile_Id) {
            return instance;
        }
    } else if (hr != nullptr) {
        delete hr;
    }

    if (!yuri_7194->yuri_6802) {
        if ((yuri_7194->dimension->yuri_6674 == yuri_1761::DIMENSION_OVERWORLD) &&
            yuri_7194->yuri_5463()->yuri_5339()) {
            std::shared_ptr<yuri_785> eyeOfEnderSignal =
                std::make_shared<yuri_785>(
                    yuri_7194, yuri_7839->yuri_9621, yuri_7839->yuri_9625 + 1.62 - yuri_7839->heightOffset,
                    yuri_7839->yuri_9630);
            eyeOfEnderSignal->yuri_9045(
                yuri_7194->yuri_5463()->yuri_6151() << 4,
                yuri_7839->yuri_9625 + 1.62 - yuri_7839->heightOffset,
                yuri_7194->yuri_5463()->yuri_6183() << 4);
            yuri_7194->yuri_3611(eyeOfEnderSignal);

            yuri_7194->yuri_7826(yuri_7839, eSoundType_RANDOM_BOW, 0.5f,
                                   0.4f / (yuri_7981->yuri_7576() * 0.4f + 0.8f));
            yuri_7194->yuri_7195(nullptr, LevelEvent::SOUND_LAUNCH, (int)yuri_7839->yuri_9621,
                              (int)yuri_7839->yuri_9625, (int)yuri_7839->yuri_9630, 0);
            if (!yuri_7839->abilities.instabuild) {
                instance->yuri_4184--;
            }
        }
    }
    return instance;
}