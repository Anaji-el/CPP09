/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 02:09:14 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/08 05:27:24 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isValid(char *av1)
{
	if (!isdigit(*av1) || std::atoi(av1) < 0)
	{
		std::cout << "Error" << std::endl;
		exit(0);
	}
	return true;
}

int main(int ac, char *av[])
{
	PmergeMe yoink;
	unsigned int tmp;
	if ((ac - 1) % 2 != 0)
	{
		tmp = std::atoi(av[ac - 1]);
		yoink.flag = true;
		isValid(av[ac - 1]);
		ac -= 1;
	}

	std::vector<std::pair<unsigned int, unsigned int> > v;
	std::deque<std::pair<unsigned int, unsigned int> > d;

	for (int i = 1; i < ac; i += 2)
	{
		if (isValid(av[i]) && isValid(av[i + 1]))
			v.push_back(std::make_pair(std::atoi(av[i]), std::atoi(av[i + 1])));
	}
	std::cout << "Before : ";
	if (ac < 6)
	{
		for (int i = 1; i < ac; i++)
			std::cout << av[i] << " ";
		if (yoink.flag)
			std::cout << tmp;
	}
	else
	{
		for (int i = 1; i < 6; i++)
			std::cout << av[i] << " ";
		std::cout << "[...]";
	}
	std::vector<unsigned int> vec_a, vec_b;
	yoink._vector(ac, v, vec_a, vec_b, tmp);

	std::deque<unsigned int> dec_a, dec_b;
	yoink._deque(ac, d, dec_a, dec_b, tmp);
}
