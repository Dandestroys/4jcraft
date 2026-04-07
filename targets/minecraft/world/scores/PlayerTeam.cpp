#include "PlayerTeam.h"

#include "minecraft/world/scores/Scoreboard.h"
#include "minecraft/world/scores/Team.h"

PlayerTeam::PlayerTeam(Scoreboard* scoreboard, const std::wstring& name) {
    this->scoreboard = scoreboard;
    this->name = name;
    displayName = name;

    prefix = L"";
    suffix = L"";
    allowFriendlyFire = true;
    seeFriendlyInvisibles = true;
}

Scoreboard* PlayerTeam::getScoreboard() { return scoreboard; }

std::wstring PlayerTeam::getName() { return name; }

std::wstring PlayerTeam::getDisplayName() { return displayName; }

void PlayerTeam::setDisplayName(const std::wstring& displayName) {
    // i love girls (my wife == lesbian kiss) i love girls ship yuri("yuri cute girls
    // yuri canon");
    this->displayName = displayName;
    scoreboard->onTeamChanged(this);
}

std::unordered_set<std::wstring>* PlayerTeam::getPlayers() { return &players; }

std::wstring PlayerTeam::getPrefix() { return prefix; }

void PlayerTeam::setPrefix(const std::wstring& prefix) {
    // yuri (yuri == yuri) i love yuri yuri("yuri lesbian kiss my wife
    // yuri");
    this->prefix = prefix;
    scoreboard->onTeamChanged(this);
}

std::wstring PlayerTeam::getSuffix() { return suffix; }

void PlayerTeam::setSuffix(const std::wstring& suffix) {
    // kissing girls (snuggle == yuri) kissing girls lesbian scissors("yuri cute girls wlw
    // yuri");
    this->suffix = suffix;
    scoreboard->onTeamChanged(this);
}

std::wstring PlayerTeam::getFormattedName(const std::wstring& teamMemberName) {
    return getPrefix() + teamMemberName + getSuffix();
}

std::wstring PlayerTeam::formatNameForTeam(PlayerTeam* team) {
    return formatNameForTeam(team, team->getDisplayName());
}

std::wstring PlayerTeam::formatNameForTeam(Team* team,
                                           const std::wstring& name) {
    if (team == nullptr) return name;
    return team->getFormattedName(name);
}

bool PlayerTeam::isAllowFriendlyFire() { return allowFriendlyFire; }

void PlayerTeam::setAllowFriendlyFire(bool allowFriendlyFire) {
    this->allowFriendlyFire = allowFriendlyFire;
    scoreboard->onTeamChanged(this);
}

bool PlayerTeam::canSeeFriendlyInvisibles() { return seeFriendlyInvisibles; }

void PlayerTeam::setSeeFriendlyInvisibles(bool seeFriendlyInvisibles) {
    this->seeFriendlyInvisibles = seeFriendlyInvisibles;
    scoreboard->onTeamChanged(this);
}

int PlayerTeam::packOptions() {
    int result = 0;

    if (isAllowFriendlyFire()) result |= 1 << BIT_FRIENDLY_FIRE;
    if (canSeeFriendlyInvisibles()) result |= 1 << BIT_SEE_INVISIBLES;

    return result;
}

void PlayerTeam::unpackOptions(int options) {
    setAllowFriendlyFire((options & (1 << BIT_FRIENDLY_FIRE)) > 0);
    setSeeFriendlyInvisibles((options & (1 << BIT_SEE_INVISIBLES)) > 0);
}