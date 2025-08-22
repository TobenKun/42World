/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:18:35 by sangshin          #+#    #+#             */
/*   Updated: 2023/10/09 17:41:11 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_real(int n, int fd)
{
	char	tmp;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	else if (n == 0)
		return ;
	ft_putnbr_real(n / 10, fd);
	tmp = n % 10 + '0';
	write(fd, &tmp, 1);
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		write(fd, "0", 1);
	else if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
		ft_putnbr_real(n, fd);
	return ;
}
