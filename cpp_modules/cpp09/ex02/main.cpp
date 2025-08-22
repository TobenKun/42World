/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:19:24 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/17 07:09:02 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <ctime>
#include <deque>
#include <iostream>
#include <sstream>
#include <vector>
#include "PmergeMe.hpp"

/* ------------ prototype -----------*/
template <typename C>
bool is_sorted(C&);
template <typename C>
double get_sort_time(PmergeMe&, C&, C&);
int	 load_av(std::vector<int>&, std::deque<int>&, std::list<int>&, int, char**);
void print(int value);
/* ----------------------------------*/

int main(int ac, char** av)
{
	PmergeMe		 pm;
	std::vector<int> vector_sequence, sorted_vector;
	std::deque<int>	 dq_sequence, sorted_dq;
	std::list<int>	 list_sequence, sorted_list;

	if (ac < 2 || load_av(vector_sequence, dq_sequence, list_sequence, ac, av))
		std::cerr << "Error: Wrong argument format" << std::endl;

	pm.setDebugMode(false);

	double vec_time = get_sort_time(pm, vector_sequence, sorted_vector);
	double dq_time = get_sort_time(pm, dq_sequence, sorted_dq);
	double list_time = get_sort_time(pm, list_sequence, sorted_list);

	// print original sequence
	std::cout << "Before: ";
	std::for_each(vector_sequence.begin(), vector_sequence.end(), print);
	std::cout << std::endl;

	// print sorted sequence
	std::cout << "After: ";
	std::for_each(sorted_vector.begin(), sorted_vector.end(), print);
	std::cout << std::endl;

	// sort check
	if (is_sorted(sorted_vector) && is_sorted(sorted_dq) &&
		is_sorted(sorted_list))
		std::cout << "\033[1;32m" << "-- OK --" << "\033[0m" << std::endl;
	else
		std::cout << "\033[1;31m" << "-- KO --" << "\033[0m" << std::endl;

	std::cout << "compare_count: " << Pair::compare_count << std::endl;

	std::cout << "time spent with vector: " << vec_time << "ms" << std::endl;
	std::cout << "time spent with deque: " << dq_time << "ms" << std::endl;
	std::cout << "time spent with list: " << list_time << "ms" << std::endl;
}

int load_av(std::vector<int>& vec, std::deque<int>& dq, std::list<int>& list,
			int ac, char** av)
{
	for (int i = 1; i < ac; ++i)
	{
		std::istringstream iss((std::string(av[i])));
		int				   num;
		if (!(iss >> num))
		{
			std::cerr << "Invalid input: " << av[i] << std::endl;
			return (1);
		}
		vec.push_back(num);
		dq.push_back(num);
		list.push_back(num);
	}
	return (0);
}

template <typename C>
double get_sort_time(PmergeMe& pm, C& unsorted, C& dest)
{
	clock_t start = clock();
	dest = pm.FJSort(unsorted);
	clock_t end = clock();

	return (double(end - start) * 1000 / CLOCKS_PER_SEC);
}

template <typename C>
bool is_sorted(C& c)
{
	typename C::iterator first = c.begin();
	typename C::iterator last = c.end();
	if (first == last) return true;	 // 빈 컨테이너는 정렬된 것으로 간주

	typename C::iterator next = first;
	++next;
	while (next != last)
	{
		if (*next < *first)	 // 이전 요소보다 현재 요소가 작으면 정렬되지 않음
		{
			return false;
		}
		++first;
		++next;
	}
	return true;
}

void print(int value) { std::cout << value << " "; }
