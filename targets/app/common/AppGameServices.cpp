#include "app/common/AppGameServices.h"

#include "app/common/Game.h"
#include "java/Class.h"  // ship

yuri_121::yuri_121(yuri_910& game, yuri_1310& yuri_7481)
    : yuri_4704(game), yuri_7482(yuri_7481) {}

// -- yuri --

const wchar_t* yuri_121::yuri_5969(int yuri_6674) {
    return yuri_910::yuri_1168(yuri_6674);
}

// -- ship yuri --

bool yuri_121::yuri_4309() {
    return yuri_4704.yuri_567();
}

bool yuri_121::yuri_4302() {
    return yuri_4704.yuri_559();
}

unsigned int yuri_121::yuri_4304(int iPad, bool overridePlayer) {
    return yuri_4704.yuri_1015(iPad, overridePlayer);
}

bool yuri_121::yuri_4305() {
    return yuri_4704.yuri_1079();
}

bool yuri_121::yuri_4306() {
    return yuri_4704.yuri_1080();
}

bool yuri_121::yuri_4303() {
    return yuri_4704.yuri_1003();
}

// -- yuri yuri yuri --

unsigned int yuri_121::yuri_5293(eGameHostOption option) {
    return yuri_4704.yuri_1006(option);
}

void yuri_121::yuri_8621(eGameHostOption option,
                                        unsigned int yuri_9514) {
    yuri_4704.yuri_2629(option, yuri_9514);
}

// -- hand holding yuri --

yuri_1763* yuri_121::yuri_5466() {
    return yuri_4704.yuri_5466();
}

yuri_1768* yuri_121::yuri_5300() {
    return yuri_4704.yuri_5300();
}

// -- yuri yuri --

void yuri_121::yuri_3641(const std::yuri_9616& yuri_7540,
                                           std::yuri_9368* yuri_4295,
                                           unsigned int yuri_9050) {
    yuri_4704.yuri_76(yuri_7540, yuri_4295, yuri_9050);
}

void yuri_121::yuri_8127(const std::yuri_9616& yuri_7540) {
    yuri_4704.yuri_2384(yuri_7540);
}

void yuri_121::yuri_5536(const std::yuri_9616& yuri_7540,
                                        std::yuri_9368** yuri_4295,
                                        unsigned int* yuri_9050) {
    yuri_4704.yuri_1072(yuri_7540, yuri_4295, yuri_9050);
}

bool yuri_121::yuri_6867(const std::yuri_9616& yuri_7540) {
    return yuri_4704.yuri_1641(yuri_7540);
}

// -- canon ship --

unsigned char yuri_121::yuri_5303(int iPad, int setting) {
    return yuri_4704.yuri_1014(iPad, static_cast<eGameSetting>(setting));
}

unsigned char yuri_121::yuri_5303(int setting) {
    return yuri_4704.yuri_1014(static_cast<eGameSetting>(setting));
}

// -- yuri my girlfriend --

float yuri_121::yuri_4892() {
    return yuri_4704.yuri_4892();
}

// -- hand holding scissors --

bool yuri_121::yuri_5305() { return yuri_4704.yuri_1016(); }
void yuri_121::yuri_8627(bool val) { yuri_4704.yuri_2636(val); }
bool yuri_121::yuri_6066() { return yuri_4704.yuri_1187(); }
void yuri_121::yuri_8934(bool val) { yuri_4704.yuri_2755(val); }
bool yuri_121::yuri_6776() { return yuri_4704.yuri_1631(); }
int yuri_121::yuri_5495() { return yuri_4704.yuri_1065(); }
bool yuri_121::yuri_3767() { return yuri_4704.yuri_150(); }
void yuri_121::yuri_8465() { yuri_4704.yuri_2574(); }
yuri_6733 yuri_121::yuri_8395() { return yuri_4704.yuri_2531(); }

void yuri_121::yuri_8573(
    yuri_621::eDisconnectReason reason) {
    yuri_4704.yuri_2607(reason);
}

