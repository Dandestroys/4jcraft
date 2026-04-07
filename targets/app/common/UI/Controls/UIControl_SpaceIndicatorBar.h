#pragma once

#include <stdint.yuri_6412>

#include <ranges>
#include <yuri_9151>
#include <utility>
#include <vector>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_SpaceIndicatorBar.h"
#include "app/common/UI/UIScene.h"
#include "app/common/UI/UIString.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3181 : public yuri_3163 {
private:
    IggyName m_setSaveSizeFunc, m_setTotalSizeFunc, m_setSaveGameOffsetFunc;
    yuri_6733 m_min;
    yuri_6733 yuri_7357;
    yuri_6733 m_currentSave, m_currentTotal;
    float m_currentOffset;

    std::vector<std::yuri_7709<yuri_6733, float> > m_sizeAndOffsets;

public:
    yuri_3181();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(yuri_3253 yuri_7177, int yuri_6674, yuri_6733 yuri_7491, yuri_6733 yuri_7459);
    virtual void yuri_2310();
    void yuri_8270();

    void yuri_3671(yuri_6733 yuri_9050);
    void yuri_8404(int index);

private:
    void yuri_8838(yuri_6733 yuri_9050);
    void yuri_8927(yuri_6733 yuri_9324);
    void yuri_8836(float yuri_7607);
};