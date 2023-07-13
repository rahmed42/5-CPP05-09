/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 20:39:27 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/18 19:10:33 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	Bureaucrat	bureaucrat1("Master", 1);
	Bureaucrat	bureaucrat2("Noob", 51);
	Bureaucrat	bureaucrat3;

	Form		cni("CNI", 1, 1);
	Form		passport("Passport", 50, 5);
	std::cout << "\033[1;35m-Test Out of bounds-------------\033[0m" << std::endl;
	try {
		Form		president("President", 0, 1); }
	catch (std::exception & e) {
		std::cout << e.what() << std::endl; }
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try {
		Form		sanspapier("NoPaper", 151, 150); }
	catch (std::exception & e) {
		std::cout << e.what() << std::endl; }
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	try {
		Bureaucrat	bureaucrat4("TOO HIGH", 0); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	// std::cout << bureaucrat4.getName() << " / Graded : " << bureaucrat4.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	try {
		Bureaucrat	bureaucrat5("TOO LOW", 151); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	// std::cout << bureaucrat5.getName() << " / Graded : " << bureaucrat5.getGrade() << std::endl;

	std::cout << "\033[1;35m--------------\033[0m" << std::endl;

	std::cout << bureaucrat1;
	std::cout << "Increment grade > " << std::endl;
	try {
		bureaucrat1.incrementGrade(); }
	catch( Bureaucrat::GradeTooHighException & e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << "Actual GRADE : " << bureaucrat1.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	std::cout << cni;
	std::cout << "\033[1;36m-SIGNING-------------\033[0m" << std::endl;
	try {
		bureaucrat1.signForm(cni); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << cni;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	std::cout << "Decrement grade > " << std::endl;
	try {
		bureaucrat1.decrementGrade(); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << "Actual GRADE : " << bureaucrat1.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	std::cout << cni;
	std::cout << "\033[1;36m-SIGNING-------------\033[0m" << std::endl;
	try {
		bureaucrat1.signForm(cni); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << cni;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << bureaucrat2;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	std::cout << passport;
	std::cout << "\033[1;36m-SIGNING-------------\033[0m" << std::endl;
	try {
		bureaucrat2.signForm(passport); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << passport;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;


	std::cout << "Increment grade > " << std::endl;
	try {
		bureaucrat2.incrementGrade(); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << "Actual GRADE : " << bureaucrat2.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	std::cout << passport;
	std::cout << "\033[1;36m-SIGNING-------------\033[0m" << std::endl;
	try {
		bureaucrat2.signForm(passport); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << passport;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << "Decrement grade > " << std::endl;
	try {
		bureaucrat2.decrementGrade(); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << "Actual GRADE : " << bureaucrat2.getGrade() << std::endl;

	std::cout << "\033[1;36m--------------\033[0m" << std::endl;

	std::cout << bureaucrat3;
	std::cout << "Decrement grade > " << std::endl;
	try {
		bureaucrat3.decrementGrade(); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << "Actual GRADE : " << bureaucrat3.getGrade() << std::endl;
	std::cout << "Increment grade > " << std::endl;
	try {
		bureaucrat3.incrementGrade(); }
	catch( std::exception &e ) {
		std::cerr << "\033[1;31mError : " << e.what() << "\033[0m" << std::endl; }
	std::cout << "Actual GRADE : " << bureaucrat3.getGrade() << std::endl;
	std::cout << "\033[1;36m--------------\033[0m" << std::endl;
	return (0);
}