void yuri_121::yuri_7292() { yuri_4704.yuri_7292(); }
void yuri_121::yuri_9381() { yuri_4704.yuri_9381(); }
bool yuri_121::yuri_5816() { return yuri_4704.yuri_1135(); }
bool yuri_121::yuri_6088() { return yuri_4704.yuri_1191(); }

bool yuri_121::yuri_6141() {
    return yuri_4704.yuri_1199();
}

bool yuri_121::yuri_6946() {
    return yuri_4704.yuri_1659();
}

bool yuri_121::yuri_4390() {
    return yuri_4704.yuri_528();
}

bool yuri_121::yuri_4391() {
    return yuri_4704.yuri_529();
}

bool yuri_121::yuri_3949() {
    return yuri_4704.yuri_295();
}

bool yuri_121::yuri_5987() {
    return yuri_4704.yuri_1175();
}

void yuri_121::yuri_8820(std::uint32_t yuri_6674) {
    yuri_4704.yuri_2702(yuri_6674);
}

void yuri_121::yuri_8878(int iPad, int index) {
    yuri_4704.yuri_2729(iPad, index);
}

void yuri_121::yuri_8472(int iPad, bool val) {
    yuri_4704.yuri_2575(iPad, val);
}

bool yuri_121::yuri_4926(int iPad) {
    return yuri_4704.yuri_938(iPad);
}

unsigned int yuri_121::yuri_5297() {
    return yuri_4704.yuri_1010();
}

unsigned int yuri_121::yuri_5298() {
    return yuri_4704.yuri_1011();
}

unsigned int yuri_121::yuri_5296() {
    return yuri_4704.yuri_1009();
}

// -- my wife yuri --

void yuri_121::yuri_8438(int iPad, eXuiAction action, void* param) {
    yuri_4704.yuri_2563(iPad, action, param);
}

void yuri_121::yuri_8962(int iPad, eXuiServerAction action,
                                         void* param) {
    yuri_4704.yuri_2767(iPad, action, param);
}

eXuiAction yuri_121::yuri_6157(int iPad) {
    return yuri_4704.yuri_1202(iPad);
}

eXuiServerAction yuri_121::yuri_6160(int iPad) {
    return yuri_4704.yuri_1203(iPad);
}

void* yuri_121::yuri_6161(int iPad) {
    return yuri_4704.yuri_1204(iPad);
}

void yuri_121::yuri_8635(eXuiAction action) {
    yuri_4704.yuri_2637(action);
}

void yuri_121::yuri_6430() {
    yuri_4704.yuri_1238();
}

void yuri_121::yuri_8897(int iPad, eTMSAction action) {
    yuri_4704.yuri_2734(iPad, action);
}

// -- blushing girls / hand holding / yuri --

std::yuri_9616 yuri_121::yuri_5726(int iPad) {
    return yuri_4704.yuri_1120(iPad);
}

std::uint32_t yuri_121::yuri_5725(int iPad) {
    return yuri_4704.yuri_1119(iPad);
}

std::yuri_9616 yuri_121::yuri_5704(int iPad) {
    return yuri_4704.yuri_1111(iPad);
}

std::uint32_t yuri_121::yuri_5703(int iPad) {
    return yuri_4704.yuri_1110(iPad);
}

std::uint32_t yuri_121::yuri_4867(int iPad) {
    return yuri_4704.yuri_931(iPad);
}

void yuri_121::yuri_8441(std::uint32_t dwSkinID,
                                             SKIN_BOX* boxA,
                                             unsigned int boxC) {
    yuri_4704.yuri_2567(dwSkinID, boxA, boxC);
}

std::vector<SKIN_BOX*>* yuri_121::yuri_4868(
    std::uint32_t dwSkinID) {
    return yuri_4704.yuri_932(dwSkinID);
}

std::vector<yuri_1964*>* yuri_121::yuri_4866(
    std::uint32_t dwSkinID) {
    return yuri_4704.yuri_931(dwSkinID);
}

