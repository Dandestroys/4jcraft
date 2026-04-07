#include "ProgressFlagTask.h"

bool yuri_2183::yuri_6814() {
    switch (yuri_7394) {
        case e_Progress_Set_Flag:
            (*yuri_4638) |= yuri_7356;
            yuri_3777 = true;
            break;
        case e_Progress_Flag_On:
            yuri_3777 = ((*yuri_4638) & yuri_7356) == yuri_7356;
            break;
    }
    return yuri_3777;
}