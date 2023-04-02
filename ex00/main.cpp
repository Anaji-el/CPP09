/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/02 07:27:16 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

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
			if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-')
				return false;
		}
	}
	return true;
}

bool frfr(int year, int month, int day)
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
	int y = std::atof((line.substr(0, 4).c_str()));
	int m = std::atof((line.substr(5, 2).c_str()));
	int d = std::atof((line.substr(8, 2).c_str()));
	return (!(year <= y) || !(month <= m) || !(day < d));
}

std::multimap<std::string, double> read_data()
{
	std::multimap<std::string, double> data;
	std::string filename = "data.csv";
	std::ifstream file(filename);

	if (!file)
		std::cerr << "cannot open this file!" << filename << std::endl;

	while (std::getline(file, filename))
	{
		char *p = std::strtok(&filename[0], ",");
		std::string key(p);
		p = std::strtok(NULL, ",");
		double value = std::atof(p);
		data.insert(std::pair<std::string,double>(key,value));
	}
	return (data);
}
bool check_date(int year, int month, int day)
{

	if (frfr(year, month, day))
	{
		if (year < 2009 || month <= 0 || month > 12 || day < 1 || day > 31)
			return false;
		if (month == 2 && (day > 28))
			return false;
		if (month == 2 && day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
			return true;
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
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
		std::cerr << "invalid arg" << std::endl;
	else
	{
		int year = std::atof((trimmed.substr(0, 4).c_str()));
		int month = std::atof((trimmed.substr(5, 2).c_str()));
		int day = std::atof((trimmed.substr(8, 2).c_str()));
		//int value = std::atof((trimmed.substr(11, 4).c_str()));
		int len = trimmed.length() + trimmed.find('|') + 1;
		double value = std::atof((trimmed.substr(trimmed.find('|') + 1, len).c_str()));
		std::string date = trimmed.substr(0, trimmed.find('|'));
		if (!check_date(year, month, day) || !(value >= 0 && value <= 1000) ||  value < 0)
		{
			if (!check_date(year, month, day))
				std::cerr << "Error: bad input => " << date <<  std::endl;
			else if (value < 0)
				std::cerr << "Error : not a positive number."<< std::endl;
			else if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
		}
		else
		{
			std::multimap<std::string, double> data = read_data();
			std::multimap<std::string, double>::iterator it;
			it = data.find(date);
			if(it == data.end())
			{
				it = data.lower_bound(date);
				it--;
			}
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
			// std::cout << trimmed.substr(0, trimmed.find('|')) << "\n"<< "The lowest bound is: " << it->second << std::endl;
			// std::cout << year << "-" << month << "-" << day << " | " << value << "" << std::endl;
		}
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "invalid arguments" << std::endl;
		exit(1);
	}
	std::string filename = av[1];
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
//to do's : abort when i add new lines in input 
//need to skip first line in input
//need to check name of file 