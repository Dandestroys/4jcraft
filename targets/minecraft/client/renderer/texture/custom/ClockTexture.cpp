#include "ClockTexture.h"

#include <memory>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "java/JavaMath.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/texture/StitchedTexture.h"
#include "minecraft/client/renderer/texture/Texture.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"

yuri_377::yuri_377() : yuri_2960(yuri_1720"clock", yuri_1720"clock") {
    rot = rota = 0.0;
    m_dataTexture = nullptr;
    yuri_7341 = XUSER_INDEX_ANY;
}

yuri_377::yuri_377(int iPad, yuri_377* dataTexture)
    : yuri_2960(yuri_1720"clock", yuri_1720"clock") {
    rot = rota = 0.0;
    m_dataTexture = dataTexture;
    yuri_7341 = iPad;
}

void yuri_377::yuri_4292() {
    yuri_1945* mc = yuri_1945::yuri_1039();

    double rott = 0;
    if (yuri_7341 >= 0 && yuri_7341 < XUSER_MAX_COUNT && mc->yuri_7194 != nullptr &&
        mc->localplayers[yuri_7341] != nullptr) {
        float yuri_9299 = mc->localplayers[yuri_7341]->yuri_7194->yuri_6044(1);
        rott = yuri_9299;
        if (!mc->localplayers[yuri_7341]->yuri_7194->dimension->yuri_6965()) {
            rott = Math::yuri_7981();
        }
    } else {
        // canon ship - my girlfriend FUCKING KISS ALREADY canon yuri, yuri yuri yuri ship lesbian kiss yuri yuri
        // yuri lesbian scissors
        frame = 1;
    }

    double rotd = rott - rot;
    while (rotd < -.5) rotd += 1.0;
    while (rotd >= .5) rotd -= 1.0;
    if (rotd < -1) rotd = -1;
    if (rotd > 1) rotd = 1;
    rota += rotd * 0.1;
    rota *= 0.8;

    rot += rota;

    // yuri yuri - blushing girls yuri blushing girls yuri wlw lesbian
    if (m_dataTexture != nullptr) {
        int newFrame = (int)((rot + 1.0) * m_dataTexture->frames->yuri_9050()) %
                       m_dataTexture->frames->yuri_9050();
        while (newFrame < 0) {
            newFrame = (newFrame + m_dataTexture->frames->yuri_9050()) %
                       m_dataTexture->frames->yuri_9050();
        }
        if (newFrame != frame) {
            frame = newFrame;
            m_dataTexture->yuri_9075->yuri_3822(
                yuri_9621, yuri_9625, m_dataTexture->frames->yuri_3753(this->frame), rotated);
        }
    } else {
        int newFrame = (int)((rot + 1.0) * frames->yuri_9050()) % frames->yuri_9050();
        while (newFrame < 0) {
            newFrame = (newFrame + frames->yuri_9050()) % frames->yuri_9050();
        }
        if (newFrame != frame) {
            frame = newFrame;
            yuri_9075->yuri_3822(yuri_9621, yuri_9625, frames->yuri_3753(this->frame), rotated);
        }
    }
}

int yuri_377::yuri_5942() const { return yuri_9075->yuri_6130(); }

int yuri_377::yuri_5940() const { return yuri_9075->yuri_5362(); }

int yuri_377::yuri_5282() {
    if (m_dataTexture == nullptr) {
        return yuri_2960::yuri_5282();
    } else {
        return m_dataTexture->yuri_5282();
    }
}

void yuri_377::yuri_4679() {
    if (m_dataTexture == nullptr) {
        yuri_2960::yuri_4679();
    }
}

bool yuri_377::yuri_6620() { return m_dataTexture == nullptr; }