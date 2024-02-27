/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:34:52 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/18 15:35:10 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	else if ((keycode >= 123 && keycode <= 126)
		|| keycode == 0 | keycode == 1 | keycode == 2 | keycode == 13)
		player_move(keycode, game);
	return (0);
}

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}
