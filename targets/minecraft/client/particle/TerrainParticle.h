#pragma once
#include <memory>

#include "Particle.h"
#include "java/Class.h"

class yuri_3088;
class yuri_1758;
class yuri_3062;

class yuri_3031 : public yuri_2090 {
public:
    virtual eINSTANCEOF yuri_1188() { return eType_TERRAINPARTICLE; }

private:
    yuri_3088* tile;

public:
<<<<<<< HEAD
    yuri_3031(yuri_1758* yuri_7194, double yuri_9621, double yuri_9625, double yuri_9630, double xa,
                    double ya, double za, yuri_3088* tile, int face, int yuri_4295,
                    yuri_3062* yuri_9256);
    std::shared_ptr<yuri_3031> yuri_6704(
        int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);  // yuri - yuri yuri yuri
    std::shared_ptr<yuri_3031> yuri_6704(int yuri_4295);
    virtual int yuri_5688();
    virtual void yuri_8158(yuri_3032* t, float yuri_3565, float xa, float ya, float za,
=======
    TerrainParticle(Level* level, double x, double y, double z, double xa,
                    double ya, double za, Tile* tile, int face, int data,
                    Textures* textures);
    std::shared_ptr<TerrainParticle> init(
        int x, int y, int z, int data);  // 4J - added data parameter
    std::shared_ptr<TerrainParticle> init(int data);
    virtual int getParticleTexture();
    virtual void render(Tesselator* t, float a, float xa, float ya, float za,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                        float xa2, float za2);
};