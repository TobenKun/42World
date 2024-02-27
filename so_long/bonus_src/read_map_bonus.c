/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:40:31 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/22 17:03:25 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	read_map(int ac, char **av, t_game *game)
{
	if (ac != 2)
		print_error(1);
	extension_check(av);
	map_checker(map_parsing(av), game);
}

void	extension_check(char **av)
{
	int		len;
	char	*name;

	name = av[1];
	len = ft_strlen(name);
	if (name[len - 4] != '.' || name[len - 3] != 'b' || name[len - 2] != 'e'
		|| name[len - 1] != 'r')
		print_error(2);
}

char	*map_parsing(char **av)
{
	int		map_fd;
	int		line_len;
	char	*line;
	char	*map;

	line_len = -1;
	map = 0;
	map_fd = open(av[1], O_RDONLY);
	if (map_fd < 0)
		print_error(3);
	line = get_next_line(map_fd);
	while (line)
	{
		if (line_len == -1)
			line_len = ft_strlen(line);
		else if (line_len != (int)ft_strlen(line))
			print_error(4);
		map = ft_strjoin_mk2(map, line);
		line = get_next_line(map_fd);
	}
	close(map_fd);
	return (map);
}

char	*ft_strjoin_mk2(char *s1, char *s2)
{
	char	*str_mk2;

	if (s1 == 0)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	str_mk2 = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str_mk2);
}
