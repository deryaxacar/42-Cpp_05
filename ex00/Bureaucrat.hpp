/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:57:59 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 11:58:00 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <cwctype>

class Bureaucrat{
    private:
        const std::string _name;
        size_t _grade;

    public:

        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, size_t grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& copy);

        std::string getName(void) const;
        size_t getGrade(void) const;
        void setGrade(int n);

        void increaseGrade(void);
        void decreaseGrade(void);

        class GradeTooHighException: public std::exception{
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception{
            const char* what() const throw();
        };

};

std::ostream &operator<<(std::ostream& o, const Bureaucrat& b);