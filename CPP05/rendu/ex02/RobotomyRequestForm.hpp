/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 19:18:31 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:51:27 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private :
		std::string		_target;

	public :
		/* Canonical Member Functions */
		RobotomyRequestForm( void );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm( void );
		RobotomyRequestForm &	operator=( RobotomyRequestForm const & rhs );

		/* Additional Constructor */
		RobotomyRequestForm( std::string target );

		/* Getters and Setters */
		void			setTarget( std::string target );
		std::string		getTarget( void ) const;

		/* Member Functions */
		int				execute(Bureaucrat const & executor) const;

		/* Exceptions */

};
