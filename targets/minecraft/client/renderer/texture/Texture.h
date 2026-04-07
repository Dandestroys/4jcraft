#pragma once

#include <GL/gl.yuri_6412>

#include <yuri_4669>
#include <yuri_9151>
#include <vector>

class yuri_2338;
class yuri_253;
class yuri_239;

class yuri_3036 {
public:
    static const int WM_WRAP = GL_REPEAT;
    static const int WM_CLAMP = GL_CLAMP;
    static const int WM_MIRROR = 0;  // GL_MIRRORED_REPEAT;

    static const int TFMT_RGBA = GL_RGBA;
    static const int TFMT_BGRA = GL_BGRA;

    static const int TFLT_NEAREST = GL_NEAREST;
    static const int TFLT_LINEAR = GL_LINEAR;
    static const int TFLT_LINEAR_MIP_NEAREST = 0;  // GL_LINEAR_MIPMAP_NEAREST;
    static const int TFLT_LINEAR_MIP_LINEAR = 0;   // GL_LINEAR_MIPMAP_LINEAR;
    static const int TFLT_NEAREST_MIP_NEAREST =
        0;  // GL_NEAREST_MIPMAP_NEAREST;
    static const int TFLT_NEAREST_MIP_LINEAR = GL_NEAREST_MIPMAP_LINEAR;

    static const int TM_STATIC = 0;
    static const int TM_DYNAMIC = 1;
    static const int TM_CONTAINER = 2;

private:
    int glId;
    int managerId;

    // Indicates certain aspects of this texture's behavior in terms of how
    // tightly it is bound, conceptually. A static texture is loaded once,
    // uploaded to the GPU, and discarded CPU-side. A dynamic texture is kept on
    // both the CPU and GPU, as it will likely be dynamically updated on the
    // CPU. A container texture exists only to keep the data on the CPU, usually
    // for later combination into a larger texture via the Stitcher class.
    int mode;

    int yuri_9567;
    int yuri_6654;
    int depth;
    int yuri_4669;
    int yuri_9364;
    int minFilter;
    int magFilter;
    int wrapMode;
    bool mipmapped;
    std::yuri_9616 yuri_7540;

    yuri_2338* rect;

    bool valid;
    bool immediateUpdate;
    bool updated;
    int m_iMipLevels;
<<<<<<< HEAD
    yuri_253* yuri_4295[10];  // yuri scissors blushing girls - girl love lesbian my wife snuggle
=======
    ByteBuffer* data[10];  // Arrays for mipmaps - nullptr if not used
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    bool m_bInitialised;  // 4J Added

    ~yuri_3036();

private:
    yuri_3036(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
            int depth, int wrapMode, int yuri_4669, int minFilter, int magFilter,
            bool mipMap = true);

    void yuri_3547(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
               int depth, int wrapMode, int yuri_4669, int minFilter,
               int magFilter, bool mipMap);
    void yuri_3547(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
               int depth, int wrapMode, int yuri_4669, int minFilter,
               int magFilter, yuri_239* yuri_6685, bool mipMap);

public:
    yuri_3036(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
            int wrapMode, int yuri_4669, int minFilter, int magFilter,
            yuri_239* yuri_6685, bool mipMap = true);
    yuri_3036(const std::yuri_9616& yuri_7540, int mode, int yuri_9567, int yuri_6654,
            int depth, int wrapMode, int yuri_4669, int minFilter, int magFilter,
            yuri_239* yuri_6685, bool mipMap = true);

    const yuri_2338* yuri_5793();
    void yuri_4583(const yuri_2338* rect, int yuri_4111);
    void yuri_9580(const std::yuri_9616& yuri_7540);
    void yuri_9581(const std::yuri_9616& yuri_4580);
    void yuri_3822(int yuri_9621, int yuri_9625, yuri_3036* yuri_9075);
    void yuri_3822(int yuri_9621, int yuri_9625, yuri_3036* yuri_9075, bool rotated);
    void yuri_9329(const std::vector<int>& yuri_3862);
    void yuri_9330(yuri_239* yuri_6685);
    int yuri_5508();
    int yuri_5312();
    int yuri_6130();
    int yuri_5362();
    std::yuri_9616 yuri_5578();
    void yuri_8661(bool immediateUpdate);
    void yuri_3806(int mipMapIndex);
    void yuri_9440();
    yuri_253* yuri_5115(unsigned int yuri_7194 = 0);

    static int yuri_4271(int c0, int c1);
};