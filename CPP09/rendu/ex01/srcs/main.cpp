/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:16:08 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/02 18:04:50 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Wrong Usage : ./RPN \"inverted Polish mathematical expression\"");
		RPN rpn(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error : " << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}
