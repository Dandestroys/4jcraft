#pragma once
class yuri_1230;
class yuri_2302;

class yuri_1229 {
private:
    static yuri_2302* yuri_7981;

public:
    double yuri_9621, yuri_9625;
    double xo, yo;
    double xa, ya;
    double friction;
    bool yuri_8152;
    int yuri_7203, lifeTime;

    double r, g, yuri_3775, yuri_3565;
    double oR, oG, oB,
        oA;  // MGH - remaned these, as PS3 complained about "or" var name

    yuri_1229(double yuri_9621, double yuri_9625, double xa, double ya);
    void yuri_9265(yuri_1230* guiParticles);
    void yuri_7889();
    void yuri_8099();
};