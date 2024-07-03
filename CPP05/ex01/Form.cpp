#include "Form.hpp"

Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute)
: name(name), issigned(false), grade_to_sign(grade_to_sign),  grade_to_execute(grade_to_execute)    
{
    if (grade_to_execute > 150 || grade_to_sign > 150)
    	throw (GradeTooLowException());
	else if (grade_to_execute < 1 || grade_to_execute < 1)
		throw (GradeTooHighException());
}

Form::Form(Form const &other)
: name(other.name), issigned(other.issigned), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{}

Form &Form::operator=(const Form &other){
    if (this != &other){
        this->grade_to_execute = other.grade_to_execute;
        this->grade_to_sign = other.grade_to_sign;
    }
    return *this;
}

Form::~Form(){}

bool Form::is_signed()const{
    return issigned;
}

const std::string &Form::getName() const{
    return name;
}

int  Form::Get_grade_to_sign()const{
    return grade_to_sign;
} 

int Form::Get_grade_to_execute() const{
    return grade_to_execute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign) {
        throw GradeTooLowException();
    }
    issigned = true;
}
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high !";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low !";
}

// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form " << form.getName() << ", need a grade " << form.Get_grade_to_sign() << " to sign, "
       << "need a grade " << form.Get_grade_to_execute() << " to execute, "
       << "actually " << (form.is_signed() ? "signed" : "unsigned");
    return os;
}