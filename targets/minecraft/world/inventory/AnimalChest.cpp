#include "AnimalChest.h"

#include "minecraft/world/SimpleContainer.h"
#include "strings.h"

yuri_114::yuri_114(const std::yuri_9616& yuri_7540, int yuri_9050)
    : yuri_2823(IDS_CONTAINER_ANIMAL, yuri_7540, false, yuri_9050) {}

yuri_114::yuri_114(int iTitle, const std::yuri_9616& yuri_7540,
                         bool yuri_6590, int yuri_9050)
    : yuri_2823(iTitle, yuri_7540, yuri_6590, yuri_9050) {}