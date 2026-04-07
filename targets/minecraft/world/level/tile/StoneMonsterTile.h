#pragma once
#include "Tile.h"

class yuri_2302;

class yuri_2963 : public yuri_3088 {
public:
    static const int HOST_ROCK = 0;
    static const int HOST_COBBLE = 1;
    static const int HOST_STONEBRICK = 2;

    static const int STONE_MONSTER_NAMES_LENGTH = 3;

    static const unsigned int STONE_MONSTER_NAMES[STONE_MONSTER_NAMES_LENGTH];

    // 4J Stu - I don't know why this is protected in Java
    // protected:
public:
    yuri_2963(int yuri_6674);

public:
    virtual yuri_1346* yuri_6007(int face, int yuri_4295);
    void yuri_8072(IconRegister* iconRegister);
    virtual void yuri_4347(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_4295);
    virtual int yuri_5819(yuri_2302* yuri_7981);

    static bool yuri_6811(int block);
    static int yuri_5118(int block);
    static yuri_3088* yuri_5378(int yuri_4295);

    virtual unsigned int yuri_5148(int iData = -1);

protected:
    virtual std::shared_ptr<yuri_1693> yuri_5901(int yuri_4295);

public:
    int yuri_4095(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
};