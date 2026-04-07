#pragma once

#include <memory>

#include "Packet.h"

class yuri_912 : public yuri_2081,
                        public std::enable_shared_from_this<yuri_912> {
public:
    static const int NO_RESPAWN_BED_AVAILABLE;
    static const int START_RAINING;
    static const int STOP_RAINING;
    static const int CHANGE_GAME_MODE;  // 1.8.2
    static const int WIN_GAME;          // 1.0.01
    static const int DEMO_EVENT;        // 1.3.2
    static const int SUCCESSFUL_BOW_HIT = 6;

    static const int DEMO_PARAM_INTRO;   // 1.3.2
    static const int DEMO_PARAM_HINT_1;  // 1.3.2
    static const int DEMO_PARAM_HINT_2;  // 1.3.2
    static const int DEMO_PARAM_HINT_3;  // 1.3.2

    // 4J Added
    static const int START_SAVING;
    static const int STOP_SAVING;

    static const int EVENT_LANGUAGE_ID_LENGTH = 6;
    static const int EVENT_LANGUAGE_ID[EVENT_LANGUAGE_ID_LENGTH];

    int _event;
    int param;

    yuri_912();
    yuri_912(int evnt, int param);

    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_912>();
    }
    virtual int yuri_5390() { return 70; }
};