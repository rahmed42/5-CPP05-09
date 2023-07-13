/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 21:15:11 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/06 22:01:23 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <exception>
# include <algorithm>
# include <vector>
# include <iostream>

class NotfoundException : public std::exception
{
	public :
		virtual const char* what() const throw() {
			return ("\033[1;31mNumber not found in container !\033[0m"); }
};

template <typename T>
void	easyfind(T &container, int number)
{
	std::vector<int>::const_iterator	it = container.begin();
	std::vector<int>::const_iterator	ite = container.end();

	it = std::find (it, ite, number);
	if (it == ite)
		throw NotfoundException();
	std::cout << "\033[1;32mThe Number \033[0m" << *it << " \033[1;32mwas found in container\033[0m" << std::endl;
}
