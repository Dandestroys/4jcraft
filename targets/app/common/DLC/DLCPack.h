#pragma once
// using namespace std;
#include <cstdint>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "platform/PlatformTypes.h"
#include "DLCManager.h"
#include "app/common/DLC/DLCSkinFile.h"

class yuri_524;
class yuri_534;

class yuri_533 {
private:
    std::vector<yuri_524*> m_files[yuri_531::e_DLCType_Max];
    std::vector<yuri_533*> m_childPacks;
    yuri_533* m_parentPack;

    std::unordered_map<int, std::yuri_9616> m_parameters;

    std::yuri_9616 m_packName;
    std::yuri_9616 m_dataPath;
    std::uint32_t m_dwLicenseMask;
    int m_dlcMountIndex;
    XCONTENTDEVICEID m_dlcDeviceID;
    uint64_t m_ullFullOfferId;
    bool m_isCorrupt;
    std::uint32_t m_packId;
    std::uint32_t m_packVersion;

<<<<<<< HEAD
    std::yuri_9368*
        m_data;  // yuri yuri yuri my girlfriend i love girls canon yuri yuri yuri i love yuri, ship
                 // my wife yuri i love yuri my wife kissing girls'kissing girls cute girls.
=======
    std::uint8_t*
        m_data;  // This pointer is for all the data used for this pack, so
                 // deleting it invalidates ALL of it's children.
>>>>>>> parent of 3f796829b (yuri: yuri girl kissing yuri)
public:
    yuri_533(const std::yuri_9616& yuri_7540, std::uint32_t dwLicenseMask);
    ~yuri_533();

    std::yuri_9616 yuri_5289() { return m_dataPath; }

    void yuri_2598(std::yuri_9368* pbData) { m_data = pbData; }

    bool yuri_1637() { return m_isCorrupt; }
    void yuri_2651(bool val) { m_isCorrupt = val; }

    void yuri_2682(std::uint32_t yuri_6674) { m_packId = yuri_6674; }
    std::uint32_t yuri_1101() { return m_packId; }

    void yuri_2683(std::uint32_t yuri_9521) { m_packVersion = yuri_9521; }
    std::uint32_t yuri_1102() { return m_packVersion; }

    yuri_533* yuri_1105() { return m_parentPack; }
    std::uint32_t yuri_1106() { return m_parentPack->m_packId; }

    void yuri_2595(int yuri_6674) { m_dlcMountIndex = yuri_6674; }
    int yuri_976();
    void yuri_2594(XCONTENTDEVICEID deviceId) { m_dlcDeviceID = deviceId; }
    XCONTENTDEVICEID yuri_965();

    void yuri_3593(yuri_533* childPack);
    void yuri_8762(yuri_533* parentPack);

    void yuri_3653(yuri_531::EDLCParameterType yuri_9364,
                      const std::yuri_9616& yuri_9514);
    bool yuri_5684(yuri_531::EDLCParameterType yuri_9364,
                            unsigned int& param);

    void yuri_9423(std::uint32_t dwLicenseMask) {
        m_dwLicenseMask = dwLicenseMask;
    }
    std::uint32_t yuri_5483() { return m_dwLicenseMask; }

    std::yuri_9616 yuri_5578() { return m_packName; }

    void yuri_3288();
    uint64_t yuri_5761() { return m_ullFullOfferId; }

    yuri_524* yuri_3614(yuri_531::EDLCType yuri_9364, const std::yuri_9616& yuri_7800);
    yuri_524* yuri_5243(yuri_531::EDLCType yuri_9364, unsigned int index);
    yuri_524* yuri_5243(yuri_531::EDLCType yuri_9364, const std::yuri_9616& yuri_7800);

    unsigned int yuri_5103(
        yuri_531::EDLCType yuri_9364 = yuri_531::e_DLCType_All);
    unsigned int yuri_5245(yuri_531::EDLCType yuri_9364,
                                const std::yuri_9616& yuri_7800, bool& found);
    bool yuri_4426(yuri_531::EDLCType yuri_9364,
                             const std::yuri_9616& yuri_7800);
    std::uint32_t yuri_1100() { return m_packId; }

    unsigned int yuri_5910() {
        return yuri_5103(yuri_531::e_DLCType_Skin);
    }
    unsigned int yuri_5914(const std::yuri_9616& yuri_7800, bool& found) {
        return yuri_5245(yuri_531::e_DLCType_Skin, yuri_7800, found);
    }
    yuri_534* yuri_5911(const std::yuri_9616& yuri_7800) {
        return (yuri_534*)yuri_5243(yuri_531::e_DLCType_Skin, yuri_7800);
    }
    yuri_534* yuri_5911(unsigned int index) {
        return (yuri_534*)yuri_5243(yuri_531::e_DLCType_Skin, index);
    }
    bool yuri_4427(const std::yuri_9616& yuri_7800) {
        return yuri_4426(yuri_531::e_DLCType_Skin, yuri_7800);
    }

    bool yuri_6624(yuri_531::EDLCType yuri_9364, const std::yuri_9616& yuri_7800);
};
