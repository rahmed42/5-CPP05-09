/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:41:10 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/02 23:08:04 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

int main(int argc, char **argv)
{
	try	{
		PmergeMe pmergeMe(argc, argv);
	}
	catch (std::exception &e) {
		std::cout << RED << "Error : " << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}
