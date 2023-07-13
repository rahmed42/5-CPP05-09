/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:36:20 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/22 22:54:17 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << "\033[1;32mIntern Default constructor called\033[0m" << std::endl;
}

Intern::Intern( Intern const & src )
{
	std::cout << "\033[1;35mIntern Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Intern::~Intern( void )
{
	std::cout << "\033[1;31mIntern Destructor called\033[0m" << std::endl;
}

Intern & Intern::operator=( Intern const & rhs )
{
	std::cout << "\033[1;34mIntern Assignment operator called\033[0m" << std::endl;
	( void ) rhs;
	return (*this);
}

Form *	Intern::makeForm(std::string formName, std::string target)
{
	int i(0);
	std::string formModel[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};

	while (i < 3)
	{
		if (formName == formModel[i])
			break ;
		i++;
	}
	switch (i)
	{
		case E_ROBOTOMY :
			return (new RobotomyRequestForm( target ));
		case E_SHRUBBERY :
			return (new ShrubberyCreationForm( target ));
		case E_PRESIDENTIAL :
			return (new PresidentialPardonForm( target ));
		default:
			throw UnexistingFormException();
	}
}

const char* Intern::UnexistingFormException::what() const throw()
{
	return ("\033[1;31mUnexisting FORM !!!\033[0m");
}
