/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:15:11 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/10 15:52:26 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <algorithm>
# include <vector>
# include <iostream>
# include <cstdlib>

class Span
{
	private :
		unsigned int _n;
		std::vector<int> _vec;

	public :
		/* Canonical Member Functions */
		Span( void );
		Span( Span const & src );
		~Span( void );
		Span &	operator=( Span const & rhs );

		/* Additional Constructor */
		Span ( unsigned int N );

		/* Getters and Setters */
		unsigned int			getN( void ) const;
		std::vector<int>		getVec( void ) const;

		/* Member Functions */
		void	addNumber( int number );
		void	addRandomNumbers( unsigned int size );
		void	fillSpanRandom( void );
		int		shortestSpan( void );
		int		longestSpan( void );

		/* Exceptions */
		class FullSpanException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public :
				virtual const char * what() const throw();
		};
};
