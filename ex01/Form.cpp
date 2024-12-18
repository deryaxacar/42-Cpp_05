/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:44:54 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 13:12:55 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::~Form(void) {}

Form::Form(std::string name): _name(name), _isSigned(false), _signGrade(150), _executeGrade(150) {}

Form::Form(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade){
    if (executeGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy) : _name(copy.getName()), _signGrade(getSignGrade()), _executeGrade(getExecuteGrade()) {
    *this = copy;
}

Form &Form::operator=(const Form& copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

std::string Form::getName(void) const {
    return _name;
}

size_t Form::getSignGrade(void) const {
    return _signGrade;
}

size_t Form::getExecuteGrade(void) const {
    return _executeGrade;
}

std::string Form::getIsSigned(void) const {
    if (_isSigned == false)
        return "\033[0;31mfalse\033[m";
    return "\033[0;32mtrue\033[m";
}

void Form::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->getSignGrade())
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Form: Grade Too High";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form: Grade Too Low";
}

std::ostream &operator<<(std::ostream& o, Form& f) { 
    o << f.getName() << ", requried grade to sign " << f.getSignGrade()
    << ", required grade to execute " <<f.getExecuteGrade() << ", is signed " <<  f.getIsSigned() << std::endl;
    return o;
}
