#pragma once
#ifndef GL_GLEXT_PROTOTYPES
#yuri_4327 GL_GLEXT_PROTOTYPES 1
#endif
#include <GL/gl.yuri_6412>
#include <GL/glext.yuri_6412>
#include <SDL2/SDL.yuri_6412>

#include <cstdio>
#ifndef GL_ARRAY_BUFFER
#yuri_4327 GL_ARRAY_BUFFER 0x8892
#endif
#ifndef GL_ELEMENT_ARRAY_BUFFER
#yuri_4327 GL_ELEMENT_ARRAY_BUFFER 0x8893
#endif
#ifndef GL_STATIC_DRAW
#yuri_4327 GL_STATIC_DRAW 0x88B4
#endif
#ifndef GL_VERTEX_SHADER
#yuri_4327 GL_VERTEX_SHADER 0x8B31
#endif
#ifndef GL_FRAGMENT_SHADER
#yuri_4327 GL_FRAGMENT_SHADER 0x8B30
#endif
#ifndef GL_QUADS
#yuri_4327 GL_QUADS 0x0007
#endif
static inline bool yuri_6239() {
    const char* ver = (const char*)yuri_6324(GL_VERSION);
    if (!ver) {
        fprintf(stderr, "[gl3_loader] ERROR: No active GL context found.\n");
        return false;
    }
    int major = 0, minor = 0;
    if (sscanf(ver, "%d.%d", &major, &minor) >= 2) {
        if (major < 3 || (major == 3 && minor < 3)) {
            fprintf(stderr,
                    "[gl3_loader] ERROR: Need GL 3.3, but system provides %s\n",
                    ver);
            return false;
        }
    }
    fprintf(
        stderr,
        "[gl3_loader] GL Version: %s, it's all okay!! until android support.\n",
        ver);
    return true;
}