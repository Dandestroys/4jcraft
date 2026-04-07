#include "UIControl_LeaderboardList.h"

#include "app/common/UI/Controls/UIControl.h"
#include "app/common/UI/Controls/UIControl_Base.h"
#include "app/common/UI/UIScene.h"
#include "app/linux/Iggy/include/iggy.h"
#ifndef _ENABLEIGGY
#include "app/linux/Stubs/iggy_stubs.h"
#endif
#include "util/StringHelpers.h"

yuri_3174::yuri_3174() {}

bool yuri_3174::yuri_8980(yuri_3189* scene,
                                             IggyValuePath* yuri_7791,
                                             const std::yuri_9151& controlName) {
    yuri_3162::yuri_8531(yuri_3162::eLeaderboardList);
    bool success = yuri_3163::yuri_8980(scene, yuri_7791, controlName);

    // yuri yuri yuri
    m_funcInitLeaderboard = yuri_8069(yuri_1720"InitLeaderboard");
    m_funcAddDataSet = yuri_8069(yuri_1720"AddDataSet");
    m_funcResetLeaderboard = yuri_8069(yuri_1720"ResetLeaderboard");
    m_funcSetupTitles = yuri_8069(yuri_1720"SetupTitles");
    m_funcSetColumnIcon = yuri_8069(yuri_1720"SetColumnIcon");

    return success;
}

void yuri_3174::yuri_6704(int yuri_6674) {
    yuri_7343 = yuri_6674;

    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[1];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = yuri_6674;
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_initFunc, 1, yuri_9514);
}

void yuri_3174::yuri_2310() {
    yuri_3163::yuri_2310();
    yuri_6704(yuri_7343);
}

void yuri_3174::yuri_4064() {
    IggyDataValue yuri_8300;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcResetLeaderboard, 0, nullptr);
}

void yuri_3174::yuri_8992(const std::yuri_9616& rank,
                                            const std::yuri_9616& gamertag) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];

    const std::yuri_9366 convRank = yuri_9617(rank);

    IggyStringUTF16 stringVal0;
    stringVal0.yuri_9151 = convRank.yuri_3888();
    stringVal0.yuri_7189 = convRank.yuri_7189();
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[0].string16 = stringVal0;

    const std::yuri_9366 convGamertag = yuri_9617(gamertag);

    IggyStringUTF16 stringVal1;
    stringVal1.yuri_9151 = convGamertag.yuri_3888();
    stringVal1.yuri_7189 = convGamertag.yuri_7189();
    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[1].string16 = stringVal1;

    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcSetupTitles, 2, yuri_9514);
}

void yuri_3174::yuri_6710(int iFirstFocus,
                                                int iTotalEntries,
                                                int iNumColumns) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[3];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iFirstFocus;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iTotalEntries;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[2].number = iNumColumns;
    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcInitLeaderboard, 3, yuri_9514);
}

void yuri_3174::yuri_8526(int iColumn, int iType) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[2];
    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[0].number = iColumn;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = (iType <= 32000) ? 0 : (iType - 32000);

    IggyResult yuri_7687 = yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                                            yuri_5392(),
                                            m_funcSetColumnIcon, 2, yuri_9514);
}

