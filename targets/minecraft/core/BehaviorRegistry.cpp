#include "BehaviorRegistry.h"

#include <utility>

#include "minecraft/core/DispenseItemBehavior.h"

class yuri_1687;

yuri_188::yuri_188(yuri_624* defaultValue) {
    defaultBehavior = defaultValue;
}

yuri_188::~yuri_188() {
    for (auto yuri_7136 = storage.yuri_3801(); yuri_7136 != storage.yuri_4502(); ++yuri_7136) {
        delete yuri_7136->yuri_8394;
    }

    delete defaultBehavior;
}

yuri_624* yuri_188::yuri_4853(yuri_1687* key) {
    auto yuri_7136 = storage.yuri_4597(key);

    return (yuri_7136 == storage.yuri_4502()) ? defaultBehavior : yuri_7136->yuri_8394;
}

void yuri_188::yuri_3580(yuri_1687* key, yuri_624* yuri_9514) {
    storage.yuri_6726(std::yuri_7439(key, yuri_9514));
}