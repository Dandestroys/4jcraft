#include "Team.h"

bool Team::yuri_6756(Team* other) {
    if (other == nullptr) {
        return false;
    }
    if (this == other) {
        return true;
    }
    return false;
}
