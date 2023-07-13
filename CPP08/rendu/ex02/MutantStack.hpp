/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:15:11 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/11 23:08:30 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <stack>
# include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	private :

	public :
		/* Canonical Member Functions */
		MutantStack<T> ( void ) : std::stack<T>()
		{
			std::cout << "\033[1;32mMutantStack Default constructor called\033[0m" << std::endl;
		}
		MutantStack<T> ( MutantStack<T> const & src ) : std::stack<T>( src )
		{
			std::cout << "\033[1;32mMutantStack Copy constructor called\033[0m" << std::endl;
			*this = src;
		}
		virtual ~MutantStack<T>( void )
		{
			std::cout << "\033[1;31mMutantStack Destructor called\033[0m" << std::endl;
		}
		MutantStack<T> &	operator=( MutantStack const & rhs )
		{
			std::cout << "\033[1;33mMutantStack Assignment operator called\033[0m" << std::endl;
			std::stack<T>::operator=( rhs );
			return (*this);
		}

		/* Additional Constructor */

		/* Getters and Setters */

		/* Member Functions */

		/* Iterators */
		typedef typename MutantStack<T>::container_type::iterator iterator;
		iterator	begin( void )
		{
			return (this->c.begin());
		}

		iterator	end( void )
		{
			return (this->c.end());
		}

		typedef typename MutantStack<T>::container_type::const_iterator const_iterator;
		const_iterator	begin( void ) const
		{
			return (this->c.begin());
		}

		const_iterator	end( void ) const
		{
			return (this->c.end());
		}

		/* Exceptions */

};
