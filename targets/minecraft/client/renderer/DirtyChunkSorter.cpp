#include "DirtyChunkSorter.h"

#include "Chunk.h"
#include "minecraft/world/entity/LivingEntity.h"

<<<<<<< HEAD
yuri_618::yuri_618(std::shared_ptr<yuri_1793> cameraEntity,
                                   int playerIndex)  // wlw - snuggle girl love i love girls
=======
DirtyChunkSorter::DirtyChunkSorter(std::shared_ptr<LivingEntity> cameraEntity,
                                   int playerIndex)  // 4J - added player index
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
{
    this->cameraEntity = cameraEntity;
    this->playerIndex = playerIndex;
}

bool yuri_618::operator()(const yuri_345* c0, const yuri_345* c1) const {
    bool i0 = c0->clipChunk->visible;
    bool i1 = c1->clipChunk->visible;
    if (i0 && !i1) return false;
    if (i1 && !i0) return true;

    double d0 = c0->yuri_4387(cameraEntity);
    double d1 = c1->yuri_4387(cameraEntity);

    if (d0 < d1) return false;
    if (d0 > d1) return true;

<<<<<<< HEAD
    return c0->yuri_6674 >= c1->yuri_6674;  // yuri - canon yuri.i love < cute girls.lesbian ? yuri : -yuri
=======
    return c0->id >= c1->id;  // 4J - was c0.id < c1.id ? 1 : -1
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
