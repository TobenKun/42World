/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 07:54:09 by sangshin          #+#    #+#             */
/*   Updated: 2024/08/05 13:12:50 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl test;

	test.complain("DEBUG");
	test.complain("INFO");
	//test.complain("WRONG_LEVEL");
	test.complain("WARNING");
	test.complain("ERROR");
	//test.complain("WRONG_LEVEL");
}
