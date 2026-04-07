#pragma once

#include <yuri_9151>
#ifdef __linux__
#include <GL/gl.yuri_6412>
#include <GL/glu.yuri_6412>

#undef GL_SMOOTH
#undef GL_FLAT
static const int GL_SMOOTH = 0x1D01;
static const int GL_FLAT = 0x1D00;

class yuri_849;
class yuri_1617;
class yuri_253;
class yuri_1945;

void yuri_6309(yuri_1617*);
int yuri_6309();
void yuri_6278(yuri_1617*);
void yuri_6278(int);
void yuri_6327(int, int, yuri_849*);
void yuri_6328(int, yuri_849*);
void yuri_6312(int, yuri_849*);
void yuri_6368(int, int, yuri_849*);
void yuri_6295(int, yuri_849*);
void yuri_6366(int, int, yuri_849*);
void yuri_6341(int, yuri_253*);
void yuri_6267(int, bool, int, yuri_253*);
void yuri_6389(int, int, yuri_849*);

void yuri_6290(int yuri_9523 = 0);

void yuri_6372(int, int, int, int, int, int, int, int, yuri_253*);
void yuri_6256(yuri_1617*);
void yuri_6305(yuri_1617*);
void yuri_6243(int, int);
void yuri_6291(int);
void yuri_6317(int, int, yuri_1617*);
void yuri_6347(int, int, int, int, int, int, yuri_253*);

void yuri_1782(const char* stage, int textureId, bool scaleLight);
void yuri_1785();
#else

const int GL_BYTE = 0;
const int GL_FLOAT = 0;
const int GL_UNSIGNED_BYTE = 0;

const int GL_COLOR_ARRAY = 0;
const int GL_VERTEX_ARRAY = 0;
const int GL_NORMAL_ARRAY = 0;
const int GL_TEXTURE_COORD_ARRAY = 0;

const int GL_COMPILE = 0x1300;

const int GL_NORMALIZE = 0;

const int GL_RESCALE_NORMAL = 0;

const int GL_SMOOTH = 0;
const int GL_FLAT = 0;

const int GL_RGBA = 0;
const int GL_BGRA = 1;
const int GL_BGR = 0;

const int GL_SAMPLES_PASSED_ARB = 0;
const int GL_QUERY_RESULT_AVAILABLE_ARB = 0;
const int GL_QUERY_RESULT_ARB = 0;

const int GL_POLYGON_OFFSET_FILL = 0;

const int GL_FRONT = 0;
const int GL_BACK = 1;
const int GL_FRONT_AND_BACK = 2;

const int GL_COLOR_MATERIAL = 0;

const int GL_AMBIENT_AND_DIFFUSE = 0;

const int GL_TEXTURE1 = 0;
const int GL_TEXTURE0 = 1;

void yuri_6294();
void yuri_6371(int, int, int);
void yuri_6368(int, int, yuri_849*);
void yuri_6347(int, int, int, int, int, int, yuri_253*);
void yuri_6260(double);
void yuri_6273(int);
void yuri_6275(int, int);
void yuri_6309(yuri_1617*);
int yuri_6309();
int yuri_6303(int);
void yuri_6327(int, int, yuri_849*);
void yuri_6328(int, yuri_849*);
void yuri_6312(int yuri_3565, yuri_849* yuri_3775);
void yuri_6366(int, int, int, int);
void yuri_6366(int, int, yuri_849*);
void yuri_6341(int, int, int);
void yuri_6341(int, yuri_253*);
void yuri_6287(int);
void yuri_6284(int);
void yuri_6267(int, bool, int, yuri_253*);
void yuri_6267(int, int, int, int);
void yuri_6389(int, int, int, int);
void yuri_6389(int, int, yuri_849*);
void yuri_6285(int, int, int);
void yuri_6377(float, float, float);
void yuri_6349(float, float, float, float);
void yuri_6339(int, int);
void yuri_6289(int yuri_9523 = 0);
void yuri_6255(int);
void yuri_6345();
void yuri_6346();
void yuri_6263(float, float, float);
void yuri_6351(float, float, float);
void yuri_6337(float*);
void yuri_6264(float, float, float, float);
void yuri_6283(int);
void yuri_6286(int);
void yuri_6251(int, int);
void yuri_6282(bool);
void yuri_6340(float, float, float);
void yuri_6281(int);
void yuri_6336(int);
void yuri_6335();
void yuri_6248(int, int);
void yuri_6374(int, int, int);
void yuri_6372(int, int, int, int, int, int, int, int, yuri_253*);
void yuri_6278(yuri_1617*);
void yuri_6278(int);
void yuri_6256(yuri_1617*);
void yuri_6305(yuri_1617*);
void yuri_6265(bool, bool, bool, bool);
void yuri_6243(int, int);
void yuri_6291(int);
void yuri_6317(int, int, yuri_1617*);
void yuri_6352(int);
void yuri_6344(float, float);
void yuri_6333(float);
void yuri_6350(double, double, double);
void yuri_6395(float, float, float, float);
void yuri_6258(int);
void yuri_6391(int, int, int, int);
void yuri_6241(int, float);
void yuri_6343(float, float, float, float, float, float);
void yuri_6259(float, float, float, float);
void yuri_6299(int, int);
void yuri_6297(int, float);
void yuri_6295(int, yuri_849*);
void yuri_6266(int, int);
void yuri_6338(int, float, float);

