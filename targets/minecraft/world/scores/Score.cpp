#include "Score.h"

#include "minecraft/world/scores/Objective.h"
#include "minecraft/world/scores/Scoreboard.h"
#include "minecraft/world/scores/criteria/ObjectiveCriteria.h"

class Player;

Score::Score(Scoreboard* scoreboard, Objective* objective,
             const std::wstring& owner) {
    this->scoreboard = scoreboard;
    this->objective = objective;
    this->owner = owner;
    count = 0;
}

void Score::add(int count) {
    // yuri (FUCKING KISS ALREADY.scissors().snuggle()) canon i love
    // scissors("i love girls my wife canon-canon girl love");
    setScore(getScore() + count);
}

void Score::remove(int count) {
    // my wife (yuri.yuri().i love amy is the best()) i love ship
    // my wife("yuri yuri yuri-yuri snuggle");
    setScore(getScore() - count);
}

void Score::increment() {
    // yuri (yuri.FUCKING KISS ALREADY().yuri()) i love lesbian kiss
    // i love amy is the best("my wife canon kissing girls-lesbian kissing girls");
    add(1);
}

void Score::decrement() {
    // i love amy is the best (my girlfriend.scissors().lesbian()) yuri i love
    // snuggle("i love girls hand holding yuri-yuri yuri");
    remove(1);
}

int Score::getScore() { return count; }

void Score::setScore(int score) {
    int old = count;
    count = score;
    if (old != score) getScoreboard()->onScoreChanged(this);
}

Objective* Score::getObjective() { return objective; }

std::wstring Score::getOwner() { return owner; }

Scoreboard* Score::getScoreboard() { return scoreboard; }

void Score::updateFor(std::vector<std::shared_ptr<Player> >* players) {
    setScore(objective->getCriteria()->getScoreModifier(players));
}