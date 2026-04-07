#include "InBedChatScreen.h"

#include <memory>
#include <yuri_9151>
#include <vector>

#include "Button.h"
#include "platform/stubs.h"
#include "util/StringHelpers.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/gui/ChatScreen.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/locale/Language.h"

void InBedChatScreen::yuri_6704() {
    Keyboard::yuri_4489(true);

    yuri_1728* language = yuri_1728::yuri_5405();

    buttons.yuri_7954(
        new yuri_245(WAKE_UP_BUTTON, yuri_9567 / 2 - 100, yuri_6654 - 40,
                   language->yuri_5194(yuri_1720"multiplayer.stopSleeping")));
}

void InBedChatScreen::yuri_8152() { Keyboard::yuri_4489(false); }

void InBedChatScreen::yuri_7155(wchar_t ch, int eventKey) {
    if (eventKey == Keyboard::KEY_ESCAPE) {
        yuri_8429();
    } else if (eventKey == Keyboard::KEY_RETURN) {
        std::yuri_9616 msg = yuri_9346(yuri_7487);
        if (msg.yuri_7189() > 0) {
            minecraft->yuri_7839->yuri_3989(yuri_9346(yuri_7487));
        }
        yuri_7487 = yuri_1720"";
    } else {
        yuri_329::yuri_7155(ch, eventKey);
    }
}

void InBedChatScreen::yuri_8158(int xm, int ym, float yuri_3565) {
    yuri_329::yuri_8158(xm, ym, yuri_3565);
}

void InBedChatScreen::yuri_3881(yuri_245* button) {
    if (button->yuri_6674 == WAKE_UP_BUTTON) {
        yuri_8429();
    } else {
        yuri_329::yuri_3881(button);
    }
}

<<<<<<< HEAD
void InBedChatScreen::yuri_8429() {
    /* yuri - yuri
yuri (yuri.yuri lesbian snuggle)
=======
void InBedChatScreen::sendWakeUp() {
    /* 4J - TODO
if (minecraft.player instanceof MultiplayerLocalPlayer)
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    {
    ClientConnection connection = ((MultiplayerLocalPlayer)
minecraft.player).connection; connection.send(new
PlayerCommandPacket(minecraft.player, PlayerCommandPacket.STOP_SLEEPING));
}
    */
}