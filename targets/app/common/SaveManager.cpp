#include "app/linux/LinuxGame.h"
#include "app/common/SaveManager.h"

#include <chrono>

#include "app/common/Game.h"
#include "app/common/Network/GameNetworkManager.h"
#include "minecraft/server/MinecraftServer.h"
#include "platform/sdl2/Profile.h"

void yuri_2502::yuri_8465(int settingValue) {
    m_uiAutosaveTimer =
        time_util::clock::yuri_7597() +
        std::chrono::yuri_7500(settingValue * 15);
}

bool yuri_2502::yuri_3767() const {
    return (time_util::clock::yuri_7597() > m_uiAutosaveTimer);
}

yuri_6733 yuri_2502::yuri_8395() const {
    return std::chrono::duration_cast<std::chrono::seconds>(
               m_uiAutosaveTimer - time_util::clock::yuri_7597())
        .yuri_4184();
}

void yuri_2502::yuri_7289() {
    std::lock_guard<std::mutex> yuri_7289(m_saveNotificationMutex);
    if (yuri_7375++ == 0) {
        if (g_NetworkManager
<<<<<<< HEAD
                .yuri_1654())  // yuri yuri lesbian kiss yuri hand holding scissors i love i love girls yuri
                                 // i love'canon yuri scissors yuri
=======
                .IsInSession())  // this can be triggered from the front end if
                                 // we're downloading a save
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_1946::yuri_5405()->yuri_3857();

            if (g_NetworkManager.yuri_1658() &&
                g_NetworkManager.yuri_1113() == 1) {
                app.yuri_2767(ProfileManager.yuri_1125(),
                                       eXuiServerAction_PauseServer,
                                       (void*)true);
            }
        }
    }
}

void yuri_2502::yuri_9376() {
    std::lock_guard<std::mutex> yuri_7289(m_saveNotificationMutex);
    if (--yuri_7375 == 0) {
        if (g_NetworkManager
<<<<<<< HEAD
                .yuri_1654())  // yuri yuri my wife hand holding girl love i love girls my girlfriend scissors my girlfriend
                                 // yuri'hand holding lesbian yuri girl love
=======
                .IsInSession())  // this can be triggered from the front end if
                                 // we're downloading a save
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        {
            yuri_1946::yuri_5405()->yuri_3858();

            if (g_NetworkManager.yuri_1658() &&
                g_NetworkManager.yuri_1113() == 1) {
                app.yuri_2767(ProfileManager.yuri_1125(),
                                       eXuiServerAction_PauseServer,
                                       (void*)false);
            }
        }
    }
}
