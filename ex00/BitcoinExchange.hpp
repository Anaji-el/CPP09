/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaji-el <anaji-el@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:47:10 by anaji-el          #+#    #+#             */
/*   Updated: 2023/03/29 00:17:20 by anaji-el         ###   ########.fr       */
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
public:
	Btc();
	Btc &  operator=(Btc const & rhs);
	~Btc();
	
};
#endif
