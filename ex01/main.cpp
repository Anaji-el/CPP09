#include <iostream>
#include <stack>
#include <cstdlib>

std::string removeSpaces(std::string str)
{
	str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
	return str;
}

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "invalid arguments" << std::endl;
	std::string trimmed = removeSpaces(av[1]);
	std::stack<int> stack;
	for (size_t i = 0; i < trimmed.length(); i++)
	{
		char c = trimmed[i];
		if (isdigit(c))
			stack.push(static_cast<int>(c) - 48);
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (stack.size() < 2)
			{
				std::cerr << "Not enough numbers" << std::endl;
				exit(1);
			}
			int first = stack.top();
			stack.pop();
			int second = stack.top();
			stack.pop();
			switch (c)
			{
			case '*':
				stack.push(second * first);
				break;
			case '/':
				stack.push(second / first);
				break;
			case '+':
				stack.push(second + first);
				break;
			case '-':
				stack.push(second - first);
				break;
			}
		}
		else
		{
			std::cerr << "Wrong character" << std::endl;
			exit(1);
		}
	}
	if (stack.size() != 1)
	{
		std::cerr << "Stack not empty" << std::endl;
		exit(1);
	}
	std::cout << stack.top() << std::endl;
	return (0);
}
