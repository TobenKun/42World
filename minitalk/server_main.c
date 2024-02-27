/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 22:39:56 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/04 17:24:05 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "new_libft/libft.h"

/* everything[0] = idx;
 * everything[1] = one character;
 * everything[2] = flag;
 */
int	g_everything[3];

int	main(void)
{
	ft_memset(g_everything, 0, sizeof(int) * 3);
	ft_printf("pid: %d\n", getpid());
	signal(SIGUSR1, (void *)sigusr1_handler);
	signal(SIGUSR2, (void *)sigusr2_handler);
	exec_server();
}

void	exec_server(void)
{
	int	client_pid;

	while (1)
	{
		if (g_everything[0] == 8 && g_everything[2] == 1)
		{
			if (g_everything[1] == 0)
			{
				ft_printf("\n");
				ft_memset(g_everything, 0, sizeof(int) * 3);
				kill(client_pid, SIGUSR1);
			}
			ft_printf("%c", g_everything[1]);
			ft_memset(g_everything, 0, sizeof(int) * 2);
		}
		else if (g_everything[0] == 32 && g_everything[2] == 0)
		{
			client_pid = g_everything[1];
			g_everything[2] = 1;
			ft_memset(g_everything, 0, sizeof(int) * 2);
		}
	}
}

void	sigusr1_handler(void)
{
	g_everything[0]++;
}

void	sigusr2_handler(void)
{
	int	idx;

	idx = g_everything[0];
	if (g_everything[2] == 0)
		g_everything[1] |= (1 << (31 - idx));
	else
		g_everything[1] |= (1 << (7 - idx));
	g_everything[0]++;
}
