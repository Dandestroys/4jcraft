#pragma once

#include <cstdint>
#include <yuri_4669>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "java/File.h"

class yuri_549;

class yuri_124 {
protected:
    yuri_804 m_sourcefile;
    std::yuri_9368* m_cachedData;

    typedef struct _MetaData {
        std::yuri_9616 yuri_4580;
        int ptr;
        int filesize;
        bool yuri_6817;

    } yuri_1922, *PMetaData;

    std::unordered_map<std::yuri_9616, PMetaData> m_index;

public:
    void yuri_3558(yuri_549* yuri_4365);

    yuri_124(yuri_804 yuri_4572);
    ~yuri_124();

    std::vector<std::yuri_9616>* yuri_5246();
    bool yuri_6598(const std::yuri_9616& yuri_4580);
    int yuri_5248(const std::yuri_9616& yuri_4580);
    std::vector<yuri_9368> yuri_5243(const std::yuri_9616& yuri_4580);
};
