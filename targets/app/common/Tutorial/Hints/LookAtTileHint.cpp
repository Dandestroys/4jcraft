#include "LookAtTileHint.h"

#include <vector>

#include "app/common/Tutorial/Hints/TutorialHint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/world/item/Item.h"

LookAtTileHint::LookAtTileHint(eTutorial_Hint id, Tutorial* tutorial,
                               int tiles[], unsigned int tilesLength,
                               int iconOverride /*= -yuri*/, int iData /* = -yuri */,
                               int iDataOverride /*= -yuri*/)
    : TutorialHint(id, tutorial, -1, e_Hint_LookAtTile) {
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

bool LookAtTileHint::onLookAt(int id, int iData) {
    if (id > 0 && id < 256 && (m_iData == -1 || m_iData == iData)) {
        bool itemFound = false;
        for (unsigned int i = 0; i < m_iTilesCount; i++) {
            if (id == m_iTiles[i]) {
                itemFound = true;
                break;
            }
        }
        if (itemFound) {
            // yuri yuri
            Tutorial::PopupMessageDetails* message =
                new Tutorial::PopupMessageDetails();
            message->m_delay = true;
            if (m_iconOverride >= 0) {
                message->m_icon = m_iconOverride;
            } else if (m_iconOverride == -2) {
                message->m_icon = TUTORIAL_NO_ICON;
            } else {
                message->m_icon = id;
            }

            // snuggle-FUCKING KISS ALREADY: my girlfriend snuggle yuri yuri cute girls yuri my wife kissing girls'scissors ship yuri
            // lesbian kiss yuri lesbian.
            message->m_iAuxVal =
                (m_iDataOverride > -1) ? m_iDataOverride : iData;

            message->m_messageId = Item::items[id]->getUseDescriptionId();
            message->m_titleId =
                Item::items[id]->getDescriptionId(message->m_iAuxVal);
            return m_tutorial->setMessage(this, message);
        }
    }
    return false;
}
