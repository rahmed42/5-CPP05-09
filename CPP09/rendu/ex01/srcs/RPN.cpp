/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:15:59 by rahmed            #+#    #+#             */
/*   Updated: 2023/04/07 19:49:51 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RPN.hpp"

/* Canonical Member Functions */
RPN::RPN(void) :
_stack() {}

RPN::RPN(RPN const &src) :
_stack(src._stack) {}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &rhs)
{
	if (this == &rhs)
		return (*this);

	this->_stack = rhs._stack;

	return (*this);
}

/* Additional Constructor */
RPN::RPN(std::string const &arg) :
_stack()
{
	/* Check if expression is valid */
	isValidExpression(arg);

	/* Run RPN to calculate */
	runRPN(arg);
}

/* Member Functions */
/* Check if expression is valid */
void RPN::isValidExpression(std::string const &arg)
{
	/* Check if expression is not empty */
	if (arg.empty())
		throw std::invalid_argument("Expression is empty");

	/* Check expression does not contain invalid characters */
	std::size_t found = arg.find_first_not_of("0123456789+-/* ");
	if (found != std::string::npos)
		throw std::invalid_argument("Expression contains invalid characters");

	/* check if numbers < 10 are separated by a space or operator */
	if (arg.at(arg.length() - 1) >= '0' && arg.at(arg.length() - 1) <= '9')
		throw std::invalid_argument("Expression is not valid");
	for (std::size_t i = 0; i < arg.length() - 1; i++)
	{
		if (arg.at(i) >= '0' && arg.at(i) <= '9')
		{
			if (arg.at(i + 1) != ' ' &&
				arg.at(i + 1) != '+' && arg.at(i + 1) != '-' &&
				arg.at(i + 1) != '*' && arg.at(i + 1) != '/')
				throw std::invalid_argument("Expression is not valid");
		}
	}
}

void RPN::runRPN(std::string const &arg)
{
	int a;
	int b;
	int result = 0;
	for (std::size_t i = 0; i < arg.length(); i++)
	{
		if (arg.at(i) >= '0' && arg.at(i) <= '9')
			_stack.push(arg.at(i) - '0');
		else if ((arg.at(i) == '+') && (_stack.size() >= 2))
		{
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			result = a + b;
			_stack.push(result);
			#ifdef CALC
				std::cout << BLUE << a << " + " << b << " = " << YELLOW << result << RESET << std::endl;
			#endif
		}
		else if ((arg.at(i) == '-') && (_stack.size() >= 2))
		{
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			result = a - b;
			_stack.push(result);
			#ifdef CALC
				std::cout << BLUE << a << " - " << b << " = " << YELLOW << result << RESET << std::endl;
			#endif
		}
		else if ((arg.at(i) == '*') && (_stack.size() >= 2))
		{
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			result = a * b;
			_stack.push(result);
			#ifdef CALC
				std::cout << BLUE << a << " * " << b << " = " << YELLOW << result << RESET << std::endl;
			#endif
		}
		else if ((arg.at(i) == '/') && (_stack.size() >= 2))
		{
			b = _stack.top();
			_stack.pop();
			a = _stack.top();
			_stack.pop();
			if (b == 0)
			{
				std::cout << RED << a << " / " << b << " !!!" << std::endl;
				throw std::invalid_argument("Division by zero");
			}
			result = a / b;
			_stack.push(result);
			#ifdef CALC
				std::cout << BLUE << a << " / " << b << " = " << YELLOW << result << RESET << std::endl;
			#endif
		}
		else if (arg.at(i) == ' ')
			continue;
		else
			throw std::invalid_argument("Expression is not valid");
	}
	result = _stack.top();
	std::cout << GREEN << "___________\nResult = " << YELLOW << result << RESET << std::endl;
}
