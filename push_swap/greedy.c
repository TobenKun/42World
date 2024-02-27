/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:00:46 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/11 16:33:45 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	if_min_max(t_stack *head, int num)
{
	int	counter;
	int	total;

	counter = 0;
	total = stack_count(head);
	while (head)
	{
		if (head->content > num)
			counter++;
		head = head->next;
	}
	if (counter > 0 && counter < total)
		return (0);
	return (1);
}

int	counting_command(t_stacks *stacks, t_stack *ptr)
{
	int	most_short[2];
	int	for_now;
	int	i;

	i = 0;
	most_short[0] = 0;
	most_short[1] = -1;
	while (ptr != 0)
	{
		for_now = i;
		if (stack_count(stacks->b_head) / 2 < i)
			for_now = stack_count(stacks->b_head) - i + 1;
		for_now += how_many_ra(stacks, ptr->content);
		if (most_short[1] == -1 || most_short[1] > for_now)
		{
			most_short[0] = i;
			most_short[1] = for_now;
		}
		ptr = ptr->next;
		i++;
	}
	return (most_short[0]);
}

int	how_many_ra(t_stacks *stacks, int target)
{
	int		info[2];
	int		i;
	t_stack	*ptr;

	i = 0;
	info[0] = -1;
	info[1] = -1;
	ptr = stacks->a_head;
	if (ptr == 0)
		return (0);
	while (ptr)
	{
		if (ptr->content < target && info[1] < ptr->content)
		{
			info[0] = i;
			info[1] = ptr->content;
		}
		ptr = ptr->next;
		i++;
	}
	if (info[0] == -1 || info[0] == stack_count(stacks->a_head) - 1)
		info[0] = 0;
	if (info[0] > stack_count(stacks->a_head) / 2)
		info[0] = stack_count(stacks->a_head) - info[0] + 1;
	return (info[0]);
}

void	do_command(t_stacks *stacks, int index)
{
	int	start_point;

	if (stacks->a_head == 0)
		return (push_a(stacks, 0));
	set_bstack(stacks, index);
	start_point = if_min_max(stacks->a_head, stacks->b_head->content);
	if (start_point == 0)
		put_middle(stacks);
	else
		put_end(stacks);
}

void	set_bstack(t_stacks *stacks, int index)
{
	int	direction;
	int	num;
	int	info[3];

	direction = 0;
	ft_memset(info, -1, 12);
	num = index_value(stacks->b_head, index);
	if (index > stack_count(stacks->b_head) / 2)
		direction = 1;
	while (stacks->b_head->content != num)
	{
		idt_finder(stacks, info, num);
		if (direction == 1 && info[2] == 1)
			reverse_rotate_both(stacks, 0);
		else if (direction == 1 && info[2] != 1)
			reverse_rotate_b(stacks, 0);
		else if (direction == 0 && info[2] == 0)
			rotate_both(stacks, 0);
		else
			rotate_b(stacks, 0);
	}
}
