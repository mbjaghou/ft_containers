NAME =   ft_containers
CC = c++

INCLUDE = equal.hpp is_integral.hpp vector.hpp lexicographical_compare.hpp iterator.hpp stack.hpp\
		  avl_tree.hpp map.hpp pair.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp\


OBJ = main.o \

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)
re : fclean all

.PHONY : all clean fclean re