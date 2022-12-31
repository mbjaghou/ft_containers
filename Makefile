NAME =   ft_containers

NAMEONE = std_containers

CC = c++

INCLUDE = equal.hpp is_integral.hpp vector.hpp lexicographical_compare.hpp iterator.hpp stack.hpp\
		  avl_tree.hpp map.hpp pair.hpp distance.hpp

FLAGS = -Wall -Werror -Wextra -std=c++98

SRC =	main.cpp\

SRCONE = std_containers.cpp\

OBJ = main.o std_containers.o \

all: $(NAME) $(NAMEONE)

$(NAME): $(SRC) $(INCLUDE)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

$(NAMEONE) : $(SRCONE) $(INCLUDE)
	$(CC) $(FLAGS) $(SRCONE) -o $(NAMEONE)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME) $(NAMEONE)
re : fclean all

.PHONY : all clean fclean re