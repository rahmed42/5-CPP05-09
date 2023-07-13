/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:05 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:40:07 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_execGrade;

	public :
		/* Canonical Member Functions */
		AForm( void );
		AForm( AForm const & src );
		virtual ~AForm( void );
		AForm &	operator=( AForm const & rhs );

		/* Additional Constructor */
		AForm( std::string name, int signGrade, int execGrade );

		/* Getters and Setters */
		std::string		getName(void) const;
		bool			getSigned(void) const;
		int				getSignGrade(void) const;
		int				getExecGrade(void) const;

		/* Member Functions */
		void			beSigned(Bureaucrat const & b);
		virtual int		execute(Bureaucrat const & executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public :
				virtual const char* what() const throw();
		};
};

/* Operator functions */
std::ostream &	operator<<( std::ostream & o, AForm const & rhs );
