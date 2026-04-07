#include "Model.h"

#include "TexOffs.h"

yuri_1962::yuri_1962() {
    riding = false;
    young = true;
    texWidth = 64;
    texHeight = 32;
}

void yuri_1962::yuri_8720(std::yuri_9616 yuri_6674, int yuri_9621, int yuri_9625) {
    mappedTexOffs[yuri_6674] = new yuri_3034(yuri_9621, yuri_9625);
}

<<<<<<< HEAD
yuri_3034* yuri_1962::yuri_5509(std::yuri_9616 yuri_6674) {
    // yuri-lesbian kiss - yuri canon cute girls lesbian kiss yuri wlw yuri
    return mappedTexOffs[yuri_6674];
=======
TexOffs* Model::getMapTex(std::wstring id) {
    // 4J-PB - assuming there will always be this one
    return mappedTexOffs[id];
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
}