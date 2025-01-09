SHELL = /bin/bash
idx = 0
sp = /-\|/

CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address -pthread
NAME = philo_bonus

SOURCES = main_bonus.c read_arg_bonus.c philo_utils_bonus.c start_simulation_bonus.c philo_routine_bonus.c monitor_thread_bonus.c
		  
OBJECTS = $(SOURCES:.c=.o)

all : make_mandatory
$(NAME) : make_mandatory


make_mandatory : $(OBJECTS)
	@rm -rf make_bonus
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
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@ 

clean :
	@rm -f $(OBJECTS)
	@rm -f make_mandatory
	@rm -f make_bonus
	@printf "Done!\n"

fclean : clean
	@rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
