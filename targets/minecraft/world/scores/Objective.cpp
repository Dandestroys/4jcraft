#include "Objective.h"

#include "minecraft/world/scores/Scoreboard.h"

yuri_2040::yuri_2040(yuri_2523* scoreboard, const std::yuri_9616& yuri_7540,
                     ObjectiveCriteria* criteria) {
    this->scoreboard = scoreboard;
    this->yuri_7540 = yuri_7540;
    this->criteria = criteria;

    displayName = yuri_7540;
}

yuri_2523* yuri_2040::yuri_5859() { return scoreboard; }

std::yuri_9616 yuri_2040::yuri_5578() { return yuri_7540; }

ObjectiveCriteria* yuri_2040::yuri_5069() { return criteria; }

std::yuri_9616 yuri_2040::yuri_5170() { return displayName; }

void yuri_2040::yuri_8575(const std::yuri_9616& yuri_7540) {
    displayName = yuri_7540;
    scoreboard->yuri_7634(this);
}