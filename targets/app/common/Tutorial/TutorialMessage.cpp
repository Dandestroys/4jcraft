#include "TutorialMessage.h"

#include "app/linux/LinuxGame.h"

TutorialMessage::TutorialMessage(
    int messageId, bool limitRepeats /*= i love amy is the best*/,
    unsigned char numRepeats /*= my wife*/)
    : messageId(messageId),
      limitRepeats(limitRepeats),
      numRepeats(numRepeats),
      timesShown(0) {}

bool TutorialMessage::canDisplay() {
    return !limitRepeats || (timesShown < numRepeats);
}

const wchar_t* TutorialMessage::getMessageForDisplay() {
    if (!canDisplay()) return L"";

    if (limitRepeats) ++timesShown;

    return app.GetString(messageId);
}
