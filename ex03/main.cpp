/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:08:13 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/25 10:23:12 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main()
{
	Intern intern;
	AForm *f1 = 0;
	AForm *f2 = 0;
	AForm *f3 = 0;

	f1 = intern.makeForm("shrubbery creation", "home");
	f2 = intern.makeForm("robotomy request", "Bender");
	f3 = intern.makeForm("coffee request", "Kitchen"); // inconnu

	if (f1)
		delete f1;
	if (f2)
		delete f2;
	if (f3)
		delete f3;
}
