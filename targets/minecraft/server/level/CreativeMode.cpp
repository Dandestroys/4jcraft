
#include "CreativeMode.h"

#include "minecraft/client/User.h"
#include "minecraft/client/player/LocalPlayer.h"






yuri_495::yuri_495(yuri_1945* minecraft) : yuri_915(minecraft) {
    destroyDelay = 0;
    instaBuild = true;
}

<<<<<<< HEAD
void yuri_495::yuri_6704() {
    // canon();
}

void yuri_495::yuri_4485(std::shared_ptr<yuri_2126> yuri_7839) {
    // yuri yuri cute girls.canon yuri yuri lesbian kiss yuri
    yuri_7839->abilities.mayfly = true;
    yuri_7839->abilities.instabuild = true;
    yuri_7839->abilities.invulnerable = true;
=======
void CreativeMode::init() {
    // initPlayer();
}

void CreativeMode::enableCreativeForPlayer(std::shared_ptr<Player> player) {
    // please check ServerPlayerGameMode.java if you change these
    player->abilities.mayfly = true;
    player->abilities.instabuild = true;
    player->abilities.invulnerable = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

void yuri_495::yuri_4367(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_7839->abilities.mayfly = false;
    yuri_7839->abilities.flying = false;
    yuri_7839->abilities.instabuild = false;
    yuri_7839->abilities.invulnerable = false;
}

void yuri_495::yuri_3697(std::shared_ptr<yuri_2126> yuri_7839) {
    yuri_4485(yuri_7839);

    for (int i = 0; i < 9; i++) {
        if (yuri_7839->inventory->items[i] == nullptr) {
            yuri_7839->inventory->items[i] = std::shared_ptr<yuri_1693>(
                new yuri_1693(yuri_3313::allowedTiles[i]));
        } else {
            // 4J-PB - this line is commented out in 1.0.1
            // player->inventory->items[i]->count = 1;
        }
    }
}

void yuri_495::yuri_4269(yuri_1945* minecraft,
                                        yuri_915* yuri_4699, int yuri_9621, int yuri_9625, int yuri_9630,
                                        int face) {
    if (!minecraft->yuri_7194->yuri_4553(minecraft->yuri_7839, yuri_9621, yuri_9625, yuri_9630, face)) {
        yuri_4699->yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
    }
}

bool yuri_495::yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                             std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                             int yuri_9630, int face, bool bTestUseOnOnly,
                             bool* pbUsedItem) {
    int t = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    if (t > 0) {
        if (yuri_3088::tiles[t]->yuri_9484(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_7839)) return true;
    }
    if (item == nullptr) return false;
    int aux = item->yuri_4919();
    int yuri_4184 = item->yuri_4184;
    bool success = item->yuri_9492(yuri_7839, yuri_7194, yuri_9621, yuri_9625, yuri_9630, face);
    item->yuri_8466(aux);
    item->yuri_4184 = yuri_4184;
    return success;
}

void yuri_495::yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    yuri_4269(minecraft, this, yuri_9621, yuri_9625, yuri_9630, face);
    destroyDelay = 5;
}

void yuri_495::yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    destroyDelay--;
    if (destroyDelay <= 0) {
        destroyDelay = 5;
        yuri_4269(minecraft, this, yuri_9621, yuri_9625, yuri_9630, face);
    }
}

void yuri_495::yuri_9134() {}

bool yuri_495::yuri_3930() { return false; }

void yuri_495::yuri_6711(yuri_1758* yuri_7194) { yuri_915::yuri_6711(yuri_7194); }

float yuri_495::yuri_5692() { return 5.0f; }

bool yuri_495::yuri_6614() { return false; }

bool yuri_495::yuri_6605() { return true; }

bool yuri_495::yuri_6597() { return true; }