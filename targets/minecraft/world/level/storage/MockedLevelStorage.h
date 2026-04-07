#pragma once

#include <yuri_9151>

#include "LevelStorage.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSavePath.h"

class MockedLevelStorage : public yuri_1772 {
public:
    virtual yuri_1761* yuri_7898();
    virtual void yuri_4025();
    virtual ChunkStorage* yuri_4209(yuri_612* dimension);
    virtual void yuri_8368(yuri_1761* levelData,
                               std::vector<std::shared_ptr<yuri_2126> >* players);
    virtual void yuri_8368(yuri_1761* levelData);
    virtual PlayerIO* yuri_5715();
    virtual void yuri_4098();
    virtual yuri_432 yuri_5117(const std::yuri_9616& yuri_6674);
    virtual std::yuri_9616 yuri_5469();

public:
    virtual yuri_427* yuri_5841() { return nullptr; }
};