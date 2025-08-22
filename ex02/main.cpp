/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 12:14:37 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/20 12:15:02 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void sep(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n";
}

static void printForm(const Form &f)
{
	std::cout << f << std::endl;
}

int main()
{
	// 0) Sanity check Bureaucrat affichage
	{
		sep("Sanity check Bureaucrat");
		Bureaucrat alice("Alice", 42);
		std::cout << alice << std::endl;
	}

	// 1) Construction de Form valide + getters / operator<<
	try
	{
		sep("Form valide");
		Form f("TopSecret", 42, 10);
		printForm(f);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	// 2) Constructions invalides (grades hors bornes) -> exceptions
	try
	{
		sep("Form invalide (signGrade < 1)");
		Form f("BadSignHigh", 0, 10); // doit throw GradeTooHighException
		printForm(f);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}
	try
	{
		sep("Form invalide (execGrade > 150)");
		Form f("BadExecLow", 10, 151); // doit throw GradeTooLowException
		printForm(f);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// 3) Signature réussie via beSigned()
	try
	{
		sep("Signature reussie via beSigned()");
		Bureaucrat boss("Boss", 1);
		Form contract("Contract", 5, 10);
		printForm(contract);
		contract.beSigned(boss); // OK (1 <= 5)
		printForm(contract);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	// 4) Signature échouée via beSigned() (grade trop bas) -> exception
	try
	{
		sep("Signature echouee via beSigned() (throw)");
		Bureaucrat intern("Intern", 150);
		Form req("Request", 100, 100);
		printForm(req);
		req.beSigned(intern); // doit throw GradeTooLowException
		std::cout << "SHOULD NOT PRINT\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// 5) Utilisation de Bureaucrat::signForm(Form&) (doit imprimer le message)
	{
		sep("Bureaucrat::signForm() success");
		Bureaucrat senior("Senior", 10);
		Form paper("Paper", 42, 42);
		senior.signForm(paper); // doit imprimer: "<bureaucrat> signed <form>"
		printForm(paper);
	}
	{
		sep("Bureaucrat::signForm() failure");
		Bureaucrat junior("Junior", 120);
		Form clearance("Clearance", 50, 50);
		junior.signForm(clearance); // doit imprimer: "<bureaucrat> couldn't sign <form> because <reason>"
		printForm(clearance);
	}

	// 6) Double signature (la 2e ne doit pas changer l'état ; selon implémentation, rien/exception/message)
	{
		sep("Double signature");
		Bureaucrat chief("Chief", 3);
		Form rule("Rule42", 5, 5);
		chief.signForm(rule); // 1ère signature OK
		chief.signForm(rule); // 2e tentative : selon ton choix, message/exception/no-op
		printForm(rule);
	}

	// 7) Limites exactes (grade pile requis)
	{
		sep("Limites exactes (grade == signGrade)");
		Bureaucrat exact("Exact", 75);
		Form f("ExactForm", 75, 75);
		exact.signForm(f); // doit passer
		printForm(f);
	}

	return 0;
}
