/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:03 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/18 19:07:55 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( void ) : _name("Default"), _grade(150)
{
	std::cout << "\033[1;32mBureaucrat Default constructor called\033[0m" << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const & src )
{
	std::cout << "\033[1;35mBureaucrat Copy constructor called\033[0m" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "\033[1;31mBureaucrat Destructor called\033[0m" << std::endl;
}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "\033[1;34mBureaucrat Assignment operator called\033[0m" << std::endl;
	this->_grade = rhs._grade;
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

std::ostream &	operator<<( std::ostream & o, Bureaucrat const & rhs )
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return (o);
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name)
{
	std::cout << "\033[1;32mBureaucrat " << this->_name << " Constructor called\033[0m" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}

void	Bureaucrat::incrementGrade( void )
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void	Bureaucrat::signForm( Form & f )
{
	try
	{
		if (not f.getSigned())
		{
			f.beSigned(*this);
			if (f.getSigned())
				std::cout << "\033[1;32m" << this->_name << " signed " << f.getName() << "\033[0m" << std::endl;
		}
		else
			std::cout << "\033[1;35m" << this->_name << " cannot sign " << f.getName() << " because it is already signed\033[0m" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "\033[1;31m" << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << "\033[0m" << std::endl;
	}
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\033[1;33mGrade too low\033[0m");
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\033[1;33mGrade too high\033[0m");
}
