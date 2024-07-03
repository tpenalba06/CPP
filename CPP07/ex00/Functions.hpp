#pragma once
#include <iostream>
#include <string>

template <typename T>
void swap(T &a, T&b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T min (const T &a, const T &b){
    if (b < a)
        return b;
    else 
        return a; 
}

template <typename T>
T max(T &a, T &b){
    if (b > a)
        return b;
    else
        return a;
}