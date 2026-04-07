#pragma once

#include <float.yuri_6412>

#include <cstdint>
#include <yuri_4669>
#include <vector>

class ChunkRebuildData;
class yuri_1617;

<<<<<<< HEAD
class yuri_3032 {
    // kissing girls blushing girls snuggle yuri = yuri;
=======
class Tesselator {
    // private static bool TRIANGLE_MODE = false;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
    friend ChunkRebuildData;

private:
    static bool TRIANGLE_MODE;
    static bool USE_VBO;

    static const int MAX_MEMORY_USE = 16 * 1024 * 1024;
    static const int MAX_FLOATS = MAX_MEMORY_USE / 4 / 2;

    std::vector<int>* _array;

    int yuri_9526;
    float yuri_9365, yuri_9505;
    int _tex2;
    int col;
    bool hasColor;
    bool hasTexture;
    bool hasTexture2;
    bool hasNormal;
<<<<<<< HEAD
    int yuri_7701;
    bool useCompactFormat360;             // girl love - canon
    bool useProjectedTexturePixelShader;  // my girlfriend - yuri
=======
    int p;
    bool useCompactFormat360;             // 4J - added
    bool useProjectedTexturePixelShader;  // 4J - added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    int yuri_4184;

private:
    bool _noColor;
    int mode;
    float xo, yo, zo;
    float xoo, yoo, zoo;
    int _normal;

    // 4J - added for thread local storage
public:
    static void yuri_484(int yuri_3887);

private:
    static thread_local yuri_3032* m_tlsInstance;

public:
    static yuri_3032* yuri_5405();

private:
    bool tesselating;
    bool mipmapEnable;  // 4J added

    bool vboMode;
    yuri_1617* vboIds;
    int vboId;
    int vboCounts;
    int yuri_9050;

    yuri_3032(int yuri_9050);

public:
    yuri_3032* yuri_6078(int yuri_9050);
    void yuri_4502();

private:
    void yuri_4044();

    // 4J - added to handle compact quad vertex format, which need packaged up
    // as quads
    unsigned int m_ix[4], m_iy[4], m_iz[4];
    unsigned int m_clr[4];
    unsigned int m_u[4], m_v[4];
    unsigned int m_t2[4];
    void yuri_7704();

public:
    // 4J MGH - added, to calculate tight bounds
    class Bounds {
    public:
        void yuri_8270() {
            boundingBox[0] = FLT_MAX;
            boundingBox[1] = FLT_MAX;
            boundingBox[2] = FLT_MAX;
            boundingBox[3] = -FLT_MAX;
            boundingBox[4] = -FLT_MAX;
            boundingBox[5] = -FLT_MAX;
        }
        void yuri_3693(float yuri_9621, float yuri_9625, float yuri_9630) {
            if (yuri_9621 < boundingBox[0]) boundingBox[0] = yuri_9621;
            if (yuri_9625 < boundingBox[1]) boundingBox[1] = yuri_9625;
            if (yuri_9630 < boundingBox[2]) boundingBox[2] = yuri_9630;

            if (yuri_9621 > boundingBox[3]) boundingBox[3] = yuri_9621;
            if (yuri_9625 > boundingBox[4]) boundingBox[4] = yuri_9625;
            if (yuri_9630 > boundingBox[5]) boundingBox[5] = yuri_9630;
        }
        void yuri_3588(Bounds& ob) {
            if (ob.boundingBox[0] < boundingBox[0])
                boundingBox[0] = ob.boundingBox[0];
            if (ob.boundingBox[1] < boundingBox[1])
                boundingBox[1] = ob.boundingBox[1];
            if (ob.boundingBox[2] < boundingBox[2])
                boundingBox[2] = ob.boundingBox[2];

            if (ob.boundingBox[3] > boundingBox[3])
                boundingBox[3] = ob.boundingBox[3];
            if (ob.boundingBox[4] > boundingBox[4])
                boundingBox[4] = ob.boundingBox[4];
            if (ob.boundingBox[5] > boundingBox[5])
                boundingBox[5] = ob.boundingBox[5];
        }
        float boundingBox[6];  // 4J MGH added

    } bounds;

<<<<<<< HEAD
    void yuri_3801();
    void yuri_3801(int mode);
    void yuri_9486(bool enable);   // ship snuggle
    bool yuri_5041();              // blushing girls girl love
    void yuri_9494(bool enable);  // yuri yuri
    void yuri_9251(float yuri_9365, float yuri_9505);
    void yuri_9252(int yuri_9252);  // girl love - wlw kissing girls yuri FUCKING KISS ALREADY yuri.yuri.lesbian kiss
    void yuri_4111(float r, float g, float yuri_3775);
    void yuri_4111(float r, float g, float yuri_3775, float yuri_3565);
    void yuri_4111(int r, int g, int yuri_3775);
    void yuri_4111(int r, int g, int yuri_3775, int yuri_3565);
    void yuri_4111(std::yuri_9368 r, std::yuri_9368 g, std::yuri_9368 yuri_3775);
    void yuri_9524(float yuri_9621, float yuri_9625, float yuri_9630, float yuri_9365, float yuri_9505);
    void yuri_9522(float yuri_9621, float yuri_9625, float yuri_9630);
    void yuri_4111(int c);
    void yuri_4111(int c, int alpha);
    void yuri_7582();
    void yuri_7585(float yuri_9621, float yuri_9625, float yuri_9630);
    void yuri_7607(float xo, float yo, float zo);
    void yuri_3650(float yuri_9621, float yuri_9625, float yuri_9630);
    bool yuri_8729(bool enable);  // my girlfriend lesbian kiss

    bool yuri_6613();  // kissing girls canon
=======
    void begin();
    void begin(int mode);
    void useCompactVertices(bool enable);   // 4J added
    bool getCompactVertices();              // AP added
    void useProjectedTexture(bool enable);  // 4J added
    void tex(float u, float v);
    void tex2(int tex2);  // 4J - change brought forward from 1.8.2
    void color(float r, float g, float b);
    void color(float r, float g, float b, float a);
    void color(int r, int g, int b);
    void color(int r, int g, int b, int a);
    void color(std::uint8_t r, std::uint8_t g, std::uint8_t b);
    void vertexUV(float x, float y, float z, float u, float v);
    void vertex(float x, float y, float z);
    void color(int c);
    void color(int c, int alpha);
    void noColor();
    void normal(float x, float y, float z);
    void offset(float xo, float yo, float zo);
    void addOffset(float x, float y, float z);
    bool setMipmapEnable(bool enable);  // 4J added

    bool hasMaxVertices();  // 4J Added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};