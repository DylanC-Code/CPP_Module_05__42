/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 09:56:36 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/20 11:18:48 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
private:
	const std::string _name;
	int _grade;

public:
	// Canonical Form
	Bureaucrat(Bureaucrat const &src);
	~Bureaucrat();
	Bureaucrat &operator=(Bureaucrat const &src);

	// Custom Constructor
	Bureaucrat(const std::string &name, int grade);

	// Getters
	const std::string &getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	// Internal Exceptions
	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
