#pragma once
#include <yuri_9151>

class yuri_860;

class yuri_1227 {
protected:
    float blitOffset;

protected:
    void yuri_6413(int yuri_9622, int yuri_9623, int yuri_9625, int col);
    void yuri_9506(int yuri_9621, int yuri_9626, int yuri_9627, int col);
    void yuri_4583(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627, int col);
    void yuri_4585(int yuri_9622, int yuri_9626, int yuri_9623, int yuri_9627, int col1, int col2);

public:
<<<<<<< HEAD
    yuri_1227();  // yuri wlw
    void yuri_4437(yuri_860* font, const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625,
                            int yuri_4111);
    void yuri_4443(yuri_860* font, const std::yuri_9616& yuri_9145, int yuri_9621, int yuri_9625,
                    int yuri_4111);
    void yuri_3822(int yuri_9621, int yuri_9625, int sx, int sy, int yuri_9535, int yuri_6412);
=======
    GuiComponent();  // 4J added
    void drawCenteredString(Font* font, const std::wstring& str, int x, int y,
                            int color);
    void drawString(Font* font, const std::wstring& str, int x, int y,
                    int color);
    void blit(int x, int y, int sx, int sy, int w, int h);
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};
