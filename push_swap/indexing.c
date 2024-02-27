/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 20:27:46 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/25 22:49:09 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stacks *stacks, int **map, char **argv)
{
	int		i;
	char	**num_list;
	int		minus_count;

	i = 0;
	minus_count = 0;
	while (i < MALLOC_SIZE)
		minus_count += bit_count(map[1][i++]);
	i = 0;
	while (*argv)
	{
		num_list = ft_split(*argv, ' ');
		if (num_list == 0)
			exit(1);
		i = 0;
		minus_or_plus(stacks, num_list, map, minus_count);
		free(num_list);
		argv++;
	}
}

void	minus_or_plus(t_stacks *stacks, char **list, int **map, int minus_count)
{
	int	i;
	int	num;

	i = 0;
	while (list[i])
	{
		num = strict_atoi(list[i]);
		if (num < 0)
			minus_indexing(stacks, map[1], num);
		else
			plus_indexing(stacks, map, num, minus_count);
		free(list[i]);
		i++;
	}
}

void	plus_indexing(t_stacks *stacks, int **map, int num, int minus_count)
{
	int	i;
	int	idx;

	i = 0;
	idx = minus_count;
	while (((num >> 5) - i) > 0)
		idx += bit_count(map[0][i++]);
	idx += extra_bit_count(map[0][i], num % 32, 0);
	add_last(&stacks->a_tail, idx);
}

void	minus_indexing(t_stacks *stacks, int *map, long long num)
{
	int	i;
	int	idx;

	i = (MALLOC_SIZE);
	idx = 0;
	num *= -1;
	while (--i > (num >> 5))
	{
		if (map[i] == 0)
			continue ;
		idx += bit_count(map[i]);
	}
	idx += extra_bit_count(map[i], num % 32, 1);
	add_last(&stacks->a_tail, idx);
}
