#ifndef PMEREME_HPP
# define PMEREME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <sys/time.h>
#include <unistd.h>

std::vector<int> _vector(int ac, char *av[], std::vector<std::pair<unsigned int, unsigned int> > &container,
                         std::vector<unsigned int> &cont, std::vector<unsigned int> &conta);
std::deque<int> _deque(int ac, char *av[], std::deque<std::pair<unsigned int, unsigned int> > &container,
                       std::deque<unsigned int> &cont, std::deque<unsigned int> &conta);
std::pair<int, int> make_int_string_pair(int x, int s);

#endif