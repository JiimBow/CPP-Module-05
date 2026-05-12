/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:51 by jodone            #+#    #+#             */
/*   Updated: 2026/05/12 18:23:12 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main()
{
    std::srand(std::time(0));
    std::cout << "====SHRUBBERY TEST====" << std::endl;

    try
    {
        std::cout << "==== Creation Bureaucrats ====" << std::endl;
        Bureaucrat boss("Boss", 1);
        Bureaucrat manager("Manager", 50);
        Bureaucrat larbin("Larbin", 140);

        std::cout << boss << std::endl;
        std::cout << manager << std::endl;
        std::cout << larbin << std::endl;
        std::cout << std::endl;

        std::cout << "==== Creation Forms ====" << std::endl;
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Cyborg");
        PresidentialPardonForm pres("Trump");

        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pres << std::endl;
        std::cout << std::endl;

        std::cout << "==== Sign Forms ====" << std::endl;
        larbin.signForm(shrub);
        manager.signForm(robot);
        boss.signForm(pres);
        std::cout << std::endl;

        std::cout << "==== Larbin execution ====" << std::endl;
        larbin.executeForm(shrub);
        larbin.executeForm(robot);
        larbin.executeForm(pres);
        std::cout << std::endl;

        std::cout << "==== Manager execution ====" << std::endl;
        manager.executeForm(shrub);
        manager.executeForm(robot);
        manager.executeForm(pres);
        std::cout << std::endl;

        std::cout << "==== Boss execution ====" << std::endl;
        boss.executeForm(shrub);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(pres);
        std::cout << std::endl;

        std::cout << "==== Not Signed Form execution ====" << std::endl;
        PresidentialPardonForm notSigned("NotSigned");
        boss.executeForm(notSigned);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}
