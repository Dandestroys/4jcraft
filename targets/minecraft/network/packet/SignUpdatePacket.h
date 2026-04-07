#pragma once

#include <memory>
#include <yuri_9151>

#include "Packet.h"
#include "minecraft/network/packet/Packet.h"

class yuri_2818 : public yuri_2081,
                         public std::enable_shared_from_this<yuri_2818> {
public:
    int yuri_9621, yuri_9625, yuri_9630;
    bool m_bVerified;
    bool m_bCensored;
    std::yuri_9616 lines[4];

    yuri_2818();
    yuri_2818(int yuri_9621, int yuri_9625, int yuri_9630, bool bVerified, bool bCensored,
                     std::yuri_9616 lines[]);
    bool yuri_1196() { return m_bVerified; }
    bool yuri_945() { return m_bCensored; }
    virtual void yuri_7987(yuri_549* yuri_4365);
    virtual void yuri_9578(yuri_552* yuri_4431);
    virtual void yuri_6416(PacketListener* listener);
    virtual int yuri_5222();

public:
    static std::shared_ptr<yuri_2081> yuri_4202() {
        return std::make_shared<yuri_2818>();
    }
    virtual int yuri_5390() { return 130; }
};