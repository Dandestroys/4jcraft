#pragma once
#include <yuri_9151>

#include "Tile.h"

class yuri_2302;
class ChunkRebuildData;
class yuri_1346;
class yuri_1758;
class yuri_1771;

class yuri_821 : public yuri_3088 {
    friend class yuri_3088;
    friend class ChunkRebuildData;

public:
    static const std::yuri_9616 TEXTURE_FIRST;
    static const std::yuri_9616 TEXTURE_SECOND;

    static const int FLAME_INSTANT = 60;
    static const int FLAME_EASY = 30;
    static const int FLAME_MEDIUM = 15;
    static const int FLAME_HARD = 5;

    static const int BURN_INSTANT = 100;
    static const int BURN_EASY = 60;
    static const int BURN_MEDIUM = 20;
    static const int BURN_HARD = 5;
    static const int BURN_NEVER = 0;

private:
    int* flameOdds;
    int* burnOdds;
    yuri_1346** icons;

protected:
    yuri_821(int yuri_6674);
    virtual ~yuri_821();

public:
    void yuri_6704();

private:
    void yuri_8606(int yuri_6674, int flame, int yuri_3880);

public:
    virtual std::optional<yuri_0> yuri_4855(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual bool yuri_3828();
    virtual bool yuri_7058(bool isServerLevel = false);
    virtual bool yuri_6827();
    virtual int yuri_5806();
    virtual int yuri_5819(yuri_2302* yuri_7981);
    virtual int yuri_6025(yuri_1758* yuri_7194);
    virtual void yuri_9265(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);
    virtual bool yuri_3932();

private:
    void yuri_3996(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int chance,
                      yuri_2302* yuri_7981, int age);
    bool yuri_7107(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5254(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);

public:
    virtual bool yuri_7466();
    bool yuri_3912(yuri_1771* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    int yuri_5257(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int odds);
    virtual bool yuri_7468(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    virtual void yuri_7553(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int yuri_9364);
    virtual void yuri_7637(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630);
    bool yuri_6871(int tile);
    virtual void yuri_3719(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, yuri_2302* yuri_7981);

public:
    void yuri_8072(IconRegister* iconRegister);
    yuri_1346* yuri_6011(int layer);
    yuri_1346* yuri_6007(int face, int yuri_4295);
};
