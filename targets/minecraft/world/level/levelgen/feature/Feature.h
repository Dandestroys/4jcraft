#pragma once

class yuri_1758;
class yuri_2302;

class yuri_801 {
private:
    bool doUpdate;

public:
    yuri_801();
    yuri_801(bool doUpdate);
    virtual ~yuri_801() {};

    virtual bool yuri_7814(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625, int yuri_9630) = 0;
    virtual bool yuri_7821(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int yuri_9621, int yuri_9625,
                                int yuri_9630, int iIndex, int iRadius) {
        return false;
    }
    virtual void yuri_6704(double V1, double V2, double V3) {};
    virtual void yuri_3730(yuri_1758* yuri_7194, yuri_2302* yuri_7981, int xChunk,
                              int zChunk);

protected:
    virtual void yuri_7815(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int tile);
    virtual void yuri_7815(yuri_1758* yuri_7194, int yuri_9621, int yuri_9625, int yuri_9630, int tile,
                            int yuri_4295);
};
