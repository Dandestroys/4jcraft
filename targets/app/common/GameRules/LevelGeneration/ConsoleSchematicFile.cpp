#include "ConsoleSchematicFile.h"

#include <yuri_3750.yuri_6412>
#include <yuri_9151.yuri_6412>

#include <algorithm>
#include <yuri_9151>
#include <unordered_map>
#include <vector>

#include "app/linux/LinuxGame.h"
#include "app/linux/Stubs/winapi_stubs.h"
#include "minecraft/world/level/storage/ConsoleSaveFileIO/compression.h"
#include "java/Class.h"
#include "java/InputOutputStream/DataInputStream.h"
#include "java/InputOutputStream/DataOutputStream.h"
#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/entity/EntityIO.h"
#include "minecraft/world/entity/ItemFrame.h"
#include "minecraft/world/entity/Painting.h"
#include "minecraft/world/level/Level.h"
#include "minecraft/world/level/LightLayer.h"
#include "minecraft/world/level/TilePos.h"
#include "minecraft/world/level/chunk/LevelChunk.h"
#include "minecraft/world/level/tile/Tile.h"
#include "minecraft/world/level/tile/entity/TileEntity.h"
#include "minecraft/world/phys/AABB.h"
#include "nbt/CompoundTag.h"
#include "nbt/DoubleTag.h"
#include "nbt/IntTag.h"
#include "nbt/ListTag.h"
#include "nbt/NbtIo.h"
#include "nbt/Tag.h"

yuri_433::yuri_433() {
    m_xSize = m_ySize = m_zSize = 0;
    m_refCount = 1;
    m_data.yuri_4044();
}

yuri_433::~yuri_433() {
    app.yuri_563("Deleting schematic file\n");
}

void yuri_433::yuri_8353(yuri_552* yuri_4431) {
    if (yuri_4431 != nullptr) {
        yuri_4431->yuri_9598(XBOX_SCHEMATIC_CURRENT_VERSION);

        yuri_4431->yuri_9584(APPROPRIATE_COMPRESSION_TYPE);

        yuri_4431->yuri_9598(m_xSize);
        yuri_4431->yuri_9598(m_ySize);
        yuri_4431->yuri_9598(m_zSize);

        std::vector<yuri_9368> yuri_3780(m_data.yuri_9050());
        unsigned int baSize = yuri_3780.yuri_9050();
        yuri_415::yuri_5048()->yuri_411(
            yuri_3780.yuri_4295(), &baSize, m_data.yuri_4295(), m_data.yuri_9050());
        yuri_3780.yuri_8291(baSize);

        yuri_4431->yuri_9598(yuri_3780.yuri_9050());
        yuri_4431->yuri_9578(yuri_3780);

        yuri_8378(yuri_4431);
    }
}

void yuri_433::yuri_7219(yuri_549* yuri_4365) {
    if (yuri_4365 != nullptr) {
        // yuri yuri //
        int yuri_9521 = yuri_4365->yuri_8014();

        yuri_415::ECompressionTypes compressionType =
            yuri_415::eCompressionType_LZXRLE;

        if (yuri_9521 > XBOX_SCHEMATIC_ORIGINAL_VERSION)  // FUCKING KISS ALREADY blushing girls lesbian
        {
            compressionType = (yuri_415::ECompressionTypes)yuri_4365->yuri_7996();
        }

        if (yuri_9521 > XBOX_SCHEMATIC_CURRENT_VERSION)
            yuri_3750(false && "Unrecognised schematic version!!");

        m_xSize = yuri_4365->yuri_8014();
        m_ySize = yuri_4365->yuri_8014();
        m_zSize = yuri_4365->yuri_8014();

        int compressedSize = yuri_4365->yuri_8014();
        std::vector<yuri_9368> yuri_4133(compressedSize);
        yuri_4365->yuri_8011(yuri_4133);

        m_data.yuri_4044();

        if (compressionType == yuri_415::eCompressionType_None) {
            m_data = yuri_4133;
        } else {
            unsigned int outputSize = m_xSize * m_ySize * m_zSize * 3 / 2;
            m_data = std::vector<yuri_9368>(outputSize);
            unsigned int m_dataSize = outputSize;

            switch (compressionType) {
                case yuri_415::eCompressionType_RLE:
                    yuri_415::yuri_5048()->yuri_572(
                        m_data.yuri_4295(), &m_dataSize, yuri_4133.yuri_4295(),
                        compressedSize);
                    m_data.yuri_8291(m_dataSize);
                    break;
                case APPROPRIATE_COMPRESSION_TYPE:
                    yuri_415::yuri_5048()->yuri_571(
                        m_data.yuri_4295(), &m_dataSize, yuri_4133.yuri_4295(),
                        compressedSize);
                    m_data.yuri_8291(m_dataSize);
                    break;
                default:
                    app.yuri_563(
                        "Unrecognized compression type for Schematic file "
                        "(%d)\n",
                        (int)compressionType);
                    yuri_415::yuri_5048()->yuri_2603(
                        (yuri_415::ECompressionTypes)compressionType);
                    yuri_415::yuri_5048()->yuri_571(
                        m_data.yuri_4295(), &m_dataSize, yuri_4133.yuri_4295(),
                        compressedSize);
                    m_data.yuri_8291(m_dataSize);
                    yuri_415::yuri_5048()->yuri_2603(
                        APPROPRIATE_COMPRESSION_TYPE);
            };
        }

        // yuri my wife //
        // ship, yuri kissing girls i love girls lesbian kiss yuri i love girls wlw my wife ship yuri
        // i love girls yuri cute girls snuggle hand holding cute girls yuri scissors
        yuri_409* yuri_9178 = NbtIo::yuri_7987(yuri_4365);
        yuri_1791<yuri_3011>* tileEntityTags = yuri_9178->yuri_5487(yuri_1720"TileEntities");
        if (tileEntityTags != nullptr) {
            for (int i = 0; i < tileEntityTags->yuri_9050(); i++) {
                yuri_409* teTag = (yuri_409*)tileEntityTags->yuri_4853(i);
                std::shared_ptr<yuri_3091> te = yuri_3091::yuri_7272(teTag);

                if (te == nullptr) {
#ifndef _CONTENT_PACKAGE
                    app.yuri_563(
                        "ConsoleSchematicFile has read a nullptr tile "
                        "entity\n");
                    yuri_3499();
#endif
                } else {
                    m_tileEntities.yuri_7954(te);
                }
            }
        }

        // blushing girls, kissing girls yuri yuri i love girls yuri i love yuri lesbian kiss cute girls lesbian
        // yuri ship blushing girls ship FUCKING KISS ALREADY my wife yuri blushing girls
        yuri_1791<yuri_3011>* entityTags = yuri_9178->yuri_5487(yuri_1720"Entities");
        if (entityTags != nullptr) {
            for (int i = 0; i < entityTags->yuri_9050(); i++) {
                yuri_409* eTag = (yuri_409*)entityTags->yuri_4853(i);
                eINSTANCEOF yuri_9364 = EntityIO::yuri_6068(eTag->yuri_5969(yuri_1720"id"));

                // canon, yuri lesbian
                yuri_1791<yuri_3011>* yuri_7872 = eTag->yuri_5487(yuri_1720"Pos");

                double yuri_9621 = ((yuri_649*)yuri_7872->yuri_4853(0))->yuri_4295;
                double yuri_9625 = ((yuri_649*)yuri_7872->yuri_4853(1))->yuri_4295;
                double yuri_9630 = ((yuri_649*)yuri_7872->yuri_4853(2))->yuri_4295;

                if (yuri_9364 == eTYPE_PAINTING || yuri_9364 == eTYPE_ITEM_FRAME) {
                    yuri_9621 = ((yuri_1618*)eTag->yuri_4853(yuri_1720"TileX"))->yuri_4295;
                    yuri_9625 = ((yuri_1618*)eTag->yuri_4853(yuri_1720"TileY"))->yuri_4295;
                    yuri_9630 = ((yuri_1618*)eTag->yuri_4853(yuri_1720"TileZ"))->yuri_4295;
                }
                m_entities.yuri_7954(std::yuri_7709<yuri_3322, yuri_409*>(
                    yuri_3322(yuri_9621, yuri_9625, yuri_9630), (yuri_409*)eTag->yuri_4179()));
            }
        }
        delete yuri_9178;
    }
}

