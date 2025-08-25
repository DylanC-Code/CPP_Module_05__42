/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:49:33 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 11:14:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* *** Canonical AForm *** */

AForm::AForm(const AForm &src) : _name(src.getName()),
								 _requiredSignItGrade(src.getRequiredSignItGrade()),
								 _requiredExecuteItGrade(src.getRequiredExecuteItGrade())
{
	(*this) = src;
}

AForm &AForm::operator=(const AForm &src)
{

	if (this != &src)
		this->_isSigned = src.getIsSigned();
	return (*this);
}

AForm::~AForm() {}

/* *** Custom Constructor *** */

AForm::AForm(const std::string &name,
			 int requiredSignItGrade,
			 int requiredExecuteItGrade) : _name(name),
										   _isSigned(false),
										   _requiredSignItGrade(requiredSignItGrade),
										   _requiredExecuteItGrade(requiredExecuteItGrade)
{
	if (requiredSignItGrade < 1 || requiredExecuteItGrade < 1)
		throw GradeTooHighException();
	else if (requiredSignItGrade > 150 || requiredExecuteItGrade > 150)
		throw GradeTooLowException();
};

/* *** Getters *** */

const std::string &AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getRequiredSignItGrade() const
{
	return _requiredSignItGrade;
}

int AForm::getRequiredExecuteItGrade() const
{
	return _requiredExecuteItGrade;
}

void AForm::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_requiredSignItGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const AForm &src)
{
	os << "AForm: " << src.getName()
	   << ", Signed: " << (src.getIsSigned() ? "Yes" : "No")
	   << ", Required Sign Grade: " << src.getRequiredSignItGrade()
	   << ", Required Execute Grade: " << src.getRequiredExecuteItGrade();
	return os;
}

/* *** Internal Exceptions *** */

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high!\n";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low!\n";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed!\n";
}
