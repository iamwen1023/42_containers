
FLAGS					=	-Wall -Wextra -Werror -std=c++98 
CC						=	c++
FT_CONTAINERS_TARGET 	=	ft_container
STD_CONTAINERS_TARGET 	=	std_container
TEST_FILE 				=	main.cpp
FT_CONTAINERS_HEADERS 	=	srcs/map.hpp \
							srcs/vector.hpp \
							srcs/stack.hpp \
							srcs/iterator_traits.hpp \
							srcs/pair.hpp \
							srcs/rb_node.hpp \
							srcs/rb_tree.hpp \
							srcs/rbtree_iterator.hpp \
							srcs/reverse_iterator.hpp \
							srcs/utils.hpp 


all: $(FT_CONTAINERS_TARGET) 

$(FT_CONTAINERS_TARGET): $(TEST_FILE) 
	$(CC) $(CFLAGS) -I $(FT_CONTAINERS_HEADERS) $(TEST_FILE) -o

# $(STL_CONTAINERS_TARGET): $(TEST_FILE) 
# 	$(CC) $(CFLAGS) -D'star=($(STAR),0)' $@ $(TEST_FILE)

# clean :	clean
# 		rm -f $(FT_CONTAINERS_TARGET) $(STL_CONTAINERS_TARGET)

fclean:	clean


re: fclean all

.PHONY: all clean fclean re test

# test:	clean
# 		$(MKDIR) $(BUILD) && $(CD) $(BUILD) && \
# 		cmake .. -DCMAKE_BUILD_TYPE=Debug -G "Unix Makefiles"
# 		make all -C build
# 		cd ./$(BUILD)/tests/
# 		bash ./ft_containers_tst
