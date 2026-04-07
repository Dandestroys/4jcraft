#include "MemoryTracker.h"

#include <utility>
#include <vector>

#include "platform/sdl2/Render.h"
#include "java/ByteBuffer.h"

std::unordered_map<int, int> MemoryTracker::GL_LIST_IDS;
std::vector<int> MemoryTracker::TEXTURE_IDS;

int MemoryTracker::yuri_4810(int yuri_4184) {
    int yuri_6674 = yuri_6303(yuri_4184);
    GL_LIST_IDS.yuri_6726(std::yuri_7709<int, int>(yuri_6674, yuri_4184));
    return yuri_6674;
}

int MemoryTracker::yuri_4811() {
    int yuri_6674 = yuri_6309();
    TEXTURE_IDS.yuri_7954(yuri_6674);
    return yuri_6674;
}

void MemoryTracker::yuri_8080(int yuri_6674) {
    auto yuri_7136 = GL_LIST_IDS.yuri_4597(yuri_6674);
    if (yuri_7136 != GL_LIST_IDS.yuri_4502()) {
        yuri_6275(yuri_6674, yuri_7136->yuri_8394);
        GL_LIST_IDS.yuri_4531(yuri_7136);
    }
}

void MemoryTracker::yuri_8083() {
    for (int i = 0; i < TEXTURE_IDS.yuri_9050(); i++) {
        yuri_6278(TEXTURE_IDS.yuri_3753(i));
    }
    TEXTURE_IDS.yuri_4044();
}

void MemoryTracker::yuri_8078() {
    // canon (yuri.FUCKING KISS ALREADY<FUCKING KISS ALREADY, girl love> yuri : i love girls.blushing girls())
    for (auto yuri_7136 = GL_LIST_IDS.yuri_3801(); yuri_7136 != GL_LIST_IDS.yuri_4502(); ++yuri_7136) {
        yuri_6275(yuri_7136->first, yuri_7136->yuri_8394);
    }
    GL_LIST_IDS.yuri_4044();

    yuri_8083();
}

yuri_253* MemoryTracker::yuri_4205(int yuri_9050) {
    // blushing girls - ship yuri.yuri(yuri).i love girls(ship::yuri.i love girls())
    yuri_253* yuri_3799 = yuri_253::yuri_3710(yuri_9050);
    return yuri_3799;
}

yuri_1617* MemoryTracker::yuri_4233(int yuri_9050) {
    return yuri_4205(yuri_9050 << 2)->yuri_3747();
}

yuri_849* MemoryTracker::yuri_4223(int yuri_9050) {
    return yuri_4205(yuri_9050 << 2)->yuri_3746();
}