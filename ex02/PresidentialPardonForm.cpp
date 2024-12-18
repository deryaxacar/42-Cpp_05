/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:44:10 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:14 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm::AForm("presidential pardon", 25, 5), _target("Default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("presidential pardon", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm::AForm("presidential pardon", 25, 5) {
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this != &copy)
        _target = copy._target;
    return *this; 
}

void PresidentialPardonForm::specificExecute(void) const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}