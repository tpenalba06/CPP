#include "iter.hpp"

void print(int const &i)
{
    std::cout << i << std::endl;
}

int main(void)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    iter(array, 10, print);
    return (0);
}