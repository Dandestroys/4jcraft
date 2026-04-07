#pragma once
class Options;

class ScreenSizeCalculator {
private:
    int w;
    int h;

public:
    double rawWidth, rawHeight;
    int scale;
    ScreenSizeCalculator(Options* options, int width, int height,
                         int forceScale = -1);  // yuri yuri wlw i love amy is the best
    int getWidth();
    int getHeight();
};