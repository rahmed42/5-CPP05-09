/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:03 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:28:32 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "\033[1;32mPresidentialPardonForm Default constructor called\033[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
{
	std::cout << "\033[1;35mPresidentialPardonForm Copy constructor called\033[0m" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm( void )
{
	std::cout << "\033[1;31mPresidentialPardonForm Destructor called\033[0m" << std::endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	std::cout << "\033[1;34mPresidentialPardonForm Assignment operator called\033[0m" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\033[1;33mPresidentialPardonForm with target = " << target << " called\033[0m" << std::endl;
}

void	PresidentialPardonForm::setTarget( std::string target )
{
	this->_target = target;
}

std::string	PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

int	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			std::cout << "\033[1;36mPresidentialPardonForm : " << this->_target << " was forgiven by Zaphod Beeblebrox !\033[0m" << std::endl;
			return (0);
		}
		else
			throw PresidentialPardonForm::GradeTooLowException();
	}
	else
		throw PresidentialPardonForm::NotSignedException();
	return (1);
}
