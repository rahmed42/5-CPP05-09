/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:59:24 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/30 22:37:17 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifier.hpp"

int	main( )
{
	std::cout << "Random : identify(Base* p) = " << std::endl;
	identify(generate());

	std::cout << "Random : identify(Base& p) = " << std::endl;
	identify(*generate());

	return (0);
}
