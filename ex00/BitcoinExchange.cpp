/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:29:54 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/07 17:43:28 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc() {}
Btc::~Btc() {}


std::string Btc::remove_spaces(const std::string &str)
{
	std::string result = str;
	result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
	return result;
}

bool Btc::check_date(int year, int month, int day)
{
    if (year < 1000 || month <= 0 || month > 12 || day < 1 || day > 31)
        return false;
    if (month == 2 && (day > 28))
        return false;
    if (month == 2 && day == 29 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        return true;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;
}

bool Btc::is_valid(const std::string &str)
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
			if (str[i] == '.')
				continue;
			if ((!isdigit(str[i]) && str[i] != '-') || (str.find(".") != str.rfind(".")))
				return false;
			// if (!(isdigit(str[i]) && str[i] != '.' && str[i] != '-') || (str.find(".") != str.rfind(".")))
		}
	}
	return true;
}

bool Btc::data_(int year, int month, int day)
{
	std::string filename = "data.csv";
	std::ifstream file(filename);

	if (!file)
	{
		std::cerr << "Error: could not open file." << filename << std::endl;
		return 1;
	}
	std::string line;
	int i = 0;
	while (i++ < 2)
		std::getline(file, line);
	int y = std::atof((line.substr(0, 4).c_str()));
	int m = std::atof((line.substr(5, 2).c_str()));
	int d = std::atof((line.substr(8, 2).c_str()));
	if (year < y)
		return false;
	else if (year == y && month < m)
		return false;
	else if (year == y && month == m && day < d)
		return false;
	else
		return true;
}

void Btc::get_date(std::string line, std::map<std::string, double> &data)
{
	std::string trimmed = remove_spaces(line);
	// std::cout << trimmed << std::endl;
	std::map<std::string, double>::iterator it;
	if (!is_valid(trimmed))
		std::cerr << "Error" << std::endl;
	else
	{
		double value = 0;
		int year = std::atof((trimmed.substr(0, 4).c_str()));
		int month = std::atof((trimmed.substr(5, 2).c_str()));
		int day = std::atof((trimmed.substr(8, 2).c_str()));
		int len = trimmed.length() + trimmed.find('|') + 1;
		if (trimmed.find('|') != ULONG_MAX)
			value = std::atof((trimmed.substr(trimmed.find('|') + 1, len).c_str()));
		std::string date = trimmed.substr(0, trimmed.find('|'));
		if (!check_date(year, month, day) || !(value >= 0 && value <= 1000) || value < 0)
		{
			if (!check_date(year, month, day))
				std::cerr << "Error: bad input => " << date << std::endl;
			if (value < 0)
				std::cerr << "Error : not a positive number." << std::endl;
			else if (value > 1000)
				std::cerr << "Error: too large a number." << std::endl;
		}
		else if (!data_(year, month, day))
			std::cout << "2009-01-02 => " << value << " = " << 0 * value << std::endl;
		else
		{
			it = data.find(date);
			if (it == data.end())
			{
				it = data.lower_bound(date);
				it--;
			}
			// std::cout << it->first << " => " << value << " = " << it->second * value << std::endl;
			// std::cout << trimmed.substr(0, trimmed.find('|')) << "\n"<< "The lowest bound is: " << it->second << std::endl;
			std::cout << date << " => " << value << " = " << it->second * value << std::endl;
		}
	}
}