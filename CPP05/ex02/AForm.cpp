#include "AForm.hpp"

AForm::AForm(const std::string &name, int grade_to_sign, int grade_to_execute, const std::string &_target)
: name(name), issigned(false), grade_to_sign(grade_to_sign),  grade_to_execute(grade_to_execute), _target(_target)  
{
    if (grade_to_execute > 150 || grade_to_sign > 150)
    	throw (GradeTooLowException());
	else if (grade_to_execute < 1 || grade_to_execute < 1)
		throw (GradeTooHighException());
}

AForm::AForm(AForm const &other)
: name(other.name), issigned(other.issigned), grade_to_sign(other.grade_to_sign), grade_to_execute(other.grade_to_execute)
{}

AForm &AForm::operator=(const AForm &other){
    if (this != &other){
        this->grade_to_execute = other.grade_to_execute;
        this->grade_to_sign = other.grade_to_sign;
    }
    return *this;
}

AForm::~AForm(){}

////////////////
bool AForm::is_signed()const{
    return issigned;
}

const std::string &AForm::getName() const{
    return name;
}

int  AForm::Get_grade_to_sign()const{
    return grade_to_sign;
} 

int AForm::Get_grade_to_execute() const{
    return grade_to_execute;
}


void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > grade_to_sign) {
        throw GradeTooLowException();
    }
    issigned = true;
}

const std::string &AForm::getTarget() const {
    return _target;
}

/////////////////////

void AForm::execute(Bureaucrat const &executor) const{
    if(!issigned){
        throw FormNotSignedException();
    }
    if(executor.getGrade() > grade_to_execute){
        throw GradeTooLowException();
    }
    executeAction();
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high !";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low !";
}

const char *AForm::FormNotSignedException::what() const throw(){
    return "Form not signed yet";
}
// Surcharge de l'opérateur d'insertion
std::ostream& operator<<(std::ostream& os, const AForm& Aform) {
    os << "AForm " << Aform.getName() << ", need a grade " << Aform.Get_grade_to_sign() << " to sign, "
       << "need a grade " << Aform.Get_grade_to_execute() << " to execute, "
       << "actually " << (Aform.is_signed() ? "signed" : "unsigned");
    return os;
}