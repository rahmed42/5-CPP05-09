/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:28:03 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/07 19:23:45 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/BitcoinExchange.hpp"

/* Canonical Member Functions */
BitcoinExchange::BitcoinExchange(void) :
_inputFile(""), _dataFile(""), _ifsInputFile(NULL), _ifsDataFile(NULL)
{
	/* Opening files */
	openFiles();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) :
_inputFile(src._inputFile), _dataFile(src._dataFile), _ifsInputFile(NULL), _ifsDataFile(NULL)
{
	/* Opening files */
	openFiles();
}

BitcoinExchange::~BitcoinExchange(void)
{
	/* Close opened files if runExchange not called */
	closeFiles();
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_inputFile = rhs._inputFile;
	this->_dataFile = rhs._dataFile;

	this->_ifsInputFile.close();
	this->_ifsInputFile.clear(); // clear the error flags
	this->_ifsInputFile.open(rhs._inputFile, std::ifstream::in);

	this->_ifsDataFile.close();
	this->_ifsDataFile.clear(); // clear the error flags
	this->_ifsDataFile.open(rhs._dataFile, std::ifstream::in);

	return (*this);
}

/* Additional Constructor */
BitcoinExchange::BitcoinExchange(std::string inputFile, std::string dataFile) :
_inputFile(inputFile), _dataFile(dataFile), _ifsInputFile(NULL), _ifsDataFile(NULL)
{
	/* Opening files */
	openFiles();
}

/* Members functions */
void BitcoinExchange::runExchange(void)
{
	/* Reading files */
	std::map<std::string, double> data = getData();
	parseInput(data);

	/* closing files */
	closeFiles();
}

void BitcoinExchange::openFiles(void)
{
	/* Opening files */
	if (_inputFile.empty() or _dataFile.empty())
		throw std::invalid_argument("Wrong Usage : Please provide the INPUT and DATA files ... ");

	_ifsInputFile.open(_inputFile, std::ifstream::in);
	if (not _ifsInputFile.is_open())
		throw std::invalid_argument("Wrong Usage : Couldn't open the INPUT file ... ");

	_ifsDataFile.open(_dataFile, std::ifstream::in);
	if (not _ifsDataFile.is_open())
		throw std::invalid_argument("Wrong Usage : Couldn't open the DATA file ... ");
}

std::map<std::string, double> BitcoinExchange::getData(void)
{
	std::map<std::string, double> data;
	std::string line;

	/* Get the first line and drop if wrong header */
	std::getline (_ifsDataFile, line);
	if (line != "date,exchange_rate")
	{
		std::cout << MAGENTA << "Your header : " << RESET << line << std::endl;
		throw std::invalid_argument("Wrong format : The DATA file header is not valid ... ");
	}

	/* Reading the file */
	while (std::getline(_ifsDataFile, line))
	{
		std::stringstream ss(line);
		std::string date, exchangeRateStr;
		double exchangeRate;

		/* Get the date */
		std::getline(ss, date, ',');
		if (date.empty())
			break;

		/* check the date format */
		checkDate(date);

		/* Get the exchange rate */
		ss >> exchangeRateStr;
		exchangeRate = std::atof(exchangeRateStr.c_str());
		if (exchangeRate < 0.0 || exchangeRate > DBL_MAX)
			throw std::out_of_range("exchange_rate is out of range: " + exchangeRateStr);

		/* Add the data to the map */
		data.insert(std::pair<std::string, double> (date, exchangeRate));

		#ifdef DEBUG
			std::cout << MAGENTA << "Date : " << date << " | Exchange Rate : " << exchangeRate << RESET << std::endl;
		#endif
	}
	return (data);
}

