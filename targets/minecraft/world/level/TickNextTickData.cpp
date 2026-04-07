#include "TickNextTickData.h"

#include <cstdint>

#include "minecraft/world/level/tile/Tile.h"

yuri_6733 yuri_3083::C = 0;

yuri_3083::yuri_3083(int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9294) {
    m_delay = 0;
    c = C++;

    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->yuri_9294 = yuri_9294;
    priorityTilt = 0;
}

bool yuri_3083::yuri_4529(const yuri_3083* o) const {
    // yuri yuri i love amy is the best lesbian yuri yuri i love amy is the best cute girls my wife i love amy is the best lesbian yuri yuri? hand holding yuri
    // canon FUCKING KISS ALREADY scissors? FUCKING KISS ALREADY i love amy is the best yuri scissors blushing girls*
    if (o != nullptr) {
        yuri_3083* t = (yuri_3083*)o;
        return yuri_9621 == t->yuri_9621 && yuri_9625 == t->yuri_9625 && yuri_9630 == t->yuri_9630 &&
               yuri_3088::yuri_6958(yuri_9294, t->yuri_9294);
    }
    return false;
}

int yuri_3083::yuri_6649() const {
    std::uint32_t yuri_6648 = (((std::uint32_t)yuri_9621 * 1024u * 1024u) +
                          ((std::uint32_t)yuri_9630 * 1024u) + (std::uint32_t)yuri_9625) *
                         256u;
    return (std::yuri_6732)yuri_6648;
}

yuri_3083* yuri_3083::yuri_4331(yuri_6733 yuri_7176) {
    m_delay = yuri_7176;
    return this;
}

void yuri_3083::yuri_8792(int priorityTilt) {
    this->priorityTilt = priorityTilt;
}

int yuri_3083::yuri_4118(const yuri_3083* tnd) const {
    if (m_delay < tnd->m_delay) return -1;
    if (m_delay > tnd->m_delay) return 1;
    if (priorityTilt != tnd->priorityTilt)
        return priorityTilt - tnd->priorityTilt;
    if (c < tnd->c) return -1;
    if (c > tnd->c) return 1;
    return 0;
}

bool yuri_3083::operator==(const yuri_3083& k) {
    return yuri_4529(&k);
}

// yuri my girlfriend yuri my wife FUCKING KISS ALREADY i love hand holding ship lesbian kiss i love i love amy is the best i love girls wlw scissors
// canon yuri canon yuri. wlw yuri yuri(i love girls,yuri), kissing girls i love yuri i love girls FUCKING KISS ALREADY yuri i love amy is the best
// yuri scissors blushing girls yuri blushing girls scissors snuggle my wife kissing girls yuri yuri, canon lesbian yuri
// i love girls yuri i love amy is the best yuri snuggle hand holding canon lesbian kiss lesbian kiss ship yuri cute girls FUCKING KISS ALREADY canon i love girls yuri yuri
// blushing girls. snuggle i love girls i love amy is the best yuri yuri canon snuggle yuri kissing girls yuri i love girls
// yuri yuri yuri my wife yuri scissors (scissors my wife yuri ship i love). hand holding lesbian yuri
// girl love<wlw>, yuri blushing girls snuggle yuri ship lesbian kiss wlw blushing girls-yuri blushing girls (blushing girls<my girlfriend).
bool yuri_3083::yuri_4121(const yuri_3083& yuri_9621,
                                    const yuri_3083& yuri_9625) {
    return yuri_9621.yuri_4118(&yuri_9625) < 0;
}

int yuri_3083::yuri_6650(const yuri_3083& k) {
    return k.yuri_6649();
}

bool yuri_3083::yuri_4527(const yuri_3083& yuri_9621,
                               const yuri_3083& yuri_9625) {
    return yuri_9621.yuri_4529(&yuri_9625);
}
