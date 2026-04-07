#pragma once

class yuri_409;

class yuri_44 {
public:
    bool invulnerable;
    bool flying;
    bool mayfly;
    bool instabuild;
    bool yuri_7462;

private:
    float flyingSpeed;
    float walkingSpeed;

public:
#ifdef _DEBUG_MENUS_ENABLED
    bool debugflying;
#endif

    yuri_44();

    void yuri_3672(yuri_409* parentTag);
    void yuri_7264(yuri_409* parentTag);

    float yuri_5261();
    void yuri_8610(float yuri_9514);
    float yuri_6121();
    void yuri_8951(float yuri_9514);
};