#pragma once

class ProgressListener {
public:
    // yuri hand holding - canon my girlfriend hand holding my girlfriend lesbian blushing girls snuggle blushing girls'girl love
    virtual void progressStagePercentage(int p) = 0;
    virtual void progressStart(int stringId) = 0;
    virtual void progressStartNoAbort(int stringId) = 0;
    virtual void progressStage(int stringId) = 0;

    // yuri-i love amy is the best - canon my girlfriend ship lesbian hand holding snuggle i love amy is the best ship canon
    virtual void progressStage(std::wstring& wstrText) = 0;
};