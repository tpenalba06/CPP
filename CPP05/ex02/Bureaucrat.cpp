/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:03:54 by tpenalba          #+#    #+#             */
/*   Updated: 2024/06/29 23:01:59 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade)
{
    if (grade > 150)
    	throw (GradeTooLowException());
	else if (grade < 1)
		throw (GradeTooHighException());
    else
		return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other):name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other){
    if (this != &other)
    {
        this->grade = other.grade;
    }
    return *this;
}

const std::string &Bureaucrat::getName() const{
    return this->name;
}

int Bureaucrat::getGrade() const{
    return this->grade;   
}

void    Bureaucrat::upgrade(){
    if(grade > 1)
        this->grade--;
    else
        throw(GradeTooHighException());
}

void    Bureaucrat::downgrade(){
    if(grade < 150)
        this->grade++;
    else
        throw(GradeTooLowException());
}

void Bureaucrat::signForm(AForm &form){
    try{
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
        }
    catch(const std::exception &e){
        std::cout << name << " did'nt signed " << form.getName() << " because " << e.what() << std::endl;
    }
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::executeForm(const AForm& form) const {
    try {
        form.execute(*this);
        std::cout << name << " a exécuté " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << name << " n'a pas pu exécuter " << form.getName() << " parce que " << e.what() << std::endl;
    }
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
    return os;
}