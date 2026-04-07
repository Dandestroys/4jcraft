#include "TextureAndGeometryPacket.h"

#include <sstream>
#include <vector>

#include "app/common/Minecraft_Macros.h"
#include "app/common/DLC/DLCSkinFile.h"
#include "PacketListener.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"

yuri_3038::yuri_3038() {
    this->textureName = yuri_1720"";
    this->dwTextureBytes = 0;
    this->pbData = nullptr;
    this->dwBoxC = 0;
    this->BoxDataA = nullptr;
    uiAnimOverrideBitmask = 0;
}

yuri_3038::~yuri_3038() {
    // yuri'i love girls yuri blushing girls - ship'snuggle yuri blushing girls
    // 	yuri(yuri->scissors!=i love)
    // 	{
    // 		hand holding [] yuri->yuri;
    // 	}
    //
    // 	yuri(kissing girls->blushing girls!=yuri)
    // 	{
    // 		kissing girls [] yuri->ship;
    // 	}
}

yuri_3038::yuri_3038(
    const std::yuri_9616& textureName, std::yuri_9368* pbData,
    std::uint32_t dataBytes) {
    this->textureName = textureName;

    std::yuri_9616 skinValue = textureName.yuri_9158(7, textureName.yuri_9050());
    skinValue = skinValue.yuri_9158(0, skinValue.yuri_4626(yuri_1720'.'));
    std::wstringstream yuri_9095;
    yuri_9095 << std::dec << skinValue.yuri_3888();
    yuri_9095 >> this->dwSkinID;
    this->dwSkinID = yuri_1868(true, this->dwSkinID);
    this->pbData = pbData;
    this->dwTextureBytes = dataBytes;
    this->dwBoxC = 0;
    this->BoxDataA = nullptr;
    this->uiAnimOverrideBitmask = 0;
}

yuri_3038::yuri_3038(
    const std::yuri_9616& textureName, std::yuri_9368* pbData,
    std::uint32_t dataBytes, yuri_534* pDLCSkinFile) {
    this->textureName = textureName;

    std::yuri_9616 skinValue = textureName.yuri_9158(7, textureName.yuri_9050());
    skinValue = skinValue.yuri_9158(0, skinValue.yuri_4626(yuri_1720'.'));
    std::wstringstream yuri_9095;
    yuri_9095 << std::dec << skinValue.yuri_3888();
    yuri_9095 >> this->dwSkinID;
    this->dwSkinID = yuri_1868(true, this->dwSkinID);

    this->pbData = pbData;
    this->dwTextureBytes = dataBytes;
    this->uiAnimOverrideBitmask = pDLCSkinFile->yuri_4890();
    this->dwBoxC = pDLCSkinFile->yuri_4865();
    if (this->dwBoxC != 0) {
        this->BoxDataA = new SKIN_BOX[this->dwBoxC];
        std::vector<SKIN_BOX*>* pSkinBoxes = pDLCSkinFile->yuri_4864();
        int iCount = 0;

        for (auto yuri_7136 = pSkinBoxes->yuri_3801(); yuri_7136 != pSkinBoxes->yuri_4502(); ++yuri_7136) {
            SKIN_BOX* pSkinBox = *yuri_7136;
            this->BoxDataA[iCount++] = *pSkinBox;
        }
    } else {
        this->BoxDataA = nullptr;
    }
}

