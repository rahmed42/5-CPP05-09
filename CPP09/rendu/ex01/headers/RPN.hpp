/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:16:15 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/02 18:05:25 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/* Container */
#include <stack>

/* Other */
#include <iostream>	 // std::cout
#include <sstream>	 // std::stringstream
#include <stdexcept> // std::invalid_argument
#include <cstdlib>	 // std::atoi / std::atof

/* Set COLORS */
#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE 	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class RPN
{
private:
	std::stack<int> _stack;

public:
	/* Canonical Member Functions */
	RPN(void);
	RPN(RPN const &src);
	~RPN(void);
	RPN &operator=(RPN const &rhs);

	/* Additional Constructor */
	RPN(std::string const &arg);

	/* Members functions */
	void isValidExpression(std::string const &arg);
	void runRPN(std::string const &arg);
};
