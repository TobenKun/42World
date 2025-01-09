/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:09:49 by sangshin          #+#    #+#             */
/*   Updated: 2024/10/06 19:03:30 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "PmergeMe.hpp"
// #include <list>

int main(void)
{
	// std::vector<int> vec = {3, 5, 4, 2, 17, 44, 24, 21, 20, 33};
	std::vector<int> vec;

	vec.push_back(4);
	vec.push_back(3);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(15);
	vec.push_back(6);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(20);
	vec.push_back(33);

	PmergeMe::mergeInsertSort(vec, 1);

	std::cout << "마지막 배열" << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
