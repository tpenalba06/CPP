#include "ABC.hpp"
#include "Base.hpp"

int main(void)
{
    Base *p = generate();
    identify(p);
    identify(*p);
    return (0);
}