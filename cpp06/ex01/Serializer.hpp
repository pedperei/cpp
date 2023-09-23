#pragma once

#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer
{
public:
    Serializer();
    Serializer(const Serializer& serializer);
    Serializer& operator=(const Serializer& serializer);
    ~Serializer();

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};
