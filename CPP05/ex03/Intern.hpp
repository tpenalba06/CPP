#pragma once 
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm* makeForm(const std::string& formName, const std::string& target);

private:
    typedef AForm* (Intern::*FormCreator)(const std::string& target) const;
    static const std::string formNames[3];
    static const FormCreator formCreators[3];

    AForm* createShrubberyCreationForm(const std::string& target) const;
    AForm* createRobotomyRequestForm(const std::string& target) const;
    AForm* createPresidentialPardonForm(const std::string& target) const;
};