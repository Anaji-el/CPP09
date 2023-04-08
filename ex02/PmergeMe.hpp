/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:32:26 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/08 01:01:43 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMEREME_HPP
#define PMEREME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>

class PmergeMe
{
private:
public:
	bool	flag;
	PmergeMe();
	PmergeMe(PmergeMe const &src);
	PmergeMe &operator=(PmergeMe const &rhs);
	~PmergeMe();

	void _vector(int ac, std::vector<std::pair<unsigned int, unsigned int> > &container,
				 std::vector<unsigned int> &cont, std::vector<unsigned int> &conta, unsigned int tmp);
	void _deque(int ac, std::deque<std::pair<unsigned int, unsigned int> > &container,
				std::deque<unsigned int> &cont, std::deque<unsigned int> &conta, unsigned int tmp);
};

#endif
