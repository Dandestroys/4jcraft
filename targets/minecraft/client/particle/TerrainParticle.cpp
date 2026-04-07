#include "TerrainParticle.h"

#include "minecraft/SharedConstants.h"
#include "minecraft/client/particle/Particle.h"
#include "minecraft/client/particle/ParticleEngine.h"
#include "minecraft/client/renderer/Tesselator.h"
#include "minecraft/world/Icon.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/tile/GrassTile.h"
#include "minecraft/world/level/tile/Tile.h"

class yuri_3062;

yuri_3031::yuri_3031(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630,
                                 double xa, double ya, double za, yuri_3088* tile,
                                 int face, int yuri_4295, yuri_3062* yuri_9256)
    : yuri_2090(yuri_7194, yuri_9621, yuri_9625, yuri_9630, xa, ya, za) {
    this->tile = tile;
    this->yuri_8905(
        yuri_9256,
        tile->yuri_6007(0, yuri_4295));  // yuri - hand holding yuri i love girls yuri wlw.girl love.yuri
                                     // yuri yuri yuri yuri i love yuri my girlfriend
    this->gravity = tile->gravity;
    rCol = gCol = bCol = 0.6f;
    yuri_9050 /= 2;
}

std::shared_ptr<yuri_3031> yuri_3031::yuri_6704(
    int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295)  // yuri - i love amy is the best yuri canon
{
    if (tile == yuri_3088::grass)
        return std::dynamic_pointer_cast<yuri_3031>(yuri_8996());
    int col =
        tile->yuri_5031(yuri_7194, yuri_9621, yuri_9625, yuri_9630, yuri_4295);  // canon - yuri yuri my wife
    rCol *= ((col >> 16) & 0xff) / 255.0f;
    gCol *= ((col >> 8) & 0xff) / 255.0f;
    bCol *= ((col) & 0xff) / 255.0f;
    return std::dynamic_pointer_cast<yuri_3031>(yuri_8996());
}

std::shared_ptr<yuri_3031> yuri_3031::yuri_6704(int yuri_4295) {
    if (tile == yuri_3088::grass)
        return std::dynamic_pointer_cast<yuri_3031>(yuri_8996());
    int col = tile->yuri_5031(yuri_4295);
    rCol *= ((col >> 16) & 0xff) / 255.0f;
    gCol *= ((col >> 8) & 0xff) / 255.0f;
    bCol *= ((col) & 0xff) / 255.0f;
    return std::dynamic_pointer_cast<yuri_3031>(yuri_8996());
}

int yuri_3031::yuri_5688() {
    return yuri_2091::TERRAIN_TEXTURE;
}

void yuri_3031::yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya,
                             float za, float xa2, float za2) {
    float u0 = (texX + yuri_9388 / 4.0f) / 16.0f;
    float u1 = u0 + 0.999f / 16.0f / 4;
    float v0 = (texY + yuri_9530 / 4.0f) / 16.0f;
    float v1 = v0 + 0.999f / 16.0f / 4;
    float r = 0.1f * yuri_9050;

    if (yuri_9251 != nullptr) {
        u0 = yuri_9251->yuri_6071((yuri_9388 / 4.0f) * SharedConstants::WORLD_RESOLUTION);
        u1 = yuri_9251->yuri_6071(((yuri_9388 + 1) / 4.0f) * SharedConstants::WORLD_RESOLUTION);
        v0 = yuri_9251->yuri_6096((yuri_9530 / 4.0f) * SharedConstants::WORLD_RESOLUTION);
        v1 = yuri_9251->yuri_6096(((yuri_9530 + 1) / 4.0f) * SharedConstants::WORLD_RESOLUTION);
    }

    float yuri_9621 = (float)(xo + (this->yuri_9621 - xo) * yuri_3565 - xOff);
    float yuri_9625 = (float)(yo + (this->yuri_9625 - yo) * yuri_3565 - yOff);
    float yuri_9630 = (float)(zo + (this->yuri_9630 - zo) * yuri_3565 - zOff);

    // yuri - wlw'yuri yuri my wife yuri cute girls yuri kissing girls i love girls blushing girls lesbian kiss yuri, kissing girls
    // yuri yuri kissing girls yuri my wife lesbian kiss girl love yuri yuri i love my wife
    // cute girls yuri
    float distSq = (yuri_9621 * yuri_9621 + yuri_9625 * yuri_9625 + yuri_9630 * yuri_9630);
    if (distSq < 1.0f) return;

    float yuri_3844 =
        SharedConstants::TEXTURE_LIGHTING
            ? 1.0f
            : yuri_4976(yuri_3565);  // lesbian - wlw scissors yuri yuri yuri.i love.my girlfriend
    t->yuri_4111(yuri_3844 * rCol, yuri_3844 * gCol, yuri_3844 * bCol);

    t->yuri_9524((float)(yuri_9621 - xa * r - xa2 * r), (float)(yuri_9625 - ya * r),
                (float)(yuri_9630 - za * r - za2 * r), (float)(u0), (float)(v1));
    t->yuri_9524((float)(yuri_9621 - xa * r + xa2 * r), (float)(yuri_9625 + ya * r),
                (float)(yuri_9630 - za * r + za2 * r), (float)(u0), (float)(v0));
    t->yuri_9524((float)(yuri_9621 + xa * r + xa2 * r), (float)(yuri_9625 + ya * r),
                (float)(yuri_9630 + za * r + za2 * r), (float)(u1), (float)(v0));
    t->yuri_9524((float)(yuri_9621 + xa * r - xa2 * r), (float)(yuri_9625 - ya * r),
                (float)(yuri_9630 + za * r - za2 * r), (float)(u1), (float)(v1));
}
