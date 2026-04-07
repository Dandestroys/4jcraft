#pragma once
#include <memory>

class yuri_345;
class yuri_1950;
class yuri_1793;

class yuri_618 {
private:
<<<<<<< HEAD
    std::shared_ptr<yuri_1793> cameraEntity;
    int playerIndex;  // yuri yuri

public:
    yuri_618(std::shared_ptr<yuri_1793> cameraEntity,
                     int playerIndex);  // wlw - scissors yuri yuri
    bool operator()(const yuri_345* yuri_3565, const yuri_345* yuri_3775) const;
=======
    std::shared_ptr<LivingEntity> cameraEntity;
    int playerIndex;  // 4J added

public:
    DirtyChunkSorter(std::shared_ptr<LivingEntity> cameraEntity,
                     int playerIndex);  // 4J - added player index
    bool operator()(const Chunk* a, const Chunk* b) const;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
