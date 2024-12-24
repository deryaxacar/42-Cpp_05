/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:57:53 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 15:59:12 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern &copy){
    *this = copy;
}

Intern &Intern::operator=(const Intern &copy){
    (void)copy;
    return (*this);
}

AForm *Intern::makeForm(std::string name, std::string target){
    std::string formNames[] = {
        "robotomy request", "presidential pardon", "shrubbery creation"
    };

    int i = 0;
    for (i = 0; i < 3; i++){
        if (name == formNames[i])
            break;
    }
        switch(i)
        {
            case 0:
                std::cout << "Intern creates " << name << std::endl;
                return (new RobotomyRequestForm(target));
            case 1:
                std::cout << "Intern creates " << name << std::endl;
                return (new PresidentialPardonForm(target));
            case 2:
                std::cout << "Intern creates " << name << std::endl;
                return (new ShrubberyCreationForm(target));
        }
        std::cout << "Intern cannot create " << name << " form" << std::endl;
        return NULL;
}