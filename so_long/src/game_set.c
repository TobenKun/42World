/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:03:22 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/18 17:52:14 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	game_set(t_game *game)
{
	int	height;

	height = ft_strlen(game->map) / (game->width + 1);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->width * 64, height * 64, "so_long");
	load_asset(game);
	picasso(game);
	mlx_hook(game->mlx_win, 2, 0, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0, close_win, game);
	mlx_loop_hook(game->mlx, time_goes_on, game);
}

void	load_asset(t_game *game)
{
	int	i_dont;
	int	use_this;

	game->land = mlx_xpm_file_to_image
		(game->mlx, "./res/land.xpm", &i_dont, &use_this);
	game->coin = mlx_xpm_file_to_image
		(game->mlx, "./res/coin.xpm", &i_dont, &use_this);
	game->exit[0] = mlx_xpm_file_to_image
		(game->mlx, "./res/exit.xpm", &i_dont, &use_this);
	game->exit[1] = mlx_xpm_file_to_image
		(game->mlx, "./res/exit2.xpm", &i_dont, &use_this);
	game->character[0] = mlx_xpm_file_to_image
		(game->mlx, "./res/char1.xpm", &i_dont, &use_this);
	game->character[1] = mlx_xpm_file_to_image
		(game->mlx, "./res/char2.xpm", &i_dont, &use_this);
	game->wall = mlx_xpm_file_to_image
		(game->mlx, "./res/wall.xpm", &i_dont, &use_this);
	game->enemy[0] = mlx_xpm_file_to_image
		(game->mlx, "./res/enemy1.xpm", &i_dont, &use_this);
	game->enemy[1] = mlx_xpm_file_to_image
		(game->mlx, "./res/enemy2.xpm", &i_dont, &use_this);
	asset_check(game);
}

int	time_goes_on(t_game *game)
{
	game->time++;
	if (game->time > 40)
		game->time = 0;
	if (game->time > 20)
	{
		draw_land(game, game->player);
		draw_enemy(game, 0);
		draw_player(game, game->player, 0);
	}
	else
	{
		draw_land(game, game->player);
		draw_enemy(game, 1);
		draw_player(game, game->player, 1);
	}
	if (game->coin_count <= 0)
		draw_exit(game, 1);
	return (0);
}

void	asset_check(t_game *game)
{
	if (!game->land || !game->coin || !game->exit[0] || !game->exit[1]
		|| !game->character[0] || !game->character[1] || !game->wall
		|| !game->enemy[0] || !game->enemy[1])
		print_error(10);
}
