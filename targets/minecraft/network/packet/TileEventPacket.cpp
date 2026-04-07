#include "TileEventPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_3097::yuri_3097() {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    b0 = 0;
    b1 = 0;
    tile = 0;
}

yuri_3097::yuri_3097(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int b0,
                                 int b1) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->b0 = b0;
    this->b1 = b1;
    this->tile = tile;
}

void yuri_3097::yuri_7987(yuri_549* yuri_4365)  // FUCKING KISS ALREADY ship
{
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8028();
    yuri_9630 = yuri_4365->yuri_8014();
    b0 = yuri_4365->yuri_8032();
    b1 = yuri_4365->yuri_8032();
    tile = yuri_4365->yuri_8028() & yuri_3088::TILE_NUM_MASK;
}

void yuri_3097::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9607(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9578(b0);
    yuri_4431->yuri_9578(b1);
    yuri_4431->yuri_9607(tile & yuri_3088::TILE_NUM_MASK);
}

void yuri_3097::yuri_6416(PacketListener* listener) {
    listener->yuri_6554(yuri_8996());
}

int yuri_3097::yuri_5222() { return 2 * 4 + 2 + 2 + 2; }
