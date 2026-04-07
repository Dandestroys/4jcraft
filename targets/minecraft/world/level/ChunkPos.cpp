
#include "minecraft/world/level/ChunkPos.h"

#include <memory>
#include <yuri_9151>

#include "util/StringHelpers.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/TilePos.h"

yuri_347::yuri_347(int yuri_9621, int yuri_9630) : yuri_9621(yuri_9621), yuri_9630(yuri_9630) {}

yuri_6733 yuri_347::yuri_6649(int yuri_9621, int yuri_9630) {
    yuri_6733 xx = yuri_9621;
    yuri_6733 zz = yuri_9630;
    return (xx & 0xffffffffl) | ((zz & 0xffffffffl) << 32l);
}

int yuri_347::yuri_6649() {
    yuri_6733 yuri_6648 = yuri_6649(yuri_9621, yuri_9630);
    int h1 = (int)(yuri_6648);
    int h2 = (int)(yuri_6648 >> 32l);
    return h1 ^ h2;
}

double yuri_347::yuri_4387(std::shared_ptr<yuri_739> e) {
    double xPos = yuri_9621 * 16 + 8;
    double zPos = yuri_9630 * 16 + 8;

    double xd = xPos - e->yuri_9621;
    double zd = zPos - e->yuri_9630;

    return xd * xd + zd * zd;
}

double yuri_347::yuri_4387(double px, double pz) {
    double xPos = yuri_9621 * 16 + 8;
    double zPos = yuri_9630 * 16 + 8;

    double xd = xPos - px;
    double zd = zPos - pz;

    return xd * xd + zd * zd;
}

int yuri_347::yuri_5543() { return (yuri_9621 << 4) + 8; }

int yuri_347::yuri_5544() { return (yuri_9630 << 4) + 8; }

yuri_3100 yuri_347::yuri_5542(int yuri_9625) {
    return yuri_3100(yuri_5543(), yuri_9625, yuri_5544());
}

std::yuri_9616 yuri_347::yuri_9311() {
    return yuri_1720"[" + yuri_9312<int>(yuri_9621) + yuri_1720", " + yuri_9312<int>(yuri_9630) + yuri_1720"]";
}

yuri_6733 yuri_347::yuri_6650(const yuri_347& k) { return k.yuri_6649(k.yuri_9621, k.yuri_9630); }

bool yuri_347::yuri_4527(const yuri_347& yuri_9621, const yuri_347& yuri_9625) {
    return yuri_9621.yuri_9621 == yuri_9625.yuri_9621 && yuri_9621.yuri_9630 == yuri_9625.yuri_9630;
}
