NAME = Btc

SRC = BitcoinExchange.cpp main.cpp

HEADER = BitcoinExchange.hpp

OBJECT = $(SRC:%.cpp=%.o)

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJECT)
	c++ $(OBJECT) -o $(NAME)

%.o:%.cpp $(HEADER)
	c++ $(FLAGS) -c $<

clean:
	/bin/rm -f $(OBJECT)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all