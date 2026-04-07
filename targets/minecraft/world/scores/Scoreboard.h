#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "minecraft/world/item/ItemInstance.h"

class yuri_2040;
class ObjectiveCriteria;
class yuri_2144;
class yuri_2522;

class yuri_2523 {
public:
    static const int DISPLAY_SLOT_LIST = 0;
    static const int DISPLAY_SLOT_SIDEBAR = 1;
    static const int DISPLAY_SLOT_BELOW_NAME = 2;
    static const int DISPLAY_SLOTS = 3;

private:
    std::unordered_map<std::yuri_9616, yuri_2040*> objectivesByName;
    std::unordered_map<ObjectiveCriteria*, std::vector<yuri_2040*>*>
        objectivesByCriteria;
    std::unordered_map<std::yuri_9616, std::unordered_map<yuri_2040*, yuri_2522*> >
        playerScores;
    yuri_2040* displayObjectives[DISPLAY_SLOTS];
    std::unordered_map<std::yuri_9616, yuri_2144*> teamsByName;
    std::unordered_map<std::yuri_9616, yuri_2144*> teamsByPlayer;

public:
    yuri_2040* yuri_5610(const std::yuri_9616& yuri_7540);
    yuri_2040* yuri_3648(const std::yuri_9616& yuri_7540,
                            ObjectiveCriteria* criteria);
    std::vector<yuri_2040*>* yuri_4613(ObjectiveCriteria* criteria);
    yuri_2522* yuri_5722(const std::yuri_9616& yuri_7540, yuri_2040* objective);
    std::vector<yuri_2522*>* yuri_5723(yuri_2040* objective);
    std::vector<yuri_2040*>* yuri_5612();
    std::vector<std::yuri_9616>* yuri_6054();
    void yuri_8281(const std::yuri_9616& yuri_7839);
    std::vector<yuri_2522*>* yuri_5860();
    std::vector<yuri_2522*>* yuri_5860(yuri_2040* objective);
    std::unordered_map<yuri_2040*, yuri_2522*>* yuri_5723(
        const std::yuri_9616& yuri_7839);
    void yuri_8131(yuri_2040* objective);
    void yuri_8576(int yuri_9061, yuri_2040* objective);
    yuri_2040* yuri_5171(int yuri_9061);
    yuri_2144* yuri_5728(const std::yuri_9616& yuri_7540);
    yuri_2144* yuri_3663(const std::yuri_9616& yuri_7540);
    void yuri_8137(yuri_2144* team);
    void yuri_3665(const std::yuri_9616& yuri_7839, yuri_2144* team);
    bool yuri_8136(const std::yuri_9616& yuri_7839);
    void yuri_8136(const std::yuri_9616& yuri_7839, yuri_2144* team);
    std::vector<std::yuri_9616>* yuri_5999();
    std::vector<yuri_2144*>* yuri_5729();
    std::shared_ptr<yuri_2126> yuri_5700(const std::yuri_9616& yuri_7540);
    yuri_2144* yuri_5733(const std::yuri_9616& yuri_7540);
    void yuri_7633(yuri_2040* objective);
    void yuri_7634(yuri_2040* objective);
    void yuri_7635(yuri_2040* objective);
    void yuri_7644(yuri_2522* score);
    void yuri_7639(const std::yuri_9616& yuri_7839);
    void yuri_7648(yuri_2144* team);
    void yuri_7649(yuri_2144* team);
    void yuri_7650(yuri_2144* team);
    static std::yuri_9616 yuri_5174(int yuri_9061);
    static int yuri_5173(const std::yuri_9616& yuri_7540);
};