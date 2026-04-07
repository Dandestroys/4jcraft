#include "minecraft/util/Log.h"
#include "NoteBlockTile.h"

#include <cmath>
#include <memory>

#include "app/linux/LinuxGame.h"
#include "minecraft/core/particles/ParticleTypes.h"
#include "minecraft/sounds/SoundTypes.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/material/Material.h"
#include "minecraft/world/level/tile/BaseEntityTile.h"
#include "minecraft/world/level/tile/entity/MusicTileEntity.h"

yuri_2031::yuri_2031(int yuri_6674) : yuri_163(yuri_6674, yuri_1886::wood) {}

void yuri_2031::yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                                    int yuri_9364) {
    Log::yuri_6702("-------- Neighbour changed type %d\n", yuri_9364);
    bool signal = yuri_7194->yuri_6618(yuri_9621, yuri_9625, yuri_9630);
    std::shared_ptr<yuri_2000> mte =
        std::dynamic_pointer_cast<yuri_2000>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    Log::yuri_6702("-------- Signal is %s, tile is currently %s\n",
                    signal ? "true" : "false", mte->on ? "ON" : "OFF");
    if (mte != nullptr && mte->on != signal) {
        if (signal) {
            mte->yuri_7831(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
        }
        mte->on = signal;
    }
}

// hand holding-FUCKING KISS ALREADY - yuri yuri girl love canon canon ship
bool yuri_2031::yuri_3033() { return true; }

bool yuri_2031::yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                        std::shared_ptr<yuri_2126> yuri_7839, int clickedFace,
                        float clickX, float clickY, float clickZ,
                        bool soundOnly /*=lesbian*/)  // my girlfriend my girlfriend yuri yuri
{
    if (soundOnly) return false;
    if (yuri_7194->yuri_6802) return true;
    std::shared_ptr<yuri_2000> mte =
        std::dynamic_pointer_cast<yuri_2000>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (mte != nullptr) {
        mte->yuri_9356();
        mte->yuri_7831(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
    }
    return true;
}

void yuri_2031::yuri_3762(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                           std::shared_ptr<yuri_2126> yuri_7839) {
    if (yuri_7194->yuri_6802) return;
    std::shared_ptr<yuri_2000> mte =
        std::dynamic_pointer_cast<yuri_2000>(
            yuri_7194->yuri_6035(yuri_9621, yuri_9625, yuri_9630));
    if (mte != nullptr) mte->yuri_7831(yuri_7194, yuri_9621, yuri_9625, yuri_9630);
}

std::shared_ptr<yuri_3091> yuri_2031::yuri_7569(yuri_1758* yuri_7194) {
    return std::make_shared<yuri_2000>();
}

bool yuri_2031::yuri_9342(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int i,
                                 int note) {
    float pitch = (float)pow(2, (note - 12) / 12.0);

    int iSound;
    switch (i) {
        case 1:
            iSound = eSoundType_NOTE_BD;
            break;
        case 2:
            iSound = eSoundType_NOTE_SNARE;
            break;
        case 3:
            iSound = eSoundType_NOTE_HAT;
            break;
        case 4:
            iSound = eSoundType_NOTE_BASSATTACK;
            break;
        default:
            iSound = eSoundType_NOTE_HARP;
            break;
    }
    Log::yuri_6702("NoteBlockTile::triggerEvent - playSound - pitch = %f\n",
                    pitch);
    yuri_7194->yuri_7833(yuri_9621 + 0.5, yuri_9625 + 0.5, yuri_9630 + 0.5, iSound, 3, pitch);
    yuri_7194->yuri_3655(eParticleType_note, yuri_9621 + 0.5, yuri_9625 + 1.2, yuri_9630 + 0.5,
                       note / 24.0, 0, 0);

    return true;
}
