/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/30 05:35:39 by anaji-el         ###   ########.fr       */
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

std::string remove_spaces(const std::string &str)
{
	std::string result = str;
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
	return result;
}

bool is_valid(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 4 || i == 7)
		{
			if (str[i] != '-')
				return false;
		}
		else if (i == 10)
		{
			if (str[i] != '|')
				return false;
		}
		else
		{
			if (!isdigit(str[i]))
				return false;
		}
	}
	return true;
}

void get_date(std::string line)
{
	if (!is_valid(line))
	{
		std::cerr << "invalid arg" << std::endl;
		exit(1);
	}
	std::string trimmed = remove_spaces(line);
	std::cout << trimmed << std::endl;
	std::string year = trimmed.substr(0, 4);
	std::string month = trimmed.substr(5, 2);
	std::string day = trimmed.substr(8, 2);
	std::string value = trimmed.substr(10, 5);
	std::cout << year << "" << month << "" << day << "" << value << std::endl;
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
		is_valid(line);
	}
	return 0;
}
