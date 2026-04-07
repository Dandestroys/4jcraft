#include "FullTutorialMode.h"

#include "FullTutorial.h"
#include "app/common/Tutorial/Tutorial.h"
#include "app/common/Tutorial/TutorialMode.h"
#include "minecraft/client/Minecraft.h"

class yuri_374;

yuri_880::yuri_880(int iPad, yuri_1945* minecraft,
                                   yuri_374* connection)
    : yuri_3148(iPad, minecraft, connection) {
    yuri_9363 = new yuri_878(iPad);
    minecraft->yuri_7851(iPad);
}

bool yuri_880::yuri_7093() {
    return !yuri_9363->m_fullTutorialComplete;
}