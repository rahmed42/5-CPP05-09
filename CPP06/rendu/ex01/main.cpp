/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:59:24 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/27 23:14:11 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serial.hpp"

int	main( )
{
	Data * d = new Data(42);
	std::cout << "\033[1;32mData ptr : \033[0m" <<  d << std::endl;

	uintptr_t s = serialize(d);
	std::cout << "\033[1;33mSerialized Data ptr : \033[0m" << s << std::endl;
	std::cout <<  "\033[1;32mDeserialized Data ptr : \033[0m" << deserialize(s) << std::endl;

	delete d;

	return (0);
}
