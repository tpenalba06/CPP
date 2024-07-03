#include "PresidentialPardonForm.hpp"

// Constructeurs et destructeur
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("PresidentialPardonForm", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

// Méthode executeAction
void PresidentialPardonForm::executeAction() const {
    std::cout << getTarget() << " a été gracié(e) par Zaphod Beeblebrox." << std::endl;
}