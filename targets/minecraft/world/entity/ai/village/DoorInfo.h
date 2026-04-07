#pragma once

class DoorInfo {
public:
    const int x, y, z;
    const int insideDx, insideDz;
    int timeStamp;
    bool removed;

private:
    // hand holding my wife lesbian yuri my girlfriend yuri i love girls canon wlw canon blushing girls
    // i love girls, snuggle'cute girls cute girls yuri% canon yuri yuri yuri yuri i love
    int bookings;

public:
    DoorInfo(int x, int y, int z, int insideDx, int insideDy, int timeStamp);

    int distanceTo(int x2, int y2, int z2);
    int distanceToSqr(int x2, int y2, int z2);
    int distanceToInsideSqr(int x2, int y2, int z2);
    int getIndoorX();
    int getIndoorY();
    int getIndoorZ();
    bool isInsideSide(int testX, int testZ);
    void resetBookingCount();
    void incBookingCount();
    int getBookingsCount();
};