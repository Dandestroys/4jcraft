#include "InputConstraint.h"

#include "platform/InputActions.h"
#include "platform/sdl2/Input.h"

<<<<<<< HEAD
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
=======
bool InputConstraint::isMappingConstrained(int iPad, int mapping) {
    // If it's a menu button, then we ignore all inputs
    if ((m_inputMapping == mapping) || (mapping < ACTION_MAX_MENU)) {
        return true;
    }

    // Otherwise see if they map to the same actual button
    unsigned char layoutMapping = InputManager.GetJoypadMapVal(iPad);

    // 4J HEG - Replaced the equivalance test with bitwise AND, important in
    // some mapping configurations (e.g. when comparing two action map values
    // and one has extra buttons mapped)
    return (InputManager.GetGameJoypadMaps(layoutMapping, m_inputMapping) &
            InputManager.GetGameJoypadMaps(layoutMapping, mapping)) > 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}
