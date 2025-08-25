/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:30:35 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/22 11:30:36 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void sep(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n";
}

static bool fileExists(const std::string &path)
{
	std::ifstream ifs(path.c_str());
	return ifs.good();
}

int main()
{
	std::srand(std::time(0)); // pour Robotomy 50%

	// Acteurs
	Bureaucrat intern("Intern", 150);
	Bureaucrat worker("Worker", 140);
	Bureaucrat mid("Mid", 70);
	Bureaucrat tech("Tech", 45);
	Bureaucrat signer25("Signer25", 25);
	Bureaucrat exec5("Exec5", 5);
	Bureaucrat chief("Chief", 1);

	// 1) Exécution interdite si NON signé
	try
	{
		sep("Execute non-signe -> doit echouer");
		ShrubberyCreationForm sh("home");
		std::cout << sh << std::endl;
		tech.executeForm(sh); // doit imprimer un message d'erreur (non signe)
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught (should be handled by executeForm msg): " << e.what() << std::endl;
	}

	// 2) Signature échoue (grade de signature trop bas)
	try
	{
		sep("Signature echoue (grade sign trop bas)");
		RobotomyRequestForm rb("Bender");
		std::cout << rb << std::endl;
		worker.signForm(rb); // worker=140, requis=72 -> echec
		std::cout << rb << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected: " << e.what() << std::endl;
	}

	// 3) Signature OK mais exécution échoue (grade exec trop bas)
	try
	{
		sep("Signature OK puis execution echoue (exec trop bas)");
		RobotomyRequestForm rb("Marvin");
		mid.signForm(rb); // mid=70, requis sign=72 -> echec ? (70 <= 72 donc OK)  // rappel: 1 est le plus haut
		// Correction : 1 est meilleur que 2. 70 n'est PAS meilleur que 72. Il est plus bas.
		// Donc mid=70 ne peut PAS signer (grade numerique plus grand -> moins bon). On prend "tech" pour signer.
		// On refait proprement :
	}
	catch (...)
	{
	}

	{
		RobotomyRequestForm rb("Marvin");
		sep("Signature OK puis execution echoue (exec trop bas) - reprise");
		tech.signForm(rb); // tech=45, requis sign=72 -> 45 est plus HAUT que 72 -> OK
		std::cout << rb << std::endl;
		mid.executeForm(rb); // mid=70, requis exec=45 -> trop bas -> echec
		std::cout << rb << std::endl;
	}

	// 4) Shrubbery : chemin heureux (fichier genere)
	try
	{
		sep("Shrubbery happy path (fichier cible)");
		ShrubberyCreationForm sh("garden");
		worker.signForm(sh);  // worker=140, requis sign=145 -> 140 est plus HAUT -> OK
		tech.executeForm(sh); // tech=45, requis exec=137 -> 45 est plus HAUT -> OK
		std::string fname = "garden_shrubbery";
		std::cout << "File \"" << fname << "\" exists? " << (fileExists(fname) ? "yes" : "no") << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected: " << e.what() << std::endl;
	}

	// 5) Robotomy : chemin heureux (plusieurs exécutions pour voir 50%)
	try
	{
		sep("Robotomy happy path (plusieurs runs)");
		RobotomyRequestForm rb("R2D2");
		tech.signForm(rb); // OK (45 <= 72)
		for (int i = 0; i < 5; ++i)
		{
			chief.executeForm(rb); // OK (1 <= 45) ; messages de réussite/échec aléatoires
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected: " << e.what() << std::endl;
	}

	// 6) PresidentialPardon : signature/exec pile aux limites
	try
	{
		sep("PresidentialPardon limites exactes");
		PresidentialPardonForm pp("Arthur Dent");
		signer25.signForm(pp); // requis sign=25 -> 25 est EXACT, donc OK
		exec5.executeForm(pp); // requis exec=5  -> 5 est EXACT, donc OK
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected: " << e.what() << std::endl;
	}

	// 7) Test d'affichage / chaining <<
	try
	{
		sep("Affichages et chaining <<");
		ShrubberyCreationForm sh2("park");
		std::cout << worker << " | " << sh2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected: " << e.what() << std::endl;
	}

	// 8) Non-regression : execute non signe via executeForm (message) + try direct
	try
	{
		sep("Execute non signe (direct .execute()) -> exception");
		PresidentialPardonForm pp2("Ford Prefect");
		// Appel direct pour vérifier que ta classe jette bien si non signé :
		pp2.execute(chief); // doit throw (non signe)
		std::cout << "SHOULD NOT PRINT\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught direct execute(): " << e.what() << std::endl;
	}

	return 0;
}
