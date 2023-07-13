/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 23:32:37 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/30 22:45:28 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "identifier.hpp"

Base *	generate(void)
{
	srand(static_cast<unsigned int>(time(NULL)));
	int		n = rand() % 3;

	switch (n)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (NULL);
}

void	identify(Base* p)
{
	A *		a = dynamic_cast<A *>(p);
	B *		b = dynamic_cast<B *>(p);
	C *		c = dynamic_cast<C *>(p);

	if (a)
		std::cout << "\033[1;33mIt's a \033[1;32mA \033[1;33mClass\033[0m" << std::endl;
	else if (b)
		std::cout << "\033[1;33mIt's a \033[1;32mB \033[1;33mClass\033[0m" << std::endl;
	else if (c)
		std::cout << "\033[1;33mIt's a \033[1;32mC \033[1;33mClass\033[0m" << std::endl;
	else
		std::cout << "\033[1;31mIt's an Unknown Class\033[0m" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		p = dynamic_cast<A &>(p);
		std::cout << "\033[1;33mIt's a \033[1;32mA \033[1;33mClass\033[0m" << std::endl;
	}
	catch ( std::bad_cast & bc)
	{
		std::cout << "\033[1;31mError : It's not a A Class\033[0m" << std::endl;
	}

	try
	{
		p = dynamic_cast<B &>(p);
		std::cout << "\033[1;33mIt's a \033[1;32mB \033[1;33mClass\033[0m" << std::endl;
	}
	catch ( std::bad_cast & bc)
	{
		std::cout << "\033[1;31mError : It's not a B Class\033[0m" << std::endl;
	}

	try
	{
		p = dynamic_cast<C &>(p);
		std::cout << "\033[1;33mIt's a \033[1;32mC \033[1;33mClass\033[0m" << std::endl;
	}
	catch ( std::bad_cast & bc)
	{
		std::cout << "\033[1;31mError : It's not a C Class\033[0m" << std::endl;
	}

}