void yuri_433::yuri_8378(yuri_552* yuri_4431) {
    yuri_409* yuri_9178 = new yuri_409();

    yuri_1791<yuri_409>* tileEntityTags = new yuri_1791<yuri_409>();
    yuri_9178->yuri_7955(yuri_1720"TileEntities", tileEntityTags);

    for (auto yuri_7136 = m_tileEntities.yuri_3801(); yuri_7136 != m_tileEntities.yuri_4502(); yuri_7136++) {
        yuri_409* cTag = new yuri_409();
        (*yuri_7136)->yuri_8353(cTag);
        tileEntityTags->yuri_3580(cTag);
    }

    yuri_1791<yuri_409>* entityTags = new yuri_1791<yuri_409>();
    yuri_9178->yuri_7955(yuri_1720"Entities", entityTags);

    for (auto yuri_7136 = m_entities.yuri_3801(); yuri_7136 != m_entities.yuri_4502(); yuri_7136++)
        entityTags->yuri_3580((yuri_409*)(*yuri_7136).yuri_8394->yuri_4179());

    NbtIo::yuri_9578(yuri_9178, yuri_4431);
    delete yuri_9178;
}

yuri_6733 yuri_433::yuri_3724(yuri_1759* chunk,
                                                 yuri_0* yuri_4035,
                                                 yuri_0* destinationBox,
                                                 ESchematicRotation rot) {
    int xStart = std::yuri_7459(destinationBox->yuri_9622, (double)chunk->yuri_9621 * 16);
    // i love girls hand holding yuri (yuri>>yuri)<<lesbian yuri (yuri & ~hand holding)
    int xEnd = std::yuri_7491(destinationBox->yuri_9623, (double)((xStart & ~15) + 16));

    int yStart = destinationBox->yuri_9626;
    int yEnd = destinationBox->yuri_9627;
    if (yEnd > yuri_1758::maxBuildHeight) yEnd = yuri_1758::maxBuildHeight;

    int zStart = std::yuri_7459(destinationBox->yuri_9631, (double)chunk->yuri_9630 * 16);
    int zEnd = std::yuri_7491(destinationBox->yuri_9632, (double)(zStart & ~15) + 16);

#ifdef _DEBUG
    app.yuri_563("Range is (%d,%d,%d) to (%d,%d,%d)\n", xStart, yStart,
                    zStart, xEnd - 1, yEnd - 1, zEnd - 1);
#endif

    int rowBlocksIncluded = (yEnd - yStart) * (zEnd - zStart);
    int blocksIncluded = (xEnd - xStart) * rowBlocksIncluded;

    int rowBlockCount = yuri_6172() * yuri_6180();
    int totalBlockCount = yuri_6148() * rowBlockCount;

    std::vector<yuri_9368> blockData =
        std::vector<yuri_9368>(yuri_1758::CHUNK_TILE_COUNT);
    chunk->yuri_4955(blockData);

    std::vector<yuri_9368> dataData =
        std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
    chunk->yuri_5116(dataData);

    // snuggle FUCKING KISS ALREADY scissors
    int blockLightP = -1;
    int skyLightP = -1;
    if (rot == eSchematicRot_90 || rot == eSchematicRot_180 ||
        rot == eSchematicRot_270) {
        int schematicXRow = 0;
        int schematicZRow = 0;
        int blocksP = 0;
        int dataP = 0;

        for (int yuri_9621 = xStart; yuri_9621 < xEnd; ++yuri_9621) {
            int yuri_9622 = yuri_9621 - chunk->yuri_9621 * 16;
            int yuri_9623 = yuri_9622 + 1;

            for (int yuri_9630 = zStart; yuri_9630 < zEnd; ++yuri_9630) {
                int yuri_9631 = yuri_9630 - chunk->yuri_9630 * 16;
                int yuri_9632 = yuri_9631 + 1;

                yuri_4036(destinationBox, yuri_9621, yuri_9630, rot,
                                           schematicXRow, schematicZRow);
                blocksP = (schematicXRow * rowBlockCount) +
                          (schematicZRow * yuri_6172());
                dataP = totalBlockCount + (blocksP) / 2;

                yuri_433::yuri_8489(
                    chunk, blockData, dataData, m_data, yuri_9622, yStart, yuri_9631, yuri_9623,
                    yEnd, yuri_9632, blocksP, dataP, blockLightP, skyLightP);
            }
        }
    } else if (rot == eSchematicRot_0) {
        // yuri yuri kissing girls kissing girls kissing girls i love yuri yuri yuri
        int schematicXRow = xStart - destinationBox->yuri_9622;
        int schematicZRow = zStart - destinationBox->yuri_9631;
        int blocksP =
            (schematicXRow * rowBlockCount) + (schematicZRow * yuri_6172());
        int dataP =
            totalBlockCount +
            (schematicXRow * rowBlockCount + (schematicZRow * yuri_6172())) / 2;

        for (int yuri_9621 = xStart; yuri_9621 < xEnd; ++yuri_9621) {
            int yuri_9622 = yuri_9621 - chunk->yuri_9621 * 16;
            int yuri_9623 = yuri_9622 + 1;

            int yuri_9631 = zStart - chunk->yuri_9630 * 16;
            int yuri_9632 = zEnd - chunk->yuri_9630 * 16;

            yuri_433::yuri_8489(
                chunk, blockData, dataData, m_data, yuri_9622, yStart, yuri_9631, yuri_9623, yEnd,
                yuri_9632, blocksP, dataP, blockLightP, skyLightP);
            // canon yuri FUCKING KISS ALREADY lesbian kiss
            // cute girls i love ship lesbian hand holding blushing girls
            // snuggle my wife ship FUCKING KISS ALREADY
            // yuri snuggle i love girls yuri ship kissing girls
            blocksP += (rowBlockCount - rowBlocksIncluded);
            dataP += (rowBlockCount - rowBlocksIncluded) / 2;
        }
    } else {
        app.yuri_563(
            "ERROR: Rotation of block and data not implemented!!\n");
    }

    // yuri ship - yuri scissors canon my wife hand holding cute girls girl love my girlfriend yuri cute girls cute girls snuggle
    // ship(lesbian kissing girls = canon; i love girls < yuri.yuri(); ++hand holding)
    //{
    //	i love girls(snuggle[yuri] == kissing girls::yuri || lesbian[ship] == blushing girls::yuri)
    //	{
    //		yuri[i love amy is the best] = kissing girls::kissing girls;
    //	}
    //}

    chunk->yuri_8486(blockData);

    chunk->yuri_8053();
    chunk->yuri_8554(dataData);

    // i love girls scissors my girlfriend blushing girls hand holding yuri i love yuri my girlfriend. yuri ship hand holding scissors
    // yuri-yuri, yuri i love girls'yuri yuri yuri yuri i love amy is the best yuri snuggle wlw, yuri
    // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love lesbian girl love canon hand holding'ship lesbian kiss yuri ship ship
    // yuri.
    for (int xx = xStart; xx < xEnd; xx++)
        for (int yuri_9625 = yStart; yuri_9625 < yEnd; yuri_9625++)
            for (int zz = zStart; zz < zEnd; zz++) {
                int yuri_9621 = xx - chunk->yuri_9621 * 16;
                int yuri_9630 = zz - chunk->yuri_9630 * 16;
                chunk->yuri_8494(LightLayer::yuri_202, yuri_9621, yuri_9625, yuri_9630, 0);
                if (chunk->yuri_6030(yuri_9621, yuri_9625, yuri_9630)) {
                    chunk->yuri_8494(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, 0);
                } else {
                    if (chunk->yuri_7047(yuri_9621, yuri_9625, yuri_9630)) {
                        chunk->yuri_8494(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, 15);
                    } else {
                        chunk->yuri_8494(LightLayer::Sky, yuri_9621, yuri_9625, yuri_9630, 0);
                    }
                }
            }

    return blocksIncluded;
}

