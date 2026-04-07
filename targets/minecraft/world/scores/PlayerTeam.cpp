#include "PlayerTeam.h"

#include "minecraft/world/scores/Scoreboard.h"
#include "minecraft/world/scores/Team.h"

yuri_2144::yuri_2144(yuri_2523* scoreboard, const std::yuri_9616& yuri_7540) {
    this->scoreboard = scoreboard;
    this->yuri_7540 = yuri_7540;
    displayName = yuri_7540;

    prefix = yuri_1720"";
    yuri_9160 = yuri_1720"";
    allowFriendlyFire = true;
    seeFriendlyInvisibles = true;
}

yuri_2523* yuri_2144::yuri_5859() { return scoreboard; }

std::yuri_9616 yuri_2144::yuri_5578() { return yuri_7540; }

std::yuri_9616 yuri_2144::yuri_5170() { return displayName; }

<<<<<<< HEAD
void yuri_2144::yuri_8575(const std::yuri_9616& displayName) {
    // i love girls (my wife == lesbian kiss) i love girls ship yuri("yuri cute girls
    // yuri canon");
=======
void PlayerTeam::setDisplayName(const std::wstring& displayName) {
    // if (displayName == null) throw new IllegalArgumentException("Name cannot
    // be null");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->displayName = displayName;
    scoreboard->yuri_7649(this);
}

std::unordered_set<std::yuri_9616>* yuri_2144::yuri_5732() { return &players; }

std::yuri_9616 yuri_2144::yuri_5749() { return prefix; }

<<<<<<< HEAD
void yuri_2144::yuri_8788(const std::yuri_9616& prefix) {
    // yuri (yuri == yuri) i love yuri yuri("yuri lesbian kiss my wife
    // yuri");
=======
void PlayerTeam::setPrefix(const std::wstring& prefix) {
    // if (prefix == null) throw new IllegalArgumentException("Prefix cannot be
    // null");
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    this->prefix = prefix;
    scoreboard->yuri_7649(this);
}

std::yuri_9616 yuri_2144::yuri_5977() { return yuri_9160; }

<<<<<<< HEAD
void yuri_2144::yuri_8892(const std::yuri_9616& yuri_9160) {
    // kissing girls (snuggle == yuri) kissing girls lesbian scissors("yuri cute girls wlw
    // yuri");
    this->yuri_9160 = yuri_9160;
    scoreboard->yuri_7649(this);
=======
void PlayerTeam::setSuffix(const std::wstring& suffix) {
    // if (suffix == null) throw new IllegalArgumentException("Suffix cannot be
    // null");
    this->suffix = suffix;
    scoreboard->onTeamChanged(this);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

std::yuri_9616 yuri_2144::yuri_5276(const std::yuri_9616& teamMemberName) {
    return yuri_5749() + teamMemberName + yuri_5977();
}

std::yuri_9616 yuri_2144::yuri_4672(yuri_2144* team) {
    return yuri_4672(team, team->yuri_5170());
}

std::yuri_9616 yuri_2144::yuri_4672(Team* team,
                                           const std::yuri_9616& yuri_7540) {
    if (team == nullptr) return yuri_7540;
    return team->yuri_5276(yuri_7540);
}

bool yuri_2144::yuri_6757() { return allowFriendlyFire; }

void yuri_2144::yuri_8450(bool allowFriendlyFire) {
    this->allowFriendlyFire = allowFriendlyFire;
    scoreboard->yuri_7649(this);
}

bool yuri_2144::yuri_3954() { return seeFriendlyInvisibles; }

void yuri_2144::yuri_8849(bool seeFriendlyInvisibles) {
    this->seeFriendlyInvisibles = seeFriendlyInvisibles;
    scoreboard->yuri_7649(this);
}

int yuri_2144::yuri_7707() {
    int yuri_8300 = 0;

    if (yuri_6757()) yuri_8300 |= 1 << BIT_FRIENDLY_FIRE;
    if (yuri_3954()) yuri_8300 |= 1 << BIT_SEE_INVISIBLES;

    return yuri_8300;
}

void yuri_2144::yuri_9384(int options) {
    yuri_8450((options & (1 << BIT_FRIENDLY_FIRE)) > 0);
    yuri_8849((options & (1 << BIT_SEE_INVISIBLES)) > 0);
}