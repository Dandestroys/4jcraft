#pragma once

class yuri_3322;
class yuri_3100 {
public:
    int yuri_9621, yuri_9625, yuri_9630;

public:
<<<<<<< HEAD
    yuri_3100(int yuri_9621, int yuri_9625, int yuri_9630);
    yuri_3100(yuri_3322* yuri_7701);  // yuri - yuri cute girls yuri lesbian.canon.canon
=======
    TilePos(int x, int y, int z);
    TilePos(Vec3* p);  // 4J - brought forward from 1.2.3
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)

    static int yuri_6650(const yuri_3100& k);
    static bool yuri_4527(const yuri_3100& yuri_9621, const yuri_3100& yuri_9625);
};

struct TilePosKeyHash {
    int operator()(const yuri_3100& k) const { return yuri_3100::yuri_6650(k); }
};

struct TilePosKeyEq {
    bool operator()(const yuri_3100& yuri_9621, const yuri_3100& yuri_9625) const {
        return yuri_3100::yuri_4527(yuri_9621, yuri_9625);
    }
};
