#include "RobotomyRequestForm.hpp"

// Constructeurs et destructeur
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45, target) {
    std::srand(std::time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// Méthode executeAction
void RobotomyRequestForm::executeAction() const {
    std::cout << "Bzzzzz... Vrrrrrr... Clang!" << std::endl;
    if (std::rand() % 2) {
        std::cout << getTarget() << " a été robotomisé avec succès !" << std::endl;
    } else {
        std::cout << "La robotomisation de " << getTarget() << " a échoué." << std::endl;
    }
}
