/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:58:04 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/27 23:13:23 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

/* Canonical Member Functions */
Data::Data( void )
{
	std::cout << "\033[1;32mData Default constructor called\033[0m" << std::endl;
}

Data::Data( Data const & src )
{
	std::cout << "\033[1;35mData Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Data::~Data( void )
{
	std::cout << "\033[1;31mData Destructor called\033[0m" << std::endl;
}

Data &	Data::operator=( Data const & rhs )
{
	std::cout << "\033[1;34mData Assignment operator called\033[0m" << std::endl;
	this->_data = rhs._data;
	return (*this);
}

/* Additional Constructor */
Data::Data ( int d ) : _data(d)
{
	std::cout << "\033[1;32mData Constructor called\033[0m" << std::endl;
}

/* Getters and Setters */
int	Data::getData( void ) const
{
	return ( this->_data );
}

void	Data::setData( int d )
{
	this->_data = d;
}
