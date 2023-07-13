/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:57:33 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/12 16:53:47 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int	main( void )
{
	int a = 2;
	int b = 3;

	std::cout << "\033[1;32mINITIAL VALUES :\033[0m" << std::endl;
	std::cout << "a = " << a << ", b = " << b << std::endl << std::endl;

	std::cout << "\033[1;32mSWAP :\033[0m" << std::endl;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << "\033[1;32mINITIAL VALUES :\033[0m" << std::endl;
	std::cout << "c = " << c << ", d = " << d << std::endl << std::endl;

	std::cout << "\033[1;32mSWAP :\033[0m" << std::endl;
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	return 0;
}
