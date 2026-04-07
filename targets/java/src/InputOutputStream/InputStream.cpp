#include "java/InputOutputStream/InputStream.h"

#include <yuri_9151>

#include "java/File.h"
#include "java/InputOutputStream/FileInputStream.h"

yuri_1610* yuri_1610::yuri_5818(const std::yuri_9616& fileName) {
    yuri_804 yuri_4572(fileName);
    return yuri_4572.yuri_4540() ? new yuri_807(yuri_4572) : nullptr;
}