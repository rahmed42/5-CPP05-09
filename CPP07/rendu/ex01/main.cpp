/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:07:39 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/16 19:20:35 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "iter.hpp"

void	ft_print_str(std::string s) {
	std::cout << s << std::endl;
}

void	ft_add_one_char(char c)
{
	std::cout << static_cast<char>(++c) << std::endl;
}

void	ft_square(int n)
{
	std::cout << pow(n, 2) << std::endl;
}

void	ft_double(double d)
{
	std::cout << d * 2 << std::endl;
}

int	main()
{
	std::string	tab1[] = {"123456", "ABCDEF", "abcdef"};
	char		tab2[] = {'a', 'z', 'A', 'Z', '(', '0'};
	int			tab3[] = {1, 2, 3, 4, 5, 6};
	double		tab4[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

	std::cout << "\033[1;32mft_print_str = print string:\033[0m" << std::endl;
	iter(tab1, 3, &ft_print_str);

	std::cout << "\033[1;32mft_add_one_char = char ++ :\033[0m" << std::endl;
	iter(tab2, 6, &ft_add_one_char);

	std::cout << "\033[1;32mft_square = number^2:\033[0m" << std::endl;
	iter(tab3, 6, &ft_square);

	std::cout << "\033[1;32mft_double = number x 2 :\033[0m" << std::endl;
	iter(tab4, 6, &ft_double);
}