/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:54:22 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/12 15:27:18 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "convert.hpp"

Convert::Convert( void )
{
	std::cout << "\033[1;32mConvert Default constructor called\033[0m" << std::endl;
}

Convert::Convert( Convert const & src )
{
	std::cout << "\033[1;35mConvert Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Convert::~Convert( void )
{
	std::cout << "\033[1;31mConvert Destructor called\033[0m" << std::endl;
}

Convert &	Convert::operator=( Convert const & rhs )
{
	std::cout << "\033[1;34mConvert Assignment operator called\033[0m" << std::endl;
	this->_str = rhs._str;
	return (*this);
}

Convert::Convert ( std::string str ) : _str(str)
{
	std::cout << "\033[1;32mConvert Constructor called\033[0m" << std::endl;
	if (not isDisplayable(str))
		throw NotDisplayableException();
}


std::string		Convert::getStr( void ) const
{
	return (this->_str);
}

void	Convert::setStr( std::string str )
{
	if (not isDisplayable(str))
		throw NotDisplayableException();
	this->_str = str;
}


bool	Convert::isNumeric( std::string str ) const
{
	bool onedot(false);

	if ( str.empty() )
		return (0);
	for ( unsigned int i(0) ; i < str.size() ; i++ )
	{
		if (str.at(i) == '.')
		{
			if (onedot)
				return (0);
			onedot = true;
		}
		else if (not ((i == 0 and (str.at(i) == '-' || str.at(i) == '+')) \
		|| (str.at(i) >= '0' and str.at(i) <= '9') || str.at(i) <= 'e' \
		|| ((i == str.size() - 1) and str.at(i)  == 'f')))
			return (0);
	}
	return (1);
}

bool	Convert::isDisplayable( std::string str ) const
{
	if ( str.empty() )
		return (0);
	for (unsigned int i(0) ; i < str.size() ; i++)
		if (not isprint(str.at(i)))
			return (0);
	return (1);
}

char	Convert::toChar( std::string str ) const
{
	if (str.size() == 1 and isDisplayable(str) and not isdigit(str.at(0)))
		return (static_cast<char>(str.at(0)));
	if ((str == "-inff" || str == "+inff" || str == "nanf") \
	|| (str == "-inf" || str == "+inf" || str == "nan"))
		throw NotANumberException();
	if (not isprint(atoi(str.c_str())))
		throw NotDisplayableException();
	return (static_cast<char>(atoi(str.c_str())));
}

int	Convert::toInt( std::string str ) const
{
	if (str.size() == 1 and isDisplayable(str) and not isdigit(str.at(0)))
		return (static_cast<int>(str.at(0)));
	if ((str == "-inff" || str == "+inff" || str == "nanf") \
	|| (str == "-inf" || str == "+inf" || str == "nan")
	|| (not isNumeric(str)))
		throw NotANumberException();
	if ( atol(str.c_str() ) > INT_MAX || atol(str.c_str() ) < INT_MIN )
		throw OverflowException();
	return (static_cast<int>(atoi(str.c_str())));
}

float	Convert::toFloat( std::string str ) const
{
	char	*end;

	if (str.size() == 1 and isDisplayable(str) and not isdigit(str.at(0)))
		return (static_cast<float>(str.at(0)));
	if (str == "-inff" || str == "+inff" || str == "nanf" \
	|| str == "-inf" || str == "+inf" || str == "nan")
		return (static_cast<float>(atof(str.c_str())));
	if ( not isNumeric(str) )
		throw NotANumberException();
	strtof(str.c_str(), &end);
	if (((*end != '\0') && (*end != 'f')) || (errno == ERANGE))
		throw OverflowException();
	return (static_cast<float>(strtof(str.c_str(), NULL)));
}

double	Convert::toDouble( std::string str ) const
{
	char	*end;

	if (str.size() == 1 and isDisplayable(str) and not isdigit(str.at(0)))
		return (static_cast<double>(str.at(0)));
	if (str == "-inff" || str == "+inff" || str == "nanf" \
	|| str == "-inf" || str == "+inf" || str == "nan")
		return (static_cast<double>(atof(str.c_str())));
	if (not isNumeric(str))
		throw NotANumberException();
	strtod(str.c_str(), &end);
	if (((*end != '\0') && (*end != 'f')) || (errno == ERANGE))
		throw OverflowException();
	return (static_cast<double>(strtod(str.c_str(), NULL)));
}

const char* Convert::NotANumberException::what() const throw()
{
		return ("\033[1;33mimpossible\033[0m");
}

const char* Convert::NotDisplayableException::what() const throw()
{
	return ("\033[1;33mNot Displayable\033[0m");
}

const char* Convert::OverflowException::what() const throw()
{
	errno = 0;
	return ("\033[1;33mOverflow\033[0m");
}

std::ostream &	operator<<( std::ostream & o, Convert const & c )
{
	try {
			o << "char : " << c.toChar(c.getStr()) << std::endl; }
	catch (std::exception & e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

	try {
			o << "int : " << c.toInt(c.getStr()) << std::endl; }
	catch (std::exception & e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl;}

	try {
			o << "float : "	;
			float f(c.toFloat(c.getStr()));
			o << f << (f - static_cast<int>(f) == 0 ? ".0" : "") << "f" << std::endl; }
	catch (std::exception & e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; }

	try {
			o << "double : ";
			double d(c.toDouble(c.getStr()));
			o << d << (d - static_cast<long long>(d) == 0 ? ".0" : "") << std::endl; }
	catch (std::exception & e) {
		std::cerr << "\033[1;31m" << e.what() << "\033[0m" << std::endl; }

	return o;
}
