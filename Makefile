NAME			=	ft_containers
NAME_STD		=	std_containers
OBJS			=	$(SRCS:.cpp=.o)
OBJS_FT			=	$(SRCS_FT:.cpp=.o)
OBJS_STD		=	$(SRCS_STD:.cpp=.o)
SRCS_FT			=	sources/main_ft.cpp
SRCS_STD		=	sources/main_std.cpp
CC				=	c++
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -std=c++98 -g
INCL			=	-Isrcs/

all:			$(NAME) $(NAME_STD)

ft:				$(NAME)

std:			$(NAME_STD)

$(NAME):		$(OBJS_FT)
		$(CC) $(OBJS_FT) -o $@

$(NAME_STD):	$(OBJS_STD)
		$(CC) $(OBJS_STD) -o $@

$(OBJS_FT):
		$(CC) -c $(SRCS_FT) $(CFLAGS) -o $@ $(INCL)

$(OBJS_STD):
		$(CC) -c $(SRCS_STD) $(CFLAGS) -o $@ $(INCL)

clean:
			$(RM) $(OBJS_FT) $(OBJS_STD)

fclean:		clean
			$(RM) $(NAME) $(NAME_STD)

re:			fclean all

.PHONY:		re, all, clean, fclean, std, ft
