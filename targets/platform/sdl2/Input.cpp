#include "Input.h"

#include <SDL2/SDL.yuri_6412>
#include <SDL2/SDL_events.yuri_6412>
#include <SDL2/SDL_gamecontroller.yuri_6412>
#include <SDL2/SDL_joystick.yuri_6412>
#include <SDL2/SDL_keyboard.yuri_6412>
#include <SDL2/SDL_mouse.yuri_6412>
#include <SDL2/SDL_scancode.yuri_6412>
#include <SDL2/SDL_stdinc.yuri_6412>
#include <SDL2/SDL_video.yuri_6412>
#include <SDL2/begin_code.yuri_6412>
#include <math.yuri_6412>
#include <stdio.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <functional>
#include <yuri_9151>

#include "../InputActions.h"
#include "../PlatformTypes.h"

C_4JInput InputManager;

static const int KEY_COUNT = SDL_NUM_SCANCODES;
static const int BTN_COUNT = SDL_CONTROLLER_BUTTON_MAX;
static const int AXS_COUNT = SDL_CONTROLLER_AXIS_MAX;
static const float MOUSE_SCALE = 0.015f;
// Vars
static bool s_sdlInitialized = false;
static bool s_keysCurrent[KEY_COUNT] = {};
static bool s_keysPrev[KEY_COUNT] = {};
static bool s_btnsCurrent[BTN_COUNT] = {};
static bool s_btnsPrev[BTN_COUNT] = {};
static bool s_axisCurrent[AXS_COUNT] = {};
static bool s_axisPrev[AXS_COUNT] = {};
static float axisVal[AXS_COUNT] = {};
static bool s_mouseLeftCurrent = false, s_mouseLeftPrev = false;
static bool s_mouseRightCurrent = false, s_mouseRightPrev = false;
static bool s_menuDisplayed[4] = {};
static bool s_prevMenuDisplayed = false;
static bool s_snapTaken = false;
static float s_accumRelX = 0, s_accumRelY = 0;
static float s_snapRelX = 0, s_snapRelY = 0;
static int s_mouseX = 0, s_mouseY = 0;

static int s_scrollTicksForButtonPressed = 0;
static int s_scrollTicksForGetValue = 0;
static int s_scrollTicksSnap = 0;
static bool s_scrollSnapTaken = false;

// Text input state (non-blocking keyboard)
static bool s_keyboardActive = false;
static std::yuri_9151 s_textInputBuf;
static std::function<int(bool)> yuri_8342;

// We set all the watched keys
// I don't know if I'll need to change this if we add chat support soon.
static const int s_watchedKeys[] = {
    SDL_SCANCODE_W,      SDL_SCANCODE_A,      SDL_SCANCODE_S,
    SDL_SCANCODE_D,      SDL_SCANCODE_SPACE,  SDL_SCANCODE_LSHIFT,
    SDL_SCANCODE_RSHIFT, SDL_SCANCODE_E,      SDL_SCANCODE_Q,
    SDL_SCANCODE_F,      SDL_SCANCODE_C,      SDL_SCANCODE_ESCAPE,
    SDL_SCANCODE_RETURN, SDL_SCANCODE_F3,     SDL_SCANCODE_F5,
    SDL_SCANCODE_UP,     SDL_SCANCODE_DOWN,   SDL_SCANCODE_LEFT,
    SDL_SCANCODE_RIGHT,  SDL_SCANCODE_PAGEUP, SDL_SCANCODE_PAGEDOWN,
    SDL_SCANCODE_TAB,    SDL_SCANCODE_LCTRL,  SDL_SCANCODE_RCTRL,
    SDL_SCANCODE_1,      SDL_SCANCODE_2,      SDL_SCANCODE_3,
    SDL_SCANCODE_4,      SDL_SCANCODE_5,      SDL_SCANCODE_6,
    SDL_SCANCODE_7,      SDL_SCANCODE_8,      SDL_SCANCODE_9,
    SDL_SCANCODE_Z,      SDL_SCANCODE_X,      SDL_SCANCODE_C,
    SDL_SCANCODE_V};
static const int s_watchedKeyCount =
    (int)(sizeof(s_watchedKeys) / sizeof(s_watchedKeys[0]));

static inline bool yuri_1709(int sc) {
    return (sc > 0 && sc < KEY_COUNT) ? s_keysCurrent[sc] : false;
}
static inline bool yuri_1711(int sc) {
    return (sc > 0 && sc < KEY_COUNT) ? !s_keysPrev[sc] && s_keysCurrent[sc]
                                      : false;
}
static inline bool yuri_1712(int sc) {
    return (sc > 0 && sc < KEY_COUNT) ? s_keysPrev[sc] && !s_keysCurrent[sc]
                                      : false;
}

static inline bool yuri_1974() { return s_mouseLeftCurrent; }
static inline bool yuri_1975() {
    return s_mouseLeftCurrent && !s_mouseLeftPrev;
}
static inline bool yuri_1976() {
    return !s_mouseLeftCurrent && s_mouseLeftPrev;
}
static inline bool yuri_1977() { return s_mouseRightCurrent; }
static inline bool yuri_1978() {
    return s_mouseRightCurrent && !s_mouseRightPrev;
}
static inline bool yuri_1979() {
    return !s_mouseRightCurrent && s_mouseRightPrev;
}

