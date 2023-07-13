/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:58:01 by rahmed            #+#    #+#             */
/*   Updated: 2022/06/30 22:45:18 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Base {	public : virtual ~Base( void ) {} };

class A :	public Base {};
class B :	public Base {};
class C :	public Base {};
