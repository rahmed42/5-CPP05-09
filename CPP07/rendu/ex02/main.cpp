/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:01:20 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/11 21:38:06 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#include <cstddef>

# define MAX_VAL 745

int	main(int , char **)
{
	size_t i = 0;

	std::cout << "\033[1;36m~~~~~~~~~~int* allocated with value 42~~~~~\033[0m" << std::endl;
	int * a = new int(42);
	std::cout << "\033[1;33mValue = \033[0m" << *a << std::endl;
	std::cout << "\033[1;33mAdress = \033[0m" << a << std::endl ;
	delete a;

	std::cout << std::endl << "\033[1;36m~~~~~Init (with 3 slots) template Class Array<int>~~~~~\033[0m" << std::endl;
	Array<int> numbers(3);

	std::cout << std::endl << "\033[1;36m~~~~~int* allocated MAX_VAL array~~~~~\033[0m" << std::endl;
	int* mirror = new int[MAX_VAL];

	/* get random numbers on actual time */
	srand(static_cast<unsigned int>(time(NULL)));

	std::cout << "\033[1;36m~~~~~Try to fill and print array more than the 3 slots of Array<int>~~~~~\033[0m" << std::endl;
	try
	{
		for (i = 0; i < MAX_VAL; i++)
		{
			const int value = rand();
			std::cout << "\033[1;33mValue[" << i << "] = \033[0m" << value << std::endl;
			numbers[i] = value;
			mirror[i] = value;
		}
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl << "\033[1;36m~~~~~init 2 Array<int> in a scope~~~~~\033[0m" << std::endl;
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	std::cout << std::endl << "\033[1;36m~~~~~Compare Array<int> and int*~~~~~\033[0m" << std::endl;
	try
	{
		for ( i = 0; i < MAX_VAL; i++)
		{
			int m(mirror[i]);
			int n(numbers[i]);
			std::cout << "\033[1;33mmirror[" << i << "] = \033[0m" << m
			<< " / \033[1;33mnumbers[" << i << "] = \033[0m" << n << std::endl;
			if (m != n)
			{
				std::cerr << "didn't save the same value!!" << std::endl;
				return 1;
			}
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1;36m~~~~~Try access to Array<int> [-2]~~~~~\033[0m" << std::endl;
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1;36m~~~~~Try access to Array<int> [MAX_VAL] (more than the 3 allocated)~~~~~\033[0m" << std::endl;
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1;36m~~~~~Try to fill with numbers Array<int> [0] to [MAX_VAL]~~~~~\033[0m" << std::endl;
	try
	{
		for ( i = 0; i < MAX_VAL; i++)
		{
			int n(numbers[i]);
			std::cout << "\033[1;33mnumbers[" << i << "] = \033[0m" << n << std::endl;
			n = rand();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl << "\033[1;36m~~~~~Init template Class Array<int> with void and fill it (in scope)~~~~~\033[0m" << std::endl;
	//SCOPE
	{
		Array<int> emptyArray;
		try
		{
			for ( i = 0; i < MAX_VAL; i++)
			{
				int n(emptyArray[i]);
				std::cout << "\033[1;33mnumbers[" << i << "] = \033[0m" << n << std::endl;
				n = rand();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << std::endl << "\033[1;36m~~~~~Copy template Class Array<int> ~~~~~\033[0m" << std::endl;
	{
		Array<int> copy(numbers);
		try
		{
			for ( i = 0; i < MAX_VAL; i++)
			{
				int n(copy[i]);
				std::cout << "\033[1;33mnumbers[" << i << "] = \033[0m" << n << std::endl;
				n = rand();
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		std::cout << std::endl << "\033[1;36m~~~~~get the copy size property ~~~~~\033[0m" << std::endl;
		std::cout << "\033[1;33mnumbers.size() = \033[0m" << numbers.size() << std::endl;
		std::cout << "\033[1;33mcopy.size() = \033[0m" << copy.size() << std::endl;
	}

	std::cout << std::endl << "\033[1;36m~~~~~Delete the int*~~~~~\033[0m" << std::endl;
	delete [] mirror;

	std::cout << std::endl << "\033[1;36m~~~~~Return will destruct Array class~~~~~\033[0m" << std::endl;
	return 0;
}
