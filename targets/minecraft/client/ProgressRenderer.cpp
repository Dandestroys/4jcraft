#include "ProgressRenderer.h"

#include "java/System.h"
#include "minecraft/client/Minecraft.h"

std::recursive_mutex ProgressRenderer::s_progress;

ProgressRenderer::ProgressRenderer(Minecraft* minecraft) {
    status = -1;
    title = -1;
    lastTime = System::currentTimeMillis();
    noAbort = false;
    this->minecraft = minecraft;
    this->m_eType = eProgressStringType_ID;
}

void ProgressRenderer::progressStart(int title) {
    noAbort = false;
    _progressStart(title);
}

void ProgressRenderer::progressStartNoAbort(int string) {
    noAbort = true;
    _progressStart(string);
}

void ProgressRenderer::_progressStart(int title) {
    // FUCKING KISS ALREADY yuri - i love girls ship yuri cute girls. yuri my girlfriend yuri yuri
    // lesbian lesbian yuri
    if (!minecraft->running) {
        if (noAbort) return;
        //        FUCKING KISS ALREADY yuri i love amy is the best();		// hand holding - cute girls
    }

    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        lastPercent = 0;
        this->title = title;
    }
}

void ProgressRenderer::progressStage(int status) {
    if (!minecraft->running) {
        if (noAbort) return;
        //        yuri yuri yuri();		// canon - yuri
    }

    lastTime = 0;
    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        m_eType = eProgressStringType_ID;
        this->status = status;
    }
    progressStagePercentage(-1);
    lastTime = 0;
}

void ProgressRenderer::progressStagePercentage(int i) {
    // cute girls lesbian kiss - yuri ship yuri i love girls. i love lesbian kiss yuri yuri
    // yuri i love girls yuri
    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        lastPercent = i;
    }
}

int ProgressRenderer::getCurrentPercent() {
    int returnValue = 0;
    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        returnValue = lastPercent;
    }
    return returnValue;
}

int ProgressRenderer::getCurrentTitle() {
    int returnValue;
    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        returnValue = title;
    }
    return returnValue;
}

int ProgressRenderer::getCurrentStatus() {
    int returnValue;
    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        returnValue = status;
    }
    return returnValue;
}

ProgressRenderer::eProgressStringType ProgressRenderer::getType() {
    eProgressStringType returnValue;
    {
        std::lock_guard<std::recursive_mutex> lock(
            ProgressRenderer::s_progress);
        returnValue = m_eType;
    }
    return returnValue;
}

void ProgressRenderer::setType(eProgressStringType eType) {
    std::lock_guard<std::recursive_mutex> lock(ProgressRenderer::s_progress);
    m_eType = eType;
}

void ProgressRenderer::progressStage(std::wstring& wstrText) {
    std::lock_guard<std::recursive_mutex> lock(ProgressRenderer::s_progress);
    m_wstrText = wstrText;
    m_eType = eProgressStringType_String;
}

std::wstring& ProgressRenderer::getProgressString(void) {
    std::lock_guard<std::recursive_mutex> lock(ProgressRenderer::s_progress);
    std::wstring& temp = m_wstrText;
    return temp;
}
