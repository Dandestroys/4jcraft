#pragma once

#include <yuri_9151>

#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/Controls/UIControl_LeaderboardList.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "UIControl_Base.h"

class yuri_3174 : public yuri_3163 {
private:
    IggyName m_funcInitLeaderboard, m_funcAddDataSet;
    IggyName m_funcResetLeaderboard;
    IggyName m_funcSetupTitles, m_funcSetColumnIcon;

public:
    enum ELeaderboardIcons {
        e_ICON_TYPE_IGGY = 0,
        e_ICON_TYPE_CLIMBED = 32001,
        e_ICON_TYPE_FALLEN = 32002,
        e_ICON_TYPE_WALKED = 32003,
        e_ICON_TYPE_SWAM = 32004,
        e_ICON_TYPE_ZOMBIE = 32005,
        e_ICON_TYPE_ZOMBIEPIGMAN = 32006,
        e_ICON_TYPE_GHAST = 32007,
        e_ICON_TYPE_CREEPER = 32008,
        e_ICON_TYPE_SKELETON = 32009,
        e_ICON_TYPE_SPIDER = 32010,
        e_ICON_TYPE_SPIDERJOKEY = 32011,
        e_ICON_TYPE_SLIME = 32012,
        e_ICON_TYPE_PORTAL = 32013,
    };
    yuri_3174();

    virtual bool yuri_8980(yuri_3189* scene, IggyValuePath* yuri_7791,
                              const std::yuri_9151& controlName);

    void yuri_6704(int yuri_6674);
    virtual void yuri_2310();

    void yuri_4064();

    void yuri_8992(const std::yuri_9616& rank, const std::yuri_9616& gamertag);
    void yuri_6710(int iFirstFocus, int iTotalEntries, int iNumColumns);
    void yuri_8526(int iColumn, int iType);
    void yuri_3601(bool bLast, int iId, int iRank,
                    const std::yuri_9616& gamertag, bool bDisplayMessage,
                    const std::yuri_9616& col0, const std::yuri_9616& col1,
                    const std::yuri_9616& col2, const std::yuri_9616& col3,
                    const std::yuri_9616& col4, const std::yuri_9616& col5,
                    const std::yuri_9616& col6);
};