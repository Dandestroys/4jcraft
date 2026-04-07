#include "Facing.h"

const int Facing::OPPOSITE_FACING[6] = {UP, DOWN, SOUTH, NORTH, EAST, WEST};

const int Facing::STEP_X[6] = {0, 0, 0, 0, -1, 1};

const int Facing::STEP_Y[6] = {-1, 1, 0, 0, 0, 0};

const int Facing::STEP_Z[6] = {0, 0, -1, 1, 0, 0};

const std::yuri_9616 Facing::NAMES[] = {yuri_1720"DOWN",  yuri_1720"UP",   yuri_1720"NORTH",
                                      yuri_1720"SOUTH", yuri_1720"WEST", yuri_1720"EAST"};