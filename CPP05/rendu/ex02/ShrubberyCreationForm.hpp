/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:18:31 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:51:37 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private :
		std::string		_target;

	public :
		/* Canonical Member Functions */
		ShrubberyCreationForm( void );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm( void );
		ShrubberyCreationForm &	operator=( ShrubberyCreationForm const & rhs );

		/* Additional Constructor */
		ShrubberyCreationForm( std::string target );

		/* Getters and Setters */
		void			setTarget( std::string target );
		std::string		getTarget( void ) const;

		/* Member Functions */
		int				execute(Bureaucrat const & executor) const;

		/* Exceptions */

};
