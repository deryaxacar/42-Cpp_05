/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deryacar <deryacar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 14:33:33 by deryacar          #+#    #+#             */
/*   Updated: 2024/12/24 15:51:16 by deryacar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name): _name(name), _isSigned(false), _signGrade(150), _executeGrade(150) {}

AForm::~AForm(void){}

AForm::AForm(const AForm& copy) : _name(copy.getName()), _signGrade(getSignGrade()), _executeGrade(getExecuteGrade()) {
    *this = copy;
}

AForm &AForm::operator=(const AForm& copy) {
    if (this == &copy)
        return *this;
    _isSigned = copy._isSigned;
    return *this;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade){
    if (executeGrade < 1 || signGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150 || signGrade > 150)
        throw GradeTooLowException();
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
        return "\033[0;31mfalse\033[m";
    return "\033[0;32mtrue\033[m";
}

bool AForm::beSigned(Bureaucrat &b) {
    if (b.getGrade() <= this->getSignGrade())
        return (this->_isSigned = 1);
    else
        throw AForm::GradeTooLowException();
}

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

const char* AForm::FromNotSignedException::what()const throw(){
    return "AForm: Form not signed!";
}

void AForm::execute(Bureaucrat const & executor)const{
    if (_isSigned == 0)
        throw FromNotSignedException();
    if (executor.getGrade() >= this->getExecuteGrade())
        throw GradeTooLowException();
    specificExecute();
}