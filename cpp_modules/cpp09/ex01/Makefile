SHELL = /bin/bash
idx = 0
sp = /-\|/
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = RPN

SOURCES = main.cpp RPN.cpp
		

OBJECTS = $(SOURCES:.cpp=.o)

all : .make_mandatory

$(NAME) : .make_mandatory

.make_mandatory : $(OBJECTS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@touch $@
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\bDone!               \n"


%.o : %.cpp
	$(eval idx = $(shell expr $(idx) + 1))
	$(eval t_idx = $(shell expr $(idx) % 4 + 1))
	$(eval chr = $(shell echo $(sp) | cut -c $(t_idx)))
	@if [ $(idx) = 1 ]; then\
		echo -n "Loading ... ";\
	fi
	@printf "\b$(chr)"
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean :
	@rm -f $(OBJECTS)
	@rm -f .make_mandatory
	@rm -f .make_bonus
	@printf "Done!\n"

fclean : clean
	@rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
