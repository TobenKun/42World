/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:07:40 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/03 16:11:10 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	book;
	std::string	usr_input;

	while (1)
	{
		if (std::cin.fail())
			return (1);
		std::cout << "please enter \"ADD\" or \"SEARCH\" or \"EXIT\"" << std::endl;
		std::getline(std::cin, usr_input);
		if (usr_input == "ADD")
			book.add();
		else if (usr_input == "SEARCH")
			book.search();
		else if (usr_input == "EXIT")
			return (0);
	}
}