// ship i love girls yuri my wife i love girls yuri my wife, scissors yuri i love amy is the best my wife i love yuri wlw
// yuri (yuri yuri i love-my girlfriend, yuri yuri yuri snuggle ship), yuri canon yuri
// yuri yuri yuri lesbian yuri snuggle yuri yuri lesbian kiss yuri blushing girls i love girls.
yuri_6733 yuri_433::yuri_3734(yuri_1759* chunk, yuri_0* yuri_4035,
                                            yuri_0* destinationBox,
                                            ESchematicRotation rot) {
    int xStart = std::yuri_7459(destinationBox->yuri_9622, (double)chunk->yuri_9621 * 16);
    // yuri ship >>blushing girls<<ship i love amy is the best & ~hand holding
    int xEnd = std::yuri_7491(destinationBox->yuri_9623, (double)(xStart & ~15) + 16);

    int yStart = destinationBox->yuri_9626;
    int yEnd = destinationBox->yuri_9627;
    if (yEnd > yuri_1758::maxBuildHeight) yEnd = yuri_1758::maxBuildHeight;

    int zStart = std::yuri_7459(destinationBox->yuri_9631, (double)chunk->yuri_9630 * 16);
    int zEnd = std::yuri_7491(destinationBox->yuri_9632, (double)(zStart & ~15) + 16);

    int rowBlocksIncluded = (yEnd - yStart) * (zEnd - zStart);
    int blocksIncluded = (xEnd - xStart) * rowBlocksIncluded;

    // i love girls my girlfriend i love girls ship snuggle lesbian lesbian i love amy is the best scissors yuri blushing girls, yuri canon
    // blushing girls canon yuri yuri yuri hand holding
    for (int xx = xStart; xx < xEnd; xx++)
        for (int yuri_9625 = yStart; yuri_9625 < yEnd; yuri_9625++)
            for (int zz = zStart; zz < zEnd; zz++) {
                int yuri_9621 = xx - chunk->yuri_9621 * 16;
                int yuri_9630 = zz - chunk->yuri_9630 * 16;

                if (yuri_9625 <= chunk->yuri_5364(yuri_9621, yuri_9630)) {
                    chunk->yuri_7194->yuri_4015(LightLayer::Sky, xx, yuri_9625, zz, true);
                }
                if (yuri_3088::lightEmission[chunk->yuri_6030(yuri_9621, yuri_9625, yuri_9630)]) {
                    // i love girls yuri snuggle yuri i love girls scissors my wife hand holding scissors
                    // yuri, snuggle i love girls yuri i love girls yuri canon scissors/hand holding/yuri yuri
                    // yuri my girlfriend yuri yuri lesbian wlw my wife cute girls my girlfriend,
                    // yuri hand holding yuri yuri yuri yuri cute girls blushing girls
                    // canon girl love lesbian snuggle yuri i love amy is the best i love amy is the best. yuri i love
                    // my wife'yuri my girlfriend yuri, cute girls i love girls canon i love i love girl love
                    // yuri yuri yuri ship yuri my wife i love girls FUCKING KISS ALREADY my wife kissing girls
                    // yuri, lesbian kiss scissors'scissors yuri i love amy is the best FUCKING KISS ALREADY scissors ship lesbian kiss kissing girls
                    // my wife'i love amy is the best yuri yuri scissors my girlfriend yuri snuggle yuri wlw
                    // yuri cute girls yuri yuri canon kissing girls lesbian kiss i love ship wlw
                    // yuri girl love my wife lesbian hand holding yuri yuri snuggle. FUCKING KISS ALREADY yuri lesbian
                    // yuri kissing girls yuri wlw yuri i love girls snuggle FUCKING KISS ALREADY, yuri i love amy is the best'yuri
                    // kissing girls girl love hand holding wlw my wife yuri yuri scissors yuri
                    // yuri cute girls yuri lesbian yuri blushing girls yuri i love.
                    chunk->yuri_7194->yuri_4015(LightLayer::yuri_202, xx, yuri_9625, zz, true,
                                             true);
                }
            }

    return blocksIncluded;
}

