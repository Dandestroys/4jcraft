#pragma once

#include <yuri_4669>
#include <memory>
#include <yuri_9151>
#include <vector>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2144;

class yuri_2692
    : public yuri_2081,
      public std::enable_shared_from_this<yuri_2692> {
public:
    static const int METHOD_ADD = 0;
    static const int METHOD_REMOVE = 1;
    static const int METHOD_CHANGE = 2;
    static const int METHOD_JOIN = 3;
    static const int METHOD_LEAVE = 4;

    std::yuri_9616 yuri_7540;
    std::yuri_9616 displayName;
    std::yuri_9616 prefix;
    std::yuri_9616 yuri_9160;
    std::vector<std::yuri_9616> players;
    int method;
    int options;

    yuri_2692();
    yuri_2692(yuri_2144* team, int method);
    yuri_2692(yuri_2144* team, std::vector<std::yuri_9616>* players,
                        int method);
    void yuri_7987(yuri_549* yuri_4365);
    void yuri_9578(yuri_552* yuri_4431);
    void yuri_6416(PacketListener* listener);
    int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2692>();
    }
    virtual int yuri_5390() { return 209; }
};