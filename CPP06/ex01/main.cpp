#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main(){
    Data myData;
    myData.value = 3434;

    uintptr_t serialized = Serializer::serialize(&myData);

    Data *deserialized = Serializer::deserialize(serialized);

    if(deserialized == &myData){
        std::cout << "Serialization and deserialization successfull" << std::endl;
    }
    else
        std::cout << "Serialization and deserialization failed" << std::endl;

    return(0);
}