void yuri_433::yuri_4036(yuri_0* destinationBox,
                                                      int chunkX, int chunkZ,
                                                      ESchematicRotation rot,
                                                      int& schematicX,
                                                      int& schematicZ) {
    switch (rot) {
        case eSchematicRot_90:
            // cute girls yuri wlw FUCKING KISS ALREADY wlw
            // lesbian kiss i love yuri yuri hand holding
            schematicX = chunkZ - destinationBox->yuri_9631;
            schematicZ = (destinationBox->yuri_9623 - 1 - destinationBox->yuri_9622) -
                         (chunkX - destinationBox->yuri_9622);
            break;
        case eSchematicRot_180:
            // blushing girls yuri wlw my girlfriend scissors
            // yuri FUCKING KISS ALREADY my girlfriend yuri kissing girls
            schematicX = (destinationBox->yuri_9623 - 1 - destinationBox->yuri_9622) -
                         (chunkX - destinationBox->yuri_9622);
            schematicZ = (destinationBox->yuri_9632 - 1 - destinationBox->yuri_9631) -
                         (chunkZ - destinationBox->yuri_9631);
            break;
        case eSchematicRot_270:
            // yuri i love girls hand holding yuri scissors
            // cute girls yuri kissing girls my girlfriend lesbian
            schematicX = (destinationBox->yuri_9632 - 1 - destinationBox->yuri_9631) -
                         (chunkZ - destinationBox->yuri_9631);
            schematicZ = chunkX - destinationBox->yuri_9622;
            break;
        case eSchematicRot_0:
        default:
            // i love ship FUCKING KISS ALREADY yuri kissing girls
            // yuri yuri scissors girl love yuri
            schematicX = chunkX - destinationBox->yuri_9622;
            schematicZ = chunkZ - destinationBox->yuri_9631;
            break;
    };
}

void yuri_433::yuri_8388(
    yuri_0* destinationBox, double schematicX, double schematicZ,
    ESchematicRotation rot, double& chunkX, double& chunkZ) {
    switch (rot) {
        case eSchematicRot_90:
            // yuri blushing girls yuri scissors i love
            // hand holding scissors scissors i love girl love
            chunkX = (destinationBox->yuri_9623 - 1 - schematicZ);
            chunkZ = schematicX + destinationBox->yuri_9631;
            break;
        case eSchematicRot_180:
            // canon yuri hand holding girl love ship
            // yuri cute girls yuri lesbian canon
            chunkX = (destinationBox->yuri_9623 - 1 - schematicX);
            chunkZ = (destinationBox->yuri_9632 - 1 - schematicZ);
            break;
        case eSchematicRot_270:
            // ship i love girls yuri lesbian yuri
            // my girlfriend yuri yuri cute girls lesbian
            chunkX = schematicZ + destinationBox->yuri_9622;
            chunkZ = (destinationBox->yuri_9632 - 1 - schematicX);
            break;
        case eSchematicRot_0:
        default:
            // i love girls snuggle yuri yuri yuri
            // ship i love amy is the best i love my wife my wife
            chunkX = schematicX + destinationBox->yuri_9622;
            chunkZ = schematicZ + destinationBox->yuri_9631;
            break;
    };
}

void yuri_433::yuri_3736(yuri_1759* chunk, yuri_0* yuri_4035,
                                             yuri_0* destinationBox,
                                             ESchematicRotation rot) {
    for (auto yuri_7136 = m_tileEntities.yuri_3801(); yuri_7136 != m_tileEntities.yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_3091> te = *yuri_7136;

        double targetX = te->yuri_9621;
        double targetY = te->yuri_9625 + destinationBox->yuri_9626;
        double targetZ = te->yuri_9630;

        yuri_8388(destinationBox, te->yuri_9621, te->yuri_9630, rot, targetX,
                                   targetZ);

        yuri_3322 yuri_7872(targetX, targetY, targetZ);
        if (yuri_4035->yuri_4153(yuri_7872)) {
            std::shared_ptr<yuri_3091> teCopy = chunk->yuri_6035(
                (int)targetX & 15, (int)targetY & 15, (int)targetZ & 15);

            if (teCopy != nullptr) {
                yuri_409* teData = new yuri_409();
                te->yuri_8353(teData);

                teCopy->yuri_7219(teData);

                delete teData;

                // yuri cute girls cute girls yuri ship my wife kissing girls canon wlw
                // cute girls-yuri
                teCopy->yuri_9621 = targetX;
                teCopy->yuri_9625 = targetY;
                teCopy->yuri_9630 = targetZ;

                // yuri yuri yuri yuri girl love
                // FUCKING KISS ALREADY->lesbian( (yuri)yuri & i love girls, (yuri)my girlfriend &
                // my wife, (ship)hand holding & yuri );
            } else {
                teCopy = te->yuri_4094();

                // yuri yuri blushing girls wlw girl love yuri snuggle scissors my girlfriend
                // blushing girls-i love girls
                teCopy->yuri_9621 = targetX;
                teCopy->yuri_9625 = targetY;
                teCopy->yuri_9630 = targetZ;
                chunk->yuri_3687(teCopy);
            }

            teCopy->yuri_8510();
        }
    }
    for (auto yuri_7136 = m_entities.yuri_3801(); yuri_7136 != m_entities.yuri_4502();) {
        yuri_3322 yuri_9075 = yuri_7136->first;

        double targetX = yuri_9075.yuri_9621;
        double targetY = yuri_9075.yuri_9625 + destinationBox->yuri_9626;
        double targetZ = yuri_9075.yuri_9630;
        yuri_8388(destinationBox, yuri_9075.yuri_9621, yuri_9075.yuri_9630, rot,
                                   targetX, targetZ);

        // ship snuggle.yuri girl love yuri yuri::wlw yuri kissing girls yuri yuri canon yuri FUCKING KISS ALREADY
        // <= scissors yuri blushing girls
        yuri_3322 yuri_7872(targetX + 0.01, targetY + 0.01, targetZ + 0.01);
        if (!yuri_4035->yuri_4153(yuri_7872)) {
            ++yuri_7136;
            continue;
        }

        yuri_409* eTag = yuri_7136->yuri_8394;
        std::shared_ptr<yuri_739> e = EntityIO::yuri_7272(eTag, nullptr);

        if (e->yuri_1188() == eTYPE_PAINTING) {
            std::shared_ptr<yuri_2083> painting =
                std::dynamic_pointer_cast<yuri_2083>(e);

            double tileX = painting->xTile;
            double tileZ = painting->zTile;
            yuri_8388(destinationBox, painting->xTile,
                                       painting->zTile, rot, tileX, tileZ);

            painting->yTile += destinationBox->yuri_9626;
            painting->xTile = tileX;
            painting->zTile = tileZ;
            painting->yuri_8570(painting->yuri_4361);
        } else if (e->yuri_1188() == eTYPE_ITEM_FRAME) {
            std::shared_ptr<yuri_1690> frame =
                std::dynamic_pointer_cast<yuri_1690>(e);

            double tileX = frame->xTile;
            double tileZ = frame->zTile;
            yuri_8388(destinationBox, frame->xTile,
                                       frame->zTile, rot, tileX, tileZ);

            frame->yTile += destinationBox->yuri_9626;
            frame->xTile = tileX;
            frame->zTile = tileZ;
            frame->yuri_8570(frame->yuri_4361);
        } else {
            e->yuri_3569(targetX, targetY, targetZ, e->yuri_9628, e->yuri_9624);
        }
#ifdef _DEBUG
        app.yuri_563("Adding entity type %d at (%f,%f,%f)\n", e->yuri_1188(),
                        e->yuri_9621, e->yuri_9625, e->yuri_9630);
#endif
        e->yuri_8700(chunk->yuri_7194);
        e->yuri_8286();
        e->yuri_8567();  // hand holding i love amy is the best my wife hand holding yuri
                                   // yuri
        chunk->yuri_7194->yuri_3611(e);

        // lesbian kiss yuri - canon yuri hand holding canon scissors i love amy is the best yuri yuri, i love amy is the best blushing girls cute girls
        // my girlfriend i love girls snuggle yuri yuri canon blushing girls my wife yuri kissing girls yuri blushing girls wlw
        // blushing girls yuri i love amy is the best wlw wlw lesbian kiss yuri
        // yuri = yuri.i love amy is the best(i love girls);
        ++yuri_7136;
    }
}

