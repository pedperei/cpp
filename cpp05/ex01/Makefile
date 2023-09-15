NAME=Form

C_FILES= main.cpp\
		 Bureaucrat.cpp\
		 Form.cpp\
		 
		 
CXX=c++
CXXFLAGS= -std=c++98 -Wall -Wextra -Werror -g #-fstandalone-debug
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