/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/31 03:30:37 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// void check_date(std::string date, int year, int month, int day)
// {
// 	if (date.size() != 10)
// 		std::cerr << "invalid arguments" << std::endl;
// 	year = stoi(date.substr(0, 4));
// 	month = stoi(date.substr(5, 2));
// 	day = stoi(date.substr(8, 2));
// }

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

bool check_date(int year, int month, int day)
{
	std::string filename = "data.csv";
	std::ifstream file(filename);
	if (!file)
	{
		std::cerr << "cannot open this file!" << filename << std::endl;
		return 1;
	}
	std::string line;
	int i = 0;
	while (i++ < 2)
		std::getline(file, line);
	int y = std::stoi(line.substr(0, 4));
	int m = std::stoi(line.substr(5, 2));
	int d = std::stoi(line.substr(8, 2));
	if (year >= y && month >= m && day >= d && (month <= m && year >= y) && (day <= d && year >= y) )
	{
	if (year < 2007 || month < 0 || month > 12 || day < 1 || day > 31)
		return false;
	if (month == 2 && (day > 28))
		return false;
	if (month == 2 && day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		return true;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day < 30)
		return false;
	return true;
	}
	return false;
}

void get_date(std::string line)
{
	std::string trimmed = remove_spaces(line);
	// std::cout << trimmed << std::endl;
	if (!is_valid(trimmed))
	{
		std::cerr << "invalid arg" << std::endl;
		exit(1);
	}
	int year = std:: stoi(trimmed.substr(0, 4));
	int month = std::stoi(trimmed.substr(5, 2));
	int day = std::stoi (trimmed.substr(8, 2));
	//std::stoi (trimmed.substr(10, 5));
	if (!check_date(year, month, day))
	{
		std::cerr << "error" << std::endl; 
	}
	std::cout<< year << "-" << month << "-" << day << std::endl;
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
