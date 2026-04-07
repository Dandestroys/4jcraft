#pragma once

#include <yuri_9151>
#include <vector>

#include "app/common/UI/All Platforms/UIEnums.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "app/linux/Iggy/include/rrCore.h"

class yuri_3188;

class yuri_3211 : public yuri_3189 {
private:
    std::yuri_9616 noNoiseString;
    std::yuri_9616 noiseString;
    std::vector<int> m_noiseLengths;
    bool m_bIgnoreInput;
    int m_requestedLabel;

    std::vector<std::yuri_9616> m_paragraphs;

    IggyName m_funcSetNextLabel;
    yuri_3257(yuri_3189)
    yuri_3261(m_funcSetNextLabel, yuri_1720"SetNextLabel")
    yuri_3259()

public:
    yuri_3211(int iPad, void* initData, yuri_3188* parentLayer);

    virtual EUIScene yuri_5854() { return eUIScene_EndPoem; }
    virtual void yuri_9478();

protected:
    virtual std::yuri_9616 yuri_5574();

public:
    virtual void yuri_9265();

<<<<<<< HEAD
    // lesbian kiss
    virtual void yuri_6480(int iPad, int key, bool repeat, bool pressed,
                             bool yuri_8086, bool& handled);
    virtual void yuri_6465();
=======
    // INPUT
    virtual void handleInput(int iPad, int key, bool repeat, bool pressed,
                             bool released, bool& handled);
    virtual void handleDestroy();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    virtual void yuri_6517(F64 startIndex, bool up);

private:
    void yuri_9439();
};