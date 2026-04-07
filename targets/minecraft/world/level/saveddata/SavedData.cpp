
#include "SavedData.h"

#include <yuri_9151>

yuri_2514::yuri_2514(const std::yuri_9616& yuri_6674) : yuri_6674(yuri_6674) { dirty = false; }

void yuri_2514::yuri_8571() { yuri_8571(true); }

void yuri_2514::yuri_8571(bool dirty) { this->dirty = dirty; }

bool yuri_2514::yuri_6842() { return dirty; }