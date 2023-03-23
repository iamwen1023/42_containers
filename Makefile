
FLAGS					=	-Wall -Wextra -Werror -std=c++98 
CC						=	c++
FT_CONTAINERS_TARGET 	=	ft_container
STD_CONTAINERS_TARGET 	=	std_container
TEST_FILE_std 			=	ft_main.cpp
TEST_FILE_ft 			=	std_main.cpp
OBJS_FT					=	$(TEST_FILE_ft:.cpp=.o)
OBJS_STD				=	$(TEST_FILE_std:.cpp=.o)
INCL					=	-Iincludes/


all: $(FT_CONTAINERS_TARGET) $(STD_CONTAINERS_TARGET) 

$(FT_CONTAINERS_TARGET): $(OBJS_FT) 
						$(CC) $(OBJS_FT) -o $@

$(STD_CONTAINERS_TARGET): $(OBJS_STD) 
						$(CC) $(OBJS_STD) -o $@

$(OBJS_FT):
		$(CC) -c $(TEST_FILE_ft) $(CFLAGS) -o $@ $(INCL)

$(OBJS_STD):
		$(CC) -c $(TEST_FILE_std) $(CFLAGS) -o $@ $(INCL)

clean:
			$(RM) $(OBJS_FT) $(OBJS_STD)

fclean:		clean
			$(RM) $(FT_CONTAINERS_TARGET) $(STD_CONTAINERS_TARGET)


re: fclean all

.PHONY: all clean fclean re test

# test:	clean
# 		$(MKDIR) $(BUILD) && $(CD) $(BUILD) && \
# 		cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
# 		make all -C build
# 		cd ./$(BUILD)/tests/
# 		bash ./ft_containers_tst