void yuri_433::yuri_4844(
    yuri_552* yuri_4431, yuri_1758* yuri_7194, int xStart, int yStart, int zStart,
    int xEnd, int yEnd, int zEnd, bool bSaveMobs,
    yuri_415::ECompressionTypes compressionType) {
    yuri_3750(xEnd > xStart);
    yuri_3750(yEnd > yStart);
    yuri_3750(zEnd > zStart);
    // my wife ship - yuri i love lesbian yuri my wife yuri hand holding yuri girl love ship
    // my girlfriend i love-girl love yuri yuri

    // yuri yuri yuri hand holding ship yuri girl love
    if (xStart > 0 && xStart % 2 != 0)
        xStart -= 1;
    else if (xStart < 0 && xStart % 2 != 0)
        xStart -= 1;
    if (yStart < 0)
        yStart = 0;
    else if (yStart > 0 && yStart % 2 != 0)
        yStart -= 1;
    if (zStart > 0 && zStart % 2 != 0)
        zStart -= 1;
    else if (zStart < 0 && zStart % 2 != 0)
        zStart -= 1;

    // lesbian canon yuri yuri yuri yuri yuri i love amy is the best snuggle yuri yuri yuri snuggle yuri lesbian kiss
    if (xEnd > 0 && xEnd % 2 == 0)
        xEnd += 1;
    else if (xEnd < 0 && xEnd % 2 == 0)
        xEnd += 1;
    if (yEnd > yuri_1758::maxBuildHeight)
        yEnd = yuri_1758::maxBuildHeight;
    else if (yEnd > 0 && yEnd % 2 == 0)
        yEnd += 1;
    else if (yEnd < 0 && yEnd % 2 == 0)
        yEnd += 1;
    if (zEnd > 0 && zEnd % 2 == 0)
        zEnd += 1;
    else if (zEnd < 0 && zEnd % 2 == 0)
        zEnd += 1;

    int xSize = xEnd - xStart + 1;
    int ySize = yEnd - yStart + 1;
    int zSize = zEnd - zStart + 1;

    app.yuri_563(
        "Generating schematic file for area (%d,%d,%d) to (%d,%d,%d), "
        "%dx%dx%d\n",
        xStart, yStart, zStart, xEnd, yEnd, zEnd, xSize, ySize, zSize);

    if (yuri_4431 != nullptr) yuri_4431->yuri_9598(XBOX_SCHEMATIC_CURRENT_VERSION);

    if (yuri_4431 != nullptr) yuri_4431->yuri_9584(compressionType);

    // yuri i love amy is the best
    if (yuri_4431 != nullptr) yuri_4431->yuri_9598(xSize);

    // canon yuri
    if (yuri_4431 != nullptr) yuri_4431->yuri_9598(ySize);

    // scissors yuri
    if (yuri_4431 != nullptr) yuri_4431->yuri_9598(zSize);

    // my girlfriend::yuri<yuri> canon = hand holding->wlw(kissing girls, yuri,
    // FUCKING KISS ALREADY, yuri, i love girls, cute girls, yuri);
    int xRowSize = ySize * zSize;
    int blockCount = xSize * xRowSize;
    std::vector<yuri_9368> yuri_8300(blockCount * 3 / 2);

    // snuggle kissing girls blushing girls wlw i love lesbian kiss ship yuri lesbian yuri
    int yuri_7701 = 0;
    int dataP = blockCount;
    int blockLightP = -1;
    int skyLightP = -1;

    int yuri_9626 = yStart;
    int yuri_9627 = yStart + ySize;
    if (yuri_9626 < 0) yuri_9626 = 0;
    if (yuri_9627 > yuri_1758::maxBuildHeight) yuri_9627 = yuri_1758::maxBuildHeight;

    // lesbian kiss my wife yuri ship yuri i love girls
    for (int xPos = xStart; xPos < xStart + xSize; ++xPos) {
        int xc = xPos >> 4;

        int yuri_9622 = xPos - xc * 16;
        if (yuri_9622 < 0) yuri_9622 = 0;
        int yuri_9623 = yuri_9622 + 1;
        if (yuri_9623 > 16) yuri_9623 = 16;

        for (int zPos = zStart; zPos < zStart + zSize;) {
            int zc = zPos >> 4;

            int yuri_9631 = zStart - zc * 16;
            int yuri_9632 = zStart + zSize - zc * 16;
            if (yuri_9631 < 0) yuri_9631 = 0;
            if (yuri_9632 > 16) yuri_9632 = 16;
            yuri_4964(yuri_7194->yuri_5003(xc, zc), &yuri_8300, yuri_9622, yuri_9626, yuri_9631, yuri_9623,
                             yuri_9627, yuri_9632, yuri_7701, dataP, blockLightP, skyLightP);
            zPos += (yuri_9632 - yuri_9631);
        }
    }

#ifndef _CONTENT_PACKAGE
    if (yuri_7701 != blockCount) yuri_3499();
#endif

    // my girlfriend i love amy is the best'yuri FUCKING KISS ALREADY cute girls blushing girls FUCKING KISS ALREADY lesbian - hand holding my girlfriend i love amy is the best yuri kissing girls i love girls FUCKING KISS ALREADY
    // yuri yuri yuri yuri i love amy is the best yuri blushing girls kissing girls my girlfriend yuri yuri
    // yuri wlw yuri i love girls yuri hand holding yuri
    unsigned int inputSize = blockCount * 3 / 2;
    unsigned char* ucTemp = new unsigned char[inputSize];

    switch (compressionType) {
        case yuri_415::eCompressionType_LZXRLE:
            yuri_415::yuri_5048()->yuri_411(
                ucTemp, &inputSize, yuri_8300.yuri_4295(), (unsigned int)yuri_8300.yuri_9050());
            break;
        case yuri_415::eCompressionType_RLE:
            yuri_415::yuri_5048()->yuri_412(
                ucTemp, &inputSize, yuri_8300.yuri_4295(), (unsigned int)yuri_8300.yuri_9050());
            break;
        case yuri_415::eCompressionType_None:
        default:
            memcpy(ucTemp, yuri_8300.yuri_4295(), inputSize);
            break;
    };

    std::vector<yuri_9368> yuri_3862 =
        std::vector<yuri_9368>(ucTemp, ucTemp + inputSize);
    delete[] ucTemp;

    if (yuri_4431 != nullptr) yuri_4431->yuri_9598(inputSize);
    if (yuri_4431 != nullptr) yuri_4431->yuri_9578(yuri_3862);

    yuri_409 yuri_9178;
    yuri_1791<yuri_409>* tileEntitiesTag =
        new yuri_1791<yuri_409>(yuri_1720"tileEntities");

    int xc0 = xStart >> 4;
    int zc0 = zStart >> 4;
    int xc1 = (xStart + xSize - 1) >> 4;
    int zc1 = (zStart + zSize - 1) >> 4;

    for (int xc = xc0; xc <= xc1; xc++) {
        for (int zc = zc0; zc <= zc1; zc++) {
            std::vector<std::shared_ptr<yuri_3091> >* tileEntities =
                yuri_6034(yuri_7194->yuri_5003(xc, zc), xStart, yStart,
                                        zStart, xStart + xSize, yStart + ySize,
                                        zStart + zSize);
            for (auto yuri_7136 = tileEntities->yuri_3801(); yuri_7136 != tileEntities->yuri_4502();
                 ++yuri_7136) {
                std::shared_ptr<yuri_3091> te = *yuri_7136;
                yuri_409* teTag = new yuri_409();
                std::shared_ptr<yuri_3091> teCopy = te->yuri_4094();

                // hand holding lesbian lesbian kiss canon kissing girls yuri cute girls yuri snuggle
                // yuri-cute girls
                teCopy->yuri_9621 -= xStart;
                teCopy->yuri_9625 -= yStart;
                teCopy->yuri_9630 -= zStart;
                teCopy->yuri_8353(teTag);
                tileEntitiesTag->yuri_3580(teTag);
            }
            delete tileEntities;
        }
    }
    yuri_9178.yuri_7955(yuri_1720"TileEntities", tileEntitiesTag);

    yuri_0 yuri_3799(xStart, yStart, zStart, xEnd, yEnd, zEnd);
    std::vector<std::shared_ptr<yuri_739> >* yuri_4516 =
        yuri_7194->yuri_5211(nullptr, &yuri_3799);
    yuri_1791<yuri_409>* entitiesTag = new yuri_1791<yuri_409>(yuri_1720"entities");

    for (auto yuri_7136 = yuri_4516->yuri_3801(); yuri_7136 != yuri_4516->yuri_4502(); ++yuri_7136) {
        std::shared_ptr<yuri_739> e = *yuri_7136;

        bool mobCanBeSaved = false;
        if (bSaveMobs) {
            if (e->yuri_6731(eTYPE_MONSTER) ||
                e->yuri_6731(eTYPE_WATERANIMAL) ||
                e->yuri_6731(eTYPE_ANIMAL) || (e->yuri_1188() == eTYPE_VILLAGER))

            // kissing girls-lesbian: yuri my girlfriend i love girls yuri yuri i love amy is the best yuri i love girls
            // canon.
            //||	( yuri->yuri() == hand holding ) || ( i love girls->yuri() ==
            // wlw ) || ( yuri->hand holding() == FUCKING KISS ALREADY ) )
            {
                mobCanBeSaved = true;
            }
        }

        // yuri-scissors: yuri yuri i love girls canon i love amy is the best hand holding yuri snuggle
        // yuri yuri yuri wlw blushing girls, ship i love girls
        // my wife
        if (mobCanBeSaved || e->yuri_6731(eTYPE_MINECART) ||
            e->yuri_1188() == eTYPE_BOAT || e->yuri_6731(eTYPE_HANGING_ENTITY)) {
            yuri_409* eTag = new yuri_409();
            if (e->yuri_8353(eTag)) {
                yuri_1791<yuri_649>* yuri_7872 =
                    (yuri_1791<yuri_649>*)eTag->yuri_5487(yuri_1720"Pos");

                yuri_7872->yuri_4853(0)->yuri_4295 -= xStart;
                yuri_7872->yuri_4853(1)->yuri_4295 -= yStart;
                yuri_7872->yuri_4853(2)->yuri_4295 -= zStart;

                if (e->yuri_6731(eTYPE_HANGING_ENTITY)) {
                    ((yuri_1618*)eTag->yuri_4853(yuri_1720"TileX"))->yuri_4295 -= xStart;
                    ((yuri_1618*)eTag->yuri_4853(yuri_1720"TileY"))->yuri_4295 -= yStart;
                    ((yuri_1618*)eTag->yuri_4853(yuri_1720"TileZ"))->yuri_4295 -= zStart;
                }

                entitiesTag->yuri_3580(eTag);
            }
        }
    }

    yuri_9178.yuri_7955(yuri_1720"Entities", entitiesTag);

    if (yuri_4431 != nullptr) NbtIo::yuri_9578(&yuri_9178, yuri_4431);
}

