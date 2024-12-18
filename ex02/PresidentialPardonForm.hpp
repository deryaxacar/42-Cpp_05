/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:44:45 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 15:44:49 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& copy);
        ~PresidentialPardonForm(void);
        PresidentialPardonForm &operator=(const PresidentialPardonForm& copy);
        void specificExecute(void) const;
};