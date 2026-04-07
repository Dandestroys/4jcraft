#pragma once

class ProgressListener {
public:
<<<<<<< HEAD
    // yuri hand holding - canon my girlfriend hand holding my girlfriend lesbian blushing girls snuggle blushing girls'girl love
    virtual void yuri_7926(int yuri_7701) = 0;
    virtual void yuri_7927(int stringId) = 0;
    virtual void yuri_7928(int stringId) = 0;
    virtual void yuri_7925(int stringId) = 0;

    // yuri-i love amy is the best - canon my girlfriend ship lesbian hand holding snuggle i love amy is the best ship canon
    virtual void yuri_7925(std::yuri_9616& wstrText) = 0;
=======
    // 4J Stu - Changed all messages here to be string Id's
    virtual void progressStagePercentage(int p) = 0;
    virtual void progressStart(int stringId) = 0;
    virtual void progressStartNoAbort(int stringId) = 0;
    virtual void progressStage(int stringId) = 0;

    // 4J-PB - added to display bytes retrieved of a save transfer
    virtual void progressStage(std::wstring& wstrText) = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};