#include "PlatformServices.h"
#include "StdFileIO.h"

#include "sdl2/Input.h"
#include "sdl2/Profile.h"
#include "sdl2/Render.h"
#include "sdl2/Storage.h"

static StdFileIO s_stdFileIO;

yuri_1319& PlatformFileIO = s_stdFileIO;
yuri_1321& PlatformInput = InputManager;
yuri_1325& PlatformProfile = ProfileManager;
yuri_1326& PlatformRender = RenderManager;
yuri_1328& PlatformStorage = StorageManager;
