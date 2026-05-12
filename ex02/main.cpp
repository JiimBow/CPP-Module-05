/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:51 by jodone            #+#    #+#             */
/*   Updated: 2026/05/12 17:51:55 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(0));
    std::cout << "====SHRUBBERY TEST====" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 1);

        ShrubberyCreationForm tree("home");

        std::cout << tree << std::endl;

        bob.signForm(tree);

        tree.execute(bob);

        std::cout << "Shrubbery created!" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "====ROBOTOMY TEST====" << std::endl;

    try
    {
        Bureaucrat bob("Bob", 1);
        RobotomyRequestForm form("Marvin");

        bob.signForm(form);

        form.execute(bob);
        form.execute(bob);
        form.execute(bob);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
