/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/12 11:26:05 by jodone            #+#    #+#             */
/*   Updated: 2026/05/12 17:41:56 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyForm", 145, 137), target(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy), target(copy.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{
		AForm::operator=(copy);
		target = copy.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!getIsSigned())
		throw FormNotSignedException();
	
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	
	std::ofstream file((target + "_shrubbery").c_str());

	file	<<	"       # #### ####\n"
	   		<<	"    ### \\/#|### |/####\n"
			<< "   ##\\/#/ \\||/##/_/##/_#\n"
			<< "  ###  \\/###|/ \\/ # ###\n"
			<< " ##_\\_#\\_\\## | #/###_/_####\n"
			<< "## #### # \\ #| /  #### ##/##\n"
			<< " __#_--###`  |{,###---###-~\n"
			<< "         \\ }{\n"
			<< "           }}{\n"
			<< "           }}{\n"
			<< "           {{}\n"
			<< "     , -=-~{ .-^- _\n"
			<< "           `}\n"
			<< "            {\n";
	file.close();
}