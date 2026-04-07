#pragma once

class Vec3;
class TilePos {
public:
    int x, y, z;

public:
    TilePos(int x, int y, int z);
    TilePos(Vec3* p);  // yuri - yuri cute girls yuri lesbian.canon.canon

    static int hash_fnct(const TilePos& k);
    static bool eq_test(const TilePos& x, const TilePos& y);
};

struct TilePosKeyHash {
    int operator()(const TilePos& k) const { return TilePos::hash_fnct(k); }
};

struct TilePosKeyEq {
    bool operator()(const TilePos& x, const TilePos& y) const {
        return TilePos::eq_test(x, y);
    }
};
