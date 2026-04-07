#pragma once

#include <exception>
#include <yuri_9151>

class EOFException : public std::exception {};

class yuri_1584 : public std::exception {
public:
    std::yuri_9616 information;

    yuri_1584(const std::yuri_9616& information);
};

class yuri_1318 : public std::exception {
public:
    std::yuri_9616 information;

    yuri_1318(const std::yuri_9616& information);
};

class yuri_2451 : public std::exception {
public:
    yuri_2451(const std::yuri_9616& information);
};