/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:51 by jodone            #+#    #+#             */
/*   Updated: 2026/05/12 19:06:00 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    try
    {
        std::cout << "==== Bureaucrats ====" << std::endl;

        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 40);
        Bureaucrat larbin("Larbin", 140);

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << larbin << std::endl;
        std::cout << std::endl;

        std::cout << "==== Intern creates forms ====" << std::endl;

        Intern someIntern;

        AForm* f1 = someIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = someIntern.makeForm("robotomy request", "Bender");
        AForm* f3 = someIntern.makeForm("presidential pardon", "Arthur Dent");

        std::cout << *f1 << std::endl;
        std::cout << *f2 << std::endl;
        std::cout << *f3 << std::endl;
        std::cout << std::endl;

        std::cout << "==== Signing forms ====" << std::endl;

        larbin.signForm(*f1);
        manager.signForm(*f2);
        boss.signForm(*f3);
        std::cout << std::endl;

        std::cout << "==== Execution tests ====" << std::endl;

        larbin.executeForm(*f1);
        manager.executeForm(*f2);
        boss.executeForm(*f3);
        std::cout << std::endl;

        std::cout << "==== Execution by boss on all ====" << std::endl;

        boss.executeForm(*f1);
        boss.executeForm(*f2);
        boss.executeForm(*f3);
        std::cout << std::endl;

        delete f1;
        delete f2;
        delete f3;

        std::cout << "==== Unknown form test (should throw) ====" << std::endl;

        AForm* f4 = someIntern.makeForm("invalid form name", "test");
        boss.executeForm(*f4);

        delete f4;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}