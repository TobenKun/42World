/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:55:39 by sangshin          #+#    #+#             */
/*   Updated: 2023/11/25 22:51:04 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	(*g_fp[9])(t_flag *, va_list) = {printc, prints, printp, printd,
	printd, printu, printx, print_bigx, print_percent};

int	ft_printf(const char *string, ...)
{
	va_list	ap;
	t_flag	flag;

	ft_bzero(&flag, sizeof(t_flag));
	va_start(ap, string);
	while (*string)
	{
		if (*string == '%')
		{
			ft_bzero(&flag, sizeof(int) * 9);
			if (format_print((char *)string, ap, &flag) == -1)
				return (-1);
			while (type_check(*(++string), &flag) == -1 && *string)
				(void)"welcome to my code!";
		}
		else
			if (write(1, string, 1) < 0 * flag.total_len++)
				return (-1);
		string++;
	}
	return (flag.total_len);
}

int	format_print(char *string, va_list ap, t_flag *flag)
{
	while (*(string++))
	{
		if (type_check(*string, flag) != -1)
			return (g_fp[type_check(*string, flag)](flag, ap));
		if (flag->is_dot == 0)
			flag_check(*string, flag);
		if (*string >= '1' && *string <= '9')
		{
			read_number(&string, flag);
			string--;
		}
	}
	return (-1);
}

int	type_check(char c, t_flag *flag)
{
	char	*type;
	int		i;

	i = 0;
	type = "cspdiuxX%";
	while (type[i])
	{
		if (type[i] == c)
		{
			flag->type = c;
			return (i);
		}
		i++;
	}
	return (-1);
}

void	flag_check(char c, t_flag *flag)
{
	if (c == '#')
		flag->hash_sign = 1;
	if (c == '0' && flag->minus_zero != '-')
		flag->minus_zero = '0';
	if (c == '-')
		flag->minus_zero = '-';
	if (c == '.')
		flag->is_dot = 1;
	if (c == '+')
		flag->plus_space = '+';
	if (c == ' ' && flag->plus_space != '+')
		flag->plus_space = ' ';
}

void	read_number(char **s, t_flag *flag)
{
	if (flag->is_dot == 0)
		flag->width = ft_atoi(*s);
	else
		flag->precision = ft_atoi(*s);
	while (ft_isdigit(**s))
		(*s)++;
}
