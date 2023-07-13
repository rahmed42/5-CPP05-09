/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:03 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/18 17:41:25 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "AForm.hpp"

AForm::AForm( void ) : _name(""), _signGrade(1), _execGrade(1)
{
	std::cout << "\033[1;32mAForm Default constructor called\033[0m" << std::endl;
	this->_signed = false;
}

AForm::AForm( AForm const & src ) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	std::cout << "\033[1;35mAForm Copy constructor called\033[0m" << std::endl;
	this->_signed = src._signed;
	*this = src;
}

AForm::~AForm( void )
{
	std::cout << "\033[1;31mAForm Destructor called\033[0m" << std::endl;
}

AForm & AForm::operator=( AForm const & rhs )
{
	std::cout << "\033[1;34mAForm Assignment operator called\033[0m" << std::endl;
	this->_signed = rhs._signed;
	return (*this);
}

AForm::AForm( std::string name, int signGrade, int execGrade ) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	std::cout << "\033[1;32mAForm " << this->_name << " Constructor called\033[0m" << std::endl;
	if ((signGrade < 1) or (execGrade < 1))
		throw AForm::GradeTooHighException();
	if ((signGrade > 150) or (execGrade > 150))
		throw AForm::GradeTooLowException();
	this->_signed = false;
}

std::string	AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int	AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

std::ostream &	operator<<( std::ostream & o, AForm const & rhs )
{
	o << "AForm Name : " << rhs.getName() << std::endl;
	if (rhs.getSigned())
		o << "\033[1;36mAForm is signed\033[0m" << std::endl;
	else
		o << "\033[1;33mAForm is not signed\033[0m" << std::endl;
	o << "Sign Grade : " << rhs.getSignGrade() << std::endl;
	o << "Exec Grade : " << rhs.getExecGrade() << std::endl;
	return (o);
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("\033[1;33mGrade too low\033[0m");
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("\033[1;33mGrade too high\033[0m");
}

const char*	AForm::NotSignedException::what() const throw()
{
	return ("\033[1;31mForm Not Signed !\033[0m");
}