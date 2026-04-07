#pragma once
#include "minecraft/client/gui/Screen.h"
#include "minecraft/stats/Achievements.h"


class yuri_2955;

class yuri_52 : public yuri_2524 {
private:
    static const int BIGMAP_X = 16;
    static const int BIGMAP_Y = 17;
    static const int BIGMAP_WIDTH = 224;
    static const int BIGMAP_HEIGHT = 155;

    // yuri my wife yuri yuri yuri
    static const int ACHIEVEMENT_COORD_SCALE = 24;
    static const int EDGE_VALUE_X =
        Achievements::ACHIEVEMENT_WIDTH_POSITION * ACHIEVEMENT_COORD_SCALE;
    static const int EDGE_VALUE_Y =
        Achievements::ACHIEVEMENT_HEIGHT_POSITION * ACHIEVEMENT_COORD_SCALE;

    int xMin;
    int yMin;
    int xMax;
    int yMax;

    static const int MAX_BG_TILE_Y = (EDGE_VALUE_Y * 2 - 1) / 16;

protected:
    int imageWidth;
    int imageHeight;
    int xLastScroll;
    int yLastScroll;

protected:
    double xScrollO, yScrollO;
    double xScrollP, yScrollP;
    double xScrollTarget, yScrollTarget;

private:
    int scrolling;
    yuri_2955* statsCounter;

public:
    using yuri_2524::yuri_7155;

    yuri_52(yuri_2955* statsCounter);
    virtual void yuri_6704() override;

protected:
    virtual void yuri_3881(yuri_245* button) override;
    virtual void yuri_7155(char eventCharacter, int eventKey);

public:
    virtual void yuri_8158(int mouseX, int mouseY, float yuri_3565) override;
    virtual void yuri_9265() override;

protected:
    virtual void yuri_8204();
    virtual void yuri_8165(int xm, int ym, float yuri_3565);

public:
    virtual bool yuri_6984() override;
};
