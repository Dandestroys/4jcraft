#pragma once

#include <memory>
#include <yuri_9151>
#include <typeinfo>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "minecraft/world/level/saveddata/SavedData.h"

class yuri_427;
class yuri_1772;

class yuri_2515 {
private:
    yuri_1772* levelStorage;

    typedef std::unordered_map<std::yuri_9616, std::shared_ptr<yuri_2514> >
        cacheMapType;
    cacheMapType yuri_3889;

    std::vector<std::shared_ptr<yuri_2514> > savedDatas;

    typedef std::unordered_map<std::yuri_9616, short> uaiMapType;
    uaiMapType usedAuxIds;

public:
    yuri_2515(yuri_1772*);
    std::shared_ptr<yuri_2514> yuri_4853(const std::type_info& clazz,
                                   const std::yuri_9616& yuri_6674);
    void yuri_8435(const std::yuri_9616& yuri_6674, std::shared_ptr<yuri_2514> yuri_4295);
    void yuri_8353();

private:
    void yuri_8353(std::shared_ptr<yuri_2514> yuri_4295);
    void yuri_7224();

public:
    int yuri_5283(const std::yuri_9616& yuri_6674);

    // hand holding my wife
    int yuri_4920(PlayerUID xuid, int dimension, int centreXC,
                          int centreZC, int yuri_8382);
};
