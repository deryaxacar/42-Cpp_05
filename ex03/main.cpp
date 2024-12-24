/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:01:02 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 16:58:46 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    try {

    Bureaucrat a("V", 44);
    a.signAForm(*rrf);
    a.executeForm(*rrf);
    delete rrf;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    AForm* zpf;
    try {
        zpf = someRandomIntern.makeForm("NOT FOUND FORM", "nothing");
        delete zpf;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}