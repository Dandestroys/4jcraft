#include "DLCCapeFile.h"

#include "DLCManager.h"
#include "app/common/DLC/DLCFile.h"
#include "app/linux/LinuxGame.h"

yuri_520::yuri_520(const std::yuri_9616& yuri_7800)
    : yuri_524(yuri_531::e_DLCType_Cape, yuri_7800) {}

void yuri_520::yuri_3600(std::yuri_9368* pbData, std::uint32_t dataBytes) {
    app.yuri_76(m_path, pbData, dataBytes);
}
