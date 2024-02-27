/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picasso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:00:45 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/22 17:03:25 by sangshin         ###   ########.fr       */
/*   Updated: 2024/01/17 11:57:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	picasso(t_game *game)
{
	draw_land(game, 0);
	draw_wall(game);
	draw_exit(game, 0);
	draw_coin(game);
	draw_player(game, 0, 0);
	draw_enemy(game, 0);
	print_move_count(game);
}

void	draw_land(t_game *game, int player)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (player != 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->land,
			player % (game->width + 1) * 64,
			player / (game->width + 1) * 64);
		return ;
	}
	while (i <= game->width)
	{
		mlx_put_image_to_window
			(game->mlx, game->mlx_win, game->land, i * 64, j * 64);
		i++;
		if (i > game->width)
		{
			if (j == (int)ft_strlen(game->map) / (game->width + 1))
				break ;
			i = 0;
			j++;
		}
	}
}

void	draw_wall(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] == '1')
		{
			mlx_put_image_to_window(game->mlx,
				game->mlx_win,
				game->wall,
				(i % (game->width + 1)) * 64,
				(i / (game->width + 1)) * 64);
		}
		i++;
	}
}

void	draw_exit(t_game *game, int state)
{
	int	i;

	i = 0;
	while (game->map[i] != 'E')
		i++;
	mlx_put_image_to_window(game->mlx,
		game->mlx_win,
		game->exit[state],
		(i % (game->width + 1)) * 64,
		(i / (game->width + 1)) * 64);
}

void	draw_coin(t_game *game)
{
	int	i;

	i = 0;
	game->coin_count = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'C')
		{
			mlx_put_image_to_window(game->mlx,
				game->mlx_win,
				game->coin,
				(i % (game->width + 1)) * 64,
				(i / (game->width + 1)) * 64);
			game->coin_count++;
		}
		i++;
	}
}
