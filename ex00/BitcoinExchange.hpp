/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:47:10 by anaji-el          #+#    #+#             */
/*   Updated: 2023/04/07 17:45:40 by anaji-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  BITCOINEXCHANGE_HPP
# define  BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <ostream>
#include <fstream>
#include <map>


class Btc{
private:
public:
	Btc();
	Btc(Btc const &src);
	Btc &  operator=(Btc const & rhs);
	~Btc();
	
	bool check_date(int year, int month, int day);
	bool is_valid(const std::string &str);
	bool data_(int year, int month, int day);
	void get_date(std::string line, std::map<std::string, double> &data);
	std::string remove_spaces(const std::string &str);
};
#endif
