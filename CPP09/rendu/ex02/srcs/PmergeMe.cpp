/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:40:44 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/07 21:17:20 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/PmergeMe.hpp"

/* Canonical Member Functions */
PmergeMe::PmergeMe(void) :
_vecSequence(), _listSequence() {}

PmergeMe::PmergeMe(PmergeMe const &src) :
_vecSequence(src._vecSequence), _listSequence(src._listSequence) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_vecSequence = rhs._vecSequence;
	this->_listSequence = rhs._listSequence;

	return (*this);
}

/* Additional Constructor */
PmergeMe::PmergeMe(int const &argc, char **const &argv) :
_vecSequence(), _listSequence()
{
	/* Check if sequence is valid */
	isValidSequence(argc, argv);

	/* Run PmergeMe to sort */
	runPmergeMe(argc, argv);
}

/* Member Functions */
/* Check if expression is valid and print duplicates */
void PmergeMe::isValidSequence(int const &argc, char **const &argv)
{
	/* Check if sequence is not empty */
	if (argc < 2)
		throw std::invalid_argument("Wrong Usage : ./PmergeMe <Sequence of positive integers>");

	/* Check if not intergers */
	for (int i = 1; i < argc; i++)
	{
		std::string str(argv[i]);
		for (std::size_t j = 0; j < str.length(); j++)
		{
			if (!std::isdigit(str.at(j)))
				throw std::invalid_argument("Sequence contains non-integer values");
		}
	}

	bool duplicate = false;
	std::vector<int> vec;

	/* Check if duplicates or negative numbers */
	for (int i = 1; i < argc; i++)
	{
		if (std::atoi(argv[i]) < 0)
			throw std::invalid_argument("Sequence contains negative numbers");

		for (int j = i + 1; j < argc; j++)
		{
			duplicate = true;
			if (std::atoi(argv[i]) == std::atoi(argv[j]))
			{
				vec.push_back(std::atoi(argv[i]));
				break;
			}
		}
	}
	if (duplicate)
	{
		// Delete duplicates from the vector
		for (size_t i = 0; i < vec.size(); i++)
		{
			for (size_t j = i + 1; j < vec.size(); j++)
			{
				if (vec.at(i) == vec.at(j))
				{
					vec.erase(vec.begin() + j);
					j--;
				}
			}
		}

		// Print duplicates
		std::cout << MAGENTA << "<Sequence contains duplicate>" << RED << std::endl;
		printSequence(vec);
		std::cout << RESET << "------------------------------------" << std::endl;
	}
}

/* Run PmergeMe to sort */
void PmergeMe::runPmergeMe(int const &argc, char **const &argv)
{
	std::clock_t vecTime, lstTime, start;

	/* Fill vector with sequence */
	for (int i = 1; i < argc; i++)
		_vecSequence.push_back(std::atoi(argv[i]));

	/* Fill list with sequence */
	for (int i = 1; i < argc; i++)
		_listSequence.push_back(std::atoi(argv[i]));

	/* Print original sequence */
	std::cout << YELLOW << "Original sequence : " << RESET;
	printSequence(_vecSequence);

	/* Sort vector */
	start = std::clock();
	std::vector<int>::iterator vecIt = _vecSequence.begin(), vecIte = _vecSequence.end();
	sortVecSequence(_vecSequence, 0, _vecSequence.size() - 1);
	vecTime = std::clock() - start;
	#ifdef DEBUG
		std::cout << RED << "<DEBUG>" << CYAN << "Sorted Vector : " << RESET;
		printSequence(_vecSequence);
	#endif

	/* Sort list */
	start = std::clock();
	std::list<int>::iterator lstIt = _listSequence.begin(), lstIte = _listSequence.end();
	sortListSequence(lstIt, lstIte);
	lstTime = std::clock() - start;
	#ifdef DEBUG
		std::cout << RED << "<DEBUG>" << CYAN << "Sorted List   : " << RESET;
		printSequence(_listSequence);
	#endif

	/* Check if sorted vec and lst are the same */
	while (vecIt != vecIte && lstIt != lstIte)
	{
		if (*vecIt != *lstIt)
		{
			std::cout << RED << "Sorted Vector : " << RESET;
			printSequence(_vecSequence);
			std::cout << RED << "Sorted List   : " << RESET;
			printSequence(_listSequence);

			throw std::invalid_argument("Sorted list and vector are not the same");
		}
		vecIt++;
		lstIt++;
	}

	std::cout << YELLOW << "Sorted sequence   : " << RESET;
	printSequence(_vecSequence);

	/* Set Color of time */
	std::string colorVec = BLUE, colorLst = BLUE;
	if (vecTime < lstTime) {
		colorVec = GREEN; colorLst = RED; }
	else if (vecTime > lstTime) {
		colorVec = RED; colorLst = GREEN; }

	/* Print time */
	std::cout << YELLOW << "Time to process a range of : " << MAGENTA << argc - 1 << RESET
			<< " elements with std::vector : " << colorVec << static_cast<float>(vecTime)/CLOCKS_PER_SEC * 1000000 << " us" << RESET << std::endl;

	std::cout << YELLOW << "Time to process a range of : " << MAGENTA << argc - 1 << RESET
			<< " elements with std::list   : " << colorLst << static_cast<float>(lstTime)/CLOCKS_PER_SEC * 1000000 << " us" << RESET << std::endl;
}

