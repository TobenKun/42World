/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 16:33:48 by sangshin          #+#    #+#             */
/*   Updated: 2024/09/13 16:43:37 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	std::vector<int>::iterator it = easyfind(arr, 5);
	if (it != arr.end())
		std::cout << *it << std::endl;
	else
		std::cout << "No occurrence" << std::endl;

	std::list<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	std::list<int>::iterator it2 = easyfind(list, 7);
	if (it2 != list.end())
		std::cout << *it2 << std::endl;
	else
		std::cout << "No occurrence" << std::endl;

	std::deque<int> deque;
	deque.push_back(1);
	deque.push_back(2);
	deque.push_back(3);
	std::deque<int>::iterator it3 = easyfind(deque, 2);
	if (it3 != deque.end())
		std::cout << *it3 << std::endl;
	else
		std::cout << "No occurrence" << std::endl;
}
