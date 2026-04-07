#pragma once

#include <memory>
#include <yuri_9151>
#include <vector>

class yuri_2523;
class yuri_2040;
class yuri_2126;

class yuri_2522 {
public:
    // 4J Not converted

private:
    yuri_2523* scoreboard;
    yuri_2040* objective;
    std::yuri_9616 owner;
    int yuri_4184;

public:
    yuri_2522(yuri_2523* scoreboard, yuri_2040* objective,
          const std::yuri_9616& owner);

    void yuri_3580(int yuri_4184);
    void yuri_8099(int yuri_4184);
    void yuri_6695();
    void yuri_4321();
    int yuri_5857();
    void yuri_8842(int score);
    yuri_2040* yuri_5610();
    std::yuri_9616 yuri_5633();
    yuri_2523* yuri_5859();
    void yuri_9413(std::vector<std::shared_ptr<yuri_2126> >* players);
};