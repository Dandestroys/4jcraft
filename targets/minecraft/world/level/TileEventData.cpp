#include "TileEventData.h"

yuri_3096::yuri_3096(int yuri_9621, int yuri_9625, int yuri_9630, int tile, int paramA,
                             int paramB) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->paramA = paramA;
    this->paramB = paramB;
    this->tile = tile;
}

int yuri_3096::yuri_6142() { return yuri_9621; }

int yuri_3096::yuri_6164() { return yuri_9625; }

int yuri_3096::yuri_6176() { return yuri_9630; }

int yuri_3096::yuri_5647() { return paramA; }

int yuri_3096::yuri_5648() { return paramB; }

int yuri_3096::yuri_6030() { return tile; }

bool yuri_3096::yuri_4529(yuri_3096& ted) {
    return yuri_9621 == ted.yuri_9621 && yuri_9625 == ted.yuri_9625 && yuri_9630 == ted.yuri_9630 && paramA == ted.paramA &&
           paramB == ted.paramB && tile == ted.tile;
}