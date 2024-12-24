/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:33:56 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 15:13:50 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request", 72, 45), target("Default"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy Request", 72, 45), target(target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm("Robotomy Request", 72, 45){
    *this = copy;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy){
    this->target = copy.target;
    return *this;
}

void RobotomyRequestForm::specificExecute()const{
    srand(time(0));
    bool succes = rand() % 2 == 0;
    std::cout << "*DRILLING NOISES *" << std::endl;
    if (succes)
        std::cout << this->target << " has been robotomized succesfuly" << std::endl;
    else
        std::cout << "ROBOTOMY " << target << " failed" << std::endl; 
}