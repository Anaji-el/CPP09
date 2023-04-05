#include "PmergeMe.hpp"

int main(int ac, char **av){
    if (ac != 2)
        std::cerr << "invalid arguments" << std::endl;
    
    for (int i = 1; i < ac; ++i) {
        std::string str = av[i];
        for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
            if (!isdigit(*it)) {
                std::cerr << "Error\n";
                return 1;
            }
        }
    }
    
}