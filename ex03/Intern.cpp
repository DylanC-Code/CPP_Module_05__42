/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:44:09 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/25 10:23:12 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* *** Canonical Form *** */

Intern::Intern(const Intern &src)
{
	(*this) = src;
}

Intern &Intern::operator=(const Intern &src)
{
	(void)src;
	return (*this);
}

Intern::~Intern() {};

/* *** Custom Constructor *** */

Intern::Intern() {};

/* *** Specific Member Functions *** */

typedef AForm *(*FormCreator)(const std::string &target);

static AForm *createShrubbery(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *createRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *createPresidential(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	const std::string formsName[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	const FormCreator creators[3] = {&createShrubbery, &createRobotomy, &createPresidential};

	for (size_t i = 0; i < 3; i++)
	{
		if (formsName[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}

	std::cout << "Intern couldn't create form \"" << formName << "\" (unknown)" << std::endl;
	return 0;
}
