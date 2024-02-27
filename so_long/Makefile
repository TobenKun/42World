SHELL = /bin/bash
idx = 0
sp = /-\|/

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long

SOURCES = $(SRC_DIR)so_long_main.c $(SRC_DIR)error_handle.c $(SRC_DIR)read_map.c $(SRC_DIR)map_check.c $(SRC_DIR)smart_navi.c \
		$(SRC_DIR)picasso.c $(SRC_DIR)draw_else.c $(SRC_DIR)game_set.c $(SRC_DIR)player_move.c $(SRC_DIR)hook.c
BONUS = $(BNS_DIR)so_long_main_bonus.c $(BNS_DIR)error_handle_bonus.c $(BNS_DIR)read_map_bonus.c $(BNS_DIR)map_check_bonus.c $(BNS_DIR)smart_navi_bonus.c \
		$(BNS_DIR)picasso_bonus.c $(BNS_DIR)draw_else_bonus.c $(BNS_DIR)game_set_bonus.c $(BNS_DIR)player_move_bonus.c $(BNS_DIR)hook_bonus.c

SRC_DIR = ./src/
BNS_DIR = ./bonus_src/

ARC_DIR = ./new_libft
INC_ARC = $(ARC_DIR)/libft.a
INC_MLX = ./mlx/libmlx.a

OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)

all : make_mandatory

$(NAME) : make_mandatory

bonus : make_bonus


$(INC_ARC) :
	@$(MAKE) -C $(ARC_DIR) -s bonus

$(INC_MLX) :
	@$(MAKE) -C ./mlx -s

make_bonus : $(INC_ARC) $(BONUS_OBJ) $(inc_mlx)
	@rm -rf make_mandatory
	@$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@touch $@
	@printf "\b\b\b\b\b\b\b\b\b\b\b\b\bBONUS Done!               \n"

make_mandatory : $(INC_ARC) $(OBJECTS) $(INC_MLX)
	@rm -rf make_bonus
	@$(CC) $(CFLAGS) $^ -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
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
	@rm -f $(BONUS_OBJ)
	@rm -f $(OBJECTS)
	@$(MAKE) -C $(ARC_DIR) -s clean
	@$(MAKE) -C ./mlx -s clean
	@rm -f make_mandatory
	@rm -f make_bonus
	@printf "Done!\n"

fclean : clean
	@rm -f $(NAME)
	@rm -f $(INC_ARC)
	@$(MAKE) -C $(ARC_DIR) -s fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re
