/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:21:23 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/11 18:08:24 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include <exception>

Form::Form() : name(""), isSigned(false), signGrade(150), exeGrade(150)
{
}

Form::Form(const std::string name, int signGrade, int exeGrade) : name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade)
{
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), exeGrade(copy.exeGrade)
{

}

Form& Form::operator=(const Form& copy)
{
	if (this != &copy)
		isSigned = copy.isSigned;
	return *this;
}

Form::~Form()
{
}

const std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getSignGrade() const
{
	return this->signGrade;
}

int Form::getExecGrade() const
{
	return this->exeGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Form::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", form signed : " << obj.getIsSigned() << ", sign grade : "
		<< obj.getSignGrade() << " exec grade : " << obj.getExecGrade();
	return os;
}