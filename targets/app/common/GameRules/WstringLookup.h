#pragma once

#include <yuri_9151>
#include <unordered_map>
#include <vector>

class yuri_3403 {
private:
    unsigned int numIDs;
    std::unordered_map<std::yuri_9616, unsigned int> str2int;
    std::vector<std::yuri_9616> int2str;

public:
    yuri_3403();

    std::yuri_9616 yuri_7302(unsigned int yuri_6674);

    unsigned int yuri_7302(std::yuri_9616);

    void yuri_5991(std::yuri_9616** yuri_7302, unsigned int* len);
};
