/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:58:01 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/27 23:11:18 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

class Data
{
	private :
		int			_data;

	public :
		/* Canonical Member Functions */
		Data( void );
		Data( Data const & src );
		~Data( void );
		Data &	operator=( Data const & rhs );

		/* Additional Constructor */
		Data ( int d );

		/* Getters and Setters */
		int			getData( void ) const;
		void		setData( int d );
};
