/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:39:27 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/22 22:52:22 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main( void )
{
	Bureaucrat	bureaucrat1("Master", 1);
	Intern		someRandomIntern;
	Form*		rrf(NULL);
	Form*		scf(NULL);
	Form*		ppf(NULL);
	Form*		badform(NULL);

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try {
		rrf = someRandomIntern.makeForm("robotomy request", "Bobby");
		std::cout << *rrf << std::endl;}
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}

	delete rrf;
	std::cout << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try {
			scf = someRandomIntern.makeForm("shrubbery creation", "Shrubby");
			std::cout << *scf << std::endl;
			std::cout << "\033[1;36m-Exec without signing\033[0m" << std::endl;
			bureaucrat1.executeForm(*scf);
			std::cout << "\033[1;36m-Sign\033[0m" << std::endl;
			bureaucrat1.signForm(*scf);
			std::cout << "\033[1;36m-Exec after signing\033[0m" << std::endl;
			bureaucrat1.executeForm(*scf);
			std::cout << *scf << std::endl;
		}
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}

	delete scf;
	std::cout << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try {
		ppf = someRandomIntern.makeForm("presidential pardon", "Presy");
		std::cout << *ppf << std::endl;}
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}

	delete ppf;
	std::cout << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try {
		badform = someRandomIntern.makeForm("PloufPlouf creation", "Baddy");
		std::cout << *badform << std::endl;}
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}

	delete badform;
	std::cout << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	return (0);
}
