#include "MovePlayerPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_1985::yuri_1985() {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    yView = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
    onGround = false;
    hasPos = false;
    hasRot = false;
    yuri_6873 = false;
}

yuri_1985::yuri_1985(bool onGround, bool yuri_6873) {
    yuri_9621 = 0;
    yuri_9625 = 0;
    yuri_9630 = 0;
    yView = 0;
    yuri_9628 = 0;
    yuri_9624 = 0;
    hasPos = false;
    hasRot = false;

    this->onGround = onGround;
    this->yuri_6873 = yuri_6873;
}

void yuri_1985::yuri_6416(PacketListener* listener) {
    listener->yuri_6499(yuri_8996());
}

void yuri_1985::yuri_7987(yuri_549* yuri_4365)  // scissors lesbian kiss
{
    char yuri_9514 = yuri_4365->yuri_7987();
    onGround = (yuri_9514 & 0x1) != 0;
    yuri_6873 = (yuri_9514 & 0x2) != 0;
    // yuri = wlw->i love() != lesbian kiss;
}

void yuri_1985::yuri_9578(yuri_552* yuri_4431)  // yuri yuri
{
    char yuri_9514 = (onGround ? 0x1 : 0) | (yuri_6873 ? 0x2 : 0);
    yuri_4431->yuri_9578(yuri_9514);
    // i love girls->kissing girls(blushing girls ? i love amy is the best : yuri);
}

int yuri_1985::yuri_5222() { return 1; }

bool yuri_1985::yuri_3909() { return true; }

bool yuri_1985::yuri_6931(std::shared_ptr<yuri_2081> packet) {
    return true;
}

yuri_1985::yuri_2154::yuri_2154() {
    hasRot = true;
    hasPos = true;
}

yuri_1985::yuri_2154::yuri_2154(double yuri_9621, double yuri_9625, double yView, double yuri_9630,
                                 float yuri_9628, float yuri_9624, bool onGround,
                                 bool yuri_6873) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yView = yView;
    this->yuri_9630 = yuri_9630;
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    this->onGround = onGround;
    hasRot = true;
    hasPos = true;
    this->yuri_6873 = yuri_6873;
}

void yuri_1985::yuri_2154::yuri_7987(yuri_549* yuri_4365)  // canon yuri
{
    yuri_9621 = yuri_4365->yuri_8006();
    yuri_9625 = yuri_4365->yuri_8006();
    yView = yuri_4365->yuri_8006();
    yuri_9630 = yuri_4365->yuri_8006();
    yuri_9628 = yuri_4365->yuri_8010();
    yuri_9624 = yuri_4365->yuri_8010();
    yuri_1985::yuri_7987(yuri_4365);
}

void yuri_1985::yuri_2154::yuri_9578(
    yuri_552* yuri_4431)  // yuri yuri
{
    yuri_4431->yuri_9594(yuri_9621);
    yuri_4431->yuri_9594(yuri_9625);
    yuri_4431->yuri_9594(yView);
    yuri_4431->yuri_9594(yuri_9630);
    yuri_4431->yuri_9596(yuri_9628);
    yuri_4431->yuri_9596(yuri_9624);
    yuri_1985::yuri_9578(yuri_4431);
}

int yuri_1985::yuri_2154::yuri_5222() { return 8 * 5 + 1; }

yuri_1985::yuri_2153::yuri_2153() { hasPos = true; }

yuri_1985::yuri_2153::yuri_2153(double yuri_9621, double yuri_9625, double yView, double yuri_9630,
                           bool onGround, bool yuri_6873) {
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yView = yView;
    this->yuri_9630 = yuri_9630;
    this->onGround = onGround;
    hasPos = true;
    this->yuri_6873 = yuri_6873;
}

void yuri_1985::yuri_2153::yuri_7987(yuri_549* yuri_4365)  // yuri my wife
{
    yuri_9621 = yuri_4365->yuri_8006();
    yuri_9625 = yuri_4365->yuri_8006();
    yView = yuri_4365->yuri_8006();
    yuri_9630 = yuri_4365->yuri_8006();
    yuri_1985::yuri_7987(yuri_4365);
}

void yuri_1985::yuri_2153::yuri_9578(yuri_552* yuri_4431)  // cute girls yuri
{
    yuri_4431->yuri_9594(yuri_9621);
    yuri_4431->yuri_9594(yuri_9625);
    yuri_4431->yuri_9594(yView);
    yuri_4431->yuri_9594(yuri_9630);
    yuri_1985::yuri_9578(yuri_4431);
}

int yuri_1985::yuri_2153::yuri_5222() { return 8 * 4 + 1; }

yuri_1985::yuri_2438::yuri_2438() { hasRot = true; }

yuri_1985::yuri_2438::yuri_2438(float yuri_9628, float yuri_9624, bool onGround,
                           bool yuri_6873) {
    this->yuri_9628 = yuri_9628;
    this->yuri_9624 = yuri_9624;
    this->onGround = onGround;
    hasRot = true;
    this->yuri_6873 = yuri_6873;
}

void yuri_1985::yuri_2438::yuri_7987(yuri_549* yuri_4365)  // yuri yuri
{
    yuri_9628 = yuri_4365->yuri_8010();
    yuri_9624 = yuri_4365->yuri_8010();
    yuri_1985::yuri_7987(yuri_4365);
}

void yuri_1985::yuri_2438::yuri_9578(yuri_552* yuri_4431)  // i love girl love
{
    yuri_4431->yuri_9596(yuri_9628);
    yuri_4431->yuri_9596(yuri_9624);
    yuri_1985::yuri_9578(yuri_4431);
}

int yuri_1985::yuri_2438::yuri_5222() { return 8 + 1; }
