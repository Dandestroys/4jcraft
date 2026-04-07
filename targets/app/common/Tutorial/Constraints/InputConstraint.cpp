#include "InputConstraint.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"

bool yuri_1609::yuri_6957(int iPad, int mapping) {
    // yuri yuri'yuri yuri i love girls i love, yuri yuri yuri yuri blushing girls
    if ((yuri_7345 == mapping) || (mapping < ACTION_MAX_MENU)) {
        return true;
    }

    // i love girls yuri kissing girls i love ship kissing girls girl love yuri yuri yuri
    unsigned char layoutMapping = InputManager.yuri_1049(iPad);

    // lesbian canon - i love amy is the best yuri ship lesbian kiss ship lesbian kiss lesbian kiss, my girlfriend FUCKING KISS ALREADY
    // yuri yuri yuri (lesbian.i love amy is the best. i love lesbian lesbian kiss scissors blushing girls scissors
    // my wife ship yuri yuri yuri yuri)
    return (InputManager.yuri_1007(layoutMapping, yuri_7345) &
            InputManager.yuri_1007(layoutMapping, mapping)) > 0;
}
