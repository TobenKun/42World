SHELL = /bin/bash
idx = 0
sp = /-\|/

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECKER = checker

SOURCES = push_swap_main.c parsing.c stack.c rotate.c push.c reverse_rotate.c \
		put_num.c greedy.c sorting.c swap.c indexing.c bit_counting.c manual_sort.c error.c
BONUS = checker_main.c swap.c push.c rotate.c reverse_rotate.c stack.c indexing.c \
		bit_counting.c get_next_line.c parsing.c error.c

ARC_DIR = ./new_libft
INC_ARC = $(ARC_DIR)/libft.a

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : make_mandatory make_bonus

$(NAME) : make_mandatory

bonus : make_bonus

$(CHECKER) : make_bonus

$(INC_ARC) :
	@$(MAKE) -C $(ARC_DIR) -s bonus

make_bonus : $(INC_ARC) $(BONUS_OBJ)
	@$(CC) $(CFLAGS) $(BONUS_OBJ) $(INC_ARC) -o $(CHECKER)
	@touch $@
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\bBONUS Done!               \n"

make_mandatory : $(INC_ARC) $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@touch $@
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\bDone!               \n"

%.o : %.c
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo -n "Loading ... ";\
	fi
	@printf "\b$(chr)"
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	@rm -f $(BONUS_OBJ)
	@rm -f $(OBJECTS)
	@$(MAKE) -C $(ARC_DIR) -s clean
	@rm -f make_mandatory
	@rm -f make_bonus
	@printf "Done!\n"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(CHECKER)
	@rm -f $(INC_ARC)
	@$(MAKE) -C $(ARC_DIR) -s fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
