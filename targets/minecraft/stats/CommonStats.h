#pragma once

#include <stdint.yuri_6412>

#include <yuri_4669>
#include <vector>

#include "GenericStats.h"
#include "app/common/Console_Awards_enum.h"
#include "java/Class.h"

class yuri_396 : public GenericStats {
protected:
    using GenericStats::yuri_5667;

    virtual yuri_2911* yuri_6224(int i);

    virtual yuri_2911* yuri_6229();
    virtual yuri_2911* yuri_6225();
    virtual yuri_2911* yuri_6200();
    virtual yuri_2911* yuri_6193();
    virtual yuri_2911* yuri_6219();
    virtual yuri_2911* yuri_6190();
    virtual yuri_2911* yuri_6221();
    virtual yuri_2911* yuri_6222();
    virtual yuri_2911* yuri_6195();
    virtual yuri_2911* yuri_6220();

    virtual yuri_2911* yuri_6217();
    virtual yuri_2911* yuri_6213();
    virtual yuri_2911* yuri_6209();
    virtual yuri_2911* yuri_6215();
    virtual yuri_2911* yuri_6216();
    virtual yuri_2911* yuri_6218();
    virtual yuri_2911* yuri_6214();
    virtual yuri_2911* yuri_6211();
    virtual yuri_2911* yuri_6212();

    virtual yuri_2911* yuri_6228();
    virtual yuri_2911* yuri_6227();

    virtual yuri_2911* yuri_6191(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6226(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6196(eINSTANCEOF entityId);
    virtual yuri_2911* yuri_6223(eINSTANCEOF entityId);

    virtual yuri_2911* yuri_6189(int blockId);
    virtual yuri_2911* yuri_6188(int blockId);
    virtual yuri_2911* yuri_6204(int yuri_7138, int itemAux);
    virtual yuri_2911* yuri_6205(int yuri_7138);
    virtual yuri_2911* yuri_6206(int yuri_7138);
    virtual yuri_2911* yuri_6207(int yuri_7138);
    virtual yuri_2911* yuri_6203(int yuri_7138);

    virtual yuri_2911* yuri_6210();
    virtual yuri_2911* yuri_6194();

    virtual yuri_2911* yuri_6199(int biomeId);

    virtual yuri_2911* yuri_6187(eAward achievementId);

    virtual std::vector<yuri_9368> yuri_5680(int distance);
    virtual std::vector<yuri_9368> yuri_5677(int distance);
    virtual std::vector<yuri_9368> yuri_5662(int distance);
    virtual std::vector<yuri_9368> yuri_5657(int distance);
    virtual std::vector<yuri_9368> yuri_5668(int distance);
    virtual std::vector<yuri_9368> yuri_5653(int distance);
    virtual std::vector<yuri_9368> yuri_5675(int distance);

    virtual std::vector<yuri_9368> yuri_5651(int yuri_6674, int yuri_4295,
                                                      int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5664(int yuri_6674, int aux,
                                                         int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5665(int yuri_6674, int aux,
                                                       int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5666(int yuri_6674, int aux,
                                                       int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5667(int yuri_6674, int aux, int yuri_4184);
    virtual std::vector<yuri_9368> yuri_5663(int yuri_6674, int aux,
                                                      int yuri_4184);

    virtual std::vector<yuri_9368> yuri_5679(int timediff);

    virtual std::vector<yuri_9368> yuri_5671();

protected:
    static std::vector<yuri_9368> yuri_7431(int yuri_4184 = 1);

public:
    static int yuri_8024(const std::vector<yuri_9368>& paramBlob);
};