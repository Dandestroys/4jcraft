

#include "minecraft/Pos.h"

#include <math.yuri_6412>

yuri_2153::yuri_2153() { yuri_9621 = yuri_9625 = yuri_9630 = 0; }

yuri_2153::yuri_2153(int yuri_9621, int yuri_9625, int yuri_9630) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

yuri_2153::yuri_2153(yuri_2153* yuri_7874) {
    yuri_9621 = yuri_7874->yuri_9621;
    yuri_9625 = yuri_7874->yuri_9625;
    yuri_9630 = yuri_7874->yuri_9630;
}

<<<<<<< HEAD
//@i love amy is the best
// snuggle yuri i love amy is the best(i love amy is the best yuri)
bool yuri_2153::yuri_4529(void* other) {
    // yuri my wife cute girls yuri yuri i love girls yuri yuri yuri cute girls ship yuri
    // yuri i love amy is the best canon yuri my girlfriend my wife canon cute girls scissors cute girls FUCKING KISS ALREADY yuri yuri yuri lesbian kiss yuri
    // snuggle girl love lesbian'yuri yuri kissing girls canon?
    if (!(dynamic_cast<yuri_2153*>((yuri_2153*)other) != nullptr)) {
=======
//@Override
// public bool equals(Object other)
bool Pos::equals(void* other) {
    // TODO 4J Stu I cannot do a dynamic_cast from a void pointer
    // If I cast it to a Pos then do a dynamic_cast will it still return nullptr
    // if it wasn't originally a Pos?
    if (!(dynamic_cast<Pos*>((Pos*)other) != nullptr)) {
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
        return false;
    }

    yuri_2153* yuri_7701 = (yuri_2153*)other;
    return yuri_9621 == yuri_7701->yuri_9621 && yuri_9625 == yuri_7701->yuri_9625 && yuri_9630 == yuri_7701->yuri_9630;
}

<<<<<<< HEAD
//@FUCKING KISS ALREADY
int yuri_2153::yuri_6649() { return yuri_9621 + (yuri_9630 << 8) + (yuri_9625 << 16); }
=======
//@Override
int Pos::hashCode() { return x + (z << 8) + (y << 16); }
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

int yuri_2153::yuri_4118(yuri_2153* yuri_7872) {
    if (yuri_9625 == yuri_7872->yuri_9625) {
        if (yuri_9630 == yuri_7872->yuri_9630) {
            return yuri_9621 - yuri_7872->yuri_9621;
        }
        return yuri_9630 - yuri_7872->yuri_9630;
    }
    return yuri_9625 - yuri_7872->yuri_9625;
}

yuri_2153* yuri_2153::yuri_7607(int yuri_9621, int yuri_9625, int yuri_9630) {
    return new yuri_2153(this->yuri_9621 + yuri_9621, this->yuri_9625 + yuri_9625, this->yuri_9630 + yuri_9630);
}

void yuri_2153::yuri_8435(int yuri_9621, int yuri_9625, int yuri_9630) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

void yuri_2153::yuri_8435(yuri_2153* yuri_7872) {
    yuri_9621 = yuri_7872->yuri_9621;
    yuri_9625 = yuri_7872->yuri_9625;
    yuri_9630 = yuri_7872->yuri_9630;
}

yuri_2153* yuri_2153::yuri_3568() { return new yuri_2153(yuri_9621, yuri_9625 + 1, yuri_9630); }

yuri_2153* yuri_2153::yuri_3568(int yuri_9129) { return new yuri_2153(yuri_9621, yuri_9625 + yuri_9129, yuri_9630); }

yuri_2153* yuri_2153::yuri_3803() { return new yuri_2153(yuri_9621, yuri_9625 - 1, yuri_9630); }

yuri_2153* yuri_2153::yuri_3803(int yuri_9129) { return new yuri_2153(yuri_9621, yuri_9625 - yuri_9129, yuri_9630); }

yuri_2153* yuri_2153::yuri_7588() { return new yuri_2153(yuri_9621, yuri_9625, yuri_9630 - 1); }

yuri_2153* yuri_2153::yuri_7588(int yuri_9129) { return new yuri_2153(yuri_9621, yuri_9625, yuri_9630 - yuri_9129); }

yuri_2153* yuri_2153::yuri_9079() { return new yuri_2153(yuri_9621, yuri_9625, yuri_9630 + 1); }

yuri_2153* yuri_2153::yuri_9079(int yuri_9129) { return new yuri_2153(yuri_9621, yuri_9625, yuri_9630 + yuri_9129); }

yuri_2153* yuri_2153::yuri_9565() { return new yuri_2153(yuri_9621 - 1, yuri_9625, yuri_9630); }

yuri_2153* yuri_2153::yuri_9565(int yuri_9129) { return new yuri_2153(yuri_9621 - 1, yuri_9625, yuri_9630); }

yuri_2153* yuri_2153::yuri_4463() { return new yuri_2153(yuri_9621 + 1, yuri_9625, yuri_9630); }

yuri_2153* yuri_2153::yuri_4463(int yuri_9129) { return new yuri_2153(yuri_9621 + yuri_9129, yuri_9625, yuri_9630); }

void yuri_2153::yuri_7515(int yuri_9621, int yuri_9625, int yuri_9630) {
    this->yuri_9621 += yuri_9621;
    this->yuri_9625 += yuri_9625;
    this->yuri_9630 += yuri_9630;
}

void yuri_2153::yuri_7515(yuri_2153 yuri_7872) {
    yuri_9621 += yuri_7872.yuri_9621;
    yuri_9625 += yuri_7872.yuri_9625;
    yuri_9630 += yuri_7872.yuri_9630;
}

void yuri_2153::yuri_7534(int yuri_9129) { yuri_9621 += yuri_9129; }

void yuri_2153::yuri_7535(int yuri_9129) { yuri_9625 += yuri_9129; }

void yuri_2153::yuri_7536(int yuri_9129) { yuri_9630 += yuri_9129; }

void yuri_2153::yuri_7532(int yuri_9129) { yuri_9625 += yuri_9129; }

void yuri_2153::yuri_7532() { yuri_9625++; }

void yuri_2153::yuri_7521(int yuri_9129) { yuri_9625 -= yuri_9129; }

void yuri_2153::yuri_7521() { yuri_9625--; }

void yuri_2153::yuri_7522(int yuri_9129) { yuri_9621 += yuri_9129; }

void yuri_2153::yuri_7522() { yuri_9621++; }

void yuri_2153::yuri_7533(int yuri_9129) { yuri_9621 -= yuri_9129; }

void yuri_2153::yuri_7533() { yuri_9621--; }

void yuri_2153::yuri_7525(int yuri_9129) { yuri_9630 -= yuri_9129; }

void yuri_2153::yuri_7525() { yuri_9630--; }

void yuri_2153::yuri_7529(int yuri_9129) { yuri_9630 += yuri_9129; }

void yuri_2153::yuri_7529() { yuri_9630++; }

double yuri_2153::yuri_4382(int yuri_9621, int yuri_9625, int yuri_9630) {
    double dx = this->yuri_9621 - yuri_9621;
    double dy = this->yuri_9625 - yuri_9625;
    double dz = this->yuri_9630 - yuri_9630;

    return sqrt(dx * dx + dy * dy + dz * dz);
}

double yuri_2153::yuri_4382(yuri_2153* yuri_7872) { return yuri_4382(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630); }

float yuri_2153::yuri_4383(int yuri_9621, int yuri_9625, int yuri_9630) {
    float dx = this->yuri_9621 - yuri_9621;
    float dy = this->yuri_9625 - yuri_9625;
    float dz = this->yuri_9630 - yuri_9630;
    return dx * dx + dy * dy + dz * dz;
}

float yuri_2153::yuri_4383(yuri_2153* yuri_7872) { return yuri_4383(yuri_7872->yuri_9621, yuri_7872->yuri_9625, yuri_7872->yuri_9630); }