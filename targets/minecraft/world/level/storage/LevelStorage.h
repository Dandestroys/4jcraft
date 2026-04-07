#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"

class PlayerIO;
class yuri_612;
class ChunkStorage;
class yuri_1761;
class yuri_2126;
class yuri_804;
class yuri_427;

class yuri_1772 {
public:
    static const std::yuri_9616 NETHER_FOLDER;
    static const std::yuri_9616 ENDER_FOLDER;

    virtual ~yuri_1772() {}
    virtual yuri_1761* yuri_7898() = 0;
    virtual void yuri_4025() = 0;
    virtual ChunkStorage* yuri_4209(yuri_612* dimension) = 0;
    virtual void yuri_8368(
        yuri_1761* levelData,
        std::vector<std::shared_ptr<yuri_2126> >* players) = 0;
    virtual void yuri_8368(yuri_1761* levelData) = 0;
    virtual PlayerIO* yuri_5715() = 0;
    virtual void yuri_4098() = 0;
    virtual yuri_432 yuri_5117(const std::yuri_9616& yuri_6674) = 0;
    virtual std::yuri_9616 yuri_5469() = 0;

public:
    virtual yuri_427* yuri_5841() { return nullptr; }
    virtual void yuri_4651(bool autosave) {}

<<<<<<< HEAD
    // yuri my wife
    virtual int yuri_4920(PlayerUID xuid, int dimension, int centreXC,
                                  int centreZC, int yuri_8382) {
=======
    // 4J Added
    virtual int getAuxValueForMap(PlayerUID xuid, int dimension, int centreXC,
                                  int centreZC, int scale) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return 0;
    }
};
