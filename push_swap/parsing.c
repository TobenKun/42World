/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 06:21:52 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/25 22:49:29 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stacks *stacks, char **argv)
{
	char	**numbers;
	int		i;
	int		*dup_map[2];

	argv++;
	i = 0;
	dup_map[0] = 0;
	dup_map[1] = 0;
	while ((argv[i]))
	{
		numbers = ft_split(argv[i], ' ');
		if (numbers == 0 || numbers[0] == 0)
			print_error();
		for_numbers(numbers, dup_map);
		i++;
		free(numbers);
	}
	indexing(stacks, dup_map, argv);
	free(dup_map[0]);
	free(dup_map[1]);
	connect_head(stacks);
}

void	for_numbers(char **numbers, int **map)
{
	int	i;
	int	num;

	i = 0;
	while (numbers[i])
	{
		num = strict_atoi(numbers[i]);
		duplication_check(map, num);
		free(numbers[i]);
		i++;
	}
}

int	strict_atoi(char *str)
{
	int				i;
	long long int	result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		sign *= -1 + 2 * (str[i++] == '+');
	if (ft_isdigit(str[i]) == 0)
		print_error();
	while ('0' <= str[i] && str[i] <= '9')
	{
		result = result * 10 + (str[i++] - '0');
		if (result * sign > 2147483647 || result * sign < -2147483648)
			print_error();
	}
	if (str[i] != 0)
		print_error();
	return ((int)result * sign);
}

void	duplication_check(int	**map, long long num)
{
	if (*map == 0)
	{
		map[0] = malloc((MALLOC_SIZE) * sizeof(int));
		map[1] = malloc((MALLOC_SIZE) * sizeof(int));
	}
	if (map[0] == 0 || map[1] == 0)
		exit(1);
	if (num >= 0)
	{
		if ((map[0][num >> 5] & 1 << (num % 32)) != 0)
			print_error();
		map[0][num >> 5] |= 1 << (num % 32);
	}
	else
	{
		num *= -1;
		if ((map[1][num >> 5] & 1 << (num % 32)) != 0)
			print_error();
		map[1][num >> 5] |= 1 << (num % 32);
	}
}
