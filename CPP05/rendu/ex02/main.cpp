/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:39:27 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/22 21:29:23 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main( void )
{
	Bureaucrat	bureaucrat1("Master", 1);
	std::cout << bureaucrat1;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	Bureaucrat	bureaucrat2("Noob", 51);
	std::cout << bureaucrat2;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	Bureaucrat	bureaucrat3;
	std::cout << bureaucrat3;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	ShrubberyCreationForm	scf("Shrubbery");
	std::cout << scf;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	RobotomyRequestForm		rrf("Robot");
	std::cout << rrf;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	PresidentialPardonForm	ppf("President");
	std::cout << ppf;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << "Executing ShrubberyCreationForm" << std::endl;
	try {
		bureaucrat1.executeForm(scf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	std::cout << scf << std::endl;
	try {
		bureaucrat1.signForm(scf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	try {
		bureaucrat1.executeForm(scf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	std::cout << scf;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << "Executing RobotomyRequestForm" << std::endl;
	try {
		bureaucrat2.executeForm(rrf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	std::cout << rrf << std::endl;
	try {
		bureaucrat2.signForm(rrf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	try {
		bureaucrat2.executeForm(rrf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	while (bureaucrat2.getGrade() > rrf.getExecGrade())
		bureaucrat2.incrementGrade();
	std::cout << "\033[1;33mnew EXEC grade ++ : \033[0m" << bureaucrat2 << std::endl;

	std::cout << "\033[1;33mTRY AGAIN TO EXEC \033[0m" << std::endl;
	try {
		bureaucrat2.executeForm(rrf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	std::cout << rrf;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << "Executing PresidentialPardonForm" << std::endl;
	try {
		bureaucrat3.executeForm(ppf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	std::cout << ppf << std::endl;
	try {
		bureaucrat3.signForm(ppf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;


	while (bureaucrat3.getGrade() > ppf.getSignGrade())
		bureaucrat3.incrementGrade();
	std::cout << "\033[1;33mnew Sign grade ++ : \033[0m" << bureaucrat3 << std::endl;


	std::cout << "\033[1;33mTRY AGAIN TO Sign \033[0m" << std::endl;
	try {
		bureaucrat3.signForm(ppf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	try {
		bureaucrat3.executeForm(ppf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	while (bureaucrat3.getGrade() > ppf.getExecGrade())
		bureaucrat3.incrementGrade();
	std::cout << "\033[1;33mnew Exec grade ++ : \033[0m" << bureaucrat3 << std::endl;

	try {
		bureaucrat3.executeForm(ppf); }
	catch (std::exception & e) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }

	std::cout << std::endl;

	std::cout << ppf;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	return (0);
}
