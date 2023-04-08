/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 05:49:58 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/08 05:49:59 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "invalid arguments" << std::endl;
		return 0;
	}
	std::string trimmed = removeSpaces(av[1]);
	std::stack<int> stack;
	for (size_t i = 0; i < trimmed.length(); i++)
	{
		char c = trimmed[i];
		if (isdigit(c))
			stack.push(static_cast<int>(c) - 48);
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (stack.size() < 2)
			{
				std::cout << "Not enough numbers" << std::endl;
				exit(1);
			}
			int first = stack.top();
			stack.pop();
			int second = stack.top();
			stack.pop();
			switch (c)
			{
			case '*':
				stack.push(second * first);
				break;
			case '/':
				if(first == 0)
				{
					std::cout << "can't divide on Zero" << std::endl;
					return 0;
				}
				stack.push(second / first);
				break;
			case '+':
				stack.push(second + first);
				break;
			case '-':
				stack.push(second - first);
				break;
			}
		}
		else
		{
			std::cout << "Wrong character" << std::endl;
			exit(1);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Stack not empty" << std::endl;
		exit(1);
	}
	std::cout << stack.top() << std::endl;
	return (0);
}
