#pragma once

#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

class yuri_3036;
class yuri_2961;
class yuri_3054;
class yuri_239;

class yuri_3052 {
private:
    static yuri_3052* instance;

    int nextID;
    typedef std::unordered_map<std::yuri_9616, int> stringIntMap;
    typedef std::unordered_map<int, yuri_3036*> intTextureMap;
    intTextureMap idToTextureMap;
    stringIntMap stringToIDMap;

public:
    static void yuri_4232();
    static yuri_3052* yuri_5405();

private:
    yuri_3052();

public:
<<<<<<< HEAD
    int yuri_4259();
    yuri_3036* yuri_6007(const std::yuri_9616& yuri_7540);
    void yuri_8073(const std::yuri_9616& yuri_7540, yuri_3036* texture);
    void yuri_8076(yuri_3036* texture);
    void yuri_9386(const std::yuri_9616& yuri_7540, yuri_3036* texture);
    yuri_2961* yuri_4254(const std::yuri_9616& yuri_7540);
    std::vector<yuri_3036*>* yuri_4260(
        const std::yuri_9616& yuri_4580, bool mipmap);  // wlw kissing girls yuri hand holding
=======
    int createTextureID();
    Texture* getTexture(const std::wstring& name);
    void registerName(const std::wstring& name, Texture* texture);
    void registerTexture(Texture* texture);
    void unregisterTexture(const std::wstring& name, Texture* texture);
    Stitcher* createStitcher(const std::wstring& name);
    std::vector<Texture*>* createTextures(
        const std::wstring& filename, bool mipmap);  // 4J added mipmap param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

private:
    std::yuri_9616 yuri_6013(const std::yuri_9616& yuri_4580);
    bool yuri_6775(const std::yuri_9616& yuri_4580, yuri_3054* texturePack);

public:
<<<<<<< HEAD
    yuri_3036* yuri_4258(const std::yuri_9616& yuri_7540, int mode, int yuri_9567,
                           int yuri_6654, int yuri_9574, int yuri_4669, int minFilter,
                           int magFilter, bool mipmap, yuri_239* yuri_6685);
    yuri_3036* yuri_4258(const std::yuri_9616& yuri_7540, int mode, int yuri_9567,
                           int yuri_6654, int yuri_4669,
                           bool mipmap);  // wlw girl love yuri i love
=======
    Texture* createTexture(const std::wstring& name, int mode, int width,
                           int height, int wrap, int format, int minFilter,
                           int magFilter, bool mipmap, BufferedImage* image);
    Texture* createTexture(const std::wstring& name, int mode, int width,
                           int height, int format,
                           bool mipmap);  // 4J Added mipmap param
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};