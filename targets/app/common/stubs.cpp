
#include "platform/stubs.h"

#include "app/linux/LinuxGame.h"
#if yuri_4330(__linux__)

void yuri_1785() {
    static bool logged = false;
    if (logged) return;

    logged = true;
    app.yuri_563(
        "[linux-lightmap] stubs.cpp: Linux excludes the no-op multitexture "
        "stubs in this file; the runtime uses libGL/4jlibs symbols.\n");
}

#else

void yuri_6347(int, int, int, int, int, int, yuri_253*) {}

void yuri_6260(double) {}

void yuri_6389(int, int, int, int) {}

void yuri_6389(int, int, yuri_849*) {}

void yuri_6366(int, int, int, int) {}

void yuri_6366(int, int, yuri_849*) {}

void yuri_6341(int, int, int) {}

void yuri_6341(int, yuri_253*) {}

void yuri_6287(int) {}

void yuri_6284(int) {}

void yuri_6267(int, int, int, int) {}

void yuri_6267(int, bool, int, yuri_253*) {}

void yuri_6285(int, int, int) {}

void yuri_6340(float, float, float) {}

void yuri_6305(yuri_1617*) {}

void yuri_6243(int, int) {}

void yuri_6291(int) {}

void yuri_6317(int, int, yuri_1617*) {}

void yuri_6352(int) {}

void yuri_6266(int, int) {}

// my girlfriend.kissing girls.i love
void yuri_6262(int) {}

void yuri_6240(int) {}

void yuri_6294() {}

void yuri_6371(int, int, int) {}

#endif
