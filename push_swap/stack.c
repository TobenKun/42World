/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 06:23:12 by sangshin          #+#    #+#             */
/*   Updated: 2023/12/24 20:31:37 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_front(t_stack **head, int content)
{
	t_stack	*new_one;

	new_one = ft_calloc(1, sizeof(t_stack));
	if (new_one == 0)
		exit(1);
	new_one->content = content;
	if (*head != 0)
	{
		new_one->next = *head;
		new_one->next->prev = new_one;
	}
	*head = new_one;
}

void	add_last(t_stack **tail, int content)
{
	t_stack	*new_one;

	new_one = ft_calloc(1, sizeof(t_stack));
	if (new_one == 0)
		exit(1);
	new_one->content = content;
	if (*tail != 0)
	{
		new_one->prev = *tail;
		new_one->prev->next = new_one;
	}
	*tail = new_one;
}

int	is_sorted(t_stack *head)
{
	while (head->next)
	{
		if (head->content > head->next->content)
			return (1);
		head = head->next;
	}
	return (0);
}

int	stack_count(t_stack *head)
{
	int	count;

	count = 0;
	while (head)
	{
		head = head->next;
		count++;
	}
	return (count);
}

void	connect_head(t_stacks *stacks)
{
	t_stack	*tmp;

	tmp = stacks->a_tail;
	while (tmp->prev)
		tmp = tmp->prev;
	stacks->a_head = tmp;
}
