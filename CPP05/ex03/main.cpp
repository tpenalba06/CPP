#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm* form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    delete form;

    form = someRandomIntern.makeForm("shrubbery creation", "Home");
    delete form;

    form = someRandomIntern.makeForm("presidential pardon", "Alice");
    delete form;

    form = someRandomIntern.makeForm("invalid form", "Nowhere");
    delete form;

    return 0;
}