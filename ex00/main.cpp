/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/28 03:31:21 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Btc.hpp"


int	check_date(int year, int month, int day){
	
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
