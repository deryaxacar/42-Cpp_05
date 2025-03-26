/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:37:44 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 15:25:31 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <exception>
#include <iostream>

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    size_t _grade;

public:
    Bureaucrat(void);
    ~Bureaucrat(void);
    Bureaucrat(std::string name);
    Bureaucrat(std::string name, size_t grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &copy);

    std::string getName(void) const;
    size_t getGrade(void) const;
    void setGrade(int n);

    void increaseGrade(void);
    void decreaseGrade(void);

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    void signAForm(AForm &f);
    void executeForm(AForm const &form) const;
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);