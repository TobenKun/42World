/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:59:31 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/03 15:23:02 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_end(t_stacks *stacks)
{
	t_stack	*ptr;
	int		info[2];
	int		idx;

	info[0] = 0;
	idx = 0;
	ptr = stacks->a_head;
	info[1] = 0;
	while (ptr)
	{
		idx++;
		if (ptr->content > info[0])
		{
			info[0] = ptr->content;
			info[1] = idx;
		}
		ptr = ptr->next;
	}
	if (info[1] > stack_count(stacks->a_head) / 2)
		while (stacks->a_tail->content != info[0])
			reverse_rotate_a(stacks, 0);
	else
		while (stacks->a_tail->content != info[0])
			rotate_a(stacks, 0);
	push_a(stacks, 0);
}

void	put_middle(t_stacks *stacks)
{
	t_stack	*ptr;
	int		num;
	int		info[3];

	num = stacks->b_head->content;
	ptr = stacks->a_head;
	if (ptr->next == 0)
		return (push_a(stacks, 0));
	if (stacks->a_head->content < stacks->a_tail->content)
		if (num < stacks->a_head->content)
			return (push_a(stacks, 0));
	if (stacks->a_tail->content < num && stacks->a_head->content > num)
		return (push_a(stacks, 0));
	idt_finder(stacks, info, num);
	if (info[2] == 1)
	{
		while (stacks->a_head->content != info[1])
			reverse_rotate_a(stacks, 0);
	}
	else
		while (stacks->a_head->content != info[1])
			rotate_a(stacks, 0);
	push_a(stacks, 0);
}

// arr[0] = idx
// arr[1] = target_value
// arr[2] = direction
void	idt_finder(t_stacks *stacks, int *arr, int num)
{
	t_stack	*ptr;
	int		idx;
	int		target;

	idx = 0;
	ptr = stacks->a_head;
	target = -1;
	while (ptr && ptr->next)
	{
		idx++;
		if (ptr->content < num && ptr->next->content > num)
		{
			target = ptr->next->content;
			break ;
		}
		ptr = ptr->next;
	}
	if (target == -1)
		arr[2] = 2;
	else if (idx > stack_count(stacks->a_head) / 2)
		arr[2] = 1;
	else
		arr[2] = 0;
	arr[0] = idx;
	arr[1] = target;
}

int	index_value(t_stack *head, int idx)
{
	int	value;

	while (idx-- > 0)
		head = head->next;
	value = head->content;
	return (value);
}
