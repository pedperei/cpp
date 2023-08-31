NAME=violence

C_FILES= Weapon.cpp\
		 HumanA.cpp\
		 HumanB.cpp\
		 main.cpp\
		 
CC=c++
CFLAGS= -std=c++98 -Wall -Wextra -Werror -g
REMOVE = rm -rf

all: $(NAME)

$(NAME): $(C_FILES)
	$(CC) $(CFLAGS) $(C_FILES) -o $(NAME) 

clean:
	$(REMOVE) -f

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all	

.PHONY: all clean fclean re