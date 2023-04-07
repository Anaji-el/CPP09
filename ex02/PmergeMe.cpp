#include "PmergeMe.hpp"

std::pair<int, std::string> make_int_string_pair(int x, const std::string &s)
{
	return std::make_pair(x, s);
}

std::vector<int> _vector(int ac, char *av[], std::vector<std::pair<unsigned int, unsigned int>  > &container,
					std::vector<unsigned int> &cont, std::vector<unsigned int> &conta)
{
	clock_t start_time, end;
	double diff;
	unsigned int tmp;

	start_time = clock();
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
	}

	for (size_t i = 0; i < container.size(); i++)
		conta.push_back(container[i].first);

	for (size_t i = 0; i < container.size(); i++)
		cont.push_back(container[i].second);

	std::sort(conta.begin(), conta.end());

	for (size_t i = 0; i < cont.size(); i++)
		conta.insert(std::lower_bound(begin(conta), conta.end(), cont[i]), cont[i]);
	if (false)
		conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);
	std::cout << "\nAfter : ";

	for (size_t i = 0; i < conta.size(); i++)
		std::cout << conta[i] << " ";
	std::cout << std::endl;

	end = clock();
	diff = double(end - start_time) / 1000;
	std::cout << "Time to process a range of " << ac << " elements with v : " << diff << " us"
			  << std::endl;
}

std::deque<int> _deque(int ac, char *av[], std::deque<std::pair<unsigned int, unsigned int> > &container,
					std::deque<unsigned int> &cont, std::deque<unsigned int> &conta)
{
	clock_t start_time, end;
	double diff;
	unsigned int tmp;

	start_time = clock();
	for (size_t i = 0; i < container.size(); i++)
	{
		if (container[i].first > container[i].second)
			std::swap(container[i].first, container[i].second);
	}

	for (size_t i = 0; i < container.size(); i++)
		conta.push_back(container[i].first);

	for (size_t i = 0; i < container.size(); i++)
		cont.push_back(container[i].second);

	std::sort(conta.begin(), conta.end());

	for (size_t i = 0; i < cont.size(); i++)
		conta.insert(std::lower_bound(begin(conta), conta.end(), cont[i]), cont[i]);
	if (false)
		conta.insert(std::lower_bound(conta.begin(), conta.end(), tmp), tmp);
	// std::cout << "\nAfter : ";

	// for (size_t i = 0; i < conta.size(); i++)
	//     std::cout << conta[i] << " ";

	end = clock();
	diff = double(end - start_time) / 1000;
	std::cout << "\nTime to process a range of " << ac << " elements with d : " << diff << " us"
			  << std::endl;
}
