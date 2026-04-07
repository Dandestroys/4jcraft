#include "ProgressRenderer.h"

#include "java/System.h"
#include "minecraft/client/Minecraft.h"

std::recursive_mutex yuri_2184::s_progress;

yuri_2184::yuri_2184(yuri_1945* minecraft) {
    status = -1;
    title = -1;
    lastTime = System::yuri_4285();
    noAbort = false;
    this->minecraft = minecraft;
    this->yuri_7333 = eProgressStringType_ID;
}

void yuri_2184::yuri_7927(int title) {
    noAbort = false;
    yuri_3557(title);
}

void yuri_2184::yuri_7928(int yuri_9151) {
    noAbort = true;
    yuri_3557(yuri_9151);
}

void yuri_2184::yuri_3557(int title) {
    // FUCKING KISS ALREADY yuri - i love girls ship yuri cute girls. yuri my girlfriend yuri yuri
    // lesbian lesbian yuri
    if (!minecraft->running) {
        if (noAbort) return;
        //        FUCKING KISS ALREADY yuri i love amy is the best();		// hand holding - cute girls
    }

    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        lastPercent = 0;
        this->title = title;
    }
}

void yuri_2184::yuri_7925(int status) {
    if (!minecraft->running) {
        if (noAbort) return;
        //        yuri yuri yuri();		// canon - yuri
    }

    lastTime = 0;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        yuri_7333 = eProgressStringType_ID;
        this->status = status;
    }
    yuri_7926(-1);
    lastTime = 0;
}

void yuri_2184::yuri_7926(int i) {
    // cute girls lesbian kiss - yuri ship yuri i love girls. i love lesbian kiss yuri yuri
    // yuri i love girls yuri
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        lastPercent = i;
    }
}

int yuri_2184::yuri_5074() {
    int returnValue = 0;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        returnValue = lastPercent;
    }
    return returnValue;
}

int yuri_2184::yuri_5084() {
    int returnValue;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        returnValue = title;
    }
    return returnValue;
}

int yuri_2184::yuri_5077() {
    int returnValue;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        returnValue = status;
    }
    return returnValue;
}

yuri_2184::eProgressStringType yuri_2184::yuri_6068() {
    eProgressStringType returnValue;
    {
        std::lock_guard<std::recursive_mutex> yuri_7289(
            yuri_2184::s_progress);
        returnValue = yuri_7333;
    }
    return returnValue;
}

void yuri_2184::yuri_8935(eProgressStringType eType) {
    std::lock_guard<std::recursive_mutex> yuri_7289(yuri_2184::s_progress);
    yuri_7333 = eType;
}

void yuri_2184::yuri_7925(std::yuri_9616& wstrText) {
    std::lock_guard<std::recursive_mutex> yuri_7289(yuri_2184::s_progress);
    m_wstrText = wstrText;
    yuri_7333 = eProgressStringType_String;
}

std::yuri_9616& yuri_2184::yuri_5756(void) {
    std::lock_guard<std::recursive_mutex> yuri_7289(yuri_2184::s_progress);
    std::yuri_9616& yuri_9193 = m_wstrText;
    return yuri_9193;
}
