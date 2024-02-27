/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 10:42:11 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/22 21:56:31 by sangshin         ###   ########.fr       */
/*   Updated: 2024/01/17 12:31:52 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_bzero(&game, sizeof(t_game));
	read_map(ac, av, &game);
	game_set(&game);
	mlx_loop(game.mlx);
}
