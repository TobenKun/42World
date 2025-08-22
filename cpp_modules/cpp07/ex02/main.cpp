/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:13:53 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/27 13:50:47 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main(void)
{
	try
	{
		Array<int> arr(16);
		std::cout << arr.size() << std::endl;
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 3;

		std::cout << arr[0] << std::endl;
		std::cout << arr[1] << std::endl;
		std::cout << arr[2] << std::endl;
		std::cout << arr[3] << std::endl;

		Array<std::string> arr2(10);
		arr2[0] = "hello";
		arr2[1] = "world";
		arr2[2] = "bye";
		arr2[3] = "world";

		Array<std::string> arr3 = arr2;

		for (unsigned i = 0; i < arr2.size(); i++)
		{
			std::cout << "arr2[" << i << "]: " << arr2[i] << std::endl;
		}
	}
	catch (...)
	{
		std::cout << "index overflow" << std::endl;
	}
}
