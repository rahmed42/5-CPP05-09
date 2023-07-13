/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:36:18 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/22 22:12:21 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

enum	e_message
{
	E_ROBOTOMY,
	E_SHRUBBERY,
	E_PRESIDENTIAL
};

class Intern
{
	public:
		/* Canonical Member Functions */
		Intern( void );
		Intern( Intern const & src );
		~Intern( void );
		Intern & operator=( Intern const & rhs );

		/* Member Functions */
		Form *	makeForm(std::string formName, std::string target);

		/* Exceptions */
		class UnexistingFormException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

};
