/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:18:31 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:51:33 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private :
		std::string		_target;

	public :
		/* Canonical Member Functions */
		PresidentialPardonForm( void );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm( void );
		PresidentialPardonForm &	operator=( PresidentialPardonForm const & rhs );

		/* Additional Constructor */
		PresidentialPardonForm( std::string target );

		/* Getters and Setters */
		void			setTarget( std::string target );
		std::string		getTarget( void ) const;

		/* Member Functions */
		int				execute(Bureaucrat const & executor) const;

		/* Exceptions */

};