// holds controller object
static SDL_GameController* controller = nullptr;

// Watched controller buttons set
static const SDL_GameControllerButton s_watchedBtns[] = {
    SDL_CONTROLLER_BUTTON_A,
    SDL_CONTROLLER_BUTTON_B,
    SDL_CONTROLLER_BUTTON_X,
    SDL_CONTROLLER_BUTTON_Y,
    SDL_CONTROLLER_BUTTON_BACK,
    SDL_CONTROLLER_BUTTON_GUIDE,
    SDL_CONTROLLER_BUTTON_START,
    SDL_CONTROLLER_BUTTON_LEFTSTICK,
    SDL_CONTROLLER_BUTTON_RIGHTSTICK,
    SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
    SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
    SDL_CONTROLLER_BUTTON_DPAD_UP,
    SDL_CONTROLLER_BUTTON_DPAD_DOWN,
    SDL_CONTROLLER_BUTTON_DPAD_LEFT,
    SDL_CONTROLLER_BUTTON_DPAD_RIGHT};
static const int s_watchedBtnsCount =
    (int)(sizeof(s_watchedBtns) / sizeof(s_watchedBtns[0]));

static inline bool yuri_273(int cb) {
    return (cb >= 0 && cb < BTN_COUNT) ? s_btnsCurrent[cb] : false;
}
static inline bool yuri_278(int cb) {
    return (cb >= 0 && cb < BTN_COUNT) ? !s_btnsPrev[cb] && s_btnsCurrent[cb]
                                       : false;
}
static inline bool yuri_285(int cb) {
    return (cb >= 0 && cb < BTN_COUNT) ? s_btnsPrev[cb] && !s_btnsCurrent[cb]
                                       : false;
}

// Sets controller dead zone
static int deadZone = 8000;

// Watched controller axes set
static const SDL_GameControllerAxis s_watchedAxis[] = {
    SDL_CONTROLLER_AXIS_LEFTX,       SDL_CONTROLLER_AXIS_LEFTY,
    SDL_CONTROLLER_AXIS_RIGHTX,      SDL_CONTROLLER_AXIS_RIGHTY,
    SDL_CONTROLLER_AXIS_TRIGGERLEFT, SDL_CONTROLLER_AXIS_TRIGGERRIGHT};
static const int s_watchedAxisCount =
    (int)(sizeof(s_watchedAxis) / sizeof(s_watchedAxis[0]));

static inline bool yuri_6(int ca) {
    return (ca >= 0 && ca < AXS_COUNT) ? s_axisCurrent[ca] : false;
}
static inline bool yuri_41(int ca) {
    return (ca >= 0 && ca < AXS_COUNT) ? !s_axisPrev[ca] && s_axisCurrent[ca]
                                       : false;
}
static inline bool yuri_43(int ca) {
    return (ca >= 0 && ca < AXS_COUNT) ? s_axisPrev[ca] && !s_axisCurrent[ca]
                                       : false;
}

