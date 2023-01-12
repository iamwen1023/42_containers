NAME		= containers
SRC			= test.cpp 
OBJ			= $(SRC:.cpp=.o)
BUILD		= build
FLAGS		= -Wall -Wextra -Werror -std=c++98 
CC			= c++
CD			= cd
RM			= rm -rf
MKDIR		= mkdir
SHADOW		= -Wshadow=local


all: $(NAME) 

$(NAME): $(OBJ)
		$(CC) -o $@ $(OBJ) $(FLAGS) $(SHADOW)

%.o: %.cpp
		$(CC) $(FLAGS) -c $< -o $(<:.cpp=.o) 

clean:
		$(RM) $(OBJ)
		$(RM) $(BUILD)

fclean: clean
		$(RM)  $(NAME)

test:	clean
		$(MKDIR) $(BUILD) && $(CD) $(BUILD) && \
		cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
		make all -C build

re:    fclean 
	   make all

.PHONY:     all clean fclean re test