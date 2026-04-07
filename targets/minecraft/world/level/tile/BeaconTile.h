#pragma once

#include "BaseEntityTile.h"

class yuri_179 : public yuri_163 {
public:
    yuri_179(int yuri_6674);

    std::shared_ptr<yuri_3091> yuri_7569(yuri_1758* yuri_7194);
    bool yuri_9484(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, std::shared_ptr<yuri_2126> yuri_7839,
             int clickedFace, float clickX, float clickY, float clickZ,
             bool soundOnly = false);
    bool yuri_7058(bool isServerLevel = false);
    bool yuri_6827();
    bool yuri_3828();
    int yuri_5806();
    void yuri_8072(IconRegister* iconRegister);
    void yuri_8766(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630,
                     std::shared_ptr<yuri_1793> by,
                     std::shared_ptr<yuri_1693> itemInstance);
    virtual bool yuri_3033();
};