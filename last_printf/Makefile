CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INC_H = ft_printf.h
SOURCES = ft_printf.c print_bigx.c printc.c \
printd.c printp.c prints.c printu.c printx.c
BONUS = ft_printf_bonus.c print_bigx_bonus.c printc_bonus.c \
printd_bonus.c printp_bonus.c prints_bonus.c printu_bonus.c printx_bonus.c
INC_ARC = libft.a

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : make_mandatory

$(NAME) : make_mandatory

$(INC_ARC) :
	$(MAKE) -C ./libft bonus
	cp ./libft/libft.a ./$(NAME)

bonus : make_bonus

make_bonus : $(INC_ARC) $(BONUS_OBJ)
	ar crs $(NAME) $(BONUS_OBJ)
	touch $@

make_mandatory : $(INC_ARC) $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) 
	touch $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 
clean :
	rm -f $(BONUS_OBJ)
	rm -f $(OBJECTS)
	$(MAKE) -C ./libft clean
	rm -f make_mandatory
	rm -f make_bonus

fclean : clean
	rm -f $(NAME)
	rm -f $(INC_ARC)
	$(MAKE) -C ./libft fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
