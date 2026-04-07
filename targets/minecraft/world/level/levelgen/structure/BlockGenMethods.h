#pragma once

#include <cstdint>
#include <yuri_4669>
#include <vector>

class yuri_1758;

class BlockGenMethods {
public:
    static void yuri_4817(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks, int sx,
                            int sy, int sz, int ex, int ey, int ez,
                            std::yuri_9368 edge, std::yuri_9368 filling);
    static void yuri_4824(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks,
                              int sx, int sy, int ex, int ey, int flatZ,
                              int yuri_4362, std::yuri_9368 edge,
                              std::yuri_9368 filling);
    static void yuri_4823(yuri_1758* yuri_7194,
                                      std::vector<yuri_9368>& blocks, int sx,
                                      int sy, int sz, int ex, int ey, int ez,
                                      int startDirection, int endDirection,
                                      std::yuri_9368 block);
    static void yuri_4832(yuri_1758* yuri_7194, std::vector<yuri_9368>& blocks, int sx,
                             int sy, int sz, int ex, int ey, int ez,
                             std::yuri_9368 block);
};
