#pragma once

#include <iostream>
#include "Form.hpp"

class Form;

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

        void signForm(Form &form);

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