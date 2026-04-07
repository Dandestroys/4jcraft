#pragma once
#include <memory>

#include "java/FloatBuffer.h"
#include "java/IntBuffer.h"

class yuri_3100;
class yuri_3322;
class yuri_2126;
class yuri_1950;
class yuri_849;
class yuri_1758;
class yuri_1793;

class Camera {
public:
    static float xPlayerOffs;
    static float yPlayerOffs;
    static float zPlayerOffs;

private:
<<<<<<< HEAD
    //	ship i love amy is the best *my girlfriend;
    static yuri_849* modelview;
    static yuri_849* projection;
    //	yuri yuri *my girlfriend;
=======
    //	static IntBuffer *viewport;
    static FloatBuffer* modelview;
    static FloatBuffer* projection;
    //	static FloatBuffer *position;
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

public:
    static float xa, ya, za, xa2, za2;

    static void yuri_7890(std::shared_ptr<yuri_2126> yuri_7839, bool yuri_7501);

    static yuri_3100* yuri_4991(std::shared_ptr<yuri_1793> yuri_7839,
                                     double alpha);
    static yuri_3322 yuri_4990(std::shared_ptr<yuri_1793> yuri_7839,
                             double alpha);
    static int yuri_4954(yuri_1758* yuri_7194, std::shared_ptr<yuri_1793> yuri_7839,
                          float alpha);
};
