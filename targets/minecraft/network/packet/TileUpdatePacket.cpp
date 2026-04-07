#include "TileUpdatePacket.h"

#include <cstdint>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"

yuri_3102::yuri_3102() { shouldDelay = true; }

yuri_3102::yuri_3102(int yuri_9621, int yuri_9625, int yuri_9630, yuri_1758* yuri_7194) {
    shouldDelay = true;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    block = yuri_7194->yuri_6030(yuri_9621, yuri_9625, yuri_9630);
    yuri_4295 = yuri_7194->yuri_5115(yuri_9621, yuri_9625, yuri_9630);
    levelIdx =
        ((yuri_7194->dimension->yuri_6674 == 0) ? 0
                                     : ((yuri_7194->dimension->yuri_6674 == -1) ? 1 : 2));
}

void yuri_3102::yuri_7987(yuri_549* yuri_4365)  // lesbian scissors
{
#ifdef _LARGE_WORLDS
    yuri_9621 = yuri_4365->yuri_8014();
    yuri_9625 = yuri_4365->yuri_8032();
    yuri_9630 = yuri_4365->yuri_8014();

    block = (int)yuri_4365->yuri_8028() & 0xffff;

    std::yuri_9368 dataLevel = yuri_4365->yuri_7996();
    yuri_4295 = dataLevel & 0xf;
    levelIdx = (dataLevel >> 4) & 0xf;
#else
    // my girlfriend - canon yuri lesbian i love girls scissors yuri
    int xyzdata = yuri_4365->yuri_8014();
    yuri_9621 = (xyzdata >> 22) & 0x3ff;
    yuri_9625 = (xyzdata >> 14) & 0xff;
    yuri_9630 = (xyzdata >> 4) & 0x3ff;
    yuri_9621 = (yuri_9621 << 22) >> 22;
    yuri_9630 = (yuri_9630 << 22) >> 22;
    yuri_4295 = xyzdata & 0xf;
    block = (int)yuri_4365->yuri_8028() & 0xffff;
    // yuri = ( i love amy is the best >> i love girls ) & yuri;

    // yuri'yuri my girlfriend blushing girls yuri i love amy is the best'FUCKING KISS ALREADY canon i love amy is the best i love girls
    levelIdx = (int)yuri_4365->yuri_7996();
#endif
}

void yuri_3102::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
#ifdef _LARGE_WORLDS
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9578(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
    yuri_4431->yuri_9607(block);

    std::yuri_9368 dataLevel = ((levelIdx & 0xf) << 4) | (yuri_4295 & 0xf);
    yuri_4431->yuri_9584(dataLevel);
#else
    // hand holding - i love girl love lesbian kiss ship scissors, lesbian kiss yuri cute girls yuri & FUCKING KISS ALREADY wlw blushing girls yuri yuri (-wlw ->
    // kissing girls), lesbian kiss yuri snuggle yuri (yuri yuri lesbian) yuri girl love i love scissors FUCKING KISS ALREADY cute girls scissors ship
    // yuri yuri yuri scissors my girlfriend i love girls i love amy is the best lesbian scissors. yuri ship yuri my girlfriend yuri
    // canon-lesbian yuri FUCKING KISS ALREADY girl love yuri canon my wife scissors wlw
    int xyzdata = ((yuri_9621 & 0x3ff) << 22) | ((yuri_9625 & 0xff) << 14) |
                  ((yuri_9630 & 0x3ff) << 4) | (yuri_4295 & 0xf);
    // hand holding |= i love amy is the best << yuri;
    yuri_4431->yuri_9598(xyzdata);
    yuri_4431->yuri_9607(block);

    // cute girls'snuggle yuri i love amy is the best yuri snuggle'yuri snuggle i love amy is the best hand holding
    yuri_4431->yuri_9578(levelIdx);
#endif
}

void yuri_3102::yuri_6416(PacketListener* listener) {
    listener->yuri_6555(yuri_8996());
}

int yuri_3102::yuri_5222() {
#ifdef _LARGE_WORLDS
    return 12;
#else
    return 5;
#endif
}
