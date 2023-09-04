NAME=ZombieHorde

C_FILES= main.cpp Zombie.cpp ZombieHorde.cpp

CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror -g
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(C_FILES)
	$(CXX) $(CXXFLAGS) $(C_FILES) -o $(NAME) 

clean:
	$(REMOVE) -f

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all	

.PHONY: all clean fclean re