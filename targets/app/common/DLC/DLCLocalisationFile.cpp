#include "DLCLocalisationFile.h"

#include "DLCManager.h"
#include "app/common/DLC/DLCFile.h"
#include "app/common/Localisation/StringTable.h"

yuri_530::yuri_530(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_LocalisationData, yuri_7800) {
    m_strings = nullptr;
}

void yuri_530::yuri_3600(std::yuri_9368* pbData,
                                  std::uint32_t dataBytes) {
    m_strings = new yuri_2974(pbData, dataBytes);
}
