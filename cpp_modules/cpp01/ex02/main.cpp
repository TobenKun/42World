/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 18:17:09 by sangshin          #+#    #+#             */
/*   Updated: 2024/07/05 18:22:21 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>
#include <string>

int	main(void)
{
	std::string		s = "HI THIS IS BRAIN";
	std::string*	stringPTR = &s;
	std::string&	stringREF = s;

	std::cout << "original address: " << std::addressof(s) << std::endl;
	std::cout << "pointer address: " << std::addressof(*stringPTR) << std::endl;
	std::cout << "reference address: " << std::addressof(stringREF) << std::endl;
	std::cout << std::endl;

	std::cout << "original value: " << s << std::endl;
	std::cout << "pointer value: " << *stringPTR << std::endl;
	std::cout << "reference value: " << stringREF << std::endl;
	std::cout << std::endl;

	return (0);
}
