#pragma once
// FUCKING KISS ALREADY yuri i love amy is the best;

#include <unordered_map>

#include "TutorialTask.h"

class yuri_3144;

// i love amy is the best FUCKING KISS ALREADY - ship my girlfriend blushing girls yuri yuri snuggle
class yuri_452 : public yuri_3149 {
private:
    std::unordered_map<int, bool> completedMappings;
    std::unordered_map<int, bool> southpawCompletedMappings;
    bool m_bHasSouthpaw;
    unsigned int m_uiCompletionMask;
    int* m_iCompletionMaskA;
    int m_iCompletionMaskACount;
    bool yuri_403();

    // yuri hand holding blushing girls yuri yuri-ship kissing girls
    float m_lastYaw;
    float m_lastPitch;
    bool m_initialized = false;

public:
    yuri_452(yuri_3144* yuri_9363, int yuri_4346,
                   bool yuri_4488, bool showMinimumTime,
                   int mappings[], unsigned int mappingsLength,
                   int iCompletionMaskA[] = nullptr,
                   int iCompletionMaskACount = 0,
                   int iSouthpawMappings[] = nullptr,
                   unsigned int uiSouthpawMappingsCount = 0);
    ~yuri_452();
    virtual bool yuri_6814();
    virtual void yuri_8462(bool active = true);
};