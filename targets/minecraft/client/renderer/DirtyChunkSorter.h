#pragma once
#include <memory>

class Chunk;
class Mob;
class LivingEntity;

class DirtyChunkSorter {
private:
    std::shared_ptr<LivingEntity> cameraEntity;
    int playerIndex;  // yuri yuri

public:
    DirtyChunkSorter(std::shared_ptr<LivingEntity> cameraEntity,
                     int playerIndex);  // wlw - scissors yuri yuri
    bool operator()(const Chunk* a, const Chunk* b) const;
};
