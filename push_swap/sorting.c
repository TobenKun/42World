/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:42:14 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/03 15:30:08 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_stacks *stacks, int total, int small_pivot, int big_pivot)
{
	while (total > 0)
	{
		if (stacks->a_head->content <= small_pivot)
		{
			push_b(stacks, 0);
			if (stacks->b_head->next != 0
				&& stacks->a_head->content > big_pivot)
			{
				rotate_both(stacks, 0);
				total--;
			}
			else if (stacks->b_head->next != 0
				&& stacks->b_head->next->content > small_pivot)
				rotate_b(stacks, 0);
		}
		else if (stacks->a_head->content <= big_pivot)
			push_b(stacks, 0);
		else
			rotate_a(stacks, 0);
		total--;
	}
	while (stack_count(stacks->a_head) > 3)
		push_b(stacks, 0);
	manual_sort(stacks, stack_count(stacks->a_head));
}

void	b_to_a(t_stacks *stacks)
{
	int	index;

	while (stacks->b_head != 0)
	{
		index = counting_command(stacks, stacks->b_head);
		do_command(stacks, index);
	}
}

void	last_sort(t_stacks *stacks)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = stacks->a_head;
	while (ptr)
	{
		if (ptr->content == 0)
			break ;
		i++;
		ptr = ptr->next;
	}
	while (i > stack_count(stacks->a_head) / 2 && stacks->a_head->content != 0)
		reverse_rotate_a(stacks, 0);
	while (i <= stack_count(stacks->a_head) / 2 && stacks->a_head->content != 0)
		rotate_a(stacks, 0);
}
