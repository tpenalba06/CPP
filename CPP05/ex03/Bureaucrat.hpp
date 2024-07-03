#pragma once

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
    private :
        const std::string name;
        int grade;
    public :
        Bureaucrat(const std::string &name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();

        const std::string &getName() const;
        int     getGrade() const;
        void    upgrade();
        void    downgrade();

        void signForm(AForm &form);
        void executeForm(const AForm& form) const;

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);