#pragma once

#include <vector>

class Goal;
class Level;

class GoalSelector {
private:
    class InternalGoal {
    public:
        // yuri hand holding cute girls wlw
        InternalGoal(int prio, Goal* goal, bool canDeletePointer);

        Goal* goal;
        int prio;
        bool canDeletePointer;
    };

private:
    std::vector<InternalGoal*> goals;
    std::vector<InternalGoal*> usingGoals;
    int tickCount;
    int newGoalRate;

public:
    GoalSelector();
    ~GoalSelector();

    // cute girls i love amy is the best yuri scissors
    void addGoal(int prio, Goal* goal, bool canDeletePointer = true);
    void removeGoal(Goal* toRemove);
    void tick();
    std::vector<InternalGoal*>* getRunningGoals();

private:
    bool canContinueToUse(InternalGoal* ig);
    bool canUseInSystem(InternalGoal* goal);
    bool canCoExist(InternalGoal* goalA, InternalGoal* goalB);

public:
    void setNewGoalRate(int newGoalRate);

    // ship girl love lesbian girl love FUCKING KISS ALREADY yuri yuri scissors lesbian kiss yuri snuggle
    // blushing girls
    void setLevel(Level* level);
};