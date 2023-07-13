/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:59:24 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/26 22:41:11 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "convert.hpp"

int	main( int ac, char **av )
{
	if (ac == 2)
	{
		Convert	c(av[1]);
		std::cout << c;
	}
	else
		std::cout << "\033[1;31mError : Wrong number of Args\033[0m" << std::endl;

	return (0);
}
