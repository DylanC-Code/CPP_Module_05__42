/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:37:48 by dcastor           #+#    #+#             */
/*   Updated: 2025/08/25 09:42:13 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
public:
	// Canonical Form
	Intern(const Intern &src);
	~Intern();
	Intern &operator=(const Intern &src);

	// Custom Constructor
	Intern();

	AForm *makeForm(const std::string &formName, const std::string &target) const;
};

#endif
