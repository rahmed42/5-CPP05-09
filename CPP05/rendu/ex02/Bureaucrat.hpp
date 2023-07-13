/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:05 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:12:17 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private :
		const std::string		_name;
		int						_grade;

	public :
		/* Canonical Member Functions */
		Bureaucrat( void );
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat( void );
		Bureaucrat &	operator=( Bureaucrat const & rhs );

		/* Additional Constructor */
		Bureaucrat( std::string const & name, int grade );

		/* Getters and Setters */
		std::string		getName(void) const;
		int				getGrade(void) const;

		/* Member Functions */
		void			incrementGrade( void );
		void			decrementGrade( void );
		void			signForm( AForm & f );
		void			executeForm( AForm const & form );

		/* Exceptions */
		class GradeTooLowException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

/* Operator functions */
std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs );
