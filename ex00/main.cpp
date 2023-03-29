/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/29 00:42:00 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

void check_date(std::string date, int year, int month, int day)
{
	if (date.size() != 10)
		std::cerr << "invalid arguments" << std::endl;
	year = stoi(date.substr(0, 4));
	month = stoi(date.substr(5, 2));
	day = stoi(date.substr(8, 2));
}

std::string removeSpaces(const std::string &str)
{
	std::string result = str;
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
	return result;
}

bool isValid(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] != '-' && str[i] != '|' && !isdigit(str[i]))
		{
			return false;
		}
	}

	return true;
}

/* If I need date to be 01 instead of 1, I need to remove stoi */
void get_date(std::string line)
{
	if (!isValid(line))
	{
		/* I need to print right error here and not just exit */
		exit(1);
	}
	std::string trimmed = removeSpaces(line);
	int year = stoi(trimmed.substr(0, 4));
	int month = stoi(trimmed.substr(5, 2));
	int day = stoi(trimmed.substr(8, 2));
	// std::cout << year << " " << month << " " << day << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "invalid arguments" << std::endl;
		exit(1);
	}
	(void)av;
	std::string filename = "input.txt";
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "cannot open this file!" << filename << std::endl;
		return 1;
	}
	std::string line;

	while (std::getline(file, line))
	{
		get_date(line);
	}
	return 0;
}
