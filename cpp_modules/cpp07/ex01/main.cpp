/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:13:53 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/09 16:38:35 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void test(T &t)
{
	std::cout << t << std::endl;
}

int main(void)
{
	{
		int arr[10] = {1, 2, 3};
		iter(arr, 10, test<int>);
	}
	{
		char arr[15] = "hello world!";
		iter(arr, 15, test<char>);
	}
	{
		char const *arr[10] = {0};
		arr[0] = "dd";
		arr[1] = "00";
		arr[2] = "11";
		arr[3] = "xxxxxxxxxxxx";
		arr[4] = "99999999999";
		iter(arr, 5, test<const char *>);
	}
	{
		std::string arr[10];
		arr[0] = "dd";
		arr[1] = "00";
		arr[2] = "11";
		arr[3] = "xxxxxxxxxxxx";
		arr[4] = "99999999999";
		iter(arr, 5, test<std::string>);
	}
}
