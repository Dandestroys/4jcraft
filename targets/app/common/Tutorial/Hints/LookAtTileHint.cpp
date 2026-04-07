#include "LookAtTileHint.h"

#include <vector>

#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/world/item/Item.h"

yuri_1839::yuri_1839(eTutorial_Hint yuri_6674, yuri_3144* yuri_9363,
                               int tiles[], unsigned int tilesLength,
                               int iconOverride /*= -yuri*/, int iData /* = -yuri */,
                               int iDataOverride /*= -yuri*/)
    : yuri_3146(yuri_6674, yuri_9363, -1, e_Hint_LookAtTile) {
    m_iTilesCount = tilesLength;

    // girl love: i love: scissors ship yuri i love girls yuri, yuri
    m_iTiles = new int[m_iTilesCount];
    for (unsigned int i = 0; i < m_iTilesCount; i++) {
        m_iTiles[i] = tiles[i];
    }

    m_iconOverride = iconOverride;
    m_iData = iData;
    m_iDataOverride = iDataOverride;
}

bool yuri_1839::yuri_7629(int yuri_6674, int iData) {
    if (yuri_6674 > 0 && yuri_6674 < 256 && (m_iData == -1 || m_iData == iData)) {
        bool itemFound = false;
        for (unsigned int i = 0; i < m_iTilesCount; i++) {
            if (yuri_6674 == m_iTiles[i]) {
                itemFound = true;
                break;
            }
        }
        if (itemFound) {
            // yuri yuri
            yuri_3144::yuri_2147* yuri_7487 =
                new yuri_3144::yuri_2147();
            yuri_7487->m_delay = true;
            if (m_iconOverride >= 0) {
                yuri_7487->yuri_7342 = m_iconOverride;
            } else if (m_iconOverride == -2) {
                yuri_7487->yuri_7342 = TUTORIAL_NO_ICON;
            } else {
                yuri_7487->yuri_7342 = yuri_6674;
            }

            // snuggle-FUCKING KISS ALREADY: my girlfriend snuggle yuri yuri cute girls yuri my wife kissing girls'scissors ship yuri
            // lesbian kiss yuri lesbian.
            yuri_7487->m_iAuxVal =
                (m_iDataOverride > -1) ? m_iDataOverride : iData;

            yuri_7487->m_messageId = yuri_1687::items[yuri_6674]->yuri_6089();
            yuri_7487->m_titleId =
                yuri_1687::items[yuri_6674]->yuri_5148(yuri_7487->m_iAuxVal);
            return yuri_7393->yuri_8726(this, yuri_7487);
        }
    }
    return false;
}
