/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:19:47 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/20 11:24:27 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

static void sep(const std::string &title)
{
	std::cout << "\n==== " << title << " ====\n";
}

int main()
{
	// 1) Construction valide + affichage + chaînage <<
	try
	{
		sep("Construction valide + operator<<");
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
		std::cout << "Chaining: " << a << " | OK\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	// 2) Construction invalide (trop haut)
	try
	{
		sep("Construction invalide (grade < 1)");
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl; // ne doit pas s'afficher
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// 3) Construction invalide (trop bas)
	try
	{
		sep("Construction invalide (grade > 150)");
		Bureaucrat c("Charlie", 151);
		std::cout << c << std::endl; // ne doit pas s'afficher
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// 4) Limite haute : increment jusqu’à 1 puis un de trop
	try
	{
		sep("Limite haute (increment)");
		Bureaucrat h("High", 2);
		std::cout << h << std::endl;
		h.incrementGrade(); // 2 -> 1
		std::cout << "After increment: " << h << std::endl;
		h.incrementGrade(); // doit lancer GradeTooHighException
		std::cout << "SHOULD NOT PRINT\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// 5) Limite basse : decrement jusqu’à 150 puis un de trop
	try
	{
		sep("Limite basse (decrement)");
		Bureaucrat l("Low", 149);
		std::cout << l << std::endl;
		l.decrementGrade(); // 149 -> 150
		std::cout << "After decrement: " << l << std::endl;
		l.decrementGrade(); // doit lancer GradeTooLowException
		std::cout << "SHOULD NOT PRINT\n";
	}
	catch (const std::exception &e)
	{
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	// 6) Robustesse : plusieurs increments/decrements normaux
	try
	{
		sep("Increments/Decrements normaux");
		Bureaucrat m("Mary", 100);
		std::cout << m << std::endl;
		m.incrementGrade(); // 99
		m.incrementGrade(); // 98
		m.decrementGrade(); // 99
		std::cout << "After ops: " << m << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
