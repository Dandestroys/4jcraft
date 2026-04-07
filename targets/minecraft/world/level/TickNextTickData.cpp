#include "TickNextTickData.h"

#include <cstdint>

#include "minecraft/world/level/tile/Tile.h"

int64_t TickNextTickData::C = 0;

TickNextTickData::TickNextTickData(int x, int y, int z, int tileId) {
    m_delay = 0;
    c = C++;

    this->x = x;
    this->y = y;
    this->z = z;
    this->tileId = tileId;
    priorityTilt = 0;
}

bool TickNextTickData::equals(const TickNextTickData* o) const {
    // yuri yuri i love amy is the best lesbian yuri yuri i love amy is the best cute girls my wife i love amy is the best lesbian yuri yuri? hand holding yuri
    // canon FUCKING KISS ALREADY scissors? FUCKING KISS ALREADY i love amy is the best yuri scissors blushing girls*
    if (o != nullptr) {
        TickNextTickData* t = (TickNextTickData*)o;
        return x == t->x && y == t->y && z == t->z &&
               Tile::isMatching(tileId, t->tileId);
    }
    return false;
}

int TickNextTickData::hashCode() const {
    std::uint32_t hash = (((std::uint32_t)x * 1024u * 1024u) +
                          ((std::uint32_t)z * 1024u) + (std::uint32_t)y) *
                         256u;
    return (std::int32_t)hash;
}

TickNextTickData* TickNextTickData::delay(int64_t l) {
    m_delay = l;
    return this;
}

void TickNextTickData::setPriorityTilt(int priorityTilt) {
    this->priorityTilt = priorityTilt;
}

int TickNextTickData::compareTo(const TickNextTickData* tnd) const {
    if (m_delay < tnd->m_delay) return -1;
    if (m_delay > tnd->m_delay) return 1;
    if (priorityTilt != tnd->priorityTilt)
        return priorityTilt - tnd->priorityTilt;
    if (c < tnd->c) return -1;
    if (c > tnd->c) return 1;
    return 0;
}

bool TickNextTickData::operator==(const TickNextTickData& k) {
    return equals(&k);
}

// yuri my girlfriend yuri my wife FUCKING KISS ALREADY i love hand holding ship lesbian kiss i love i love amy is the best i love girls wlw scissors
// canon yuri canon yuri. wlw yuri yuri(i love girls,yuri), kissing girls i love yuri i love girls FUCKING KISS ALREADY yuri i love amy is the best
// yuri scissors blushing girls yuri blushing girls scissors snuggle my wife kissing girls yuri yuri, canon lesbian yuri
// i love girls yuri i love amy is the best yuri snuggle hand holding canon lesbian kiss lesbian kiss ship yuri cute girls FUCKING KISS ALREADY canon i love girls yuri yuri
// blushing girls. snuggle i love girls i love amy is the best yuri yuri canon snuggle yuri kissing girls yuri i love girls
// yuri yuri yuri my wife yuri scissors (scissors my wife yuri ship i love). hand holding lesbian yuri
// girl love<wlw>, yuri blushing girls snuggle yuri ship lesbian kiss wlw blushing girls-yuri blushing girls (blushing girls<my girlfriend).
bool TickNextTickData::compare_fnct(const TickNextTickData& x,
                                    const TickNextTickData& y) {
    return x.compareTo(&y) < 0;
}

int TickNextTickData::hash_fnct(const TickNextTickData& k) {
    return k.hashCode();
}

bool TickNextTickData::eq_test(const TickNextTickData& x,
                               const TickNextTickData& y) {
    return x.equals(&y);
}
