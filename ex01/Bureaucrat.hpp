/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:43:29 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 12:44:05 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class Bureaucrat {
    private:
        const std::string _name;
        size_t _grade;
        void setGrade(int n);
    public:
        Bureaucrat(void);
        ~Bureaucrat(void);
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, size_t grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat &operator=(const Bureaucrat& copy);

        std::string getName(void) const;
        size_t getGrade(void) const;

        void increaseGrade(void);
        void decreaseGrade(void);
        void signForm(Form& f);

        class GradeTooHighException: public std::exception {
            const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream& o, const Bureaucrat& b);