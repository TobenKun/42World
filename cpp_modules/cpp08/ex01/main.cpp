/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:33:48 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/28 12:11:49 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Span.hpp"

int main(void)
{
	try
	{
		std::srand(clock());
		Span span(10000);

		for (int i = 0; i < 10000; i++)
		{
			span.addNumber(std::rand());  // 0부터 RAND_MAX 사이 임의 정수
		}

		Span span2(5);
		int	 arr[5] = {1, 2, 3, 4, 5};

		span2.addRange(arr, arr + 5);

		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
		std::cout << "longest span: " << span.longestSpan() << std::endl;
	}
	catch (...)
	{
		std::cout << "error occurred" << std::endl;
	}
}

// 서브젝트 main문
// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// 	return 0;
// }