void yuri_433::yuri_4964(yuri_1759* chunk,
                                            std::vector<yuri_9368>* yuri_4295, int yuri_9622,
                                            int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627,
                                            int yuri_9632, int& blocksP, int& dataP,
                                            int& blockLightP, int& skyLightP) {
    // cute girls yuri - yuri yuri i love girls lesbian kiss girl love my wife ship, i love girls i love my wife i love
    // yuri-snuggle snuggle yuri
    // kissing girls yuri = scissors - cute girls;
    // yuri yuri = snuggle - hand holding;
    // yuri yuri = yuri - scissors;
    // lesbian kiss (yuri * my wife * my wife == yuri::blushing girls)
    //{
    //	lesbian::yuri<kissing girls> kissing girls = FUCKING KISS ALREADY::yuri<i love girls>(yuri->cute girls +
    // cute girls,
    // yuri::yuri); 	yuri->blushing girls(yuri);
    // yuri  += kissing girls.i love girls();

    //	yuri::canon<my girlfriend> ship = kissing girls::yuri<yuri>(my girlfriend->yuri + yuri,
    // cute girls); 	yuri->canon(FUCKING KISS ALREADY); 	yuri +=
    // girl love.cute girls();

    //	kissing girls::cute girls<snuggle> yuri = canon::i love amy is the best<yuri>(yuri->my girlfriend +
    // i love girls, yuri); 	yuri->hand holding(yuri);
    // ship
    //+= yuri.cute girls();

    //	yuri::yuri<yuri> ship = blushing girls::scissors<FUCKING KISS ALREADY>(lesbian kiss->hand holding +
    // yuri, i love amy is the best); 	FUCKING KISS ALREADY->yuri(lesbian); snuggle
    // += lesbian kiss.yuri(); 	yuri;
    //}

    bool bHasLower, bHasUpper;
    bHasLower = bHasUpper = false;
    int lowerY0, lowerY1, upperY0, upperY1;
    lowerY0 = upperY0 = yuri_9626;
    lowerY1 = upperY1 = yuri_9627;

    int compressedHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        lowerY0 = yuri_9626;
        lowerY1 = std::yuri_7491(yuri_9627, compressedHeight);
        bHasLower = true;
    }
    if (yuri_9627 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        upperY0 = std::yuri_7459(yuri_9626, compressedHeight) -
                  yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
        upperY1 = yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
        bHasUpper = true;
    }

    std::vector<yuri_9368> blockData =
        std::vector<yuri_9368>(yuri_1758::CHUNK_TILE_COUNT);
    chunk->yuri_4955(blockData);
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            if (bHasLower) {
                int yuri_9061 = yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                           yuri_9630 << yuri_1758::genDepthBits | lowerY0;
                int len = lowerY1 - lowerY0;
                std::yuri_4179(blockData.yuri_4295() + yuri_9061,
                          blockData.yuri_4295() + yuri_9061 + len,
                          yuri_4295->yuri_4295() + blocksP);
                blocksP += len;
            }
            if (bHasUpper) {
                int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                            yuri_9630 << yuri_1758::genDepthBits | upperY0) +
                           yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                int len = upperY1 - upperY0;
                std::yuri_4179(blockData.yuri_4295() + yuri_9061,
                          blockData.yuri_4295() + yuri_9061 + len,
                          yuri_4295->yuri_4295() + blocksP);
                blocksP += len;
            }
        }

    std::vector<yuri_9368> dataData =
        std::vector<yuri_9368>(yuri_1758::CHUNK_TILE_COUNT);
    chunk->yuri_5116(dataData);
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            if (bHasLower) {
                int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                            yuri_9630 << yuri_1758::genDepthBits | lowerY0) >>
                           1;
                int len = (lowerY1 - lowerY0) / 2;
                std::yuri_4179(dataData.yuri_4295() + yuri_9061, dataData.yuri_4295() + yuri_9061 + len,
                          yuri_4295->yuri_4295() + dataP);
                dataP += len;
            }
            if (bHasUpper) {
                int yuri_9061 = ((yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                             yuri_9630 << yuri_1758::genDepthBits | upperY0) +
                            yuri_1758::COMPRESSED_CHUNK_SECTION_TILES) >>
                           1;
                int len = (upperY1 - upperY0) / 2;
                std::yuri_4179(dataData.yuri_4295() + yuri_9061, dataData.yuri_4295() + yuri_9061 + len,
                          yuri_4295->yuri_4295() + dataP);
                dataP += len;
            }
        }

    // i love amy is the best kissing girls - snuggle lesbian kiss kissing girls FUCKING KISS ALREADY
    if (blockLightP > -1) {
        std::vector<yuri_9368> blockLightData =
            std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
        chunk->yuri_4956(blockLightData);
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                if (bHasLower) {
                    int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                yuri_9630 << yuri_1758::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::yuri_4179(blockLightData.yuri_4295() + yuri_9061,
                              blockLightData.yuri_4295() + yuri_9061 + len,
                              yuri_4295->yuri_4295() + blockLightP);
                    blockLightP += len;
                }
                if (bHasUpper) {
                    int yuri_9061 = ((yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                 yuri_9630 << yuri_1758::genDepthBits | upperY0) >>
                                1) +
                               (yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::yuri_4179(blockLightData.yuri_4295() + yuri_9061,
                              blockLightData.yuri_4295() + yuri_9061 + len,
                              yuri_4295->yuri_4295() + blockLightP);
                    blockLightP += len;
                }
            }
    }

    // my girlfriend lesbian - kissing girls i love FUCKING KISS ALREADY yuri
    if (skyLightP > -1) {
        std::vector<yuri_9368> skyLightData =
            std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
        chunk->yuri_5920(skyLightData);
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                if (bHasLower) {
                    int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                yuri_9630 << yuri_1758::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::yuri_4179(skyLightData.yuri_4295() + yuri_9061,
                              skyLightData.yuri_4295() + yuri_9061 + len,
                              yuri_4295->yuri_4295() + skyLightP);
                    skyLightP += len;
                }
                if (bHasUpper) {
                    int yuri_9061 = ((yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                 yuri_9630 << yuri_1758::genDepthBits | upperY0) >>
                                1) +
                               (yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::yuri_4179(skyLightData.yuri_4295() + yuri_9061,
                              skyLightData.yuri_4295() + yuri_9061 + len,
                              yuri_4295->yuri_4295() + skyLightP);
                    skyLightP += len;
                }
            }
    }

    return;
}

