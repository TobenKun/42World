/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:47:48 by sangshin          #+#    #+#             */
/*   Updated: 2024/01/22 17:02:08 by sangshin         ###   ########.fr       */
/*   Updated: 2024/01/17 12:40:56 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	print_error(int err_no)
{
	write(2, "Error\n", 7);
	if (err_no == 1)
		perror("ac != 2\n");
	else if (err_no == 2)
		perror("argument should be .ber file\n");
	else if (err_no == 3)
		perror("open fail\n");
	else if (err_no == 4)
		perror("map is not sagackhyung\n");
	else if (err_no == 5)
		perror("map wall error\n");
	else if (err_no == 6)
		perror("mandatory error\n");
	else if (err_no == 7)
		perror("map weird char\n");
	else if (err_no == 8)
		perror("player cannot win\n");
	else if (err_no == 9)
		perror("STOP UCKKA\n");
	else if (err_no == 10)
		perror("xpm file error\n");
	exit(1);
}
