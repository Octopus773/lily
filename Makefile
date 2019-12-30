##
## EPITECH PROJECT, 2019
## library lily
## File description:
## Makefile liblily
##

NAME 		= 	liblily.a

SRC		 	= 	sources/lily_add_node.c \
				sources/lily_create_node.c \
				sources/lily_destroy_list.c \
				sources/lily_destroy_node.c \
				sources/lily_get_node_from_index.c \
				sources/lily_get_index_from_node.c \
				sources/lily_get_list_length.c \
				sources/lily_rem_node.c \
				sources/lily_create_list_from_array.c \
				sources/lily_mov_node.c \
				sources/lily_inv_list.c \

OBJ 		=   $(SRC:%.c=%.o)

TESTS 		= 	tests/test_my_printf.c \

SRC_TEST 	=	sources/my_putnbr_base_long.c \


INCLUDE 	= 	-I ./includes

COVERAGE 	= 	--coverage -lcriterion

CFLAGS 		= 	-W -Wall -Wextra -Wshadow $(INCLUDE)

CC 			= 	gcc

NAME_TEST 	= 	unit_tests

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) rc $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	$(RM) *.gc*
	$(RM) $(NAME_TEST)

re : fclean all

tests_run :
	$(RM) *.gc*
	$(CC) -o $(NAME_TEST) $(SRC_TEST) $(TESTS) $(INCLUDE) $(COVERAGE) $(CFLAGS)
	./unit_tests
