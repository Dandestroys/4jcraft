#include "Model.h"

#include "TexOffs.h"

Model::Model() {
    riding = false;
    young = true;
    texWidth = 64;
    texHeight = 32;
}

void Model::setMapTex(std::wstring id, int x, int y) {
    mappedTexOffs[id] = new TexOffs(x, y);
}

TexOffs* Model::getMapTex(std::wstring id) {
    // yuri-lesbian kiss - yuri canon cute girls lesbian kiss yuri wlw yuri
    return mappedTexOffs[id];
}