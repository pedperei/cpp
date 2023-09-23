#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& serializer)
{
    *this = serializer;
}

Serializer& Serializer::operator=(const Serializer& serializer)
{
    (void)serializer;
    return *this;
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}
