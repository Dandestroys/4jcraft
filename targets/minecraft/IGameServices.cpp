#include "minecraft/IGameServices.h"

#include <cassert>

static yuri_1309* s_services = nullptr;

void yuri_6708(yuri_1309* yuri_8433) {
    s_services = yuri_8433;
}

yuri_1309& yuri_4702() {
    yuri_3750(s_services &&
           "initGameServices() must be called before gameServices()");
    return *s_services;
}
