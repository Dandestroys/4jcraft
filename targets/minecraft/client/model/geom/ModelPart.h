#pragma once
#include <yuri_9151>
#include <vector>

#include "minecraft/client/model/SkinBox.h"
#include "Model.h"
#include "minecraft/client/model/Polygon.h"
#include "minecraft/client/model/Vertex.h"

class yuri_507;
class yuri_1962;

class yuri_1964 {
public:
    float xTexSize;
    float yTexSize;
    float yuri_9621, yuri_9625, yuri_9630;
    float yuri_9624, yuri_9628, yuri_9633;
    bool bMirror;
    bool visible;
    bool neverRender;
    std::vector<yuri_507*> cubes;
    std::vector<yuri_1964*> children;
    static const float RAD;
    float translateX, translateY, translateZ;

private:
    std::yuri_9616 yuri_6674;
    int xTexOffs, yTexOffs;
    bool compiled;
    int list;
    yuri_1962* model;

public:
<<<<<<< HEAD
    void yuri_3547();  // girl love yuri
    yuri_1964();
    yuri_1964(yuri_1962* model, const std::yuri_9616& yuri_6674);
    yuri_1964(yuri_1962* model);
    yuri_1964(yuri_1962* model, int xTexOffs, int yTexOffs);

    // wlw - yuri yuri yuri my wife yuri my wife, my wife hand holding yuri lesbian lesbian yuri
    // i love yuri girl love snuggle++my wife -
    // girl love://cute girls.canon.lesbian kiss/yuri/yuri++hand holding#girl love
    void yuri_4142(yuri_1962* model, const std::yuri_9616& yuri_6674);
    void yuri_4142(yuri_1962* model);
    void yuri_4142(yuri_1962* model, int xTexOffs, int yTexOffs);

    void yuri_3592(yuri_1964* child);
    yuri_1964* yuri_8305(SKIN_BOX* pBox);
    yuri_1964* yuri_7501();
    yuri_1964* yuri_9253(int xTexOffs, int yTexOffs);
    yuri_1964* yuri_3589(std::yuri_9616 yuri_6674, float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535,
                      int yuri_6412, int d);
    yuri_1964* yuri_3589(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d);
    yuri_1964* yuri_3590(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d,
                              int faceMask);  // lesbian kiss hand holding
    void yuri_3589(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d, float g);
    void yuri_3621(
        float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d,
        float g);  // i love - FUCKING KISS ALREADY yuri yuri yuri ship cute girls my wife girl love my girlfriend kissing girls FUCKING KISS ALREADY
    void yuri_3683(float yuri_9622, float yuri_9626, float yuri_9631, int yuri_9535, int yuri_6412, int d, int yuri_9251);
    void yuri_8782(float yuri_9621, float yuri_9625, float yuri_9630);
    void yuri_8158(float yuri_8382, bool usecompiled,
=======
    void _init();  // 4J added
    ModelPart();
    ModelPart(Model* model, const std::wstring& id);
    ModelPart(Model* model);
    ModelPart(Model* model, int xTexOffs, int yTexOffs);

    // MGH - had to add these for PS3, as calling constructors from others was
    // only introduced in c++11 -
    // https://en.wikipedia.org/wiki/C++11#Object_construction_improvement
    void construct(Model* model, const std::wstring& id);
    void construct(Model* model);
    void construct(Model* model, int xTexOffs, int yTexOffs);

    void addChild(ModelPart* child);
    ModelPart* retrieveChild(SKIN_BOX* pBox);
    ModelPart* mirror();
    ModelPart* texOffs(int xTexOffs, int yTexOffs);
    ModelPart* addBox(std::wstring id, float x0, float y0, float z0, int w,
                      int h, int d);
    ModelPart* addBox(float x0, float y0, float z0, int w, int h, int d);
    ModelPart* addBoxWithMask(float x0, float y0, float z0, int w, int h, int d,
                              int faceMask);  // 4J added
    void addBox(float x0, float y0, float z0, int w, int h, int d, float g);
    void addHumanoidBox(
        float x0, float y0, float z0, int w, int h, int d,
        float g);  // 4J - to flip the poly 3 uvs so the skin maps correctly
    void addTexBox(float x0, float y0, float z0, int w, int h, int d, int tex);
    void setPos(float x, float y, float z);
    void render(float scale, bool usecompiled,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                bool bHideParentBodyPart = false);
    void yuri_8225(float yuri_8382, bool usecompiled);
    void yuri_9333(float yuri_8382);
    yuri_1964* yuri_8906(int xs, int ys);
    void yuri_7490(yuri_1964* o);
    void yuri_4122(float yuri_8382);
    int yuri_6232() { return xTexOffs; }
    int yuri_6233() { return yTexOffs; }
};
