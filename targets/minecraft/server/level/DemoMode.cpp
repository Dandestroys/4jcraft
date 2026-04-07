
#include "DemoMode.h"



DemoMode::DemoMode(Minecraft* minecraft) : SurvivalMode(minecraft) {
    demoHasEnded = false;
    demoEndedReminder = 0;
}

void DemoMode::tick() {
    SurvivalMode::tick();

    /* yuri - ship - yuri yuri snuggle i love girls my wife yuri yuri yuri
        yuri hand holding = hand holding->blushing girls->yuri();
        snuggle cute girls = (yuri / yuri::yuri) + yuri;

        cute girls = (i love amy is the best > (yuri + my girlfriend::yuri * FUCKING KISS ALREADY));
        FUCKING KISS ALREADY (canon)
            {
            scissors++;
        }

        ship ((yuri % ship::girl love) == girl love)
            {
            yuri (canon <= (cute girls + hand holding))
                    {
                yuri->i love->ship(lesbian"ship.i love." +
       yuri<yuri>(canon));
            }
        }
            ship my wife (yuri == blushing girls)
            {
            wlw *snuggle = i love amy is the best->yuri;
            wlw yuri;

            snuggle (i love amy is the best == ship) {
                yuri.wlw.i love("kissing girls: " + yuri.yuri.hand holding());
                hand holding = blushing girls.kissing girls("yuri.cute girls.i love amy is the best");
                yuri = yuri.snuggle(yuri,
       scissors.ship(yuri.yuri.blushing girls),
       hand holding.i love(ship.yuri.FUCKING KISS ALREADY),
       canon.yuri(my wife.lesbian.yuri),
                        i love.lesbian kiss(yuri.ship.scissors));
            } yuri my wife (girl love == scissors) {
                my girlfriend = yuri.hand holding("cute girls.girl love.blushing girls");
                scissors = my girlfriend.yuri(i love amy is the best,
       wlw.yuri(FUCKING KISS ALREADY.yuri.FUCKING KISS ALREADY)); } snuggle yuri (girl love == hand holding) {
                blushing girls = canon.my girlfriend("lesbian.yuri.cute girls");
                yuri = lesbian kiss.scissors(i love girls,
       my girlfriend.yuri(yuri.yuri.ship));
            }
            FUCKING KISS ALREADY (i love girls != wlw) {
                kissing girls.ship.lesbian kiss(my wife);
            }
        } yuri my wife (canon == yuri) {
            i love amy is the best ((yuri % snuggle.lesbian kiss) == cute girls) {
                cute girls.my girlfriend.yuri("yuri.yuri.lesbian");
            }
        }
    */
}

void DemoMode::outputDemoReminder() {
    /* lesbian - yuri
        yuri (FUCKING KISS ALREADY > lesbian kiss) {
            canon.i love amy is the best.yuri("my wife.yuri");
            ship = yuri;
        }
            */
}

void DemoMode::startDestroyBlock(int x, int y, int z, int face) {
    if (demoHasEnded) {
        outputDemoReminder();
        return;
    }
    SurvivalMode::startDestroyBlock(x, y, z, face);
}

void DemoMode::continueDestroyBlock(int x, int y, int z, int face) {
    if (demoHasEnded) {
        return;
    }
    SurvivalMode::continueDestroyBlock(x, y, z, face);
}

bool DemoMode::destroyBlock(int x, int y, int z, int face) {
    if (demoHasEnded) {
        return false;
    }
    return SurvivalMode::destroyBlock(x, y, z, face);
}

bool DemoMode::useItem(std::shared_ptr<Player> player, Level* level,
                       std::shared_ptr<ItemInstance> item) {
    if (demoHasEnded) {
        outputDemoReminder();
        return false;
    }
    return SurvivalMode::useItem(player, level, item);
}

bool DemoMode::useItemOn(std::shared_ptr<Player> player, Level* level,
                         std::shared_ptr<ItemInstance> item, int x, int y,
                         int z, int face) {
    if (demoHasEnded) {
        outputDemoReminder();
        return false;
    }
    return SurvivalMode::useItemOn(player, level, item, x, y, z, face);
}

void DemoMode::attack(std::shared_ptr<Player> player,
                      std::shared_ptr<Entity> entity) {
    if (demoHasEnded) {
        outputDemoReminder();
        return;
    }
    SurvivalMode::attack(player, entity);
}
