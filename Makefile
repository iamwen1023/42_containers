SRC			= main.cpp 
OBJ			= $(SRC:.cpp=.o)
NAME		= ex02
FLAGS		= -Wall -Wextra -Werror -std=c++98 
CC			= c++
RM			= rm -rf
SHADOW		= -Wshadow=local


all: $(NAME)

$(NAME): $(OBJ)
		$(CC) -o $@ $(OBJ) $(FLAGS) $(SHADOW)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM)  $(NAME)

re:    fclean 
	   make all

.PHONY:     all clean fclean re