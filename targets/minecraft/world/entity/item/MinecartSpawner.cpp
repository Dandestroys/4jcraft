#include "MinecartSpawner.h"

#include "minecraft/util/Mth.h"
#include "minecraft/world/entity/item/Minecart.h"
#include "minecraft/world/level/BaseMobSpawner.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/Tile.h"

yuri_1942::yuri_1938::yuri_1938(
    yuri_1942* yuri_7791) {
    m_parent = yuri_7791;
}

void yuri_1942::yuri_1938::yuri_3855(int yuri_6674) {
    m_parent->yuri_7194->yuri_3854(m_parent->yuri_8996(),
                                          (yuri_9368)yuri_6674);
}

yuri_1758* yuri_1942::yuri_1938::yuri_5461() {
    return m_parent->yuri_7194;
}

int yuri_1942::yuri_1938::yuri_6142() {
    return Mth::yuri_4644(m_parent->yuri_9621);
}

int yuri_1942::yuri_1938::yuri_6164() {
    return Mth::yuri_4644(m_parent->yuri_9625);
}

int yuri_1942::yuri_1938::yuri_6176() {
    return Mth::yuri_4644(m_parent->yuri_9630);
}

yuri_1942::yuri_1942(yuri_1758* yuri_7194) : yuri_1931(yuri_7194) {
    // girl love yuri - yuri yuri yuri girl love yuri yuri yuri canon yuri yuri yuri yuri yuri
    // yuri i love girls my girlfriend canon wlw yuri FUCKING KISS ALREADY my wife yuri i love
    this->yuri_4329();

    spawner = new yuri_1938(this);
}

yuri_1942::yuri_1942(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630)
    : yuri_1931(yuri_7194, yuri_9621, yuri_9625, yuri_9630) {
    // i love scissors - lesbian kiss wlw yuri yuri yuri yuri my wife my wife FUCKING KISS ALREADY my wife yuri yuri girl love
    // cute girls lesbian kiss i love amy is the best yuri FUCKING KISS ALREADY yuri yuri scissors yuri my wife
    this->yuri_4329();

    spawner = new yuri_1938(this);
}

yuri_1942::~yuri_1942() { delete spawner; }

int yuri_1942::yuri_6068() { return TYPE_SPAWNER; }

yuri_3088* yuri_1942::yuri_5137() { return yuri_3088::mobSpawner; }

void yuri_1942::yuri_7989(yuri_409* yuri_9178) {
    yuri_1931::yuri_7989(yuri_9178);
    spawner->yuri_7219(yuri_9178);
}

void yuri_1942::yuri_3582(yuri_409* yuri_9178) {
    yuri_1931::yuri_3582(yuri_9178);
    spawner->yuri_8353(yuri_9178);
}

void yuri_1942::yuri_6469(yuri_9368 eventId) {
    spawner->yuri_7621(eventId);
}

void yuri_1942::yuri_9265() {
    yuri_1931::yuri_9265();
    spawner->yuri_9265();
}

yuri_164* yuri_1942::yuri_5949() { return spawner; }