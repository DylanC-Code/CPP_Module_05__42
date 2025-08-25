/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:27:03 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/20 12:16:36 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _requiredSignItGrade;
	const int _requiredExecuteItGrade;

public:
	// Canonical AForm
	AForm(const AForm &src);
	AForm &operator=(const AForm &src);
	virtual ~AForm();

	// Custom Constructor
	AForm(const std::string &name, int requiredSignItGrade, int requiredExecuteItGrade);

	// Getters
	const std::string &getName() const;
	bool getIsSigned() const;
	int getRequiredSignItGrade() const;
	int getRequiredExecuteItGrade() const;

	void beSigned(const Bureaucrat &b);

	virtual void execute(Bureaucrat const &executor) const = 0;

	// Internal Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &src);

#endif
