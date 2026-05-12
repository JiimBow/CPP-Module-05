/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:21:13 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/12 16:40:11 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class AForm
{
private:
	const std::string	name;
	bool	isSigned;
	const int signGrade;
	const int exeGrade;
public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	AForm();
	AForm(const std::string name, int signGrade, int exeGrade);
	AForm(const AForm& copy);
	AForm& operator=(const AForm& copy);
	virtual ~AForm();

	const std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void	beSigned(Bureaucrat const & bureaucrat);
	virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif