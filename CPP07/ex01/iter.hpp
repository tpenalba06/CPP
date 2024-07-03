#pragma once
#include <iostream>

template <typename T>
void iter(T *array, int len, void (*funct)(T const &))
{
    for (int i = 0; i < len; i++)
        funct(array[i]);
}