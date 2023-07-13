/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:39:27 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/18 19:10:56 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main( void )
{
	Bureaucrat	bureaucrat1("Master", 1);
	Bureaucrat	bureaucrat2("Noob", 50);
	Bureaucrat	bureaucrat3;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try
	{
		Bureaucrat	bureaucrat4("TOO HIGH", 0);
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	// std::cout << bureaucrat4.getName() << " / Graded : " << bureaucrat4.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	try
	{
		Bureaucrat	bureaucrat5("TOO LOW", 151);
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	// std::cout << bureaucrat5.getName() << " / Graded : " << bureaucrat5.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << bureaucrat1;
	std::cout << "Increment grade > " << std::endl;
	try
	{
		bureaucrat1.incrementGrade();
	}
	catch( Bureaucrat::GradeTooHighException & e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "Actual GRADE : " << bureaucrat1.getGrade() << std::endl;
	std::cout << "Decrement grade > " << std::endl;
	try
	{
		bureaucrat1.decrementGrade();
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "Actual GRADE : " << bureaucrat1.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << bureaucrat2;
	std::cout << "Increment grade > " << std::endl;
	try
	{
		bureaucrat2.incrementGrade();
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "Actual GRADE : " << bureaucrat2.getGrade() << std::endl;
	std::cout << "Decrement grade > " << std::endl;
	try
	{
		bureaucrat2.decrementGrade();
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "Actual GRADE : " << bureaucrat2.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << bureaucrat3;
	std::cout << "Decrement grade > " << std::endl;
	try
	{
		bureaucrat3.decrementGrade();
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "Actual GRADE : " << bureaucrat3.getGrade() << std::endl;
	std::cout << "Increment grade > " << std::endl;
	try
	{
		bureaucrat3.incrementGrade();
	}
	catch( std::exception &e )
	{
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl;
	}
	std::cout << "Actual GRADE : " << bureaucrat3.getGrade() << std::endl;

	return (0);
}
