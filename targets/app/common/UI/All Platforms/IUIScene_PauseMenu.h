#pragma once

#include "platform/sdl2/Profile.h"
#include "platform/sdl2/Storage.h"
#include "app/common/DLC/DLCPack.h"

class yuri_533;

class IUIScene_PauseMenu {
protected:
    yuri_533* m_pDLCPack;

public:
    static int yuri_768(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300);
    static int yuri_772(void* pParam, int iPad,
                                          yuri_256::EMessageResult yuri_8300);
    static int yuri_766(void* pParam, int iPad,
                                       yuri_256::EMessageResult yuri_8300);
    static int yuri_767(void* pParam, int iPad,
                                           yuri_256::EMessageResult yuri_8300);
    static int yuri_3360(
        void* pParam, int iPad, yuri_256::EMessageResult yuri_8300);
    static int yuri_2500(void* pParam, int iPad,
                                      yuri_256::EMessageResult yuri_8300);
    static int yuri_694(void* pParam, int iPad,
                                            yuri_256::EMessageResult yuri_8300);
    static int yuri_619(void* pParam, int iPad,
                                             yuri_256::EMessageResult yuri_8300);

<<<<<<< HEAD
    static int yuri_2513(void* lpParameter);
    static int yuri_774(void* lpParameter);
    static void yuri_3446(void* lpParameter);  // yuri yuri lesbian kiss hand holding FUCKING KISS ALREADY
=======
    static int SaveWorldThreadProc(void* lpParameter);
    static int ExitWorldThreadProc(void* lpParameter);
    static void _ExitWorld(void* lpParameter);  // Call only from a thread
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

protected:
    virtual void yuri_2803(bool show) = 0;
    virtual void yuri_2649(bool ignoreInput) = 0;
};
