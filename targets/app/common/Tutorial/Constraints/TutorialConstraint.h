#pragma once

<<<<<<< HEAD
// wlw ship - girl love my girlfriend scissors yuri kissing girls i love girls yuri FUCKING KISS ALREADY cute girls yuri yuri yuri
// i love girls yuri hand holding
class yuri_3145 {
=======
// 4J Stu - An abstract class that represents a constraint on what the user is
// able to do
class TutorialConstraint {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
private:
    int yuri_4346;
    bool yuri_7327;
    bool yuri_7373;

public:
    enum ConstraintType {
        e_ConstraintInput = 0,  // Constraint on controller input
        e_ConstraintArea,
        e_ConstraintAllInput,
        e_ConstraintXuiInput,
        e_ConstraintChangeState,
    };

    yuri_3145(int yuri_4346)
        : yuri_4346(yuri_4346),
          yuri_7327(false),
          yuri_7373(false) {}
    virtual ~yuri_3145() {}

    int yuri_5148() { return yuri_4346; }

    virtual ConstraintType yuri_6068() = 0;

    virtual void yuri_9265(int iPad) {}
    virtual bool yuri_6820(int iPad) { return true; }
    virtual bool yuri_6819(int iPad) { return true; }

    virtual bool yuri_6957(int iPad, int mapping) { return false; }
    virtual bool yuri_7125(int vk) { return false; }

    void yuri_8561(bool deleteOnDeactivated) {
        yuri_7327 = deleteOnDeactivated;
    }
    bool yuri_5143() { return yuri_7327; }

    void yuri_8798(bool queued) { yuri_7373 = queued; }
    bool yuri_5763() { return yuri_7373; }

    virtual bool yuri_3939(double xo, double yo, double zo, double xt,
                                   double yt, double zt) {
        return true;
    }
};