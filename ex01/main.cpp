/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:02:12 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 13:15:16 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[0;34m*-----------------------------------------------------*\033[m" << std::endl;
    {
        Bureaucrat b("Donkey");
        try {
            Form a("Invalid Form", 1, 200);
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << "\033[0;34m*-----------------------------------------------------*\033[m" << std::endl;
    {
        try {
            Bureaucrat a("Mary Jane", 20);
            Form f("Document Form", 20, 10);

            std::cout << f;
            a.signForm(f);
            std::cout << f;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << "\033[0;34m*-----------------------------------------------------*\033[m" << std::endl;
    {
        try {
            Bureaucrat b("Peter Parker", 50);
            Form f("Application Form", 40, 20);
            
            std::cout << f;
            
            b.signForm(f);
            
            std::cout << f;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    std::cout << "\033[0;34m*-----------------------------------------------------*\033[m" << std::endl;
}
