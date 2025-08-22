/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:49:33 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/20 12:26:50 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* *** Canonical Form *** */

Form::Form(const Form &src) : _name(src.getName()),
							  _requiredSignItGrade(src.getRequiredSignItGrade()),
							  _requiredExecuteItGrade(src.getRequiredExecuteItGrade())
{
	(*this) = src;
}

Form &Form::operator=(const Form &src)
{

	if (this != &src)
		this->_isSigned = src.getIsSigned();
	return (*this);
}

Form::~Form() {}

/* *** Custom Constructor *** */

Form::Form(const std::string &name,
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

const std::string &Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getRequiredSignItGrade() const
{
	return _requiredSignItGrade;
}

int Form::getRequiredExecuteItGrade() const
{
	return _requiredExecuteItGrade;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > this->_requiredSignItGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &src)
{
	os << "Form: " << src.getName()
	   << ", Signed: " << (src.getIsSigned() ? "Yes" : "No")
	   << ", Required Sign Grade: " << src.getRequiredSignItGrade()
	   << ", Required Execute Grade: " << src.getRequiredExecuteItGrade();
	return os;
}

/* *** Internal Exceptions *** */

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high!\n";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low!\n";
}
