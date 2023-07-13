/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:40:58 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/07 21:17:35 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Container */
#include <vector>
#include <list>

/* Other */
#include <iostream>		// std::cout
#include <string>		// std::string
#include <stdexcept>	// std::invalid_argument
#include <ctime> 		// std::clock_t / clock / CLOCKS_PER_SEC
#include <cstdlib>		// std::atoi

/* Set COLORS */
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define RESET		"\033[0m"

/* Set Threshold */
# define INSERTION_SORT_THRESHOLD	16

class PmergeMe
{
private:
	std::vector<int> _vecSequence;
	std::list<int> _listSequence;

public:
	/* Canonical Member Functions */
	PmergeMe(void);
	PmergeMe(PmergeMe const &src);
	~PmergeMe(void);
	PmergeMe &operator=(PmergeMe const &rhs);

	/* Additional Constructor */
	PmergeMe(int const &argc, char **const &argv);

	/* Member Functions */
	void isValidSequence(int const &argc, char **const &argv);
	void runPmergeMe(int const &argc, char **const &argv);

	template <typename T>
	void printSequence(T const &sequence)
	{
		typename T::const_iterator it = sequence.begin();
		typename T::const_iterator ite = sequence.end();

		while (it != ite)
		{
			std::cout << *it;
			if (++it != ite)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	void insertionVec(std::vector<int> &vec, int const &start, int const &end);
	void mergeVec(std::vector<int> &vec, int const &start, int const &mid, int const &end);
	void sortVecSequence(std::vector<int> &vec, int const &start, int const &end);

	void insertionList(std::list<int>::iterator &start, std::list<int>::iterator &end);
	void mergeList(std::list<int>::iterator &start, std::list<int>::iterator &mid, std::list<int>::iterator &end);
	void sortListSequence(std::list<int>::iterator &start, std::list<int>::iterator &end);
};
