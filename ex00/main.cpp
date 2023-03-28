/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/28 06:49:35 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include " BitcoinExchange.hpp"

void	check_date(std::string date, int year, int month, int day){
	if (date.size() != 10)
		std::cerr << "invalid arguments" << std::endl;
	if (year != 4)
	if (data)
	year = stoi(date.substr(0, 4));
	month = stoi(date.substr(5,2));
	day = stoi(date.substr(8, 2));
}

int main(int ac, char **av) {
	if (ac != 2){
		std::cerr << "invalid arguments" << std::endl;
		exit(1);
	}
	std::string	filename = "input.txt";
	std::ifstream file(filename);
	if (!file){
		std::cerr << "cannot open this file!"<< filename << std::endl;
		return 1;
	}
	std::string line;

		while (std::getline(file, line)) {
        std::string key = line.substr(0, 10);
		std::cout << key << std::endl;
    }
	return 0;
}
