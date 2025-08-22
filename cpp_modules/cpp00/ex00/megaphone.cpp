/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:22:54 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/05 15:36:57 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cctype>
#include <iostream>

int	main(int ac, char **av)
{
	unsigned long	i;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	av++;
	while (*av)
	{
		std::string str = *av;
		for (i = 0; i < str.size(); i++)
			str[i] = std::toupper(str[i]);
		av++;
		std::cout << str;
	}
	std::cout << std::endl;
}
