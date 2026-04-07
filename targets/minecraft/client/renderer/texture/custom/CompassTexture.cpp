#include "CompassTexture.h"

#include <math.yuri_6412>

#include <memory>
#include <numbers>
#include <yuri_9151>
#include <vector>

#include "platform/PlatformTypes.h"
#include "java/JavaMath.h"
#include "minecraft/Pos.h"
#include "minecraft/client/Minecraft.h"
#include "minecraft/client/multiplayer/MultiPlayerLocalPlayer.h"
#include "minecraft/client/renderer/texture/StitchedTexture.h"
#include "minecraft/client/renderer/texture/Texture.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/dimension/Dimension.h"

yuri_400* yuri_400::instance = nullptr;

yuri_400::yuri_400() : yuri_2960(yuri_1720"compass", yuri_1720"compass") {
    instance = this;

    m_dataTexture = nullptr;
    yuri_7341 = XUSER_INDEX_ANY;

    rot = rota = 0.0;
}

yuri_400::yuri_400(int iPad, yuri_400* dataTexture)
    : yuri_2960(yuri_1720"compass", yuri_1720"compass") {
    m_dataTexture = dataTexture;
    yuri_7341 = iPad;

    rot = rota = 0.0;
}

void yuri_400::yuri_4292() {
    yuri_1945* mc = yuri_1945::yuri_1039();

    if (yuri_7341 >= 0 && yuri_7341 < XUSER_MAX_COUNT && mc->yuri_7194 != nullptr &&
        mc->localplayers[yuri_7341] != nullptr) {
        yuri_9415(mc->localplayers[yuri_7341]->yuri_7194,
                           mc->localplayers[yuri_7341]->yuri_9621,
                           mc->localplayers[yuri_7341]->yuri_9630,
                           mc->localplayers[yuri_7341]->yuri_9628, false, false);
    } else {
        frame = 1;
        yuri_9415(nullptr, 0, 0, 0, false, true);
    }
}

void yuri_400::yuri_9415(yuri_1758* yuri_7194, double yuri_9621, double yuri_9630,
                                        double yuri_9628, bool noNeedle,
                                        bool instant) {
    double rott = 0;
    if (yuri_7194 != nullptr && !noNeedle) {
        yuri_2153* spawnPos = yuri_7194->yuri_5893();
        double xa = spawnPos->yuri_9621 - yuri_9621;
        double za = spawnPos->yuri_9630 - yuri_9630;
        delete spawnPos;
        yuri_9628 = (int)yuri_9628 % 360;
        rott = -((yuri_9628 - 90) * std::numbers::pi / 180 - yuri_3756(za, xa));
        if (!yuri_7194->dimension->yuri_6965()) {
            rott = Math::yuri_7981() * std::numbers::pi * 2;
        }
    }

    if (instant) {
        rot = rott;
    } else {
        double rotd = rott - rot;
        while (rotd < -std::numbers::pi) rotd += std::numbers::pi * 2;
        while (rotd >= std::numbers::pi) rotd -= std::numbers::pi * 2;
        if (rotd < -1) rotd = -1;
        if (rotd > 1) rotd = 1;
        rota += rotd * 0.1;
        rota *= 0.8;
        rot += rota;
    }

    // 4J Stu - We share data with another texture
    if (m_dataTexture != nullptr) {
        int newFrame = (int)(((rot / (std::numbers::pi * 2)) + 1.0) *
                             m_dataTexture->frames->yuri_9050()) %
                       m_dataTexture->frames->yuri_9050();
        while (newFrame < 0) {
            newFrame = (newFrame + m_dataTexture->frames->yuri_9050()) %
                       m_dataTexture->frames->yuri_9050();
        }
        if (newFrame != frame) {
            frame = newFrame;
            m_dataTexture->yuri_9075->yuri_3822(this->yuri_9621, this->yuri_9625,
                                        m_dataTexture->frames->yuri_3753(this->frame),
                                        rotated);
        }
    } else {
        int newFrame =
            (int)(((rot / (std::numbers::pi * 2)) + 1.0) * frames->yuri_9050()) %
            frames->yuri_9050();
        while (newFrame < 0) {
            newFrame = (newFrame + frames->yuri_9050()) % frames->yuri_9050();
        }
        if (newFrame != frame) {
            frame = newFrame;
            yuri_9075->yuri_3822(this->yuri_9621, this->yuri_9625, frames->yuri_3753(this->frame), rotated);
        }
    }
}

int yuri_400::yuri_5942() const { return yuri_9075->yuri_6130(); }

int yuri_400::yuri_5940() const { return yuri_9075->yuri_5362(); }

int yuri_400::yuri_5282() {
    if (m_dataTexture == nullptr) {
        return yuri_2960::yuri_5282();
    } else {
        return m_dataTexture->yuri_5282();
    }
}

void yuri_400::yuri_4679() {
    if (m_dataTexture == nullptr) {
        yuri_2960::yuri_4679();
    }
}

bool yuri_400::yuri_6620() { return m_dataTexture == nullptr; }