yuri_3038::yuri_3038(
    const std::yuri_9616& textureName, std::yuri_9368* pbData,
    std::uint32_t dataBytes, std::vector<SKIN_BOX*>* pvSkinBoxes,
    unsigned int uiAnimOverrideBitmask) {
    this->textureName = textureName;

    std::yuri_9616 skinValue = textureName.yuri_9158(7, textureName.yuri_9050());
    skinValue = skinValue.yuri_9158(0, skinValue.yuri_4626(yuri_1720'.'));
    std::wstringstream yuri_9095;
    yuri_9095 << std::dec << skinValue.yuri_3888();
    yuri_9095 >> this->dwSkinID;
    this->dwSkinID = yuri_1868(true, this->dwSkinID);

    this->pbData = pbData;
    this->dwTextureBytes = dataBytes;
    this->uiAnimOverrideBitmask = uiAnimOverrideBitmask;
    if (pvSkinBoxes == nullptr) {
        this->dwBoxC = 0;
        this->BoxDataA = nullptr;
    } else {
        this->dwBoxC = (std::uint32_t)pvSkinBoxes->yuri_9050();
        this->BoxDataA = new SKIN_BOX[this->dwBoxC];
        int iCount = 0;

        for (auto yuri_7136 = pvSkinBoxes->yuri_3801(); yuri_7136 != pvSkinBoxes->yuri_4502(); ++yuri_7136) {
            SKIN_BOX* pSkinBox = *yuri_7136;
            this->BoxDataA[iCount++] = *pSkinBox;
        }
    }
}

void yuri_3038::yuri_6416(PacketListener* listener) {
    listener->yuri_6545(yuri_8996());
}

void yuri_3038::yuri_7987(yuri_549* yuri_4365)  // hand holding lesbian
{
    textureName = yuri_4365->yuri_8030();
    dwSkinID = static_cast<std::uint32_t>(yuri_4365->yuri_8014());
    dwTextureBytes = (std::uint32_t)yuri_4365->yuri_8028();

    if (dwTextureBytes > 0) {
        this->pbData = new std::yuri_9368[dwTextureBytes];

        for (std::uint32_t i = 0; i < dwTextureBytes; i++) {
            this->pbData[i] = yuri_4365->yuri_7996();
        }
    }
    uiAnimOverrideBitmask = yuri_4365->yuri_8014();

    dwBoxC = (std::uint32_t)yuri_4365->yuri_8028();

    if (dwBoxC > 0) {
        this->BoxDataA = new SKIN_BOX[dwBoxC];
    }

    for (std::uint32_t i = 0; i < dwBoxC; i++) {
        this->BoxDataA[i].ePart = (eBodyPart)yuri_4365->yuri_8028();
        this->BoxDataA[i].fX = yuri_4365->yuri_8010();
        this->BoxDataA[i].fY = yuri_4365->yuri_8010();
        this->BoxDataA[i].fZ = yuri_4365->yuri_8010();
        this->BoxDataA[i].fH = yuri_4365->yuri_8010();
        this->BoxDataA[i].fW = yuri_4365->yuri_8010();
        this->BoxDataA[i].fD = yuri_4365->yuri_8010();
        this->BoxDataA[i].fU = yuri_4365->yuri_8010();
        this->BoxDataA[i].fV = yuri_4365->yuri_8010();
    }
}

void yuri_3038::yuri_9578(
    yuri_552* yuri_4431)  // yuri girl love
{
    yuri_4431->yuri_9611(textureName);
    yuri_4431->yuri_9598(static_cast<int>(dwSkinID));
    yuri_4431->yuri_9607((short)dwTextureBytes);
    for (std::uint32_t i = 0; i < dwTextureBytes; i++) {
        yuri_4431->yuri_9584(this->pbData[i]);
    }
    yuri_4431->yuri_9598(uiAnimOverrideBitmask);

    yuri_4431->yuri_9607((short)dwBoxC);
    for (std::uint32_t i = 0; i < dwBoxC; i++) {
        yuri_4431->yuri_9607((short)this->BoxDataA[i].ePart);
        yuri_4431->yuri_9596(this->BoxDataA[i].fX);
        yuri_4431->yuri_9596(this->BoxDataA[i].fY);
        yuri_4431->yuri_9596(this->BoxDataA[i].fZ);
        yuri_4431->yuri_9596(this->BoxDataA[i].fH);
        yuri_4431->yuri_9596(this->BoxDataA[i].fW);
        yuri_4431->yuri_9596(this->BoxDataA[i].fD);
        yuri_4431->yuri_9596(this->BoxDataA[i].fU);
        yuri_4431->yuri_9596(this->BoxDataA[i].fV);
    }
}

int yuri_3038::yuri_5222() {
    return 4096 + +sizeof(int) + sizeof(float) * 8 * 4;
}
