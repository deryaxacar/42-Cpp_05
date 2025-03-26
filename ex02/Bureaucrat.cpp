/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:33:39 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 15:41:06 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name)
{
    setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
    *this = copy;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this == &copy)
        return *this;
    _grade = copy._grade;
    return *this;
}

std::string Bureaucrat::getName(void) const
{
    return this->_name;
}

size_t Bureaucrat::getGrade(void) const
{
    return this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat: Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat: Grade Too Low";
}

void Bureaucrat::increaseGrade(void)
{
    setGrade(getGrade() - 1);
}

void Bureaucrat::decreaseGrade(void)
{
    setGrade(getGrade() + 1);
}

void Bureaucrat::setGrade(int n)
{
    if (n < 1)
        throw GradeTooHighException();
    else if (n > 150)
        throw GradeTooLowException();
    _grade = n;
}

void Bureaucrat::signAForm(AForm &f)
{
    try
    {
        if (f.beSigned(*this))
        {
            std::cout << this->getName() << " signed " << f.getName() << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form) const
{
    try
    {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade();
    return o;
}
