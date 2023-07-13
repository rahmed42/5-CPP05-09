/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:01:12 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/10 15:56:03 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>

static void listVector( Span & sp );
static void printSpan( Span & sp, bool list );

int	main()
{
	unsigned int maxSpan(6);
	unsigned int iterationsToAdd(20000);
	unsigned int MaxSpanSize(25000);

	Span sp = Span(maxSpan);

	try	{
		printSpan(sp, true);

		sp.addNumber(12);
		printSpan(sp, true);

		sp.addNumber(3);
		printSpan(sp, true);

		sp.addNumber(17);
		sp.addNumber(-21);
		sp.addNumber(-3);
		sp.addNumber(21);
		printSpan(sp, true);

		std::cout << std::endl << "\033[1;35mTrying to add more numbers...\033[0m" << std::endl;
		sp.addNumber(44);
		sp.addNumber(155);
	}
	catch (Span::FullSpanException & e)	{
		std::cout << e.what() << std::endl;	}
	printSpan(sp, true);

	std::cout << std::endl;

	Span sp2 = Span(MaxSpanSize);
	std::cout << std::endl << "\033[1;35mAdding \033[0m" << iterationsToAdd << " \033[1;35mnumbers on \033[0m" << MaxSpanSize << std::endl;
	sp2.addRandomNumbers(iterationsToAdd);
	printSpan(sp2, false);

	std::cout << std::endl;

	Span sp3 = Span(MaxSpanSize);
	sp3.fillSpanRandom();
	printSpan(sp3, false);

	return (0);
}

static void printSpan( Span & sp, bool list )
{
	if (list)
		listVector(sp);
	else
		std::cout << std::endl << "\033[1;33mList of numbers: \033[0m" \
		<< std::endl << "[Hidden]" << std::endl;

	try
	{
		int sSpan(sp.shortestSpan());
		int lSpan(sp.longestSpan());
		std::cout << "\033[1;33mShortest Span : \033[0m"  << sSpan << std::endl;
		std::cout << "\033[1;33mLongest Span : \033[0m" << lSpan << std::endl;
	}
	catch (Span::NotEnoughNumbersException & e) {
		std::cout << e.what() << std::endl; }
}

static void listVector( Span & sp )
{
	std::cout << std::endl << "\033[1;33mList of numbers : \033[0m" << std::endl;

	for (unsigned int i = 0; i < sp.getVec().size() ; i++)
		std::cout << sp.getVec()[i] << " ";
	std::cout << std::endl;
}