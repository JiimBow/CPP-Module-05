/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:29:01 by jodone            #+#    #+#             */
/*   Updated: 2026/05/05 13:48:48 by jodone           ###   ########.fr       */
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
		const char* what() const throw()
		{
            return "Grade too high";
		}
	};
	
	class GradeTooLowExcetion : public std::exception
	{
	public:
		const char* waht() const throw()
		{
			return "Grade too low";
		}
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
