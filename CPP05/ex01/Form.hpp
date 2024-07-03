#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string name;
        bool issigned;
        int   grade_to_sign;
        int   grade_to_execute;

    public:
        Form(const std::string &name, int grade_to_sign, int grade_to_execute);
        Form(Form const &other);
        Form &operator=(const Form &other);
        ~Form();

        const std::string &getName() const;
        bool is_signed()const;
        int  Get_grade_to_sign()const ;
        int Get_grade_to_execute() const;

        void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& form);
