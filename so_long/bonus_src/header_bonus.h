/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:42:31 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/22 17:01:39 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_BONUS_H
# define HEADER_BONUS_H

# include "../mlx/mlx.h"
# include "../new_libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	char	*map;
	int		width;
	void	*land;
	void	*character[2];
	void	*enemy[2];
	void	*coin;
	void	*exit[2];	
	void	*wall;
	int		player;
	int		coin_count;
	int		time;
	int		move_count;
}	t_game;

void	game_set(t_game *game);
void	load_asset(t_game *game);
int		key_hook(int keycode, t_game *game);
void	player_move(int keycode, t_game *game);
void	can_move(t_game *game, int direction);
void	print_move_count(t_game *game);
int		close_win(t_game *game);
void	move_player(t_game *game, int direction);
void	asset_check(t_game *game);

//loop
int		time_goes_on(t_game *game);

// read_map
void	read_map(int ac, char **av, t_game *game);
void	extension_check(char **av);
char	*map_parsing(char **av);
char	*ft_strjoin_mk2(char *s1, char *s2);

// map check
void	map_checker(char *map, t_game *game);
void	prevent_uckka(char *map);
void	wall_check(char *map, int width, int hight);
void	mandatory_check(char *map, int width, int hight);
void	else_check(char *map);

// smart_navi
void	smart_navi(char *map, int width);
void	can_win(char *map, int width);
int		obstacle_check(char *map, int i);

// draw_map
void	picasso(t_game *game);
void	draw_land(t_game *game, int player);
void	draw_wall(t_game *game);
void	draw_exit(t_game *game, int state);
void	draw_coin(t_game *game);
void	draw_player(t_game *game, int i, int state);
void	draw_enemy(t_game *game, int state);

// error handler
void	print_error(int err_no);
#endif