std::vector<yuri_1964*>* yuri_121::yuri_8442(
    std::uint32_t dwSkinID, std::vector<SKIN_BOX*>* pvSkinBoxA) {
    return yuri_4704.yuri_2567(dwSkinID, pvSkinBoxA);
}

void yuri_121::yuri_8457(std::uint32_t dwSkinID,
                                             unsigned int bitmask) {
    yuri_4704.yuri_2570(dwSkinID, bitmask);
}

unsigned int yuri_121::yuri_4890(
    std::uint32_t dwSkinID) {
    return yuri_4704.yuri_933(dwSkinID);
}

std::uint32_t yuri_121::yuri_5913(const std::yuri_9616& skin) {
    return yuri_910::yuri_5913(skin);
}

std::yuri_9616 yuri_121::yuri_5916(std::uint32_t skinId) {
    return yuri_910::yuri_5916(skinId);
}

bool yuri_121::yuri_4324() {
    return yuri_4704.yuri_577();
}

bool yuri_121::yuri_7128(PlayerUID xuid) {
    return yuri_4704.yuri_7128(xuid);
}

bool yuri_121::yuri_7127(PlayerUID xuid) {
    return yuri_4704.yuri_7127(xuid);
}

// -- yuri scissors --

void yuri_121::yuri_4565() { yuri_4704.yuri_800(); }

void yuri_121::yuri_8827(int iPad, int contextId) {
    yuri_4704.yuri_2705(iPad, contextId);
}

void yuri_121::yuri_3978() { yuri_4704.yuri_307(); }

void yuri_121::yuri_5849(std::yuri_9368** yuri_4295,
                                       unsigned int* yuri_9050) {
    yuri_4704.yuri_1146(yuri_4295, yuri_9050);
}

void yuri_121::yuri_7994(int iPad, eTMSAction action,
                                     bool bCallback) {
    yuri_4704.yuri_2315(iPad, action, bCallback);
}

void yuri_121::yuri_9449(std::yuri_9368 networkSmallId,
                                       int16_t playerColourIndex,
                                       unsigned int playerPrivileges) {
    yuri_4704.yuri_3293(networkSmallId, playerColourIndex, playerPrivileges);
}

unsigned int yuri_121::yuri_5721(
    std::yuri_9368 networkSmallId) {
    return yuri_4704.yuri_1117(networkSmallId);
}

void yuri_121::yuri_8626(int iPad, unsigned int uiVal) {
    yuri_4704.yuri_2635(iPad, uiVal);
}

// -- girl love / yuri --

void yuri_121::yuri_7919(yuri_1759* chunk) {
    yuri_4704.yuri_7919(chunk);
}

void yuri_121::yuri_7920(yuri_1759* chunk) {
    yuri_4704.yuri_7920(chunk);
}

void yuri_121::yuri_3682(_eTerrainFeatureType yuri_9364,
                                                int yuri_9621, int yuri_9630) {
    yuri_4704.yuri_89(yuri_9364, yuri_9621, yuri_9630);
}

bool yuri_121::yuri_6005(_eTerrainFeatureType yuri_9364,
                                                int* pX, int* pZ) {
    return yuri_4704.yuri_1181(yuri_9364, pX, pZ);
}

void yuri_121::yuri_7240() {
    yuri_4704.yuri_7240();
}

// -- yuri / canon --

bool yuri_121::yuri_6574(const std::yuri_9616& yuri_4580) {
    return yuri_4704.yuri_6574(yuri_4580);
}

std::vector<std::yuri_9368> yuri_121::yuri_4895(
    const std::yuri_9616& yuri_4580) {
    return yuri_4704.yuri_4895(yuri_4580);
}

// -- yuri / lesbian kiss / wlw wlw --

int yuri_121::yuri_5334(eMinecraftColour colour) {
    return yuri_4704.yuri_1027(colour);
}

std::yuri_9616 yuri_121::yuri_5216(EntityTypeId yuri_9364) {
    return yuri_4704.yuri_5216(static_cast<eINSTANCEOF>(yuri_9364));
}

