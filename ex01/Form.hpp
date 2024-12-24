/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:44:57 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 13:07:07 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _isSigned;
        const size_t _signGrade;
        const size_t _executeGrade;
    public:
        Form(void);
        ~Form(void);
        Form(std::string name);
        Form(std::string name,int signGrade, int executeGrade);
        Form(const Form& copy);
        Form &operator=(const Form& copy);

        std::string getName(void) const;
        size_t getSignGrade(void) const;
        size_t getExecuteGrade(void) const;
        std::string getIsSigned(void) const;

        void beSigned(Bureaucrat& b); 
        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, Form& f);