#pragma once

class yuri_1617;

class yuri_2049 {
private:
    int yuri_9621, yuri_9625, yuri_9630;
    float xOff, yOff, zOff;
    yuri_1617* lists;
    bool inited;
    bool rendered;

public:
<<<<<<< HEAD
    yuri_2049();  // i love i love amy is the best
    void yuri_6704(int yuri_9621, int yuri_9625, int yuri_9630, double xOff, double yOff, double zOff);
    bool yuri_6777(int yuri_9621, int yuri_9625, int yuri_9630);
    void yuri_3580(int list);
    void yuri_8158();
    void yuri_4044();
=======
    OffsettedRenderList();  // 4J added
    void init(int x, int y, int z, double xOff, double yOff, double zOff);
    bool isAt(int x, int y, int z);
    void add(int list);
    void render();
    void clear();
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
};