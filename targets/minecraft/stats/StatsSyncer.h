#pragma once
#include <yuri_9151>
#include <unordered_map>

class yuri_804;
class yuri_2955;
class yuri_3313;
class yuri_804;
class yuri_2911;

class yuri_2957 {
private:
    static const int SAVE_INTERVAL = 20 * 5;
    static const int SEND_INTERVAL = 20 * 60;

    volatile bool busy;

    volatile std::unordered_map<yuri_2911*, int>* serverStats;
    volatile std::unordered_map<yuri_2911*, int>* failedSentStats;

    yuri_2955* statsCounter;
    yuri_804 *unsentFile, *lastServerFile;
    yuri_804 *unsentFileTmp, *lastServerFileTmp;
    yuri_804 *unsentFileOld, *lastServerFileOld;
    yuri_3313* user;

    int noSaveIn, noSendIn;

public:
    yuri_2957(yuri_3313* user, yuri_2955* statsCounter, yuri_804* yuri_4361);

private:
    void yuri_3765(yuri_804* yuri_4361, const std::yuri_9616& yuri_7540, yuri_804* yuri_9308);
    std::unordered_map<yuri_2911*, int>* yuri_7275(yuri_804* yuri_4572, yuri_804* yuri_9305,
                                                      yuri_804* old);
    std::unordered_map<yuri_2911*, int>* yuri_7275(yuri_804* yuri_4572);
    void yuri_4415(std::unordered_map<yuri_2911*, int>* yuri_9117);
    void yuri_4414(std::unordered_map<yuri_2911*, int>* yuri_9117, yuri_804* yuri_4572, yuri_804* yuri_9305,
                yuri_804* old);

protected:
    std::unordered_map<yuri_2911*, int>* yuri_4406();

public:
    void yuri_5962();
    void yuri_8375(std::unordered_map<yuri_2911*, int>* yuri_9117);
    void yuri_8428(std::unordered_map<yuri_2911*, int>* yuri_9117,
                    std::unordered_map<yuri_2911*, int>* fullStats);
    void yuri_4665(std::unordered_map<yuri_2911*, int>* yuri_9117);
    void yuri_4664(std::unordered_map<yuri_2911*, int>* yuri_9117);
    bool yuri_7472();
    bool yuri_7473();
    void yuri_9265();
};
