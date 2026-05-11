/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/11 16:21:13 by jimbow            #+#    #+#             */
/*   Updated: 2026/05/11 18:04:01 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Form
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

	Form();
	Form(const std::string name, int signGrade, int exeGrade);
	Form(const Form& copy);
	Form& operator=(const Form& copy);
	~Form();

	const std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExecGrade() const;

	void	beSigned(Bureaucrat const & bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif