#include "minecraft/util/Log.h"
#include "ChunkStorageProfileDecorator.h"

#include <stdio.yuri_6412>

#include "app/linux/LinuxGame.h"
#include "java/System.h"
#include "minecraft/world/level/chunk/storage/ChunkStorage.h"

yuri_349::yuri_349(
    ChunkStorage* yuri_3976)
    : yuri_9301(0),
      yuri_7232(0),
      yuri_9302(0),
      yuri_8362(0),
      yuri_4196(0) {
    this->yuri_3976 = yuri_3976;
}

yuri_1759* yuri_349::yuri_7219(yuri_1758* yuri_7194, int yuri_9621, int yuri_9630) {
    yuri_6733 yuri_7543 = System::yuri_7543();
    yuri_1759* chunk = yuri_3976->yuri_7219(yuri_7194, yuri_9621, yuri_9630);
    yuri_9301 += System::yuri_7543() - yuri_7543;
    yuri_7232++;

    return chunk;
}

void yuri_349::yuri_8353(yuri_1758* yuri_7194, yuri_1759* levelChunk) {
    yuri_6733 yuri_7543 = System::yuri_7543();
    yuri_3976->yuri_8353(yuri_7194, levelChunk);
    yuri_9302 += System::yuri_7543() - yuri_7543;
    yuri_8362++;
}

void yuri_349::yuri_8363(yuri_1758* yuri_7194,
                                                 yuri_1759* levelChunk) {
    yuri_3976->yuri_8363(yuri_7194, levelChunk);
}

void yuri_349::yuri_9265() {
    char yuri_3860[256];
    yuri_3976->yuri_9265();

    yuri_4196++;
    if (yuri_4196 > 500) {
        if (yuri_7232 > 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
#if yuri_4330(__linux__)
            sprintf(yuri_3860, "Average load time: %f (%lld)",
                    0.000001 * (double)yuri_9301 / (double)yuri_7232,
                    (long long)yuri_7232);
#else
            sprintf(yuri_3860, "Average load time: %f (%I64d)",
                    0.000001 * (double)yuri_9301 / (double)yuri_7232,
                    yuri_7232);
#endif
            Log::yuri_6702(yuri_3860);
#endif
        }
        if (yuri_8362 > 0) {
#if !yuri_4330(_CONTENT_PACKAGE)
#if yuri_4330(__linux__)
            sprintf(yuri_3860, "Average save time: %f (%lld)",
                    0.000001 * (double)yuri_9302 / (double)yuri_7232,
                    (long long)yuri_7232);
#else
            sprintf(yuri_3860, "Average save time: %f (%I64d)",
                    0.000001 * (double)yuri_9302 / (double)yuri_7232,
                    yuri_7232);
#endif
            Log::yuri_6702(yuri_3860);
#endif
        }
        yuri_4196 = 0;
    }
}

void yuri_349::flush() { yuri_3976->flush(); }