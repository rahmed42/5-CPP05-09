/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 19:46:00 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/16 19:20:30 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

template <typename T>
void	iter(T *tab, size_t size, void (*f)(T const ))
{
	size_t	i(0);

	while (i < size)
		f(tab[i++]);
}
