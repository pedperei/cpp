NAME=megaphone

C_FILES= megaphone.cpp

CC=c++
CFLAGS= -std=c++98 -Wall -Wextra -Werror  -g
REMOVE = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(C_FILES) -o $(NAME) 

clean:
	$(REMOVE) -f

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all	

.PHONY: all clean fclean re