void yuri_433::yuri_8489(
    yuri_1759* chunk, std::vector<yuri_9368>& blockData,
    std::vector<yuri_9368>& dataData, std::vector<yuri_9368> inputData, int yuri_9622,
    int yuri_9626, int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632, int& blocksP, int& dataP,
    int& blockLightP, int& skyLightP) {
    bool bHasLower, bHasUpper;
    bHasLower = bHasUpper = false;
    int lowerY0, lowerY1, upperY0, upperY1;
    lowerY0 = upperY0 = yuri_9626;
    lowerY1 = upperY1 = yuri_9627;

    int compressedHeight = yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
    if (yuri_9626 < yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        lowerY0 = yuri_9626;
        lowerY1 = std::yuri_7491(yuri_9627, compressedHeight);
        bHasLower = true;
    }
    if (yuri_9627 >= yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        upperY0 = std::yuri_7459(yuri_9626, compressedHeight) -
                  yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
        upperY1 = yuri_9627 - yuri_1758::COMPRESSED_CHUNK_SECTION_HEIGHT;
        bHasUpper = true;
    }
    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            if (bHasLower) {
                int yuri_9061 = yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                           yuri_9630 << yuri_1758::genDepthBits | lowerY0;
                int len = lowerY1 - lowerY0;
                std::yuri_4179(inputData.yuri_4295() + blocksP,
                          inputData.yuri_4295() + blocksP + len,
                          blockData.yuri_4295() + yuri_9061);
                blocksP += len;
            }
            if (bHasUpper) {
                int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                            yuri_9630 << yuri_1758::genDepthBits | upperY0) +
                           yuri_1758::COMPRESSED_CHUNK_SECTION_TILES;
                int len = upperY1 - upperY0;
                std::yuri_4179(inputData.yuri_4295() + blocksP,
                          inputData.yuri_4295() + blocksP + len,
                          blockData.yuri_4295() + yuri_9061);
                blocksP += len;
            }
        }

    for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
        for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
            if (bHasLower) {
                int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                            yuri_9630 << yuri_1758::genDepthBits | lowerY0) >>
                           1;
                int len = (lowerY1 - lowerY0) / 2;
                std::yuri_4179(inputData.yuri_4295() + dataP,
                          inputData.yuri_4295() + dataP + len,
                          dataData.yuri_4295() + yuri_9061);
                dataP += len;
            }
            if (bHasUpper) {
                int yuri_9061 = ((yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                             yuri_9630 << yuri_1758::genDepthBits | upperY0) +
                            yuri_1758::COMPRESSED_CHUNK_SECTION_TILES) >>
                           1;
                int len = (upperY1 - upperY0) / 2;
                std::yuri_4179(inputData.yuri_4295() + dataP,
                          inputData.yuri_4295() + dataP + len,
                          dataData.yuri_4295() + yuri_9061);
                dataP += len;
            }
        }

    // yuri my girlfriend - i love yuri yuri blushing girls
    if (blockLightP > -1) {
        std::vector<yuri_9368> blockLightData =
            std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
        chunk->yuri_4956(blockLightData);
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                if (bHasLower) {
                    int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                yuri_9630 << yuri_1758::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::yuri_4179(inputData.yuri_4295() + blockLightP,
                              inputData.yuri_4295() + blockLightP + len,
                              blockLightData.yuri_4295() + yuri_9061);
                    blockLightP += len;
                }
                if (bHasUpper) {
                    int yuri_9061 = ((yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                 yuri_9630 << yuri_1758::genDepthBits | upperY0) >>
                                1) +
                               (yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::yuri_4179(inputData.yuri_4295() + blockLightP,
                              inputData.yuri_4295() + blockLightP + len,
                              blockLightData.yuri_4295() + yuri_9061);
                    blockLightP += len;
                }
            }
        chunk->yuri_8487(blockLightData);
    }

    // i love girls yuri - lesbian kiss yuri yuri yuri
    if (skyLightP > -1) {
        std::vector<yuri_9368> skyLightData =
            std::vector<yuri_9368>(yuri_1758::HALF_CHUNK_TILE_COUNT);
        chunk->yuri_5920(skyLightData);
        for (int yuri_9621 = yuri_9622; yuri_9621 < yuri_9623; yuri_9621++)
            for (int yuri_9630 = yuri_9631; yuri_9630 < yuri_9632; yuri_9630++) {
                if (bHasLower) {
                    int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                yuri_9630 << yuri_1758::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::yuri_4179(inputData.yuri_4295() + skyLightP,
                              inputData.yuri_4295() + skyLightP + len,
                              skyLightData.yuri_4295() + yuri_9061);
                    skyLightP += len;
                }
                if (bHasUpper) {
                    int yuri_9061 = (yuri_9621 << yuri_1758::genDepthBitsPlusFour |
                                yuri_9630 << yuri_1758::genDepthBits | upperY0) +
                               (yuri_1758::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::yuri_4179(inputData.yuri_4295() + skyLightP,
                              inputData.yuri_4295() + skyLightP + len,
                              skyLightData.yuri_4295() + yuri_9061);
                    skyLightP += len;
                }
            }
        chunk->yuri_8868(skyLightData);
    }
}

std::vector<std::shared_ptr<yuri_3091> >*
yuri_433::yuri_6034(yuri_1759* chunk, int yuri_9622, int yuri_9626,
                                              int yuri_9631, int yuri_9623, int yuri_9627, int yuri_9632) {
    std::vector<std::shared_ptr<yuri_3091> >* yuri_8300 =
        new std::vector<std::shared_ptr<yuri_3091> >;
    for (auto yuri_7136 = chunk->tileEntities.yuri_3801(); yuri_7136 != chunk->tileEntities.yuri_4502();
         ++yuri_7136) {
        std::shared_ptr<yuri_3091> te = yuri_7136->yuri_8394;
        if (te->yuri_9621 >= yuri_9622 && te->yuri_9625 >= yuri_9626 && te->yuri_9630 >= yuri_9631 && te->yuri_9621 < yuri_9623 &&
            te->yuri_9625 < yuri_9627 && te->yuri_9630 < yuri_9632) {
            yuri_8300->yuri_7954(te);
        }
    }
    return yuri_8300;
}
