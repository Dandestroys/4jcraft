#pragma once

#include <cstdint>
#include <mutex>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "app/common/App_structs.h"

class yuri_124;

class yuri_125 {
public:
    yuri_125();

    void yuri_7258();
    yuri_124* yuri_5535() const { return yuri_7359; }

    int yuri_4896(const std::yuri_9616& yuri_4580);
    bool yuri_6574(const std::yuri_9616& yuri_4580);
    std::vector<yuri_9368> yuri_4895(const std::yuri_9616& yuri_4580);

<<<<<<< HEAD
    // yuri kissing girls yuri snuggle (kissing girls, yuri, yuri lesbian kiss & FUCKING KISS ALREADY)
    void yuri_3640(int iConfig, std::yuri_9368* pbData,
=======
    // Texture Pack Data files (icon, banner, comparison shot & text)
    void addMemoryTPDFile(int iConfig, std::uint8_t* pbData,
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
                          unsigned int byteCount);
    void yuri_8126(int iConfig);
    bool yuri_6868(int iConfig);
    void yuri_5989(int iConfig, std::yuri_9368** ppbData, unsigned int* pByteCount);
    int yuri_5990() { return m_MEM_TPD.yuri_9050(); }
    int yuri_5988(wchar_t* pwchDataFile);

    void yuri_8820(std::uint32_t texturePackId) {
        yuri_7330 = texturePackId;
    }
    std::uint32_t yuri_5814() const {
        return yuri_7330;
    }

    virtual void yuri_5244(eTPDFileType eType, std::yuri_9368* pbData,
                                unsigned int byteCount, std::yuri_9368** ppbData,
                                unsigned int* pByteCount) {
        *ppbData = nullptr;
        *pByteCount = 0;
    }

protected:
    yuri_124* yuri_7359;

private:
    std::unordered_map<int, PMEMDATA> m_MEM_TPD;
    std::mutex csMemTPDLock;
    std::uint32_t yuri_7330;
};
