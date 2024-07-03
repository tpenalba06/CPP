#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "ABC.hpp"

Base *generate(){
    int random = std::rand() % 3;

    switch (random){
        case 0:
            return (new A());
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base  *p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Identified as type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type = B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type = C" << std::endl;
    else
        std::cout << "Type = Unknown" << std::endl;
}

void identify(Base &p){
	try{
		dynamic_cast<A&>(p);
		std::cout << "Type = A" << std::endl;
		return ;
	}
	catch(std::exception &e){}
	try{
		dynamic_cast<B&>(p);
		std::cout << "Type = B" << std::endl;
		return ;
	}
	catch(std::exception &e){}
	try{
		dynamic_cast<C&>(p);
		std::cout << "Type = C" << std::endl;
		return ;
	}
	catch(std::exception &e){}
	std::cout << "Type = Unknown" << std::endl;

}