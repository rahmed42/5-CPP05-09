/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:03 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/22 21:21:09 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "\033[1;32mRobotomyRequestForm Default constructor called\033[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
{
	std::cout << "\033[1;35mRobotomyRequestForm Copy constructor called\033[0m" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm( void )
{
	std::cout << "\033[1;31mRobotomyRequestForm Destructor called\033[0m" << std::endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	std::cout << "\033[1;34mRobotomyRequestForm Assignment operator called\033[0m" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "\033[1;33mRobotomyRequestForm with target = " << target << " called\033[0m" << std::endl;
}

void	RobotomyRequestForm::setTarget( std::string target )
{
	this->_target = target;
}

std::string	RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

int	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	unsigned int count(10);

	srand(time(NULL));
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			while (count--)
			{
				if (rand() % 2)
					std::cout << "\033[1;36mRobotomyRequestForm : BzzzzZZzZZZzZzZZZzZz " << this->_target << " was robotomized !\033[0m" << std::endl;
				else
					std::cout << "\033[1;31mRobotomyRequestForm FAILED !\033[0m" << std::endl;
			}
			return (0);
		}
		else
			throw RobotomyRequestForm::GradeTooLowException();
	}
	else
		throw RobotomyRequestForm::NotSignedException();
	return (1);
}