/* Sort vector sequence */
void PmergeMe::insertionVec(std::vector<int> &vec, int const &start, int const &end)
{
	for (int i = start; i < end; i++)
	{
		int j = i + 1;
		int tmpVal = vec[j];

		while (j > start && vec[j - 1] > tmpVal)
		{
			vec[j] = vec[j - 1];
			j--;
		}
		vec[j] = tmpVal;
	}
}

void PmergeMe::mergeVec(std::vector<int> &vec, int const &start, int const &mid, int const &end)
{
	// Get sizes of both sides of vector
	int leftSize = mid - start + 1;
	int rightSize = end - mid;

	// Create temp vectors
	std::vector<int> leftVec;
	std::vector<int> rightVec;

	// Copy both sides of vector to temp vectors
	for (int i = 0; i < leftSize; i++)
		leftVec.push_back(vec[start + i]);
	for (int j = 0; j < rightSize; j++)
		rightVec.push_back(vec[mid + 1 + j]);

	// While both vectors have elements to compare merge them back into the original vector
	int i = 0, j = 0, k = start;
	while (i < leftSize && j < rightSize)
	{
		// Copy the smaller element back into the original vector
		if (leftVec[i] <= rightVec[j])
			vec[k++] = leftVec[i++];
		else
			vec[k++] = rightVec[j++];
	}

	// Copy remaining elements
	while (i < leftSize)
		vec[k++] = leftVec[i++];
	while (j < rightSize)
		vec[k++] = rightVec[j++];
}

void PmergeMe::sortVecSequence(std::vector<int> &vec, int const &start, int const &end)
{
	// If the vector is larger than the threshold, sort it
	if (end - start > INSERTION_SORT_THRESHOLD)
	{
		// Get the middle index
		int mid = start + (end - start) / 2;

		// Sort both sides of the vector
		sortVecSequence(vec, start, mid);
		sortVecSequence(vec, mid + 1, end);

		// Merge both sides of the vector
		mergeVec(vec, start, mid, end);
	}
	// Else sort the vector using insertion sort
	else
		insertionVec(vec, start, end);
}

/* Sort list sequence */
void PmergeMe::insertionList(std::list<int>::iterator &start, std::list<int>::iterator &end)
{
	std::list<int>::iterator i = start;
	i++;
	for (; i != end; i++)
	{
		std::list<int>::iterator j = i;
		int key = *j;

		while (j != start && *(--j) > key)
		{
			std::swap(*j, *(++j));
			j--;
		}
	}
}

void PmergeMe::mergeList(std::list<int>::iterator &start, std::list<int>::iterator &mid, std::list<int>::iterator &end)
{
	// Get sizes of both sides of list
	int leftSize = std::distance(start, mid);
	int rightSize = std::distance(mid, end);

	// Create temp lists
	std::list<int> leftList;
	std::list<int> rightList;

	// Copy both sides of list to temp lists
	std::list<int>::iterator lstIt = start;
	for (int i = 0; i < leftSize; i++)
		leftList.push_back(*lstIt++);
	for (int j = 0; j < rightSize; j++)
		rightList.push_back(*lstIt++);

	// While both lists have elements to compare merge them back into the original list
	std::list<int>::iterator leftIt = leftList.begin(), rightIt = rightList.begin();
	lstIt = start;

	while (leftIt != leftList.end() && rightIt != rightList.end())
	{
		// Copy the smaller element back into the original list
		if (*leftIt <= *rightIt)
			*lstIt++ = *leftIt++;
		else
			*lstIt++ = *rightIt++;
	}

	// Copy remaining elements
	while (leftIt != leftList.end())
		*lstIt++ = *leftIt++;
	while (rightIt != rightList.end())
		*lstIt++ = *rightIt++;
}

void PmergeMe::sortListSequence(std::list<int>::iterator &start, std::list<int>::iterator &end)
{
	// If the list is larger than the threshold, sort it
	if (std::distance(start, end) > INSERTION_SORT_THRESHOLD)
	{
		// Set the middle it at begenning and Advance it by half the distance
		std::list<int>::iterator mid = start;
		ptrdiff_t len = std::distance(start, end) / 2;

		std::advance(mid, len);

		// Sort both sides of the list
		sortListSequence(start, mid);
		sortListSequence(mid, end);

		// Merge both sides of the list
		mergeList(start, mid, end);
	}
	// Else sort the list using insertion sort
	else
		insertionList(start, end);
}
