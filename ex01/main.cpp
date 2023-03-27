#include <iostream>
#include <stack>
#include <cstdlib>

int main(int ac, char** av) {
    if (ac != 2)
        std::cerr << "invalid arguments" << std::endl;
    char* equation = av[1];
	char* item;
	item = strtok(equation, " ");
	std::cout << item << std::endl;
	item = strtok(equation, " ");
	std::cout << item << std::endl;
	while ((item = strtok(equation, " "))) {
		std::cout << item << std::endl;
	}

}
