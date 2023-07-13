/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:01:12 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/10 15:56:17 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>

static void listVector( std::vector<int>	&vect );

int	main(int , char **)
{
	std::vector<int>	vect;
	int					toFind = 30;
	int					toFind2 = 42;

	vect.push_back(10);
	vect.push_back(20);
	vect.push_back(30);
	vect.push_back(40);
	vect.push_back(50);
	vect.push_back(60);
	vect.push_back(70);

	listVector(vect);
	
	std::cout << "\033[1;33measyfind(container, " << toFind << ") : \033[0m" ;
	try
	{
		easyfind(vect, toFind);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[1;33measyfind(container, " << toFind2 << ") : \033[0m" ;
	try
	{
		easyfind(vect, toFind2);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}

static void listVector( std::vector<int>	&vect )
{
	std::cout << std::endl << "\033[1;33mList of numbers : \033[0m" << std::endl;

	for (unsigned int i = 0; i < vect.size() ; i++)
		std::cout << vect[i] << " ";
	std::cout << std::endl;
}