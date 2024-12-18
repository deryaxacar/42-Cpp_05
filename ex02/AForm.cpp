/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:30:56 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/18 15:43:09 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default AForm"),
               _isSigned(false),
               _signGrade(150),
               _executeGrade(150) {}

AForm::~AForm(void) {}

AForm::AForm(std::string name): _name(name), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::AForm(std::string name,
           int signGrade,
           int executeGrade) : 
           _name(name),
           _isSigned(false),
           _signGrade(signGrade),
           _executeGrade(executeGrade) {
    if (executeGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150 || signGrade> 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy.getName()),
                               _signGrade(getSignGrade()),
                               _executeGrade(getExecuteGrade()) {
    *this = copy;
}

AForm &AForm::operator=(const AForm& copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

std::string AForm::getName(void) const {
    return _name;
}

size_t AForm::getSignGrade(void) const {
    return _signGrade;
}

size_t AForm::getExecuteGrade(void) const {
    return _executeGrade;
}

std::string AForm::getIsSigned(void) const {
    if (_isSigned == false)
        return "false";
    return "true";
}

void AForm::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->getSignGrade())
        this->_isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() >= _executeGrade)
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << _name << std::endl;
    specificExecute();
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm: Form not signed!";
};

const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm: Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm: Grade Too Low";
}

std::ostream &operator<<(std::ostream& o, AForm& f) { 
    o << f.getName() << ", requried grade to sign " << f.getSignGrade()
    << ", required grade to execute " <<f.getExecuteGrade() << ", is signed " <<  f.getIsSigned() << std::endl;
    return o;
}
