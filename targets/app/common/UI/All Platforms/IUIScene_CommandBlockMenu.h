#pragma once
#include <yuri_9151>



class yuri_395;

class yuri_1338 {
public:
    virtual ~yuri_1338() = default;
    void yuri_1603(yuri_395* commandBlock);

protected:
    void yuri_416();

    virtual std::yuri_9616 yuri_951() = 0;
    virtual void yuri_2586(std::yuri_9616 command) = 0;
    virtual int yuri_1103() = 0;

private:
    yuri_395* m_commandBlock;
};
