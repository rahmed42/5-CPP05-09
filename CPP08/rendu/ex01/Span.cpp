/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 22:07:20 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/10 15:52:18 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span( void ) : _n(0), _vec(0)
{
	std::cout << "\033[1;32mSpan Default constructor called\033[0m" << std::endl;
}

Span::Span( Span const & src )
{
	std::cout << "\033[1;35mSpan Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Span::~Span( void )
{
	std::cout << "\033[1;31mSpan Destructor called\033[0m" << std::endl;
}

Span &	Span::operator=( Span const & rhs )
{
	std::cout << "\033[1;34mSpan Assignment operator called\033[0m" << std::endl;
	this->_n = rhs._n;
	this->_vec = rhs._vec;
	return (*this);
}

Span::Span( unsigned int N ) : _n(N)
{
	std::cout << "\033[1;32mSpan Constructor with parameter called\033[0m" << std::endl;
	this->_vec.reserve(this->_n);
}

unsigned int	Span::getN( void ) const
{
	return (this->_n);
}
std::vector<int>	Span::getVec( void ) const
{
	return (this->_vec);
}

void	Span::addNumber( int number )
{
	if (this->_vec.size() >= this->_n)
		throw FullSpanException();
	this->_vec.push_back(number);
}

void	Span::addRandomNumbers( unsigned int size )
{
	srand(static_cast<unsigned int>(time(NULL)));

	try	{
		for (unsigned int i = 0; i < size; i++)
			addNumber(rand());
	}
	catch (Span::FullSpanException & e)	{
		std::cout << e.what() << std::endl;	}
}

void	Span::fillSpanRandom( void )
{
	this->_vec = std::vector<int>(this->getN());

	std::vector<int>::iterator	it = this->_vec.begin();
	std::vector<int>::iterator	ite = this->_vec.end();

	std::cout << std::endl << "\033[1;35mFill Span size \033[0m" << this->getN() << " \033[1;35mwith Random numbers...\033[0m" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	std::generate(it, ite, std::rand);
}

int	Span::shortestSpan( void )
{
	if (this->_vec.size() < 2)
		throw NotEnoughNumbersException();

	int diff = longestSpan();
	std::sort(this->_vec.begin(), this->_vec.end());

	std::vector<int>::const_iterator	it = this->_vec.begin();
	std::vector<int>::const_iterator	ite = this->_vec.end();

	while (it != ite)
	{
		if (std::count(it, ite, *it) >= 2)
			return (0);
		if (std::abs(*(it + 1) - *it) < diff)
			diff = std::abs(*(it + 1) - *it);
		it++;
	}
	return (diff);
}

int	Span::longestSpan( void )
{
	if (this->_vec.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int>::const_iterator	it = this->_vec.begin();
	std::vector<int>::const_iterator	ite = this->_vec.end();

	return (*std::max_element(it, ite) - *std::min_element(it , ite));
}

const char* Span::FullSpanException::what() const throw()
{
		return ("\033[1;31m-- Error -- Can't add more numbers ! the Span is FULL\033[0m");
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
		return ("\033[1;31m-- Error -- You have to set at least 2 Numbers\033[0m");
}