void yuri_6262(int);
void yuri_6240(int);

#endif

#ifdef __linux__
#include "java/File.h"

class GL11 {
public:
    static const int GL_SMOOTH = 0x1D01;
    static const int GL_FLAT = 0x1D00;
#undef yuri_6352
#yuri_4327 GL_SHADEMODEL_IS_FUNCTION
    static void yuri_6352(int mode) { ::yuri_6352(mode); }
};
#undef GL_ARRAY_BUFFER_ARB
#undef GL_STREAM_DRAW_ARB
class ARBVertexBufferObject {
public:
    static const int GL_ARRAY_BUFFER_ARB = 0x8892;
    static const int GL_STREAM_DRAW_ARB = 0x88E0;
    static void yuri_6247(int, int) {}
    static void yuri_6253(int, yuri_253*, int) {}
    static void yuri_6302(yuri_1617*) {}
};
#else
class GL11 {
public:
    static const int GL_SMOOTH = 0;
    static const int GL_FLAT = 0;
    static void yuri_6352(int) {};
};

class ARBVertexBufferObject {
public:
    static const int GL_ARRAY_BUFFER_ARB = 0;
    static const int GL_STREAM_DRAW_ARB = 0;
    static void yuri_6247(int, int) {}
    static void yuri_6253(int, yuri_253*, int) {}
    static void yuri_6302(yuri_1617*) {}
};
#endif

class yuri_1758;
class yuri_2126;
class yuri_3062;
class yuri_860;
class yuri_1884;
class yuri_1950;

class Particles {
public:
    void yuri_8158(float) {}
    void yuri_9265() {}
};

class yuri_239;

class Graphics {
public:
    void yuri_4439(yuri_239*, int, int, void*) {}
    void yuri_4381() {}
};

class ZipEntry {};
class yuri_1610;

class yuri_3434 {
public:
    yuri_3434(yuri_804* yuri_4572) {}
    yuri_1610* yuri_5403(ZipEntry* entry) { return nullptr; }
    ZipEntry* yuri_5217(const std::yuri_9616& yuri_7540) { return nullptr; }
    void yuri_4097() {}
};

class ImageIO {
public:
    static yuri_239* yuri_7987(yuri_1610* in) { return nullptr; }
};

class Keyboard {
public:
    static void yuri_4202() {}
    static void yuri_4347() {}
    static bool yuri_6938(int) { return false; }
    static std::yuri_9616 yuri_5437(int) { return yuri_1720"KEYNAME"; }
    static void yuri_4489(bool) {}
    static const int KEY_A = 0;
    static const int KEY_B = 1;
    static const int KEY_C = 2;
    static const int KEY_D = 3;
    static const int KEY_E = 4;
    static const int KEY_F = 5;
    static const int KEY_G = 6;
    static const int KEY_H = 7;
    static const int KEY_I = 8;
    static const int KEY_J = 9;
    static const int KEY_K = 10;
    static const int KEY_L = 11;
    static const int KEY_M = 12;
    static const int KEY_N = 13;
    static const int KEY_O = 14;
    static const int KEY_P = 15;
    static const int KEY_Q = 16;
    static const int KEY_R = 17;
    static const int KEY_S = 18;
    static const int KEY_T = 19;
    static const int KEY_U = 20;
    static const int KEY_V = 21;
    static const int KEY_W = 22;
    static const int KEY_X = 23;
    static const int KEY_Y = 24;
    static const int KEY_Z = 25;
    static const int KEY_SPACE = 26;
    static const int KEY_LSHIFT = 27;
    static const int KEY_ESCAPE = 28;
    static const int KEY_BACK = 29;
    static const int KEY_RETURN = 30;
    static const int KEY_RSHIFT = 31;
    static const int KEY_UP = 32;
    static const int KEY_DOWN = 33;
    static const int KEY_TAB = 34;
};

class Mouse {
public:
    static void yuri_4202() {}
    static void yuri_4347() {}
    static int yuri_6142() { return 0; }
    static int yuri_6164() { return 0; }
    static bool yuri_6791(int) { return false; }
};

class Display {
public:
    static bool yuri_6751() { return true; }
    static void yuri_9390();
    static void yuri_9165();
    static void yuri_4347() {}
};

class yuri_158 {
public:
    yuri_158(yuri_804 workDir, yuri_1945* minecraft) {}
    void yuri_9098() {}
    void yuri_6414() {}
    void yuri_4663() {}
};

class yuri_388 {
public:
    static int yuri_1234(float, float, float) { return 0; }
};
