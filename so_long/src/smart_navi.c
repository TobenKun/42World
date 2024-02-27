/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart_navi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:43:17 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/18 14:46:05 by sangshin         ###   ########.fr       */
/*   Updated: 2024/01/17 11:55:30 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	smart_navi(char *map, int width)
{
	int		i;
	char	*dup_map;

	i = 0;
	dup_map = ft_strdup(map);
	while (ft_strchr(dup_map, 'P'))
	{
		while (dup_map[i] != 'P')
			i++;
		dup_map[i] = 'X';
		if (obstacle_check(dup_map, i - (width + 1)) != 1)
			dup_map[i - (width + 1)] = 'P';
		if (obstacle_check(dup_map, i + (width + 1)) != 1)
			dup_map[i + (width + 1)] = 'P';
		if (obstacle_check(dup_map, i - 1) != 1)
			dup_map[i - 1] = 'P';
		if (obstacle_check(dup_map, i + 1) != 1)
			dup_map[i + 1] = 'P';
		i = 0;
	}
	can_win(dup_map, width);
}

int	obstacle_check(char *map, int i)
{
	if (map[i] == '1' || map[i] == 'X' || map[i] == 'E' || map[i] == 'A')
		return (1);
	return (0);
}

void	can_win(char *map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'C')
			print_error(8);
		i++;
	}
	i = 0;
	while (map[i] != 'E')
		i++;
	if (map[i - (width + 1)] != 'X' && map[i + (width + 1)] != 'X'
		&& map[i - 1] != 'X' && map[i + 1] != 'X')
		print_error(8);
	free(map);
}
