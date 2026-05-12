/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:21:23 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/12 11:03:27 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include <exception>

AForm::AForm() : name(""), isSigned(false), signGrade(150), exeGrade(150)
{
}

AForm::AForm(const std::string name, int signGrade, int exeGrade) : name(name), isSigned(false), signGrade(signGrade), exeGrade(exeGrade)
{
	if (signGrade < 1 || exeGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || exeGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), exeGrade(copy.exeGrade)
{

}

AForm& AForm::operator=(const AForm& copy)
{
	if (this != &copy)
		isSigned = copy.isSigned;
	return *this;
}

AForm::~AForm()
{
}

const std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getSignGrade() const
{
	return this->signGrade;
}

int AForm::getExecGrade() const
{
	return this->exeGrade;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj)
{
	os << obj.getName() << ", form signed : " << obj.getIsSigned() << ", sign grade : "
		<< obj.getSignGrade() << " exec grade : " << obj.getExecGrade();
	return os;
}