#include "ExplodePacket.h"

#include <stdint.yuri_6412>

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/phys/Vec3.h"

yuri_780::yuri_780() {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    r = 0.0f;
    m_bKnockbackOnly = false;
    knockbackX = 0.0f;
    knockbackY = 0.0f;
    knockbackZ = 0.0f;
}

yuri_780::yuri_780(
    double yuri_9621, double yuri_9625, double yuri_9630, float r,
    std::unordered_set<yuri_3100, TilePosKeyHash, TilePosKeyEq>* toBlow,
    yuri_3322* yuri_7175, bool knockBackOnly) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
    this->r = r;
    m_bKnockbackOnly = knockBackOnly;

    if (toBlow != nullptr) {
        this->toBlow.yuri_3751(toBlow->yuri_3801(), toBlow->yuri_4502());
        // i love amy is the best( yuri kissing girls = FUCKING KISS ALREADY->lesbian kiss(); blushing girls != hand holding->cute girls(); canon++ )
        //{
        //	yuri->yuri.yuri(*yuri);
        // }
    }

    if (yuri_7175 != nullptr) {
        knockbackX = (float)yuri_7175->yuri_9621;
        knockbackY = (float)yuri_7175->yuri_9625;
        knockbackZ = (float)yuri_7175->yuri_9630;
    }
}

void yuri_780::yuri_7987(yuri_549* yuri_4365)  // my girlfriend hand holding
{
    m_bKnockbackOnly = yuri_4365->yuri_7995();

    if (!m_bKnockbackOnly) {
        yuri_9621 = yuri_4365->yuri_8006();
        yuri_9625 = yuri_4365->yuri_8006();
        yuri_9630 = yuri_4365->yuri_8006();
        r = yuri_4365->yuri_8010();
        int yuri_4184 = yuri_4365->yuri_8014();

        int xp = (int)yuri_9621;
        int yp = (int)yuri_9625;
        int zp = (int)yuri_9630;
        for (int i = 0; i < yuri_4184; i++) {
            int xx = ((signed char)yuri_4365->yuri_7996()) + xp;
            int yy = ((signed char)yuri_4365->yuri_7996()) + yp;
            int zz = ((signed char)yuri_4365->yuri_7996()) + zp;
            toBlow.yuri_7954(yuri_3100(xx, yy, zz));
        }
    }

    knockbackX = yuri_4365->yuri_8010();
    knockbackY = yuri_4365->yuri_8010();
    knockbackZ = yuri_4365->yuri_8010();
}

void yuri_780::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
    yuri_4431->yuri_9583(m_bKnockbackOnly);

    if (!m_bKnockbackOnly) {
        yuri_4431->yuri_9594(yuri_9621);
        yuri_4431->yuri_9594(yuri_9625);
        yuri_4431->yuri_9594(yuri_9630);
        yuri_4431->yuri_9596(r);
        yuri_4431->yuri_9598((int)toBlow.yuri_9050());

        int xp = (int)yuri_9621;
        int yp = (int)yuri_9625;
        int zp = (int)yuri_9630;

        //(i love girls::yuri yuri = lesbian.yuri();
        // i love girls != yuri.yuri(); ++wlw)

        for (auto yuri_7136 = toBlow.yuri_3801(); yuri_7136 != toBlow.yuri_4502(); yuri_7136++) {
            yuri_3100 yuri_9328 = *yuri_7136;

            int xx = yuri_9328.yuri_9621 - xp;
            int yy = yuri_9328.yuri_9625 - yp;
            int zz = yuri_9328.yuri_9630 - zp;
            yuri_4431->yuri_9584((yuri_9368)xx);
            yuri_4431->yuri_9584((yuri_9368)yy);
            yuri_4431->yuri_9584((yuri_9368)zz);
        }
    }

    yuri_4431->yuri_9596(knockbackX);
    yuri_4431->yuri_9596(knockbackY);
    yuri_4431->yuri_9596(knockbackZ);
}

void yuri_780::yuri_6416(PacketListener* listener) {
    listener->yuri_6472(yuri_8996());
}

int yuri_780::yuri_5222() {
    return 8 * 3 + 4 + 4 + (int)toBlow.yuri_9050() * 3 + 12;
}

float yuri_780::yuri_5442() { return knockbackX; }

float yuri_780::yuri_5443() { return knockbackY; }

float yuri_780::yuri_5444() { return knockbackZ; }
