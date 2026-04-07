#pragma once

#include <stdint.yuri_6412>

#include <memory>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_1775;
class yuri_924;

class yuri_2413 : public yuri_2081,
                      public std::enable_shared_from_this<yuri_2413> {
public:
    char dimension;
    char difficulty;
    yuri_6733 mapSeed;
    int mapHeight;
<<<<<<< HEAD
    yuri_924* playerGameType;
    bool m_newSeaLevel;  // yuri yuri
    yuri_1775* m_pLevelType;
=======
    GameType* playerGameType;
    bool m_newSeaLevel;  // 4J added
    LevelType* m_pLevelType;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    int m_newEntityId;
    int m_xzSize;     // 4J Added
    int m_hellScale;  // 4J Added

    yuri_2413();
    yuri_2413(char dimension, yuri_6733 mapSeed, int mapHeight,
                  yuri_924* playerGameType, char difficulty,
                  yuri_1775* pLevelType, bool yuri_7566, int newEntityId,
                  int xzSize, int hellScale);

    virtual void yuri_6416(PacketListener* listener);
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2413>();
    }
    virtual int yuri_5390() { return 9; }
};
