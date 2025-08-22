/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:05:01 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 11:15:16 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137) {};

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getRequiredExecuteItGrade())
		throw AForm::GradeTooLowException();
	std::string fileName = this->getName() + "_shrubbery";
	std::ofstream outFile(fileName.c_str());
	if (!outFile)
	{
		std::cout << "Error creating file: " << fileName << std::endl;
		return;
	}
	outFile << "       _-_\n"
			   "    /~~   ~~\\\n"
			   " /~~         ~~\\\n"
			   "{               }\n"
			   " \\  _-     -_  /\n"
			   "   ~  \\\\ //  ~\n"
			   "_- -   | | _- _\n"
			   "  _ -  | |   -_\n"
			   "      // \\\\\n";
	outFile.close();
}
