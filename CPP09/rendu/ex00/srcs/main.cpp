/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:28:00 by rahmed            #+#    #+#             */
/*   Updated: 2023/03/23 22:00:38 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Wrong Usage : ./btc [file]");

		BitcoinExchange btc(argv[1], "data.csv");
		btc.runExchange();
	}
	catch (std::exception &e)
	{
		std::cout << RED << "Error : " << e.what() << RESET << std::endl;
		return (1);
	}

	return (0);
}
