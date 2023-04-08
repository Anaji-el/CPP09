/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:32:18 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/08 05:09:00 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(): flag(false) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::_vector(int ac, std::vector<std::pair<unsigned int, unsigned int> > &container,
					std::vector<unsigned int> &cont, std::vector<unsigned int> &conta, unsigned int tmp)
{
	clock_t start_time, end;
	double diff;

	start_time = clock();
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
	}

	for (size_t i = 0; i < container.size(); i++)
		conta.push_back(container[i].first);

	for (size_t i = 0; i < container.size(); i++)
		cont.push_back(container[i].second);

	std::sort(conta.begin(), conta.end());

	for (size_t i = 0; i < cont.size(); i++)
		conta.insert(std::lower_bound(begin(conta), conta.end(), cont[i]), cont[i]);
		std::cout << "\n"<< cont.size() <<"HEELLO" << std::endl;
	if (flag)
		conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);
	std::cout << "\nAfter : ";
	for (size_t i = 0; i < conta.size(); i++)
		std::cout << conta[i] << " ";
	std::cout << std::endl;

	end = clock();
	diff = double(end - start_time) / 1000;
	std::cout << "Time to process a range of " << ac << " elements with v : " << diff << " us"
			<< std::endl;
}

void PmergeMe::_deque(int ac, std::deque<std::pair<unsigned int, unsigned int> > &container,
					  std::deque<unsigned int> &cont, std::deque<unsigned int> &conta, unsigned int tmp)
{
	clock_t start_time, end;
	double diff;

	start_time = clock();
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
	}

	for (size_t i = 0; i < container.size(); i++)
		conta.push_back(container[i].first);

	for (size_t i = 0; i < container.size(); i++)
		cont.push_back(container[i].second);

	std::sort(conta.begin(), conta.end());

	for (size_t i = 0; i < cont.size(); i++)
		conta.insert(std::lower_bound(begin(conta), conta.end(), cont[i]), cont[i]);
	if (flag)
		conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);
	// std::cout << "\nAfter : ";

	// for (size_t i = 0; i < conta.size(); i++)
	//     std::cout << conta[i] << " ";

	end = clock();
	diff = double(end - start_time) / 1000;
	std::cout << "\nTime to process a range of " << ac << " elements with d : " << diff << " us"
			  << std::endl;
}
