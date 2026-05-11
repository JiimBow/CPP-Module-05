/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:51 by jodone            #+#    #+#             */
/*   Updated: 2026/05/11 18:29:38 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat Yosh("Yosh", 42);
		Form Taxes("Taxes", 50, 25);
	
		std::cout << Yosh << std::endl;
		std::cout << Taxes << std::endl;

		Yosh.signForm(Taxes);

		std::cout << Taxes << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat Bob("Bob", 65);
		Form MariageContract("MariageContract", 50, 25);
	
		std::cout << Bob << std::endl;
		std::cout << MariageContract << std::endl;

		Bob.signForm(MariageContract);

		std::cout << MariageContract << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Form BadForm("BadForm", 0, 25);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Form AnotherBad("AnotherBad", 151, 25);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
