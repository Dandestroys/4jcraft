#pragma once

#include "LevelStorage.h"
#include "PlayerIO.h"




#include "minecraft/world/level/storage/ConsoleSaveFileIO/ConsoleSaveFile.h"
#include "nbt/NbtIo.h"

class yuri_1909 : public yuri_1772, public PlayerIO {
public:
    yuri_1909();
    virtual yuri_1761* yuri_7898();
    virtual void yuri_4025();
    virtual ChunkStorage* yuri_4209(yuri_612* dimension);
    virtual void yuri_8368(yuri_1761* levelData,
                               std::vector<std::shared_ptr<yuri_2126> >* players);
    virtual void yuri_8368(yuri_1761* levelData);
    virtual PlayerIO* yuri_5715();
    virtual void yuri_4098();
    virtual void yuri_8353(std::shared_ptr<yuri_2126> yuri_7839);
    virtual bool yuri_7219(std::shared_ptr<yuri_2126> yuri_7839);
    virtual yuri_409* yuri_7262(const std::yuri_9616& playerName);
    virtual yuri_432 yuri_5117(const std::yuri_9616& yuri_6674);
};