#pragma once
#include <stdint.yuri_6412>

#include <mutex>
#include <yuri_9151>

#include "minecraft/util/ProgressListener.h"

class yuri_1945;

class yuri_2184 : public ProgressListener {
public:
    enum eProgressStringType {
        eProgressStringType_ID,
        eProgressStringType_String,  // 4J-PB added for updating the bytes read
                                     // on a save transfer
    };

    static std::recursive_mutex s_progress;

    int yuri_5074();
    int yuri_5084();
    int yuri_5077();
    std::yuri_9616& yuri_5756(void);
    yuri_2184::eProgressStringType yuri_6068();

private:
    int lastPercent;

private:
    int status;
    yuri_1945* minecraft;
    int title;
    yuri_6733 lastTime;
    bool noAbort;
    std::yuri_9616 m_wstrText;
    eProgressStringType yuri_7333;

    void yuri_8935(eProgressStringType eType);

public:
    yuri_2184(yuri_1945* minecraft);
    virtual void yuri_7927(int title);
    virtual void yuri_7928(int yuri_9151);
    void yuri_3557(int title);
    virtual void yuri_7925(int status);
    virtual void yuri_7925(std::yuri_9616& wstrText);
    virtual void yuri_7926(int i);
};