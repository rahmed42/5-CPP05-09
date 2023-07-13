/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rahmed <rahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:01:12 by rahmed            #+#    #+#             */
/*   Updated: 2022/07/11 23:13:53 by rahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include <list>

void printList ( void );
void printMutantStack ( void );

int	main()
{
	printList();
	printMutantStack();

	return (0);
}

void printMutantStack ( void )
{
	std::cout << "\033[1;36m ~~~~~ TEST Mutant Stack ~~~~~ \033[0m" << std::endl;

	MutantStack<int> mstack;

	std::cout << "\033[1;34m> PUSH > 3 Elements...\033[0m" << std::endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(42);

	std::cout << "\033[1;33mTop Element : \033[0m"	<< mstack.top() \
	<< " / Size = " << mstack.size() << std::endl;

	std::cout << "\033[1;35m< POP < 1 Element...\033[0m"	<< std::endl;
	mstack.pop();

	std::cout << "\033[1;33mTop Element : \033[0m"	<< mstack.top() \
	<< " / Size = " << mstack.size() << std::endl;

	std::cout << "\033[1;35m< POP < 1 Element...\033[0m"	<< std::endl;
	mstack.pop();

	std::cout << "\033[1;33mTop Element : \033[0m"	<< mstack.top() \
	<< " / Size = " << mstack.size() << std::endl;

	std::cout << "\033[1;34m> PUSH > 10 Elements...\033[0m" << std::endl;
	mstack.push(-3);
	mstack.push(15);
	mstack.push(737);
	mstack.push(0);
	mstack.push(13);
	mstack.push(125);
	mstack.push(17);
	mstack.push(50);
	mstack.push(424);
	mstack.push(777);

	std::cout << "\033[1;33mTop Element : \033[0m"	<< mstack.top() \
	<< " / Size = " << mstack.size() << std::endl;

	std::cout << "\033[1;36mTest Iterators : \033[0m" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	MutantStack<int>::const_iterator c_it = mstack.begin();
	MutantStack<int>::const_iterator c_ite = mstack.end();
	(void) c_it;
	(void) c_ite;

	std::cout << "\033[1;33mBegin ++ : \033[0m" << std::endl;
	++it;
	std::cout << *it << std::endl;

	std::cout << "\033[1;33mBegin -- : \033[0m" << std::endl;
	--it;
	std::cout << *it << std::endl;

	std::cout << "\033[1;36mLIST : \033[0m" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout << "\033[1;36m(poping) STACK cpy from MutantStack: \033[0m" << std::endl;
	while (!s.empty())
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
}


void printList ( void )
{
	std::cout << "\033[1;36m ~~~~~ TEST std::list ~~~~~ \033[0m" << std::endl;

	std::list<int> testlist;

	std::cout << "\033[1;34m> PUSH > 3 Elements...\033[0m" << std::endl;
	testlist.push_back(5);
	testlist.push_back(17);
	testlist.push_back(42);

	std::cout << "\033[1;33mTop Element : \033[0m"	<< testlist.back() \
	<< " / Size = " << testlist.size() << std::endl;

	std::cout << "\033[1;35m< POP < 1 Element...\033[0m"	<< std::endl;
	testlist.pop_back();

	std::cout << "\033[1;33mTop Element : \033[0m"	<< testlist.back() \
	<< " / Size = " << testlist.size() << std::endl;

	std::cout << "\033[1;35m< POP < 1 Element...\033[0m"	<< std::endl;
	testlist.pop_back();

	std::cout << "\033[1;33mTop Element : \033[0m"	<< testlist.back() \
	<< " / Size = " << testlist.size() << std::endl;

	std::cout << "\033[1;34m> PUSH > 10 Elements...\033[0m" << std::endl;
	testlist.push_back(-3);
	testlist.push_back(15);
	testlist.push_back(737);
	testlist.push_back(0);
	testlist.push_back(13);
	testlist.push_back(125);
	testlist.push_back(17);
	testlist.push_back(50);
	testlist.push_back(424);
	testlist.push_back(777);

	std::cout << "\033[1;33mTop Element : \033[0m"	<< testlist.back() \
	<< " / Size = " << testlist.size() << std::endl;

	std::cout << "\033[1;36mTest Iterators : \033[0m" << std::endl;
	std::list<int>::iterator it = testlist.begin();
	std::list<int>::iterator ite = testlist.end();

	std::list<int>::const_iterator c_it = testlist.begin();
	std::list<int>::const_iterator c_ite = testlist.end();
	(void) c_it;
	(void) c_ite;

	std::cout << "\033[1;33mBegin ++ : \033[0m" << std::endl;
	++it;
	std::cout << *it << std::endl;

	std::cout << "\033[1;33mBegin -- : \033[0m" << std::endl;
	--it;
	std::cout << *it << std::endl;

	std::cout << "\033[1;36mLIST : \033[0m" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
}