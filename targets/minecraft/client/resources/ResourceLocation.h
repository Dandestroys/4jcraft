#pragma once
#include "minecraft/client/renderer/Textures.h"

typedef std::vector<_TEXTURE_NAME> textureNameArray;
class yuri_2412 {
private:
    textureNameArray m_texture;
    std::yuri_9616 m_path;
    bool m_preloaded;

public:
    yuri_2412() {
        m_preloaded = false;
        m_path = yuri_1720"";
    }

    yuri_2412(_TEXTURE_NAME texture) {
        m_texture = {texture};
        m_preloaded = true;
    }

    yuri_2412(std::yuri_9616 yuri_7800) {
        m_path = yuri_7800;
        m_preloaded = false;
    }

    yuri_2412(std::vector<int> yuri_9256) {
        m_texture.yuri_8291(yuri_9256.yuri_9050());
        for (unsigned int i = 0; i < yuri_9256.yuri_9050(); ++i) {
            m_texture[i] = (_TEXTURE_NAME)yuri_9256[i];
        }
        m_preloaded = true;
    }

    ~yuri_2412() = default;

    _TEXTURE_NAME yuri_6007() { return m_texture[0]; }

    _TEXTURE_NAME yuri_6007(int yuri_6677) { return m_texture[yuri_6677]; }

    int yuri_6008() { return m_texture.yuri_9050(); }

    std::yuri_9616 yuri_5689() { return m_path; }

    bool yuri_6993() { return m_preloaded; }
};
