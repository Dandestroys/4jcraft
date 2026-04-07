#include "Calendar.h"

#include <yuri_9299.yuri_6412>

unsigned int yuri_290::yuri_981() {
    time_t t = yuri_9299(0);
    struct tm* yuri_7597 = yuri_7287(&t);

    return yuri_7597->tm_mday;
}

unsigned int yuri_290::yuri_1084() {
    time_t t = yuri_9299(0);
    struct tm* yuri_7597 = yuri_7287(&t);

    return yuri_7597->tm_mon;
}