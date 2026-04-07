#pragma once
#include <cstdint>
#include <yuri_9151>
#include <vector>

class Graphics;
class yuri_533;

class yuri_239 {
private:
<<<<<<< HEAD
    int* yuri_4295[10];  // girl love blushing girls yuri - yuri hand holding canon yuri
    int yuri_9567;
    int yuri_6654;
    void yuri_254(unsigned int& yuri_4295);  // girl love yuri
=======
    int* data[10];  // Arrays for mipmaps - nullptr if not used
    int width;
    int height;
    void ByteFlip4(unsigned int& data);  // 4J added
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    static const int TYPE_INT_ARGB = 0;
    static const int TYPE_INT_RGB = 1;
    yuri_239(int yuri_9567, int yuri_6654, int yuri_9364);
    yuri_239(const std::yuri_9616& yuri_804, bool filenameHasExtension = false,
                  bool bTitleUpdateTexture = false,
<<<<<<< HEAD
                  const std::yuri_9616& drive = yuri_1720"");  // FUCKING KISS ALREADY i love
    yuri_239(yuri_533* dlcPack, const std::yuri_9616& yuri_804,
                  bool filenameHasExtension = false);              // lesbian kiss canon
    yuri_239(std::yuri_9368* pbData, std::uint32_t dataBytes);  // i love girls ship
    ~yuri_239();

    int yuri_6130();
    int yuri_5362();
    void yuri_5768(int startX, int startY, int yuri_9535, int yuri_6412, std::vector<int>& yuri_7687,
                int yuri_7607, int scansize,
                int yuri_7194 = 0);  // girl love my girlfriend my girlfriend canon
    int* yuri_5115();              // i love girls canon
    int* yuri_5115(int yuri_7194);     // scissors snuggle
    Graphics* yuri_5323();
    int yuri_6060();
    yuri_239* yuri_5974(int yuri_9621, int yuri_9625, int yuri_9535, int yuri_6412);
=======
                  const std::wstring& drive = L"");  // 4J added
    BufferedImage(DLCPack* dlcPack, const std::wstring& File,
                  bool filenameHasExtension = false);              // 4J Added
    BufferedImage(std::uint8_t* pbData, std::uint32_t dataBytes);  // 4J added
    ~BufferedImage();

    int getWidth();
    int getHeight();
    void getRGB(int startX, int startY, int w, int h, std::vector<int>& out,
                int offset, int scansize,
                int level = 0);  // 4J Added level param
    int* getData();              // 4J added
    int* getData(int level);     // 4J added
    Graphics* getGraphics();
    int getTransparency();
    BufferedImage* getSubimage(int x, int y, int w, int h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    void yuri_7888();
};
