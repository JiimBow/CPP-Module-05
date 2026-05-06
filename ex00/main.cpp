/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:51 by jodone            #+#    #+#             */
/*   Updated: 2026/05/06 10:54:01 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	try
	{
		Bureaucrat Yosh("Yosh", 2);
	
		std::cout << Yosh << std::endl;

		Yosh.UpGrade();
		std::cout << Yosh << std::endl;
		Yosh.UpGrade();
		std::cout << Yosh << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat Yosh("Yosh", 149);
		Yosh.DownGrade();
		std::cout << Yosh << std::endl;
		Yosh.DownGrade();
		std::cout << Yosh << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat Jim("Jim", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat Bob("Bob", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
