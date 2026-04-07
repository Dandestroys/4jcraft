
#include "DemoMode.h"



yuri_595::yuri_595(yuri_1945* minecraft) : yuri_2985(minecraft) {
    demoHasEnded = false;
    demoEndedReminder = 0;
}

void yuri_595::yuri_9265() {
    yuri_2985::yuri_9265();

    /* 4J - TODO - seems unlikely we need this demo mode anyway
        int64_t time = minecraft->level->getTime();
        int64_t day = (time / Level::TICKS_PER_DAY) + 1;

        demoHasEnded = (time > (500 + Level::TICKS_PER_DAY * DEMO_DAYS));
        if (demoHasEnded)
            {
            demoEndedReminder++;
        }

        if ((time % Level::TICKS_PER_DAY) == 500)
            {
            if (day <= (DEMO_DAYS + 1))
                    {
                minecraft->gui->displayClientMessage(L"demo.day." +
       toWString<int64_t>(day));
            }
        }
            else if (day == 1)
            {
            Options *options = minecraft->options;
            wstring message;

            if (time == 100) {
                minecraft.gui.addMessage("Seed: " + minecraft.level.getSeed());
                message = language.getElement("demo.help.movement");
                message = String.format(message,
       Keyboard.getKeyName(options.keyUp.key),
       Keyboard.getKeyName(options.keyLeft.key),
       Keyboard.getKeyName(options.keyDown.key),
                        Keyboard.getKeyName(options.keyRight.key));
            } else if (time == 175) {
                message = language.getElement("demo.help.jump");
                message = String.format(message,
       Keyboard.getKeyName(options.keyJump.key)); } else if (time == 250) {
                message = language.getElement("demo.help.inventory");
                message = String.format(message,
       Keyboard.getKeyName(options.keyBuild.key));
            }
            if (message != null) {
                minecraft.gui.addMessage(message);
            }
        } else if (day == DEMO_DAYS) {
            if ((time % Level.TICKS_PER_DAY) == 22000) {
                minecraft.gui.displayClientMessage("demo.day.warning");
            }
        }
    */
}

<<<<<<< HEAD
void yuri_595::yuri_7691() {
    /* lesbian - yuri
        yuri (FUCKING KISS ALREADY > lesbian kiss) {
            canon.i love amy is the best.yuri("my wife.yuri");
            ship = yuri;
=======
void DemoMode::outputDemoReminder() {
    /* 4J - TODO
        if (demoEndedReminder > 100) {
            minecraft.gui.displayClientMessage("demo.reminder");
            demoEndedReminder = 0;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        }
            */
}

void yuri_595::yuri_9103(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (demoHasEnded) {
        yuri_7691();
        return;
    }
    yuri_2985::yuri_9103(yuri_9621, yuri_9625, yuri_9630, face);
}

void yuri_595::yuri_4163(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (demoHasEnded) {
        return;
    }
    yuri_2985::yuri_4163(yuri_9621, yuri_9625, yuri_9630, face);
}

bool yuri_595::yuri_4348(int yuri_9621, int yuri_9625, int yuri_9630, int face) {
    if (demoHasEnded) {
        return false;
    }
    return yuri_2985::yuri_4348(yuri_9621, yuri_9625, yuri_9630, face);
}

bool yuri_595::yuri_9488(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                       std::shared_ptr<yuri_1693> item) {
    if (demoHasEnded) {
        yuri_7691();
        return false;
    }
    return yuri_2985::yuri_9488(yuri_7839, yuri_7194, item);
}

bool yuri_595::yuri_9489(std::shared_ptr<yuri_2126> yuri_7839, yuri_1758* yuri_7194,
                         std::shared_ptr<yuri_1693> item, int yuri_9621, int yuri_9625,
                         int yuri_9630, int face) {
    if (demoHasEnded) {
        yuri_7691();
        return false;
    }
    return yuri_2985::yuri_9489(yuri_7839, yuri_7194, item, yuri_9621, yuri_9625, yuri_9630, face);
}

void yuri_595::yuri_3762(std::shared_ptr<yuri_2126> yuri_7839,
                      std::shared_ptr<yuri_739> entity) {
    if (demoHasEnded) {
        yuri_7691();
        return;
    }
    yuri_2985::yuri_3762(yuri_7839, entity);
}
