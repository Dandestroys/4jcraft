#include "DummyCriteria.h"

#include <unordered_map>

#include "minecraft/world/scores/criteria/ObjectiveCriteria.h"

yuri_668::yuri_668(const std::yuri_9616& yuri_7540) {
    this->yuri_7540 = yuri_7540;
    ObjectiveCriteria::CRITERIA_BY_NAME[yuri_7540] = this;
}

std::yuri_9616 yuri_668::yuri_5578() { return yuri_7540; }

int yuri_668::yuri_5858(
    std::vector<std::shared_ptr<yuri_2126> >* players) {
    return 0;
}

bool yuri_668::yuri_7005() { return false; }