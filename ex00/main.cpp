/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 13:09:03 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/27 06:20:30 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <map>

int main(int ac, char **av) {
	if (ac != 2){
		std::cerr << "invalid arguments" << std::endl;
		exit(1);
	}
	std::string	filename = "data.csv";
	std::ifstream file(filename);
	if (!file){
		std::cerr << "cannot open this file!"<< filename << std::endl;
		return 1;
	}
	std::string line;
	while (std::getline(file, line)){
		// std::cout << line << std::endl;
		std::map<std::string, int> ddata; 
	}
	return 0;
}