void BitcoinExchange::parseInput(std::map<std::string, double> data)
{
	std::map<std::string, double>::iterator itData = data.begin();
	std::map<std::string, double>::iterator iteData = data.end();
	std::string line;

	/* Get the first line and drop if wrong header */
	std::getline(_ifsInputFile, line);
	if (line != "date | value")
	{
		std::cout << MAGENTA << "Your header : " << RESET << line << std::endl;
		throw std::invalid_argument("Wrong format : The INPUT file header is not valid");
	}

	/* Reading the file */
	while (std::getline(_ifsInputFile, line))
	{
		try {
			std::stringstream ss(line);
			std::string date, valueStr;
			double value;

			/* Get the date */
			std::getline(ss, date, ' ');
			if (date.empty())
				break;
			if (ss.get() != '|' || ss.get() != ' ')
				throw std::invalid_argument("Wrong line format in the input file => " + line);

			/* check the date format */
			checkDate(date);

			/* Get the value and check bounds */
			ss >> valueStr;
			value = std::atof(valueStr.c_str());
			if (value < 0.0)
				throw std::out_of_range("Value is negative => " + valueStr);
			else if (value > 1000.0)
				throw std::out_of_range("Value is out of range => " + valueStr);

			/* Get the nearest date */
			std::map<std::string, double>::iterator nearestItData = itData;
			int deltaDate;
			int oldDeltaDate = compareDate(date, nearestItData->first);
			bool found = false;

			while (itData != iteData)
			{
				deltaDate = compareDate(date, itData->first);
				// We want the nearest date that is not greater than the date given in the input file
				if (std::abs(deltaDate) <= std::abs(oldDeltaDate) && deltaDate >= 0)
				{
					nearestItData = itData;
					oldDeltaDate = deltaDate;
				}
				// If the date is greater than the date given in the input file, we stop the loop and give the lower date
				else if (deltaDate < 0)
				{
					found = true;
					--itData;
					break;
				}
				++itData;
			}
			if (not found)
				nearestItData = --itData;
			std::cout << CYAN << date << RESET << " : " << nearestItData->second << " * " << value
			<< " = " << YELLOW << nearestItData->second * value << RESET << std::endl;
		}
		catch (std::exception& e) {
			std::cout << RED << "Error : " << e.what() << RESET << std::endl;
		}
	}
}

void BitcoinExchange::checkDate(std::string const &date)
{
	std::string YYYY_str = date.substr(0, 4);
	std::string MM_str = date.substr(5, 2);
	std::string DD_str = date.substr(8, 2);

	int YYYY = std::atoi(YYYY_str.c_str());
	int MM = std::atoi(MM_str.c_str());
	int DD = std::atoi(DD_str.c_str());

	if (date[4] != '-' || date[7] != '-')
		throw std::invalid_argument("Bad input, the date format is not valid => " + date);

	if (YYYY < 0 || YYYY > 9999)
		throw std::out_of_range("Year is out of range: " + YYYY_str);
	if (MM < 1 || MM > 12)
		throw std::out_of_range("Month is out of range: " + MM_str);
	if (DD < 1 || DD > 31 ||
		(DD > 30 && (MM == 4 || MM == 6 || MM == 9 || MM == 11)) ||
		(DD > 29 && MM == 2 && (YYYY % 4 == 0 && (YYYY % 100 != 0 || YYYY % 400 == 0))) ||
		(DD > 28 && MM == 2 && (YYYY % 4 != 0 || (YYYY % 100 == 0 && YYYY % 400 != 0))))
		throw std::out_of_range("Day is out of range: " + DD_str);
}

int BitcoinExchange::compareDate(std::string const &date1, std::string const &date2)
{
	int YYYY1, YYYY2, MM1, MM2, DD1, DD2;

	YYYY1 = std::atoi(date1.substr(0, 4).c_str());
	YYYY2 = std::atoi(date2.substr(0, 4).c_str());
	MM1 = std::atoi(date1.substr(5, 2).c_str());
	MM2 = std::atoi(date2.substr(5, 2).c_str());
	DD1 = std::atoi(date1.substr(8, 2).c_str());
	DD2 = std::atoi(date2.substr(8, 2).c_str());

	return ((YYYY1 - YYYY2) * 10000 + (MM1 - MM2) * 100 + (DD1 - DD2));
}

void BitcoinExchange::closeFiles(void)
{
	/* Close opened files */
	if (_ifsInputFile.is_open())
		_ifsInputFile.close();
	if (_ifsDataFile.is_open())
		_ifsDataFile.close();
}
