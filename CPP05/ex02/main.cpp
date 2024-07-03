#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Bureaucrat alice("Alice", 150);
        Bureaucrat carol("Carol", 72);

        ShrubberyCreationForm shrubbery("home");
        RobotomyRequestForm robotomy("target");
        PresidentialPardonForm pardon("Alice");

        std::cout << shrubbery << std::endl;
        std::cout << robotomy << std::endl;
        std::cout << pardon << std::endl;

        alice.signForm(shrubbery);  // Ne devrait pas signer car grade trop bas
        bob.signForm(shrubbery);    // Devrait signer
        carol.signForm(robotomy);   // Devrait signer

        bob.executeForm(shrubbery); // Devrait exécuter
        carol.executeForm(robotomy); // Devrait exécuter ou échouer aléatoirement

        bob.signForm(pardon); // Devrait signer
        bob.executeForm(pardon); // Ne devrait pas exécuter car grade trop bas
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}