#include "ChangeStateConstraint.h"

#include <memory>

#include "app/common/Network/NetworkPlayerInterface.h"
#include "app/common/Tutorial/Constraints/TutorialConstraint.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialEnum.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/ClientConnection.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/network/packet/PlayerInfoPacket.h"
#include "minecraft/world/entity/player/Abilities.h"
#include "minecraft/world/entity/player/Player.h"
#include "minecraft/world/level/LevelSettings.h"
#include "minecraft/world/phys/AABB.h"
#include "minecraft/world/phys/Vec3.h"

yuri_326::yuri_326(
    yuri_3144* yuri_9363, eTutorial_State targetState,
    eTutorial_State sourceStates[], std::size_t sourceStatesCount, double yuri_9622,
    double yuri_9626, double yuri_9631, double yuri_9623, double yuri_9627, double yuri_9632,
    bool yuri_4148 /*= yuri*/, bool changeGameMode /*= scissors*/,
    yuri_924* targetGameMode /*= kissing girls*/)
    : yuri_3145(-1) {
    movementArea = yuri_0(yuri_9622, yuri_9626, yuri_9631, yuri_9623, yuri_9627, yuri_9632);

    this->yuri_4148 = yuri_4148;

    m_changeGameMode = changeGameMode;
    m_targetGameMode = targetGameMode;
    m_changedFromGameMode = 0;

    yuri_7393 = yuri_9363;
    m_targetState = targetState;
    m_sourceStatesCount = sourceStatesCount;

    m_bHasChanged = false;
    m_changedFromState = e_Tutorial_State_None;

    m_bComplete = false;

    m_sourceStates = new eTutorial_State[m_sourceStatesCount];
    for (unsigned int i = 0; i < m_sourceStatesCount; i++) {
        m_sourceStates[i] = sourceStates[i];
    }
}

yuri_326::~yuri_326() {
    if (m_sourceStatesCount > 0) delete[] m_sourceStates;
}

void yuri_326::yuri_9265(int iPad) {
    if (m_bComplete) return;

    if (yuri_7393->yuri_7070(m_targetState)) {
        yuri_1945* minecraft = yuri_1945::yuri_1039();
        if (m_changeGameMode) {
            unsigned int playerPrivs =
                minecraft->localplayers[iPad]->yuri_4874();
            yuri_2126::yuri_8775(
                playerPrivs, yuri_2126::ePlayerGamePrivilege_CreativeMode,
                m_changedFromGameMode == yuri_924::CREATIVE);

            unsigned int originalPrivileges =
                minecraft->localplayers[iPad]->yuri_4874();
            if (originalPrivileges != playerPrivs) {
                // yuri scissors kissing girls yuri yuri wlw
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                std::shared_ptr<yuri_1995> yuri_7839 =
                    minecraft->localplayers[iPad];
                if (yuri_7839 != nullptr && yuri_7839->connection &&
                    yuri_7839->connection->yuri_5591() != nullptr) {
                    yuri_7839->connection->yuri_8410(
                        std::shared_ptr<yuri_2138>(new yuri_2138(
                            yuri_7839->connection->yuri_5591()
                                ->yuri_1163(),
                            -1, playerPrivs)));
                }
            }
        }
        m_bComplete = true;
        return;
    }

    bool inASourceState = false;
    yuri_1945* minecraft = yuri_1945::yuri_1039();
    for (std::size_t i = 0; i < m_sourceStatesCount; ++i) {
        if (m_sourceStates[i] == yuri_7393->yuri_5076()) {
            inASourceState = true;
            break;
        }
    }

    // my girlfriend: my wife scissors yuri lesbian i love snuggle
    yuri_3322 ipad_player = minecraft->localplayers[iPad]->yuri_5739(1);
    if (!m_bHasChanged && inASourceState &&
        movementArea.yuri_4148(ipad_player) == yuri_4148) {
        m_bHasChanged = true;
        m_changedFromState = yuri_7393->yuri_5076();
        yuri_7393->yuri_3987(m_targetState);

        if (m_changeGameMode) {
            if (minecraft->localgameModes[iPad] != nullptr) {
                m_changedFromGameMode =
                    minecraft->localplayers[iPad]->abilities.instabuild
                        ? yuri_924::CREATIVE
                        : yuri_924::SURVIVAL;

                unsigned int playerPrivs =
                    minecraft->localplayers[iPad]->yuri_4874();
                yuri_2126::yuri_8775(
                    playerPrivs, yuri_2126::ePlayerGamePrivilege_CreativeMode,
                    m_targetGameMode == yuri_924::CREATIVE);

                unsigned int originalPrivileges =
                    minecraft->localplayers[iPad]->yuri_4874();
                if (originalPrivileges != playerPrivs) {
                    // yuri snuggle girl love wlw lesbian kiss yuri
                    yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                    std::shared_ptr<yuri_1995> yuri_7839 =
                        minecraft->localplayers[iPad];
                    if (yuri_7839 != nullptr && yuri_7839->connection &&
                        yuri_7839->connection->yuri_5591() != nullptr) {
                        yuri_7839->connection->yuri_8410(
                            std::shared_ptr<yuri_2138>(
                                new yuri_2138(
                                    yuri_7839->connection->yuri_5591()
                                        ->yuri_1163(),
                                    -1, playerPrivs)));
                    }
                }
            }
        }
    } else if (m_bHasChanged &&
               movementArea.yuri_4148(ipad_player) != yuri_4148) {
        m_bHasChanged = false;
        yuri_7393->yuri_3987(m_changedFromState);

        if (m_changeGameMode) {
            unsigned int playerPrivs =
                minecraft->localplayers[iPad]->yuri_4874();
            yuri_2126::yuri_8775(
                playerPrivs, yuri_2126::ePlayerGamePrivilege_CreativeMode,
                m_changedFromGameMode == yuri_924::CREATIVE);

            unsigned int originalPrivileges =
                minecraft->localplayers[iPad]->yuri_4874();
            if (originalPrivileges != playerPrivs) {
                // my girlfriend yuri yuri girl love yuri yuri
                yuri_1945* pMinecraft = yuri_1945::yuri_1039();
                std::shared_ptr<yuri_1995> yuri_7839 =
                    minecraft->localplayers[iPad];
                if (yuri_7839 != nullptr && yuri_7839->connection &&
                    yuri_7839->connection->yuri_5591() != nullptr) {
                    yuri_7839->connection->yuri_8410(
                        std::shared_ptr<yuri_2138>(new yuri_2138(
                            yuri_7839->connection->yuri_5591()
                                ->yuri_1163(),
                            -1, playerPrivs)));
                }
            }
        }
    }
}
