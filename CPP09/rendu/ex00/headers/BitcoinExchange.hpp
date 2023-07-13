/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:27:41 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/02 18:08:10 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Container */
#include <map>

/* Other */
#include <iostream>		// std::cout
#include <sstream>		// std::stringstream
#include <fstream>		// std::ifstream
#include <string>		// std::string
#include <utility>		// std::pair
#include <stdexcept>	// std::invalid_argument
#include <cfloat>		// DBL_MAX
#include <cstdlib>		// std::atoi / std::atof

/* Set COLORS */
# define RED		"\033[1;31m"
# define GREEN		"\033[1;32m"
# define YELLOW		"\033[1;33m"
# define BLUE		"\033[1;34m"
# define MAGENTA	"\033[1;35m"
# define CYAN		"\033[1;36m"
# define RESET		"\033[0m"

class BitcoinExchange
{
private:
	std::string _inputFile;
	std::string _dataFile;
	std::ifstream _ifsInputFile;
	std::ifstream _ifsDataFile;

public:
	/* Canonical Member Functions */
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const &src);
	~BitcoinExchange(void);
	BitcoinExchange &operator=(BitcoinExchange const &rhs);

	/* Additional Constructor */
	BitcoinExchange(std::string inputFile, std::string dataFile);

	/* Members functions */
	void runExchange(void);
	void openFiles(void);
	std::map<std::string, double> getData(void);
	void parseInput(std::map<std::string, double> data);
	void closeFiles(void);
	void checkDate(std::string const &date);
	int compareDate(std::string const &date1, std::string const &date2);
};
