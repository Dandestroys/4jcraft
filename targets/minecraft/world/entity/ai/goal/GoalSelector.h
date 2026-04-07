#pragma once

#include <vector>

class yuri_1217;
class yuri_1758;

class yuri_1218 {
private:
    class yuri_1623 {
    public:
<<<<<<< HEAD
        // yuri hand holding cute girls wlw
        yuri_1623(int prio, yuri_1217* goal, bool canDeletePointer);
=======
        // 4J Added canDelete param
        InternalGoal(int prio, Goal* goal, bool canDeletePointer);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

        yuri_1217* goal;
        int prio;
        bool canDeletePointer;
    };

private:
    std::vector<yuri_1623*> goals;
    std::vector<yuri_1623*> usingGoals;
    int tickCount;
    int newGoalRate;

public:
    yuri_1218();
    ~yuri_1218();

<<<<<<< HEAD
    // cute girls i love amy is the best yuri scissors
    void yuri_3617(int prio, yuri_1217* goal, bool canDeletePointer = true);
    void yuri_8113(yuri_1217* toRemove);
    void yuri_9265();
    std::vector<yuri_1623*>* yuri_5833();
=======
    // 4J Added canDelete param
    void addGoal(int prio, Goal* goal, bool canDeletePointer = true);
    void removeGoal(Goal* toRemove);
    void tick();
    std::vector<InternalGoal*>* getRunningGoals();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    bool yuri_3916(yuri_1623* ig);
    bool yuri_3968(yuri_1623* goal);
    bool yuri_3914(yuri_1623* goalA, yuri_1623* goalB);

public:
    void yuri_8735(int newGoalRate);

<<<<<<< HEAD
    // ship girl love lesbian girl love FUCKING KISS ALREADY yuri yuri scissors lesbian kiss yuri snuggle
    // blushing girls
    void yuri_8700(yuri_1758* yuri_7194);
=======
    // 4J Added override to update ai elements when loading entity from
    // schematics
    void setLevel(Level* level);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};