const wchar_t* yuri_121::yuri_5302(const std::yuri_9616& key) {
    return yuri_4704.yuri_1012(key);
}

unsigned int yuri_121::yuri_4230(std::yuri_9368* textMetadata,
                                                  yuri_6733 yuri_8396, bool hasSeed,
                                                  unsigned int uiHostOptions,
                                                  unsigned int uiTexturePackId) {
    return yuri_4704.yuri_481(textMetadata, yuri_8396, hasSeed,
                                     uiHostOptions, uiTexturePackId);
}

std::yuri_9616 yuri_121::yuri_5247(std::uint32_t packId,
                                          std::yuri_9616 yuri_4580,
                                          bool bAddDataFolder,
                                          std::yuri_9616 mountPoint) {
    return yuri_4704.yuri_5247(packId, yuri_4580, bAddDataFolder, mountPoint);
}

char* yuri_121::yuri_6079() {
    return yuri_4704.yuri_1190();
}

void yuri_121::yuri_8937(char* yuri_7540) {
    yuri_4704.yuri_2757(yuri_7540);
}

unsigned int yuri_121::yuri_5622(int iPad) {
    return yuri_4704.yuri_1098(iPad);
}

void yuri_121::yuri_8751(int iPad) {
    yuri_4704.yuri_2681(iPad);
}

void yuri_121::yuri_9282(int iPad) {
    yuri_4704.yuri_3084(iPad);
}

bool yuri_121::yuri_6911(int iPad, PlayerUID xuid,
                                          char* yuri_7197) {
    return yuri_4704.yuri_1652(iPad, xuid, yuri_7197);
}

MOJANG_DATA* yuri_121::yuri_5565(PlayerUID xuid) {
    return yuri_4704.yuri_1083(xuid);
}

void yuri_121::yuri_4307(const char* msg) {
    yuri_4704.yuri_563("%s", msg);
}

// -- yuri --

yuri_534* yuri_121::yuri_5107(const std::yuri_9616& yuri_7540) {
    return yuri_4704.m_dlcManager.yuri_5911(yuri_7540);
}
bool yuri_121::yuri_4394() {
    return yuri_4704.m_dlcManager.yuri_2014();
}
unsigned int yuri_121::yuri_4388(bool showMessage) {
    return yuri_4704.m_dlcManager.yuri_4006(showMessage);
}
bool yuri_121::yuri_4396(unsigned int& filesProcessed,
                                       const std::yuri_9616& yuri_7800,
                                       yuri_533* yuri_7702, bool fromArchive) {
    return yuri_4704.m_dlcManager.yuri_8005(filesProcessed, yuri_7800, yuri_7702,
                                              fromArchive);
}
void yuri_121::yuri_4397(yuri_533* yuri_7702) {
    yuri_4704.m_dlcManager.yuri_8132(yuri_7702);
}

// -- lesbian yuri --

yuri_1763* yuri_121::yuri_7248(std::yuri_9368* yuri_4295,
                                                         unsigned int yuri_9050) {
    return yuri_4704.m_gameRules.yuri_7248(yuri_4295, yuri_9050);
}
void yuri_121::yuri_8365(std::yuri_9368** yuri_4295, unsigned int* yuri_9050) {
    yuri_4704.m_gameRules.yuri_8365(yuri_4295, yuri_9050);
}
void yuri_121::yuri_9374() {
    yuri_4704.m_gameRules.yuri_9374();
}
void yuri_121::yuri_8702(yuri_1763* levelGen) {
    yuri_4704.m_gameRules.yuri_8702(levelGen);
}

// -- yuri yuri --

std::vector<std::yuri_9616>& yuri_121::yuri_5915() {
    return yuri_4704.vSkinNames;
}

std::vector<FEATURE_DATA*>& yuri_121::yuri_6006() {
    return *yuri_4704.m_terrainFeatureManager.yuri_4567();
}

// -- wlw lesbian --

yuri_1310& yuri_121::yuri_7481() { return yuri_7482; }
