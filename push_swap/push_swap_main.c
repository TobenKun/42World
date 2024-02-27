/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:38:05 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/25 22:51:48 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc == 1)
		return (0);
	ft_bzero(&stacks, sizeof(void *) * 4);
	fill_stack(&stacks, argv);
	sorting(&stacks);
	exit(0);
}

void	sorting(t_stacks *stacks)
{
	int	number_total;

	if (is_sorted(stacks->a_head) == 0)
		return ;
	number_total = stack_count(stacks->a_head);
	if (number_total <= 5)
	{
		manual_sort(stacks, number_total);
		return ;
	}
	a_to_b(stacks, number_total, number_total * 0.33, number_total * 0.66);
	b_to_a(stacks);
	if (is_sorted(stacks->a_head) == 0)
		return ;
	last_sort(stacks);
}
