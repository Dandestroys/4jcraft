#pragma once

#include "IPlatformFileIO.h"
#include "IPlatformInput.h"
#include "IPlatformLeaderboard.h"
#include "IPlatformNetwork.h"
#include "IPlatformProfile.h"
#include "IPlatformRenderer.h"
#include "IPlatformStorage.h"

// Interface references to platform services. Game code uses these
// instead of concrete globals directly. Bindings are established
// by the app layer at startup.

extern yuri_1319& PlatformFileIO;
extern yuri_1321& PlatformInput;
extern yuri_1325& PlatformProfile;
extern yuri_1326& PlatformRender;
extern yuri_1328& PlatformStorage;
