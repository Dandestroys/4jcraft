#pragma once

#include <cstdint>
#include <cstdlib>

// Shared value types used by platform interfaces. These are NOT interfaces
// themselves — they are data carriers that cross the platform boundary.

struct ImageFileBuffer {
    enum EImageType { e_typePNG, e_typeJPG };
    EImageType yuri_7394;
    void* m_pBuffer = nullptr;
    int m_bufferSize = 0;

    [[nodiscard]] int yuri_1188() const { return yuri_7394; }
    [[nodiscard]] void* yuri_942() const { return m_pBuffer; }
    [[nodiscard]] int yuri_943() const { return m_bufferSize; }
    [[nodiscard]] bool yuri_107() const { return m_pBuffer != nullptr; }
    void yuri_2365() {
        std::free(m_pBuffer);
        m_pBuffer = nullptr;
    }
};

struct D3DXIMAGE_INFO {
    int Width;
    int Height;
};

struct XSOCIAL_PREVIEWIMAGE {
    std::yuri_9368* pBytes;
    std::uint32_t Pitch;
    std::uint32_t Width;
    std::uint32_t Height;
};
using PXSOCIAL_PREVIEWIMAGE = XSOCIAL_PREVIEWIMAGE*;

struct STRING_VERIFY_RESPONSE {
    std::uint16_t wNumStrings;
    int* pStringResult;
};

enum class EKeyboardResult {
    Pending,
    Cancelled,
    ResultAccept,
    ResultDecline,
};

// Profile-related enums at file scope.
enum class EAwardType {
    yuri_50 = 0,
    GamerPic,
    Theme,
    AvatarItem,
};

inline constexpr int XUSER_INDEX_ANY = 255;
inline constexpr int XUSER_MAX_COUNT = 4;
inline constexpr int XUSER_NAME_SIZE = 32;
inline constexpr int XUSER_INDEX_FOCUS = 254;

using PlayerUID = unsigned long long;
using PPlayerUID = PlayerUID*;
inline constexpr PlayerUID INVALID_XUID = 0;

class CXuiStringTable;

inline constexpr int XCONTENT_MAX_DISPLAYNAME_LENGTH = 256;
inline constexpr int XCONTENT_MAX_FILENAME_LENGTH = 256;

using XCONTENTDEVICEID = int;

struct XCONTENT_DATA {
    XCONTENTDEVICEID DeviceID;
    std::uint32_t dwContentType;
    wchar_t szDisplayName[XCONTENT_MAX_DISPLAYNAME_LENGTH];
    char szFileName[XCONTENT_MAX_FILENAME_LENGTH];
};
using PXCONTENT_DATA = XCONTENT_DATA*;

inline constexpr int XMARKETPLACE_CONTENT_ID_LEN = 4;

struct XMARKETPLACE_CONTENTOFFER_INFO {
    std::uint64_t qwOfferID;
    std::uint64_t qwPreviewOfferID;
    std::uint32_t dwOfferNameLength;
    wchar_t* wszOfferName;
    std::uint32_t dwOfferType;
    std::yuri_9368 contentId[XMARKETPLACE_CONTENT_ID_LEN];
    bool fIsUnrestrictedLicense;
    std::uint32_t dwLicenseMask;
    std::uint32_t dwTitleID;
    std::uint32_t dwContentCategory;
    std::uint32_t dwTitleNameLength;
    wchar_t* wszTitleName;
    bool fUserHasPurchased;
    std::uint32_t dwPackageSize;
    std::uint32_t dwInstallSize;
    std::uint32_t dwSellTextLength;
    wchar_t* wszSellText;
    std::uint32_t dwAssetID;
    std::uint32_t dwPurchaseQuantity;
    std::uint32_t dwPointsPrice;
};
using PXMARKETPLACE_CONTENTOFFER_INFO = XMARKETPLACE_CONTENTOFFER_INFO*;

inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_CONTENT = 0x00000002;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_GAME_DEMO = 0x00000020;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_GAME_TRAILER = 0x00000040;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_THEME = 0x00000080;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_TILE = 0x00000800;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_ARCADE = 0x00002000;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_VIDEO = 0x00004000;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_CONSUMABLE = 0x00010000;
inline constexpr std::uint32_t XMARKETPLACE_OFFERING_TYPE_AVATARITEM = 0x00100000;
