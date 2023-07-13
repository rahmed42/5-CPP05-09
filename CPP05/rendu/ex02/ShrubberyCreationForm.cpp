/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:26:03 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/21 14:39:18 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) : AForm("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "\033[1;32mShrubberyCreationForm Default constructor called\033[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
{
	std::cout << "\033[1;35mShrubberyCreationForm Copy constructor called\033[0m" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void )
{
	std::cout << "\033[1;31mShrubberyCreationForm Destructor called\033[0m" << std::endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	std::cout << "\033[1;34mShrubberyCreationForm Assignment operator called\033[0m" << std::endl;
	this->_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\033[1;33mShrubberyCreationForm with target = " << target << " called\033[0m" << std::endl;
}

void	ShrubberyCreationForm::setTarget( std::string target )
{
	this->_target = target;
}

std::string	ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

int	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned())
	{
		if (executor.getGrade() <= this->getExecGrade())
		{
			std::string		filename(this->_target + "_shrubbery");
			std::ofstream	ofs(filename);

			ofs << "               ,@@@@@@@," << std::endl;
			ofs << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
			ofs << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			ofs << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			ofs << "       |o|        | |         | |" << std::endl;
			ofs << "       |.|        | |         | |" << std::endl;
			ofs << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

			std::cout << "\033[1;32mShrubberyCreationForm File : " << filename << " created\033[0m" << std::endl;
			ofs.close();
			return (0);
		}
		else
			throw ShrubberyCreationForm::GradeTooLowException();
	}
	else
		throw ShrubberyCreationForm::NotSignedException();
	return (1);
}
