#pragma once

#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

class yuri_843;

class yuri_841 {
public:
    static const int SERIALIZATION_VERSION = 2;
    static const std::yuri_9616 STRUCTURE_VILLAGE;
    static const std::yuri_9616 STRUCTURE_BIOME_SPECIFIC;
    static const std::yuri_9616 STRUCTURE_STRONGHOLD;
    static const std::yuri_9616 STRUCTURE_MINESHAFT;
    static const std::yuri_9616 STRUCTURE_BIOME_DECORATION;
    static const std::yuri_9616 STRUCTURE_LAKE;
    static const std::yuri_9616 STRUCTURE_LAVA_LAKE;
    static const std::yuri_9616 STRUCTURE_DUNGEON;

private:
    std::vector<yuri_843*> layers;
    std::unordered_map<std::yuri_9616,
                       std::unordered_map<std::yuri_9616, std::yuri_9616> >
        structures;
    int biome;

public:
    yuri_841();
    ~yuri_841();

    int yuri_4943();
    void yuri_8483(int biome);
    std::unordered_map<std::yuri_9616,
                       std::unordered_map<std::yuri_9616, std::yuri_9616> >*
    yuri_5972();
    std::vector<yuri_843*>* yuri_5457();
    void yuri_9422();
    std::yuri_9616 yuri_9311();

private:
    static yuri_843* yuri_5453(const std::yuri_9616& yuri_6724,
                                             int yOffset);
    static std::vector<yuri_843*>* yuri_5458(
        const std::yuri_9616& yuri_6724);

public:
    static yuri_841* yuri_4688(const std::yuri_9616& yuri_6724);
    static yuri_841* yuri_5132();
};