/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:33:41 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 15:50:54 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        bool _isSigned;
        const size_t _signGrade;
        const size_t _executeGrade;
    public:
        AForm(void);
        virtual ~AForm(void);
        AForm(std::string name);
        AForm(std::string name, int signGrade, int executeGrade);
        AForm(const AForm& copy);
        AForm &operator=(const AForm& copy);

        std::string getName(void) const;
        size_t getSignGrade(void) const;
        size_t getExecuteGrade(void) const;
        std::string getIsSigned(void) const;

        bool beSigned(Bureaucrat& b); 
        void execute(Bureaucrat const & executor) const;
        virtual void specificExecute() const = 0;

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };

        class FromNotSignedException : public std::exception{
           const char* what()const throw();
        };
};

std::ostream &operator<<(std::ostream& o, AForm& f);