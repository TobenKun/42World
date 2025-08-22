/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangshin <zxcv1867@naver.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:29:14 by sangshin          #+#    #+#             */
/*   Updated: 2025/02/17 12:34:19 by sangshin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <list>
#include <vector>
#include "Pair.hpp"

PmergeMe::PmergeMe() : depth(0), debug_flag(false) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::setDebugMode(bool value) { debug_flag = value; }

// ###########################################################################
// #                                                                         #
// #                        여기서부터 vector용 함수                         #
// #                                                                         #
// ###########################################################################

std::vector<int> PmergeMe::FJSort(std::vector<int> &input)
{
	Pair::compare_count = 0;
	if (input.empty()) return (input);
	std::vector<Pair> pvec;

	// input 벡터를 pair 벡터로 바꿔서 재귀함수에 전달
	for (std::vector<int>::iterator it = input.begin(); it != input.end(); it++)
		pvec.push_back(Pair(*it, NULL));

	std::vector<int>  result_vec;
	std::vector<Pair> sorted_vec = InfiniteTsukuyomi(pvec);

	// 정렬된 페어 벡터를 일반 벡터로 바꿔서 리턴
	for (std::vector<Pair>::reverse_iterator it = sorted_vec.rbegin();
		 it != sorted_vec.rend(); it++)
		result_vec.push_back(it->value);

	return (result_vec);
}

void PmergeMe::winnerComesFirst(Pvec &vec)
{
	for (Pvec::iterator it = vec.begin();
		 it != vec.end() && it + 1 != vec.end(); it++)
	{
		if (!Pair::comp(*it, *(++it))) ft_swap(*it, *(it - 1));
	}
}

void PmergeMe::attachLosers(Pvec &vec, Pvec &winner)
{
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		Pair *ptr = vec[i].pair;

		if (vec[i].pair == 0)
			vec[i].pair = &vec[i + 1];

		else
		{
			// winner의 페어 끝까지 타고 들어간 후에 거기 패자를 붙인다.
			while (ptr != 0 && ptr->pair != 0) ptr = ptr->pair;
			ptr->pair = &vec[i + 1];
		}
		winner.push_back(vec[i]);
	}
	printDebug(winner, "winner");
}

// 재귀의 깊이 d 일때 현재 위너의 길이는 2^(d)
// (자기자신을 포함한 길이, d는  첫 진입시 (0)
// 우리는 2^(d-1)-1 번 포인터를 타고 들어간 다음 잘라서 sub_chain에 붙여야함
void PmergeMe::createChains(Pvec &sorted_vec, Pvec &main_chain, Pvec &sub_chain)
{
	int target = std::pow(2, depth);

	for (Pvec::iterator it = sorted_vec.begin(); it != sorted_vec.end(); it++)
	{
		Pair *ptr = &*it;
		for (int i = 0; i < target - 1; i++)  // 포인터 타고 들어가는 부분
		{
			ptr = (ptr)->pair;
		}
		sub_chain.push_back(*ptr->pair);
		ptr->pair = 0;
		main_chain.push_back(*it);
	}
}

void PmergeMe::insertSubChain(Pvec &main_chain, Pvec &sub_chain)
{
	int insert_sequence[sub_chain.size()];
	getInsert_seq(sub_chain.size(), insert_sequence);

	for (size_t i = 0; i < sub_chain.size(); i++)
	{
		int sub_chain_idx = sub_chain.size() - insert_sequence[i];

		Pvec::iterator it = std::lower_bound(
			main_chain.begin() + sub_chain_idx, main_chain.end(),
			sub_chain[sub_chain_idx], Pair::comp);

		main_chain.insert(it, sub_chain[sub_chain_idx]);
	}
}

void PmergeMe::insertRemaining(Pvec &vec, Pvec &main_chain)
{
	if (vec.size() % 2)
	{
		Pvec::iterator it = std::lower_bound(
			main_chain.begin(), main_chain.end(), vec.back(), Pair::comp);
		main_chain.insert(it, vec.back());
	}
	printDebug(main_chain, "insert finished");
}

std::vector<Pair> PmergeMe::InfiniteTsukuyomi(Pvec vec)
{
	if (vec.size() == 1) return (vec);

	// 두개씩 비교하며 큰게 앞으로 오게 설정
	winnerComesFirst(vec);

	// 승자의 페어로 패자를 붙인다
	Pvec winner;
	attachLosers(vec, winner);

	depth++;
	Pvec sorted_vec = InfiniteTsukuyomi(winner);
	depth--;

	Pvec main_chain;  // 여기는 항상 정렬된 상태
	Pvec sub_chain;	  // 메인 체인에 삽입해야할 요소

	createChains(sorted_vec, main_chain, sub_chain);

	insertSubChain(main_chain, sub_chain);

	insertRemaining(vec, main_chain);
	return (main_chain);
}

// ###########################################################################
// #                                                                         #
// #                        여기서부터 deque용 함수                         #
// #                                                                         #
// ###########################################################################

std::deque<int> PmergeMe::FJSort(std::deque<int> &input)
{
	Pair::compare_count = 0;
	if (input.empty()) return (input);
	std::deque<Pair> pdq;

	for (std::deque<int>::iterator it = input.begin(); it != input.end(); it++)
		pdq.push_back(Pair(*it, NULL));

	std::deque<int>	 result_dq;
	std::deque<Pair> sorted_dq = InfiniteTsukuyomi(pdq);

	for (std::deque<Pair>::reverse_iterator rit = sorted_dq.rbegin();
		 rit != sorted_dq.rend(); rit++)
		result_dq.push_back(rit->value);

	return (result_dq);
}

void PmergeMe::winnerComesFirst(Pdq &dq)
{
	for (Pdq::iterator it = dq.begin(); it != dq.end() && it + 1 != dq.end();
		 it++)
	{
		if (it->value < (++it)->value) ft_swap(*it, *(it - 1));
	}
}

void PmergeMe::attachLosers(Pdq &dq, Pdq &winner)
{
	for (size_t i = 0; i + 1 < dq.size(); i += 2)
	{
		Pair *ptr = dq[i].pair;

		if (dq[i].pair == 0)
			dq[i].pair = &dq[i + 1];

		else
		{
			while (ptr != 0 && ptr->pair != 0) ptr = ptr->pair;
			ptr->pair = &dq[i + 1];
		}
		winner.push_back(dq[i]);
	}
	printDebug(winner, "winner");
}

void PmergeMe::createChains(Pdq &sorted_dq, Pdq &main_chain, Pdq &sub_chain)
{
	int target = std::pow(2, depth);

	for (Pdq::iterator it = sorted_dq.begin(); it != sorted_dq.end(); it++)
	{
		Pair *ptr = &*it;
		for (int i = 0; i < target - 1; i++)
		{
			ptr = (ptr)->pair;
		}
		sub_chain.push_back(*ptr->pair);
		ptr->pair = 0;
		main_chain.push_back(*it);
	}
}

void PmergeMe::insertSubChain(Pdq &main_chain, Pdq &sub_chain)
{
	int insert_sequence[main_chain.size()];
	getInsert_seq(sub_chain.size(), insert_sequence);

	for (size_t i = 0; i < sub_chain.size(); i++)
	{
		int sub_chain_idx = sub_chain.size() - insert_sequence[i];

		Pdq::iterator it = std::lower_bound(
			main_chain.begin() + sub_chain_idx, main_chain.end(),
			sub_chain[sub_chain_idx], Pair::comp);

		main_chain.insert(it, sub_chain[sub_chain_idx]);
	}
}

void PmergeMe::insertRemaining(Pdq &dq, Pdq &main_chain)
{
	if (dq.size() % 2)
	{
		Pdq::iterator it = std::lower_bound(
			main_chain.begin(), main_chain.end(), dq.back(), Pair::comp);
		main_chain.insert(it, dq.back());
	}
	printDebug(main_chain, "RESULT deque");
}

std::deque<Pair> PmergeMe::InfiniteTsukuyomi(Pdq dq)
{
	if (dq.size() == 1) return (dq);

	winnerComesFirst(dq);

	Pdq winner;
	attachLosers(dq, winner);

	depth++;
	Pdq sorted_dq = InfiniteTsukuyomi(winner);
	depth--;

	Pdq main_chain;
	Pdq sub_chain;

	createChains(sorted_dq, main_chain, sub_chain);

	insertSubChain(main_chain, sub_chain);

	insertRemaining(dq, main_chain);
	return (main_chain);
}

// ###########################################################################
// #                                                                         #
// #                        여기서부터 list용 함수                           #
// #                                                                         #
// ###########################################################################

std::list<int> PmergeMe::FJSort(std::list<int> &input)
{
	Pair::compare_count = 0;
	if (input.empty()) return (input);
	std::list<Pair> plist;

	for (std::list<int>::iterator it = input.begin(); it != input.end(); it++)
		plist.push_back(Pair(*it, NULL));

	std::list<int>	result_list;
	std::list<Pair> sorted_list = InfiniteTsukuyomi(plist);

	for (std::list<Pair>::reverse_iterator it = sorted_list.rbegin();
		 it != sorted_list.rend(); it++)
		result_list.push_back(it->value);

	return (result_list);
}

void PmergeMe::winnerComesFirst(Plist &list)
{
	Plist::iterator it = list.begin();
	Plist::iterator next_it = ++list.begin();
	{
		for (; it != list.end() && next_it != list.end();
			 it++, it++, next_it++, next_it++)
		{
			if (it->value < next_it->value) ft_swap(*it, *next_it);
		}
	}
}

void PmergeMe::attachLosers(Plist &list, Plist &winner)
{
	Plist::iterator it = list.begin();
	Plist::iterator next_it = ++list.begin();

	for (; it != list.end() && next_it != list.end();
		 it++, it++, next_it++, next_it++)
	{
		Pair *ptr = it->pair;

		if (it->pair == 0)
			it->pair = &(*next_it);

		else
		{
			while (ptr != 0 && ptr->pair != 0) ptr = ptr->pair;
			ptr->pair = &(*next_it);
		}
		winner.push_back(*it);
	}
	printDebug(winner, "winner");
}

void PmergeMe::createChains(Plist &sorted_list, Plist &main_chain,
							Plist &sub_chain)
{
	int target = std::pow(2, depth);

	for (Plist::iterator it = sorted_list.begin(); it != sorted_list.end();
		 it++)
	{
		Pair *ptr = &*it;
		for (int i = 0; i < target - 1; i++)  // 포인터 타고 들어가는 부분
		{
			ptr = (ptr)->pair;
		}
		sub_chain.push_back(*ptr->pair);
		ptr->pair = 0;
		main_chain.push_back(*it);
	}
	printDebug(main_chain, "main_chain");
	printDebug(sub_chain, "sub_chain");
}

void PmergeMe::insertSubChain(Plist &main_chain, Plist &sub_chain)
{
	if (main_chain.size() == 1)
	{
		main_chain.push_back(sub_chain.front());
		return;
	}
	int insert_sequence[main_chain.size()];
	getInsert_seq(sub_chain.size(), insert_sequence);

	int delta_arr[main_chain.size() - 1];
	for (size_t k = 0; k < main_chain.size(); ++k)
	{
		delta_arr[k] =
			insert_sequence[k + 1] - insert_sequence[k];  // 변화량 저장
	}

	Plist::iterator sub_iter[sub_chain.size()];
	Plist::iterator main_iter[main_chain.size()];
	Plist::iterator sub_pos = --sub_chain.end();
	Plist::iterator main_pos = --main_chain.end();

	sub_iter[0] = sub_pos;
	main_iter[0] = main_pos;
	for (size_t i = 1; i < main_chain.size(); i++)
	{
		if (delta_arr[i - 1] > 0)
		{
			for (int offset = 0; offset < delta_arr[i - 1]; offset++)
			{
				sub_pos--;
				main_pos--;
			}
		}
		else
			for (int offset = 0; offset > delta_arr[i - 1]; offset--)
			{
				sub_pos++;
				main_pos++;
			}
		sub_iter[i] = sub_pos;
		main_iter[i] = main_pos;
	}

	for (size_t i = 0; i < sub_chain.size(); i++)
	{
		Plist::iterator insert_pos = std::lower_bound(
			main_iter[i], main_chain.end(), *sub_iter[i], Pair::comp);
		main_chain.insert(insert_pos, *sub_iter[i]);
	}
}

void PmergeMe::insertRemaining(Plist &list, Plist &main_chain)
{
	if (list.size() % 2)
	{
		Plist::iterator it = std::lower_bound(
			main_chain.begin(), main_chain.end(), list.back(), Pair::comp);
		main_chain.insert(it, list.back());
	}
	printDebug(main_chain, "insert finished");
}

std::list<Pair> PmergeMe::InfiniteTsukuyomi(Plist list)
{
	if (list.size() == 1) return (list);

	// 두개씩 비교하며 큰게 앞으로 오게 설정
	winnerComesFirst(list);

	// 승자의 페어로 패자를 붙인다
	Plist winner;
	attachLosers(list, winner);

	depth++;
	Plist sorted_list = InfiniteTsukuyomi(winner);
	depth--;

	Plist main_chain;  // 여기는 항상 정렬된 상태
	Plist sub_chain;   // 메인 체인에 삽입해야할 요소

	createChains(sorted_list, main_chain, sub_chain);

	insertSubChain(main_chain, sub_chain);

	insertRemaining(list, main_chain);
	return (main_chain);
}

int PmergeMe::getTk(int k) { return ((pow(2, k + 1) + pow(-1, k)) / 3); }

void PmergeMe::getInsert_seq(int size, int *arr)
{
	int	 Tk;
	int	 prev_Tk = 0;
	int	 j = 0;
	bool stop_flag = false;

	for (int i = 0; !stop_flag; i++)
	{
		Tk = getTk(i);

		if (Tk >= size)	 // size 보다 더 큰값이 들어가지 않게 조정하고 종료
		{
			Tk = size;
			stop_flag = true;
		}

		while (Tk > prev_Tk)
		{
			arr[j++] = Tk;
			Tk--;
		}
		prev_Tk = getTk(i);
	}
	return;
}
