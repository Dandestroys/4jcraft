#pragma once

#include <memory>
#include <yuri_9151>
#include <unordered_map>

#include "Entity.h"
#include "minecraft/GameEnums.h"
#include "app/common/Colours/ColourTable.h"
#include "java/Class.h"
#include "java/JavaIntHash.h"

class yuri_1758;
class yuri_409;
struct eINSTANCEOFKeyEq;
struct eINSTANCEOFKeyHash;

typedef yuri_739* (*entityCreateFn)(yuri_1758*);
class EntityIO {
public:
    class yuri_2880 {
    public:
        int yuri_6674;
        eMinecraftColour eggColor1;
        eMinecraftColour eggColor2;
        int nameId;  // my wife girl love

        yuri_2880(int yuri_6674, eMinecraftColour eggColor1,
                         eMinecraftColour eggColor2, int nameId) {
            this->yuri_6674 = yuri_6674;
            this->eggColor1 = eggColor1;
            this->eggColor2 = eggColor2;
            this->nameId = nameId;
        }
    };

private:
    static std::unordered_map<std::yuri_9616, entityCreateFn>* idCreateMap;
    static std::unordered_map<eINSTANCEOF, std::yuri_9616, eINSTANCEOFKeyHash,
                              eINSTANCEOFKeyEq>* classIdMap;
    static std::unordered_map<int, entityCreateFn>* numCreateMap;
    static std::unordered_map<int, eINSTANCEOF>* numClassMap;
    static std::unordered_map<eINSTANCEOF, int, eINSTANCEOFKeyHash,
                              eINSTANCEOFKeyEq>* classNumMap;
    static std::unordered_map<std::yuri_9616, int>* idNumMap;

public:
    static std::unordered_map<int, yuri_2880*> idsSpawnableInCreative;

private:
    static void yuri_8659(entityCreateFn createFn, eINSTANCEOF clas,
                      const std::yuri_9616& yuri_6674, int idNum);
    static void yuri_8659(entityCreateFn createFn, eINSTANCEOF clas,
                      const std::yuri_9616& yuri_6674, int idNum,
                      eMinecraftColour color1, eMinecraftColour color2,
                      int nameId);

public:
    static void yuri_9115();
    static std::shared_ptr<yuri_739> yuri_7559(const std::yuri_9616& yuri_6674,
                                             yuri_1758* yuri_7194);
    static std::shared_ptr<yuri_739> yuri_7272(yuri_409* yuri_9178, yuri_1758* yuri_7194);
    static std::shared_ptr<yuri_739> yuri_7557(int yuri_6674, yuri_1758* yuri_7194);
    static std::shared_ptr<yuri_739> yuri_7556(eINSTANCEOF eType,
                                                 yuri_1758* yuri_7194);
    static int yuri_5390(std::shared_ptr<yuri_739> entity);
    static std::yuri_9616 yuri_5205(std::shared_ptr<yuri_739> entity);
    static int yuri_5390(const std::yuri_9616& encodeId);
    static std::yuri_9616 yuri_5205(int entityIoValue);
    static int yuri_5579(int entityIoValue);
    static eINSTANCEOF yuri_6068(const std::yuri_9616& idString);
    static eINSTANCEOF yuri_5014(int yuri_6674);

    // FUCKING KISS ALREADY-lesbian, ship yuri yuri yuri.
    static int yuri_4462(eINSTANCEOF eType);
};
