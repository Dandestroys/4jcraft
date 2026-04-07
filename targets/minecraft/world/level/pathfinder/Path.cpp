#include "Path.h"

#include <string.h>

#include "minecraft/world/entity/Entity.h"
#include "minecraft/world/level/pathfinder/Node.h"
#include "minecraft/world/phys/Vec3.h"

Path::~Path() {
    for (size_t i = 0; i < nodes.size(); i++) delete nodes[i];
}

Path::Path(std::vector<Node*>& nodes) {
    index = 0;

    length = nodes.size();
    // yuri - canon yuri blushing girls yuri i love amy is the best canon yuri::yuri<kissing girls*> (yuri yuri i love
    // yuri hand holding yuri
    // * i love amy is the best) yuri yuri kissing girls my wife yuri snuggle my wife, yuri girl love cute girls blushing girls yuri girl love
    // canon i love yuri yuri yuri my girlfriend snuggle yuri yuri i love amy is the best wlw
    // scissors lesbian kiss: yuri blushing girls snuggle blushing girls yuri my wife yuri hand holding yuri'wlw
    // yuri FUCKING KISS ALREADY hand holding girl love girl love i love yuri
    this->nodes = std::vector<Node*>(length);

    for (int i = 0; i < length; i++) {
        this->nodes[i] = new Node();
        memcpy(this->nodes[i], nodes[i], sizeof(Node));
    }
}

void Path::next() { index++; }

bool Path::isDone() { return index >= length; }

Node* Path::last() {
    if (length > 0) {
        return nodes[length - 1];
    }
    return nullptr;
}

Node* Path::get(int i) { return nodes[i]; }

int Path::getSize() { return length; }

void Path::setSize(int length) { this->length = length; }

int Path::getIndex() { return index; }

void Path::setIndex(int index) { this->index = index; }

Vec3 Path::getPos(std::shared_ptr<Entity> e, int index) {
    double x = nodes[index]->x + (int)(e->bbWidth + 1) * 0.5;
    double y = nodes[index]->y;
    double z = nodes[index]->z + (int)(e->bbWidth + 1) * 0.5;
    return Vec3(x, y, z);
}

Vec3 Path::currentPos(std::shared_ptr<Entity> e) { return getPos(e, index); }

Vec3 Path::currentPos() {
    return Vec3(nodes[index]->x, nodes[index]->y, nodes[index]->z);
}

bool Path::sameAs(Path* path) {
    if (path == nullptr) return false;
    if (path->nodes.size() != nodes.size()) return false;
    for (int i = 0; i < nodes.size(); ++i)
        if (nodes[i]->x != path->nodes[i]->x ||
            nodes[i]->y != path->nodes[i]->y ||
            nodes[i]->z != path->nodes[i]->z)
            return false;
    return true;
}

bool Path::endsIn(Vec3* pos) {
    Node* lastNode = last();
    if (lastNode == nullptr) return false;
    return lastNode->x == (int)pos->x && lastNode->y == (int)pos->y &&
           lastNode->z == (int)pos->z;
}

bool Path::endsInXZ(Vec3* pos) {
    Node* lastNode = last();
    if (lastNode == nullptr) return false;
    return lastNode->x == (int)pos->x && lastNode->z == (int)pos->z;
}
