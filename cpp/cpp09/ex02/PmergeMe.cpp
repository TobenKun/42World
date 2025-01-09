/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:58:01 by sangshin          #+#    #+#             */
/*   Updated: 2024/10/06 19:07:31 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
// #include <cmath>
#include <iostream>
#include <ostream>
#include <vector>

// std::vector<int> PmergeMe::mergeInsertSort(std::vector<int>& vec)
// {
// 	if (vec.empty() || vec.size() == 1) return (vec);
//
// 	std::vector<std::pair<int, int>> pair_list;
// 	for (size_t i = 0; i < vec.size() - 1; i += 2)
// 		pair_list.push_back(std::pair<int, int>(vec[i], vec[i + 1]));
// 	if (vec.size() % 2 == 1)
// 		pair_list.push_back(std::pair<int, int>(0, vec.back()));
//
// 	return (ford(pair_list));
// }

// std::vector<std::pair<std::vector<int>, std::vector<int>>> true_vec;
//  이런 모양 만들어야함;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//  쪼갤때 승자 뒤로 패자를 넣는 방식으로
//
//  아니면 그냥 벡터 하나로 만들어서
//  앞 절반 승자, 뒷 절반 패자
//
//  함수 매개인자로 벡터랑 몇번째 라운드인지를 가져가서
//  몇개를 옮겨야 하는지 전해주기

// std::vector<std::pair<int, int>> PmergeMe::ford(
// 	std::vector<std::pair<int, int>>& arr)
// {
// 	if (arr.size() == 1) return (arr);
// }

std::vector<int> PmergeMe::mergeInsertSort(std::vector<int> &vec, int n)
{
	// n 은 1부터 2배씩 증가 ex) 1, 2, 4, 8, 16 ...

	if (n > vec.size() / 2) return (vec);

	std::cout << "n :" << n << std::endl;
	std::cout << "before: " << &vec << std::endl;

	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	for (int i = 0; i < vec.size() - n; i += (n * 2))
	{
		if (vec[i] > vec[i + n])
		{
			for (int j = 0; j < n; j++)
			{
				int tmp = vec[i + j];
				vec[i + j] = vec[i + j + n];
				vec[i + j + n] = tmp;
			}
		}
	}
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	mergeInsertSort(vec, n * 2);
	// 원래는 특정 순서로 삽입해야 하지만 지금은 그냥
	// 패자 앞에서부터 삽입하는 걸로 하자.

	std::cout << "\n재귀 나왔어!" << std::endl;
	std::cout << "n 은 지금 " << n << "야!" << std::endl;

	std::cout << "전체 벡터는 지금 ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::vector<int> winner;
	std::vector<int> loser;
	for (int i = 0; i < vec.size() - n; i += n * 2)
	{  // i 가 0 ~ 8
		for (int j = 0; j < n; j++)
		{
			winner.push_back(vec[i + j]);
			loser.push_back(vec[i + j + n]);
		}
	}
	if ((n * 2) * 2 > vec.size())
	// 짝이 안맞는 애가 있었으면
	{
		for (int i = (n * 2); i < vec.size(); i++)
		{
			loser.push_back(vec[i]);  // 루저그룹에 다 때려박아 버린다
		}
	}
	std::cout << "this is winner" << std::endl;

	for (std::vector<int>::iterator it = winner.begin(); it != winner.end();
		 ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "this is loser" << std::endl;

	for (std::vector<int>::iterator it = loser.begin(); it != loser.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	// 위너그룹이랑 루저그룹 분리 완료
	// 여기서부터 위너그룹에 루저그룹을 삽입해야 함

	// 위너그룹의 제일 마지막 애한테 진 루저그룹은 위너그룹 제일 뒤로 가면 됨
	// 비교를 해보지 않아도 그 앞에는 어차피 못들어감

	// 각 그룹의 대표의 인덱스는 n씩 증가
	// winner그룹에는 n개씩 k 그룹이 들어있음
	// k = vec.size() / 2 / n (정수 연산)
	// 즉 loser 그룹의 k번째 그룹은 위너 제일 뒤로 가면 됨

	int k = vec.size() / 2 / n - 1;	 // 0부터 세기로 합시다

	for (int i = 0; i < n; i++)
	{
		winner.push_back(loser[k * n]);
		loser.erase(loser.begin() + k * n);
	}  // 위너 마지막그룹에 진 루저그룹은 위너그룹 젤 뒤로 넣으면서 지우기

	// 원래 여기서부터 이진 탐색을 해야 하지만
	// 이진 탐색도 어렵다 그냥 앞에서부터 삽입정렬 하자
	// TODO: 여기서부터 특정 순서에 따라 이진탐색을 시작해야함
	// 근데 이제 뭐부터 넣을지를 잘 구해야 함

	int winner_group_cont = k + 1;
	int loser_group_count = k - 1;

	// TODO:: 여기 고쳐야함!!
	// 루저 카운터가 -1 이면 짜바리 넣어야됨 ㅠㅠ
	// -> 얘도 이진탐색으로

	std::cout << "삽입정렬 시작" << std::endl;
	std::cout << "winner 그룹의 수: " << winner_group_cont << std::endl;
	std::cout << "loser 그룹의 수: " << loser_group_count << std::endl;
	std::cout << "this is winner" << std::endl;

	for (std::vector<int>::iterator it = winner.begin(); it != winner.end();
		 ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::cout << "this is loser" << std::endl;

	for (std::vector<int>::iterator it = loser.begin(); it != loser.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	std::cout << "\n삽입 반복문 시작" << std::endl;
	for (int i = 0; i <= loser_group_count; i++)
	{
		std::cout << "this is winner" << std::endl;
		for (std::vector<int>::iterator it = winner.begin(); it != winner.end();
			 ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
		std::cout << "this is loser" << std::endl;
		for (std::vector<int>::iterator it = loser.begin(); it != loser.end();
			 ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		int j = 0;
		for (; j <= winner_group_cont; j++)
		{
			if (loser[i * n] < winner[j * n])  // 위너 그룹보다 작으면
			{
				std::cout << loser[i * n] << "을 " << winner[j * n]
						  << " 앞에다 넣을거야" << std::endl;
				winner.insert(winner.begin() + (j * n), loser.begin() + (i * n),
							  loser.begin() + (i * n + n));
				winner_group_cont += 1;
				break;
			}
		}
		if (j > winner_group_cont)
			winner.insert(winner.end(), loser.begin() + (i * n),
						  loser.begin() + (i * n + n));
	}
	std::cout << "n :" << n << std::endl;

	vec = winner;
	return (vec);
}

std::list<int> PmergeMe::mergeInsertSort(std::list<int> &list)
{
	// do nothing yet
	return (list);
}
