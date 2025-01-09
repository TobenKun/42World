/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:54:09 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/05 13:12:34 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	Harl test(av[1]);

	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WRONG_LEVEL");
	test.complain("WARNING");
	test.complain("ERROR");
	test.complain("WRONG_LEVEL");
}
