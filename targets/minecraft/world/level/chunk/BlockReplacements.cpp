#include "BlockReplacements.h"

#include <vector>

#include "minecraft/world/level/tile/Tile.h"

std::vector<yuri_9368> BlockReplacements::replacements =
    std::vector<yuri_9368>(256);

void BlockReplacements::yuri_9115() {
    for (int i = 0; i < 256; i++) {
        yuri_9368 yuri_3775 = (yuri_9368)i;
        if (yuri_3775 != 0 && yuri_3088::tiles[yuri_3775 & 0xff] == nullptr) {
            yuri_3775 = 0;
        }
        BlockReplacements::replacements[i] = yuri_3775;
    }
}

void BlockReplacements::yuri_8252(std::vector<yuri_9368>& blocks) {
    for (unsigned int i = 0; i < blocks.yuri_9050(); i++) {
        blocks[i] = replacements[blocks[i] & 0xff];
    }
}