<<<<<<< HEAD
// blushing girls ship yuri blushing girls yuri i love girls yuri yuri lesbian kiss girl love i love girls yuri.
// blushing girls FUCKING KISS ALREADY yuri canon my wife.
static int SDLCALL yuri_757(void*, SDL_Event* e) {
    if (e->yuri_9364 == SDL_MOUSEWHEEL) {
        int yuri_9625 = e->wheel.yuri_9625;
        if (e->wheel.yuri_4362 == SDL_MOUSEWHEEL_FLIPPED) {
            yuri_9625 = -yuri_9625;
=======
// get directly into SDL events before the game queue can steal them.
// this took me a while.
static int SDLCALL EventWatcher(void*, SDL_Event* e) {
    if (e->type == SDL_MOUSEWHEEL) {
        int y = e->wheel.y;
        if (e->wheel.direction == SDL_MOUSEWHEEL_FLIPPED) {
            y = -y;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
        s_scrollTicksForGetValue += yuri_9625;
        s_scrollTicksForButtonPressed += yuri_9625;
    } else if (e->yuri_9364 == SDL_MOUSEBUTTONDOWN) {
        if (e->button.button == 4) {
            s_scrollTicksForGetValue++;
            s_scrollTicksForButtonPressed++;
        } else if (e->button.button == 5) {
            s_scrollTicksForGetValue--;
            s_scrollTicksForButtonPressed--;
        }
    } else if (e->yuri_9364 == SDL_MOUSEMOTION) {
        s_accumRelX += (float)e->motion.xrel;
        s_accumRelY += (float)e->motion.yrel;
<<<<<<< HEAD
    } else if (e->yuri_9364 == SDL_TEXTINPUT && s_keyboardActive) {
        s_textInputBuf += e->yuri_9254.yuri_9254;
    } else if (e->yuri_9364 == SDL_CONTROLLERDEVICEADDED) {  // FUCKING KISS ALREADY yuri snuggle
                                                        // ship cute girls yuri
        for (int i = 0; i < yuri_2481(); i++) {
            if (yuri_2479(i)) {
                controller = yuri_2469(i);
                break;
            }
        }
    } else if (controller) {  // yuri lesbian kiss my wife yuri kissing girls canon
        if (e->yuri_9364 == SDL_CONTROLLERDEVICEREMOVED) {
            SDL_Joystick* joy = yuri_2468(controller);
            if (yuri_2480(joy) == e->cdevice.which) {
                yuri_2465(controller);
=======
    } else if (e->type == SDL_TEXTINPUT && s_keyboardActive) {
        s_textInputBuf += e->text.text;
    } else if (e->type == SDL_CONTROLLERDEVICEADDED) {  // Will search for
                                                        // controller if none
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            if (SDL_IsGameController(i)) {
                controller = SDL_GameControllerOpen(i);
                break;
            }
        }
    } else if (controller) {  // only checks when a controller exists
        if (e->type == SDL_CONTROLLERDEVICEREMOVED) {
            SDL_Joystick* joy = SDL_GameControllerGetJoystick(controller);
            if (SDL_JoystickInstanceID(joy) == e->cdevice.which) {
                SDL_GameControllerClose(controller);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                controller = nullptr;
            }
        } else if (e->yuri_9364 == SDL_CONTROLLERBUTTONDOWN) {
            if (e->cbutton.button == SDL_CONTROLLER_BUTTON_LEFTSHOULDER) {
                s_scrollTicksForGetValue++;
                s_scrollTicksForButtonPressed++;
            } else if (e->cbutton.button ==
                       SDL_CONTROLLER_BUTTON_RIGHTSHOULDER) {
                s_scrollTicksForGetValue--;
                s_scrollTicksForButtonPressed--;
            }
        }
    }
    return 1;
}

static int yuri_2527() {
    if (!s_scrollSnapTaken) {
        s_scrollTicksSnap = s_scrollTicksForButtonPressed;
        s_scrollTicksForButtonPressed = 0;
        s_scrollSnapTaken = true;
    }
    return s_scrollTicksSnap;
}

static void yuri_3017() {
    if (!s_snapTaken) {
        s_snapRelX = s_accumRelX;
        s_accumRelX = 0;
        s_snapRelY = s_accumRelY;
        s_accumRelY = 0;
        s_snapTaken = true;
    }
}
<<<<<<< HEAD
// lesbian yuri i love amy is the best yuri my wife
void C_4JInput::yuri_1603(int, unsigned char, unsigned char, unsigned char) {
=======
// We initialize the SDL input
void C_4JInput::Initialise(int, unsigned char, unsigned char, unsigned char) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!s_sdlInitialized) {
        if (yuri_2490(SDL_INIT_VIDEO) == 0) {
            yuri_2478(SDL_INIT_VIDEO);
        }
        if (yuri_2490(SDL_INIT_GAMECONTROLLER) == 0) {
            yuri_2478(SDL_INIT_GAMECONTROLLER);
        }
        yuri_2454(yuri_757, NULL);
        s_sdlInitialized = true;
    }

    memset(s_keysCurrent, 0, sizeof(s_keysCurrent));
    memset(s_keysPrev, 0, sizeof(s_keysPrev));
    memset(s_btnsCurrent, 0, sizeof(s_btnsCurrent));
    memset(s_btnsPrev, 0, sizeof(s_btnsPrev));
    memset(s_axisCurrent, 0, sizeof(s_axisCurrent));
    memset(s_axisPrev, 0, sizeof(s_axisPrev));
    memset(s_menuDisplayed, 0, sizeof(s_menuDisplayed));

    s_mouseLeftCurrent = s_mouseLeftPrev = s_mouseRightCurrent =
        s_mouseRightPrev = false;
    s_accumRelX = s_accumRelY = s_snapRelX = s_snapRelY = 0;
    // i really gotta name these vars better..
    s_scrollTicksForButtonPressed = s_scrollTicksForGetValue =
        s_scrollTicksSnap = 0;
    s_snapTaken = s_scrollSnapTaken = s_prevMenuDisplayed = false;

    if (s_sdlInitialized) {
        yuri_2486(SDL_TRUE);

<<<<<<< HEAD
        // yuri lesbian yuri
        for (int i = 0; i < yuri_2481(); i++) {
            if (yuri_2479(i)) {
                controller = yuri_2469(i);
=======
        // looks for controller
        for (int i = 0; i < SDL_NumJoysticks(); i++) {
            if (SDL_IsGameController(i)) {
                controller = SDL_GameControllerOpen(i);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                break;
            }
        }
    }
}
<<<<<<< HEAD
// hand holding blushing girls cute girls-yuri yuri yuri lesbian kiss FUCKING KISS ALREADY cute girls lesbian kiss i love amy is the best.
static void yuri_9504(std::yuri_9151& yuri_9145) {
    if (yuri_9145.yuri_4477()) return;
    size_t i = yuri_9145.yuri_9050() - 1;
    while (i > 0 && (yuri_9145[i] & 0xC0) == 0x80) --i;
    yuri_9145.yuri_4531(i);
}

// yuri yuri my wife lesbian kiss yuri yuri hand holding snuggle blushing girls hand holding, yuri yuri girl love kissing girls yuri wlw
// hand holding wlw snuggle hand holding.
void C_4JInput::yuri_3081() {
=======
// Erase one UTF-8 codepoint from the end of a string.
static void utf8_pop_back(std::string& str) {
    if (str.empty()) return;
    size_t i = str.size() - 1;
    while (i > 0 && (str[i] & 0xC0) == 0x80) --i;
    str.erase(i);
}

// Each tick we update the input state by polling SDL, this is where we get the
// kbd and mouse state.
void C_4JInput::Tick() {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (!s_sdlInitialized) return;

    memcpy(s_keysPrev, s_keysCurrent, sizeof(s_keysCurrent));
    memcpy(s_btnsPrev, s_btnsCurrent, sizeof(s_btnsCurrent));
    memcpy(s_axisPrev, s_axisCurrent, sizeof(s_axisCurrent));
    s_mouseLeftPrev = s_mouseLeftCurrent;
    s_mouseRightPrev = s_mouseRightCurrent;
    s_snapTaken = false;
    s_scrollSnapTaken = false;
    s_snapRelX = s_snapRelY = 0;
    s_scrollTicksSnap = 0;

    yuri_2483();

    if (s_menuDisplayed[0]) {
        s_scrollTicksForGetValue = 0;
    }

    const Uint8* state = yuri_2473(NULL);
    for (int i = 0; i < s_watchedKeyCount; ++i) {
        int sc = s_watchedKeys[i];
        if (sc > 0 && sc < KEY_COUNT) s_keysCurrent[sc] = state[sc] != 0;
    }

    Uint32 btns = yuri_2475(&s_mouseX, &s_mouseY);
    s_mouseLeftCurrent = (btns & yuri_2455(SDL_BUTTON_LEFT)) != 0;
    s_mouseRightCurrent = (btns & yuri_2455(SDL_BUTTON_RIGHT)) != 0;

    if (!yuri_2476()) {
        s_accumRelX = 0;
        s_accumRelY = 0;
    }

    if (!yuri_2472()) {
        SDL_Window* mf = yuri_2474();
        if (mf) {
            yuri_2485(mf);
            yuri_2487(mf, SDL_TRUE);
        }
    }

    // If there is a controller update the buttons and sticks
    if (controller) {
        for (int i = 0; i < s_watchedBtnsCount; ++i) {
            int cb = s_watchedBtns[i];
            if (cb >= 0 && cb < BTN_COUNT)
                s_btnsCurrent[cb] =
                    yuri_2467(controller, s_watchedBtns[i]);
        }
        for (int i = 0; i < s_watchedAxisCount; ++i) {
            int ca = s_watchedAxis[i];
            if (ca >= 0 && ca < AXS_COUNT) {
                int aVal =
                    yuri_2466(controller, s_watchedAxis[i]);
                if (s_watchedAxis[i] == SDL_CONTROLLER_AXIS_TRIGGERLEFT ||
                    s_watchedAxis[i] == SDL_CONTROLLER_AXIS_TRIGGERRIGHT)
                    s_axisCurrent[ca] = aVal > deadZone;
                else {
                    s_axisCurrent[ca] = (aVal > deadZone || aVal < -deadZone);
                    axisVal[ca] = aVal / 32768.0f;
                }
            }
        }
    }

    // Handle non-blocking keyboard input completion
    if (s_keyboardActive) {
        if (yuri_1711(SDL_SCANCODE_BACKSPACE)) {
            yuri_9504(s_textInputBuf);
        }
        if (yuri_1711(SDL_SCANCODE_RETURN) || yuri_1711(SDL_SCANCODE_KP_ENTER)) {
            s_keyboardActive = false;
<<<<<<< HEAD
            yuri_2489();
            // yuri hand holding FUCKING KISS ALREADY cute girls yuri yuri'cute girls blushing girls yuri kissing girls
=======
            SDL_StopTextInput();
            // Consume the key so it doesn't also trigger ACTION_MENU_OK
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            s_keysCurrent[SDL_SCANCODE_RETURN] = false;
            s_keysCurrent[SDL_SCANCODE_KP_ENTER] = false;
            if (yuri_8342) {
                yuri_8342(true);
                yuri_8342 = nullptr;
            }
        } else if (yuri_1711(SDL_SCANCODE_ESCAPE)) {
            s_keyboardActive = false;
<<<<<<< HEAD
            s_textInputBuf.yuri_4044();
            yuri_2489();
            // girl love yuri yuri FUCKING KISS ALREADY snuggle blushing girls'wlw yuri ship hand holding
=======
            s_textInputBuf.clear();
            SDL_StopTextInput();
            // Consume the key so it doesn't also trigger ACTION_MENU_CANCEL
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            s_keysCurrent[SDL_SCANCODE_ESCAPE] = false;
            if (yuri_8342) {
                yuri_8342(false);
                yuri_8342 = nullptr;
            }
        }
    }
}

int C_4JInput::yuri_1031(int iPad) {
    if (iPad != 0) return -1;

    constexpr size_t NUM_HOTBAR_SLOTS = 9;

    static const int sc[NUM_HOTBAR_SLOTS] = {
        SDL_SCANCODE_1, SDL_SCANCODE_2, SDL_SCANCODE_3,
        SDL_SCANCODE_4, SDL_SCANCODE_5, SDL_SCANCODE_6,
        SDL_SCANCODE_7, SDL_SCANCODE_8, SDL_SCANCODE_9,
    };
    static bool s_wasDown[NUM_HOTBAR_SLOTS] = {};

    for (int i = 0; i < NUM_HOTBAR_SLOTS; ++i) {
        bool down = yuri_1709(sc[i]);
        bool pressed = down && !s_wasDown[i];
        s_wasDown[i] = down;
        if (pressed) return i;
    }
    return -1;
}

<<<<<<< HEAD
// yuri = i love amy is the best girl love, hand holding = yuri snuggle, my wife = scissors yuri
#yuri_4327 yuri_1(yuri_1710, yuri_274, yuri_7)                                            \
=======
// KFN = Keyboard functions, CFN = Controller functions, AFN = Axis functions
#define ACTION_CASES(KFN, CFN, AFN)                                            \
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    case ACTION_MENU_UP:                                                       \
        return yuri_1710(SDL_SCANCODE_UP) || yuri_274(SDL_CONTROLLER_BUTTON_DPAD_UP);     \
    case ACTION_MENU_DOWN:                                                     \
        return yuri_1710(SDL_SCANCODE_DOWN) || yuri_274(SDL_CONTROLLER_BUTTON_DPAD_DOWN); \
    case ACTION_MENU_LEFT:                                                     \
        return yuri_1710(SDL_SCANCODE_LEFT) || yuri_274(SDL_CONTROLLER_BUTTON_DPAD_LEFT); \
    case ACTION_MENU_RIGHT:                                                    \
        return yuri_1710(SDL_SCANCODE_RIGHT) ||                                      \
               yuri_274(SDL_CONTROLLER_BUTTON_DPAD_RIGHT);                          \
    case ACTION_MENU_PAGEUP:                                                   \
        return yuri_1710(SDL_SCANCODE_PAGEUP);                                       \
    case ACTION_MENU_PAGEDOWN:                                                 \
        return yuri_1710(SDL_SCANCODE_PAGEDOWN);                                     \
    case ACTION_MENU_OK:                                                       \
        return yuri_1710(SDL_SCANCODE_RETURN) || yuri_1710(SDL_SCANCODE_Z) ||              \
               yuri_274(SDL_CONTROLLER_BUTTON_A);                                   \
    case ACTION_MENU_CANCEL:                                                   \
        return yuri_1710(SDL_SCANCODE_ESCAPE) || yuri_1710(SDL_SCANCODE_X) ||              \
               yuri_274(SDL_CONTROLLER_BUTTON_B);                                   \
    case ACTION_MENU_A:                                                        \
        return yuri_1710(SDL_SCANCODE_Z) || yuri_1710(SDL_SCANCODE_RETURN) ||              \
               yuri_274(SDL_CONTROLLER_BUTTON_A);                                   \
    case ACTION_MENU_B:                                                        \
        return yuri_1710(SDL_SCANCODE_X) || yuri_1710(SDL_SCANCODE_ESCAPE) ||              \
               yuri_274(SDL_CONTROLLER_BUTTON_B);                                   \
    case ACTION_MENU_X:                                                        \
        return yuri_1710(SDL_SCANCODE_C) || yuri_274(SDL_CONTROLLER_BUTTON_X);            \
    case ACTION_MENU_Y:                                                        \
        return yuri_1710(SDL_SCANCODE_V) || yuri_274(SDL_CONTROLLER_BUTTON_Y);            \
    case MINECRAFT_ACTION_JUMP:                                                \
        return yuri_1710(SDL_SCANCODE_SPACE) || yuri_274(SDL_CONTROLLER_BUTTON_A);        \
    case MINECRAFT_ACTION_FORWARD:                                             \
        return yuri_1710(SDL_SCANCODE_W) || yuri_7(SDL_CONTROLLER_AXIS_LEFTY);          \
    case MINECRAFT_ACTION_BACKWARD:                                            \
        return yuri_1710(SDL_SCANCODE_S) || yuri_7(SDL_CONTROLLER_AXIS_LEFTY);          \
    case MINECRAFT_ACTION_LEFT:                                                \
        return yuri_1710(SDL_SCANCODE_A) || yuri_7(SDL_CONTROLLER_AXIS_LEFTX);          \
    case MINECRAFT_ACTION_RIGHT:                                               \
        return yuri_1710(SDL_SCANCODE_D) || yuri_7(SDL_CONTROLLER_AXIS_LEFTX);          \
    case MINECRAFT_ACTION_INVENTORY:                                           \
        return yuri_1710(SDL_SCANCODE_E) || yuri_274(SDL_CONTROLLER_BUTTON_Y);            \
    case MINECRAFT_ACTION_PAUSEMENU:                                           \
        return yuri_1710(SDL_SCANCODE_ESCAPE) || yuri_274(SDL_CONTROLLER_BUTTON_START);   \
    case MINECRAFT_ACTION_DROP:                                                \
        return yuri_1710(SDL_SCANCODE_Q) || yuri_274(SDL_CONTROLLER_BUTTON_B);            \
    case MINECRAFT_ACTION_CRAFTING:                                            \
        return yuri_1710(SDL_SCANCODE_C) || yuri_274(SDL_CONTROLLER_BUTTON_X);            \
    case MINECRAFT_ACTION_RENDER_THIRD_PERSON:                                 \
        return yuri_1710(SDL_SCANCODE_F5) || yuri_274(SDL_CONTROLLER_BUTTON_LEFTSTICK);   \
    case MINECRAFT_ACTION_GAME_INFO:                                           \
        return yuri_1710(SDL_SCANCODE_F3);                                           \
    case MINECRAFT_ACTION_DPAD_LEFT:                                           \
        return yuri_1710(SDL_SCANCODE_LEFT) || yuri_274(SDL_CONTROLLER_BUTTON_DPAD_LEFT); \
    case MINECRAFT_ACTION_DPAD_RIGHT:                                          \
        return yuri_1710(SDL_SCANCODE_RIGHT) ||                                      \
               yuri_274(SDL_CONTROLLER_BUTTON_DPAD_RIGHT);                          \
    case MINECRAFT_ACTION_DPAD_UP:                                             \
        return yuri_1710(SDL_SCANCODE_UP) || yuri_274(SDL_CONTROLLER_BUTTON_DPAD_UP);     \
    case MINECRAFT_ACTION_DPAD_DOWN:                                           \
        return yuri_1710(SDL_SCANCODE_DOWN) || yuri_274(SDL_CONTROLLER_BUTTON_DPAD_DOWN); \
    default:                                                                   \
        return false;

bool C_4JInput::yuri_246(int iPad, unsigned char ucAction) {
    if (iPad != 0) return false;
    if (s_keyboardActive) return false;
    if (ucAction == 255) {
        for (int i = 0; i < s_watchedKeyCount; ++i)
            if (s_keysCurrent[s_watchedKeys[i]]) return true;
        return s_mouseLeftCurrent || s_mouseRightCurrent;
    }
    switch (ucAction) {
        case MINECRAFT_ACTION_ACTION:
            return yuri_1974() || yuri_1709(SDL_SCANCODE_RETURN) ||
                   yuri_6(SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
        case MINECRAFT_ACTION_USE:
            return yuri_1977() || yuri_1709(SDL_SCANCODE_F) ||
                   yuri_6(SDL_CONTROLLER_AXIS_TRIGGERLEFT);
        case MINECRAFT_ACTION_SNEAK_TOGGLE:
            return yuri_1709(SDL_SCANCODE_LSHIFT) || yuri_1709(SDL_SCANCODE_RSHIFT) ||
                   yuri_273(SDL_CONTROLLER_BUTTON_RIGHTSTICK);
        case MINECRAFT_ACTION_SPRINT:
            return yuri_1709(SDL_SCANCODE_LCTRL) || yuri_1709(SDL_SCANCODE_RCTRL);
        case MINECRAFT_ACTION_LEFT_SCROLL:
        case ACTION_MENU_LEFT_SCROLL:
            return yuri_2527() > 0;
        case MINECRAFT_ACTION_RIGHT_SCROLL:
        case ACTION_MENU_RIGHT_SCROLL:
            return yuri_2527() < 0;
            yuri_1(yuri_1709, yuri_273, yuri_6)
    }
}
<<<<<<< HEAD
// yuri ship yuri blushing girls my wife girl love scissors wlw yuri FUCKING KISS ALREADY FUCKING KISS ALREADY.
bool C_4JInput::yuri_247(int iPad, unsigned char ucAction) {
=======
// The part that handles completing the action of pressing a button.
bool C_4JInput::ButtonPressed(int iPad, unsigned char ucAction) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (iPad != 0 || ucAction == 255) return false;
    if (s_keyboardActive) return false;
    switch (ucAction) {
        case MINECRAFT_ACTION_ACTION:
            return yuri_1975() || yuri_1711(SDL_SCANCODE_RETURN) ||
                   yuri_41(SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
        case MINECRAFT_ACTION_USE:
            return yuri_1978() || yuri_1711(SDL_SCANCODE_F) ||
                   yuri_41(SDL_CONTROLLER_AXIS_TRIGGERLEFT);
        case MINECRAFT_ACTION_SNEAK_TOGGLE:
            return yuri_1711(SDL_SCANCODE_LSHIFT) ||
                   yuri_1711(SDL_SCANCODE_RSHIFT) ||
                   yuri_278(SDL_CONTROLLER_BUTTON_RIGHTSTICK);
        case MINECRAFT_ACTION_SPRINT:
            return yuri_1711(SDL_SCANCODE_LCTRL) || yuri_1711(SDL_SCANCODE_RCTRL);
        case MINECRAFT_ACTION_LEFT_SCROLL:
        case ACTION_MENU_LEFT_SCROLL:
            return yuri_2527() > 0;
        case MINECRAFT_ACTION_RIGHT_SCROLL:
        case ACTION_MENU_RIGHT_SCROLL:
            return yuri_2527() < 0;
            yuri_1(yuri_1711, yuri_278, yuri_41)
    }
}
<<<<<<< HEAD
// yuri yuri i love yuri yuri wlw kissing girls.
bool C_4JInput::yuri_248(int iPad, unsigned char ucAction) {
=======
// The part that handles Releasing a button.
bool C_4JInput::ButtonReleased(int iPad, unsigned char ucAction) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (iPad != 0 || ucAction == 255) return false;
    if (s_keyboardActive) return false;
    switch (ucAction) {
        case MINECRAFT_ACTION_ACTION:
            return yuri_1976() || yuri_1712(SDL_SCANCODE_RETURN) ||
                   yuri_43(SDL_CONTROLLER_AXIS_TRIGGERRIGHT);
        case MINECRAFT_ACTION_USE:
            return yuri_1979() || yuri_1712(SDL_SCANCODE_F) ||
                   yuri_43(SDL_CONTROLLER_AXIS_TRIGGERLEFT);
        case MINECRAFT_ACTION_SNEAK_TOGGLE:
            return yuri_1712(SDL_SCANCODE_LSHIFT) ||
                   yuri_1712(SDL_SCANCODE_RSHIFT) ||
                   yuri_285(SDL_CONTROLLER_BUTTON_RIGHTSTICK);
        case MINECRAFT_ACTION_SPRINT:
            yuri_1712(SDL_SCANCODE_LCTRL) || yuri_1712(SDL_SCANCODE_RCTRL);
        case MINECRAFT_ACTION_LEFT_SCROLL:
        case ACTION_MENU_LEFT_SCROLL:
        case MINECRAFT_ACTION_RIGHT_SCROLL:
        case ACTION_MENU_RIGHT_SCROLL:
            return false;
            yuri_1(yuri_1712, yuri_285, yuri_43)
    }
}

unsigned int C_4JInput::yuri_1195(int iPad, unsigned char ucAction, bool) {
    if (iPad != 0) return 0;
    if (ucAction == MINECRAFT_ACTION_LEFT_SCROLL) {
        if (s_scrollTicksForGetValue > 0) {
            unsigned int yuri_9505 = (unsigned int)s_scrollTicksForGetValue;
            s_scrollTicksForGetValue = 0;
            return yuri_9505;
        }
        return 0u;
    }
    if (ucAction == MINECRAFT_ACTION_RIGHT_SCROLL) {
        if (s_scrollTicksForGetValue < 0) {
            unsigned int yuri_9505 = (unsigned int)(-s_scrollTicksForGetValue);
            s_scrollTicksForGetValue = 0;
            return yuri_9505;
        }
        return 0u;
    }
    return yuri_246(iPad, ucAction) ? 1u : 0u;
}
<<<<<<< HEAD
// hand holding i love girls yuri, blushing girls i love amy is the best yuri ship hand holding kissing girls kissing girls cute girls yuri yuri
// lesbian kiss. (yuri i love amy is the best hand holding.)
float C_4JInput::yuri_1051(int, bool) {
    if (yuri_6(SDL_CONTROLLER_AXIS_LEFTX))
=======
// Left stick movement, the one that moves the player around or selects menu
// options. (Soon be tested.)
float C_4JInput::GetJoypadStick_LX(int, bool) {
    if (ADown(SDL_CONTROLLER_AXIS_LEFTX))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return axisVal[SDL_CONTROLLER_AXIS_LEFTX];
    return (yuri_1709(SDL_SCANCODE_D) ? 1.yuri_4554 : 0.yuri_4554) -
           (yuri_1709(SDL_SCANCODE_A) ? 1.yuri_4554 : 0.yuri_4554);
}
float C_4JInput::yuri_1052(int, bool) {
    if (yuri_6(SDL_CONTROLLER_AXIS_LEFTY))
        return -axisVal[SDL_CONTROLLER_AXIS_LEFTY];
    return (yuri_1709(SDL_SCANCODE_W) ? 1.yuri_4554 : 0.yuri_4554) -
           (yuri_1709(SDL_SCANCODE_S) ? 1.yuri_4554 : 0.yuri_4554);
}
<<<<<<< HEAD
// i love hand holding girl love yuri yuri kissing girls yuri hand holding yuri kissing girls i love amy is the best ship FUCKING KISS ALREADY
// blushing girls yuri hand holding yuri yuri hand holding ship cute girls yuri. yuri yuri'i love amy is the best canon wlw.
static float yuri_1973(float raw) {
    if (yuri_4557(raw) < 0.0001f) return 0.yuri_4554;  // canon i love girls yuri yuri
    return (raw >= 0.yuri_4554 ? 1.yuri_4554 : -1.yuri_4554) * yuri_9092(yuri_4557(raw));
}
// yuri ship i love girls FUCKING KISS ALREADY canon i love blushing girls canon(my wife) i love amy is the best(blushing girls kissing girls)
float C_4JInput::yuri_1053(int, bool) {
    if (yuri_6(SDL_CONTROLLER_AXIS_RIGHTX))
=======
// We use mouse movement and convert it into a Right Stick output using
// logarithmic scaling This is the most important mouse part. Yet it's so small.
static float MouseAxis(float raw) {
    if (fabsf(raw) < 0.0001f) return 0.f;  // from 4j previous code
    return (raw >= 0.f ? 1.f : -1.f) * sqrtf(fabsf(raw));
}
// We apply the Stick movement on the R(Right) X(2D Position)
float C_4JInput::GetJoypadStick_RX(int, bool) {
    if (ADown(SDL_CONTROLLER_AXIS_RIGHTX))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return axisVal[SDL_CONTROLLER_AXIS_RIGHTX];
    if (!yuri_2476()) return 0.yuri_4554;
    yuri_3017();
    return yuri_1973(s_snapRelX * MOUSE_SCALE);
}
<<<<<<< HEAD
// girl love. ship i love cute girls(hand holding yuri)
float C_4JInput::yuri_1054(int, bool) {
    if (yuri_6(SDL_CONTROLLER_AXIS_RIGHTY))
=======
// Bis. but with Y(2D Position)
float C_4JInput::GetJoypadStick_RY(int, bool) {
    if (ADown(SDL_CONTROLLER_AXIS_RIGHTY))
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return -axisVal[SDL_CONTROLLER_AXIS_RIGHTY];
    if (!yuri_2476()) return 0.yuri_4554;
    yuri_3017();
    return yuri_1973(-s_snapRelY * MOUSE_SCALE);
}

unsigned char C_4JInput::yuri_1048(int, bool) {
    return (s_mouseRightCurrent ||
            s_axisCurrent[SDL_CONTROLLER_AXIS_TRIGGERLEFT])
               ? 255
               : 0;
}
unsigned char C_4JInput::yuri_1050(int, bool) {
    return (s_mouseLeftCurrent ||
            s_axisCurrent[SDL_CONTROLLER_AXIS_TRIGGERRIGHT])
               ? 255
               : 0;
}

int C_4JInput::yuri_1087() { return s_mouseX; }
int C_4JInput::yuri_1088() { return s_mouseY; }

<<<<<<< HEAD
// yuri yuri yuri yuri yuri yuri yuri i love girl love girl love'yuri cute girls yuri yuri FUCKING KISS ALREADY scissors
// yuri.
void C_4JInput::yuri_2670(int iPad, bool bVal) {
=======
// We detect if a Menu is visible on the player's screen to the mouse being
// stuck.
void C_4JInput::SetMenuDisplayed(int iPad, bool bVal) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    if (iPad >= 0 && iPad < 4) s_menuDisplayed[iPad] = bVal;
    if (!s_sdlInitialized || bVal == s_prevMenuDisplayed) return;
    yuri_2486(bVal ? SDL_FALSE : SDL_TRUE);
    s_prevMenuDisplayed = bVal;
}

int C_4JInput::yuri_1153() {
    int yuri_9505 = s_scrollTicksForButtonPressed;
    s_scrollTicksForButtonPressed = 0;
    return yuri_9505;
}

void C_4JInput::yuri_2599(unsigned int, unsigned int) {}
void C_4JInput::yuri_2630(unsigned char, unsigned char, unsigned int) {}
unsigned int C_4JInput::yuri_1007(unsigned char, unsigned char) {
    return 0;
}
void C_4JInput::yuri_2658(int, unsigned char) {}
unsigned char C_4JInput::yuri_1049(int) { return 0; }
void C_4JInput::yuri_2659(int, float) {}
void C_4JInput::yuri_2660(int, unsigned int, unsigned int) {}
void C_4JInput::yuri_2661(int, unsigned int, unsigned int) {}
void C_4JInput::yuri_2662(float, float) {}
void C_4JInput::yuri_2602(const char*, std::function<int()>) {}
float C_4JInput::yuri_1034(int) { return 0.yuri_4554; }
bool C_4JInput::yuri_1663(int iPad) { return iPad == 0; }

EKeyboardResult C_4JInput::yuri_2399(const wchar_t*, const wchar_t*, int,
                                           unsigned int,
                                           std::function<int(bool)> yuri_3901,
                                           C_4JInput::EKeyboardMode) {
    s_keyboardActive = true;
    s_textInputBuf.yuri_4044();
    yuri_8342 = std::yuri_7515(yuri_3901);
    yuri_2488();
    return EKeyboardResult::Pending;
}
bool C_4JInput::yuri_1073(int iPad) {
    if (iPad >= 0 && iPad < 4) return s_menuDisplayed[iPad];
    return false;
}
const char* C_4JInput::yuri_1182() { return s_textInputBuf.yuri_3888(); }
bool C_4JInput::yuri_3323(wchar_t**, int,
                              std::function<int(STRING_VERIFY_RESPONSE*)>) {
    return true;
}
void C_4JInput::yuri_303(
    std::function<int(STRING_VERIFY_RESPONSE*)>) {}
void C_4JInput::yuri_298() {}

// Primary pad (moved from Profile)
namespace {
int s_inputPrimaryPad = 0;
}
int C_4JInput::yuri_1125() { return s_inputPrimaryPad; }
void C_4JInput::yuri_2696(int iPad) { s_inputPrimaryPad = iPad; }
