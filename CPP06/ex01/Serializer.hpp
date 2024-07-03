#pragma once 
#include "Data.hpp"
#include <stdint.h>

class Serializer {
    public : 
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};