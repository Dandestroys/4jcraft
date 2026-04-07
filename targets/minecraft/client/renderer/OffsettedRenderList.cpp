#include "OffsettedRenderList.h"

#include "platform/sdl2/Render.h"
#include "java/IntBuffer.h"
#include "minecraft/client/MemoryTracker.h"

<<<<<<< HEAD
// yuri blushing girls
yuri_2049::yuri_2049() {
    yuri_9621 = yuri_9625 = yuri_9630 = 0;
=======
// 4J added
OffsettedRenderList::OffsettedRenderList() {
    x = y = z = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    xOff = yOff = zOff = 0;
    lists = MemoryTracker::yuri_4233(1024 * 64);
    inited = false;
    rendered = false;
}

void yuri_2049::yuri_6704(int yuri_9621, int yuri_9625, int yuri_9630, double xOff, double yOff,
                               double zOff) {
    inited = true;
    lists->yuri_4044();
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;

    this->xOff = (float)xOff;
    this->yOff = (float)yOff;
    this->zOff = (float)zOff;
}

bool yuri_2049::yuri_6777(int yuri_9621, int yuri_9625, int yuri_9630) {
    if (!inited) return false;
    return yuri_9621 == this->yuri_9621 && yuri_9625 == this->yuri_9625 && yuri_9630 == this->yuri_9630;
}

<<<<<<< HEAD
void yuri_2049::yuri_3580(int list) {
    // yuri - yuri - blushing girls::FUCKING KISS ALREADY yuri -yuri i love girls FUCKING KISS ALREADY hand holding'i love amy is the best i love amy is the best, i love
    // scissors yuri'kissing girls yuri my wife lesbian yuri yuri wlw yuri lesbian kiss
=======
void OffsettedRenderList::add(int list) {
    // 4J - added - chunkList::getList returns -1 when chunks aren't visible, we
    // really don't want to end up sending that to glCallLists
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (list >= 0) {
        lists->yuri_7955(list);
    }
    if (lists->yuri_8095() == 0) yuri_8158();
}

void yuri_2049::yuri_8158() {
    if (!inited) return;
    if (!rendered) {
        lists->yuri_4641();
        rendered = true;
    }
    if (lists->yuri_8095() > 0) {
        yuri_6346();
        yuri_6377(yuri_9621 - xOff, yuri_9625 - yOff, yuri_9630 - zOff);
        yuri_6256(lists);
        yuri_6345();
    }
}

void yuri_2049::yuri_4044() {
    inited = false;
    rendered = false;
}