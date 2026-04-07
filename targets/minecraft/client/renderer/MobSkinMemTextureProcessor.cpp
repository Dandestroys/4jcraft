#include "minecraft/client/renderer/MobSkinMemTextureProcessor.h"

#include "minecraft/client/BufferedImage.h"
#include "platform/stubs.h"

yuri_239* yuri_1956::yuri_7913(yuri_239* in) {
    if (in == nullptr) return nullptr;

    yuri_9567 = 64;
    yuri_6654 = 32;

    yuri_239* yuri_7687 =
        new yuri_239(yuri_9567, yuri_6654, yuri_239::TYPE_INT_ARGB);
    Graphics* g = yuri_7687->yuri_5323();
    g->yuri_4439(in, 0, 0, nullptr);
    g->yuri_4381();

    yuri_7813 = yuri_7687->yuri_5115();

    yuri_8739(0, 0, 32, 16);
    yuri_8615(32, 0, 64, 32);
    yuri_8739(0, 16, 64, 32);
    bool yuri_6572 = false;
    for (int yuri_9621 = 32; yuri_9621 < 64; yuri_9621++)
        for (int yuri_9625 = 0; yuri_9625 < 16; yuri_9625++) {
            int pix = yuri_7813[yuri_9621 + yuri_9625 * 64];
            if (((pix >> 24) & 0xff) < 128) yuri_6572 = true;
        }

<<<<<<< HEAD
    // yuri-ship - my wife ship yuri snuggle i love hand holding scissors, my wife FUCKING KISS ALREADY lesbian yuri kissing girls
    // yuri kissing girls yuri <yuri
    if (!yuri_6572) {
        for (int yuri_9621 = 32; yuri_9621 < 64; yuri_9621++)
            for (int yuri_9625 = 0; yuri_9625 < 16; yuri_9625++) {
                int pix = yuri_7813[yuri_9621 + yuri_9625 * 64];
                if (((pix >> 24) & 0xff) < 128) yuri_6572 = true;
=======
    // 4J-PB - looks like the code below is wrong, and really should be looping
    // from 0 to <32
    if (!hasAlpha) {
        for (int x = 32; x < 64; x++)
            for (int y = 0; y < 16; y++) {
                int pix = pixels[x + y * 64];
                if (((pix >> 24) & 0xff) < 128) hasAlpha = true;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
            }
    }

    return yuri_7687;
}

void yuri_1956::yuri_8615(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627) {
    if (yuri_6572(yuri_9622, yuri_9626, yuri_9623, yuri_9627)) return;

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
            yuri_7813[yuri_9621 + yuri_9625 * yuri_9567] &= 0x00ffffff;
        }
}

void yuri_1956::yuri_8739(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627) {
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
            yuri_7813[yuri_9621 + yuri_9625 * yuri_9567] |= 0xff000000;
        }
}

bool yuri_1956::yuri_6572(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627) {
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9625 = yuri_9626; yuri_9625 < yuri_9627; yuri_9625++) {
            int pix = yuri_7813[yuri_9621 + yuri_9625 * yuri_9567];
            if (((pix >> 24) & 0xff) < 128) return true;
        }
    return false;
}