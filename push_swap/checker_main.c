/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 15:52:36 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/15 17:50:32 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac == 1)
		return (0);
	ft_bzero(&stacks, sizeof(void *) * 4);
	fill_stack(&stacks, av);
	command_check(&stacks);
	exit(0);
}

void	command_check(t_stacks *stacks)
{
	read_command(stacks);
	if (stack_count(stacks->b_head) == 0 && is_sorted(stacks->a_head) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

void	read_command(t_stacks *stacks)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		exec_command(stacks, line);
		line = get_next_line(0);
		free(line);
	}
}

void	exec_command(t_stacks *stacks, char *line)
{
	if (ft_strncmp("pa\n", line, 4) == 0)
		push_a(stacks, 1);
	else if (ft_strncmp("pb\n", line, 4) == 0)
		push_b(stacks, 1);
	else if (ft_strncmp("sa\n", line, 4) == 0)
		swap_a(stacks, 1);
	else if (ft_strncmp("sb\n", line, 4) == 0)
		swap_b(stacks, 1);
	else if (ft_strncmp("ss\n", line, 4) == 0)
		swap_both(stacks, 1);
	else if (ft_strncmp("ra\n", line, 4) == 0)
		rotate_a(stacks, 1);
	else if (ft_strncmp("rb\n", line, 4) == 0)
		rotate_b(stacks, 1);
	else if (ft_strncmp("rr\n", line, 4) == 0)
		rotate_both(stacks, 1);
	else if (ft_strncmp("rra\n", line, 5) == 0)
		reverse_rotate_a(stacks, 1);
	else if (ft_strncmp("rrb\n", line, 5) == 0)
		reverse_rotate_b(stacks, 1);
	else if (ft_strncmp("rrr\n", line, 5) == 0)
		reverse_rotate_both(stacks, 1);
	else
		print_error();
}
