NAME=PmergeMe

C_FILES= main.cpp\
		 PmergeMe.cpp\

CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror -g -fstandalone-debug
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(C_FILES)
	$(CXX) $(CXXFLAGS) $(C_FILES) -o $(NAME)

clean:
	$(REMOVE) -f
	

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

test: all
	shuf -i 1-10000 -n 1000 | tr "\n" " " | xargs ./$(NAME)
	@echo "\n"
	shuf -i 1-10000 -n 3000 | tr "\n" " " | xargs ./$(NAME)

.PHONY: all clean fclean re