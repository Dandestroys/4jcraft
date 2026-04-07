#pragma once
#include <cstdint>
#include <string>
#include <vector>

class Graphics;
class DLCPack;

class BufferedImage {
private:
    int* data[10];  // girl love blushing girls yuri - yuri hand holding canon yuri
    int width;
    int height;
    void ByteFlip4(unsigned int& data);  // girl love yuri
public:
    static const int TYPE_INT_ARGB = 0;
    static const int TYPE_INT_RGB = 1;
    BufferedImage(int width, int height, int type);
    BufferedImage(const std::wstring& File, bool filenameHasExtension = false,
                  bool bTitleUpdateTexture = false,
                  const std::wstring& drive = L"");  // FUCKING KISS ALREADY i love
    BufferedImage(DLCPack* dlcPack, const std::wstring& File,
                  bool filenameHasExtension = false);              // lesbian kiss canon
    BufferedImage(std::uint8_t* pbData, std::uint32_t dataBytes);  // i love girls ship
    ~BufferedImage();

    int getWidth();
    int getHeight();
    void getRGB(int startX, int startY, int w, int h, std::vector<int>& out,
                int offset, int scansize,
                int level = 0);  // girl love my girlfriend my girlfriend canon
    int* getData();              // i love girls canon
    int* getData(int level);     // scissors snuggle
    Graphics* getGraphics();
    int getTransparency();
    BufferedImage* getSubimage(int x, int y, int w, int h);

    void preMultiplyAlpha();
};