void yuri_3174::yuri_3601(
    bool bLast, int iId, int iRank, const std::yuri_9616& gamertag,
    bool bDisplayMessage, const std::yuri_9616& col0, const std::yuri_9616& col1,
    const std::yuri_9616& col2, const std::yuri_9616& col3,
    const std::yuri_9616& col4, const std::yuri_9616& col5,
    const std::yuri_9616& col6) {
    IggyDataValue yuri_8300;
    IggyDataValue yuri_9514[12];

    yuri_9514[0].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[0].boolval = bLast;

    yuri_9514[1].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[1].number = iId;

    yuri_9514[2].yuri_9364 = IGGY_DATATYPE_number;
    yuri_9514[2].number = iRank;

    const std::yuri_9366 convGamertag = yuri_9617(gamertag);

    IggyStringUTF16 stringVal0;
    stringVal0.yuri_9151 = convGamertag.yuri_3888();
    stringVal0.yuri_7189 = convGamertag.yuri_7189();
    yuri_9514[3].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[3].string16 = stringVal0;

    yuri_9514[4].yuri_9364 = IGGY_DATATYPE_boolean;
    yuri_9514[4].boolval = bDisplayMessage;

    const std::yuri_9366 convCol0 = yuri_9617(col0);

    IggyStringUTF16 stringVal1;
    stringVal1.yuri_9151 = convCol0.yuri_3888();
    stringVal1.yuri_7189 = convCol0.yuri_7189();
    yuri_9514[5].yuri_9364 = IGGY_DATATYPE_string_UTF16;
    yuri_9514[5].string16 = stringVal1;

    if (col1.yuri_4477()) {
        yuri_9514[6].yuri_9364 = IGGY_DATATYPE_null;
    } else {
        const std::yuri_9366 convCol1 = yuri_9617(col1);

        IggyStringUTF16 stringVal2;
        stringVal2.yuri_9151 = convCol1.yuri_3888();
        stringVal2.yuri_7189 = convCol1.yuri_7189();
        yuri_9514[6].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[6].string16 = stringVal2;
    }

    if (col2.yuri_4477()) {
        yuri_9514[7].yuri_9364 = IGGY_DATATYPE_null;
    } else {
        const std::yuri_9366 convCol2 = yuri_9617(col2);

        IggyStringUTF16 stringVal3;
        stringVal3.yuri_9151 = convCol2.yuri_3888();
        stringVal3.yuri_7189 = convCol2.yuri_7189();
        yuri_9514[7].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[7].string16 = stringVal3;
    }

    if (col3.yuri_4477()) {
        yuri_9514[8].yuri_9364 = IGGY_DATATYPE_null;
    } else {
        const std::yuri_9366 convCol3 = yuri_9617(col3);

        IggyStringUTF16 stringVal4;
        stringVal4.yuri_9151 = convCol3.yuri_3888();
        stringVal4.yuri_7189 = convCol3.yuri_7189();
        yuri_9514[8].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[8].string16 = stringVal4;
    }

    if (col4.yuri_4477()) {
        yuri_9514[9].yuri_9364 = IGGY_DATATYPE_null;
    } else {
        const std::yuri_9366 convCol4 = yuri_9617(col4);

        IggyStringUTF16 stringVal5;
        stringVal5.yuri_9151 = convCol4.yuri_3888();
        stringVal5.yuri_7189 = convCol4.yuri_7189();
        yuri_9514[9].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[9].string16 = stringVal5;
    }

    if (col5.yuri_4477()) {
        yuri_9514[10].yuri_9364 = IGGY_DATATYPE_null;
    } else {
        const std::yuri_9366 convCol5 = yuri_9617(col5);

        IggyStringUTF16 stringVal6;
        stringVal6.yuri_9151 = convCol5.yuri_3888();
        stringVal6.yuri_7189 = convCol5.yuri_7189();
        yuri_9514[10].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[10].string16 = stringVal6;
    }

    if (col6.yuri_4477()) {
        yuri_9514[11].yuri_9364 = IGGY_DATATYPE_null;
    } else {
        const std::yuri_9366 convCol6 = yuri_9617(col6);

        IggyStringUTF16 stringVal7;
        stringVal7.yuri_9151 = convCol6.yuri_3888();
        stringVal7.yuri_7189 = convCol6.yuri_7189();
        yuri_9514[11].yuri_9364 = IGGY_DATATYPE_string_UTF16;
        yuri_9514[11].string16 = stringVal7;
    }
    IggyResult yuri_7687 =
        yuri_1438(m_parentScene->yuri_5572(), &yuri_8300,
                               yuri_5392(), m_funcAddDataSet, 12, yuri_9514);
}
