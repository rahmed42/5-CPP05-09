/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:54:19 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/30 21:36:48 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include <typeinfo>
# include <climits>
# include <cfloat>
# include <cctype>
# include <string>
# include <iomanip>
# include <cstdlib>

class Convert
{
	private :
		std::string _str;

	public :
		/* Canonical Member Functions */
		Convert( void );
		Convert( Convert const & src );
		virtual ~Convert( void );
		Convert &	operator=( Convert const & rhs );

		/* Additional Constructor */
		Convert ( std::string str );

		/* Getters and Setters */
		std::string		getStr( void ) const;
		void			setStr( std::string );

		/* Member Functions */
		bool			isNumeric( std::string str ) const;
		bool			isDisplayable( std::string str ) const;
		char			toChar( std::string str ) const;
		int				toInt( std::string str ) const;
		float			toFloat( std::string str ) const;
		double			toDouble( std::string str ) const;

		/* Exceptions */
		class NotANumberException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class NotDisplayableException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class OverflowException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};
};

std::ostream &	operator<<( std::ostream & o, Convert const & c );
