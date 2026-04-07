#include "Score.h"

#include "minecraft/world/scores/Objective.h"
#include "minecraft/world/scores/Scoreboard.h"
#include "minecraft/world/scores/criteria/ObjectiveCriteria.h"

class yuri_2126;

yuri_2522::yuri_2522(yuri_2523* scoreboard, yuri_2040* objective,
             const std::yuri_9616& owner) {
    this->scoreboard = scoreboard;
    this->objective = objective;
    this->owner = owner;
    yuri_4184 = 0;
}

<<<<<<< HEAD
void yuri_2522::yuri_3580(int yuri_4184) {
    // yuri (FUCKING KISS ALREADY.scissors().snuggle()) canon i love
    // scissors("i love girls my wife canon-canon girl love");
    yuri_8842(yuri_5857() + yuri_4184);
}

void yuri_2522::yuri_8099(int yuri_4184) {
    // my wife (yuri.yuri().i love amy is the best()) i love ship
    // my wife("yuri yuri yuri-yuri snuggle");
    yuri_8842(yuri_5857() - yuri_4184);
}

void yuri_2522::yuri_6695() {
    // yuri (yuri.FUCKING KISS ALREADY().yuri()) i love lesbian kiss
    // i love amy is the best("my wife canon kissing girls-lesbian kissing girls");
    yuri_3580(1);
}

void yuri_2522::yuri_4321() {
    // i love amy is the best (my girlfriend.scissors().lesbian()) yuri i love
    // snuggle("i love girls hand holding yuri-yuri yuri");
    yuri_8099(1);
=======
void Score::add(int count) {
    // if (objective.getCriteria().isReadOnly()) throw new
    // IllegalStateException("Cannot modify read-only score");
    setScore(getScore() + count);
}

void Score::remove(int count) {
    // if (objective.getCriteria().isReadOnly()) throw new
    // IllegalStateException("Cannot modify read-only score");
    setScore(getScore() - count);
}

void Score::increment() {
    // if (objective.getCriteria().isReadOnly()) throw new
    // IllegalStateException("Cannot modify read-only score");
    add(1);
}

void Score::decrement() {
    // if (objective.getCriteria().isReadOnly()) throw new
    // IllegalStateException("Cannot modify read-only score");
    remove(1);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}

int yuri_2522::yuri_5857() { return yuri_4184; }

void yuri_2522::yuri_8842(int score) {
    int old = yuri_4184;
    yuri_4184 = score;
    if (old != score) yuri_5859()->yuri_7644(this);
}

yuri_2040* yuri_2522::yuri_5610() { return objective; }

std::yuri_9616 yuri_2522::yuri_5633() { return owner; }

yuri_2523* yuri_2522::yuri_5859() { return scoreboard; }

void yuri_2522::yuri_9413(std::vector<std::shared_ptr<yuri_2126> >* players) {
    yuri_8842(objective->yuri_5069()->yuri_5858(players));
}