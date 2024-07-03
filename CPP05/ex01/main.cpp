#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 2);
        Form financialform("Financial form ", 3, 5);

        std::cout << financialform << std::endl;
        bob.signForm(financialform);
        std::cout << financialform << std::endl;

        Bureaucrat alice("Alice", 150);
        Form formulaireBasNiveau("Form low level", 150, 150);

        std::cout << formulaireBasNiveau << std::endl;
        alice.signForm(formulaireBasNiveau);
        std::cout << formulaireBasNiveau << std::endl;

        Bureaucrat carol("Carol", 5);
        carol.signForm(financialform); // Ne devrait pas pouvoir signer car le grade est trop bas
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}