#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat Joe("Joe", 1);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Nico("Nico", 140);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}