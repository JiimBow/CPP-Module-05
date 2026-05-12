/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimbow <jimbow@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 10:28:51 by jodone            #+#    #+#             */
/*   Updated: 2026/05/12 17:07:43 by jimbow           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

int main()
{
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

    return 0;
}
