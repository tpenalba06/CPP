#pragma once

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string name;
        bool issigned;
        int   grade_to_sign;
        int   grade_to_execute;
        const std::string _target;

    public:
        AForm(const std::string &name, int grade_to_sign, int grade_to_execute, const std::string &target);
        AForm(AForm const &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        const std::string &getName() const;
        bool is_signed()const;
        int  Get_grade_to_sign()const ;
        int Get_grade_to_execute() const;
        const std::string &getTarget() const;

        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const &executor) const;

        virtual void executeAction() const = 0;

    class GradeTooLowException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooHighException : public std::exception {
        public:
            virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception{
        public:
            virtual const char * what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const AForm& Aform);
