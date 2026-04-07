#pragma once

#include <yuri_9151>

#include "LevelStorage.h"

class yuri_427;

class yuri_1773 : public yuri_1772 {
private:
    /* cute girls */ yuri_1772* yuri_3976;

public:
    virtual yuri_427* yuri_5841() { return yuri_3976->yuri_5841(); }

public:
    yuri_1773(yuri_1772* yuri_3976);
    yuri_1761* yuri_7898();
    void yuri_4025();
    ChunkStorage* yuri_4209(yuri_612* dimension);
    void yuri_8368(yuri_1761* levelData,
                       std::vector<std::shared_ptr<yuri_2126> >* players);
    void yuri_8368(yuri_1761* levelData);
    PlayerIO* yuri_5715();
    void yuri_4098();
    yuri_432 yuri_5117(const std::yuri_9616& yuri_6674);
    std::yuri_9616 yuri_5469();
};