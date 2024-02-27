/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 07:06:59 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/22 17:03:25 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	player_move(int keycode, t_game *game)
{
	if (keycode == 123 || keycode == 0)
		can_move(game, -1);
	else if (keycode == 124 || keycode == 2)
		can_move(game, 1);
	else if (keycode == 125 || keycode == 1)
		can_move(game, game->width + 1);
	else if (keycode == 126 || keycode == 13)
		can_move(game, -(game->width + 1));
}

void	can_move(t_game *game, int direction)
{
	if (game->map[game->player + direction] == '1')
		return ;
	else if (game->map[game->player + direction] == 'C')
	{
		game->map[game->player + direction] = '0';
		game->coin_count--;
		draw_land(game, game->player + direction);
	}
	else if (game->map[game->player + direction] == 'E')
	{
		if (game->coin_count > 0)
			return ;
		else
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit(0);
		}
	}
	else if (game->map[game->player + direction] == 'A')
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(0);
	}
	move_player(game, direction);
}

void	move_player(t_game *game, int direction)
{
	game->player += direction;
	draw_player(game, game->player, game->time / 20);
	draw_land(game, game->player - direction);
	game->move_count++;
	print_move_count(game);
}

void	print_move_count(t_game *game)
{
	char	*count;
	char	*ment;

	ft_printf("Move count: %d\n", game->move_count);
	count = ft_itoa(game->move_count);
	ment = ft_strjoin("Move count: ", count);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win,
		game->wall,
		0, 0);
	mlx_put_image_to_window(game->mlx,
		game->mlx_win,
		game->wall,
		64, 0);
	mlx_string_put(game->mlx, game->mlx_win, 1, 10, 0x00FFFFFF, ment);
	free(count);
	free(ment);
}
