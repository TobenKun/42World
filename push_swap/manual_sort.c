/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:10:56 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/11 16:38:03 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manual_sort(t_stacks *stacks, int total)
{
	if (total == 2)
		swap_a(stacks, 0);
	else if (total == 3)
		sort_three(stacks);
	else if (total == 4)
		sort_four(stacks);
	else
		sort_five(stacks);
}

void	sort_three(t_stacks *stacks)
{
	const int	a = stacks->a_head->content;
	const int	b = stacks->a_head->next->content;
	const int	c = stacks->a_head->next->next->content;

	if (b > c && c > a)
	{
		reverse_rotate_a(stacks, 0);
		swap_a(stacks, 0);
	}
	else if (a > b && a < c)
	{
		swap_a(stacks, 0);
	}
	else if (a < b && a > c)
		reverse_rotate_a(stacks, 0);
	else if (a > c && b < c)
	{
		rotate_a(stacks, 0);
	}
	else if (a > b && b > c)
	{
		swap_a(stacks, 0);
		reverse_rotate_a(stacks, 0);
	}
}

void	sort_four(t_stacks *stacks)
{
	push_b(stacks, 0);
	sort_three(stacks);
	b_to_a(stacks);
	last_sort(stacks);
}

void	sort_five(t_stacks *stacks)
{
	push_b(stacks, 0);
	push_b(stacks, 0);
	sort_three(stacks);
	b_to_a(stacks);
	last_sort(stacks);
}
