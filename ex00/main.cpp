/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/07 17:39:06 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


std::map<std::string, double> read_data()
{
	std::map<std::string, double> data;
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
		data.insert(std::pair<std::string, double>(key, value));
	}
	return (data);
}


int main(int ac, char **av)
{
	Btc b;
	if (ac  != 2)
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
	std::string  line;

	if (std::getline(file, line))
	{
		if (line.find("date") == ULONG_MAX || line.find("|") == ULONG_MAX || line.find("value") == ULONG_MAX)
		{
			std::cout << "Error: cannot find data or value" << std::endl;
			exit(1);
		}
		std::map<std::string, double> data = read_data();
		while (std::getline(file, line))
		{
			if (line.empty() || b.remove_spaces(line).empty())
			{
				continue;
			}
			b.get_date(line, data);
			b.is_valid(line);
		}
	}
	return 0;
}
