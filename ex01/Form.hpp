/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:27:03 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/20 11:42:15 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _requiredSignItGrade;
	const int _requiredExecuteItGrade;

	// Internal Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};

public:
	// Canonical Form
	Form(const Form &src);
	Form &operator=(const Form &src);
	~Form();

	// Custom Constructor
	Form(const std::string &name, int requiredSignItGrade, int requiredExecuteItGrade);

	// Getters
	const std::string &getName() const;
	bool getIsSigned() const;
	int getRequiredSignItGrade() const;
	int getRequiredExecuteItGrade() const;

	void beSigned(const Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &os, const Form &src);

#endif
