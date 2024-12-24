/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:57:47 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 16:07:02 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "\033[0;31m-------------------------"<< std::endl;
    std::cout << "Decrease Grade\033[m\n"<< std::endl;

    Bureaucrat b("John");
    std::cout << b << std::endl;

    try { 
        b.decreaseGrade();
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << b << std::endl;
    
    std::cout << "\033[0;31m-------------------------"<< std::endl;
    std::cout << "Increase Grade\033[m\n"<< std::endl;

	Bureaucrat a("Taylor", 5); 
	std::cout << a << std::endl;

	try { 
        for (size_t i = 0; i < 5; ++i) {
            a.increaseGrade();
        }
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
	std::cout << a << std::endl;
	return(0);
}