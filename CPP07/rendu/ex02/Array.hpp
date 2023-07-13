/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:56:27 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/05 19:26:00 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <iostream>

template <typename T>
class Array
{
	private :
		T		*_tab;
		int		_size;

	public :
		/* Canonical Member Functions */
		Array<T> ( void ) : _tab(NULL), _size(0)
		{
			std::cout << "\033[1;32mArray Default constructor called\033[0m" << std::endl;
		}
		Array<T> (Array<T> const & src)
		{
			std::cout << "\033[1;32mArray Copy constructor called\033[0m" << std::endl;
			*this = src;
		}
		~Array<T> ( void )
		{
			std::cout << "\033[1;31mArray Destructor called\033[0m" << std::endl;
		}
		Array<T> & operator=(Array const & rhs)
		{
			std::cout << "\033[1;33mArray Assignment operator called\033[0m" << std::endl;
			this->_tab = rhs._tab;
			this->_size = rhs._size;
			return (*this);
		}

		/* Additional Constructor */
		Array<T> ( unsigned int n ) : _tab(new T[n]), _size(n)
		{
			std::cout << "\033[1;32mArray -unsigned int- Constructor called\033[0m" << std::endl;
		}

		/* Operator functions */
		T & operator[](int i)
		{
			std::cout << "\033[1;34mArray Access operator called\033[0m" << std::endl;
			if (i < 0 || i >= this->_size)
				throw OutOfBoundsException();
			return (this->_tab[i]);
		}

		/* Getters and Setters */
		T *			tab( void ) const	{ return (this->_tab); }
		int			size( void ) const	{ return (this->_size); }

		/* Exceptions */
		class OutOfBoundsException : public std::exception
		{
			public :
				virtual const char* what() const throw()
				{
					return ("\033[1;35mArray::OutOfBoundsException\033[0m");
				}
		};
};
