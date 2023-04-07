/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:09:14 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/07 02:46:37 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool flag = false;
unsigned int tmp;


void checkInput(char *av1, char *av2)
{
	if (std::atoi(av1) < 0 || std::atoi(av2) < 0)
	{
		std::cerr << "Invalid Input: Number Less Than 0\n";
		exit(0);
	}
}

int main(int ac, char *av[])
{
	if ((ac - 1) % 2 != 0)
	{
		flag = true;
		tmp = std::atoi(av[ac - 1]);
		if (std::atoi(av[ac - 1]) < 0)
			exit(1);
		ac -= 1;
	}

	std::cout << "Before : ";
	if (ac < 6)
	{
		for (size_t i = 1; i < ac; i++)
			std::cout << av[i] << " ";
	}
	else
	{
		for (size_t i = 1; i < 6; i++)
			std::cout << av[i] << " ";
		std::cout << "[...]";
	}

	std::vector<std::pair<unsigned int, unsigned int> > v;
	std::deque<std::pair<unsigned int, unsigned int> > d;
	for (int i = 1; i < ac; i += 2)
	{
		if (isdigit(*av[i]))
		{
			checkInput(av[i], av[i + 1]);
			v.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
		}
	}
	std::vector<unsigned int> vec_a, vec_b;
	_vector(ac, av, v, vec_a, vec_b);

	std::deque<unsigned int> dec_a, dec_b;
	_deque(ac, av, d, dec_a, dec_b);
}
