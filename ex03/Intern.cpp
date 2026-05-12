/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 18:27:39 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/12 18:55:41 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern()
{
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern& copy)
{
	(void)copy;
	return *this;
}

Intern::~Intern()
{
}

static AForm* createShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

static AForm* createRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

static AForm* createPresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string nameForm, std::string targetForm)
{
	std::string forms[3] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* (*creators[3])(std::string) = 
	{
		&createShrubberyForm,
		&createRobotomyForm,
		&createPresidentialForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (nameForm == forms[i])
		{
			std::cout << "Intern creates " << nameForm << std::endl;
			return creators[i](targetForm);
		}
	}

	std::cout << "Intern can't create " << nameForm << std::endl;
	throw std::invalid_argument("Unknow form name");
}