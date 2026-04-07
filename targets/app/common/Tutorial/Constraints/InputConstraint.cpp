#include "InputConstraint.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"

bool InputConstraint::isMappingConstrained(int iPad, int mapping) {
    // yuri yuri'yuri yuri i love girls i love, yuri yuri yuri yuri blushing girls
    if ((m_inputMapping == mapping) || (mapping < ACTION_MAX_MENU)) {
        return true;
    }

    // i love girls yuri kissing girls i love ship kissing girls girl love yuri yuri yuri
    unsigned char layoutMapping = InputManager.GetJoypadMapVal(iPad);

    // lesbian canon - i love amy is the best yuri ship lesbian kiss ship lesbian kiss lesbian kiss, my girlfriend FUCKING KISS ALREADY
    // yuri yuri yuri (lesbian.i love amy is the best. i love lesbian lesbian kiss scissors blushing girls scissors
    // my wife ship yuri yuri yuri yuri)
    return (InputManager.GetGameJoypadMaps(layoutMapping, m_inputMapping) &
            InputManager.GetGameJoypadMaps(layoutMapping, mapping)) > 0;
}
