SHELL = /bin/bash
idx = 0
sp = /-\|/

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk

SOURCES = client_main.c server_main.c
BONUS = client_main_bonus.c server_main_bonus.c
ARC_DIR = ./new_libft
INC_ARC = $(ARC_DIR)/libft.a

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : make_mandatory

$(NAME) : make_mandatory

bonus : make_bonus

$(INC_ARC) :
	@$(MAKE) -C $(ARC_DIR) -s bonus

make_bonus : $(INC_ARC) $(BONUS_OBJ)
	@rm -rf make_mandatory
	@$(CC) $(CFLAGS) client_main_bonus.o $(INC_ARC) -o client
	@$(CC) $(CFLAGS) server_main_bonus.o $(INC_ARC) -o server
	@touch $@
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\bBONUS Done!               \n"

make_mandatory : $(INC_ARC) $(OBJECTS)
	@rm -rf make_bonus
	@$(CC) $(CFLAGS) client_main.o $(INC_ARC) -o client
	@$(CC) $(CFLAGS) server_main.o $(INC_ARC) -o server
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
	@rm -f client
	@rm -f server
	@rm -f $(INC_ARC)
	@$(MAKE) -C $(ARC_DIR) -s fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
