/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:29:25 by jodone            #+#    #+#             */
/*   Updated: 2026/05/06 10:09:31 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <exception>
#include <stdexcept>

Bureaucrat::Bureaucrat(std::string const & name, int grade) : name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy)
{
	if (this != &copy)
		grade = copy.grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void	Bureaucrat::UpGrade()
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void	Bureaucrat::DownGrade()
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too High";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}