/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:03 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/18 17:41:25 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Form.hpp"

Form::Form( void ) : _name(""), _signGrade(1), _execGrade(1)
{
	std::cout << "\033[1;32mForm Default constructor called\033[0m" << std::endl;
	this->_signed = false;
}

Form::Form( Form const & src ) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "\033[1;35mForm Copy constructor called\033[0m" << std::endl;
	this->_signed = src._signed;
	*this = src;
}

Form::~Form( void )
{
	std::cout << "\033[1;31mForm Destructor called\033[0m" << std::endl;
}

Form & Form::operator=( Form const & rhs )
{
	std::cout << "\033[1;34mForm Assignment operator called\033[0m" << std::endl;
	this->_signed = rhs._signed;
	return (*this);
}

Form::Form( std::string name, int signGrade, int execGrade ) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "\033[1;32mForm " << this->_name << " Constructor called\033[0m" << std::endl;
	if ((signGrade < 1) or (execGrade < 1))
		throw Form::GradeTooHighException();
	if ((signGrade > 150) or (execGrade > 150))
		throw Form::GradeTooLowException();
	this->_signed = false;
}

std::string	Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

std::ostream &	operator<<( std::ostream & o, Form const & rhs )
{
	o << "Form Name : " << rhs.getName() << std::endl;
	if (rhs.getSigned())
		o << "Form is signed" << std::endl;
	else
		o << "Form is not signed" << std::endl;
	o << "Sign Grade : " << rhs.getSignGrade() << std::endl;
	o << "Exec Grade : " << rhs.getExecGrade() << std::endl;
	return (o);
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("\033[1;33mGrade too low\033[0m");
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("\033[1;33mGrade too high\033[0m");
}
