/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:29:01 by jodone            #+#    #+#             */
/*   Updated: 2026/05/06 10:03:59 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Bureaucrat
{
private:
	std::string const name;
	int	grade;
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
	
	
	Bureaucrat(std::string const & name, int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();

	const std::string	getName(void) const;
	int					getGrade(void) const;
	void				UpGrade(void);
	void				DownGrade(void);
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);
