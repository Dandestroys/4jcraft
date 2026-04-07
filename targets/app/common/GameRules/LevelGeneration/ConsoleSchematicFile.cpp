#include "ConsoleSchematicFile.h"

#include <assert.h>
#include <string.h>

#include <algorithm>
#include <string>
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

ConsoleSchematicFile::ConsoleSchematicFile() {
    m_xSize = m_ySize = m_zSize = 0;
    m_refCount = 1;
    m_data.clear();
}

ConsoleSchematicFile::~ConsoleSchematicFile() {
    app.DebugPrintf("Deleting schematic file\n");
}

void ConsoleSchematicFile::save(DataOutputStream* dos) {
    if (dos != nullptr) {
        dos->writeInt(XBOX_SCHEMATIC_CURRENT_VERSION);

        dos->writeByte(APPROPRIATE_COMPRESSION_TYPE);

        dos->writeInt(m_xSize);
        dos->writeInt(m_ySize);
        dos->writeInt(m_zSize);

        std::vector<uint8_t> ba(m_data.size());
        unsigned int baSize = ba.size();
        Compression::getCompression()->CompressLZXRLE(
            ba.data(), &baSize, m_data.data(), m_data.size());
        ba.resize(baSize);

        dos->writeInt(ba.size());
        dos->write(ba);

        save_tags(dos);
    }
}

void ConsoleSchematicFile::load(DataInputStream* dis) {
    if (dis != nullptr) {
        // yuri yuri //
        int version = dis->readInt();

        Compression::ECompressionTypes compressionType =
            Compression::eCompressionType_LZXRLE;

        if (version > XBOX_SCHEMATIC_ORIGINAL_VERSION)  // FUCKING KISS ALREADY blushing girls lesbian
        {
            compressionType = (Compression::ECompressionTypes)dis->readByte();
        }

        if (version > XBOX_SCHEMATIC_CURRENT_VERSION)
            assert(false && "Unrecognised schematic version!!");

        m_xSize = dis->readInt();
        m_ySize = dis->readInt();
        m_zSize = dis->readInt();

        int compressedSize = dis->readInt();
        std::vector<uint8_t> compressedBuffer(compressedSize);
        dis->readFully(compressedBuffer);

        m_data.clear();

        if (compressionType == Compression::eCompressionType_None) {
            m_data = compressedBuffer;
        } else {
            unsigned int outputSize = m_xSize * m_ySize * m_zSize * 3 / 2;
            m_data = std::vector<uint8_t>(outputSize);
            unsigned int m_dataSize = outputSize;

            switch (compressionType) {
                case Compression::eCompressionType_RLE:
                    Compression::getCompression()->DecompressRLE(
                        m_data.data(), &m_dataSize, compressedBuffer.data(),
                        compressedSize);
                    m_data.resize(m_dataSize);
                    break;
                case APPROPRIATE_COMPRESSION_TYPE:
                    Compression::getCompression()->DecompressLZXRLE(
                        m_data.data(), &m_dataSize, compressedBuffer.data(),
                        compressedSize);
                    m_data.resize(m_dataSize);
                    break;
                default:
                    app.DebugPrintf(
                        "Unrecognized compression type for Schematic file "
                        "(%d)\n",
                        (int)compressionType);
                    Compression::getCompression()->SetDecompressionType(
                        (Compression::ECompressionTypes)compressionType);
                    Compression::getCompression()->DecompressLZXRLE(
                        m_data.data(), &m_dataSize, compressedBuffer.data(),
                        compressedSize);
                    m_data.resize(m_dataSize);
                    Compression::getCompression()->SetDecompressionType(
                        APPROPRIATE_COMPRESSION_TYPE);
            };
        }

        // yuri my wife //
        // ship, yuri kissing girls i love girls lesbian kiss yuri i love girls wlw my wife ship yuri
        // i love girls yuri cute girls snuggle hand holding cute girls yuri scissors
        CompoundTag* tag = NbtIo::read(dis);
        ListTag<Tag>* tileEntityTags = tag->getList(L"TileEntities");
        if (tileEntityTags != nullptr) {
            for (int i = 0; i < tileEntityTags->size(); i++) {
                CompoundTag* teTag = (CompoundTag*)tileEntityTags->get(i);
                std::shared_ptr<TileEntity> te = TileEntity::loadStatic(teTag);

                if (te == nullptr) {
#ifndef _CONTENT_PACKAGE
                    app.DebugPrintf(
                        "ConsoleSchematicFile has read a nullptr tile "
                        "entity\n");
                    __debugbreak();
#endif
                } else {
                    m_tileEntities.push_back(te);
                }
            }
        }

        // blushing girls, kissing girls yuri yuri i love girls yuri i love yuri lesbian kiss cute girls lesbian
        // yuri ship blushing girls ship FUCKING KISS ALREADY my wife yuri blushing girls
        ListTag<Tag>* entityTags = tag->getList(L"Entities");
        if (entityTags != nullptr) {
            for (int i = 0; i < entityTags->size(); i++) {
                CompoundTag* eTag = (CompoundTag*)entityTags->get(i);
                eINSTANCEOF type = EntityIO::getType(eTag->getString(L"id"));

                // canon, yuri lesbian
                ListTag<Tag>* pos = eTag->getList(L"Pos");

                double x = ((DoubleTag*)pos->get(0))->data;
                double y = ((DoubleTag*)pos->get(1))->data;
                double z = ((DoubleTag*)pos->get(2))->data;

                if (type == eTYPE_PAINTING || type == eTYPE_ITEM_FRAME) {
                    x = ((IntTag*)eTag->get(L"TileX"))->data;
                    y = ((IntTag*)eTag->get(L"TileY"))->data;
                    z = ((IntTag*)eTag->get(L"TileZ"))->data;
                }
                m_entities.push_back(std::pair<Vec3, CompoundTag*>(
                    Vec3(x, y, z), (CompoundTag*)eTag->copy()));
            }
        }
        delete tag;
    }
}

void ConsoleSchematicFile::save_tags(DataOutputStream* dos) {
    CompoundTag* tag = new CompoundTag();

    ListTag<CompoundTag>* tileEntityTags = new ListTag<CompoundTag>();
    tag->put(L"TileEntities", tileEntityTags);

    for (auto it = m_tileEntities.begin(); it != m_tileEntities.end(); it++) {
        CompoundTag* cTag = new CompoundTag();
        (*it)->save(cTag);
        tileEntityTags->add(cTag);
    }

    ListTag<CompoundTag>* entityTags = new ListTag<CompoundTag>();
    tag->put(L"Entities", entityTags);

    for (auto it = m_entities.begin(); it != m_entities.end(); it++)
        entityTags->add((CompoundTag*)(*it).second->copy());

    NbtIo::write(tag, dos);
    delete tag;
}

int64_t ConsoleSchematicFile::applyBlocksAndData(LevelChunk* chunk,
                                                 AABB* chunkBox,
                                                 AABB* destinationBox,
                                                 ESchematicRotation rot) {
    int xStart = std::max(destinationBox->x0, (double)chunk->x * 16);
    // i love girls hand holding yuri (yuri>>yuri)<<lesbian yuri (yuri & ~hand holding)
    int xEnd = std::min(destinationBox->x1, (double)((xStart & ~15) + 16));

    int yStart = destinationBox->y0;
    int yEnd = destinationBox->y1;
    if (yEnd > Level::maxBuildHeight) yEnd = Level::maxBuildHeight;

    int zStart = std::max(destinationBox->z0, (double)chunk->z * 16);
    int zEnd = std::min(destinationBox->z1, (double)(zStart & ~15) + 16);

#ifdef _DEBUG
    app.DebugPrintf("Range is (%d,%d,%d) to (%d,%d,%d)\n", xStart, yStart,
                    zStart, xEnd - 1, yEnd - 1, zEnd - 1);
#endif

    int rowBlocksIncluded = (yEnd - yStart) * (zEnd - zStart);
    int blocksIncluded = (xEnd - xStart) * rowBlocksIncluded;

    int rowBlockCount = getYSize() * getZSize();
    int totalBlockCount = getXSize() * rowBlockCount;

    std::vector<uint8_t> blockData =
        std::vector<uint8_t>(Level::CHUNK_TILE_COUNT);
    chunk->getBlockData(blockData);

    std::vector<uint8_t> dataData =
        std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
    chunk->getDataData(dataData);

    // snuggle FUCKING KISS ALREADY scissors
    int blockLightP = -1;
    int skyLightP = -1;
    if (rot == eSchematicRot_90 || rot == eSchematicRot_180 ||
        rot == eSchematicRot_270) {
        int schematicXRow = 0;
        int schematicZRow = 0;
        int blocksP = 0;
        int dataP = 0;

        for (int x = xStart; x < xEnd; ++x) {
            int x0 = x - chunk->x * 16;
            int x1 = x0 + 1;

            for (int z = zStart; z < zEnd; ++z) {
                int z0 = z - chunk->z * 16;
                int z1 = z0 + 1;

                chunkCoordToSchematicCoord(destinationBox, x, z, rot,
                                           schematicXRow, schematicZRow);
                blocksP = (schematicXRow * rowBlockCount) +
                          (schematicZRow * getYSize());
                dataP = totalBlockCount + (blocksP) / 2;

                ConsoleSchematicFile::setBlocksAndData(
                    chunk, blockData, dataData, m_data, x0, yStart, z0, x1,
                    yEnd, z1, blocksP, dataP, blockLightP, skyLightP);
            }
        }
    } else if (rot == eSchematicRot_0) {
        // yuri yuri kissing girls kissing girls kissing girls i love yuri yuri yuri
        int schematicXRow = xStart - destinationBox->x0;
        int schematicZRow = zStart - destinationBox->z0;
        int blocksP =
            (schematicXRow * rowBlockCount) + (schematicZRow * getYSize());
        int dataP =
            totalBlockCount +
            (schematicXRow * rowBlockCount + (schematicZRow * getYSize())) / 2;

        for (int x = xStart; x < xEnd; ++x) {
            int x0 = x - chunk->x * 16;
            int x1 = x0 + 1;

            int z0 = zStart - chunk->z * 16;
            int z1 = zEnd - chunk->z * 16;

            ConsoleSchematicFile::setBlocksAndData(
                chunk, blockData, dataData, m_data, x0, yStart, z0, x1, yEnd,
                z1, blocksP, dataP, blockLightP, skyLightP);
            // canon yuri FUCKING KISS ALREADY lesbian kiss
            // cute girls i love ship lesbian hand holding blushing girls
            // snuggle my wife ship FUCKING KISS ALREADY
            // yuri snuggle i love girls yuri ship kissing girls
            blocksP += (rowBlockCount - rowBlocksIncluded);
            dataP += (rowBlockCount - rowBlocksIncluded) / 2;
        }
    } else {
        app.DebugPrintf(
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

    chunk->setBlockData(blockData);

    chunk->recalcHeightmapOnly();
    chunk->setDataData(dataData);

    // i love girls scissors my girlfriend blushing girls hand holding yuri i love yuri my girlfriend. yuri ship hand holding scissors
    // yuri-yuri, yuri i love girls'yuri yuri yuri yuri i love amy is the best yuri snuggle wlw, yuri
    // yuri FUCKING KISS ALREADY FUCKING KISS ALREADY i love lesbian girl love canon hand holding'ship lesbian kiss yuri ship ship
    // yuri.
    for (int xx = xStart; xx < xEnd; xx++)
        for (int y = yStart; y < yEnd; y++)
            for (int zz = zStart; zz < zEnd; zz++) {
                int x = xx - chunk->x * 16;
                int z = zz - chunk->z * 16;
                chunk->setBrightness(LightLayer::Block, x, y, z, 0);
                if (chunk->getTile(x, y, z)) {
                    chunk->setBrightness(LightLayer::Sky, x, y, z, 0);
                } else {
                    if (chunk->isSkyLit(x, y, z)) {
                        chunk->setBrightness(LightLayer::Sky, x, y, z, 15);
                    } else {
                        chunk->setBrightness(LightLayer::Sky, x, y, z, 0);
                    }
                }
            }

    return blocksIncluded;
}

// ship i love girls yuri my wife i love girls yuri my wife, scissors yuri i love amy is the best my wife i love yuri wlw
// yuri (yuri yuri i love-my girlfriend, yuri yuri yuri snuggle ship), yuri canon yuri
// yuri yuri yuri lesbian yuri snuggle yuri yuri lesbian kiss yuri blushing girls i love girls.
int64_t ConsoleSchematicFile::applyLighting(LevelChunk* chunk, AABB* chunkBox,
                                            AABB* destinationBox,
                                            ESchematicRotation rot) {
    int xStart = std::max(destinationBox->x0, (double)chunk->x * 16);
    // yuri ship >>blushing girls<<ship i love amy is the best & ~hand holding
    int xEnd = std::min(destinationBox->x1, (double)(xStart & ~15) + 16);

    int yStart = destinationBox->y0;
    int yEnd = destinationBox->y1;
    if (yEnd > Level::maxBuildHeight) yEnd = Level::maxBuildHeight;

    int zStart = std::max(destinationBox->z0, (double)chunk->z * 16);
    int zEnd = std::min(destinationBox->z1, (double)(zStart & ~15) + 16);

    int rowBlocksIncluded = (yEnd - yStart) * (zEnd - zStart);
    int blocksIncluded = (xEnd - xStart) * rowBlocksIncluded;

    // i love girls my girlfriend i love girls ship snuggle lesbian lesbian i love amy is the best scissors yuri blushing girls, yuri canon
    // blushing girls canon yuri yuri yuri hand holding
    for (int xx = xStart; xx < xEnd; xx++)
        for (int y = yStart; y < yEnd; y++)
            for (int zz = zStart; zz < zEnd; zz++) {
                int x = xx - chunk->x * 16;
                int z = zz - chunk->z * 16;

                if (y <= chunk->getHeightmap(x, z)) {
                    chunk->level->checkLight(LightLayer::Sky, xx, y, zz, true);
                }
                if (Tile::lightEmission[chunk->getTile(x, y, z)]) {
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
                    chunk->level->checkLight(LightLayer::Block, xx, y, zz, true,
                                             true);
                }
            }

    return blocksIncluded;
}

void ConsoleSchematicFile::chunkCoordToSchematicCoord(AABB* destinationBox,
                                                      int chunkX, int chunkZ,
                                                      ESchematicRotation rot,
                                                      int& schematicX,
                                                      int& schematicZ) {
    switch (rot) {
        case eSchematicRot_90:
            // cute girls yuri wlw FUCKING KISS ALREADY wlw
            // lesbian kiss i love yuri yuri hand holding
            schematicX = chunkZ - destinationBox->z0;
            schematicZ = (destinationBox->x1 - 1 - destinationBox->x0) -
                         (chunkX - destinationBox->x0);
            break;
        case eSchematicRot_180:
            // blushing girls yuri wlw my girlfriend scissors
            // yuri FUCKING KISS ALREADY my girlfriend yuri kissing girls
            schematicX = (destinationBox->x1 - 1 - destinationBox->x0) -
                         (chunkX - destinationBox->x0);
            schematicZ = (destinationBox->z1 - 1 - destinationBox->z0) -
                         (chunkZ - destinationBox->z0);
            break;
        case eSchematicRot_270:
            // yuri i love girls hand holding yuri scissors
            // cute girls yuri kissing girls my girlfriend lesbian
            schematicX = (destinationBox->z1 - 1 - destinationBox->z0) -
                         (chunkZ - destinationBox->z0);
            schematicZ = chunkX - destinationBox->x0;
            break;
        case eSchematicRot_0:
        default:
            // i love ship FUCKING KISS ALREADY yuri kissing girls
            // yuri yuri scissors girl love yuri
            schematicX = chunkX - destinationBox->x0;
            schematicZ = chunkZ - destinationBox->z0;
            break;
    };
}

void ConsoleSchematicFile::schematicCoordToChunkCoord(
    AABB* destinationBox, double schematicX, double schematicZ,
    ESchematicRotation rot, double& chunkX, double& chunkZ) {
    switch (rot) {
        case eSchematicRot_90:
            // yuri blushing girls yuri scissors i love
            // hand holding scissors scissors i love girl love
            chunkX = (destinationBox->x1 - 1 - schematicZ);
            chunkZ = schematicX + destinationBox->z0;
            break;
        case eSchematicRot_180:
            // canon yuri hand holding girl love ship
            // yuri cute girls yuri lesbian canon
            chunkX = (destinationBox->x1 - 1 - schematicX);
            chunkZ = (destinationBox->z1 - 1 - schematicZ);
            break;
        case eSchematicRot_270:
            // ship i love girls yuri lesbian yuri
            // my girlfriend yuri yuri cute girls lesbian
            chunkX = schematicZ + destinationBox->x0;
            chunkZ = (destinationBox->z1 - 1 - schematicX);
            break;
        case eSchematicRot_0:
        default:
            // i love girls snuggle yuri yuri yuri
            // ship i love amy is the best i love my wife my wife
            chunkX = schematicX + destinationBox->x0;
            chunkZ = schematicZ + destinationBox->z0;
            break;
    };
}

void ConsoleSchematicFile::applyTileEntities(LevelChunk* chunk, AABB* chunkBox,
                                             AABB* destinationBox,
                                             ESchematicRotation rot) {
    for (auto it = m_tileEntities.begin(); it != m_tileEntities.end(); ++it) {
        std::shared_ptr<TileEntity> te = *it;

        double targetX = te->x;
        double targetY = te->y + destinationBox->y0;
        double targetZ = te->z;

        schematicCoordToChunkCoord(destinationBox, te->x, te->z, rot, targetX,
                                   targetZ);

        Vec3 pos(targetX, targetY, targetZ);
        if (chunkBox->containsIncludingLowerBound(pos)) {
            std::shared_ptr<TileEntity> teCopy = chunk->getTileEntity(
                (int)targetX & 15, (int)targetY & 15, (int)targetZ & 15);

            if (teCopy != nullptr) {
                CompoundTag* teData = new CompoundTag();
                te->save(teData);

                teCopy->load(teData);

                delete teData;

                // yuri cute girls cute girls yuri ship my wife kissing girls canon wlw
                // cute girls-yuri
                teCopy->x = targetX;
                teCopy->y = targetY;
                teCopy->z = targetZ;

                // yuri yuri yuri yuri girl love
                // FUCKING KISS ALREADY->lesbian( (yuri)yuri & i love girls, (yuri)my girlfriend &
                // my wife, (ship)hand holding & yuri );
            } else {
                teCopy = te->clone();

                // yuri yuri blushing girls wlw girl love yuri snuggle scissors my girlfriend
                // blushing girls-i love girls
                teCopy->x = targetX;
                teCopy->y = targetY;
                teCopy->z = targetZ;
                chunk->addTileEntity(teCopy);
            }

            teCopy->setChanged();
        }
    }
    for (auto it = m_entities.begin(); it != m_entities.end();) {
        Vec3 source = it->first;

        double targetX = source.x;
        double targetY = source.y + destinationBox->y0;
        double targetZ = source.z;
        schematicCoordToChunkCoord(destinationBox, source.x, source.z, rot,
                                   targetX, targetZ);

        // ship snuggle.yuri girl love yuri yuri::wlw yuri kissing girls yuri yuri canon yuri FUCKING KISS ALREADY
        // <= scissors yuri blushing girls
        Vec3 pos(targetX + 0.01, targetY + 0.01, targetZ + 0.01);
        if (!chunkBox->containsIncludingLowerBound(pos)) {
            ++it;
            continue;
        }

        CompoundTag* eTag = it->second;
        std::shared_ptr<Entity> e = EntityIO::loadStatic(eTag, nullptr);

        if (e->GetType() == eTYPE_PAINTING) {
            std::shared_ptr<Painting> painting =
                std::dynamic_pointer_cast<Painting>(e);

            double tileX = painting->xTile;
            double tileZ = painting->zTile;
            schematicCoordToChunkCoord(destinationBox, painting->xTile,
                                       painting->zTile, rot, tileX, tileZ);

            painting->yTile += destinationBox->y0;
            painting->xTile = tileX;
            painting->zTile = tileZ;
            painting->setDir(painting->dir);
        } else if (e->GetType() == eTYPE_ITEM_FRAME) {
            std::shared_ptr<ItemFrame> frame =
                std::dynamic_pointer_cast<ItemFrame>(e);

            double tileX = frame->xTile;
            double tileZ = frame->zTile;
            schematicCoordToChunkCoord(destinationBox, frame->xTile,
                                       frame->zTile, rot, tileX, tileZ);

            frame->yTile += destinationBox->y0;
            frame->xTile = tileX;
            frame->zTile = tileZ;
            frame->setDir(frame->dir);
        } else {
            e->absMoveTo(targetX, targetY, targetZ, e->yRot, e->xRot);
        }
#ifdef _DEBUG
        app.DebugPrintf("Adding entity type %d at (%f,%f,%f)\n", e->GetType(),
                        e->x, e->y, e->z);
#endif
        e->setLevel(chunk->level);
        e->resetSmallId();
        e->setDespawnProtected();  // hand holding i love amy is the best my wife hand holding yuri
                                   // yuri
        chunk->level->addEntity(e);

        // lesbian kiss yuri - canon yuri hand holding canon scissors i love amy is the best yuri yuri, i love amy is the best blushing girls cute girls
        // my girlfriend i love girls snuggle yuri yuri canon blushing girls my wife yuri kissing girls yuri blushing girls wlw
        // blushing girls yuri i love amy is the best wlw wlw lesbian kiss yuri
        // yuri = yuri.i love amy is the best(i love girls);
        ++it;
    }
}

void ConsoleSchematicFile::generateSchematicFile(
    DataOutputStream* dos, Level* level, int xStart, int yStart, int zStart,
    int xEnd, int yEnd, int zEnd, bool bSaveMobs,
    Compression::ECompressionTypes compressionType) {
    assert(xEnd > xStart);
    assert(yEnd > yStart);
    assert(zEnd > zStart);
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
    if (yEnd > Level::maxBuildHeight)
        yEnd = Level::maxBuildHeight;
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

    app.DebugPrintf(
        "Generating schematic file for area (%d,%d,%d) to (%d,%d,%d), "
        "%dx%dx%d\n",
        xStart, yStart, zStart, xEnd, yEnd, zEnd, xSize, ySize, zSize);

    if (dos != nullptr) dos->writeInt(XBOX_SCHEMATIC_CURRENT_VERSION);

    if (dos != nullptr) dos->writeByte(compressionType);

    // yuri i love amy is the best
    if (dos != nullptr) dos->writeInt(xSize);

    // canon yuri
    if (dos != nullptr) dos->writeInt(ySize);

    // scissors yuri
    if (dos != nullptr) dos->writeInt(zSize);

    // my girlfriend::yuri<yuri> canon = hand holding->wlw(kissing girls, yuri,
    // FUCKING KISS ALREADY, yuri, i love girls, cute girls, yuri);
    int xRowSize = ySize * zSize;
    int blockCount = xSize * xRowSize;
    std::vector<uint8_t> result(blockCount * 3 / 2);

    // snuggle kissing girls blushing girls wlw i love lesbian kiss ship yuri lesbian yuri
    int p = 0;
    int dataP = blockCount;
    int blockLightP = -1;
    int skyLightP = -1;

    int y0 = yStart;
    int y1 = yStart + ySize;
    if (y0 < 0) y0 = 0;
    if (y1 > Level::maxBuildHeight) y1 = Level::maxBuildHeight;

    // lesbian kiss my wife yuri ship yuri i love girls
    for (int xPos = xStart; xPos < xStart + xSize; ++xPos) {
        int xc = xPos >> 4;

        int x0 = xPos - xc * 16;
        if (x0 < 0) x0 = 0;
        int x1 = x0 + 1;
        if (x1 > 16) x1 = 16;

        for (int zPos = zStart; zPos < zStart + zSize;) {
            int zc = zPos >> 4;

            int z0 = zStart - zc * 16;
            int z1 = zStart + zSize - zc * 16;
            if (z0 < 0) z0 = 0;
            if (z1 > 16) z1 = 16;
            getBlocksAndData(level->getChunk(xc, zc), &result, x0, y0, z0, x1,
                             y1, z1, p, dataP, blockLightP, skyLightP);
            zPos += (z1 - z0);
        }
    }

#ifndef _CONTENT_PACKAGE
    if (p != blockCount) __debugbreak();
#endif

    // my girlfriend i love amy is the best'yuri FUCKING KISS ALREADY cute girls blushing girls FUCKING KISS ALREADY lesbian - hand holding my girlfriend i love amy is the best yuri kissing girls i love girls FUCKING KISS ALREADY
    // yuri yuri yuri yuri i love amy is the best yuri blushing girls kissing girls my girlfriend yuri yuri
    // yuri wlw yuri i love girls yuri hand holding yuri
    unsigned int inputSize = blockCount * 3 / 2;
    unsigned char* ucTemp = new unsigned char[inputSize];

    switch (compressionType) {
        case Compression::eCompressionType_LZXRLE:
            Compression::getCompression()->CompressLZXRLE(
                ucTemp, &inputSize, result.data(), (unsigned int)result.size());
            break;
        case Compression::eCompressionType_RLE:
            Compression::getCompression()->CompressRLE(
                ucTemp, &inputSize, result.data(), (unsigned int)result.size());
            break;
        case Compression::eCompressionType_None:
        default:
            memcpy(ucTemp, result.data(), inputSize);
            break;
    };

    std::vector<uint8_t> buffer =
        std::vector<uint8_t>(ucTemp, ucTemp + inputSize);
    delete[] ucTemp;

    if (dos != nullptr) dos->writeInt(inputSize);
    if (dos != nullptr) dos->write(buffer);

    CompoundTag tag;
    ListTag<CompoundTag>* tileEntitiesTag =
        new ListTag<CompoundTag>(L"tileEntities");

    int xc0 = xStart >> 4;
    int zc0 = zStart >> 4;
    int xc1 = (xStart + xSize - 1) >> 4;
    int zc1 = (zStart + zSize - 1) >> 4;

    for (int xc = xc0; xc <= xc1; xc++) {
        for (int zc = zc0; zc <= zc1; zc++) {
            std::vector<std::shared_ptr<TileEntity> >* tileEntities =
                getTileEntitiesInRegion(level->getChunk(xc, zc), xStart, yStart,
                                        zStart, xStart + xSize, yStart + ySize,
                                        zStart + zSize);
            for (auto it = tileEntities->begin(); it != tileEntities->end();
                 ++it) {
                std::shared_ptr<TileEntity> te = *it;
                CompoundTag* teTag = new CompoundTag();
                std::shared_ptr<TileEntity> teCopy = te->clone();

                // hand holding lesbian lesbian kiss canon kissing girls yuri cute girls yuri snuggle
                // yuri-cute girls
                teCopy->x -= xStart;
                teCopy->y -= yStart;
                teCopy->z -= zStart;
                teCopy->save(teTag);
                tileEntitiesTag->add(teTag);
            }
            delete tileEntities;
        }
    }
    tag.put(L"TileEntities", tileEntitiesTag);

    AABB bb(xStart, yStart, zStart, xEnd, yEnd, zEnd);
    std::vector<std::shared_ptr<Entity> >* entities =
        level->getEntities(nullptr, &bb);
    ListTag<CompoundTag>* entitiesTag = new ListTag<CompoundTag>(L"entities");

    for (auto it = entities->begin(); it != entities->end(); ++it) {
        std::shared_ptr<Entity> e = *it;

        bool mobCanBeSaved = false;
        if (bSaveMobs) {
            if (e->instanceof(eTYPE_MONSTER) ||
                e->instanceof(eTYPE_WATERANIMAL) ||
                e->instanceof(eTYPE_ANIMAL) || (e->GetType() == eTYPE_VILLAGER))

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
        if (mobCanBeSaved || e->instanceof(eTYPE_MINECART) ||
            e->GetType() == eTYPE_BOAT || e->instanceof(eTYPE_HANGING_ENTITY)) {
            CompoundTag* eTag = new CompoundTag();
            if (e->save(eTag)) {
                ListTag<DoubleTag>* pos =
                    (ListTag<DoubleTag>*)eTag->getList(L"Pos");

                pos->get(0)->data -= xStart;
                pos->get(1)->data -= yStart;
                pos->get(2)->data -= zStart;

                if (e->instanceof(eTYPE_HANGING_ENTITY)) {
                    ((IntTag*)eTag->get(L"TileX"))->data -= xStart;
                    ((IntTag*)eTag->get(L"TileY"))->data -= yStart;
                    ((IntTag*)eTag->get(L"TileZ"))->data -= zStart;
                }

                entitiesTag->add(eTag);
            }
        }
    }

    tag.put(L"Entities", entitiesTag);

    if (dos != nullptr) NbtIo::write(&tag, dos);
}

void ConsoleSchematicFile::getBlocksAndData(LevelChunk* chunk,
                                            std::vector<uint8_t>* data, int x0,
                                            int y0, int z0, int x1, int y1,
                                            int z1, int& blocksP, int& dataP,
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
    lowerY0 = upperY0 = y0;
    lowerY1 = upperY1 = y1;

    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        lowerY0 = y0;
        lowerY1 = std::min(y1, compressedHeight);
        bHasLower = true;
    }
    if (y1 >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        upperY0 = std::max(y0, compressedHeight) -
                  Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
        upperY1 = y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
        bHasUpper = true;
    }

    std::vector<uint8_t> blockData =
        std::vector<uint8_t>(Level::CHUNK_TILE_COUNT);
    chunk->getBlockData(blockData);
    for (int x = x0; x < x1; x++)
        for (int z = z0; z < z1; z++) {
            if (bHasLower) {
                int slot = x << Level::genDepthBitsPlusFour |
                           z << Level::genDepthBits | lowerY0;
                int len = lowerY1 - lowerY0;
                std::copy(blockData.data() + slot,
                          blockData.data() + slot + len,
                          data->data() + blocksP);
                blocksP += len;
            }
            if (bHasUpper) {
                int slot = (x << Level::genDepthBitsPlusFour |
                            z << Level::genDepthBits | upperY0) +
                           Level::COMPRESSED_CHUNK_SECTION_TILES;
                int len = upperY1 - upperY0;
                std::copy(blockData.data() + slot,
                          blockData.data() + slot + len,
                          data->data() + blocksP);
                blocksP += len;
            }
        }

    std::vector<uint8_t> dataData =
        std::vector<uint8_t>(Level::CHUNK_TILE_COUNT);
    chunk->getDataData(dataData);
    for (int x = x0; x < x1; x++)
        for (int z = z0; z < z1; z++) {
            if (bHasLower) {
                int slot = (x << Level::genDepthBitsPlusFour |
                            z << Level::genDepthBits | lowerY0) >>
                           1;
                int len = (lowerY1 - lowerY0) / 2;
                std::copy(dataData.data() + slot, dataData.data() + slot + len,
                          data->data() + dataP);
                dataP += len;
            }
            if (bHasUpper) {
                int slot = ((x << Level::genDepthBitsPlusFour |
                             z << Level::genDepthBits | upperY0) +
                            Level::COMPRESSED_CHUNK_SECTION_TILES) >>
                           1;
                int len = (upperY1 - upperY0) / 2;
                std::copy(dataData.data() + slot, dataData.data() + slot + len,
                          data->data() + dataP);
                dataP += len;
            }
        }

    // i love amy is the best kissing girls - snuggle lesbian kiss kissing girls FUCKING KISS ALREADY
    if (blockLightP > -1) {
        std::vector<uint8_t> blockLightData =
            std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
        chunk->getBlockLightData(blockLightData);
        for (int x = x0; x < x1; x++)
            for (int z = z0; z < z1; z++) {
                if (bHasLower) {
                    int slot = (x << Level::genDepthBitsPlusFour |
                                z << Level::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::copy(blockLightData.data() + slot,
                              blockLightData.data() + slot + len,
                              data->data() + blockLightP);
                    blockLightP += len;
                }
                if (bHasUpper) {
                    int slot = ((x << Level::genDepthBitsPlusFour |
                                 z << Level::genDepthBits | upperY0) >>
                                1) +
                               (Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::copy(blockLightData.data() + slot,
                              blockLightData.data() + slot + len,
                              data->data() + blockLightP);
                    blockLightP += len;
                }
            }
    }

    // my girlfriend lesbian - kissing girls i love FUCKING KISS ALREADY yuri
    if (skyLightP > -1) {
        std::vector<uint8_t> skyLightData =
            std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
        chunk->getSkyLightData(skyLightData);
        for (int x = x0; x < x1; x++)
            for (int z = z0; z < z1; z++) {
                if (bHasLower) {
                    int slot = (x << Level::genDepthBitsPlusFour |
                                z << Level::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::copy(skyLightData.data() + slot,
                              skyLightData.data() + slot + len,
                              data->data() + skyLightP);
                    skyLightP += len;
                }
                if (bHasUpper) {
                    int slot = ((x << Level::genDepthBitsPlusFour |
                                 z << Level::genDepthBits | upperY0) >>
                                1) +
                               (Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::copy(skyLightData.data() + slot,
                              skyLightData.data() + slot + len,
                              data->data() + skyLightP);
                    skyLightP += len;
                }
            }
    }

    return;
}

void ConsoleSchematicFile::setBlocksAndData(
    LevelChunk* chunk, std::vector<uint8_t>& blockData,
    std::vector<uint8_t>& dataData, std::vector<uint8_t> inputData, int x0,
    int y0, int z0, int x1, int y1, int z1, int& blocksP, int& dataP,
    int& blockLightP, int& skyLightP) {
    bool bHasLower, bHasUpper;
    bHasLower = bHasUpper = false;
    int lowerY0, lowerY1, upperY0, upperY1;
    lowerY0 = upperY0 = y0;
    lowerY1 = upperY1 = y1;

    int compressedHeight = Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
    if (y0 < Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        lowerY0 = y0;
        lowerY1 = std::min(y1, compressedHeight);
        bHasLower = true;
    }
    if (y1 >= Level::COMPRESSED_CHUNK_SECTION_HEIGHT) {
        upperY0 = std::max(y0, compressedHeight) -
                  Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
        upperY1 = y1 - Level::COMPRESSED_CHUNK_SECTION_HEIGHT;
        bHasUpper = true;
    }
    for (int x = x0; x < x1; x++)
        for (int z = z0; z < z1; z++) {
            if (bHasLower) {
                int slot = x << Level::genDepthBitsPlusFour |
                           z << Level::genDepthBits | lowerY0;
                int len = lowerY1 - lowerY0;
                std::copy(inputData.data() + blocksP,
                          inputData.data() + blocksP + len,
                          blockData.data() + slot);
                blocksP += len;
            }
            if (bHasUpper) {
                int slot = (x << Level::genDepthBitsPlusFour |
                            z << Level::genDepthBits | upperY0) +
                           Level::COMPRESSED_CHUNK_SECTION_TILES;
                int len = upperY1 - upperY0;
                std::copy(inputData.data() + blocksP,
                          inputData.data() + blocksP + len,
                          blockData.data() + slot);
                blocksP += len;
            }
        }

    for (int x = x0; x < x1; x++)
        for (int z = z0; z < z1; z++) {
            if (bHasLower) {
                int slot = (x << Level::genDepthBitsPlusFour |
                            z << Level::genDepthBits | lowerY0) >>
                           1;
                int len = (lowerY1 - lowerY0) / 2;
                std::copy(inputData.data() + dataP,
                          inputData.data() + dataP + len,
                          dataData.data() + slot);
                dataP += len;
            }
            if (bHasUpper) {
                int slot = ((x << Level::genDepthBitsPlusFour |
                             z << Level::genDepthBits | upperY0) +
                            Level::COMPRESSED_CHUNK_SECTION_TILES) >>
                           1;
                int len = (upperY1 - upperY0) / 2;
                std::copy(inputData.data() + dataP,
                          inputData.data() + dataP + len,
                          dataData.data() + slot);
                dataP += len;
            }
        }

    // yuri my girlfriend - i love yuri yuri blushing girls
    if (blockLightP > -1) {
        std::vector<uint8_t> blockLightData =
            std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
        chunk->getBlockLightData(blockLightData);
        for (int x = x0; x < x1; x++)
            for (int z = z0; z < z1; z++) {
                if (bHasLower) {
                    int slot = (x << Level::genDepthBitsPlusFour |
                                z << Level::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::copy(inputData.data() + blockLightP,
                              inputData.data() + blockLightP + len,
                              blockLightData.data() + slot);
                    blockLightP += len;
                }
                if (bHasUpper) {
                    int slot = ((x << Level::genDepthBitsPlusFour |
                                 z << Level::genDepthBits | upperY0) >>
                                1) +
                               (Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::copy(inputData.data() + blockLightP,
                              inputData.data() + blockLightP + len,
                              blockLightData.data() + slot);
                    blockLightP += len;
                }
            }
        chunk->setBlockLightData(blockLightData);
    }

    // i love girls yuri - lesbian kiss yuri yuri yuri
    if (skyLightP > -1) {
        std::vector<uint8_t> skyLightData =
            std::vector<uint8_t>(Level::HALF_CHUNK_TILE_COUNT);
        chunk->getSkyLightData(skyLightData);
        for (int x = x0; x < x1; x++)
            for (int z = z0; z < z1; z++) {
                if (bHasLower) {
                    int slot = (x << Level::genDepthBitsPlusFour |
                                z << Level::genDepthBits | lowerY0) >>
                               1;
                    int len = (lowerY1 - lowerY0) / 2;
                    std::copy(inputData.data() + skyLightP,
                              inputData.data() + skyLightP + len,
                              skyLightData.data() + slot);
                    skyLightP += len;
                }
                if (bHasUpper) {
                    int slot = (x << Level::genDepthBitsPlusFour |
                                z << Level::genDepthBits | upperY0) +
                               (Level::COMPRESSED_CHUNK_SECTION_TILES / 2);
                    int len = (upperY1 - upperY0) / 2;
                    std::copy(inputData.data() + skyLightP,
                              inputData.data() + skyLightP + len,
                              skyLightData.data() + slot);
                    skyLightP += len;
                }
            }
        chunk->setSkyLightData(skyLightData);
    }
}

std::vector<std::shared_ptr<TileEntity> >*
ConsoleSchematicFile::getTileEntitiesInRegion(LevelChunk* chunk, int x0, int y0,
                                              int z0, int x1, int y1, int z1) {
    std::vector<std::shared_ptr<TileEntity> >* result =
        new std::vector<std::shared_ptr<TileEntity> >;
    for (auto it = chunk->tileEntities.begin(); it != chunk->tileEntities.end();
         ++it) {
        std::shared_ptr<TileEntity> te = it->second;
        if (te->x >= x0 && te->y >= y0 && te->z >= z0 && te->x < x1 &&
            te->y < y1 && te->z < z1) {
            result->push_back(te);
        }
    }
    return result;
}
