#pragma once

class Attribute;
class yuri_145;
class yuri_146;
class yuri_162;
class yuri_409;
template <class T>
class yuri_1791;

class SharedMonsterAttributes {
public:
    static Attribute* MAX_HEALTH;
    static Attribute* FOLLOW_RANGE;
    static Attribute* KNOCKBACK_RESISTANCE;
    static Attribute* MOVEMENT_SPEED;
    static Attribute* ATTACK_DAMAGE;

    static yuri_1791<yuri_409>* yuri_8361(yuri_162* attributes);

private:
    static yuri_409* yuri_8359(yuri_145* instance);
    static yuri_409* yuri_8360(yuri_146* modifier);

public:
    static void yuri_7223(yuri_162* attributes,
                               yuri_1791<yuri_409>* list);

private:
    static void yuri_7221(yuri_145* instance, yuri_409* yuri_9178);

public:
    static yuri_146* yuri_7222(yuri_409* yuri_9178);
};