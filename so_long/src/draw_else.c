/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_else.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:02:12 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/18 17:52:33 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw_player(t_game *game, int i, int state)
{
	if (i == 0)
	{
		while (game->map[i] != 'P')
			i++;
		game->map[i] = '0';
		game->player = i;
	}
	mlx_put_image_to_window(game->mlx,
		game->mlx_win,
		game->character[state],
		(i % (game->width + 1)) * 64,
		(i / (game->width + 1)) * 64);
}

void	draw_enemy(t_game *game, int state)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'A')
		{
			draw_land(game, i);
			mlx_put_image_to_window(game->mlx,
				game->mlx_win,
				game->enemy[state],
				(i % (game->width + 1)) * 64,
				(i / (game->width + 1)) * 64);
		}
		i++;
	}
}
