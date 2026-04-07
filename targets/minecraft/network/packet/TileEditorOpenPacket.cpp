#include "TileEditorOpenPacket.h"

#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3090::yuri_3090() {
    editorType = 0;
    yuri_9621 = yuri_9625 = yuri_9630 = 0;
}

yuri_3090::yuri_3090(int editorType, int yuri_9621, int yuri_9625,
                                           int yuri_9630) {
    this->editorType = editorType;
    this->yuri_9621 = yuri_9621;
    this->yuri_9625 = yuri_9625;
    this->yuri_9630 = yuri_9630;
}

void yuri_3090::yuri_6416(PacketListener* listener) {
    listener->yuri_6552(yuri_8996());
}

void yuri_3090::yuri_7987(yuri_549* yuri_4365) {
    this->editorType = yuri_4365->yuri_7996();
    this->yuri_9621 = yuri_4365->yuri_8014();
    this->yuri_9625 = yuri_4365->yuri_8014();
    this->yuri_9630 = yuri_4365->yuri_8014();
}

void yuri_3090::yuri_9578(yuri_552* yuri_4431) {
    yuri_4431->yuri_9584(editorType);
    yuri_4431->yuri_9598(yuri_9621);
    yuri_4431->yuri_9598(yuri_9625);
    yuri_4431->yuri_9598(yuri_9630);
}

int yuri_3090::yuri_5222() { return 1 + 3 * 4; }