/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:41:26 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/18 14:49:10 by sangshin         ###   ########.fr       */
/*   Updated: 2024/01/17 11:49:04 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	map_checker(char *map, t_game *game)
{
	int	map_width;
	int	map_height;

	prevent_uckka(map);
	map_width = 0;
	while (map[map_width] != '\n')
		map_width++;
	map_height = (int)ft_strlen(map) / (map_width + 1);
	wall_check(map, map_width, map_height);
	mandatory_check(map, map_width, map_height);
	else_check(map);
	smart_navi(map, map_width);
	game->map = map;
	game->width = map_width;
}

void	prevent_uckka(char *map)
{
	int	nl;

	nl = 0;
	if (map == 0)
		print_error(9);
	while (*map)
	{
		if (*map == '\n')
			nl++;
		map++;
	}
	if (nl == 0)
		print_error(9);
}

void	wall_check(char *map, int width, int height)
{
	int	i;

	i = 0;
	while (i < width)
	{
		if (map[i] != '1')
			print_error(5);
		i++;
	}
	i = (width + 1) * (height - 1);
	while (map[i] != '\n')
	{
		if (map[i] != '1')
			print_error(5);
		i++;
	}
	i = 0;
	while (i < (width + 1) * height)
	{
		if (map[i] != '1' || map[i + width - 1] != '1')
			print_error(5);
		i += width + 1;
	}
}

void	mandatory_check(char *map, int width, int height)
{
	int	i;
	int	start_point;
	int	end_point;
	int	collectable;

	i = 0;
	start_point = 0;
	end_point = 0;
	collectable = 0;
	while (i < (width + 1) * height)
	{
		if (map[i] == 'P')
			start_point++;
		else if (map[i] == 'E')
			end_point++;
		else if (map[i] == 'C')
			collectable++;
		i++;
	}
	if (start_point != 1 || end_point != 1)
		print_error(6);
	if (collectable < 1)
		print_error(6);
}

void	else_check(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != '0' && map[i] != '\n' && map[i] != 'P'
			&& map[i] != 'E' && map[i] != 'C' && map[i] != 'A')
			print_error(7);
		i++;
	}
}
