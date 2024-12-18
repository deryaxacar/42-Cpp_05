/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:45:41 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 15:45:49 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    {
        try {
        Bureaucrat a("\033[0;36mWall-e\033[m", 25);
        Bureaucrat b("\033[0;44mSally\033[m", 1);
        AForm* rqf = new RobotomyRequestForm("\033[0;37mROBOT\033[m");
        PresidentialPardonForm ppf("\033[0;41mMcQueen\033[m");
        
        a.signAForm(*rqf);
        a.signAForm(ppf);
        a.executeForm(*rqf);
        a.executeForm(ppf);
        b.executeForm(ppf);
        
        delete rqf;
        }
        catch (std::exception &e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }
    }
    {
        Bureaucrat a("\033[0;35mTow Mater\033[m");
        ShrubberyCreationForm scf("shrub");
        a.executeForm(scf);
        a.signAForm(scf);
        for (size_t i = 0; i < 10; ++i) {
            a.increaseGrade();
        }
        a.signAForm(scf);
        a.executeForm(scf);
        for (size_t i = 0; i < 10; ++i) {
            a.increaseGrade();
        }
        a.executeForm(scf);
    }
}
